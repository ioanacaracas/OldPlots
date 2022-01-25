{
//=========Macro generated from canvas: c1/c1
//=========  (Fri Jan 21 11:52:46 2022) by ROOT version5.34/38
   TCanvas *c1 = new TCanvas("c1", "c1",10,55,700,500);
   c1->Range(583.125,-2.1,951.875,18.9);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH1F *htemp__1 = new TH1F("htemp__1","event.fGenShower.fXmax",100,620,915);
   htemp__1->SetBinContent(8,2);
   htemp__1->SetBinContent(9,1);
   htemp__1->SetBinContent(10,2);
   htemp__1->SetBinContent(11,4);
   htemp__1->SetBinContent(13,2);
   htemp__1->SetBinContent(14,2);
   htemp__1->SetBinContent(15,2);
   htemp__1->SetBinContent(16,3);
   htemp__1->SetBinContent(18,3);
   htemp__1->SetBinContent(19,2);
   htemp__1->SetBinContent(20,3);
   htemp__1->SetBinContent(21,11);
   htemp__1->SetBinContent(22,13);
   htemp__1->SetBinContent(24,4);
   htemp__1->SetBinContent(25,15);
   htemp__1->SetBinContent(26,7);
   htemp__1->SetBinContent(27,3);
   htemp__1->SetBinContent(28,7);
   htemp__1->SetBinContent(29,3);
   htemp__1->SetBinContent(30,16);
   htemp__1->SetBinContent(31,7);
   htemp__1->SetBinContent(32,7);
   htemp__1->SetBinContent(33,7);
   htemp__1->SetBinContent(34,2);
   htemp__1->SetBinContent(35,3);
   htemp__1->SetBinContent(36,2);
   htemp__1->SetBinContent(37,6);
   htemp__1->SetBinContent(38,9);
   htemp__1->SetBinContent(39,10);
   htemp__1->SetBinContent(40,11);
   htemp__1->SetBinContent(44,4);
   htemp__1->SetBinContent(45,2);
   htemp__1->SetBinContent(46,6);
   htemp__1->SetBinContent(47,3);
   htemp__1->SetBinContent(49,2);
   htemp__1->SetBinContent(51,1);
   htemp__1->SetBinContent(52,2);
   htemp__1->SetBinContent(53,1);
   htemp__1->SetBinContent(56,1);
   htemp__1->SetBinContent(80,1);
   htemp__1->SetBinContent(86,3);
   htemp__1->SetBinContent(88,1);
   htemp__1->SetBinContent(93,3);
   htemp__1->SetEntries(199);
   htemp__1->SetDirectory(0);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("htemp");
   text->SetTextSize(0.0368);
   text = ptstats->AddText("Entries = 199    ");
   text = ptstats->AddText("Mean  =    714");
   text = ptstats->AddText("RMS   =  44.39");
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
