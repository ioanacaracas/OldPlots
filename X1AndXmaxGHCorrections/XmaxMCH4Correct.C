{
//=========Macro generated from canvas: c1/c1
//=========  (Fri Jan 21 11:51:35 2022) by ROOT version5.34/38
   TCanvas *c1 = new TCanvas("c1", "c1",10,55,700,500);
   c1->Range(1322.5,-2.1,1697.5,18.9);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH1F *htemp__1 = new TH1F("htemp__1","event.fGenShower.fXmax",100,1360,1660);
   htemp__1->SetBinContent(8,3);
   htemp__1->SetBinContent(9,9);
   htemp__1->SetBinContent(10,2);
   htemp__1->SetBinContent(12,6);
   htemp__1->SetBinContent(13,14);
   htemp__1->SetBinContent(15,4);
   htemp__1->SetBinContent(16,5);
   htemp__1->SetBinContent(17,4);
   htemp__1->SetBinContent(18,6);
   htemp__1->SetBinContent(19,1);
   htemp__1->SetBinContent(22,7);
   htemp__1->SetBinContent(23,3);
   htemp__1->SetBinContent(24,16);
   htemp__1->SetBinContent(25,4);
   htemp__1->SetBinContent(28,4);
   htemp__1->SetBinContent(31,16);
   htemp__1->SetBinContent(32,8);
   htemp__1->SetBinContent(33,15);
   htemp__1->SetBinContent(34,6);
   htemp__1->SetBinContent(37,5);
   htemp__1->SetBinContent(38,12);
   htemp__1->SetBinContent(39,13);
   htemp__1->SetBinContent(40,8);
   htemp__1->SetBinContent(41,4);
   htemp__1->SetBinContent(42,3);
   htemp__1->SetBinContent(43,3);
   htemp__1->SetBinContent(44,2);
   htemp__1->SetBinContent(45,5);
   htemp__1->SetBinContent(47,2);
   htemp__1->SetBinContent(49,10);
   htemp__1->SetBinContent(51,7);
   htemp__1->SetBinContent(52,4);
   htemp__1->SetBinContent(55,2);
   htemp__1->SetBinContent(56,4);
   htemp__1->SetBinContent(57,2);
   htemp__1->SetBinContent(58,6);
   htemp__1->SetBinContent(59,2);
   htemp__1->SetBinContent(63,5);
   htemp__1->SetBinContent(67,1);
   htemp__1->SetBinContent(68,4);
   htemp__1->SetBinContent(81,1);
   htemp__1->SetBinContent(84,6);
   htemp__1->SetBinContent(87,3);
   htemp__1->SetBinContent(94,1);
   htemp__1->SetEntries(248);
   htemp__1->SetDirectory(0);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("htemp");
   text->SetTextSize(0.0368);
   text = ptstats->AddText("Entries = 248    ");
   text = ptstats->AddText("Mean  =   1466");
   text = ptstats->AddText("RMS   =   54.7");
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
