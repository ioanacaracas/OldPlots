/*
 * Plot.C
 *
 *  Created on: Dec 6, 2016
 *      Author: mayotte
 */
void Plot(){ //run via root Plot.C

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

  Double_t monoh1FD[3] = {100.00, 99.0, 99.0};
  Double_t stereoh1FD[3]= {0.0, 99.0, 99.0};
  Double_t triple1FD[3] = {0.0, 0.0, 87.0};

  Double_t monoh2FD[3] = {91.0, 100.0, 95.0};
  Double_t stereoh2FD[3]= {0.0, 96.0, 94.0};
Double_t triple2FD[3] = {0.0, 0.0, 70.0};

Double_t monoh3FD[3] = {80.0, 92.0, 93.0};
  Double_t stereoh3FD[3]= {0.0, 62.0, 80.0};
Double_t triple3FD[3] = {0.0, 0.0, 54.0};

Double_t monoh5FD[3] = {0.0, 59.0, 91.0};
  Double_t stereoh5FD[3]= {0.0, 17.0, 46.0};
Double_t triple5FD[3] = {0.0, 0.0, 9.0};

  Double_t RFD[3] = {5.0, 10.0, 14.0};

	Double_t EffMonoH1FD[3];
	Double_t EffMonoH2FD[3];
	Double_t EffMonoH3FD[3];
	Double_t EffMonoH5FD[3];

	Double_t EffStereoH1FD[3];
	Double_t EffStereoH2FD[3];
	Double_t EffStereoH3FD[3];
	Double_t EffStereoH5FD[3];

	Double_t EffTripleH1FD[3];
	Double_t EffTripleH2FD[3];
	Double_t EffTripleH3FD[3];
	Double_t EffTripleH5FD[3];



	for(int i =0; i<3; i++){
		EffMonoH1FD[i] = monoh1FD[i]/100.0; //100 events sim
		EffMonoH2FD[i] = monoh2FD[i]/100.0;
		EffMonoH3FD[i] = monoh3FD[i]/100.0;
		EffMonoH5FD[i] = monoh5FD[i]/100.0;

		EffStereoH1FD[i] = stereoh1FD[i]/100.0; //100 events sim
		EffStereoH2FD[i] = stereoh2FD[i]/100.0;
		EffStereoH3FD[i] = stereoh3FD[i]/100.0;
		EffStereoH5FD[i] = stereoh5FD[i]/100.0;

		EffTripleH1FD[i] = triple1FD[i]/100.0; //100 events sim
		EffTripleH2FD[i] = triple2FD[i]/100.0;
		EffTripleH3FD[i] = triple3FD[i]/100.0;
		EffTripleH5FD[i] = triple5FD[i]/100.0;

	}

	TGraph* GraphMonoH1 = new TGraph(3, &RFD[0], &monoh1FD[0]);
	GraphMonoH1->SetMarkerStyle(8);
	GraphMonoH1->SetMarkerColor(4);
	GraphMonoH1->SetLineColor(4);
	GraphMonoH1->SetLineWidth(2);
	GraphMonoH1->SetMarkerSize(1.5);


	TGraph* GraphMonoH2 = new TGraph(3, &RFD[0], &monoh2FD[0]);
	GraphMonoH2->SetMarkerStyle(8);
	GraphMonoH2->SetMarkerColor(8);
	GraphMonoH2->SetLineColor(8);
	GraphMonoH2->SetLineWidth(2);
	GraphMonoH2->SetMarkerSize(1.5);

	TGraph* GraphMonoH3 = new TGraph(3, &RFD[0], &monoh3FD[0]);
	GraphMonoH3->SetMarkerStyle(8);
	GraphMonoH3->SetMarkerColor(2);
	GraphMonoH3->SetLineColor(2);
	GraphMonoH3->SetLineWidth(2);
	GraphMonoH3->SetMarkerSize(1.5);

	TGraph* GraphMonoH5 = new TGraph(3, &RFD[0], &monoh5FD[0]);
	GraphMonoH5->SetMarkerStyle(8);
	GraphMonoH5->SetMarkerColor(1);
	GraphMonoH5->SetLineColor(1);
	GraphMonoH5->SetLineWidth(2);
	GraphMonoH5->SetMarkerSize(1.5);

	TMultiGraph* mgMono = new TMultiGraph();
	mgMono->Add(GraphMonoH1);
	mgMono->Add(GraphMonoH2);
	mgMono->Add(GraphMonoH3);
	mgMono->Add(GraphMonoH5);


	TCanvas *CanvasMono = new TCanvas("CanvasMono","CanvasMono",700,530);  //sizes here so change the last 2 to make your plot whatever size you want
	//Canvas1->SetGrid();
	CanvasMono->SetBottomMargin(0.18);
	CanvasMono->SetTopMargin(0.07);
	CanvasMono->SetFrameLineWidth(2);
	CanvasMono->SetLineWidth(2);
	//gStyle->SetTickLength(0.02,"z");
	CanvasMono->SetLeftMargin(0.15);
	CanvasMono->SetRightMargin(0.04);

	CanvasMono->cd();

	mgMono->SetMinimum(-5);
	mgMono->Draw("APL");
	mgMono->GetYaxis()->SetTitle("Triggering Efficiency (%)");
	mgMono->GetXaxis()->SetTitle("R_{FD} [km]");
	mgMono->GetYaxis()->SetTitleOffset(1.1);
	mgMono->GetXaxis()->SetTitleOffset(1.2);
	mgMono->GetYaxis()->SetLabelSize(.06);
	mgMono->GetYaxis()->SetTitleSize(.065);
	mgMono->GetXaxis()->SetLabelSize(.06);
	mgMono->GetXaxis()->SetTitleSize(.065);
	mgMono->GetXaxis()->SetLabelFont(132);
	mgMono->GetYaxis()->SetLabelFont(132);
	mgMono->GetXaxis()->SetTitleFont(132);
	mgMono->GetYaxis()->SetTitleFont(132);
	mgMono->GetXaxis()->CenterTitle();
	mgMono->GetYaxis()->CenterTitle();

	legMono = new TLegend(.7,0.25,.96,0.5); //size of legend
	
	legMono->AddEntry(GraphMonoH1,"#font[132]{H_{1} = 1.4 km}","lp"); //top right
	legMono->AddEntry(GraphMonoH2,"#font[132]{H_{1} = 2 km}","lp"); //bottm left
	legMono->AddEntry(GraphMonoH3,"#font[132]{H_{1} = 3 km}","lp"); //bottom right
	legMono->AddEntry(GraphMonoH5,"#font[132]{H_{1} = 5 km}","lp"); //bottom right
	//leg->AddEntry(Mean4,"#font[132]{h_{int} = 5 km}","lf");

	legMono->SetBorderSize(1);
	legMono->SetTextSize(.04);
	legMono->SetTextFont(132);
	legMono->SetMargin(.28);
	legMono->SetFillStyle(4000);
	legMono->Draw("same"); //draws the legend on the plot

	CanvasMono->Print("TrigEfficiencyMonoEvents.pdf");

	///==========stereo events=============

	TGraph* GraphStereoH1 = new TGraph(3, &RFD[0], &stereoh1FD[0]);
	GraphStereoH1->SetMarkerStyle(8);
	GraphStereoH1->SetMarkerColor(4);
	GraphStereoH1->SetLineColor(4);
	GraphStereoH1->SetLineWidth(2);
	GraphStereoH1->SetMarkerSize(1.5);


	TGraph* GraphStereoH2 = new TGraph(3, &RFD[0], &stereoh2FD[0]);
	GraphStereoH2->SetMarkerStyle(8);
	GraphStereoH2->SetMarkerColor(8);
	GraphStereoH2->SetLineColor(8);
	GraphStereoH2->SetLineWidth(2);
	GraphStereoH2->SetMarkerSize(1.5);

	TGraph* GraphStereoH3 = new TGraph(3, &RFD[0], &stereoh3FD[0]);
	GraphStereoH3->SetMarkerStyle(8);
	GraphStereoH3->SetMarkerColor(2);
	GraphStereoH3->SetLineColor(2);
	GraphStereoH3->SetLineWidth(2);
	GraphStereoH3->SetMarkerSize(1.5);

	TGraph* GraphStereoH5 = new TGraph(3, &RFD[0], &stereoh5FD[0]);
	GraphStereoH5->SetMarkerStyle(8);
	GraphStereoH5->SetMarkerColor(1);
	GraphStereoH5->SetLineColor(1);
	GraphStereoH5->SetLineWidth(2);
	GraphStereoH5->SetMarkerSize(1.5);

	TMultiGraph* mgStereo = new TMultiGraph();
	mgStereo->Add(GraphStereoH1);
	mgStereo->Add(GraphStereoH2);
	mgStereo->Add(GraphStereoH3);
	mgStereo->Add(GraphStereoH5);

	TCanvas *CanvasStereo = new TCanvas("CanvasStereo","CanvasStereo",700,530);  //sizes here so change the last 2 to make your plot whatever size you want
	//Canvas1->SetGrid();
	CanvasStereo->SetBottomMargin(0.18);
	CanvasStereo->SetTopMargin(0.07);
	CanvasStereo->SetFrameLineWidth(2);
	CanvasStereo->SetLineWidth(2);
	//gStyle->SetTickLength(0.02,"z");
	CanvasStereo->SetLeftMargin(0.15);
	CanvasStereo->SetRightMargin(0.04);

	CanvasStereo->cd();

	mgStereo->SetMinimum(-5);
	mgStereo->Draw("APL");
	mgStereo->GetYaxis()->SetTitle("Triggering Efficiency (%)");
	mgStereo->GetXaxis()->SetTitle("R_{FD} [km]");
	mgStereo->GetYaxis()->SetTitleOffset(1.1);
	mgStereo->GetXaxis()->SetTitleOffset(1.2);
	mgStereo->GetYaxis()->SetLabelSize(.06);
	mgStereo->GetYaxis()->SetTitleSize(.065);
	mgStereo->GetXaxis()->SetLabelSize(.06);
	mgStereo->GetXaxis()->SetTitleSize(.065);
	mgStereo->GetXaxis()->SetLabelFont(132);
	mgStereo->GetYaxis()->SetLabelFont(132);
	mgStereo->GetXaxis()->SetTitleFont(132);
	mgStereo->GetYaxis()->SetTitleFont(132);
	mgStereo->GetXaxis()->CenterTitle();
	mgStereo->GetYaxis()->CenterTitle();

	legStereo = new TLegend(.19,0.68,.44,0.93); //size of legend
	
	legStereo->AddEntry(GraphStereoH1,"#font[132]{H_{1} = 1.4 km}","lp"); //top right
	legStereo->AddEntry(GraphStereoH2,"#font[132]{H_{1} = 2 km}","lp"); //bottm left
	legStereo->AddEntry(GraphStereoH3,"#font[132]{H_{1} = 3 km}","lp"); //bottom right
	legStereo->AddEntry(GraphStereoH5,"#font[132]{H_{1} = 5 km}","lp"); //bottom right
	//leg->AddEntry(Mean4,"#font[132]{h_{int} = 5 km}","lf");

	legStereo->SetBorderSize(1);
	legStereo->SetTextSize(.04);
	legStereo->SetTextFont(132);
	legStereo->SetMargin(.28);
	legStereo->SetFillStyle(4000);
	legStereo->Draw("same"); //draws the legend on the plot

	CanvasStereo->Print("TrigEfficiencyStereoEvents.pdf");

	///==========triple events=============

	TGraph* GraphTripleH1 = new TGraph(3, &RFD[0], &triple1FD[0]);
	GraphTripleH1->SetMarkerStyle(8);
	GraphTripleH1->SetMarkerColor(4);
	GraphTripleH1->SetLineColor(4);
	GraphTripleH1->SetLineWidth(2);
	GraphTripleH1->SetMarkerSize(1.5);


	TGraph* GraphTripleH2 = new TGraph(3, &RFD[0], &triple2FD[0]);
	GraphTripleH2->SetMarkerStyle(8);
	GraphTripleH2->SetMarkerColor(8);
	GraphTripleH2->SetLineColor(8);
	GraphTripleH2->SetLineWidth(2);
	GraphTripleH2->SetMarkerSize(1.5);

	TGraph* GraphTripleH3 = new TGraph(3, &RFD[0], &triple3FD[0]);
	GraphTripleH3->SetMarkerStyle(8);
	GraphTripleH3->SetMarkerColor(2);
	GraphTripleH3->SetLineColor(2);
	GraphTripleH3->SetLineWidth(2);
	GraphTripleH3->SetMarkerSize(1.5);

	TGraph* GraphTripleH5 = new TGraph(3, &RFD[0], &triple5FD[0]);
	GraphTripleH5->SetMarkerStyle(8);
	GraphTripleH5->SetMarkerColor(1);
	GraphTripleH5->SetLineColor(1);
	GraphTripleH5->SetLineWidth(2);
	GraphTripleH5->SetMarkerSize(1.5);

	TMultiGraph* mgTriple = new TMultiGraph();
	mgTriple->Add(GraphTripleH1);
	mgTriple->Add(GraphTripleH2);
	mgTriple->Add(GraphTripleH3);
	mgTriple->Add(GraphTripleH5);

	TCanvas *CanvasTriple = new TCanvas("CanvasTriple","CanvasTriple",700,530);  //sizes here so change the last 2 to make your plot whatever size you want
	//Canvas1->SetGrid();
	CanvasTriple->SetBottomMargin(0.18);
	CanvasTriple->SetTopMargin(0.07);
	CanvasTriple->SetFrameLineWidth(2);
	CanvasTriple->SetLineWidth(2);
	//gStyle->SetTickLength(0.02,"z");
	CanvasTriple->SetLeftMargin(0.15);
	CanvasTriple->SetRightMargin(0.04);

	CanvasTriple->cd();

	mgTriple->SetMinimum(-5);
	mgTriple->SetMaximum(104);
	mgTriple->Draw("APL");
	mgTriple->GetYaxis()->SetTitle("Triggering Efficiency (%)");
	mgTriple->GetXaxis()->SetTitle("R_{FD} [km]");
	mgTriple->GetYaxis()->SetTitleOffset(1.1);
	mgTriple->GetXaxis()->SetTitleOffset(1.2);
	mgTriple->GetYaxis()->SetLabelSize(.06);
	mgTriple->GetYaxis()->SetTitleSize(.065);
	mgTriple->GetXaxis()->SetLabelSize(.06);
	mgTriple->GetXaxis()->SetTitleSize(.065);
	mgTriple->GetXaxis()->SetLabelFont(132);
	mgTriple->GetYaxis()->SetLabelFont(132);
	mgTriple->GetXaxis()->SetTitleFont(132);
	mgTriple->GetYaxis()->SetTitleFont(132);
	mgTriple->GetXaxis()->CenterTitle();
	mgTriple->GetYaxis()->CenterTitle();

	legTriple = new TLegend(.19,0.68,.44,0.93); //size of legend
	
	legTriple->AddEntry(GraphTripleH1,"#font[132]{H_{1} = 1.4 km}","lp"); //top right
	legTriple->AddEntry(GraphTripleH2,"#font[132]{H_{1} = 2 km}","lp"); //bottm left
	legTriple->AddEntry(GraphTripleH3,"#font[132]{H_{1} = 3 km}","lp"); //bottom right
	legTriple->AddEntry(GraphTripleH5,"#font[132]{H_{1} = 5 km}","lp"); //bottom right
	//leg->AddEntry(Mean4,"#font[132]{h_{int} = 5 km}","lf");

	legTriple->SetBorderSize(1);
	legTriple->SetTextSize(.04);
	legTriple->SetTextFont(132);
	legTriple->SetMargin(.28);
	legTriple->SetFillStyle(4000);
	legTriple->Draw("same"); //draws the legend on the plot

	CanvasTriple->Print("TrigEfficiencyTripleEvents.pdf");


  TH1F* histo = new TH1F("histo" , "histo", 30, -0.5, 30.5);
  TH1F* histo2 = new TH1F("histo2" , "histo2", 3, -0.5, 30.5);
  TH1F* histo3 = new TH1F("histo3" , "histo3", 3, -0.5, 30.5);
  for(int i=0; i<3;i++)
    { 

      histo->Fill(RFD[i], monoh5FD[i]);
}

for(int i=0; i<3;i++)
    {       histo2->Fill(RFD[i], stereoh5FD[i]);}



for(int i=0; i<3;i++)
    { 

      histo3->Fill(RFD[i], triple5FD[i]);
}
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

  TCanvas *Canvas1 = new TCanvas("Canvas1","Canvas name",200,10,700,400);  //sizes here so change the last 2 to make your plot whatever size you want
  //Canvas1->SetGrid();
  Canvas1->SetRightMargin(0.02);//This changes the margins
  Canvas1->SetLeftMargin(0.175);
  Canvas1->SetTopMargin(0.02);
  Canvas1->SetBottomMargin(0.18);
  Canvas1->SetTicks(1,1);

 
  Axis1->GetYaxis()->SetRangeUser(0,120); //sets the Y axis range
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
  Mean1->SetLineWidth(2); //slightly thicker lines
  Axis1->Draw(""); //draws histogram
 
histo->SetFillColorAlpha(kBlue, 0.35);
histo->SetLineWidth(2);
 histo->Draw("same");
  histo2->SetLineColor(kRed);
  histo2->SetFillColorAlpha(kRed, 0.35);
  histo2->SetLineWidth(2);
  histo2->Draw("same");
   histo3->SetLineColor(kBlack);
  histo3->SetFillColorAlpha(kBlack, 0.35);
  histo3->SetLineWidth(2);
  histo3->Draw("same");

  //Mean1->Rebin(7);
  Mean1->SetFillColorAlpha(kBlue+1, 0.35);
  //Mean1->Draw("sames");  //slightly thicker lines

  // MeanOff->SetMarkerStyle(8);
  // MeanOff->SetMarkerSize(1);

  Mean2->SetLineColor(kRed+1); // change color of this histogram's lines
  Mean2->SetFillColorAlpha(kRed, 0.35); //change color of this histogram's filling and make see through
  Mean2->SetLineWidth(2) ;//slightly thicker lines
  //Mean2->Rebin(7);
  //Mean2->Draw("sames"); //use "sames" if you want a stat box

  Mean3->SetLineColor(kBlack);
  Mean3->SetFillColorAlpha(kBlack, 0.35);
  Mean3->SetLineWidth(2);
  //Mean3->Rebin(7);
  //Mean3->Draw("sames");

  Mean4->SetLineColor(kGreen+1);
  Mean4->SetFillColorAlpha(kGreen, 0.35);
  Mean4->SetLineWidth(2);
  //Mean4->Rebin(7);
  //Mean4->Draw("sames");

  //This makes a legend with 4 spots
  leg = new TLegend(.75,0.75,.95,0.95); //size of legend
  leg->SetNColumns(2); //2 columns
  //leg->AddEntry(Mean1,"another slot","lf"); //top left
  leg->AddEntry(histo,"#font[132]{Mono Events}","lf"); //top right
  leg->AddEntry(histo2,"#font[132]{Stereo Events}","lf"); //bottm left
  leg->AddEntry(histo3,"#font[132]{Triple Events}","lf"); //bottom right
  //leg->AddEntry(Mean4,"#font[132]{h_{int} = 5 km}","lf");
  leg->Draw(); //draws the legend on the plot

  Canvas1->Print("Means.pdf"); //This saves the plot to Mean.pdf

  cout<<"entries: "<<" mono: "<<histo->GetEntries()<<" stereo: "<<histo2->GetEntries()<<" triple: "<<histo3->GetEntries()<<endl;


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
