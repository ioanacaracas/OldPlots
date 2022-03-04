#include <RecEvent.h>
#include <RecEventFile.h>
#include <DetectorGeometry.h>
#include <FileInfo.h>
#include <EventInfo.h>
#include <FDSelection.h>
#include <UtilityFunctions.h>
#include <Shower.h>

#include <TFile.h>
#include <TVector.h>
#include <TH1.h>
#include <TH2.h>
#include <TProfile.h>
#include <THistPainter.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TColor.h>
#include <TF1.h>
#include <TFormula.h>
#include <TGraphErrors.h>
#include <TPaveStats.h>
#include <TAxis.h>
#include <TGaxis.h>
#include <TLatex.h>

#include "TROOT.h"

#include <vector>
#include <math.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

#include "ReWeight.h"

using namespace std;

static string inFileName,
              outName = gOutputFile,
              RatioNames[15],
              D1Names[15],
              D0Names[15],
              ZenithNames[15],
              weightFileName = "DataFiles/Weights.dat",
              figureDirectoryName = "Figures/",
              figureName = "Weights";

static const float Hmax = 9000,
                   ToRad = M_PI/180,
                   ToDeg = 180/M_PI,
                   ZenMax = 110 * ToRad,
                   ZenMin = 180 * ToRad,
                   CosMax = cos(ZenMax),
                   CosMin = cos(ZenMin);


static double P0Par[2] = {7689, 943.8},
              P1Par[3] = {-0.001124,0.0001191,0.002599 };

double fitfunctionRatio(double* x, double* par) {
  return exp(par[1]*(x[0]-par[0])) + par[2];
}

double fitP0Theta(double* x, double* par) {
  return  par[1]/(cos(x[0]*ToRad) * cos(x[0]*ToRad)) - par[0]/cos(x[0]*ToRad);
}

double fitP1Theta(double* x, double* par) {
  return  par[1]/(cos(x[0]*ToRad) * cos(x[0]*ToRad)) - par[0]/cos(x[0]*ToRad) + par[2];
}

double fitP2Theta(double* x, double* par) {
  return par[0] + par[1]*x[0] + par[2]*x[0]*x[0];
}

struct data {
  std::vector<float> d1;
  std::vector<float> d0;
  std::vector<float> zenith;
} gen;

int main(int argc, char** argv) {

  int nOptions = getOptions(argc, argv);

  if (nOptions < 0 || argc - nOptions != 1) {
    Usage(argv[0]);
    return 1;
  }
  inFileName = argv[nOptions];

  ReadData(inFileName);

  outName = gOutputFile.c_str();
  TFile* outFile = new TFile(outName.c_str(), "RECREATE");
  cout<<" Writing to "<<outName<<endl<<endl;

  
  //outFile->Open(outName.c_str());

  FillHistograms();
  CalculateWeightingParameters(outFile);
  PlotThrown();

  outFile->Write();
  outFile->Close();

  return 1;
}

int ReadData(string inFileName) {
  unsigned int nUnique = 0;

  // EventInfo eventInfo;
  // RecEventFile* inDataFile;
  // RecEvent* recEvent;

  TFile *inDataFile= new TFile(inFileName.c_str(),"READ");
  //recEvent = new RecEvent();

  cout << " opening file " << inFileName;
  //Setting all unused branches to 0 to speed things up... A lot.

  // inDataFile->SetBranchStatus("event.f*", 0);
  // inDataFile->SetBranchStatus("event.fGenShower.fD0", 1);
  // inDataFile->SetBranchStatus("event.fGenShower.fD1", 1);
  // inDataFile->SetBranchStatus("event.fGenShower.fAxisCoreCS", 1);

  // inDataFile->SetBuffers(&(recEvent));

 // inDataFile->cd();

  TVectorD *RootVectorLgE  = ((TVectorD*) inDataFile->Get("RootVectorLgEMC"));
  TVectorD *RootVectorXmax =    ((TVectorD*) inDataFile->Get("RootVectorXmaxMC"));
  TVectorD *RootVectorX0  =   ((TVectorD*) inDataFile->Get("RootVectorX0MC"));
  TVectorD *RootVectorX1  =   ((TVectorD*) inDataFile->Get("RootVectorX1MC"));
  TVectorD *RootVectorD0  =   ((TVectorD*) inDataFile->Get("RootVectorD0MC"));
  TVectorD *RootVectorD1  =   ((TVectorD*) inDataFile->Get("RootVectorD1MC"));
  TVectorD *RootVectorZenithAngle  =   ((TVectorD*) inDataFile->Get("RootVectorZenith"));
  TVectorD *RootVectorShowerNumber  =   ((TVectorD*) inDataFile->Get("RootVectorShowerNR"));



  unsigned int nEv = RootVectorZenithAngle->GetNoElements();
  int combinedCount = 0;

  cout << " reading " << nEv << " events... " << endl;

  for (unsigned int i = 0; i < nEv; i++) {
    // inDataFile->GetEventInfo(i, &eventInfo);
    // inDataFile->ReadEvent(i);

    // const std::vector<FDEvent>& fdEvents = recEvent->GetFDEvents();
    // const GenShower& genEvent = recEvent->GetGenShower();

    float Zen = ((*RootVectorZenithAngle))[i] ;
    float D0  = ((*RootVectorD0))[i];
    float D1  = ((*RootVectorD1))[i];

    gen.d0.push_back(D0);
    gen.d1.push_back(D1);
    gen.zenith.push_back(Zen);

    nUnique++;

    UtilityFunctions::ShowProgress(i, nEv - 1);
  }

  cout << " " << nUnique << " of " << nEv << " read in." << endl;

  return nUnique;
}

