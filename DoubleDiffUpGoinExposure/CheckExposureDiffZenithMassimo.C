	#include <Math/Polynomial.h>  
#include <Math/Interpolator.h>
#include <TFile.h>
#include <TObject.h>
#include <TRandom.h>
#include <TH1D.h>
#include <TH2D.h>
#include <TProfile.h>
#include <TProfile2D.h>
#include <TTree.h>
#include <TStyle.h>
#include <Riostream.h>
#include <TMath.h>

#include <iostream>
#include <string>
#include <cmath>

	void CheckExposureDiffZenithMassimo(){

		//DoubleDiff File with detector efficiency
	//DoubleDiff File with detector efficiency
	TFile* MassimoFile = new TFile("/home/ioana/PHD/AnalysisXmaxHeightIntEtc/AnitaAnalysis/TauDecay/TauPropagation/ExposureAndFluxLimClean/RootFilesExposureDoubleDiffMassimo/RootFileMassimoICRCCuts.root", "READ");
	MassimoFile->cd();

	TH2D* ExposureEcal = ((TH2D*) MassimoFile->Get("ExposureAllZeniths"));
	ExposureEcal->Sumw2();
	ExposureEcal->SetDirectory(0);

	MassimoFile->Close();

	TFile* MassimoFile = new TFile("/home/ioana/PHD/AnalysisXmaxHeightIntEtc/AnitaAnalysis/TauDecay/TauPropagation/ExposureAndFluxLimClean/RootFilesExposureDoubleDiffMassimo/RootFileMassimoICRCCuts.root", "READ");
	MassimoFile->cd();
	TH2D* ExposureEcalZenith1 = ((TH2D*) MassimoFile->Get("ExposureZenithRange1"));
	ExposureEcalZenith1->Sumw2();
	ExposureEcalZenith1->SetDirectory(0); 
	MassimoFile->Close();


	TFile* MassimoFile = new TFile("/home/ioana/PHD/AnalysisXmaxHeightIntEtc/AnitaAnalysis/TauDecay/TauPropagation/ExposureAndFluxLimClean/RootFilesExposureDoubleDiffMassimo/RootFileMassimoICRCCuts.root", "READ");
	MassimoFile->cd();
	TH2D* ExposureEcalZenith2 = ((TH2D*) MassimoFile->Get("ExposureZenithRange2"));
	ExposureEcalZenith2->Sumw2();
	ExposureEcalZenith2->SetDirectory(0);
	MassimoFile->Close();
	
	TFile* MassimoFile = new TFile("/home/ioana/PHD/AnalysisXmaxHeightIntEtc/AnitaAnalysis/TauDecay/TauPropagation/ExposureAndFluxLimClean/RootFilesExposureDoubleDiffMassimo/RootFileMassimoICRCCuts.root", "READ");
	MassimoFile->cd();

	TH2D* ExposureEcalZenith3 = ((TH2D*) MassimoFile->Get("ExposureZenithRange3"));
	ExposureEcalZenith3->Sumw2();
	ExposureEcalZenith3->SetDirectory(0);
	MassimoFile->Close();




	TH2D* Zenith1 = ExposureEcalZenith1->Clone();
	

	

	
	// Zenith3->SetMarkerColor(2);
	// Zenith3->SetLineColor(2);
	// Zenith3->Draw();
	
	// TFile* RootFileCheckExposureMassimo = new TFile("RootFileCheckExposureMassimo.root", "UPDATE");
	// AllZenith->ProjectionX()->Write("exposureAllZenith");
	// RootFileCheckExposureMassimo->Write();
	// RootFileCheckExposureMassimo->Close();

	TFile* RootFileCheckExposureMassimo = new TFile("../RootFileCheckExposureMassimo.root", "READ");
	TH1D* ExposureZenith1 = ((TH1D*) RootFileCheckExposureMassimo->Get("exposureZenith1"));
	ExposureZenith1->SetDirectory(0);
	TH1D* ExposureZenith2 = ((TH1D*) RootFileCheckExposureMassimo->Get("exposureZenith2"));
	ExposureZenith2->SetDirectory(0);
	TH1D* ExposureZenith3 = ((TH1D*) RootFileCheckExposureMassimo->Get("exposureZenith3"));
	ExposureZenith3->SetDirectory(0);
	TH1D* ExposureAllZenith = ((TH1D*) RootFileCheckExposureMassimo->Get("exposureAllZenith"));
	ExposureAllZenith->SetDirectory(0);

	TCanvas* CanvasZenith1 = new TCanvas("CanvasZenith1", "CanvasZenith1",700,530);
	CanvasZenith1->cd();

	ExposureZenith1->SetLineColor(kRed+3);
	ExposureZenith1->SetMarkerColor(kRed+3);
	ExposureZenith1->SetMarkerStyle(8);

	ExposureZenith2->SetLineColor(kRed);
	ExposureZenith2->SetMarkerColor(kRed);
	ExposureZenith2->SetMarkerStyle(8);

	ExposureZenith3->SetLineColor(4);
	ExposureZenith3->SetMarkerColor(4);
	ExposureZenith3->SetMarkerStyle(4);

	ExposureAllZenith->SetLineColor(1);
	ExposureAllZenith->SetMarkerColor(1);
	ExposureAllZenith->SetMarkerStyle(8);


	ExposureZenith1->Draw("E");
	ExposureZenith2->Draw("Esames");
	ExposureZenith3->Draw("Esames");
	//ExposureAllZenith->Draw("Esames");

	for(int i=0; i<ExposureZenith1->GetXaxis()->GetNbins(); i++){
		cout<<" lgE = "<<ExposureZenith1->GetXaxis()->GetBinCenter(i+1)<<" cont: "<<ExposureZenith1->GetBinContent(i+1)<<endl;
	}

	TCanvas* CanvasExposureMassimo = new TCanvas("CanvasExposureMassimo", "CanvasExposureMassimo", 700,530);
	CanvasExposureMassimo->cd();
	CanvasExposureMassimo->SetBottomMargin(0.18);
	CanvasExposureMassimo->SetTopMargin(0.07);
	CanvasExposureMassimo->SetFrameLineWidth(2);
	CanvasExposureMassimo->SetLineWidth(2);
	gStyle->SetTickLength(0.02,"z");
	CanvasExposureMassimo->SetLeftMargin(0.12);
	CanvasExposureMassimo->SetRightMargin(0.18);

	ExposureEcal->SetTitle("");
	ExposureEcal->GetXaxis()->SetTitle("lg E_{sh} / eV");
	ExposureEcal->GetXaxis()->SetNdivisions(9,2, 0);
	ExposureEcal->GetXaxis()->SetRangeUser(16.5, 18.5);
	ExposureEcal->GetYaxis()->SetTitleOffset(0.75);
	ExposureEcal->GetYaxis()->SetTitle("H_{1} [km]");
	ExposureEcal->GetYaxis()->SetNdivisions(9,0,1);
	ExposureEcal->GetXaxis()->SetTitleOffset(1.25);
	ExposureEcal->GetYaxis()->SetLabelSize(.06);
	ExposureEcal->GetYaxis()->SetTitleSize(.065);
	ExposureEcal->GetXaxis()->SetLabelSize(.06);
	ExposureEcal->GetXaxis()->SetTitleSize(.065);
	ExposureEcal->GetXaxis()->SetLabelFont(132);
	ExposureEcal->GetYaxis()->SetLabelFont(132);
	ExposureEcal->GetXaxis()->SetTitleFont(132);
	ExposureEcal->GetYaxis()->SetTitleFont(132);
	ExposureEcal->GetXaxis()->CenterTitle();
	ExposureEcal->GetYaxis()->CenterTitle();
	cout<<"it should work"<<endl;
	ExposureEcal->GetZaxis()->SetTitle("d#varepsilon/dH [km sr yr]");
	ExposureEcal->GetZaxis()->SetTitleOffset(0.85);
	ExposureEcal->GetZaxis()->SetTitleSize(0.065);
	ExposureEcal->GetZaxis()->SetLabelSize(0.06);
	ExposureEcal->GetZaxis()->SetTitleFont(132);
	ExposureEcal->GetZaxis()->SetLabelFont(132);
	ExposureEcal->GetZaxis()->CenterTitle();


	TGaxis::SetMaxDigits(2);
	gStyle->SetTextFont(22);
	gStyle->SetTextAlign(32);
	gStyle->SetPaintTextFormat(".0f ");


	ExposureEcal->SetMarkerSize(1);
	ExposureEcal->Draw("COLZ");
	gPad->Update();
	TPaletteAxis *palette=(TPaletteAxis*)ExposureEcal->FindObject("palette");
	
	palette->SetX1NDC (0.859);
	palette->SetX2NDC (0.889);

	CanvasExposureMassimo->Print("Plots/ExposureMassimoDoubleDiffNoNr.pdf");

	TCanvas* CanvasExposureMassimoZenith1 = new TCanvas("CanvasExposureMassimoZenith1", "CanvasExposureMassimoZenith1", 700,530);
	CanvasExposureMassimoZenith1->cd();
	CanvasExposureMassimoZenith1->SetBottomMargin(0.18);
	CanvasExposureMassimoZenith1->SetTopMargin(0.07);
	CanvasExposureMassimoZenith1->SetFrameLineWidth(2);
	CanvasExposureMassimoZenith1->SetLineWidth(2);
	gStyle->SetTickLength(0.02,"z");
	CanvasExposureMassimoZenith1->SetLeftMargin(0.11);
	CanvasExposureMassimoZenith1->SetRightMargin(0.2);

	ExposureEcalZenith1->SetTitle("");
	ExposureEcalZenith1->GetXaxis()->SetTitle("lg E_{sh} / eV");
	ExposureEcalZenith1->GetXaxis()->SetNdivisions(9,2, 0);
	ExposureEcalZenith1->GetXaxis()->SetRangeUser(16.5, 18.5);
	ExposureEcalZenith1->GetYaxis()->SetTitleOffset(0.75);
	ExposureEcalZenith1->GetYaxis()->SetTitle("H_{1} [km]");
	ExposureEcalZenith1->GetYaxis()->SetNdivisions(9,0,1);
	ExposureEcalZenith1->GetXaxis()->SetTitleOffset(1.25);
	ExposureEcalZenith1->GetYaxis()->SetLabelSize(.06);
	ExposureEcalZenith1->GetYaxis()->SetTitleSize(.065);
	ExposureEcalZenith1->GetXaxis()->SetLabelSize(.06);
	ExposureEcalZenith1->GetXaxis()->SetTitleSize(.065);
	ExposureEcalZenith1->GetXaxis()->SetLabelFont(132);
	ExposureEcalZenith1->GetYaxis()->SetLabelFont(132);
	ExposureEcalZenith1->GetXaxis()->SetTitleFont(132);
	ExposureEcalZenith1->GetYaxis()->SetTitleFont(132);
	ExposureEcalZenith1->GetXaxis()->CenterTitle();
	ExposureEcalZenith1->GetYaxis()->CenterTitle();
	cout<<"it should work"<<endl;
	ExposureEcalZenith1->GetZaxis()->SetTitle("d#varepsilon/dH [km sr yr]");
	ExposureEcalZenith1->GetZaxis()->SetTitleOffset(0.95);
	ExposureEcalZenith1->GetZaxis()->SetTitleSize(0.065);
	ExposureEcalZenith1->GetZaxis()->SetLabelSize(0.06);
	ExposureEcalZenith1->GetZaxis()->SetTitleFont(132);
	ExposureEcalZenith1->GetZaxis()->SetLabelFont(132);
	ExposureEcalZenith1->GetZaxis()->CenterTitle();
	ExposureEcalZenith1->GetZaxis()->SetRangeUser(0,1.5E3);

//	ExposureEcalZenith1->GetZaxis()->SetNdivisions(5);


	TGaxis::SetMaxDigits(2);
	gStyle->SetTextFont(22);
	gStyle->SetTextAlign(32);
	gStyle->SetPaintTextFormat(".0f ");


	ExposureEcalZenith1->SetMarkerSize(1);
	ExposureEcalZenith1->Draw("COLZTEXT");
	gPad->Update();
	TPaletteAxis *palette2=(TPaletteAxis*)ExposureEcalZenith1->FindObject("palette");
	
	palette2->SetX1NDC (0.849);
	palette2->SetX2NDC (0.879);

	CanvasExposureMassimoZenith1->Print("Plots/ExposureMassimoDoubleDiffZenithRange.pdf");

		// TCanvas* CanvasZenith2 = new TCanvas("CanvasZenith2", "CanvasZenith2",700,530);
	// CanvasZenith2->cd();
	// ExposureEcalZenith2->Draw("COLZ");

	

	// TCanvas* CanvasZenith3 = new TCanvas("CanvasZenith3", "CanvasZenith3",700,530);
	// CanvasZenith3->cd();
	// TH1D* Zenith3 = ExposureEcalZenith3->ProjectionX();
	// Zenith3->SetMarkerColor(1);
	// Zenith3->SetLineColor(1);

	
	
	//Zenith3->Draw();



}