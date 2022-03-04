#include <cmath>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>
#include <iomanip>    // std::setw
#include <string>
#include <sstream>
#include <fstream>
#include <stdexcept>
#include <unistd.h>
#include <ctime>

#include <TFile.h>
#include <TH1.h>
#include <TProfile.h>
#include <THistPainter.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TColor.h>
#include <TF1.h>
#include <TGraph.h>
#include <TGraphErrors.h>
#include <TFormula.h>
#include <TF1.h>
#include <TArrow.h>
#include <TLatex.h>
#include <TGraphAsymmErrors.h>
#include <TGaxis.h>
#include <TVector.h>

using namespace std;

Double_t DistanceFunc(Double_t *x,Double_t *par) {
  Double_t fitval;

  if(x[0] <= par[1]){
    fitval = par[0];
  }
  else{
    fitval = par[0] * (1.132 * 9000 * 9000 / (x[0] * x[0]) - 0.132);
  }
  return fitval;
} 



void PlotGenerationMethods(){
  //Set Ploting Options Plotting
  gStyle->SetOptStat(0);
  gStyle->SetStatX(.95);// Set x-position (fraction of pad size)
  gStyle->SetStatY(.9);// Set y-position (fraction of pad size)
  gStyle->SetStatW(0.4);// Set width of stat-box (fraction of pad size)
  gStyle->SetStatH(0.12);// Set height of stat-box (fraction of pad size)
  gStyle->SetOptFit(0);
  gStyle->SetPalette(1);
  gStyle->SetCanvasColor(0); //make a white background
  gStyle->SetCanvasBorderMode(0); //turn off the 'raised picture' look
  gStyle->SetFrameBorderMode(0);  //turn off the red axis frames
  gStyle->SetTitleFillColor(0);
  gStyle->SetTitleBorderSize(0);
  gStyle->SetStatColor(0);
  gStyle->SetStatBorderSize(0);
  gStyle->SetPadColor(0);
  gStyle->SetLegendBorderSize(0);
  gStyle->SetFrameLineWidth(1.5);
  gStyle->SetLineWidth(1);
  gStyle->SetEndErrorSize(0);
  //gStyle->SetOptStat(0);
  gStyle->SetPalette(1);

  //Read in Data Files


  TFile *OutFile    = new TFile("Out1E8EventsUpgoingTheta.root","READ");
  // TFile *OutFile    = new TFile("test.root","READ");

  TH1F* ZenithD = (TH1F*) OutFile->Get("ZenithD");
  TH1F* CosZenithD = (TH1F*) OutFile->Get("CosZenithD");
  TH1F* CosSqZenithD = (TH1F*) OutFile->Get("CosSqZenithD");

  TH1F* HFromD = (TH1F*) OutFile->Get("HFromD");
  TH1F* HFromDCos = (TH1F*) OutFile->Get("HFromDCos");
  TH1F* HFromDCosSq = (TH1F*) OutFile->Get("HFromDCosSq");

  TProfile* HFromDvsZenith = (TProfile*) OutFile->Get("HFromDvsZenith");
  TProfile* HFromDCosvsZenith = (TProfile*) OutFile->Get("HFromDCosvsZenith");
  TProfile* HFromDCosSqvsZenith = (TProfile*) OutFile->Get("HFromDCosSqvsZenith");

  TH1F* FlatDCosSqCut = (TH1F*) OutFile->Get("FlatDCosSqCut");
  TProfile* FlatDCosSqvsZenithCut =(TProfile*) OutFile->Get("FlatDCosSqvsZenithCut");

  //try to change angles from 

  TProfile* FlatDCosSqvsZenith =(TProfile*) OutFile->Get("FlatDCosSqvsZenith");
  TH1F* FlatDCosSq = (TH1F*) OutFile->Get("FlatDCosSq");

  TH1F* ZenithGen = (TH1F*) OutFile->Get("ZenithH");
  TH1F* CosZenithGen = (TH1F*) OutFile->Get("CosZenithH");
  TH1F* CosSqZenithGen = (TH1F*) OutFile->Get("CosSqZenithH");
  TH1F* Cos3ZenithGen = (TH1F*) OutFile->Get("Cos3ZenithH");

  TH1F* DFromH = (TH1F*) OutFile->Get("DFromH");
  TH1F* DFromHCos = (TH1F*) OutFile->Get("DFromHCos");
  TH1F* DFromHCosSq = (TH1F*) OutFile->Get("DFromHCosSq");

  TProfile* DFromHvsZenith = (TProfile*) OutFile->Get("DFromHvsZenith");
  TProfile* DFromHCosvsZenith = (TProfile*) OutFile->Get("DFromHCosvsZenith");
  TProfile* DFromHCosSqvsZenith = (TProfile*) OutFile->Get("DFromHCosSqvsZenith");


  TH1F* ZenithDFromHmax = (TH1F*) OutFile->Get("ZenithDFromHmax");
  TH1F* CosZenithDFromHmax = (TH1F*) OutFile->Get("CosZenithDFromHmax");
  TH1F* CosSqZenithDFromHmax = (TH1F*) OutFile->Get("CosSqZenithDFromHmax");

  TH1F* DFromDFromHmax = (TH1F*) OutFile->Get("DFromDFromHmax");
  TH1F* DFromDFromHmaxCos = (TH1F*) OutFile->Get("DFromDFromHmaxCos");
  TH1F* DFromDFromHmaxCosSq = (TH1F*) OutFile->Get("DFromDFromHmaxCosSq");

  TProfile* DFromDFromHmaxvsZenith = (TProfile*) OutFile->Get("DFromDFromHmaxvsZenith");
  TProfile* DFromDFromHmaxCosvsZenith = (TProfile*) OutFile->Get("DFromDFromHmaxCosvsZenith");
  TProfile* DFromDFromHmaxCosSqvsZenith = (TProfile*) OutFile->Get("DFromDFromHmaxCosSqvsZenith");


  TH1F* X1Depth = (TH1F*) OutFile->Get("X1Depth");
  TH1F* X0FromDFromHmaxCos = (TH1F*) OutFile->Get("X0FromDFromHmaxCos");
  

  // ZenithOn->Sumw2();
  // ZenithOn->Scale(1/ZenithOn->GetMaximum());



  Double_t ymin, ymax;

  double scale = 100/1000000.0;

  // CosSqZenithD->Sumw2();
  // CosSqZenithD->Scale(scale);
  // CosSqZenithGen->Sumw2();
  // CosSqZenithGen->Scale(scale); 
  // CosSqZenithDFromHmax->Sumw2();
  // CosSqZenithDFromHmax->Scale(scale);
  // CosZenithDFromHmax->Sumw2();
  // CosZenithDFromHmax->Scale(scale);

  TCanvas *ZenithCanvas = new TCanvas("ZenithCanvas", "Zenith", 200, 10, 500, 400);

  //Set Canvas Margins
  ZenithCanvas->Draw();
  ZenithCanvas->SetRightMargin(0.04);
  ZenithCanvas->SetLeftMargin(0.12);
  ZenithCanvas->SetTopMargin(0.08);
  ZenithCanvas->SetBottomMargin(0.12);
  ZenithCanvas->SetTicks(0, 0);


  CosSqZenithD->SetTitle("Zenith Distributions");
  CosSqZenithD->GetXaxis()->SetLabelFont(132);
  CosSqZenithD->GetXaxis()->SetTitleFont(132);
  CosSqZenithD->GetYaxis()->SetLabelFont(132);
  CosSqZenithD->GetYaxis()->SetTitleFont(132);
  CosSqZenithD->GetXaxis()->SetRangeUser(90,180);
  CosSqZenithD->GetXaxis()->SetTitleSize(.05);
  CosSqZenithD->GetXaxis()->CenterTitle();
  CosSqZenithD->GetXaxis()->SetTitle("#font[132]{#theta [#circ]}");
  CosSqZenithD->GetXaxis()->SetTitleSize(.06);
  CosSqZenithD->GetXaxis()->SetLabelSize(.05);
  CosSqZenithD->GetXaxis()->SetTitleOffset(.95);

  CosSqZenithD->GetYaxis()->SetRangeUser(0,1.7/scale);
  CosSqZenithD->GetYaxis()->CenterTitle();
  CosSqZenithD->GetYaxis()->SetTitle("Event Count");
  CosSqZenithD->GetYaxis()->SetTitleSize(.06);
  CosSqZenithD->GetYaxis()->SetLabelSize(.05);
  CosSqZenithD->GetYaxis()->SetTitleOffset(.9);

  CosSqZenithD->SetLineColor(15);
  CosSqZenithD->SetLineWidth(6);
  CosSqZenithD->Draw("l");

  CosSqZenithGen->SetLineColor(kCyan+2);
  CosSqZenithGen->SetLineWidth(4);
  CosSqZenithGen->SetLineStyle(1);
  CosSqZenithGen->Draw("lsames");

  CosSqZenithDFromHmax->SetLineColor(kRed);
  CosSqZenithDFromHmax->SetLineWidth(4);
  CosSqZenithDFromHmax->SetLineStyle(7);
  CosSqZenithDFromHmax->Draw("lsames");

  CosZenithDFromHmax->SetLineColor(1);
  CosZenithDFromHmax->SetLineWidth(2);
  CosZenithDFromHmax->SetLineStyle(1);
  CosZenithDFromHmax->Draw("lsames");
  
  TH1F* CosZenithDFromHmaxScale = CosZenithDFromHmax->Clone("CosZenithDFromHmaxScale");
  CosZenithDFromHmaxScale->Scale(0.51);
  CosZenithDFromHmaxScale->SetLineColor(1);
  CosZenithDFromHmaxScale->SetLineWidth(2);
  CosZenithDFromHmaxScale->SetLineStyle(7);
  CosZenithDFromHmaxScale->Draw("lsames");


  TLegend* FitLegend = new TLegend(0.15, .67, .9, .92,NULL,"brNDCARC");
  FitLegend->SetFillColor(0);
  FitLegend->SetTextFont(132);
  FitLegend->SetFillStyle(0);
  FitLegend->SetMargin(0.09);
  FitLegend->SetBorderSize(0);
  FitLegend->SetTextSize(0.035);


  std::ostringstream legendCut;
  std::ostringstream legendGen;
  std::ostringstream legendHtoDCos2;
  std::ostringstream legendHtoDCos;


  legendCut << fixed <<setprecision(1)
              << "D_{Flat}  H_{max} Cut       cos(#theta)^{2}:  #mu = " << CosSqZenithD->GetMean()
              << "#circ  % Kept = " << 100 * float(CosSqZenithD->GetEntries())/100000000.0;

  legendGen << fixed <<setprecision(1)
              << "D_{Flat}  No H Cut      cos(#theta)^{2}:   #mu = " << CosSqZenithGen->GetMean()
              << "#circ  % Kept = " << 100 *   float(CosSqZenithGen->GetEntries())/100000000.0;

  legendHtoDCos2 << fixed <<setprecision(1)
              << "H_{Flat}  D=H/cos(#theta)   cos(#theta)^{2}:  #mu = " << CosSqZenithDFromHmax->GetMean()
              << "#circ  % Kept = " << 100 * float(CosSqZenithDFromHmax->GetEntries())/100000000.0;

  legendHtoDCos << fixed <<setprecision(1)
              << "#font[22]{H_{Flat}  D=H/cos(#theta)   cos(#theta):  #mu = " << CosZenithDFromHmax->GetMean()
              << "#circ  % Kept = " << 100 * float(CosZenithDFromHmax->GetEntries())/100000000.0<<"}";

  FitLegend->AddEntry(CosSqZenithD, legendCut.str().c_str(), "l");
  FitLegend->AddEntry(CosSqZenithGen, legendGen.str().c_str(), "l");
  FitLegend->AddEntry(CosSqZenithDFromHmax, legendHtoDCos2.str().c_str(), "l");
  FitLegend->AddEntry(CosZenithDFromHmax, legendHtoDCos.str().c_str(), "l");
  FitLegend->AddEntry(CosZenithDFromHmaxScale,"H_{Flat}  D=H/cos(#theta)    cos(#theta):   Scaled", "l");


  FitLegend->Draw("same");

  ZenithCanvas->Print("Zenith.pdf");

  //delete ZenithCanvas;





//======================================================================================================

 TCanvas *DvsZenithCanvas = new TCanvas("DvsZenithCanvas", "Zenith", 200, 10, 730,500);
  //Set Canvas Margins
  // DvsZenithCanvas->Draw();
  // DvsZenithCanvas->SetRightMargin(0.04);
  // DvsZenithCanvas->SetLeftMargin(0.12);
  // DvsZenithCanvas->SetTopMargin(0.08);
  // DvsZenithCanvas->SetBottomMargin(0.12);
  // DvsZenithCanvas->SetTicks(0, 0);

	DvsZenithCanvas->SetBottomMargin(0.18);
	DvsZenithCanvas->SetTopMargin(0.07);
	DvsZenithCanvas->SetFrameLineWidth(2);
	DvsZenithCanvas->SetLineWidth(2);
	//gStyle->SetTickLength(0.02,"z");
	DvsZenithCanvas->SetLeftMargin(0.15);
	DvsZenithCanvas->SetRightMargin(0.04);


  //FlatDCosSqvsZenithCut->SetTitle("Distance vs Zenith Profiles");
	FlatDCosSqvsZenithCut->SetTitle("");
  FlatDCosSqvsZenithCut->GetXaxis()->SetLabelFont(132);
  FlatDCosSqvsZenithCut->GetXaxis()->SetTitleFont(132);
  FlatDCosSqvsZenithCut->GetYaxis()->SetLabelFont(132);
  FlatDCosSqvsZenithCut->GetYaxis()->SetTitleFont(132);

  // FlatDCosSqvsZenithCut->GetXaxis()->SetRangeUser(0,90);
  FlatDCosSqvsZenithCut->GetXaxis()->SetTitleSize(.05);
  FlatDCosSqvsZenithCut->GetXaxis()->CenterTitle();
  FlatDCosSqvsZenithCut->GetXaxis()->SetTitle("Distance from core D_{1} [m]");
  FlatDCosSqvsZenithCut->GetXaxis()->SetTitleSize(.06);
  FlatDCosSqvsZenithCut->GetXaxis()->SetLabelSize(.05);
  FlatDCosSqvsZenithCut->GetXaxis()->SetTitleOffset(1.15);

  FlatDCosSqvsZenithCut->GetYaxis()->SetRangeUser(35,80);
  FlatDCosSqvsZenithCut->GetYaxis()->SetRangeUser(100,150);
  FlatDCosSqvsZenithCut->GetYaxis()->CenterTitle();
  FlatDCosSqvsZenithCut->GetYaxis()->SetTitle("#font[132]{#LT #theta #GT [#circ]}");
  FlatDCosSqvsZenithCut->GetYaxis()->SetTitleSize(.06);
  FlatDCosSqvsZenithCut->GetYaxis()->SetLabelSize(.05);
  FlatDCosSqvsZenithCut->GetYaxis()->SetTitleOffset(.9);

  FlatDCosSqvsZenithCut->SetLineColor(15);
  FlatDCosSqvsZenithCut->SetLineWidth(6);
  FlatDCosSqvsZenithCut->Draw("l");

  FlatDCosSqvsZenith->SetLineColor(kCyan+2);
  FlatDCosSqvsZenith->SetLineWidth(4);
  FlatDCosSqvsZenith->SetLineStyle(1);
  FlatDCosSqvsZenith->Draw("lsames");

  DFromDFromHmaxCosSqvsZenith->SetLineColor(kRed);
  DFromDFromHmaxCosSqvsZenith->SetLineWidth(4);
  DFromDFromHmaxCosSqvsZenith->SetLineStyle(7);
  DFromDFromHmaxCosSqvsZenith->Draw("lsames");

  DFromDFromHmaxCosvsZenith->SetLineColor(1);
  DFromDFromHmaxCosvsZenith->SetLineWidth(2);
  DFromDFromHmaxCosvsZenith->SetLineStyle(1);
  DFromDFromHmaxCosvsZenith->Draw("lsames");
  

  TLegend* FitLegend = new TLegend(0.15, .72, .9, .92,NULL,"brNDCARC");
  FitLegend->SetFillColor(0);
  FitLegend->SetTextFont(132);
  FitLegend->SetFillStyle(0);
  FitLegend->SetMargin(0.09);
  FitLegend->SetBorderSize(0);
  FitLegend->SetTextSize(0.035);

// egESVsUpGoingVsCombinedDiffSigma[iSigma]->SetBorderSize(1);
// 	legESVsUpGoingVsCombinedDiffSigma[iSigma]->SetTextSize(.07);
// 	legESVsUpGoingVsCombinedDiffSigma[iSigma]->SetTextFont(132);
// 	legESVsUpGoingVsCombinedDiffSigma[iSigma]->SetMargin(.2);


  std::ostringstream legendCut;
  std::ostringstream legendGen;
  std::ostringstream legendHtoDCos2;
  std::ostringstream legendHtoDCos;

  legendCut << fixed <<setprecision(1)
              << "D_{Flat}  H_{max} Cut       cos(#theta)^{2}:  #mu = " << CosSqZenithD->GetMean()
              << "#circ  % Kept = " << 100 * float(CosSqZenithD->GetEntries())/100000000.0;

  legendGen << fixed <<setprecision(1)
              << "D_{Flat}  No H Cut      cos(#theta)^{2}:   #mu = " << CosSqZenithGen->GetMean()
              << "#circ  % Kept = " << 100 *   float(CosSqZenithGen->GetEntries())/100000000.0;

  legendHtoDCos2 << fixed <<setprecision(1)
              << "H_{Flat}  D=H/cos(#theta)   cos(#theta)^{2}:  #mu = " << CosSqZenithDFromHmax->GetMean()
              << "#circ  % Kept = " << 100 * float(CosSqZenithDFromHmax->GetEntries())/100000000.0;

  legendHtoDCos << fixed <<setprecision(1)
              << "#font[22]{H_{Flat}  D=H/cos(#theta)   cos(#theta):  #mu = " << CosZenithDFromHmax->GetMean()
              << "#circ  % Kept = " << 100 * float(CosZenithDFromHmax->GetEntries())/100000000.0<<"}";

  FitLegend->AddEntry(FlatDCosSqvsZenithCut, legendCut.str().c_str(), "l");
  FitLegend->AddEntry(FlatDCosSqvsZenith, legendGen.str().c_str(), "l");
  FitLegend->AddEntry(DFromDFromHmaxCosSqvsZenith, legendHtoDCos2.str().c_str(), "l");
  FitLegend->AddEntry(DFromDFromHmaxCosvsZenith, legendHtoDCos.str().c_str(), "l");



  FitLegend->Draw("same");

  DvsZenithCanvas->Print("DvsZenith.pdf");

// DvsZenithCanvas->Draw();

  //delete DvsZenithCanvas;






//======================================================================================================

 TCanvas *DCanvas = new TCanvas("DCanvas", "Zenith", 200, 10, 500, 400);

  //Set Canvas Margins
  DCanvas->Draw();
  DCanvas->SetRightMargin(0.04);
  DCanvas->SetLeftMargin(0.12);
  DCanvas->SetTopMargin(0.08);
  DCanvas->SetBottomMargin(0.12);
  DCanvas->SetTicks(0, 0);


  FlatDCosSqCut->SetTitle("Distance from Shower Core");
  FlatDCosSqCut->GetXaxis()->SetLabelFont(132);
  FlatDCosSqCut->GetXaxis()->SetTitleFont(132);
  FlatDCosSqCut->GetYaxis()->SetLabelFont(132);
  FlatDCosSqCut->GetYaxis()->SetTitleFont(132);
  // FlatDCosSqCut->GetXaxis()->SetRangeUser(0,90);
  FlatDCosSqCut->GetXaxis()->SetTitleSize(.05);
  FlatDCosSqCut->GetXaxis()->CenterTitle();
  FlatDCosSqCut->GetXaxis()->SetTitle("Distance from core [m]");
  FlatDCosSqCut->GetXaxis()->SetTitleSize(.06);
  FlatDCosSqCut->GetXaxis()->SetLabelSize(.05);
  FlatDCosSqCut->GetXaxis()->SetTitleOffset(.95);

  FlatDCosSqCut->GetYaxis()->SetRangeUser(0,3.2/scale);
  FlatDCosSqCut->GetYaxis()->CenterTitle();
  FlatDCosSqCut->GetYaxis()->SetTitle("#font[132]{Event Count}");
  FlatDCosSqCut->GetYaxis()->SetTitleSize(.06);
  FlatDCosSqCut->GetYaxis()->SetLabelSize(.05);
  FlatDCosSqCut->GetYaxis()->SetTitleOffset(.9);

  FlatDCosSqCut->SetLineColor(15);
  FlatDCosSqCut->SetLineWidth(6);
  FlatDCosSqCut->Draw("l");

  FlatDCosSq->SetLineColor(kCyan+2);
  FlatDCosSq->SetLineWidth(4);
  FlatDCosSq->SetLineStyle(1);
  FlatDCosSq->Draw("lsames");

  DFromDFromHmaxCosSq->SetLineColor(kRed);
  DFromDFromHmaxCosSq->SetLineWidth(4);
  DFromDFromHmaxCosSq->SetLineStyle(7);
  DFromDFromHmaxCosSq->Draw("lsames");

  DFromDFromHmaxCos->SetLineColor(1);
  DFromDFromHmaxCos->SetLineWidth(2);
  DFromDFromHmaxCos->SetLineStyle(1);
  DFromDFromHmaxCos->Draw("lsames");
  
  TH1F* DFromDFromHmaxCosScale = DFromDFromHmaxCos->Clone("DFromDFromHmaxCos");
  DFromDFromHmaxCosScale->Scale(0.51);
  DFromDFromHmaxCosScale->SetLineColor(1);
  DFromDFromHmaxCosScale->SetLineWidth(2);
  DFromDFromHmaxCosScale->SetLineStyle(7);
  DFromDFromHmaxCosScale->Draw("lsames");



  TLegend* FitLegend = new TLegend(0.15, .67, .9, .92,NULL,"brNDCARC");
  FitLegend->SetFillColor(0);
  FitLegend->SetTextFont(132);
  FitLegend->SetFillStyle(0);
  FitLegend->SetMargin(0.09);
  FitLegend->SetBorderSize(0);
  FitLegend->SetTextSize(0.035);


  std::ostringstream legendCut;
  std::ostringstream legendGen;
  std::ostringstream legendHtoDCos2;
  std::ostringstream legendHtoDCos;


  legendCut << fixed <<setprecision(0)
              << "D_{Flat}  H_{max} Cut       cos(#theta)^{2}:  #mu = " << FlatDCosSqCut->GetMean()
              << "    % Kept = " << 100 * float(FlatDCosSqCut->GetEntries())/100000000.0;

  legendGen << fixed <<setprecision(0)
              << "D_{Flat}  No H Cut      cos(#theta)^{2}:  #mu = " << FlatDCosSq->GetMean()
              << "   % Kept = " << 100 * float(FlatDCosSq->GetEntries())/100000000.0;

  legendHtoDCos2 << fixed <<setprecision(0)
              << "H_{Flat}  D=H/cos(#theta)  cos(#theta)^{2}:  #mu = " << DFromDFromHmaxCosSq->GetMean()
              << "     % Kept = " << 100 * float(DFromDFromHmaxCosSq->GetEntries())/100000000.0;

  legendHtoDCos << fixed <<setprecision(0)
              << "#font[22]{H_{Flat}  D=H/cos(#theta)  cos(#theta):  #mu = " << DFromDFromHmaxCos->GetMean()
              << "    % Kept = " << 100 * float(DFromDFromHmaxCos->GetEntries())/100000000.0<<"}";


  FitLegend->AddEntry(FlatDCosSqCut, legendCut.str().c_str(), "l");
  FitLegend->AddEntry(FlatDCosSq, legendGen.str().c_str(), "l");
  FitLegend->AddEntry(DFromDFromHmaxCosSq, legendHtoDCos2.str().c_str(), "l");
  FitLegend->AddEntry(DFromDFromHmaxCos, legendHtoDCos.str().c_str(), "l");
  FitLegend->AddEntry(DFromDFromHmaxCosScale, "H_{Flat}  D=H/cos(#theta),   cos(#theta):   Scaled", "l");



  FitLegend->Draw("same");

  DCanvas->Print("D.pdf");

  delete DCanvas;







  TF1* DFit = new TF1("DFit",DistanceFunc,0,27000,2); //With flat top
  DFit->SetParameter(0,0.02);
  DFit->SetParameter(1,9000);

  Double_t N = DFromDFromHmaxCos->GetEntries();
  DFromDFromHmaxCos->Sumw2();
  DFromDFromHmaxCos->Scale(1/N);

  Double_t Nx1 = X0FromDFromHmaxCos->GetEntries();
  X0FromDFromHmaxCos->Sumw2();
  X0FromDFromHmaxCos->Scale(1/Nx1);


  TCanvas *DNormCanvas = new TCanvas("DNormCanvas", "X0 Distance", 200, 10, 500, 400);

  //Set Canvas Margins
  DNormCanvas->Draw();
  DNormCanvas->SetRightMargin(0.04);
  DNormCanvas->SetLeftMargin(0.12);
  DNormCanvas->SetTopMargin(0.08);
  DNormCanvas->SetBottomMargin(0.12);
  DNormCanvas->SetTicks(0, 0);


  DFromDFromHmaxCos->SetTitle("Normalized Xfirst and XInject Distances");
  DFromDFromHmaxCos->GetXaxis()->SetLabelFont(132);
  DFromDFromHmaxCos->GetXaxis()->SetTitleFont(132);
  DFromDFromHmaxCos->GetYaxis()->SetLabelFont(132);
  DFromDFromHmaxCos->GetYaxis()->SetTitleFont(132);
  DFromDFromHmaxCos->GetXaxis()->SetTitleSize(.05);
  DFromDFromHmaxCos->GetXaxis()->CenterTitle();
  DFromDFromHmaxCos->GetXaxis()->SetTitle("Distance from core [m]");
  DFromDFromHmaxCos->GetXaxis()->SetTitleSize(.06);
  DFromDFromHmaxCos->GetXaxis()->SetLabelSize(.05);
  DFromDFromHmaxCos->GetXaxis()->SetTitleOffset(.95);

  DFromDFromHmaxCos->GetYaxis()->SetRangeUser(0,0.024);
  DFromDFromHmaxCos->GetYaxis()->CenterTitle();
  DFromDFromHmaxCos->GetYaxis()->SetTitle("#font[132]{Event Count}");
  DFromDFromHmaxCos->GetYaxis()->SetTitleSize(.06);
  DFromDFromHmaxCos->GetYaxis()->SetLabelSize(.05);
  DFromDFromHmaxCos->GetYaxis()->SetTitleOffset(.9);

  DFromDFromHmaxCos->SetLineColor(15);
  DFromDFromHmaxCos->SetLineWidth(6);
  DFromDFromHmaxCos->Draw("l");

  DFromDFromHmaxCos->Fit("DFit","0QN");
  DFit->Draw("sames");

  X0FromDFromHmaxCos->SetLineColor(1);
  X0FromDFromHmaxCos->SetLineWidth(2);
  X0FromDFromHmaxCos->SetLineStyle(1);
  X0FromDFromHmaxCos->Draw("lsames");


  TLegend* FitLegend = new TLegend(0.5, .77, .9, .92,NULL,"brNDCARC");
  FitLegend->SetFillColor(0);
  FitLegend->SetTextFont(132);
  FitLegend->SetFillStyle(0);
  FitLegend->SetMargin(0.09);
  FitLegend->SetBorderSize(0);
  FitLegend->SetTextSize(0.035);

  std::ostringstream legendDToX1;
  legendDToX1 << fixed <<setprecision(0)
              << "#font[22]{Flat Distance to X1}";

  std::ostringstream legendDToX0;
  legendDToX0 << fixed <<setprecision(0)
              << "#font[22]{Distance to XInject}";


  FitLegend->AddEntry(DFromDFromHmaxCos,legendDToX1.str().c_str(), "l");
  FitLegend->AddEntry(X0FromDFromHmaxCos, legendDToX0.str().c_str() , "l");


  FitLegend->Draw("same");

  DNormCanvas->Print("DToX1.pdf");

  delete DNormCanvas;

  
  // TH1F* CosZenithDFromHmaxScale = CosZenithDFromHmax->Clone("CosZenithDFromHmaxScale");
  TH1F* D0D1Ratio = DFromDFromHmaxCos->Clone("D0D1Ratio");
  D0D1Ratio->Sumw2();
  D0D1Ratio->Divide(X0FromDFromHmaxCos);

  TCanvas *RatioCanvas = new TCanvas("RatioCanvas", "D0/D1 Ratio", 200, 10, 500, 400);
  RatioCanvas->SetRightMargin(0.04);
  RatioCanvas->SetLeftMargin(0.12);
  RatioCanvas->SetTopMargin(0.08);
  RatioCanvas->SetBottomMargin(0.12);
  RatioCanvas->SetTicks(0, 0);

  D0D1Ratio->SetTitle("Ratio of D0 and D1 frequency");
  D0D1Ratio->GetXaxis()->SetLabelFont(132);
  D0D1Ratio->GetXaxis()->SetTitleFont(132);
  D0D1Ratio->GetYaxis()->SetLabelFont(132);
  D0D1Ratio->GetYaxis()->SetTitleFont(132);
  D0D1Ratio->GetXaxis()->SetTitleSize(.05);
  D0D1Ratio->GetXaxis()->CenterTitle();
  D0D1Ratio->GetXaxis()->SetTitle("Distance from core [m]");
  D0D1Ratio->GetXaxis()->SetTitleSize(.06);
  D0D1Ratio->GetXaxis()->SetLabelSize(.05);
  D0D1Ratio->GetXaxis()->SetTitleOffset(.95);

  D0D1Ratio->GetYaxis()->SetRangeUser(0.01,3);
  D0D1Ratio->GetYaxis()->CenterTitle();
  D0D1Ratio->GetYaxis()->SetTitle("#font[132]{Weight}");
  D0D1Ratio->GetYaxis()->SetTitleSize(.06);
  D0D1Ratio->GetYaxis()->SetLabelSize(.05);
  D0D1Ratio->GetYaxis()->SetTitleOffset(.9);

  D0D1Ratio->SetLineWidth(2);
  D0D1Ratio->SetLineColor(1);
  D0D1Ratio->Draw("l");

  TF1* WLT9000 = new TF1("WLT9000","pol6",0,9000);
  D0D1Ratio->Fit(WLT9000,"Q0N","",0,9000);
  WLT9000->SetLineColor(kRed);
  WLT9000->Draw("sames");

  TF1* WGT9000 = new TF1("WGT9000","pol6",9000,26000);
  D0D1Ratio->Fit(WGT9000,"Q0N","",9000,26000);
  WGT9000->SetLineColor(kAzure);
  WGT9000->Draw("sames");

  RatioCanvas->Print("Weights.pdf");

}