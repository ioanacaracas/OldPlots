/*
 * Plot.C
 *
 *  Created on: Dec 6, 2016
 *      Author: mayotte
 */
void PlotFDdistanceEye4(){ //run via root Plot.C

  //Start Plotting

  gStyle->SetOptStat(1);

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
  //gStyle->SetOptStat(0);
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

//TFile *AnalysisFile1 = new TFile("./Analysis_ElectronE17_17.5_theta115-120_H0.root ","READ");
//TFile *AnalysisFile2 = new TFile("./Analysis_ElectronE17.5_18_theta115-120_H0.root ","READ");
//TFile *AnalysisFile3 = new TFile("./Analysis_ElectronE18_18.5_theta115-120_H0.root ","READ");


TFile *AnalysisFile1 = new TFile("./Analysis_ProtonE17_17.5_theta115-120_H0.root ","READ");
TFile *AnalysisFile2 = new TFile("./Analysis_ProtonE17.5_18_theta115-120_H0.root ","READ");
TFile *AnalysisFile3 = new TFile("./Analysis_ProtonE18_18.5_theta115-120_H0.root ","READ");



 
AnalysisFile1->cd(); //change to file 1
  TH1F* Mean1        = ((TH1F*) AnalysisFile1->Get("DistHistoEye4"));
AnalysisFile2->cd(); //change to file 1
  TH1F* Mean2        = ((TH1F*) AnalysisFile2->Get("DistHistoEye4"));
AnalysisFile3->cd(); //change to file 1
  TH1F* Mean3        = ((TH1F*) AnalysisFile3->Get("DistHistoEye4"));


   



  //TLine* ZeroLine = new TLine(17.7,0,19.7,0); // A line to put on your plots if you want one
  //ZeroLine->SetLineStyle(2);
   gStyle->SetOptStat(0);
  TH1F* Axis1 = new TH1F("Axis1","",10,0,50);

  TCanvas *Canvas1 = new TCanvas("Canvas1","Canvas name",700,530);  //sizes here so change the last 2 to make your plot whatever size you want
  //Canvas1->SetGrid();
  Canvas1->SetBottomMargin(0.18);
  Canvas1->SetTopMargin(0.07);
  Canvas1->SetFrameLineWidth(2);
  Canvas1->SetLineWidth(2);
  //gStyle->SetTickLength(0.02,"z");
  Canvas1->SetLeftMargin(0.15);
  Canvas1->SetRightMargin(0.04);
  Axis1->GetYaxis()->SetRangeUser(0,10); //sets the Y axis range
  Axis1->GetXaxis()->SetRangeUser(0,40); //sets the X axis range
  Axis1->GetYaxis()->SetTitle("Triggered Events");
  Axis1->GetXaxis()->SetTitle("R_{FD} [km]");
  Axis1->GetYaxis()->SetTitleOffset(1.1);
  Axis1->GetXaxis()->SetTitleOffset(1.2);
  Axis1->GetYaxis()->SetLabelSize(.06);
  Axis1->GetYaxis()->SetTitleSize(.065);
  Axis1->GetXaxis()->SetLabelSize(.06);
  Axis1->GetXaxis()->SetTitleSize(.065);
  Axis1->GetXaxis()->SetLabelFont(132);
  Axis1->GetYaxis()->SetLabelFont(132);
  Axis1->GetXaxis()->SetTitleFont(132);
  Axis1->GetYaxis()->SetTitleFont(132);
  Axis1->GetXaxis()->CenterTitle();
  Axis1->GetYaxis()->CenterTitle();
  // MeanAll->SetMarkerStyle(8); //changes style of plot points. dont need for a histogram
  // MeanAll->SetMarkerSize(1);
  //Mean1->SetLineWidth(2); //slightly thicker lines
  Axis1->Draw(""); //draws histogram


//Mean3->SetLineWidth(2);



Mean1->Draw("sames");




  //This makes a legend with 4 spots
  /*leg = new TLegend(.75,0.75,.95,0.95); //size of legend
  leg->SetNColumns(2); //2 columns
  //leg->AddEntry(Mean1,"another slot","lf"); //top left
  leg->AddEntry(Mean1,"#font[132]{h_{int} = 1.4 km}","lf"); //top right
  leg->AddEntry(Mean2,"#font[132]{h_{int} = 2 km}","lf"); //bottm left
  leg->AddEntry(Mean3,"#font[132]{h_{int} = 3 km}","lf"); //bottom right
  leg->AddEntry(Mean4,"#font[132]{h_{int} = 5 km}","lf");
  leg->Draw(); //draws the legend on the plot*/

  Canvas1->Print("RFDProtonE17_17.5Theta115_120.pdf"); //This saves the plot 

  TH1F* Axis2 = new TH1F("Axis2","",10,0,50);

  TCanvas *Canvas2 = new TCanvas("Canvas2","Canvas name",700,530);  //sizes here so change the last 2 to make your plot whatever size you want
  //Canvas1->SetGrid();
  Canvas2->SetBottomMargin(0.18);
  Canvas2->SetTopMargin(0.07);
  Canvas2->SetFrameLineWidth(2);
  Canvas2->SetLineWidth(2);
  //gStyle->SetTickLength(0.02,"z");
  Canvas2->SetLeftMargin(0.15);
  Canvas2->SetRightMargin(0.04);
  Axis2->GetYaxis()->SetRangeUser(0,10); //sets the Y axis range
  Axis2->GetXaxis()->SetRangeUser(0,40); //sets the X axis range
  Axis2->GetYaxis()->SetTitle("Triggered Events");
  Axis2->GetXaxis()->SetTitle("R_{FD} [km]");
  Axis2->GetYaxis()->SetTitleOffset(1.1);
  Axis2->GetXaxis()->SetTitleOffset(1.2);
  Axis2->GetYaxis()->SetLabelSize(.06);
  Axis2->GetYaxis()->SetTitleSize(.065);
  Axis2->GetXaxis()->SetLabelSize(.06);
  Axis2->GetXaxis()->SetTitleSize(.065);
  Axis2->GetXaxis()->SetLabelFont(132);
  Axis2->GetYaxis()->SetLabelFont(132);
  Axis2->GetXaxis()->SetTitleFont(132);
  Axis2->GetYaxis()->SetTitleFont(132);
  Axis2->GetXaxis()->CenterTitle();
  Axis2->GetYaxis()->CenterTitle();
  // MeanAll->SetMarkerStyle(8); //changes style of plot points. dont need for a histogram
  // MeanAll->SetMarkerSize(1);
  //Mean1->SetLineWidth(2); //slightly thicker lines
  Axis2->Draw(""); //draws histogram

  Mean2->Draw("sames");

  Canvas2->Print("RFDProtonE17.5_18Theta115_120.pdf"); //This saves the plot 

  TH1F* Axis3 = new TH1F("Axis3","",10,0,50);

  TCanvas *Canvas3 = new TCanvas("Canvas3","Canvas name",700,530);  //sizes here so change the last 2 to make your plot whatever size you want
  //Canvas1->SetGrid();
  Canvas3->SetBottomMargin(0.18);
  Canvas3->SetTopMargin(0.07);
  Canvas3->SetFrameLineWidth(2);
  Canvas3->SetLineWidth(2);
  //gStyle->SetTickLength(0.02,"z");
  Canvas3->SetLeftMargin(0.15);
  Canvas3->SetRightMargin(0.04);
  Axis3->GetYaxis()->SetRangeUser(0,10); //sets the Y axis range
  Axis3->GetXaxis()->SetRangeUser(0,40); //sets the X axis range
  Axis3->GetYaxis()->SetTitle("Triggered Events");
  Axis3->GetXaxis()->SetTitle("R_{FD} [km]");
  Axis3->GetYaxis()->SetTitleOffset(1.1);
  Axis3->GetXaxis()->SetTitleOffset(1.2);
  Axis3->GetYaxis()->SetLabelSize(.06);
  Axis3->GetYaxis()->SetTitleSize(.065);
  Axis3->GetXaxis()->SetLabelSize(.06);
  Axis3->GetXaxis()->SetTitleSize(.065);
  Axis3->GetXaxis()->SetLabelFont(132);
  Axis3->GetYaxis()->SetLabelFont(132);
  Axis3->GetXaxis()->SetTitleFont(132);
  Axis3->GetYaxis()->SetTitleFont(132);
  Axis3->GetXaxis()->CenterTitle();
  Axis3->GetYaxis()->CenterTitle();
  // MeanAll->SetMarkerStyle(8); //changes style of plot points. dont need for a histogram
  // MeanAll->SetMarkerSize(1);
  //Mean1->SetLineWidth(2); //slightly thicker lines
  Axis3->Draw(""); //draws histogram

  Mean3->Draw("sames");

  Canvas3->Print("RFDProtonE18_18.5Theta115_120.pdf"); //This saves the plot 


//Now another plot. You can do this as many times as you want. makesure the canvases are named differently.

  
  gStyle->SetStatX(.97);
  gStyle->SetStatW(0.45);
  gStyle->SetStatH(0.25);

  //Counts->Print("Counts.pdf");

}
