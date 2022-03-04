/*
 * Plot.C
 *
 *  Created on: Dec 6, 2016
 *      Author: mayotte
 */
void EfficiencyFDTau_H3(){ //run via root Plot.C

  //Start Plotting

 // gStyle->SetOptStat(1);

  gStyle->SetStatX(.95);
  gStyle->SetStatY(.9);
  // Set x-position (fraction of pad size)
  gStyle->SetStatW(0.4);
  // Set width of stat-box (fraction of pad size)
  gStyle->SetStatH(0.12);
  // Set height of stat-box (fraction of pad size)
  gStyle->SetOptFit(1);
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
  gStyle->SetOptStat(0);
  gStyle->SetPalette(1);

  const Int_t NRGBs = 5;
  const Int_t NCont = 80;

  Double_t stops[9] = { 0.0000, 0.1250, 0.2500, 0.3750, 0.5000, 0.6250, 0.7500, 0.8750, 1.0000};
  Double_t red[9]   = { 0.2082, 0.0592, 0.0780, 0.0232, 0.1802, 0.5301, 0.8186, 0.9956, 0.9764};
  Double_t green[9] = { 0.1664, 0.3599, 0.5041, 0.6419, 0.7178, 0.7492, 0.7328, 0.7862, 0.9832};
  Double_t blue[9]  = { 0.5293, 0.8684, 0.8385, 0.7914, 0.6425, 0.4662, 0.3499, 0.1968, 0.0539};
  TColor::CreateGradientColorTable(9, stops, red, green, blue, NCont);
  /*
  Double_t stops[NRGBs] = { 0.00, 0.34, 0.61, 0.84, 1.00 };
  Double_t red[NRGBs]   = { 0.00, 0.00, 0.87, 1.00, 0.51 };
  Double_t green[NRGBs] = { 0.00, 0.81, 1.00, 0.20, 0.00 };
  Double_t blue[NRGBs]  = { 0.51, 1.00, 0.12, 0.00, 0.00 };
  */
  //TColor::CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont);
  gStyle->SetNumberContours(NCont);

  const double XRange[2] = {17.4,21};
  const double MeanRange[2] = {600,820};
  const double SigmaRange[2] = {0,100};


TFile *TauEmin17Thetamin115H1 = new TFile("./Analysis_TauE17_17.5_theta115-120_H1.root ","READ");
//TFile *TauEmin17Thetamin120H1 = new TFile("./Analysis_TauE17_17.5_theta120-125_H1.root ","READ"); 
//TFile *TauEmin17Thetamin125H1 = new TFile("./Analysis_TauE17_17.5_theta125-130_H1.root ","READ");


TFile *TauEmin175Thetamin115H1 = new TFile("./Analysis_TauE17.5_18_theta115-120_H1.root ","READ");
// TFile *TauEmin175Thetamin120H1 = new TFile("./Analysis_TauE17.5_18_theta120-125_H1.root ","READ");
// TFile *TauEmin175Thetamin125H1 = new TFile("./Analysis_TauE17.5_18_theta125-130_H1.root ","READ");


TFile *TauEmin18Thetamin115H1 = new TFile("./Analysis_TauE18_18.5_theta115-120_H1.root ","READ");
// TFile *TauEmin18Thetamin120H1 = new TFile("./Analysis_TauE18_18.5_theta120-125_H1.root ","READ");
// TFile *TauEmin18Thetamin125H1 = new TFile("./Analysis_TauE18_18.5_theta125-130_H1.root ","READ");



 
TauEmin17Thetamin115H1->cd(); //change to file 1
  TGraphErrors *TriggeringEfficiencyEmin17Thetamin115H1        = ((TGraphErrors*) TauEmin17Thetamin115H1->Get("TriggeringEfficiency"));
  TVectorD *MeanDiffErecEmcEmin17Thetamin115H1 =    ((TVectorD*) TauEmin17Thetamin115H1->Get("MeanDiffErecEmc"));
  TVectorD *SigmaDiffErecEmcEmin17Thetamin115H1 =    ((TVectorD*) TauEmin17Thetamin115H1->Get("SigmaDiffErecEmc"));
  TH1F *HistoTrigEvOverGenEventsEmin17Thetamin115H1 = ((TH1F*) TauEmin17Thetamin115H1->Get("CloneHisto"));
  TH1F *HistoEnergyDifferenceEmin17Thetamin115H1 = ((TH1F*) TauEmin17Thetamin115H1->Get("HistoDifferenceE"));
  TH1F *HistoEnergylgEmcEmin17Thetamin115H1 = ((TH1F*) TauEmin17Thetamin115H1->Get("HistoLgEMC"));

/*TauEmin17Thetamin120H1->cd(); //change to file 1
  TGraphErrors *TriggeringEfficiencyEmin17Thetamin120H1        = ((TGraphErrors*) TauEmin17Thetamin120H1->Get("TriggeringEfficiency"));
  TVectorD *MeanDiffErecEmcEmin17Thetamin120H1 =    ((TVectorD*) TauEmin17Thetamin120H1->Get("MeanDiffErecEmc"));
  TVectorD *SigmaDiffErecEmcEmin17Thetamin120H1 =    ((TVectorD*) TauEmin17Thetamin120H1->Get("SigmaDiffErecEmc"));
  TH1F *HistoTrigEvOverGenEventsEmin17Thetamin120H1 = ((TH1F*) TauEmin17Thetamin120H1->Get("CloneHisto"));
  TH1F *HistoEnergyDifferenceEmin17Thetamin120H1 = ((TH1F*) TauEmin17Thetamin120H1->Get("HistoDifferenceE"));
  TH1F *HistoEnergylgEmcEmin17Thetamin120H1 = ((TH1F*) TauEmin17Thetamin120H1->Get("HistoLgEMC"));*/

/*TauEmin17Thetamin125H1->cd(); //change to file 1
  TGraphErrors *TriggeringEfficiencyEmin17Thetamin125H1        = ((TGraphErrors*) TauEmin17Thetamin125H1->Get("TriggeringEfficiency"));
  TVectorD *MeanDiffErecEmcEmin17Thetamin125H1 =    ((TVectorD*) TauEmin17Thetamin125H1->Get("MeanDiffErecEmc"));
  TVectorD *SigmaDiffErecEmcEmin17Thetamin125H1 =    ((TVectorD*) TauEmin17Thetamin125H1->Get("SigmaDiffErecEmc"));
  TH1F *HistoTrigEvOverGenEventsEmin17Thetamin125H1 = ((TH1F*) TauEmin17Thetamin125H1->Get("CloneHisto"));
  TH1F *HistoEnergyDifferenceEmin17Thetamin125H1 = ((TH1F*) TauEmin17Thetamin125H1->Get("HistoDifferenceE"));
  TH1F *HistoEnergylgEmcEmin17Thetamin125H1 = ((TH1F*) TauEmin17Thetamin125H1->Get("HistoLgEMC"));*/




 
TauEmin175Thetamin115H1->cd(); //change to file 1
  TGraphErrors *TriggeringEfficiencyEmin175Thetamin115H1        = ((TGraphErrors*) TauEmin175Thetamin115H1->Get("TriggeringEfficiency"));
  TVectorD *MeanDiffErecEmcEmin175Thetamin115H1 =    ((TVectorD*) TauEmin175Thetamin115H1->Get("MeanDiffErecEmc"));
  TVectorD *SigmaDiffErecEmcEmin175Thetamin115H1 =    ((TVectorD*) TauEmin175Thetamin115H1->Get("SigmaDiffErecEmc"));
  TH1F *HistoTrigEvOverGenEventsEmin175Thetamin115H1 = ((TH1F*) TauEmin175Thetamin115H1->Get("CloneHisto"));
  TH1F *HistoEnergyDifferenceEmin175Thetamin115H1 = ((TH1F*) TauEmin175Thetamin115H1->Get("HistoDifferenceE"));
  TH1F *HistoEnergylgEmcEmin175Thetamin115H1 = ((TH1F*) TauEmin175Thetamin115H1->Get("HistoLgEMC"));

// TauEmin175Thetamin120H1->cd(); //change to file 1
//   TGraphErrors *TriggeringEfficiencyEmin175Thetamin120H1        = ((TGraphErrors*) TauEmin175Thetamin120H1->Get("TriggeringEfficiency"));
//   TVectorD *MeanDiffErecEmcEmin175Thetamin120H1 =    ((TVectorD*) TauEmin175Thetamin120H1->Get("MeanDiffErecEmc"));
//   TVectorD *SigmaDiffErecEmcEmin175Thetamin120H1 =    ((TVectorD*) TauEmin175Thetamin120H1->Get("SigmaDiffErecEmc"));
//    TH1F *HistoTrigEvOverGenEventsEmin175Thetamin120H1 = ((TH1F*) TauEmin175Thetamin120H1->Get("CloneHisto"));
//    TH1F *HistoEnergyDifferenceEmin175Thetamin120H1 = ((TH1F*) TauEmin175Thetamin120H1->Get("HistoDifferenceE"));
//    TH1F *HistoEnergylgEmcEmin175Thetamin120H1 = ((TH1F*) TauEmin175Thetamin120H1->Get("HistoLgEMC"));

// TauEmin175Thetamin125H1->cd(); //change to file 1
//   TGraphErrors *TriggeringEfficiencyEmin175Thetamin125H1        = ((TGraphErrors*) TauEmin175Thetamin125H1->Get("TriggeringEfficiency"));
//   TVectorD *MeanDiffErecEmcEmin175Thetamin125H1 =    ((TVectorD*) TauEmin175Thetamin125H1->Get("MeanDiffErecEmc"));
//   TVectorD *SigmaDiffErecEmcEmin175Thetamin125H1 =    ((TVectorD*) TauEmin175Thetamin125H1->Get("SigmaDiffErecEmc"));
//    TH1F *HistoTrigEvOverGenEventsEmin175Thetamin125H1 = ((TH1F*) TauEmin175Thetamin125H1->Get("CloneHisto"));
//    TH1F *HistoEnergyDifferenceEmin175Thetamin125H1 = ((TH1F*) TauEmin175Thetamin125H1->Get("HistoDifferenceE"));
//    TH1F *HistoEnergylgEmcEmin175Thetamin125H1 = ((TH1F*) TauEmin175Thetamin125H1->Get("HistoLgEMC"));



 
TauEmin18Thetamin115H1->cd(); //change to file 1
  TGraphErrors *TriggeringEfficiencyEmin18Thetamin115H1        = ((TGraphErrors*) TauEmin18Thetamin115H1->Get("TriggeringEfficiency"));
  TVectorD *MeanDiffErecEmcEmin18Thetamin115H1 =    ((TVectorD*) TauEmin18Thetamin115H1->Get("MeanDiffErecEmc"));
  TVectorD *SigmaDiffErecEmcEmin18Thetamin115H1 =    ((TVectorD*) TauEmin18Thetamin115H1->Get("SigmaDiffErecEmc"));
  TH1F *HistoTrigEvOverGenEventsEmin18Thetamin115H1 = ((TH1F*) TauEmin18Thetamin115H1->Get("CloneHisto"));
  TH1F *HistoEnergyDifferenceEmin18Thetamin115H1 = ((TH1F*) TauEmin18Thetamin115H1->Get("HistoDifferenceE"));
  TH1F *HistoEnergylgEmcEmin18Thetamin115H1 = ((TH1F*) TauEmin18Thetamin115H1->Get("HistoLgEMC"));

// TauEmin18Thetamin120H1->cd(); //change to file 1
//   TGraphErrors *TriggeringEfficiencyEmin18Thetamin120H1        = ((TGraphErrors*) TauEmin18Thetamin120H1->Get("TriggeringEfficiency"));
//   TVectorD *MeanDiffErecEmcEmin18Thetamin120H1 =    ((TVectorD*) TauEmin18Thetamin120H1->Get("MeanDiffErecEmc"));
//   TVectorD *SigmaDiffErecEmcEmin18Thetamin120H1 =    ((TVectorD*) TauEmin18Thetamin120H1->Get("SigmaDiffErecEmc"));
//   TH1F *HistoTrigEvOverGenEventsEmin18Thetamin120H1 = ((TH1F*) TauEmin18Thetamin120H1->Get("CloneHisto"));
//   TH1F *HistoEnergyDifferenceEmin18Thetamin120H1 = ((TH1F*) TauEmin18Thetamin120H1->Get("HistoDifferenceE"));
//   TH1F *HistoEnergylgEmcEmin18Thetamin120H1 = ((TH1F*) TauEmin18Thetamin120H1->Get("HistoLgEMC"));

// TauEmin18Thetamin125H1->cd(); //change to file 1
//   TGraphErrors *TriggeringEfficiencyEmin18Thetamin125H1        = ((TGraphErrors*) TauEmin18Thetamin125H1->Get("TriggeringEfficiency"));
//   TVectorD *MeanDiffErecEmcEmin18Thetamin125H1 =    ((TVectorD*) TauEmin18Thetamin125H1->Get("MeanDiffErecEmc"));
//   TVectorD *SigmaDiffErecEmcEmin18Thetamin125H1 =    ((TVectorD*) TauEmin18Thetamin125H1->Get("SigmaDiffErecEmc"));
//   TH1F *HistoTrigEvOverGenEventsEmin18Thetamin125H1 = ((TH1F*) TauEmin18Thetamin125H1->Get("CloneHisto"));
//   TH1F *HistoEnergyDifferenceEmin18Thetamin125H1 = ((TH1F*) TauEmin18Thetamin125H1->Get("HistoDifferenceE"));
//   TH1F *HistoEnergylgEmcEmin18Thetamin125H1 = ((TH1F*) TauEmin18Thetamin125H1->Get("HistoLgEMC"));
  //TLine* ZeroLine = new TLine(17.7,0,19.7,0); // A line to put on your plots if you want one
  //ZeroLine->SetLineStyle(2);
	TH1F* Axis1 = new TH1F("Axis1","",100,0,520);

	TCanvas *Canvas1 = new TCanvas("Canvas1","Canvas name",200,10,700,400);  //sizes here so change the last 2 to make your plot whatever size you want

	TCanvas *Canvas2 = new TCanvas("Canvas2","Canvas name2",700,530);


	TCanvas *Canvas3 = new TCanvas("Canvas3","Canvas name3",200,10,700,400);
	TCanvas *Canvas4 = new TCanvas("Canvas4","Canvas name4",200,10,700,400);
	TCanvas *CanvasEnergydiff = new TCanvas("CanvasEnergydiff","Canvas Energydiff",200,10,700,400);
	TCanvas *CanvasSigmaEnergydiff = new TCanvas("CanvasSigmaEnergydiff","Canvas Sigma Energydiff",200,10,700,400);

	TCanvas *CanvaslgEfficiency = new TCanvas ("CanvaslgEfficiency", "CanvaslgEfficiency",200,10,700,400 );
	TCanvas *CanvaslgEfficiency120 = new TCanvas ("CanvaslgEfficiency120", "CanvaslgEfficiency120",200,10,700,400 );
	TCanvas *CanvaslgEfficiency125 = new TCanvas ("CanvaslgEfficiency125", "CanvaslgEfficiency125",200,10,700,400 );
  //Canvas1->SetGrid();
  
Canvas1->cd();
  Canvas1->SetRightMargin(0.02);//This changes the margins
  Canvas1->SetLeftMargin(0.175);
  Canvas1->SetTopMargin(0.02);
  Canvas1->SetBottomMargin(0.18);
  Canvas1->SetTicks(1,1);
  Axis1->GetYaxis()->SetRangeUser(0,30); //sets the Y axis range
  //Axis1->GetXaxis()->SetRangeUser(0,30); //sets the X axis range
  Axis1->GetYaxis()->SetLabelFont(132); //Nice font
  Axis1->GetYaxis()->SetTitleSize(.05); //changes the axis title size
  Axis1->GetYaxis()->CenterTitle(); //centers the axis title
  Axis1->GetYaxis()->SetTitle("#font[132]{Triggered Events}"); // This is the axis title uses latex code basically change '\alpha' for '#alpha' otherwist it is the same
  Axis1->GetYaxis()->SetTitleOffset(1.2); //distance between axis title and axis
  Axis1->GetXaxis()->SetTitleSize(.05);//changes the axis title size
  Axis1->GetXaxis()->CenterTitle();//centers the axis title
  Axis1->GetXaxis()->SetLabelFont(132); //Nice font
  Axis1->GetXaxis()->SetTitle("#font[132]{R_{FD} [km]}");// This is the axis title uses latex code basically change '\alpha' for '#alpha' otherwist it is the same
  Axis1->SetTitle(""); //Histogram title here
  // MeanAll->SetMarkerStyle(8); //changes style of plot points. dont need for a histogram
  // MeanAll->SetMarkerSize(1);
  //Mean1->SetLineWidth(2); //slightly thicker lines
  //Axis1->Draw(""); //draws histogram
//TriggeringEfficiencyEmin17Thetamin115H1->Draw("APC");

TriggeringEfficiencyEmin17Thetamin115H1->SetLineColor(kRed+4);
//TriggeringEfficiencyEmin17Thetamin120H1->SetLineColor(kRed);
//TriggeringEfficiencyEmin17Thetamin125H1->SetLineColor(kRed-5);

TMultiGraph *mg = new TMultiGraph();
mg->Add(TriggeringEfficiencyEmin17Thetamin115H1);
//mg->Add(TriggeringEfficiencyEmin17Thetamin120H1);
//mg->Add(TriggeringEfficiencyEmin17Thetamin125H1);
mg->SetTitle("Triggering Efficiency  ;Distance_{FD} [km]; TriggeredEvents");
//mg->Draw("APC");

MeanDiffErecEmcEmin17Thetamin115H1->Print();

cout<<"val?? "<<( (*MeanDiffErecEmcEmin17Thetamin115H1) )[0]<<"  "<< ( (*SigmaDiffErecEmcEmin17Thetamin115H1) )[0]  <<endl;
// Double_t MeanDiffErecEmcEmin17H1[1] = {( (*MeanDiffErecEmcEmin17Thetamin115H1) )[0] };
// Double_t SigmaDiffErecEmcEmin17H1[1] = {  ( (*SigmaDiffErecEmcEmin17Thetamin115H1) )[0]};


// Double_t MeanDiffErecEmcEmin175H1[3] = {( (*MeanDiffErecEmcEmin175Thetamin115H1) )[0], ( (*MeanDiffErecEmcEmin175Thetamin120H1) )[0], ( (*MeanDiffErecEmcEmin175Thetamin125H1) )[0]};
// Double_t SigmaDiffErecEmcEmin175H1[3] = {  ( (*SigmaDiffErecEmcEmin175Thetamin115H1) )[0], ( (*SigmaDiffErecEmcEmin175Thetamin120H1) )[0], ( (*SigmaDiffErecEmcEmin175Thetamin125H1) )[0]};

// Double_t MeanDiffErecEmcEmin18H1[3] = {( (*MeanDiffErecEmcEmin18Thetamin115H1) )[0], ( (*MeanDiffErecEmcEmin18Thetamin120H1) )[0], ( (*MeanDiffErecEmcEmin18Thetamin125H1) )[0]};
// Double_t SigmaDiffErecEmcEmin18H1[3] = {  ( (*SigmaDiffErecEmcEmin18Thetamin115H1) )[0], ( (*SigmaDiffErecEmcEmin18Thetamin120H1) )[0], ( (*SigmaDiffErecEmcEmin18Thetamin125H1) )[0]};


// Double_t Angle [3] = {117.5, 122.5, 127.5};


// TGraph *GraphDiffErecEmcEmin17H1 = new TGraph (1, &Angle[0], &MeanDiffErecEmcEmin17H1[0]);
// GraphDiffErecEmcEmin17H1->SetMarkerStyle(20);
// GraphDiffErecEmcEmin17H1->SetMarkerColor(kBlack);


// TGraph *GraphDiffErecEmcEmin175H1 = new TGraph (3, &Angle[0], &MeanDiffErecEmcEmin175H1[0]);
// GraphDiffErecEmcEmin175H1->SetMarkerStyle(21);
// GraphDiffErecEmcEmin175H1->SetMarkerColor(kBlue);

// TGraph *GraphDiffErecEmcEmin18H1 = new TGraph (3, &Angle[0], &MeanDiffErecEmcEmin18H1[0]);
// GraphDiffErecEmcEmin18H1->SetMarkerStyle(22);
// GraphDiffErecEmcEmin18H1->SetMarkerColor(kRed);

// TMultiGraph *mgMeanEnergy = new TMultiGraph();
// mgMeanEnergy->Add(GraphDiffErecEmcEmin17H1);
// mgMeanEnergy->Add(GraphDiffErecEmcEmin175H1);
// mgMeanEnergy->Add(GraphDiffErecEmcEmin18H1);

//mgMeanEnergy->Draw("AP");
HistoTrigEvOverGenEventsEmin17Thetamin115H1->SetFillColorAlpha(kGray+2, .5);
HistoTrigEvOverGenEventsEmin17Thetamin115H1->GetYaxis()->SetRangeUser(-0.1, 2.5);
//HistoTrigEvOverGenEventsEmin17Thetamin115H1->SetStats(FALSE);
HistoTrigEvOverGenEventsEmin17Thetamin115H1->Draw("L");

HistoTrigEvOverGenEventsEmin175Thetamin115H1->SetFillColorAlpha(kAzure+2, .5);
// HistoTrigEvOverGenEventsEmin175Thetamin115H1->Draw("pe3lsame");

HistoTrigEvOverGenEventsEmin18Thetamin115H1->SetFillColorAlpha(kRed-6, .5);
// HistoTrigEvOverGenEventsEmin18Thetamin115H1->Draw("e3same");
HistoTrigEvOverGenEventsEmin18Thetamin115H1->SetMarkerStyle(24);
HistoTrigEvOverGenEventsEmin18Thetamin115H1->SetMarkerSize(.5);
HistoTrigEvOverGenEventsEmin18Thetamin115H1->SetMarkerColor(kRed-4);
HistoTrigEvOverGenEventsEmin18Thetamin115H1->SetLineColor(kRed-4);
HistoTrigEvOverGenEventsEmin18Thetamin115H1->SetLineWidth(2);

// HistoTrigEvOverGenEventsEmin18Thetamin115H1->Draw("pCsame");


	Canvas1->Print("efficiencyGraph.pdf");
	delete Canvas1;
	//Now another plot. You can do this as many times as you want. makesure the canvases are named differently.
	Canvas2->cd();
	Canvas2->SetBottomMargin(0.18);
	Canvas2->SetTopMargin(0.1);
	Canvas2->SetFrameLineWidth(2);
	Canvas2->SetLineWidth(2);
	//gStyle->SetTickLength(0.02,"z");
	Canvas2->SetLeftMargin(0.15);
	Canvas2->SetRightMargin(0.04);

	//115-120  
	TriggeringEfficiencyEmin17Thetamin115H1->SetLineColor(kBlack);
	TriggeringEfficiencyEmin17Thetamin115H1->SetMarkerColor(kBlack);
	TriggeringEfficiencyEmin17Thetamin115H1->SetFillColorAlpha(kGray+2, .5);
	TriggeringEfficiencyEmin17Thetamin115H1->GetXaxis()->SetLimits(4,35);

	TriggeringEfficiencyEmin175Thetamin115H1->SetLineColor(kBlue);
	TriggeringEfficiencyEmin175Thetamin115H1->SetMarkerStyle(21);
	TriggeringEfficiencyEmin175Thetamin115H1->SetMarkerColor(kBlue);
	TriggeringEfficiencyEmin175Thetamin115H1->SetFillColorAlpha(kAzure+2, .5);

	TriggeringEfficiencyEmin175Thetamin115H1->GetXaxis()->SetLimits(4,35);
	TriggeringEfficiencyEmin18Thetamin115H1->SetLineColor(kRed);
	TriggeringEfficiencyEmin18Thetamin115H1->SetMarkerStyle(22);
	TriggeringEfficiencyEmin18Thetamin115H1->SetMarkerColor(kRed);
	TriggeringEfficiencyEmin18Thetamin115H1->SetFillColorAlpha(kRed-6, .5);
	TriggeringEfficiencyEmin18Thetamin115H1->GetXaxis()->SetLimits(4,35);

	vector<double> XTriggeringEfficiencyEmin17Thetamin115H1;
	vector<double> ErrYTriggeringEfficiencyEmin17Thetamin115H1;
	vector<double> YTriggeringEfficiencyEmin17Thetamin115H1;
	vector<double> ErrXTriggeringEfficiencyEmin17Thetamin115H1;

	//cout<<"log test: "<<log10(10)<<endl;

	for(int i=0; i<TriggeringEfficiencyEmin18Thetamin115H1->GetN(); i++ )

	{
	  XTriggeringEfficiencyEmin17Thetamin115H1.push_back(TriggeringEfficiencyEmin17Thetamin115H1->GetX()[i]);
	  YTriggeringEfficiencyEmin17Thetamin115H1.push_back(TriggeringEfficiencyEmin17Thetamin115H1->GetY()[i]);
	  ErrYTriggeringEfficiencyEmin17Thetamin115H1.push_back(TriggeringEfficiencyEmin17Thetamin115H1->GetEY()[i]);
	  if (i>TriggeringEfficiencyEmin17Thetamin115H1->GetN()-1)
	    { //cout<<"i"<<i<<endl;
	      YTriggeringEfficiencyEmin17Thetamin115H1[i]=0;
	      ErrYTriggeringEfficiencyEmin17Thetamin115H1[i]=0;
	    XTriggeringEfficiencyEmin17Thetamin115H1[i]=XTriggeringEfficiencyEmin17Thetamin115H1[TriggeringEfficiencyEmin17Thetamin115H1->GetN()-1]+0.5*(i-(TriggeringEfficiencyEmin17Thetamin115H1->GetN()-1));}
	ErrXTriggeringEfficiencyEmin17Thetamin115H1.push_back(0);

	}

	//tried for one graph to do lg (trigEv/genEv) see how it  looks

	vector<double> XTriggeringEfficiencyEmin175Thetamin115H1;
	vector<double> ErrYTriggeringEfficiencyEmin175Thetamin115H1;
	vector<double> YTriggeringEfficiencyEmin175Thetamin115H1;
	vector<double> ErrXTriggeringEfficiencyEmin175Thetamin115H1;


	for(int i=0; i<TriggeringEfficiencyEmin18Thetamin115H1->GetN(); i++ )

	{
	  XTriggeringEfficiencyEmin175Thetamin115H1.push_back(TriggeringEfficiencyEmin175Thetamin115H1->GetX()[i]);
	  YTriggeringEfficiencyEmin175Thetamin115H1.push_back(TriggeringEfficiencyEmin175Thetamin115H1->GetY()[i]);
	  ErrYTriggeringEfficiencyEmin175Thetamin115H1.push_back(TriggeringEfficiencyEmin175Thetamin115H1->GetEY()[i]);
	  if (i>TriggeringEfficiencyEmin175Thetamin115H1->GetN()-1)
	    { //cout<<"i"<<i<<endl;
	      YTriggeringEfficiencyEmin175Thetamin115H1[i]=0;
	      ErrYTriggeringEfficiencyEmin175Thetamin115H1[i]=0;
	    XTriggeringEfficiencyEmin175Thetamin115H1[i]=XTriggeringEfficiencyEmin175Thetamin115H1[TriggeringEfficiencyEmin175Thetamin115H1->GetN()-1]+0.5*(i-(TriggeringEfficiencyEmin175Thetamin115H1->GetN()-1));}
	ErrXTriggeringEfficiencyEmin175Thetamin115H1.push_back(0);

	}




	vector<double> XTriggeringEfficiencyEmin18Thetamin115H1;
	vector<double> ErrYTriggeringEfficiencyEmin18Thetamin115H1;
	vector<double> YTriggeringEfficiencyEmin18Thetamin115H1;
	vector<double> ErrXTriggeringEfficiencyEmin18Thetamin115H1;


	for(int i=0; i<TriggeringEfficiencyEmin18Thetamin115H1->GetN(); i++ )

	{
	  XTriggeringEfficiencyEmin18Thetamin115H1.push_back(TriggeringEfficiencyEmin18Thetamin115H1->GetX()[i]);
	  YTriggeringEfficiencyEmin18Thetamin115H1.push_back(TriggeringEfficiencyEmin18Thetamin115H1->GetY()[i]);
	  ErrYTriggeringEfficiencyEmin18Thetamin115H1.push_back(TriggeringEfficiencyEmin18Thetamin115H1->GetEY()[i]);
	  if (i>TriggeringEfficiencyEmin18Thetamin115H1->GetN()-1)
	    { //cout<<"i"<<i<<endl;
	      YTriggeringEfficiencyEmin18Thetamin115H1[i]=0;
	      ErrYTriggeringEfficiencyEmin18Thetamin115H1[i]=0;
	    XTriggeringEfficiencyEmin18Thetamin115H1[i]=XTriggeringEfficiencyEmin18Thetamin115H1[TriggeringEfficiencyEmin18Thetamin115H1->GetN()-1]+0.5*(i-(TriggeringEfficiencyEmin18Thetamin115H1->GetN()-1));}
	ErrXTriggeringEfficiencyEmin18Thetamin115H1.push_back(0);

	}




	TGraph *GraphWitH1ValTriggeringEfficiencyEmin17Thetamin115H1 = new TGraphErrors(XTriggeringEfficiencyEmin17Thetamin115H1.size(), &XTriggeringEfficiencyEmin17Thetamin115H1[0], &YTriggeringEfficiencyEmin17Thetamin115H1[0], &ErrXTriggeringEfficiencyEmin17Thetamin115H1[0], &ErrYTriggeringEfficiencyEmin17Thetamin115H1[0]);

	GraphWitH1ValTriggeringEfficiencyEmin17Thetamin115H1->SetFillColorAlpha(kGray+2, .5);
	GraphWitH1ValTriggeringEfficiencyEmin17Thetamin115H1->SetMarkerStyle(20);
	GraphWitH1ValTriggeringEfficiencyEmin17Thetamin115H1->SetMarkerSize(.7);
	GraphWitH1ValTriggeringEfficiencyEmin17Thetamin115H1->SetLineColor(kBlack);
	//GraphWitH1ValTriggeringEfficiencyEmin17Thetamin115H1->Draw("aple3");


	TGraph *GraphWitH1ValTriggeringEfficiencyEmin175Thetamin115H1 = new TGraphErrors(XTriggeringEfficiencyEmin175Thetamin115H1.size(), &XTriggeringEfficiencyEmin175Thetamin115H1[0], &YTriggeringEfficiencyEmin175Thetamin115H1[0], &ErrXTriggeringEfficiencyEmin175Thetamin115H1[0], &ErrYTriggeringEfficiencyEmin175Thetamin115H1[0]);

	GraphWitH1ValTriggeringEfficiencyEmin175Thetamin115H1->SetFillColorAlpha(kAzure+2, .5);
	GraphWitH1ValTriggeringEfficiencyEmin175Thetamin115H1->SetMarkerStyle(21);
	GraphWitH1ValTriggeringEfficiencyEmin175Thetamin115H1->SetMarkerSize(.7);
	GraphWitH1ValTriggeringEfficiencyEmin175Thetamin115H1->SetMarkerColor(kBlue);
	GraphWitH1ValTriggeringEfficiencyEmin175Thetamin115H1->SetLineColor(kBlue);





	TGraph *GraphWitH1ValTriggeringEfficiencyEmin18Thetamin115H1 = new TGraphErrors(XTriggeringEfficiencyEmin18Thetamin115H1.size(), &XTriggeringEfficiencyEmin18Thetamin115H1[0], &YTriggeringEfficiencyEmin18Thetamin115H1[0], &ErrXTriggeringEfficiencyEmin18Thetamin115H1[0], &ErrYTriggeringEfficiencyEmin18Thetamin115H1[0]);

	GraphWitH1ValTriggeringEfficiencyEmin18Thetamin115H1->SetFillColorAlpha(kRed-6, .5);
	GraphWitH1ValTriggeringEfficiencyEmin18Thetamin115H1->SetMarkerStyle(22);
	GraphWitH1ValTriggeringEfficiencyEmin18Thetamin115H1->SetMarkerSize(.7);
	GraphWitH1ValTriggeringEfficiencyEmin18Thetamin115H1->SetMarkerColor(kRed);
	GraphWitH1ValTriggeringEfficiencyEmin18Thetamin115H1->SetLineColor(kRed);

	//GraphWitH1ValTriggeringEfficiencyEmin17Thetamin115H1->Draw("aple3");
	//TriggeringEfficiencyEmin18Thetamin115H1->Draw("APC");


	for(int i=0; i<XTriggeringEfficiencyEmin17Thetamin115H1.size(); i++ )
	cout<<XTriggeringEfficiencyEmin17Thetamin115H1[i]<< "  "<<YTriggeringEfficiencyEmin17Thetamin115H1[i]<<"  "<<ErrYTriggeringEfficiencyEmin17Thetamin115H1[i]<<endl;



	TMultiGraph *mgdiffE = new TMultiGraph();
	mgdiffE->Add(GraphWitH1ValTriggeringEfficiencyEmin17Thetamin115H1);
	mgdiffE->Add(GraphWitH1ValTriggeringEfficiencyEmin175Thetamin115H1);
	mgdiffE->Add(GraphWitH1ValTriggeringEfficiencyEmin18Thetamin115H1);

	//mgdiffE->SetTitle(";Distance_{FD} [km]; Triggered Ev/Generated Ev");
	mgdiffE->Draw("aple3");
	mgdiffE->GetXaxis()->SetLimits(-0.1,40);
	mgdiffE->SetMinimum(-0.1); //for setting y axis limits
	mgdiffE->SetMaximum(1.4);

	mgdiffE->GetXaxis()->SetTitle("R_{FD} [km]");
	mgdiffE->GetYaxis()->SetTitle("Triggered Ev/Generated Ev");
	mgdiffE->GetYaxis()->SetTitleOffset(1.15);
	mgdiffE->GetXaxis()->SetTitleOffset(1.2);
	mgdiffE->GetYaxis()->SetLabelSize(.06);
	mgdiffE->GetYaxis()->SetTitleSize(.065);
	mgdiffE->GetXaxis()->SetLabelSize(.06);
	mgdiffE->GetXaxis()->SetTitleSize(.065);
	mgdiffE->GetXaxis()->SetLabelFont(132);
	mgdiffE->GetYaxis()->SetLabelFont(132);
	mgdiffE->GetXaxis()->SetTitleFont(132);
	mgdiffE->GetYaxis()->SetTitleFont(132);
	mgdiffE->GetXaxis()->CenterTitle();
	mgdiffE->GetYaxis()->CenterTitle();
	//GraphWitH1ValTriggeringEfficiencyEmin18Thetamin115H1->Draw("ap");

	TLegend *legEff = new TLegend(.42,0.65,.96,0.9);

	legEff->SetBorderSize(1);
	legEff->SetTextSize(.07);
	legEff->SetTextFont(132);
	legEff->SetMargin(.2);
	legEff->AddEntry(GraphWitH1ValTriggeringEfficiencyEmin17Thetamin115H1, "lg E / eV #in  [17, 17.5]" ,"lp");
	legEff->AddEntry(GraphWitH1ValTriggeringEfficiencyEmin175Thetamin115H1, "lg E / eV #in  [17.5, 18]" ,"lp");
	legEff->AddEntry(GraphWitH1ValTriggeringEfficiencyEmin18Thetamin115H1, "lg E / eV #in  [18, 18.5]" ,"lp");

	//legES->SetFillStyle(4000);
	legEff->SetFillColor(10);
	legEff->Draw("same");

// TPaveText *pt = new TPaveText(25,0.4,35,0.7);
//  pt->AddText("lgE #in [17 - 17.5 eV] ");
//  pt->SetTextColor(1); ((TText*)pt->GetListOfLines()->Last())->SetTextColor(1);
//  pt->AddText("lgE #in [17.5 - 18 eV] ");
//  pt->SetTextColor(4); ((TText*)pt->GetListOfLines()->Last())->SetTextColor(4);
//  pt->AddText("lgE #in [18 - 18.5 eV]");
//  pt->SetTextColor(2); ((TText*)pt->GetListOfLines()->Last())->SetTextColor(2);
//  pt->Draw();


Canvas2->Print("TriggeringEfficiencyThet115-120_H1.pdf");

//120-125

// Canvas3->cd();


// vector<double> XTriggeringEfficiencyEmin17Thetamin120H1;
// vector<double> ErrYTriggeringEfficiencyEmin17Thetamin120H1;
// vector<double> YTriggeringEfficiencyEmin17Thetamin120H1;
// vector<double> ErrXTriggeringEfficiencyEmin17Thetamin120H1;


// for(int i=0; i<TriggeringEfficiencyEmin18Thetamin120H1->GetN(); i++ )

// {
//   XTriggeringEfficiencyEmin17Thetamin120H1.push_back(TriggeringEfficiencyEmin18Thetamin120H1->GetX()[i]);
//   YTriggeringEfficiencyEmin17Thetamin120H1.push_back(0);
//   ErrYTriggeringEfficiencyEmin17Thetamin120H1.push_back(0);
//   /*if (i>TriggeringEfficiencyEmin17Thetamin120H1->GetN()-1)
//     {// cout<<"i"<<i<<endl;
//       YTriggeringEfficiencyEmin17Thetamin120H1[i]=0;
//       ErrYTriggeringEfficiencyEmin17Thetamin120H1[i]=0;
//     XTriggeringEfficiencyEmin17Thetamin120H1[i]=XTriggeringEfficiencyEmin17Thetamin120H1[TriggeringEfficiencyEmin17Thetamin120H1->GetN()-1]+0.5*(i-(TriggeringEfficiencyEmin17Thetamin120H1->GetN()-1));}*/
// ErrXTriggeringEfficiencyEmin17Thetamin120H1.push_back(0);

// }



// vector<double> XTriggeringEfficiencyEmin175Thetamin120H1;
// vector<double> ErrYTriggeringEfficiencyEmin175Thetamin120H1;
// vector<double> YTriggeringEfficiencyEmin175Thetamin120H1;
// vector<double> ErrXTriggeringEfficiencyEmin175Thetamin120H1;


// for(int i=0; i<TriggeringEfficiencyEmin18Thetamin120H1->GetN(); i++ )

// {
//   XTriggeringEfficiencyEmin175Thetamin120H1.push_back(TriggeringEfficiencyEmin175Thetamin120H1->GetX()[i]);
//   YTriggeringEfficiencyEmin175Thetamin120H1.push_back(TriggeringEfficiencyEmin175Thetamin120H1->GetY()[i]);
//   ErrYTriggeringEfficiencyEmin175Thetamin120H1.push_back(TriggeringEfficiencyEmin175Thetamin120H1->GetEY()[i]);
//   if (i>TriggeringEfficiencyEmin175Thetamin120H1->GetN()-1)
//     { //cout<<"i"<<i<<endl;
//       YTriggeringEfficiencyEmin175Thetamin120H1[i]=0;
//       ErrYTriggeringEfficiencyEmin175Thetamin120H1[i]=0;
//     XTriggeringEfficiencyEmin175Thetamin120H1[i]=XTriggeringEfficiencyEmin175Thetamin120H1[TriggeringEfficiencyEmin175Thetamin120H1->GetN()-1]+0.5*(i-(TriggeringEfficiencyEmin175Thetamin120H1->GetN()-1));}
// ErrXTriggeringEfficiencyEmin175Thetamin120H1.push_back(0);

// }




// vector<double> XTriggeringEfficiencyEmin18Thetamin120H1;
// vector<double> ErrYTriggeringEfficiencyEmin18Thetamin120H1;
// vector<double> YTriggeringEfficiencyEmin18Thetamin120H1;
// vector<double> ErrXTriggeringEfficiencyEmin18Thetamin120H1;


// for(int i=0; i<TriggeringEfficiencyEmin18Thetamin120H1->GetN(); i++ )

// {
//   XTriggeringEfficiencyEmin18Thetamin120H1.push_back(TriggeringEfficiencyEmin18Thetamin120H1->GetX()[i]);
//   YTriggeringEfficiencyEmin18Thetamin120H1.push_back(TriggeringEfficiencyEmin18Thetamin120H1->GetY()[i]);
//   ErrYTriggeringEfficiencyEmin18Thetamin120H1.push_back(TriggeringEfficiencyEmin18Thetamin120H1->GetEY()[i]);
//   if (i>TriggeringEfficiencyEmin18Thetamin120H1->GetN()-1)
//     { //cout<<"i"<<i<<endl;
//       YTriggeringEfficiencyEmin18Thetamin120H1[i]=0;
//       ErrYTriggeringEfficiencyEmin18Thetamin120H1[i]=0;
//     XTriggeringEfficiencyEmin18Thetamin120H1[i]=XTriggeringEfficiencyEmin18Thetamin120H1[TriggeringEfficiencyEmin18Thetamin120H1->GetN()-1]+0.5*(i-(TriggeringEfficiencyEmin18Thetamin120H1->GetN()-1));}
// ErrXTriggeringEfficiencyEmin18Thetamin120H1.push_back(0);

// }




// TGraph *GraphWitH1ValTriggeringEfficiencyEmin17Thetamin120H1 = new TGraphErrors(XTriggeringEfficiencyEmin17Thetamin120H1.size(), &XTriggeringEfficiencyEmin17Thetamin120H1[0], &YTriggeringEfficiencyEmin17Thetamin120H1[0], &ErrXTriggeringEfficiencyEmin17Thetamin120H1[0], &ErrYTriggeringEfficiencyEmin17Thetamin120H1[0]);

// GraphWitH1ValTriggeringEfficiencyEmin17Thetamin120H1->SetFillColorAlpha(kGray+2, .5);
// GraphWitH1ValTriggeringEfficiencyEmin17Thetamin120H1->SetMarkerStyle(20);
// GraphWitH1ValTriggeringEfficiencyEmin17Thetamin120H1->SetMarkerSize(.5);
// GraphWitH1ValTriggeringEfficiencyEmin17Thetamin120H1->SetLineColor(kBlack);




// TGraph *GraphWitH1ValTriggeringEfficiencyEmin175Thetamin120H1 = new TGraphErrors(XTriggeringEfficiencyEmin175Thetamin120H1.size(), &XTriggeringEfficiencyEmin175Thetamin120H1[0], &YTriggeringEfficiencyEmin175Thetamin120H1[0], &ErrXTriggeringEfficiencyEmin175Thetamin120H1[0], &ErrYTriggeringEfficiencyEmin175Thetamin120H1[0]);

// GraphWitH1ValTriggeringEfficiencyEmin175Thetamin120H1->SetFillColorAlpha(kAzure+2, .5);
// GraphWitH1ValTriggeringEfficiencyEmin175Thetamin120H1->SetMarkerStyle(21);
// GraphWitH1ValTriggeringEfficiencyEmin175Thetamin120H1->SetMarkerSize(.5);
// GraphWitH1ValTriggeringEfficiencyEmin175Thetamin120H1->SetMarkerColor(kBlue);
// GraphWitH1ValTriggeringEfficiencyEmin175Thetamin120H1->SetLineColor(kBlue);





// TGraph *GraphWitH1ValTriggeringEfficiencyEmin18Thetamin120H1 = new TGraphErrors(XTriggeringEfficiencyEmin18Thetamin120H1.size(), &XTriggeringEfficiencyEmin18Thetamin120H1[0], &YTriggeringEfficiencyEmin18Thetamin120H1[0], &ErrXTriggeringEfficiencyEmin18Thetamin120H1[0], &ErrYTriggeringEfficiencyEmin18Thetamin120H1[0]);

// GraphWitH1ValTriggeringEfficiencyEmin18Thetamin120H1->SetFillColorAlpha(kRed-6, .5);
// GraphWitH1ValTriggeringEfficiencyEmin18Thetamin120H1->SetMarkerStyle(22);
// GraphWitH1ValTriggeringEfficiencyEmin18Thetamin120H1->SetMarkerSize(.5);
// GraphWitH1ValTriggeringEfficiencyEmin18Thetamin120H1->SetMarkerColor(kRed);
// GraphWitH1ValTriggeringEfficiencyEmin18Thetamin120H1->SetLineColor(kRed);








// /*TriggeringEfficiencyEmin17Thetamin120H1->SetLineColor(kBlack);
// TriggeringEfficiencyEmin17Thetamin120H1->SetMarkerColor(kBlack);
// TriggeringEfficiencyEmin17Thetamin120H1->GetXaxis()->SetLimits(4,35);
// TriggeringEfficiencyEmin175Thetamin120H1->SetLineColor(kBlue);
// TriggeringEfficiencyEmin175Thetamin120H1->SetMarkerStyle(21);
// TriggeringEfficiencyEmin175Thetamin120H1->SetMarkerColor(kBlue);
// TriggeringEfficiencyEmin175Thetamin120H1->GetXaxis()->SetLimits(4,35);
// TriggeringEfficiencyEmin18Thetamin120H1->SetLineColor(kRed);
// TriggeringEfficiencyEmin18Thetamin120H1->SetMarkerStyle(22);
// TriggeringEfficiencyEmin18Thetamin120H1->SetMarkerColor(kRed);
// TriggeringEfficiencyEmin18Thetamin120H1->GetXaxis()->SetLimits(4,35); */


// TMultiGraph *mgdiffEThetamin120H1 = new TMultiGraph();
// mgdiffEThetamin120H1->Add(GraphWitH1ValTriggeringEfficiencyEmin17Thetamin120H1);
// mgdiffEThetamin120H1->Add(GraphWitH1ValTriggeringEfficiencyEmin175Thetamin120H1);
// mgdiffEThetamin120H1->Add(GraphWitH1ValTriggeringEfficiencyEmin18Thetamin120H1);

// mgdiffEThetamin120H1->SetTitle("Triggering Efficiency  ;Distance_{FD} [km]; Triggered Ev/Generated Ev");
// mgdiffEThetamin120H1->Draw("aple3");
// mgdiffEThetamin120H1->SetMinimum(-0.1); //for setting y axis limits
// mgdiffEThetamin120H1->SetMaximum(1.4);
// mgdiffEThetamin120H1->GetXaxis()->SetLimits(-0.1,37);


// TPaveText *pt2 = new TPaveText(25,0.4,35,0.7);
//  pt2->AddText("lgE #in [17 - 17.5 eV] ");
//  pt2->SetTextColor(1); ((TText*)pt2->GetListOfLines()->Last())->SetTextColor(1);
//  pt2->AddText("lgE #in [17.5 - 18 eV] ");
//  pt2->SetTextColor(4); ((TText*)pt2->GetListOfLines()->Last())->SetTextColor(4);
//  pt2->AddText("lgE #in [18 - 18.5 eV]");
//  pt2->SetTextColor(2); ((TText*)pt2->GetListOfLines()->Last())->SetTextColor(2);
//  pt2->Draw();

//  Canvas3->Print("TriggeringEfficiencyThet120-125_H1.pdf");

// Canvas4->cd();


// vector<double> XTriggeringEfficiencyEmin17Thetamin125H1;
// vector<double> ErrYTriggeringEfficiencyEmin17Thetamin125H1;
// vector<double> YTriggeringEfficiencyEmin17Thetamin125H1;
// vector<double> ErrXTriggeringEfficiencyEmin17Thetamin125H1;


// for(int i=0; i<TriggeringEfficiencyEmin18Thetamin125H1->GetN(); i++ )

// {
//   XTriggeringEfficiencyEmin17Thetamin125H1.push_back(TriggeringEfficiencyEmin18Thetamin125H1->GetX()[i]);
//   YTriggeringEfficiencyEmin17Thetamin125H1.push_back(0);
//   ErrYTriggeringEfficiencyEmin17Thetamin125H1.push_back(0);
//  /* if (i>TriggeringEfficiencyEmin17Thetamin125H1->GetN()-1)
//     { //cout<<"i"<<i<<endl;
//       YTriggeringEfficiencyEmin17Thetamin125H1[i]=0;
//       ErrYTriggeringEfficiencyEmin17Thetamin125H1[i]=0;
//     XTriggeringEfficiencyEmin17Thetamin125H1[i]=XTriggeringEfficiencyEmin17Thetamin125H1[TriggeringEfficiencyEmin17Thetamin125H1->GetN()-1]+0.5*(i-(TriggeringEfficiencyEmin17Thetamin125H1->GetN()-1));}*/
// ErrXTriggeringEfficiencyEmin17Thetamin125H1.push_back(0);

// }



// vector<double> XTriggeringEfficiencyEmin175Thetamin125H1;
// vector<double> ErrYTriggeringEfficiencyEmin175Thetamin125H1;
// vector<double> YTriggeringEfficiencyEmin175Thetamin125H1;
// vector<double> ErrXTriggeringEfficiencyEmin175Thetamin125H1;


// for(int i=0; i<TriggeringEfficiencyEmin18Thetamin125H1->GetN(); i++ )

// {
//   XTriggeringEfficiencyEmin175Thetamin125H1.push_back(TriggeringEfficiencyEmin175Thetamin125H1->GetX()[i]);
//   YTriggeringEfficiencyEmin175Thetamin125H1.push_back(TriggeringEfficiencyEmin175Thetamin125H1->GetY()[i]);
//   ErrYTriggeringEfficiencyEmin175Thetamin125H1.push_back(TriggeringEfficiencyEmin175Thetamin125H1->GetEY()[i]);
//   if (i>TriggeringEfficiencyEmin175Thetamin125H1->GetN()-1)
//     { //cout<<"i"<<i<<endl;
//       YTriggeringEfficiencyEmin175Thetamin125H1[i]=0;
//       ErrYTriggeringEfficiencyEmin175Thetamin125H1[i]=0;
//     XTriggeringEfficiencyEmin175Thetamin125H1[i]=XTriggeringEfficiencyEmin175Thetamin125H1[TriggeringEfficiencyEmin175Thetamin125H1->GetN()-1]+0.5*(i-(TriggeringEfficiencyEmin175Thetamin125H1->GetN()-1));}
// ErrXTriggeringEfficiencyEmin175Thetamin125H1.push_back(0);

// }




// vector<double> XTriggeringEfficiencyEmin18Thetamin125H1;
// vector<double> ErrYTriggeringEfficiencyEmin18Thetamin125H1;
// vector<double> YTriggeringEfficiencyEmin18Thetamin125H1;
// vector<double> ErrXTriggeringEfficiencyEmin18Thetamin125H1;


// for(int i=0; i<TriggeringEfficiencyEmin18Thetamin125H1->GetN(); i++ )

// {
//   XTriggeringEfficiencyEmin18Thetamin125H1.push_back(TriggeringEfficiencyEmin18Thetamin125H1->GetX()[i]);
//   YTriggeringEfficiencyEmin18Thetamin125H1.push_back(TriggeringEfficiencyEmin18Thetamin125H1->GetY()[i]);
//   ErrYTriggeringEfficiencyEmin18Thetamin125H1.push_back(TriggeringEfficiencyEmin18Thetamin125H1->GetEY()[i]);
//   if (i>TriggeringEfficiencyEmin18Thetamin125H1->GetN()-1)
//     { //cout<<"i"<<i<<endl;
//       YTriggeringEfficiencyEmin18Thetamin125H1[i]=0;
//       ErrYTriggeringEfficiencyEmin18Thetamin125H1[i]=0;
//     XTriggeringEfficiencyEmin18Thetamin125H1[i]=XTriggeringEfficiencyEmin18Thetamin125H1[TriggeringEfficiencyEmin18Thetamin125H1->GetN()-1]+0.5*(i-(TriggeringEfficiencyEmin18Thetamin125H1->GetN()-1));}
// ErrXTriggeringEfficiencyEmin18Thetamin125H1.push_back(0);

// }




// TGraph *GraphWitH1ValTriggeringEfficiencyEmin17Thetamin125H1 = new TGraphErrors(XTriggeringEfficiencyEmin17Thetamin125H1.size(), &XTriggeringEfficiencyEmin17Thetamin125H1[0], &YTriggeringEfficiencyEmin17Thetamin125H1[0], &ErrXTriggeringEfficiencyEmin17Thetamin125H1[0], &ErrYTriggeringEfficiencyEmin17Thetamin125H1[0]);

// GraphWitH1ValTriggeringEfficiencyEmin17Thetamin125H1->SetFillColorAlpha(kGray+2, .5);
// GraphWitH1ValTriggeringEfficiencyEmin17Thetamin125H1->SetMarkerStyle(20);
// GraphWitH1ValTriggeringEfficiencyEmin17Thetamin125H1->SetMarkerSize(.5);
// GraphWitH1ValTriggeringEfficiencyEmin17Thetamin125H1->SetLineColor(kBlack);



// TGraph *GraphWitH1ValTriggeringEfficiencyEmin175Thetamin125H1 = new TGraphErrors(XTriggeringEfficiencyEmin175Thetamin125H1.size(), &XTriggeringEfficiencyEmin175Thetamin125H1[0], &YTriggeringEfficiencyEmin175Thetamin125H1[0], &ErrXTriggeringEfficiencyEmin175Thetamin125H1[0], &ErrYTriggeringEfficiencyEmin175Thetamin125H1[0]);

// GraphWitH1ValTriggeringEfficiencyEmin175Thetamin125H1->SetFillColorAlpha(kAzure+2, .5);
// GraphWitH1ValTriggeringEfficiencyEmin175Thetamin125H1->SetMarkerStyle(21);
// GraphWitH1ValTriggeringEfficiencyEmin175Thetamin125H1->SetMarkerSize(.5);
// GraphWitH1ValTriggeringEfficiencyEmin175Thetamin125H1->SetMarkerColor(kBlue);
// GraphWitH1ValTriggeringEfficiencyEmin175Thetamin125H1->SetLineColor(kBlue);





// TGraph *GraphWitH1ValTriggeringEfficiencyEmin18Thetamin125H1 = new TGraphErrors(XTriggeringEfficiencyEmin18Thetamin125H1.size(), &XTriggeringEfficiencyEmin18Thetamin125H1[0], &YTriggeringEfficiencyEmin18Thetamin125H1[0], &ErrXTriggeringEfficiencyEmin18Thetamin125H1[0], &ErrYTriggeringEfficiencyEmin18Thetamin125H1[0]);

// GraphWitH1ValTriggeringEfficiencyEmin18Thetamin125H1->SetFillColorAlpha(kRed-6, .5);
// GraphWitH1ValTriggeringEfficiencyEmin18Thetamin125H1->SetMarkerStyle(22);
// GraphWitH1ValTriggeringEfficiencyEmin18Thetamin125H1->SetMarkerColor(kRed);
// GraphWitH1ValTriggeringEfficiencyEmin18Thetamin125H1->SetMarkerSize(.5);
// GraphWitH1ValTriggeringEfficiencyEmin18Thetamin125H1->SetLineColor(kRed);





// TMultiGraph *mgdiffEThetamin125H1 = new TMultiGraph();
// mgdiffEThetamin125H1->Add(GraphWitH1ValTriggeringEfficiencyEmin17Thetamin125H1);
// mgdiffEThetamin125H1->Add(GraphWitH1ValTriggeringEfficiencyEmin175Thetamin125H1);
// mgdiffEThetamin125H1->Add(GraphWitH1ValTriggeringEfficiencyEmin18Thetamin125H1);

// mgdiffEThetamin125H1->SetTitle("Triggering Efficiency  ;Distance_{FD} [km]; Triggered Ev/Generated Ev");
// mgdiffEThetamin125H1->Draw("aple3");
// mgdiffEThetamin125H1->SetMinimum(-0.1); //for setting y axis limits
// mgdiffEThetamin125H1->SetMaximum(1.4);
// mgdiffEThetamin125H1->GetXaxis()->SetLimits(-0.1, 37);


// TPaveText *pt3 = new TPaveText(25,0.4,35,0.7);
//  pt3->AddText("lgE #in [17 - 17.5 eV] ");
//  pt3->SetTextColor(1); ((TText*)pt3->GetListOfLines()->Last())->SetTextColor(1);
//  pt3->AddText("lgE #in [17.5 - 18 eV] ");
//  pt3->SetTextColor(4); ((TText*)pt3->GetListOfLines()->Last())->SetTextColor(4);
//  pt3->AddText("lgE #in [18 - 18.5 eV]");
//  pt3->SetTextColor(2); ((TText*)pt3->GetListOfLines()->Last())->SetTextColor(2);
//  pt3->Draw();

// Canvas4->Print("TriggeringEfficiencyThet125-130_H1.pdf");


 CanvasEnergydiff->cd();

 double MeanEnergyDifferenceThetamin115[3] = {HistoEnergyDifferenceEmin17Thetamin115H1->GetMean(), HistoEnergyDifferenceEmin175Thetamin115H1->GetMean(), 
                                        HistoEnergyDifferenceEmin18Thetamin115H1->GetMean()};

   double ErrorMeanEnergyDifferenceThetamin115 [3] = {HistoEnergyDifferenceEmin17Thetamin115H1->GetMeanError(), HistoEnergyDifferenceEmin175Thetamin115H1->GetMeanError(), 
                                        HistoEnergyDifferenceEmin18Thetamin115H1->GetMeanError()};   

  double SigmaEnergyDifferenceThetamin115 [3] = {HistoEnergyDifferenceEmin17Thetamin115H1->GetStdDev(), HistoEnergyDifferenceEmin175Thetamin115H1->GetStdDev(),
                                        HistoEnergyDifferenceEmin18Thetamin115H1->GetStdDev()};

  double ErrorSigmaEnergyDifferenceThetamin115 [3] = {HistoEnergyDifferenceEmin17Thetamin115H1->GetStdDevError(), HistoEnergyDifferenceEmin175Thetamin115H1->GetStdDevError(),
                                        HistoEnergyDifferenceEmin18Thetamin115H1->GetStdDevError()};

 double EnergyThetamin115[3] = {HistoEnergylgEmcEmin17Thetamin115H1->GetMean(), HistoEnergylgEmcEmin175Thetamin115H1->GetMean(), HistoEnergylgEmcEmin18Thetamin115H1->GetMean()};
  double EnergyErrorThetamin115[3] = {HistoEnergylgEmcEmin17Thetamin115H1->GetMeanError(), HistoEnergylgEmcEmin175Thetamin115H1->GetMeanError(), HistoEnergylgEmcEmin18Thetamin115H1->GetMeanError()};

TGraph *GraphMeanEnergyDifferenceThetamin115 = new TGraphErrors(3, &EnergyThetamin115[0], &MeanEnergyDifferenceThetamin115[0], 
                                              &EnergyErrorThetamin115[0], &ErrorMeanEnergyDifferenceThetamin115[0]);
GraphMeanEnergyDifferenceThetamin115->SetFillColorAlpha(kGray+2, .5);
GraphMeanEnergyDifferenceThetamin115->SetMarkerStyle(20);
GraphMeanEnergyDifferenceThetamin115->SetMarkerSize(.5);
//GraphMeanEnergyDifferenceEmin17->Draw("aple3");


//  double MeanEnergyDifferenceThetamin120[2] = {HistoEnergyDifferenceEmin175Thetamin120H1->GetMean(), 
//                                         HistoEnergyDifferenceEmin18Thetamin120H1->GetMean()};

//  cout<<"en diff: "<<HistoEnergyDifferenceEmin175Thetamin120H1->GetMean()<< "   "<<HistoEnergyDifferenceEmin18Thetamin120H1->GetMean()<<endl;
//    double ErrorMeanEnergyDifferenceThetamin120 [2] = { HistoEnergyDifferenceEmin175Thetamin120H1->GetMeanError(), 
//                                         HistoEnergyDifferenceEmin18Thetamin120H1->GetMeanError()};   

//   double SigmaEnergyDifferenceThetamin120 [2] = { HistoEnergyDifferenceEmin175Thetamin120H1->GetStdDev(),
//                                         HistoEnergyDifferenceEmin18Thetamin120H1->GetStdDev()};

//   double ErrorSigmaEnergyDifferenceThetamin120 [2] = { HistoEnergyDifferenceEmin175Thetamin120H1->GetStdDevError(),
//                                         HistoEnergyDifferenceEmin18Thetamin120H1->GetStdDevError()};

//  double EnergyThetamin120[2] = { HistoEnergylgEmcEmin175Thetamin120H1->GetMean(), HistoEnergylgEmcEmin18Thetamin120H1->GetMean()};
//   double EnergyErrorThetamin120[2] = {HistoEnergylgEmcEmin175Thetamin120H1->GetMeanError(), HistoEnergylgEmcEmin18Thetamin120H1->GetMeanError()};

// TGraph *GraphMeanEnergyDifferenceThetamin120 = new TGraphErrors(2, &EnergyThetamin120[0], &MeanEnergyDifferenceThetamin120[0], 
//                                                 &EnergyErrorThetamin120[0], &ErrorMeanEnergyDifferenceThetamin120[0]);
// GraphMeanEnergyDifferenceThetamin120->SetFillColorAlpha(kAzure+2, .5);
// GraphMeanEnergyDifferenceThetamin120->SetMarkerStyle(21);
// GraphMeanEnergyDifferenceThetamin120->SetMarkerSize(.5);
// GraphMeanEnergyDifferenceThetamin120->SetLineColor(4);
// GraphMeanEnergyDifferenceThetamin120->SetMarkerColor(kBlue);
// //GraphMeanEnergyDifferenceThetamin120->Draw("aple3");


//  double MeanEnergyDifferenceThetamin125[2] = {HistoEnergyDifferenceEmin175Thetamin125H1->GetMean(), 
//                                         HistoEnergyDifferenceEmin18Thetamin125H1->GetMean()};

//    double ErrorMeanEnergyDifferenceThetamin125 [2] = { HistoEnergyDifferenceEmin175Thetamin125H1->GetMeanError(), 
//                                         HistoEnergyDifferenceEmin18Thetamin125H1->GetMeanError()};   

//   double SigmaEnergyDifferenceThetamin125 [2] = {HistoEnergyDifferenceEmin175Thetamin125H1->GetStdDev(),
//                                         HistoEnergyDifferenceEmin18Thetamin125H1->GetStdDev()};

//   double ErrorSigmaEnergyDifferenceThetamin125 [2] = {HistoEnergyDifferenceEmin175Thetamin125H1->GetStdDevError(),
//                                         HistoEnergyDifferenceEmin18Thetamin125H1->GetStdDevError()};

//   double EnergyThetamin125[2] = {HistoEnergylgEmcEmin175Thetamin125H1->GetMean(), HistoEnergylgEmcEmin18Thetamin125H1->GetMean()};
//   double EnergyErrorThetamin125[2] = { HistoEnergylgEmcEmin175Thetamin125H1->GetMeanError(), HistoEnergylgEmcEmin18Thetamin125H1->GetMeanError()};

// TGraph *GraphMeanEnergyDifferenceThetamin125 = new TGraphErrors(2, &EnergyThetamin125[0], &MeanEnergyDifferenceThetamin125[0], &EnergyErrorThetamin125[0], &ErrorMeanEnergyDifferenceThetamin125[0]);
// GraphMeanEnergyDifferenceThetamin125->SetFillColorAlpha(kRed-6, .5);
// GraphMeanEnergyDifferenceThetamin125->SetMarkerStyle(22);
// GraphMeanEnergyDifferenceThetamin125->SetMarkerSize(.5);
// GraphMeanEnergyDifferenceThetamin125->SetLineColor(2);
// GraphMeanEnergyDifferenceThetamin125->SetMarkerColor(kRed);


//cout<<"HistoEnergylgEmcEmin17Thetamin125H1->GetMean()"<<HistoEnergylgEmcEmin17Thetamin125H1->GetMean()<<" HistoEnergylgEmcEmin17Thetamin125H1->GetMeanError() "
//<<HistoEnergylgEmcEmin17Thetamin125H1->GetMeanError()<<endl;

//cout<<"HistoEnergylgEmcEmin17Thetamin120H1->GetMean()"<<HistoEnergylgEmcEmin17Thetamin120H1->GetMean()<<" HistoEnergylgEmcEmin17Thetamin120H1->GetMeanError() "
//<<HistoEnergylgEmcEmin17Thetamin120H1->GetMeanError()<<endl;

TMultiGraph *mgEnergyDifference = new TMultiGraph();
mgEnergyDifference->Add(GraphMeanEnergyDifferenceThetamin115);
// mgEnergyDifference->Add(GraphMeanEnergyDifferenceThetamin120);
// mgEnergyDifference->Add(GraphMeanEnergyDifferenceThetamin125);

mgEnergyDifference->SetTitle("Energy reconstruction; lg E_{MC} / eV; #scale[2]{#LT} lg #(){#frac{E_{rec} - E_{MC}}{E_{MC}}} #scale[2]{#GT} ");

mgEnergyDifference->Draw("aple3");
mgEnergyDifference->GetXaxis()->SetTitleOffset(1.3);
mgEnergyDifference->GetYaxis()->SetTitleOffset(1.3);


 leg = new TLegend(.65,0.15,.90,0.30); //size of legend
leg->AddEntry(GraphMeanEnergyDifferenceThetamin115,"#font[132]{#theta #in [115#circ, 120#circ]}","lf"); //top left
  // leg->AddEntry(GraphMeanEnergyDifferenceThetamin120,"#font[132]{#theta #in [120#circ, 125#circ]}","lf"); //top right
  // leg->AddEntry(GraphMeanEnergyDifferenceThetamin125,"#font[132]{#theta #in [125#circ, 130#circ]}","lf");
leg->Draw();

// CanvasEnergydiff->Print("MeanEnergyDifferenceH1.pdf");

CanvasSigmaEnergydiff->cd();

TGraph *GraphSigmaEnergyDifferenceThetamin115 = new TGraphErrors(3, &EnergyThetamin115[0], &SigmaEnergyDifferenceThetamin115[0], 
                                              &EnergyErrorThetamin115[0], &ErrorSigmaEnergyDifferenceThetamin115[0]);
GraphSigmaEnergyDifferenceThetamin115->SetFillColorAlpha(kGray+2, .5);
GraphSigmaEnergyDifferenceThetamin115->SetMarkerStyle(20);
GraphSigmaEnergyDifferenceThetamin115->SetMarkerSize(.5);

// TGraph *GraphSigmaEnergyDifferenceThetamin120 = new TGraphErrors(2, &EnergyThetamin120[0], &SigmaEnergyDifferenceThetamin120[0], 
//                                                 &EnergyErrorThetamin120[0], &ErrorSigmaEnergyDifferenceThetamin120[0]);
// GraphSigmaEnergyDifferenceThetamin120->SetFillColorAlpha(kAzure+2, .5);
// GraphSigmaEnergyDifferenceThetamin120->SetMarkerStyle(21);
// GraphSigmaEnergyDifferenceThetamin120->SetLineColor(4);
// GraphSigmaEnergyDifferenceThetamin120->SetMarkerColor(kBlue);
// GraphSigmaEnergyDifferenceThetamin120->SetMarkerSize(.5);

// TGraph *GraphSigmaEnergyDifferenceThetamin125 = new TGraphErrors(2, &EnergyThetamin125[0], &SigmaEnergyDifferenceThetamin125[0], &EnergyErrorThetamin125[0], &ErrorSigmaEnergyDifferenceThetamin125[0]);
// GraphSigmaEnergyDifferenceThetamin125->SetFillColorAlpha(kRed-6, .5);
// GraphSigmaEnergyDifferenceThetamin125->SetMarkerStyle(22);
// GraphSigmaEnergyDifferenceThetamin125->SetLineColor(2);
// GraphSigmaEnergyDifferenceThetamin125->SetMarkerColor(kRed);
// GraphSigmaEnergyDifferenceThetamin125->SetMarkerSize(.5);

TMultiGraph *mgSigmaEnergyDifference = new TMultiGraph();
mgSigmaEnergyDifference->Add(GraphSigmaEnergyDifferenceThetamin115);
// mgSigmaEnergyDifference->Add(GraphSigmaEnergyDifferenceThetamin120);
// mgSigmaEnergyDifference->Add(GraphSigmaEnergyDifferenceThetamin125);

mgSigmaEnergyDifference->SetTitle("Energy reconstruction; lg E_{MC} / eV; #sigma #[]{lg #(){#frac{E_{rec} - E_{MC}}{E_{MC}} }} ");

mgSigmaEnergyDifference->Draw("aple3");
mgSigmaEnergyDifference->GetXaxis()->SetTitleOffset(1.3);
mgSigmaEnergyDifference->GetYaxis()->SetTitleOffset(1.3);


 leg2 = new TLegend(.65,0.15,.90,0.30); //size of leg2end
leg2->AddEntry(GraphSigmaEnergyDifferenceThetamin115,"#font[132]{#theta #in [115#circ, 120#circ]}","lf"); //top left
  // leg2->AddEntry(GraphSigmaEnergyDifferenceThetamin120,"#font[132]{#theta #in [120#circ, 125#circ]}","lf"); //top right
  // leg2->AddEntry(GraphSigmaEnergyDifferenceThetamin125,"#font[132]{#theta #in [125#circ, 130#circ]}","lf");
leg2->Draw();
// CanvasSigmaEnergydiff->Print("SigmaEnergyDifferenceH1.pdf");



  gStyle->SetStatX(.97);
  gStyle->SetStatW(0.45);
  gStyle->SetStatH(0.25);


  //Counts->Print("Counts.pdf");

}
