void PlotTProfiles(){

	TFile* RootProfilesFile = new TFile("TFileDecayingEvents.root", "READ");
	RootProfilesFile->cd();

	TProfile2D* AtmoGenDecays = ((TProfile2D*) RootProfilesFile->Get("p2AtmoGenEventsDecaying"));
	TProfile2D* EarthGenDecays = ((TProfile2D*) RootProfilesFile->Get("p2EarthGenEventsDecaying"));
	TProfile2D* FoVDecays = ((TProfile2D*) RootProfilesFile->Get("p2dEventsDecayingInFoV"));

	TH2D* AtmoGenDecays2DHist = ((TH2D*) RootProfilesFile->Get("DecayDistanceWithRespectToEarthVsEprimTauHistEvAtmoGen"));
	TH2D* EarthGenDecays2DHist = ((TH2D*) RootProfilesFile->Get("DecayDistanceWithRespectToEarthVsEprimTauHistEvEarthGen"));
	TH2D* FoVDecays2DHist = ((TH2D*) RootProfilesFile->Get("DecayDistanceWithRespectToEarthVsEprimTauHistAllDecayingEvInAtmo")); // all decays in atmo up to dmax

	gStyle->SetOptStat(0);
	TCanvas* CanvasAtmoGenDecays = new TCanvas("CanvasAtmoGenDecays", "", 200, 10, 700,530);
	CanvasAtmoGenDecays->cd();
	CanvasAtmoGenDecays->SetBottomMargin(0.18);
	CanvasAtmoGenDecays->SetTopMargin(0.07);
	CanvasAtmoGenDecays->SetFrameLineWidth(2);
	CanvasAtmoGenDecays->SetLineWidth(2);
	
	CanvasAtmoGenDecays->SetLeftMargin(0.12);
	CanvasAtmoGenDecays->SetRightMargin(0.18);

	AtmoGenDecays->GetYaxis()->SetRangeUser(7.5,11);
	AtmoGenDecays->GetZaxis()->SetRangeUser(7.5,11);
	
	AtmoGenDecays->GetYaxis()->SetTitle("lg E_{0} / GeV");
	AtmoGenDecays->GetZaxis()->SetTitle("lg E_{decay} / GeV");
	AtmoGenDecays->GetXaxis()->SetTitle("Decay distance [km]");



	AtmoGenDecays->Draw("COLZ");



	TCanvas* CanvasEarthGenDecays = new TCanvas("CanvasEarthGenDecays", "", 200, 10, 700,530);
	CanvasEarthGenDecays->cd();
	CanvasEarthGenDecays->SetBottomMargin(0.18);
	CanvasEarthGenDecays->SetTopMargin(0.07);
	CanvasEarthGenDecays->SetFrameLineWidth(2);
	CanvasEarthGenDecays->SetLineWidth(2);
	
	CanvasEarthGenDecays->SetLeftMargin(0.12);
	CanvasEarthGenDecays->SetRightMargin(0.18);

	EarthGenDecays->GetYaxis()->SetRangeUser(7.5,11);
	EarthGenDecays->GetZaxis()->SetRangeUser(7,11);
	
	EarthGenDecays->GetYaxis()->SetTitle("lg E_{0} / GeV");
	EarthGenDecays->GetZaxis()->SetTitle("lg E_{decay} / GeV");
	EarthGenDecays->GetXaxis()->SetTitle("Decay distance [km]");

	EarthGenDecays->Draw("COLZ");

	TCanvas* CanvasAtmoGenDecays2DHist = new TCanvas("CanvasAtmoGenDecays2DHist", "", 200, 10, 700,530);
	CanvasAtmoGenDecays2DHist->cd();
	CanvasAtmoGenDecays2DHist->SetBottomMargin(0.18);
	CanvasAtmoGenDecays2DHist->SetTopMargin(0.07);
	CanvasAtmoGenDecays2DHist->SetFrameLineWidth(2);
	CanvasAtmoGenDecays2DHist->SetLineWidth(2);
	
	CanvasAtmoGenDecays2DHist->SetLeftMargin(0.14);
	CanvasAtmoGenDecays2DHist->SetRightMargin(0.16);

	//AtmoGenDecays2DHist->GetZaxis()->SetRangeUser(0,550);

	AtmoGenDecays2DHist->SetTitle("");

	AtmoGenDecays2DHist->GetYaxis()->SetTitleOffset(1);
	AtmoGenDecays2DHist->GetXaxis()->SetTitleOffset(1.2);
	AtmoGenDecays2DHist->GetYaxis()->SetLabelSize(.06);
	AtmoGenDecays2DHist->GetYaxis()->SetTitleSize(.065);
	AtmoGenDecays2DHist->GetXaxis()->SetLabelSize(.06);
	AtmoGenDecays2DHist->GetXaxis()->SetTitleSize(.065);
	AtmoGenDecays2DHist->GetXaxis()->SetLabelFont(132);
	AtmoGenDecays2DHist->GetYaxis()->SetLabelFont(132);
	AtmoGenDecays2DHist->GetXaxis()->SetTitleFont(132);
	AtmoGenDecays2DHist->GetYaxis()->SetTitleFont(132);
	AtmoGenDecays2DHist->GetXaxis()->CenterTitle();
	AtmoGenDecays2DHist->GetYaxis()->CenterTitle();
	
	AtmoGenDecays2DHist->GetZaxis()->SetTitle("N_{#tau} decays");
	AtmoGenDecays2DHist->GetZaxis()->SetTitleOffset(0.8);
	AtmoGenDecays2DHist->GetZaxis()->SetTitleSize(0.065);
	AtmoGenDecays2DHist->GetZaxis()->SetLabelSize(0.06);
	AtmoGenDecays2DHist->GetZaxis()->SetTitleFont(132);
	AtmoGenDecays2DHist->GetZaxis()->SetLabelFont(132);
	AtmoGenDecays2DHist->GetZaxis()->CenterTitle();
	AtmoGenDecays2DHist->GetXaxis()->SetRangeUser(0,26.5);
	AtmoGenDecays2DHist->GetYaxis()->SetTitle("lg E_{0} / GeV");	
	AtmoGenDecays2DHist->GetXaxis()->SetTitle("Decay distance [km]");
	gPad->SetLogz();

	AtmoGenDecays2DHist->Draw("COLZ");
	gPad->Update();
	TPaletteAxis *palette=(TPaletteAxis*)AtmoGenDecays2DHist->FindObject("palette");
	
	palette->SetX1NDC (0.859);
	palette->SetX2NDC (0.889);

	CanvasAtmoGenDecays2DHist->Print("Plots/AtmoGenTauDecaysAboveAtmoVsEprimVsDecayDistNoAtmoDensityWeight.pdf");


	TCanvas* CanvasEarthGenDecays2DHist = new TCanvas("CanvasEarthGenDecays2DHist", "", 200, 10, 700,530);
	CanvasEarthGenDecays2DHist->cd();
	CanvasEarthGenDecays2DHist->SetBottomMargin(0.18);
	CanvasEarthGenDecays2DHist->SetTopMargin(0.07);
	CanvasEarthGenDecays2DHist->SetFrameLineWidth(2);
	CanvasEarthGenDecays2DHist->SetLineWidth(2);
	
	CanvasEarthGenDecays2DHist->SetLeftMargin(0.14);
	CanvasEarthGenDecays2DHist->SetRightMargin(0.16);

	//EarthGenDecays2DHist->GetXaxis()->SetRangeUser(0,28);
	//EarthGenDecays2DHist->GetZaxis()->SetRangeUser(0,550);
	EarthGenDecays2DHist->SetTitle("");

	EarthGenDecays2DHist->GetYaxis()->SetTitleOffset(1);
	EarthGenDecays2DHist->GetXaxis()->SetTitleOffset(1.2);
	EarthGenDecays2DHist->GetYaxis()->SetLabelSize(.06);
	EarthGenDecays2DHist->GetYaxis()->SetTitleSize(.065);
	EarthGenDecays2DHist->GetXaxis()->SetLabelSize(.06);
	EarthGenDecays2DHist->GetXaxis()->SetTitleSize(.065);
	EarthGenDecays2DHist->GetXaxis()->SetLabelFont(132);
	EarthGenDecays2DHist->GetYaxis()->SetLabelFont(132);
	EarthGenDecays2DHist->GetXaxis()->SetTitleFont(132);
	EarthGenDecays2DHist->GetYaxis()->SetTitleFont(132);
	EarthGenDecays2DHist->GetXaxis()->CenterTitle();
	EarthGenDecays2DHist->GetYaxis()->CenterTitle();
	
	EarthGenDecays2DHist->GetZaxis()->SetTitle("N_{#tau} decays");
	EarthGenDecays2DHist->GetZaxis()->SetTitleOffset(0.8);
	EarthGenDecays2DHist->GetZaxis()->SetTitleSize(0.065);
	EarthGenDecays2DHist->GetZaxis()->SetLabelSize(0.06);
	EarthGenDecays2DHist->GetZaxis()->SetTitleFont(132);
	EarthGenDecays2DHist->GetZaxis()->SetLabelFont(132);
	EarthGenDecays2DHist->GetZaxis()->CenterTitle();
	EarthGenDecays2DHist->GetXaxis()->SetRangeUser(-50,26.5);
	EarthGenDecays2DHist->GetYaxis()->SetTitle("lg E_{0} / GeV");	
	EarthGenDecays2DHist->GetXaxis()->SetTitle("Decay distance [km]");
	gPad->SetLogz();


	EarthGenDecays2DHist->Draw("COLZ");
	gPad->Update();

	TPaletteAxis *palette2=(TPaletteAxis*)EarthGenDecays2DHist->FindObject("palette");
	
	palette2->SetX1NDC (0.859);
	palette2->SetX2NDC (0.889);

	CanvasEarthGenDecays2DHist->Print("Plots/EarthGenTauDecaysAboveAtmoAndInsideEarthVsEprimVsDecayDistNoAtmoDensityWeight.pdf");

	TCanvas* CanvasAllAtmoDecays = new TCanvas("CanvasAllAtmoDecays", "", 200, 10, 700,530);
	CanvasAllAtmoDecays->cd();
	CanvasAllAtmoDecays->SetBottomMargin(0.18);
	CanvasAllAtmoDecays->SetTopMargin(0.07);
	CanvasAllAtmoDecays->SetFrameLineWidth(2);
	CanvasAllAtmoDecays->SetLineWidth(2);
	
	CanvasAllAtmoDecays->SetLeftMargin(0.14);
	CanvasAllAtmoDecays->SetRightMargin(0.16);

	FoVDecays2DHist->SetTitle("");

	FoVDecays2DHist->GetYaxis()->SetTitleOffset(1);
	FoVDecays2DHist->GetXaxis()->SetTitleOffset(1.2);
	FoVDecays2DHist->GetYaxis()->SetLabelSize(.06);
	FoVDecays2DHist->GetYaxis()->SetTitleSize(.065);
	FoVDecays2DHist->GetXaxis()->SetLabelSize(.06);
	FoVDecays2DHist->GetXaxis()->SetTitleSize(.065);
	FoVDecays2DHist->GetXaxis()->SetLabelFont(132);
	FoVDecays2DHist->GetYaxis()->SetLabelFont(132);
	FoVDecays2DHist->GetXaxis()->SetTitleFont(132);
	FoVDecays2DHist->GetYaxis()->SetTitleFont(132);
	FoVDecays2DHist->GetXaxis()->CenterTitle();
	FoVDecays2DHist->GetYaxis()->CenterTitle();
	
	FoVDecays2DHist->GetZaxis()->SetTitle("N_{#tau} decays");
	FoVDecays2DHist->GetZaxis()->SetTitleOffset(0.8);
	FoVDecays2DHist->GetZaxis()->SetTitleSize(0.065);
	FoVDecays2DHist->GetZaxis()->SetLabelSize(0.06);
	FoVDecays2DHist->GetZaxis()->SetTitleFont(132);
	FoVDecays2DHist->GetZaxis()->SetLabelFont(132);
	FoVDecays2DHist->GetZaxis()->CenterTitle();


	FoVDecays2DHist->GetYaxis()->SetRangeUser(7.5,11);
	FoVDecays2DHist->GetXaxis()->SetRangeUser(0,26.5);
	//FoVDecays2DHist->GetZaxis()->SetRangeUser(0,550);
	
	FoVDecays2DHist->GetYaxis()->SetTitle("lg E_{0} / GeV");
	//AtmoGenDecays->GetZaxis()->SetTitle("lg E_{decay} / GeV");
	FoVDecays2DHist->GetXaxis()->SetTitle("Decay distance [km]");
	
	gPad->SetLogz();
	FoVDecays2DHist->Draw("COLZ");

	gPad->Update();

	TPaletteAxis *palette3=(TPaletteAxis*)FoVDecays2DHist->FindObject("palette");
	
	palette3->SetX1NDC (0.859);
	palette3->SetX2NDC (0.889);

	CanvasAllAtmoDecays->Print("Plots/ALLTauDecaysAboveAtmoVsEprimVsDecayDistNoAtmoDensityWeight.pdf");

	

}