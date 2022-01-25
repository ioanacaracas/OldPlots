{
//=========Macro generated from canvas: c1/c1
//=========  (Thu Jan 20 10:31:56 2022) by ROOT version5.34/38
   TCanvas *c1 = new TCanvas("c1", "c1",700,530);
   //c1->Range(0.190725,-2.3625,0.244275,21.2625);
c1->SetBottomMargin(0.18);
  c1->SetTopMargin(0.07);
  c1->SetFrameLineWidth(2);
  c1->SetLineWidth(2);
  //gStyle->SetTickLength(0.02,"z");
  c1->SetLeftMargin(0.15);
  c1->SetRightMargin(0.04);
   
   TH1F *htemp__1 = new TH1F("htemp__1","event.fGenShower.fX1",100,0.1965,0.2385);
   htemp__1->SetBinContent(8,2);
   htemp__1->SetBinContent(9,11);
   htemp__1->SetBinContent(12,15);
   htemp__1->SetBinContent(13,6);
   htemp__1->SetBinContent(15,8);
   htemp__1->SetBinContent(16,2);
   htemp__1->SetBinContent(17,6);
   htemp__1->SetBinContent(18,14);
   htemp__1->SetBinContent(19,7);
   htemp__1->SetBinContent(20,7);
   htemp__1->SetBinContent(22,4);
   htemp__1->SetBinContent(23,6);
   htemp__1->SetBinContent(24,1);
   htemp__1->SetBinContent(25,1);
   htemp__1->SetBinContent(26,6);
   htemp__1->SetBinContent(27,1);
   htemp__1->SetBinContent(28,10);
   htemp__1->SetBinContent(31,18);
   htemp__1->SetBinContent(32,7);
   htemp__1->SetBinContent(33,5);
   htemp__1->SetBinContent(34,5);
   htemp__1->SetBinContent(35,4);
   htemp__1->SetBinContent(36,8);
   htemp__1->SetBinContent(38,3);
   htemp__1->SetBinContent(43,8);
   htemp__1->SetBinContent(45,6);
   htemp__1->SetBinContent(47,5);
   htemp__1->SetBinContent(48,5);
   htemp__1->SetBinContent(49,5);
   htemp__1->SetBinContent(50,12);
   htemp__1->SetBinContent(54,12);
   htemp__1->SetBinContent(56,12);
   htemp__1->SetBinContent(57,8);
   htemp__1->SetBinContent(59,1);
   htemp__1->SetBinContent(62,5);
   htemp__1->SetBinContent(63,4);
   htemp__1->SetBinContent(64,7);
   htemp__1->SetBinContent(66,5);
   htemp__1->SetBinContent(67,4);
   htemp__1->SetBinContent(68,9);
   htemp__1->SetBinContent(69,4);
   htemp__1->SetBinContent(70,1);
   htemp__1->SetBinContent(72,2);
   htemp__1->SetBinContent(73,11);
   htemp__1->SetBinContent(74,11);
   htemp__1->SetBinContent(76,5);
   htemp__1->SetBinContent(78,7);
   htemp__1->SetBinContent(79,4);
   htemp__1->SetBinContent(81,11);
   htemp__1->SetBinContent(84,5);
   htemp__1->SetBinContent(86,5);
   htemp__1->SetBinContent(87,7);
   htemp__1->SetBinContent(88,10);
   htemp__1->SetBinContent(91,14);
   htemp__1->SetBinContent(93,1);
   htemp__1->SetEntries(363);
   htemp__1->SetDirectory(0);
   
   TPaveStats *ptstats = new TPaveStats(0.7,0.71,0.93,0.92,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   ptstats->SetBorderSize(0);
	ptstats->SetTextSize(.04);
	ptstats->SetTextFont(132);
	ptstats->SetMargin(.28);
	ptstats->SetFillStyle(4000);
   TText *text = ptstats->AddText("");
   text->SetTextSize(0.04);
   text = ptstats->AddText("Entries = 363    ");
   text = ptstats->AddText("Mean  = 0.2165");
   text = ptstats->AddText("RMS   = 0.01075");

   ptstats->SetOptStat(1101);
   ptstats->SetOptFit(0);
  ptstats->Draw();
   htemp__1->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(htemp__1);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   htemp__1->SetLineColor(4);
   htemp__1->GetXaxis()->SetTitle("X_{1} [g/cm^{2}]");
   
   htemp__1->GetXaxis()->SetLabelFont(42);
   htemp__1->GetXaxis()->SetLabelSize(0.035);
   htemp__1->GetXaxis()->SetTitleSize(0.035);
   htemp__1->GetXaxis()->SetTitleFont(42);
   htemp__1->GetYaxis()->SetLabelFont(42);
   htemp__1->GetYaxis()->SetLabelSize(0.035);
   htemp__1->GetYaxis()->SetTitleSize(0.035);
   htemp__1->GetYaxis()->SetTitleFont(42);
   htemp__1->GetZaxis()->SetLabelFont(42);
   htemp__1->GetZaxis()->SetLabelSize(0.035);
   htemp__1->GetZaxis()->SetTitleSize(0.035);
   htemp__1->GetZaxis()->SetTitleFont(42);
   htemp__1->GetXaxis()->SetRangeUser(0,1000);

    TH1F* Axis2 = new TH1F("Axis2","",10,0.185,0.27);
    Axis2->GetYaxis()->SetRangeUser(0,20); //sets the Y axis range
  Axis2->GetXaxis()->SetRangeUser(0.185,0.5); //sets the X axis range
  Axis2->GetYaxis()->SetTitle("Events");
  Axis2->GetXaxis()->SetTitle("X_{1} [g/cm^{2}]");
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

  gStyle->SetOptStat(0);

  Axis2->Draw("");

  htemp__1->SetLineWidth(2);

   htemp__1->Draw("same");

   
   gPad->Modified();

   c1->Print("X1CorrectH0ProtonTheta115-120_E18-18.5.pdf");
   
   // TPaveText *pt = new TPaveText(0.3102006,0.94,0.6897994,0.995,"blNDC");
   // pt->SetName("title");
   // pt->SetBorderSize(0);
   // pt->SetFillColor(0);
   // pt->SetFillStyle(0);
   // pt->SetTextFont(42);
   // text = pt->AddText("event.fGenShower.fX1");
   // pt->Draw();
   // c1->Modified();
   // c1->cd();
   // c1->SetSelected(c1);
}