void FillHistograms() {

  cout<<" Filling GenerationHistograms..."<<endl;

  TH1F *RatioHist[15]; 
  TH1F *D1Hist[15];
  TH1F *D0Hist[15];
  TH1F *ZenithHist[15];

  string name;
  std::stringstream ss;

    for (int i = 0; i < 15; i++) {

      ss.clear();
      ss.str(std::string());
      ss << "D0D1Ratio_" << i;
      name = ss.str();
      RatioNames[i] = name;

      ss.clear();
      ss.str(std::string());
      ss << "D1_" << i;
      name = ss.str();
      D1Names[i] = name;
      D1Hist[i] = new TH1F(name.c_str(), "", 100, 0, 30000);

      ss.clear();
      ss.str(std::string());
      ss << "D0_" << i;
      name = ss.str();
      D0Names[i] = name;
      D0Hist[i] = new TH1F(name.c_str(), "", 100, 0, 30000);

      ss.clear();
      ss.str(std::string());
      ss << "Zen_" << i;
      name = ss.str();
      ZenithNames[i] = name;
      ZenithHist[i] = new TH1F(name.c_str(), "", 700, 110, 180);
  }

  int size = gen.zenith.size();
  float Zenith = 0,
        D0     = 0, 
        D1     = 0, 
        Cos    = 0;

  for (int i = 0; i < size; i++) {

    Zenith = gen.zenith.at(i);
    Cos = cos(Zenith);
    int bin = floor( (Cos*Cos - CosMax*CosMax) / (CosMin * CosMin - CosMax * CosMax) * 15);

    D0 = gen.d0.at(i);
    D1 = gen.d1.at(i);

    //All lgE, all Dec

    if(abs(D0*Cos) <= Hmax && abs(D0*Cos) >= 0){
      D0Hist[bin]->Fill(D0);
      ZenithHist[bin]->Fill(Zenith * ToDeg);
    }    

    if(abs(D1*Cos) <= Hmax && abs(D1*Cos) >= 0){
      D1Hist[bin]->Fill(D1);
    }    

    UtilityFunctions::ShowProgress(i, size - 1);
  }

  float D0Max = 0,
        D1Max = 0;

  for(int i = 0; i < 15; i++){

    D1Max = D1Hist[i]->GetMaximum();

    RatioHist[i] = (TH1F*) D1Hist[i]->Clone(RatioNames[i].c_str());
    RatioHist[i]->Sumw2();

    D1Hist[i]->Scale(1/D1Max);
    RatioHist[i]->Scale(1/D1Max);

    D0Max = D0Hist[i]->GetMaximum();
    D0Hist[i]->Sumw2();
    D0Hist[i]->Scale(1/D0Max);

    RatioHist[i]->Divide(D0Hist[i]);
  }
}

