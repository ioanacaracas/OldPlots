/*
 * Plot.C
 *
 *  Created on: Dec 6, 2016
 *      Author: mayotte
 */
void Plot14km(){ //run via root Plot.C

  //Start Plotting

  gStyle->SetOptStat(0);

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

  TFile *AnalysisFile1 = new TFile("./AnalysisOutHeight1.4FD14km22bins.root","READ");//reading in your root file with histograms
  TFile *AnalysisFile2 = new TFile("./AnalysisOutHeight2FD14km22bins.root","READ");//reading in your root file with histograms
  TFile *AnalysisFile3 = new TFile("./AnalysisOutHeight3FD14km22bins.root","READ");//reading in your root file with histograms
  TFile *AnalysisFile4 = new TFile("./AnalysisOutHeight5FD14km22bins.root","READ");

  AnalysisFile1->cd(); //change to file 1
  TH1F* Mean1        = ((TH1F*) AnalysisFile1->Get("FirstTriggeredPixelEye1")); // copying this tgraph to a local copy for plotting works with histograms and whatever

  AnalysisFile2->cd(); //change to file 2
  TH1F* Mean2        = ((TH1F*) AnalysisFile2->Get("FirstTriggeredPixelEye1")); // copying this tgraph to a local copy for plotting works with histograms and whatever

  AnalysisFile3->cd(); //change to file 2
  TH1F* Mean3        = ((TH1F*) AnalysisFile3->Get("FirstTriggeredPixelEye1")); // copying this tgraph to a local copy for plotting works with histograms and whatever

  AnalysisFile4->cd(); //change to file 2
  TH1F* Mean4        = ((TH1F*) AnalysisFile4->Get("FirstTriggeredPixelEye1"));

  //TLine* ZeroLine = new TLine(17.7,0,19.7,0); // A line to put on your plots if you want one
  //ZeroLine->SetLineStyle(2);
  TH1F* Axis1 = new TH1F("Axis1","",50,0,30);

  TCanvas *Canvas1 = new TCanvas("Canvas1","Canvas name",700,530);  //sizes here so change the last 2 to make your plot whatever size you want
  //Canvas1->SetGrid();
  Canvas1->SetBottomMargin(0.18);
  Canvas1->SetTopMargin(0.07);
  Canvas1->SetFrameLineWidth(2);
  Canvas1->SetLineWidth(2);
  //gStyle->SetTickLength(0.02,"z");
  Canvas1->SetLeftMargin(0.15);
  Axis1->GetYaxis()->SetRangeUser(0,120); //sets the Y axis range
  //Axis1->GetXaxis()->SetRangeUser(0,30); //sets the X axis range
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
  Axis1->GetYaxis()->SetLabelFont(132); //Nice font
  Axis1->GetYaxis()->SetTitleSize(.065); //changes the axis title size
  Axis1->GetYaxis()->CenterTitle(); //centers the axis title
  Axis1->GetYaxis()->SetTitle("#font[132]{Triggered Events}"); // This is the axis title uses latex code basically change '\alpha' for '#alpha' otherwist it is the same
  //Axis1->GetYaxis()->SetTitleOffset(1.2); //distance between axis title and axis
  //Axis1->GetXaxis()->SetTitleSize(.05);//changes the axis title size
  Axis1->GetXaxis()->CenterTitle();//centers the axis title
  Axis1->GetXaxis()->SetLabelFont(132); //Nice font
  Axis1->GetXaxis()->SetTitle("#font[132]{#chi_{1} [#circ]}");// This is the axis title uses latex code basically change '\alpha' for '#alpha' otherwist it is the same
  Axis1->SetTitle(""); //Histogram title here
  // MeanAll->SetMarkerStyle(8); //changes style of plot points. dont need for a histogram
  // MeanAll->SetMarkerSize(1);
  Mean1->SetLineWidth(2); //slightly thicker lines
  Axis1->Draw(""); //draws histogram


  //Mean1->Rebin(7);
  Mean1->SetFillColorAlpha(kBlue+1, 0.35);
  Mean1->Draw("sames");  //slightly thicker lines

  // MeanOff->SetMarkerStyle(8);
  // MeanOff->SetMarkerSize(1);

  Mean2->SetLineColor(kRed+1); // change color of this histogram's lines
  Mean2->SetFillColorAlpha(kRed, 0.35); //change color of this histogram's filling and make see through
  Mean2->SetLineWidth(2) ;//slightly thicker lines
  //Mean2->Rebin(7);
  Mean2->Draw("sames"); //use "sames" if you want a stat box

  Mean3->SetLineColor(kBlack);
  Mean3->SetFillColorAlpha(kBlack, 0.35);
  Mean3->SetLineWidth(2);
  //Mean3->Rebin(7);
  Mean3->Draw("sames");

  Mean4->SetLineColor(kGreen+1);
  Mean4->SetFillColorAlpha(kGreen, 0.35);
  Mean4->SetLineWidth(2);
  //Mean4->Rebin(7);
  Mean4->Draw("sames");

  //This makes a legend with 4 spots
  leg = new TLegend(.5,0.7,.9,0.93); //size of legend
  leg->SetNColumns(2); //2 columns
  //leg->AddEntry(Mean1,"another slot","lf"); //top left
  leg->AddEntry(Mean1,"#font[132]{h_{int} = 1.4 km}","lf"); //top right
  leg->AddEntry(Mean2,"#font[132]{h_{int} = 2 km}","lf"); //bottm left
  leg->AddEntry(Mean3,"#font[132]{h_{int} = 3 km}","lf"); //bottom right
  leg->AddEntry(Mean4,"#font[132]{h_{int} = 5 km}","lf");
  leg->SetBorderSize(1);
  leg->SetTextSize(.04);
  leg->SetTextFont(132);
  leg->SetMargin(.28);
  leg->SetFillStyle(4000);
  leg->Draw(); //draws the legend on the plot

  Canvas1->Print("Chi1RFD14.pdf"); //This saves the plot to Mean.pdf


//Now another plot. You can do this as many times as you want. makesure the canvases are named differently.

  /*TCanvas *Counts = new TCanvas("Counts","Event Counts",200,10,700,500); //A new canvas
  Counts->SetGridy();
  Counts->SetRightMargin(0.02);
  Counts->SetLeftMargin(0.11);
  Counts->SetTopMargin(0.02);
  Counts->SetBottomMargin(0.16);
  Counts->SetLogy();
  Counts->SetTicks(1,1);
  CountsAll->SetTitle("");
  CountsAll->GetYaxis()->SetRangeUser(10,6000);
  CountsAll->GetYaxis()->SetLabelFont(132);
  CountsAll->GetYaxis()->SetLabelSize(.045);
  CountsAll->GetXaxis()->SetLabelSize(.045);
  CountsAll->GetYaxis()->CenterTitle();
  CountsAll->GetYaxis()->SetTitle("#font[132]{Events}");
  CountsAll->GetYaxis()->SetTitleSize(.06);
  CountsAll->GetYaxis()->SetTitleOffset(.7);
  CountsAll->GetXaxis()->SetTitleSize(.06);
  CountsAll->GetXaxis()->CenterTitle();
  CountsAll->GetXaxis()->SetLabelFont(132);
  CountsAll->GetXaxis()->SetTitle("#font[132]{lg[E/eV]}");
  CountsAll->SetMarkerStyle(8);
  CountsAll->SetMarkerSize(1);
  CountsAll->SetMarkerColor(1);
  CountsAll->SetLineWidth(3);
  CountsAll->SetLineStyle(7);
  CountsAll->Draw("APL");
  CountsOn->SetMarkerStyle(21);
  CountsOn->SetMarkerSize(1);
  CountsOn->SetLineColor(kAzure-2);
  CountsOn->SetMarkerColor(kAzure-2);
  CountsOn->Draw("PLSame");
  CountsOff->SetMarkerStyle(22);
  CountsOff->SetMarkerSize(1.5);
  CountsOff->SetLineColor(kRed+2);
  CountsOff->SetMarkerColor(kRed+2);
  CountsOff->Draw("PLSame");
  TLegend *leg3 = new TLegend(.75,0.75,.95,0.95);
  leg3->AddEntry(CountsAll,"#font[132]{All Sky}","pl");
  leg3->AddEntry(CountsOn,"#font[132]{On Plane}","pl");
  leg3->AddEntry(CountsOff,"#font[132]{Off Plane}","pl");
  leg3->Draw();*/

  gStyle->SetStatX(.97);
  gStyle->SetStatW(0.45);
  gStyle->SetStatH(0.25);

  //Counts->Print("Counts.pdf");

}
