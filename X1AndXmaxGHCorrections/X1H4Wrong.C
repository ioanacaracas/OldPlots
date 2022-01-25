{
//=========Macro generated from canvas: c1/c1
//=========  (Thu Jan 20 12:41:47 2022) by ROOT version5.34/38
   TCanvas *c1 = new TCanvas("c1", "c1",700,530);
   //c1->Range(0.190725,-2.3625,0.244275,21.2625);
   c1->SetBottomMargin(0.18);
  c1->SetTopMargin(0.07);
  c1->SetFrameLineWidth(2);
  c1->SetLineWidth(2);
  //gStyle->SetTickLength(0.02,"z");
  c1->SetLeftMargin(0.15);
  c1->SetRightMargin(0.05);
   TH1F *htemp__1 = new TH1F("htemp__1","event.fGenShower.fX1",100,1035,1245);
   htemp__1->SetBinContent(8,2);
   htemp__1->SetBinContent(11,6);
   htemp__1->SetBinContent(12,3);
   htemp__1->SetBinContent(15,2);
   htemp__1->SetBinContent(16,2);
   htemp__1->SetBinContent(17,2);
   htemp__1->SetBinContent(18,4);
   htemp__1->SetBinContent(19,2);
   htemp__1->SetBinContent(20,2);
   htemp__1->SetBinContent(23,4);
   htemp__1->SetBinContent(28,2);
   htemp__1->SetBinContent(30,1);
   htemp__1->SetBinContent(31,1);
   htemp__1->SetBinContent(32,3);
   htemp__1->SetBinContent(33,1);
   htemp__1->SetBinContent(34,1);
   htemp__1->SetBinContent(36,1);
   htemp__1->SetBinContent(44,2);
   htemp__1->SetBinContent(46,1);
   htemp__1->SetBinContent(48,3);
   htemp__1->SetBinContent(49,2);
   htemp__1->SetBinContent(51,5);
   htemp__1->SetBinContent(55,1);
   htemp__1->SetBinContent(57,1);
   htemp__1->SetBinContent(58,1);
   htemp__1->SetBinContent(66,2);
   htemp__1->SetBinContent(68,4);
   htemp__1->SetBinContent(69,1);
   htemp__1->SetBinContent(70,3);
   htemp__1->SetBinContent(72,1);
   htemp__1->SetBinContent(75,1);
   htemp__1->SetBinContent(76,4);
   htemp__1->SetBinContent(78,1);
   htemp__1->SetBinContent(81,1);
   htemp__1->SetBinContent(84,2);
   htemp__1->SetBinContent(90,1);
   htemp__1->SetBinContent(91,4);
   htemp__1->SetBinContent(92,1);
   htemp__1->SetBinContent(94,3);
   htemp__1->SetEntries(84);
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
   text = ptstats->AddText("Entries = 84     ");
   text = ptstats->AddText("Mean  =   1130");
   text = ptstats->AddText("RMS   =  58.17");
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
      TH1F* Axis2 = new TH1F("Axis2","",10,1020,1300);
    Axis2->GetYaxis()->SetRangeUser(0,10); //sets the Y axis range
  Axis2->GetXaxis()->SetRangeUser(1020,1300); //sets the X axis range
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

    c1->Print("X1WrongH4ProtonTheta115-120_E18-18.5.pdf");
}
