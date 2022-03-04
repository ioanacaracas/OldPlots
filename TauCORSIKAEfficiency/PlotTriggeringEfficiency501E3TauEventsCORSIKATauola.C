void PlotTriggeringEfficiency501E3TauEventsCORSIKATauola(){
	
	TFile *TauThetamin115H0 = new TFile("./ExposureInfoTauE17_18.5_Theta115-130_H0.root  ","READ");
	TFile *TauThetamin115H2 = new TFile("./ExposureInfoTauE17_18.5_Theta115-130_H2.root  ","READ");
	TFile *TauThetamin115H4 = new TFile("./ExposureInfoTauE17_18.5_Theta115-130_H4.root  ","READ");

	TauThetamin115H0->cd();

	//TMultiGraph * mggraphTrigEfficiencyH0         = ((TMultiGraph*) TauThetamin115H0->Get("mggraphTrigEfficiency"));
	TGraphErrors *	graphTrigEfficiencyEMC17to175H0        = ((TGraphErrors*) TauThetamin115H0->Get("graphTrigEfficiencyEMC17to175"));
  	TGraphErrors *	graphTrigEfficiencyEMC175to18H0        = ((TGraphErrors*) TauThetamin115H0->Get("graphTrigEfficiencyEMC175to18"));
  	TGraphErrors *	graphTrigEfficiencyEMC18to185H0        = ((TGraphErrors*) TauThetamin115H0->Get("graphTrigEfficiencyEMC18to185"));
	TCanvas *Canvas2 = new TCanvas("Canvas2","Canvas name2",700,530);
	Canvas2->SetBottomMargin(0.18);
	Canvas2->SetTopMargin(0.1);
	Canvas2->SetFrameLineWidth(2);
	Canvas2->SetLineWidth(2);
	//gStyle->SetTickLength(0.02,"z");
	Canvas2->SetLeftMargin(0.15);
	Canvas2->SetRightMargin(0.04);

	graphTrigEfficiencyEMC17to175H0->SetFillColorAlpha(kGray+2, .5);
	graphTrigEfficiencyEMC175to18H0->SetFillColorAlpha(kAzure+2, .5);
	graphTrigEfficiencyEMC18to185H0->SetFillColorAlpha(kRed-6, .5);

	TMultiGraph *mggraphTrigEfficiencyH0 = new TMultiGraph();
    mggraphTrigEfficiencyH0-> Add(graphTrigEfficiencyEMC17to175H0);
    mggraphTrigEfficiencyH0-> Add(graphTrigEfficiencyEMC175to18H0);
    mggraphTrigEfficiencyH0-> Add(graphTrigEfficiencyEMC18to185H0);

	mggraphTrigEfficiencyH0->Draw("aple3");

	mggraphTrigEfficiencyH0->GetXaxis()->SetLimits(-0.1,40);
	mggraphTrigEfficiencyH0->SetMinimum(-0.1); //for setting y axis limits
	mggraphTrigEfficiencyH0->SetMaximum(1);

	mggraphTrigEfficiencyH0->GetXaxis()->SetTitle("R_{FD} [km]");
	mggraphTrigEfficiencyH0->GetYaxis()->SetTitle("Triggered Ev/Generated Ev");
	mggraphTrigEfficiencyH0->GetYaxis()->SetTitleOffset(1.15);
	mggraphTrigEfficiencyH0->GetXaxis()->SetTitleOffset(1.2);
	mggraphTrigEfficiencyH0->GetYaxis()->SetLabelSize(.06);
	mggraphTrigEfficiencyH0->GetYaxis()->SetTitleSize(.065);
	mggraphTrigEfficiencyH0->GetXaxis()->SetLabelSize(.06);
	mggraphTrigEfficiencyH0->GetXaxis()->SetTitleSize(.065);
	mggraphTrigEfficiencyH0->GetXaxis()->SetLabelFont(132);
	mggraphTrigEfficiencyH0->GetYaxis()->SetLabelFont(132);
	mggraphTrigEfficiencyH0->GetXaxis()->SetTitleFont(132);
	mggraphTrigEfficiencyH0->GetYaxis()->SetTitleFont(132);
	mggraphTrigEfficiencyH0->GetXaxis()->CenterTitle();
	mggraphTrigEfficiencyH0->GetYaxis()->CenterTitle();

	TLegend *legEffH0 = new TLegend(.42,0.65,.96,0.9);

	legEffH0->SetBorderSize(1);
	legEffH0->SetTextSize(.07);
	legEffH0->SetTextFont(132);
	legEffH0->SetMargin(.2);
	legEffH0->AddEntry(graphTrigEfficiencyEMC17to175H0, "lg E / eV #in  [17, 17.5]" ,"lp");
	legEffH0->AddEntry(graphTrigEfficiencyEMC175to18H0, "lg E / eV #in  [17.5, 18]" ,"lp");
	legEffH0->AddEntry(graphTrigEfficiencyEMC18to185H0, "lg E / eV #in  [18, 18.5]" ,"lp");

	//legES->SetFillStyle(4000);
	legEffH0->SetFillColor(10);
	legEffH0->Draw("same");

	Canvas2->Print("TriggeringEfficiencyThet115-130_H0.pdf");

	//H2


		TauThetamin115H2->cd();

	//TMultiGraph * mggraphTrigEfficiencyH2         = ((TMultiGraph*) TauThetamin115H2->Get("mggraphTrigEfficiency"));
	TGraphErrors *	graphTrigEfficiencyEMC17to175H2        = ((TGraphErrors*) TauThetamin115H2->Get("graphTrigEfficiencyEMC17to175"));
  	TGraphErrors *	graphTrigEfficiencyEMC175to18H2        = ((TGraphErrors*) TauThetamin115H2->Get("graphTrigEfficiencyEMC175to18"));
  	TGraphErrors *	graphTrigEfficiencyEMC18to185H2        = ((TGraphErrors*) TauThetamin115H2->Get("graphTrigEfficiencyEMC18to185"));
	TCanvas *Canvas3 = new TCanvas("Canvas3","Canvas name3",700,530);
	Canvas3->SetBottomMargin(0.18);
	Canvas3->SetTopMargin(0.1);
	Canvas3->SetFrameLineWidth(2);
	Canvas3->SetLineWidth(2);
	//gStyle->SetTickLength(0.02,"z");
	Canvas3->SetLeftMargin(0.15);
	Canvas3->SetRightMargin(0.04);

	graphTrigEfficiencyEMC17to175H2->SetFillColorAlpha(kGray+2, .5);
	graphTrigEfficiencyEMC175to18H2->SetFillColorAlpha(kAzure+2, .5);
	graphTrigEfficiencyEMC18to185H2->SetFillColorAlpha(kRed-6, .5);

	TMultiGraph *mggraphTrigEfficiencyH2 = new TMultiGraph();
    mggraphTrigEfficiencyH2-> Add(graphTrigEfficiencyEMC17to175H2);
    mggraphTrigEfficiencyH2-> Add(graphTrigEfficiencyEMC175to18H2);
    mggraphTrigEfficiencyH2-> Add(graphTrigEfficiencyEMC18to185H2);

	mggraphTrigEfficiencyH2->Draw("aple3");

	mggraphTrigEfficiencyH2->GetXaxis()->SetLimits(-0.1,40);
	mggraphTrigEfficiencyH2->SetMinimum(-0.1); //for setting y axis limits
	mggraphTrigEfficiencyH2->SetMaximum(1);

	mggraphTrigEfficiencyH2->GetXaxis()->SetTitle("R_{FD} [km]");
	mggraphTrigEfficiencyH2->GetYaxis()->SetTitle("Triggered Ev/Generated Ev");
	mggraphTrigEfficiencyH2->GetYaxis()->SetTitleOffset(1.15);
	mggraphTrigEfficiencyH2->GetXaxis()->SetTitleOffset(1.2);
	mggraphTrigEfficiencyH2->GetYaxis()->SetLabelSize(.06);
	mggraphTrigEfficiencyH2->GetYaxis()->SetTitleSize(.065);
	mggraphTrigEfficiencyH2->GetXaxis()->SetLabelSize(.06);
	mggraphTrigEfficiencyH2->GetXaxis()->SetTitleSize(.065);
	mggraphTrigEfficiencyH2->GetXaxis()->SetLabelFont(132);
	mggraphTrigEfficiencyH2->GetYaxis()->SetLabelFont(132);
	mggraphTrigEfficiencyH2->GetXaxis()->SetTitleFont(132);
	mggraphTrigEfficiencyH2->GetYaxis()->SetTitleFont(132);
	mggraphTrigEfficiencyH2->GetXaxis()->CenterTitle();
	mggraphTrigEfficiencyH2->GetYaxis()->CenterTitle();

	TLegend *legEffH2 = new TLegend(.42,0.65,.96,0.9);

	legEffH2->SetBorderSize(1);
	legEffH2->SetTextSize(.07);
	legEffH2->SetTextFont(132);
	legEffH2->SetMargin(.2);
	legEffH2->AddEntry(graphTrigEfficiencyEMC17to175H2, "lg E / eV #in  [17, 17.5]" ,"lp");
	legEffH2->AddEntry(graphTrigEfficiencyEMC175to18H2, "lg E / eV #in  [17.5, 18]" ,"lp");
	legEffH2->AddEntry(graphTrigEfficiencyEMC18to185H2, "lg E / eV #in  [18, 18.5]" ,"lp");

	//legES->SetFillStyle(4000);
	legEffH2->SetFillColor(10);
	legEffH2->Draw("same");

	Canvas3->Print("TriggeringEfficiencyThet115-130_H2.pdf");

	//H4
		TauThetamin115H4->cd();

	//TMultiGraph * mggraphTrigEfficiencyH4         = ((TMultiGraph*) TauThetamin115H4->Get("mggraphTrigEfficiency"));
	TGraphErrors *	graphTrigEfficiencyEMC17to175H4        = ((TGraphErrors*) TauThetamin115H4->Get("graphTrigEfficiencyEMC17to175"));
  	TGraphErrors *	graphTrigEfficiencyEMC175to18H4        = ((TGraphErrors*) TauThetamin115H4->Get("graphTrigEfficiencyEMC175to18"));
  	TGraphErrors *	graphTrigEfficiencyEMC18to185H4        = ((TGraphErrors*) TauThetamin115H4->Get("graphTrigEfficiencyEMC18to185"));
	TCanvas *Canvas4 = new TCanvas("Canvas4","Canvas name3",700,530);
	Canvas4->SetBottomMargin(0.18);
	Canvas4->SetTopMargin(0.1);
	Canvas4->SetFrameLineWidth(2);
	Canvas4->SetLineWidth(2);
	//gStyle->SetTickLength(0.02,"z");
	Canvas4->SetLeftMargin(0.15);
	Canvas4->SetRightMargin(0.04);

	graphTrigEfficiencyEMC17to175H4->SetFillColorAlpha(kGray+2, .5);
	graphTrigEfficiencyEMC175to18H4->SetFillColorAlpha(kAzure+2, .5);
	graphTrigEfficiencyEMC18to185H4->SetFillColorAlpha(kRed-6, .5);

	TMultiGraph *mggraphTrigEfficiencyH4 = new TMultiGraph();
    mggraphTrigEfficiencyH4-> Add(graphTrigEfficiencyEMC17to175H4);
    mggraphTrigEfficiencyH4-> Add(graphTrigEfficiencyEMC175to18H4);
    mggraphTrigEfficiencyH4-> Add(graphTrigEfficiencyEMC18to185H4);

	mggraphTrigEfficiencyH4->Draw("aple3");

	mggraphTrigEfficiencyH4->GetXaxis()->SetLimits(-0.1,40);
	mggraphTrigEfficiencyH4->SetMinimum(-0.1); //for setting y axis limits
	mggraphTrigEfficiencyH4->SetMaximum(1);

	mggraphTrigEfficiencyH4->GetXaxis()->SetTitle("R_{FD} [km]");
	mggraphTrigEfficiencyH4->GetYaxis()->SetTitle("Triggered Ev/Generated Ev");
	mggraphTrigEfficiencyH4->GetYaxis()->SetTitleOffset(1.15);
	mggraphTrigEfficiencyH4->GetXaxis()->SetTitleOffset(1.2);
	mggraphTrigEfficiencyH4->GetYaxis()->SetLabelSize(.06);
	mggraphTrigEfficiencyH4->GetYaxis()->SetTitleSize(.065);
	mggraphTrigEfficiencyH4->GetXaxis()->SetLabelSize(.06);
	mggraphTrigEfficiencyH4->GetXaxis()->SetTitleSize(.065);
	mggraphTrigEfficiencyH4->GetXaxis()->SetLabelFont(132);
	mggraphTrigEfficiencyH4->GetYaxis()->SetLabelFont(132);
	mggraphTrigEfficiencyH4->GetXaxis()->SetTitleFont(132);
	mggraphTrigEfficiencyH4->GetYaxis()->SetTitleFont(132);
	mggraphTrigEfficiencyH4->GetXaxis()->CenterTitle();
	mggraphTrigEfficiencyH4->GetYaxis()->CenterTitle();

	TLegend *legEffH4 = new TLegend(.42,0.65,.96,0.9);

	legEffH4->SetBorderSize(1);
	legEffH4->SetTextSize(.07);
	legEffH4->SetTextFont(132);
	legEffH4->SetMargin(.2);
	legEffH4->AddEntry(graphTrigEfficiencyEMC17to175H4, "lg E / eV #in  [17, 17.5]" ,"lp");
	legEffH4->AddEntry(graphTrigEfficiencyEMC175to18H4, "lg E / eV #in  [17.5, 18]" ,"lp");
	legEffH4->AddEntry(graphTrigEfficiencyEMC18to185H4, "lg E / eV #in  [18, 18.5]" ,"lp");

	//legES->SetFillStyle(4000);
	legEffH4->SetFillColor(10);
	legEffH4->Draw("same");

	Canvas4->Print("TriggeringEfficiencyThet115-130_H4.pdf");



}