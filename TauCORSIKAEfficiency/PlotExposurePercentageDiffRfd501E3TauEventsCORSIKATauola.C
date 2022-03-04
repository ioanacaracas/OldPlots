void PlotExposurePercentageDiffRfd501E3TauEventsCORSIKATauola(){
	
	TFile *TauThetamin115H0 = new TFile("./ExposureInfoTauE17_18.5_Theta115-130_H0.root  ","READ");
	TauThetamin115H0->cd();

	TGraphErrors *	graphRatioR1H0        = ((TGraphErrors*) TauThetamin115H0->Get("GraphRatioR1H0"));
	TGraphErrors *	graphRatioR2H0        = ((TGraphErrors*) TauThetamin115H0->Get("GraphRatioR2H0"));
	TGraphErrors *	graphRatioR3H0        = ((TGraphErrors*) TauThetamin115H0->Get("GraphRatioR3H0"));
	TGraphErrors *	graphRatioR4H0        = ((TGraphErrors*) TauThetamin115H0->Get("GraphRatioR4H0"));
	TGraphErrors *	graphRatioR5H0        = ((TGraphErrors*) TauThetamin115H0->Get("GraphRatioR5H0"));

	TGraphErrors *	graphTrigEfficiencyEMC18to185H0        = ((TGraphErrors*) TauThetamin115H0->Get("graphTrigEfficiencyEMC18to185"));
	TCanvas *Canvas2 = new TCanvas("Canvas2","Canvas name2",700,530);
	Canvas2->cd();
	Canvas2->SetBottomMargin(0.18);
	Canvas2->SetTopMargin(0.1);
	Canvas2->SetFrameLineWidth(2);
	Canvas2->SetLineWidth(2);
	//gStyle->SetTickLength(0.02,"z");
	Canvas2->SetLeftMargin(0.2);
	Canvas2->SetRightMargin(0.04);

	graphRatioR1H0->SetMarkerStyle(20);
	graphRatioR1H0->SetMarkerColor(kBlack);
	graphRatioR1H0->SetLineColor(kBlack);
	graphRatioR1H0->SetMarkerSize(1);
	graphRatioR1H0->SetFillColorAlpha(kGray+2, .5);

	graphRatioR2H0->SetMarkerStyle(21);
	graphRatioR2H0->SetMarkerColor(kBlue);
	graphRatioR2H0->SetMarkerSize(1);
	graphRatioR2H0->SetLineColor(kBlue);
	graphRatioR2H0->SetFillColorAlpha(kAzure+2, .5);

	graphRatioR3H0->SetMarkerStyle(22);
	graphRatioR3H0->SetMarkerColor(kRed);
	graphRatioR3H0->SetMarkerSize(1);
	graphRatioR3H0->SetLineColor(kRed);
	graphRatioR3H0->SetFillColorAlpha(kRed-6, .5);

	graphRatioR4H0->SetMarkerStyle(20);
	graphRatioR4H0->SetMarkerColor(kOrange+4);
	graphRatioR4H0->SetMarkerSize(1);
	graphRatioR4H0->SetLineColor(kOrange+4);
	graphRatioR4H0->SetFillColorAlpha(kOrange-7, .5);

	graphRatioR5H0->SetMarkerStyle(20);
	graphRatioR5H0->SetMarkerColor(kMagenta+1);
	graphRatioR5H0->SetMarkerSize(1);
	graphRatioR5H0->SetLineColor(kMagenta);
	graphRatioR5H0->SetFillColorAlpha(kMagenta-9, .5);

	TMultiGraph *mgDiffRfdPercentageExposure = new TMultiGraph();
	mgDiffRfdPercentageExposure->Add(graphRatioR1H0);
	mgDiffRfdPercentageExposure->Add(graphRatioR2H0);
	mgDiffRfdPercentageExposure->Add(graphRatioR3H0);
	mgDiffRfdPercentageExposure->Add(graphRatioR4H0);
	mgDiffRfdPercentageExposure->Add(graphRatioR5H0);

	mgDiffRfdPercentageExposure->Draw("aple3");

	// mgDiffRfdPercentageExposure->GetXaxis()->SetLimits(-0.1,40);
	// mgDiffRfdPercentageExposure->SetMinimum(-0.1); //for setting y axis limits
	// mgDiffRfdPercentageExposure->SetMaximum(1);

	mgDiffRfdPercentageExposure->GetXaxis()->SetTitle("lg E / eV");
	mgDiffRfdPercentageExposure->GetYaxis()->SetTitle("#frac{Exposure(R_{FD} cut)}{Exposre (no cut)}  [%]");
	mgDiffRfdPercentageExposure->GetYaxis()->SetTitleOffset(1.2);
	mgDiffRfdPercentageExposure->GetXaxis()->SetTitleOffset(1.2);
	mgDiffRfdPercentageExposure->GetYaxis()->SetLabelSize(.06);
	mgDiffRfdPercentageExposure->GetYaxis()->SetTitleSize(.065);
	mgDiffRfdPercentageExposure->GetXaxis()->SetLabelSize(.06);
	mgDiffRfdPercentageExposure->GetXaxis()->SetTitleSize(.065);
	mgDiffRfdPercentageExposure->GetXaxis()->SetLabelFont(132);
	mgDiffRfdPercentageExposure->GetYaxis()->SetLabelFont(132);
	mgDiffRfdPercentageExposure->GetXaxis()->SetTitleFont(132);
	mgDiffRfdPercentageExposure->GetYaxis()->SetTitleFont(132);
	mgDiffRfdPercentageExposure->GetXaxis()->CenterTitle();
	mgDiffRfdPercentageExposure->GetYaxis()->CenterTitle();

	// TPaveText *ptRatio = new TPaveText(18.05,25,18.35,72);
	// ptRatio->AddText("R_{FD} > 1km ");
	// ptRatio->SetTextColor(1); ((TText*)ptRatio->GetListOfLines()->Last())->SetTextColor(1);
	// ptRatio->AddText("R_{FD} > 2 km");
	// ptRatio->SetTextColor(4); ((TText*)ptRatio->GetListOfLines()->Last())->SetTextColor(4);
	// ptRatio->AddText("R_{FD} > 3 km");
	// ptRatio->SetTextColor(2); ((TText*)ptRatio->GetListOfLines()->Last())->SetTextColor(2);
	// ptRatio->AddText("R_{FD} > 4 km");
	// ptRatio->SetTextColor(kOrange+9); ((TText*)ptRatio->GetListOfLines()->Last())->SetTextColor(kOrange+9);
	// ptRatio->AddText("R_{FD} > 5 km");
	// ptRatio->SetTextColor(2); ((TText*)ptRatio->GetListOfLines()->Last())->SetTextColor(6);

	// ptRatio->SetFillStyle(0);
	// ptRatio->SetBorderSize(0);
	// ptRatio->SetTextSize(.07);    
	// ptRatio->SetTextFont(132);

	// ptRatio->Draw();

	TLegend *legEffH0 = new TLegend(.6,0.25,.96,0.65);

	legEffH0->SetBorderSize(1);
	legEffH0->SetTextSize(.06);
	legEffH0->SetTextFont(132);
	legEffH0->SetMargin(.2);
	legEffH0->AddEntry(graphRatioR1H0, "R_{FD} > 1 km" ,"lp");
	legEffH0->AddEntry(graphRatioR2H0, "R_{FD} > 2 km" ,"lp");
	legEffH0->AddEntry(graphRatioR3H0, "R_{FD} > 3 km" ,"lp");
	legEffH0->AddEntry(graphRatioR4H0, "R_{FD} > 4 km" ,"lp");
	legEffH0->AddEntry(graphRatioR5H0, "R_{FD} > 5 km" ,"lp");


	legEffH0->Draw("same");

	Canvas2->Print("RfdExposurePercentageH0Theta115_130.pdf");

}