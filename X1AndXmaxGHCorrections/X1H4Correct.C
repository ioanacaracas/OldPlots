{
//=========Macro generated from canvas: c1/c1
//=========  (Thu Jan 20 12:48:13 2022) by ROOT version5.34/38
   TCanvas *c1 = new TCanvas("c1", "c1",700,530);
   //c1->Range(0.190725,-2.3625,0.244275,21.2625);
   c1->SetBottomMargin(0.18);
  c1->SetTopMargin(0.07);
  c1->SetFrameLineWidth(2);
  c1->SetLineWidth(2);
  //gStyle->SetTickLength(0.02,"z");
  c1->SetLeftMargin(0.15);
  c1->SetRightMargin(0.04);
   
   TH1F *htemp__1 = new TH1F("htemp__1","event.fGenShower.fX1",100,694,840);
   htemp__1->SetBinContent(8,8);
   htemp__1->SetBinContent(11,15);
   htemp__1->SetBinContent(12,4);
   htemp__1->SetBinContent(14,5);
   htemp__1->SetBinContent(15,5);
   htemp__1->SetBinContent(16,1);
   htemp__1->SetBinContent(18,11);
   htemp__1->SetBinContent(19,2);
   htemp__1->SetBinContent(22,5);
   htemp__1->SetBinContent(24,2);
   htemp__1->SetBinContent(25,8);
   htemp__1->SetBinContent(27,1);
   htemp__1->SetBinContent(29,4);
   htemp__1->SetBinContent(30,3);
   htemp__1->SetBinContent(31,8);
   htemp__1->SetBinContent(32,3);
   htemp__1->SetBinContent(33,3);
   htemp__1->SetBinContent(34,3);
   htemp__1->SetBinContent(35,4);
   htemp__1->SetBinContent(36,1);
   htemp__1->SetBinContent(38,6);
   htemp__1->SetBinContent(42,2);
   htemp__1->SetBinContent(43,6);
   htemp__1->SetBinContent(45,4);
   htemp__1->SetBinContent(46,3);
   htemp__1->SetBinContent(47,1);
   htemp__1->SetBinContent(48,5);
   htemp__1->SetBinContent(49,11);
   htemp__1->SetBinContent(53,3);
   htemp__1->SetBinContent(54,5);
   htemp__1->SetBinContent(55,6);
   htemp__1->SetBinContent(56,12);
   htemp__1->SetBinContent(61,1);
   htemp__1->SetBinContent(63,4);
   htemp__1->SetBinContent(64,6);
   htemp__1->SetBinContent(66,2);
   htemp__1->SetBinContent(67,4);
   htemp__1->SetBinContent(68,10);
   htemp__1->SetBinContent(69,6);
   htemp__1->SetBinContent(73,10);
   htemp__1->SetBinContent(74,3);
   htemp__1->SetBinContent(76,4);
   htemp__1->SetBinContent(78,3);
   htemp__1->SetBinContent(79,5);
   htemp__1->SetBinContent(81,9);
   htemp__1->SetBinContent(86,3);
   htemp__1->SetBinContent(87,3);
   htemp__1->SetBinContent(88,3);
   htemp__1->SetBinContent(89,1);
   htemp__1->SetBinContent(91,6);
   htemp__1->SetBinContent(93,5);
   htemp__1->SetEntries(248);
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
   text = ptstats->AddText("Entries = 248    ");
   text = ptstats->AddText("Mean  =  762.8");
   text = ptstats->AddText("RMS   =  36.83");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   htemp__1->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(htemp__1);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   htemp__1->SetLineColor(4);
   htemp__1->GetXaxis()->SetTitle("event.fGenShower.fX1");
   htemp__1->GetXaxis()->SetRange(1,100);
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
      TH1F* Axis2 = new TH1F("Axis2","",10,680,850);
    Axis2->GetYaxis()->SetRangeUser(0,20); //sets the Y axis range
  Axis2->GetXaxis()->SetRangeUser(680,850); //sets the X axis range
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

   c1->Print("X1CorrectH4ProtonTheta115-120_E18-18.5.pdf");
}
