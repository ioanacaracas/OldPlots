void PlotGHXmaxInterPolatedOneShower(){
	
	TFile *RootFileWithCanvas = new TFile("Analysis_ProtonE18_18.5_theta115-120_Prod0_H4_GH6ChiZeroNoErrors_NiceGraphForGHFit.root", "READ");
	RootFileWithCanvas->cd();

	TCanvas* CanvasNicePlot =  ((TCanvas*) RootFileWithCanvas->Get( "MyCanvas"));
	CanvasNicePlot->SetCanvasSize(700,530);
	CanvasNicePlot->SetBottomMargin(0.18);
	CanvasNicePlot->SetTopMargin(0.07);
	CanvasNicePlot->SetFrameLineWidth(2);
	CanvasNicePlot->SetLineWidth(2);
	//gStyle->SetTickLength(0.02,"z");
	CanvasNicePlot->SetLeftMargin(0.15);
	CanvasNicePlot->SetRightMargin(0.05);


	gStyle->SetLabelFont(132,"xy");
	gStyle->SetLabelSize(.06, "xy");
	gStyle->SetTitleSize(.065, "xy");
	gStyle->SetTitleSize(.065, "xy");
	gStyle->SetTitleFont(132, "xy");
	gStyle->SetTitleOffset(1.2, "x");

	gStyle->SetTitleX(0.1f);
	gStyle->SetTitleW(0.8f);

	CanvasNicePlot->Draw();

	
	// testCanvas->cd();
	TPaveText* pt;
	pt = (TPaveText*)MyCanvas->GetPrimitive("TPave");
	TCanvas* testCanvas = new TCanvas("c1", "c1");
	   TH1F* Axis2 = new TH1F("Axis2","",10,0,1800);
    Axis2->GetYaxis()->SetRangeUser(0,50); //sets the Y axis range
  Axis2->GetXaxis()->SetRangeUser(0,1800); //sets the X axis range
  Axis2->GetYaxis()->SetTitle("Events");
  Axis2->GetXaxis()->SetTitle("X_{max} [g/cm^{2}]");
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

  Axis2->Draw();
  pt->AddText("smth");
  TText *t2 = pt->GetLineWith("dE/dX)_{max}^{MC}")->AddText("SADSFDSF");
  t2->SetTextColor(kOrange+1);
  t2->SetText(")");
	pt->Draw("same");
 

	
}