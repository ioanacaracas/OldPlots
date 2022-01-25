{
//=========Macro generated from canvas: c1/c1
//=========  (Fri Jan 21 11:48:04 2022) by ROOT version5.34/38
   TCanvas *c1 = new TCanvas("c1", "c1",10,55,700,500);
   c1->Range(583.125,-2.75625,951.875,24.80625);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH1F *htemp__1 = new TH1F("htemp__1","event.fGenShower.fXmax",100,620,915);
   htemp__1->SetBinContent(8,2);
   htemp__1->SetBinContent(9,1);
   htemp__1->SetBinContent(10,1);
   htemp__1->SetBinContent(11,4);
   htemp__1->SetBinContent(12,4);
   htemp__1->SetBinContent(13,1);
   htemp__1->SetBinContent(14,3);
   htemp__1->SetBinContent(15,1);
   htemp__1->SetBinContent(16,3);
   htemp__1->SetBinContent(18,2);
   htemp__1->SetBinContent(19,8);
   htemp__1->SetBinContent(20,9);
   htemp__1->SetBinContent(21,15);
   htemp__1->SetBinContent(22,21);
   htemp__1->SetBinContent(24,4);
   htemp__1->SetBinContent(25,19);
   htemp__1->SetBinContent(26,12);
   htemp__1->SetBinContent(27,11);
   htemp__1->SetBinContent(28,11);
   htemp__1->SetBinContent(29,10);
   htemp__1->SetBinContent(30,21);
   htemp__1->SetBinContent(31,14);
   htemp__1->SetBinContent(32,11);
   htemp__1->SetBinContent(33,12);
   htemp__1->SetBinContent(34,10);
   htemp__1->SetBinContent(35,5);
   htemp__1->SetBinContent(36,8);
   htemp__1->SetBinContent(37,10);
   htemp__1->SetBinContent(38,17);
   htemp__1->SetBinContent(39,19);
   htemp__1->SetBinContent(40,18);
   htemp__1->SetBinContent(44,9);
   htemp__1->SetBinContent(45,7);
   htemp__1->SetBinContent(46,15);
   htemp__1->SetBinContent(47,9);
   htemp__1->SetBinContent(49,4);
   htemp__1->SetBinContent(51,3);
   htemp__1->SetBinContent(52,9);
   htemp__1->SetBinContent(53,5);
   htemp__1->SetBinContent(56,1);
   htemp__1->SetBinContent(80,2);
   htemp__1->SetBinContent(86,3);
   htemp__1->SetBinContent(88,6);
   htemp__1->SetBinContent(93,3);
   htemp__1->SetEntries(363);
   htemp__1->SetDirectory(0);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("htemp");
   text->SetTextSize(0.0368);
   text = ptstats->AddText("Entries = 363    ");
   text = ptstats->AddText("Mean  =  719.6");
   text = ptstats->AddText("RMS   =  43.02");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   htemp__1->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(htemp__1);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   htemp__1->SetLineColor(ci);
   htemp__1->GetXaxis()->SetTitle("event.fGenShower.fXmax");
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
   htemp__1->Draw("");
   
   TPaveText *pt = new TPaveText(0.2829799,0.94,0.7170201,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   text = pt->AddText("event.fGenShower.fXmax");
   pt->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