void CalculateWeightingParameters(TFile* outFile) {

  //gStyle->SetOptStat("ine");
  gStyle->SetOptFit();
  gStyle->SetStatX(.6);
  gStyle->SetStatY(.8);
  gStyle->SetStatH(0.15);
  gStyle->SetStatW(0.2);


  ofstream outfile;
  //delete old file
  outfile.open(weightFileName.c_str(), std::ofstream::out | std::ofstream::trunc);
  outfile << "$\\theta$ & $p_0$ & $p_1$ & $p_2$ & $p_3$" << endl;
  outfile.close();

  string name;
  std::stringstream ss;

  double meanZen[15], meanZenErr[15],
         p0[15], p0Err[15], 
         p1[15], p1Err[15], 
         p2[15], p2Err[15], 
         p3[15], p3Err[15];

  //Iterating over CosSq Zenithbins

  TPaveText *paveTextRatio[15];
  TLatex latex[15];
  TCanvas* CanvasRatioDiffZeniths = new TCanvas("CanvasRatioDiffZeniths", "", 200, 10, 700,530);
  CanvasRatioDiffZeniths->Divide(2,2);
  int iPadCanvas = 0;
  for (int i = 0; i < 15; ++i) {

    //Pullind ebin dec bin data for plotting and fitting
    meanZen[i] = ((TH1F*) outFile->Get(ZenithNames[i].c_str()))->GetMean();
    meanZenErr[i] = ((TH1F*) outFile->Get(ZenithNames[i].c_str()))->GetMeanError();

    double P0 = fitP0Theta(&meanZen[i],P0Par);
    double P1 = fitP1Theta(&meanZen[i],P1Par);
    double P2 = 0;
    double P3 = 0;
    double P4 = 0;

    //Grab Acceptance Histogram for Energy and Declination range
    TH1F* Weight = (TH1F*) gDirectory->Get(RatioNames[i].c_str());;
    double BinWidth = Weight->GetBinWidth(6); //Get the th1 bin width.

    int maxBin = Weight->GetMaximumBin();

    double MaxBinCenter = Weight->GetBinCenter(maxBin);
    Weight->GetXaxis()->SetRange(1,MaxBinCenter);

    P3 = MaxBinCenter + BinWidth/2 - 6000; //First guess

    //First guess for right side
    TF1 *EndExpo = new TF1("EndExpo", "exp([1] * (x - [0])) + 1", 0, MaxBinCenter + BinWidth/2);
    EndExpo->SetParameter(0,P0);
    EndExpo->SetParameter(1,P1);
    // EndExpo->SetParLimits(2, .9, 1.1);

    Weight->Fit(EndExpo,"N","",P3,MaxBinCenter - BinWidth/2);


    //First Guess for left side
    TF1 *Start = new TF1("Start", "[0]*x + [1]", 0, MaxBinCenter + BinWidth/2);
    Start->SetParLimits(0, -0.001, 0);
    Start->SetParLimits(1, 1, 1.01);
    // StartExpo->SetParLimits(2, .9, 1.1);

    Weight->Fit(Start,"N","",0,P3);

    TF1 *Total = new TF1("Total", TotalFitFunc, 0, MaxBinCenter + BinWidth/2,4);

    P0 = EndExpo->GetParameter(0);
    P1 = EndExpo->GetParameter(1);
    P2 = Start->GetParameter(0);
    P3 = Start->GetParameter(1);

    Total->SetParameter(0, P0);
    Total->SetParameter(1, P1);
    Total->SetParameter(2, P2);
    Total->SetParameter(3, P3);

    Total->SetParLimits(2, -0.001, 0);
    Total->SetParLimits(3, 1, 1.03);

    Total->SetParName(0, "P_{0}");
    Total->SetParName(1, "P_{1}");
    Total->SetParName(2, "P_{2}");
    Total->SetParName(3, "P_{3}");

    double FitLimit = MaxBinCenter - BinWidth/2;

    if(i <= 1)
      FitLimit = MaxBinCenter - 3*BinWidth/2;
    // Weight->Fit(Total, "Q B E R+ N","", 0, FitLimit);

    // double h = Total->GetMinimum(1,MaxBinCenter);
    // while (Total->GetParameter(4) > 0.0005) {
    //   double par[5];
    //   Total->GetParameters(&par[0]);
    //   Weight->Scale(1 / h);
    //   Total->SetParameters(par);
    //   Weight->TH1::Fit(Total, "Q B E N R+","", 0, FitLimit);
    //   h = Total->GetMinimum(1,MaxBinCenter);
    //   cout << " ==> " << h;
    // }
    // cout<<endl;

    //Extracting final fit values
    // Total->SetParLimits(4, -0.1, 0.1);
    Weight->TH1::Fit(Total, "Q M E N R+","", 0, FitLimit);


    //Making acceptance plot for this delcination and saving to pdf
    TCanvas *Canvas1 = new TCanvas("Canvas", "", 200, 10, 700,530);
    Canvas1->cd();
    Canvas1->SetBottomMargin(0.18);
    Canvas1->SetTopMargin(0.16);
    Canvas1->SetFrameLineWidth(2);
    Canvas1->SetLineWidth(2);
    //gStyle->SetTickLength(0.02,"z");
    Canvas1->SetLeftMargin(0.15);
    Canvas1->SetRightMargin(0.05);
    //Canvas1->Draw();
    Weight->GetYaxis()->SetRangeUser(0, 4);
    Weight->GetYaxis()->SetTitle("N_{ev}(D_{1}) / N_{ev}(D_{0}) [a.u.]");
    Weight->GetXaxis()->SetTitle("Distance D [m]");
    Weight->GetYaxis()->SetTitleOffset(1.1);
    Weight->GetXaxis()->SetTitleOffset(1.2);
    Weight->GetYaxis()->SetLabelSize(.06);
    Weight->GetYaxis()->SetTitleSize(.065);
    Weight->GetXaxis()->SetLabelSize(.06);
    Weight->GetXaxis()->SetTitleSize(.065);
    Weight->GetXaxis()->SetLabelFont(132);
    Weight->GetYaxis()->SetLabelFont(132);
    Weight->GetXaxis()->SetTitleFont(132);
    Weight->GetYaxis()->SetTitleFont(132);
    Weight->GetXaxis()->CenterTitle();
    Weight->GetYaxis()->CenterTitle();
    Weight->SetLineWidth(2);
    Weight->Draw("E");
    Start->SetLineColor(kGray + 1);
    Start->SetLineWidth(1);
    EndExpo->SetLineColor(kGray + 1);
    EndExpo->SetLineWidth(1);
    Start->Draw("Lsame");
    EndExpo->Draw("Lsame");
    Total->Draw("Lsame");

    ss.clear();
    ss.str(std::string());
    ss << figureDirectoryName << RatioNames[i] << ".pdf";
    name = ss.str();
    Canvas1->Print(name.c_str());
    delete Canvas1;

    ss.clear();
    ss.str(std::string());
    ss << figureDirectoryName << "RatioDiffZeniths.pdf";
    name = ss.str();


   
   // CanvasRatioDiffZeniths->Update();
   // CanvasRatioDiffZeniths->Modified();

    

    
   
    p0[i]   = Total->GetParameter(0);
    p1[i]   = Total->GetParameter(1);
    p2[i]   = Total->GetParameter(2);
    p3[i]   = Total->GetParameter(3);
    p0Err[i] = Total->GetParError(0);
    p1Err[i] = Total->GetParError(1);
    p2Err[i] = Total->GetParError(2);
    p3Err[i] = Total->GetParError(3);

    gStyle->SetOptStat(0);

    if(i%5 == 0){
    
      CanvasRatioDiffZeniths->cd(iPadCanvas+1);
      gPad->SetMargin(0.15, 0.13, 0.2, 0.02);

      latex[i].SetTextSize(0.06);
      latex[i].SetTextAlign(12);

      if(i!=0)
        paveTextRatio[i] = new TPaveText(13E3,0.3,29E3,1.5, "NB" );
      else
        paveTextRatio[i] = new TPaveText(5E3,1.5,21E3,2.7, "NB" );

      // paveTextRatio[i]->AddText(TString::Format("<#theta> = %.2f #circ #pm  %.2e #circ", meanZen[i], meanZenErr[i]));
      // paveTextRatio[i]->AddText("");
      paveTextRatio[i]->AddText(TString::Format("P_{0}(#theta) = %.2f #pm %.2f", p0[i], p0Err[i]));
      paveTextRatio[i]->AddText(TString::Format("P_{1}(#theta) = %.2e #pm %.2e", p1[i], p1Err[i]));
      paveTextRatio[i]->AddText(TString::Format("P_{2}(#theta) = %.2e #pm %.2e", p2[i], p2Err[i]));
      paveTextRatio[i]->SetFillStyle(0);
      paveTextRatio[i]->SetBorderSize(0);
      paveTextRatio[i]->SetTextSize(.05);   
      paveTextRatio[i]->SetTextFont(132);

      Weight->DrawCopy("E");
      Total->Draw("Lsame");
      paveTextRatio[i]->Draw("same");
      
      if(iPadCanvas!=2)
        latex[i].DrawLatex(10E3, 3.5, TString::Format("< #theta > = %.2f^{#circ}", meanZen[i]));
      else
        latex[i].DrawLatex(12E3, 3.5, TString::Format("< #theta > = %.2f^{#circ}", meanZen[i]));

      cout<<" i = "<<i<<" ipda = "<<iPadCanvas<<" zenith: "<<meanZen[i]<<"  name hist: "<< Weight->GetName() <<endl;
      iPadCanvas+=1;      
    }
    else if (i==14){
      CanvasRatioDiffZeniths->cd(4);
      gPad->SetMargin(0.15, 0.13, 0.2, 0.02);
      paveTextRatio[i] = new TPaveText(13E3,0.3,29E3,1.5, "NB" );
      
      paveTextRatio[i]->AddText(TString::Format("P_{0}(#theta) = %.2f #pm %.2f", p0[i], p0Err[i]));
      paveTextRatio[i]->AddText(TString::Format("P_{1}(#theta) = %.2e #pm %.2e", p1[i], p1Err[i]));
      paveTextRatio[i]->AddText(TString::Format("P_{2}(#theta) = %.2e #pm %.2e", p2[i], p2Err[i]));
      paveTextRatio[i]->SetFillStyle(0);
      paveTextRatio[i]->SetBorderSize(0);
      paveTextRatio[i]->SetTextSize(.05);   
      paveTextRatio[i]->SetTextFont(132);

      Weight->DrawCopy("E");
      Total->Draw("Lsame");
      paveTextRatio[i]->Draw("same");
      latex[i].SetTextAlign(12);
      latex[i].SetTextSize(0.06);
      latex[i].DrawLatex(10E3, 3.5, TString::Format("< #theta > = %.2f^{#circ} ", meanZen[i]));
    }



    delete Weight;


    cout<<p1Err[i]<<endl;

    // p1Err[0] *= 1.5;
    // p1Err[1] *= 1.5;
    // p1Err[2] *= 1.5;


    float FudgeFactor = 0.005;

    if(p0Err[i] < abs(p0[i] * FudgeFactor))
      p0Err[i] = abs(p0[i] * FudgeFactor);

    if(p1Err[i] < abs(p1[i] * FudgeFactor))
      p1Err[i] = abs(p1[i] * FudgeFactor);

    if(p2Err[i] < abs(p2[i] * FudgeFactor))
      p2Err[i] = abs(p2[i] * FudgeFactor);

    if(p3Err[i] < abs(p3[i] * FudgeFactor))
      p3Err[i] = abs(p3[i] * FudgeFactor);

  }

  CanvasRatioDiffZeniths->Print(name.c_str());

  delete CanvasRatioDiffZeniths;


  
  cout<<" Fitting Zenith Dependence..."<<endl;

 // gStyle->SetMaxDigitsY(2);
  TGaxis::SetMaxDigits(3);
  TCanvas *CanvasP0vsZenith = new TCanvas("CanvasP0vsZenith", "", 200, 10, 700,530);
  CanvasP0vsZenith->SetBottomMargin(0.18);
  CanvasP0vsZenith->SetTopMargin(0.16);
  CanvasP0vsZenith->SetFrameLineWidth(2);
  CanvasP0vsZenith->SetLineWidth(2);
  //gStyle->SetTickLength(0.02,"z");
  CanvasP0vsZenith->SetLeftMargin(0.15);
  CanvasP0vsZenith->SetRightMargin(0.03);
  TGraphErrors* graphP0vsZenith = new TGraphErrors(15, meanZen, p0, meanZenErr, p0Err);

  graphP0vsZenith->SetTitle("");
  
  graphP0vsZenith->GetYaxis()->SetTitle(" P_{0}");
  graphP0vsZenith->GetYaxis()->SetTitleOffset(1.5);
  graphP0vsZenith->GetXaxis()->SetTitle("#theta [#circ]");
  graphP0vsZenith->GetYaxis()->SetTitleOffset(1.2);
  graphP0vsZenith->GetXaxis()->SetTitleOffset(1.2);
  graphP0vsZenith->GetYaxis()->SetLabelSize(.06);
  graphP0vsZenith->GetYaxis()->SetTitleSize(.065);
  graphP0vsZenith->GetXaxis()->SetLabelSize(.06);
  graphP0vsZenith->GetXaxis()->SetTitleSize(.065);
  graphP0vsZenith->GetXaxis()->SetLabelFont(132);
  graphP0vsZenith->GetYaxis()->SetLabelFont(132);
  graphP0vsZenith->GetXaxis()->SetTitleFont(132);
  graphP0vsZenith->GetYaxis()->SetTitleFont(132);
  graphP0vsZenith->GetXaxis()->CenterTitle();
  graphP0vsZenith->GetYaxis()->CenterTitle();
  graphP0vsZenith->Draw();

  TF1 *P0vsZenithFunc = new TF1("P0vsZenithFunc", ParFunc, 110, 180, 3);
  graphP0vsZenith->Fit(P0vsZenithFunc, "W Q R+ N", "l", 110, 180);
  cout<<" P0Vs zenith parameters:  ==== [0] = "<<P0vsZenithFunc->GetParameter(0)<<" [1] = "<<P0vsZenithFunc->GetParameter(1)<<"  [2] = "<<P0vsZenithFunc->GetParameter(2)<<endl;
  P0vsZenithFunc->Draw("sames");

  double a2 = P0vsZenithFunc->GetParameter(1);
  double a1 = P0vsZenithFunc->GetParameter(0);
  double a0 = P0vsZenithFunc->GetParameter(2);

  double a2Err = P0vsZenithFunc->GetParError(1);
  double a1Err = P0vsZenithFunc->GetParError(0);
  double a0Err = P0vsZenithFunc->GetParError(2);


  TPaveText *ptP0vsZenithPave =  new TPaveText(150,20E3,170,30E3, "NB" );
  
  ptP0vsZenithPave->AddText(TString::Format("a_{0} = %.2f #pm %.2f ", a0, a0Err));
  ptP0vsZenithPave->AddText(TString::Format("a_{1} = %.2f #pm %.2f", a1, a1Err));
  ptP0vsZenithPave->AddText(TString::Format("a_{2} = %.2f #pm %.2f", a2, a2Err));
  

  ptP0vsZenithPave->SetFillStyle(0);
  ptP0vsZenithPave->SetBorderSize(0);
  ptP0vsZenithPave->SetTextSize(.05);   
  ptP0vsZenithPave->SetTextFont(132);
  ptP0vsZenithPave->Draw("same");

  ss.clear();
  ss.str(std::string());
  ss << figureDirectoryName << "P0vsZenith.pdf";
  name = ss.str();
  CanvasP0vsZenith->Print(name.c_str());

  P0vsZenithFunc->Write("P0vsZenithFunc");

  delete graphP0vsZenith;
  delete CanvasP0vsZenith;



  TCanvas *CanvasP1vsZenith = new TCanvas("CanvasP1vsZenith", "", 200, 10, 700,530);
  CanvasP1vsZenith->SetBottomMargin(0.18);
  CanvasP1vsZenith->SetTopMargin(0.16);
  CanvasP1vsZenith->SetFrameLineWidth(2);
  CanvasP1vsZenith->SetLineWidth(2);
  //gStyle->SetTickLength(0.02,"z");
  CanvasP1vsZenith->SetLeftMargin(0.15);
  CanvasP1vsZenith->SetRightMargin(0.03);

  TGraphErrors* graphP1vsZenith = new TGraphErrors(15, meanZen, p1, meanZenErr, p1Err);

  graphP1vsZenith->SetTitle("");

  graphP1vsZenith->GetYaxis()->SetTitle("P_{1} ");
  graphP1vsZenith->GetYaxis()->SetTitleOffset(1.2);

  graphP1vsZenith->GetXaxis()->SetTitle("#theta [#circ]");
  graphP1vsZenith->GetYaxis()->SetTitleOffset(1.2);
  graphP1vsZenith->GetXaxis()->SetTitleOffset(1.2);
  graphP1vsZenith->GetYaxis()->SetLabelSize(.06);
  graphP1vsZenith->GetYaxis()->SetTitleSize(.065);
  graphP1vsZenith->GetXaxis()->SetLabelSize(.06);
  graphP1vsZenith->GetXaxis()->SetTitleSize(.065);
  graphP1vsZenith->GetXaxis()->SetLabelFont(132);
  graphP1vsZenith->GetYaxis()->SetLabelFont(132);
  graphP1vsZenith->GetXaxis()->SetTitleFont(132);
  graphP1vsZenith->GetYaxis()->SetTitleFont(132);
  graphP1vsZenith->GetXaxis()->CenterTitle();
  graphP1vsZenith->GetYaxis()->CenterTitle();
  graphP1vsZenith->Draw();

  TF1 *P1vsZenithFunc = new TF1("P1vsZenithFunc", ParFunc, 110, 180, 3);
  graphP1vsZenith->Fit(P1vsZenithFunc, "Q R+ N", "l", 110, 180);
  P1vsZenithFunc->Draw("sames");

  double b2 = P1vsZenithFunc->GetParameter(1);
  double b1 = P1vsZenithFunc->GetParameter(0);
  double b0 = P1vsZenithFunc->GetParameter(2);

  double b2Err = P1vsZenithFunc->GetParError(1);
  double b1Err = P1vsZenithFunc->GetParError(0);
  double b0Err = P1vsZenithFunc->GetParError(2);

  TPaveText *ptP1vsZenithPave =  new TPaveText(140,2E-4,170,7E-4, "NB" );
  ptP1vsZenithPave->AddText(TString::Format("b_{0} = %.2e #pm %.2e", b0, b0Err));  
  ptP1vsZenithPave->AddText(TString::Format("b_{1} = %.2e #pm %.2e", b1, b1Err));
  ptP1vsZenithPave->AddText(TString::Format("b_{2} = %.2e #pm %.2e", b2, b2Err));

  ptP1vsZenithPave->SetFillStyle(0);
  ptP1vsZenithPave->SetBorderSize(0);
  ptP1vsZenithPave->SetTextSize(.05);   
  ptP1vsZenithPave->SetTextFont(132);
  ptP1vsZenithPave->Draw("same");

  ss.clear();
  ss.str(std::string());
  ss << figureDirectoryName << "P1vsZenith.pdf";
  name = ss.str();
  CanvasP1vsZenith->Print(name.c_str());
  graphP1vsZenith->Write("graphP1vsZenith");
  CanvasP1vsZenith->Write("CanvasP1vsZenith");

  P1vsZenithFunc->Write("P1vsZenithFunc");

  delete graphP1vsZenith;
  delete CanvasP1vsZenith;



  TCanvas *CanvasP2vsZenith = new TCanvas("CanvasP2vsZenith", "", 200, 10, 700,530);
  CanvasP2vsZenith->SetBottomMargin(0.18);
  CanvasP2vsZenith->SetTopMargin(0.16);
  CanvasP2vsZenith->SetFrameLineWidth(2);
  CanvasP2vsZenith->SetLineWidth(2);
  //gStyle->SetTickLength(0.02,"z");
  CanvasP2vsZenith->SetLeftMargin(0.15);
  CanvasP2vsZenith->SetRightMargin(0.03);

  TGraphErrors* graphP2vsZenith = new TGraphErrors(15, meanZen, p2, meanZenErr, p2Err);

  graphP2vsZenith->SetTitle("");
  graphP2vsZenith->GetYaxis()->SetTitle("P_{2} ");
  graphP2vsZenith->GetYaxis()->SetTitleOffset(1.2);
  graphP2vsZenith->GetXaxis()->SetTitle("#theta [#circ]");
  graphP2vsZenith->GetYaxis()->SetTitleOffset(1.2);
  graphP2vsZenith->GetXaxis()->SetTitleOffset(1.2);
  graphP2vsZenith->GetYaxis()->SetLabelSize(.06);
  graphP2vsZenith->GetYaxis()->SetTitleSize(.065);
  graphP2vsZenith->GetXaxis()->SetLabelSize(.06);
  graphP2vsZenith->GetXaxis()->SetTitleSize(.065);
  graphP2vsZenith->GetXaxis()->SetLabelFont(132);
  graphP2vsZenith->GetYaxis()->SetLabelFont(132);
  graphP2vsZenith->GetXaxis()->SetTitleFont(132);
  graphP2vsZenith->GetYaxis()->SetTitleFont(132);
  graphP2vsZenith->GetXaxis()->CenterTitle();
  graphP2vsZenith->GetYaxis()->CenterTitle();
  graphP2vsZenith->Draw();


  TF1 *P2vsZenithFunc = new TF1("P2vsZenithFunc", ParFunc, 110, 180, 3);
  graphP2vsZenith->Fit(P2vsZenithFunc, "0 Q R+ N", "l", 110, 180);
  P2vsZenithFunc->Draw("sames");

  double c2 = P2vsZenithFunc->GetParameter(1);
  double c1 = P2vsZenithFunc->GetParameter(0);
  double c0 = P2vsZenithFunc->GetParameter(2);

  double c2Err = P2vsZenithFunc->GetParError(1);
  double c1Err = P2vsZenithFunc->GetParError(0);
  double c0Err = P2vsZenithFunc->GetParError(2);

  TPaveText *ptP2vsZenithPave =  new TPaveText(115,0,145,5E-6, "NB" );
  ptP2vsZenithPave->AddText(TString::Format("c_{0} = %.2e #pm %.2e", c0, c0Err));
  ptP2vsZenithPave->AddText(TString::Format("c_{1} = %.2e #pm %.2e", c1, c1Err));
  ptP2vsZenithPave->AddText(TString::Format("c_{2} = %.2e #pm %.2e", c2, c2Err));  
  

  ptP2vsZenithPave->SetFillStyle(0);
  ptP2vsZenithPave->SetBorderSize(0);
  ptP2vsZenithPave->SetTextSize(.05);   
  ptP2vsZenithPave->SetTextFont(132);
  ptP2vsZenithPave->Draw("same");

  ss.clear();
  ss.str(std::string());
  ss << figureDirectoryName << "P2vsZenith.pdf";
  name = ss.str();
  CanvasP2vsZenith->Print(name.c_str());

  P2vsZenithFunc->Write("P2vsZenithFunc");

  delete graphP2vsZenith;
  delete CanvasP2vsZenith;



  TCanvas *CanvasP3vsZenith = new TCanvas("CanvasP3vsZenith", "", 200, 10, 700,530);
  CanvasP2vsZenith->SetBottomMargin(0.18);
  CanvasP2vsZenith->SetTopMargin(0.16);
  CanvasP2vsZenith->SetFrameLineWidth(2);
  CanvasP2vsZenith->SetLineWidth(2);
  //gStyle->SetTickLength(0.02,"z");
  CanvasP2vsZenith->SetLeftMargin(0.15);
  CanvasP2vsZenith->SetRightMargin(0.03);

  TGraphErrors* graphP3vsZenith = new TGraphErrors(15, meanZen, p3, meanZenErr, p3Err);

  graphP3vsZenith->SetTitle("");
  graphP3vsZenith->GetYaxis()->SetTitle("P_{3} ");
  graphP3vsZenith->GetYaxis()->SetTitleOffset(1.2);
  graphP3vsZenith->GetXaxis()->SetTitle("#theta [#circ]");
  graphP3vsZenith->GetYaxis()->SetTitleOffset(1.2);
  graphP3vsZenith->GetXaxis()->SetTitleOffset(1.2);
  graphP3vsZenith->GetYaxis()->SetLabelSize(.06);
  graphP3vsZenith->GetYaxis()->SetTitleSize(.065);
  graphP3vsZenith->GetXaxis()->SetLabelSize(.06);
  graphP3vsZenith->GetXaxis()->SetTitleSize(.065);
  graphP3vsZenith->GetXaxis()->SetLabelFont(132);
  graphP3vsZenith->GetYaxis()->SetLabelFont(132);
  graphP3vsZenith->GetXaxis()->SetTitleFont(132);
  graphP3vsZenith->GetYaxis()->SetTitleFont(132);
  graphP3vsZenith->GetXaxis()->CenterTitle();
  graphP3vsZenith->GetYaxis()->CenterTitle();
  graphP3vsZenith->Draw();


  TF1 *P3vsZenithFunc = new TF1("P3vsZenithFunc", "pol1", 110, 180);
  graphP3vsZenith->Fit(P3vsZenithFunc, "0 Q R+ N", "l", 110, 180);
  P3vsZenithFunc->Draw("sames");

  double d0 = P3vsZenithFunc->GetParameter(0);
  double d0Err = P3vsZenithFunc->GetParError(0);

  TPaveText *ptP3vsZenithPave =  new TPaveText(111,0.97,142,0.997, "NB" );
  ptP3vsZenithPave->AddText(TString::Format("d_{0} = %.3f #pm %.2e", d0, d0Err));
 
  

  ptP3vsZenithPave->SetFillStyle(0);
  ptP3vsZenithPave->SetBorderSize(0);
  ptP3vsZenithPave->SetTextSize(.05);   
  ptP3vsZenithPave->SetTextFont(132);
  ptP3vsZenithPave->Draw("same");

  ss.clear();
  ss.str(std::string());
  ss << figureDirectoryName << "P3vsZenith.pdf";
  name = ss.str();
  CanvasP3vsZenith->Print(name.c_str());

  P3vsZenithFunc->Write("P3vsZenithFunc");

  delete graphP3vsZenith;
  delete CanvasP3vsZenith;


}
void PlotThrown() {
  int size = gen.zenith.size();

  TF1* P0Func = (TF1*) gDirectory->Get("P0vsZenithFunc");
  TF1* P1Func = (TF1*) gDirectory->Get("P1vsZenithFunc");
  TF1* P2Func = (TF1*) gDirectory->Get("P2vsZenithFunc");
  TF1* P3Func = (TF1*) gDirectory->Get("P3vsZenithFunc");

  const float CosSqMax = CosMax*CosMax; 
  const float CosSqMin = CosMin*CosMin; 

  TH2F* D1VsCosSq = new 
    TH2F("D1VsCosSq","Distance to first interaction vs Cos(#theta)^2",120,0,30000,90,CosSqMax ,CosSqMin);
  TH2F* D1CutVsCosSq = new 
    TH2F("D1CutVsCosSq","Distance to first interaction vs Cos(#theta)^2 with max height cut",120,0,30000,90,CosSqMax,CosSqMin);
  TH2F* D0VsCosSq = new 
    TH2F("D1VsCosSq","Distance to injection vs Cos(#theta)^2 with max height cut",120,0,30000,90,CosSqMax,CosSqMin);
  TH2F* D0VsCosSqReWeight = new 
   TH2F("D0VsCosSqReWeight","Weighted Distance to injection vs Cos(#theta)^2 with max height cut",100,0,30000,90,CosSqMax,CosSqMin);

  TProfile* WeightedD0vsZenith = new 
   TProfile("WeightedD0vsZenith","Weighted D0 vs Zenith Profile",120, 0, 30000, 110, 180);

  TProfile* D1vsZenith = new 
   TProfile("D1vsZenith","D1 vs Zenith Profile",120, 0, 30000, 110, 180);


  TH1F* D1Cut = new TH1F("D1Cut", "", 120, 0, 30000);
  TH1F* D0Weighted= new TH1F("D0Weighted", "", 120, 0, 30000);

  float Zenith = 0,
        Cos    = 0, 
        D0     = 0, 
        D1     = 0, 
        H0     = 0,
        H1     = 0;

  double weight, par[4];

  for(int i =0; i < size; ++i) {
    Zenith = gen.zenith.at(i);
    Cos = cos(Zenith);
    D0 = gen.d0.at(i);
    H0 = abs(D0*Cos);
    D1 = gen.d1.at(i);
    H1 = abs(D1*Cos);

    D1VsCosSq->Fill(D1, Cos * Cos);

    if(H1 <= Hmax && H1 > 0){
      D1CutVsCosSq->Fill(D1, Cos * Cos);
      D1vsZenith->Fill(D1, Zenith * ToDeg);
      D1Cut->Fill(D1);
    }

    par[0] = P0Func->Eval(Zenith * ToDeg);
    par[1] = P1Func->Eval(Zenith * ToDeg);
    par[2] = P2Func->Eval(Zenith * ToDeg);
    par[3] = P3Func->Eval(Zenith * ToDeg);


    weight = TMath::Exp(par[1]*(D0 - par[0]));
    weight += par[2]*D0 +  par[3];

    // cout<<Zenith * ToDeg<<", "<<par[0]<<", "<<par[1]<<", "<<par[2]<<", "<<par[3]<<" -> "<<weight<<endl;

    if(H0 <= Hmax && H0 > 0){
      D0VsCosSq->Fill(D0, Cos * Cos);
      D0VsCosSqReWeight->Fill(D0, Cos * Cos, weight);
      WeightedD0vsZenith->Fill(D0, Zenith * ToDeg, weight);
      D0Weighted->Fill(D0, weight);
    }
  }


  string name;
  std::stringstream ss;

  TCanvas *CanvasD1VsCosSq = new TCanvas("CanvasD1VsCosSq", "", 200, 10, 600, 400);

  D1VsCosSq->GetYaxis()->SetTitle("cos(#theta)^2");
  D1VsCosSq->GetYaxis()->SetTitleOffset(1.5);
  D1VsCosSq->GetXaxis()->SetTitle("Distance to first interaction [m]");
  D1VsCosSq->Draw("COLZ");

  ss.clear();
  ss.str(std::string());
  ss << figureDirectoryName << "D1VsCosSq.pdf";
  name = ss.str();
  CanvasD1VsCosSq->Print(name.c_str());
  delete CanvasD1VsCosSq;

  gStyle->SetOptStat(0);
  TGaxis::SetMaxDigits(5);

  TCanvas *CanvasD1CutVsCosSq = new TCanvas("CanvasD1CutVsCosSq", "", 200, 10, 700,530);
  CanvasD1CutVsCosSq->SetBottomMargin(0.18);
  CanvasD1CutVsCosSq->SetTopMargin(0.16);
  CanvasD1CutVsCosSq->SetFrameLineWidth(2);
  CanvasD1CutVsCosSq->SetLineWidth(2);
  //gStyle->SetTickLength(0.02,"z");
  CanvasD1CutVsCosSq->SetLeftMargin(0.15);
  CanvasD1CutVsCosSq->SetRightMargin(0.15);

  D1CutVsCosSq->SetTitle("");

  D1CutVsCosSq->GetYaxis()->SetTitle("cos^{2} #theta");
  D1CutVsCosSq->GetYaxis()->SetTitleOffset(1.5);
  D1CutVsCosSq->GetXaxis()->SetTitle("Distance to first interaction D_{1} [m]");
  D1CutVsCosSq->GetYaxis()->SetTitleOffset(1.2);
  D1CutVsCosSq->GetXaxis()->SetTitleOffset(1.2);
  D1CutVsCosSq->GetYaxis()->SetLabelSize(.06);
  D1CutVsCosSq->GetYaxis()->SetTitleSize(.065);
  D1CutVsCosSq->GetXaxis()->SetLabelSize(.06);
  D1CutVsCosSq->GetXaxis()->SetTitleSize(.065);
  D1CutVsCosSq->GetXaxis()->SetLabelFont(132);
  D1CutVsCosSq->GetYaxis()->SetLabelFont(132);
  D1CutVsCosSq->GetXaxis()->SetTitleFont(132);
  D1CutVsCosSq->GetYaxis()->SetTitleFont(132);
  D1CutVsCosSq->GetXaxis()->CenterTitle();
  D1CutVsCosSq->GetYaxis()->CenterTitle();
  D1CutVsCosSq->Draw("COLZ");

  ss.clear();
  ss.str(std::string());
  ss << figureDirectoryName << "D1CutVsCosSq.pdf";
  name = ss.str();
  CanvasD1CutVsCosSq->Print(name.c_str());
  delete CanvasD1CutVsCosSq;


  TCanvas *CanvasD0VsCosSq = new TCanvas("CanvasD0VsCosSq", "", 200, 10, 700,530);
  CanvasD0VsCosSq->SetBottomMargin(0.18);
  CanvasD0VsCosSq->SetTopMargin(0.16);
  CanvasD0VsCosSq->SetFrameLineWidth(2);
  CanvasD0VsCosSq->SetLineWidth(2);
  //gStyle->SetTickLength(0.02,"z");
  CanvasD0VsCosSq->SetLeftMargin(0.15);
  CanvasD0VsCosSq->SetRightMargin(0.15);


  D0VsCosSq->SetTitle("");

  D0VsCosSq->GetYaxis()->SetTitle("cos^{2} #theta");
  D0VsCosSq->GetYaxis()->SetTitleOffset(1.5);
  D0VsCosSq->GetXaxis()->SetTitle("Distance to injection D_{0} [m]");
  D0VsCosSq->GetYaxis()->SetTitleOffset(1.2);
  D0VsCosSq->GetXaxis()->SetTitleOffset(1.2);
  D0VsCosSq->GetYaxis()->SetLabelSize(.06);
  D0VsCosSq->GetYaxis()->SetTitleSize(.065);
  D0VsCosSq->GetXaxis()->SetLabelSize(.06);
  D0VsCosSq->GetXaxis()->SetTitleSize(.065);
  D0VsCosSq->GetXaxis()->SetLabelFont(132);
  D0VsCosSq->GetYaxis()->SetLabelFont(132);
  D0VsCosSq->GetXaxis()->SetTitleFont(132);
  D0VsCosSq->GetYaxis()->SetTitleFont(132);
  D0VsCosSq->GetXaxis()->CenterTitle();
  D0VsCosSq->GetYaxis()->CenterTitle();

  D0VsCosSq->Draw("COLZ");

  ss.clear();
  ss.str(std::string());
  ss << figureDirectoryName << "D0VsCosSq.pdf";
  name = ss.str();
  CanvasD0VsCosSq->Print(name.c_str());
  delete CanvasD0VsCosSq;


  TCanvas *CanvasD0VsCosSqReWeight = new TCanvas("CanvasD0VsCosSqReWeight", "", 200, 10, 700,530);
  CanvasD0VsCosSqReWeight->SetBottomMargin(0.18);
  CanvasD0VsCosSqReWeight->SetTopMargin(0.16);
  CanvasD0VsCosSqReWeight->SetFrameLineWidth(2);
  CanvasD0VsCosSqReWeight->SetLineWidth(2);
  //gStyle->SetTickLength(0.02,"z");
  CanvasD0VsCosSqReWeight->SetLeftMargin(0.15);
  CanvasD0VsCosSqReWeight->SetRightMargin(0.15);

  D0VsCosSqReWeight->SetTitle("");

  D0VsCosSqReWeight->GetYaxis()->SetTitle("cos^{2} #theta");
  D0VsCosSqReWeight->GetYaxis()->SetTitleOffset(1.5); 
  D0VsCosSqReWeight->GetXaxis()->SetTitle("Distance to injection D_{0} [m]");
  D0VsCosSqReWeight->GetYaxis()->SetTitleOffset(1.2);
  D0VsCosSqReWeight->GetXaxis()->SetTitleOffset(1.2);
  D0VsCosSqReWeight->GetYaxis()->SetLabelSize(.06);
  D0VsCosSqReWeight->GetYaxis()->SetTitleSize(.065);
  D0VsCosSqReWeight->GetXaxis()->SetLabelSize(.06);
  D0VsCosSqReWeight->GetXaxis()->SetTitleSize(.065);
  D0VsCosSqReWeight->GetXaxis()->SetLabelFont(132);
  D0VsCosSqReWeight->GetYaxis()->SetLabelFont(132);
  D0VsCosSqReWeight->GetXaxis()->SetTitleFont(132);
  D0VsCosSqReWeight->GetYaxis()->SetTitleFont(132);
  D0VsCosSqReWeight->GetXaxis()->CenterTitle();
  D0VsCosSqReWeight->GetYaxis()->CenterTitle();
  D0VsCosSqReWeight->Draw("COLZ");

  ss.clear();
  ss.str(std::string());
  ss << figureDirectoryName << "D0VsCosSqReWeight.pdf";
  name = ss.str();
  CanvasD0VsCosSqReWeight->Print(name.c_str());
  delete CanvasD0VsCosSqReWeight;


  TCanvas *CanvasWeightedD0vsZenith = new TCanvas("CanvasWeightedD0vsZenith", "", 200, 10, 700,530);
  CanvasWeightedD0vsZenith->SetBottomMargin(0.18);
  CanvasWeightedD0vsZenith->SetTopMargin(0.16);
  CanvasWeightedD0vsZenith->SetFrameLineWidth(2);
  CanvasWeightedD0vsZenith->SetLineWidth(2);
  //gStyle->SetTickLength(0.02,"z");
  CanvasWeightedD0vsZenith->SetLeftMargin(0.15);
  CanvasWeightedD0vsZenith->SetRightMargin(0.15);
  D1vsZenith->SetTitle("");
  D1vsZenith->GetYaxis()->SetTitle("#theta [#circ]");
  D1vsZenith->GetYaxis()->SetTitleOffset(1.5);
  D1vsZenith->GetYaxis()->SetRangeUser(110,150);
  D1vsZenith->GetXaxis()->SetTitle("Distance [m]");
  D1vsZenith->GetYaxis()->SetTitleOffset(1.2);
  D1vsZenith->GetXaxis()->SetTitleOffset(1.2);
  D1vsZenith->GetYaxis()->SetLabelSize(.06);
  D1vsZenith->GetYaxis()->SetTitleSize(.065);
  D1vsZenith->GetXaxis()->SetLabelSize(.06);
  D1vsZenith->GetXaxis()->SetTitleSize(.065);
  D1vsZenith->GetXaxis()->SetLabelFont(132);
  D1vsZenith->GetYaxis()->SetLabelFont(132);
  D1vsZenith->GetXaxis()->SetTitleFont(132);
  D1vsZenith->GetYaxis()->SetTitleFont(132);
  D1vsZenith->GetXaxis()->CenterTitle();
  D1vsZenith->GetYaxis()->CenterTitle();
  D1vsZenith->SetLineColor(kRed+1);
  D1vsZenith->SetLineWidth(2);
  D1vsZenith->Draw();

  WeightedD0vsZenith->SetLineWidth(2);
  WeightedD0vsZenith->SetLineColor(kBlue+1);
  // gStyle->SetStatY(.7);
  WeightedD0vsZenith->Draw("same");

  TLegend *legDvsZenith = new TLegend(.4,0.65,.85,0.84);
  legDvsZenith->AddEntry(D1vsZenith, "Flat in D_{1}", "lp");
  legDvsZenith->AddEntry(WeightedD0vsZenith, "Re-weighted - flat in D_{0}", "lp");

  legDvsZenith->SetBorderSize(1);
  legDvsZenith->SetTextSize(.055);
  legDvsZenith->SetTextFont(132);
  legDvsZenith->SetMargin(.2);

  legDvsZenith->Draw("same");

  ss.clear();
  ss.str(std::string());
  ss << figureDirectoryName << "WeightedD0vsZenith.pdf";
  name = ss.str();
  CanvasWeightedD0vsZenith->Print(name.c_str());
  delete CanvasWeightedD0vsZenith;


  TCanvas *CanvasWeightedD0Hist = new TCanvas("CanvasWeightedD0Hist", "", 200, 10, 600, 400);

  // D1Cut->GetYaxis()->SetTitle("#theta [#circ]");
  D0Weighted->GetYaxis()->SetTitleOffset(1.5);
  // D1Cut->GetYaxis()->SetRangeUser(110,150);
  D0Weighted->GetXaxis()->SetTitle("Distance [m]");
  D1Cut->SetLineColor(kRed+1);
  D1Cut->SetLineWidth(2);
  D0Weighted->SetLineWidth(2);
  D0Weighted->Draw();
  D0Weighted->SetLineColor(kBlue+1);
  D1Cut->Draw("same");

  ss.clear();
  ss.str(std::string());
  ss << figureDirectoryName << "WeightedD0Hist.pdf";
  name = ss.str();
  CanvasWeightedD0Hist->Print(name.c_str());
  delete CanvasWeightedD0Hist;

}

Double_t TotalFitFunc(Double_t *x, Double_t *par) {//linear rising function. Matches data better in some bins
  Double_t fitval;

    fitval = TMath::Exp(par[1]*(x[0] - par[0]));
    fitval += par[2]*x[0] +  par[3];

  return fitval;
}

Double_t ParFunc(Double_t *x, Double_t *par) {//linear rising function. Matches data better in some bins

  return  par[1]/(cos(x[0]*ToRad) * cos(x[0]*ToRad)) - par[0]/cos(x[0]*ToRad) + par[2];
}
