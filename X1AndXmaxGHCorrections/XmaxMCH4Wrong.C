{
//=========Macro generated from canvas: c1/c1
//=========  (Fri Jan 21 11:54:02 2022) by ROOT version5.34/38
   TCanvas *c1 = new TCanvas("c1", "c1",10,55,700,500);
   c1->Range(1330.625,-0.7875001,1674.375,7.0875);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH1F *htemp__1 = new TH1F("htemp__1","event.fGenShower.fXmax",100,1365,1640);
   htemp__1->SetBinContent(7,3);
   htemp__1->SetBinContent(12,2);
   htemp__1->SetBinContent(15,3);
   htemp__1->SetBinContent(17,1);
   htemp__1->SetBinContent(18,4);
   htemp__1->SetBinContent(20,1);
   htemp__1->SetBinContent(22,3);
   htemp__1->SetBinContent(24,4);
   htemp__1->SetBinContent(28,1);
   htemp__1->SetBinContent(32,5);
   htemp__1->SetBinContent(33,1);
   htemp__1->SetBinContent(34,3);
   htemp__1->SetBinContent(36,5);
   htemp__1->SetBinContent(39,1);
   htemp__1->SetBinContent(40,6);
   htemp__1->SetBinContent(41,2);
   htemp__1->SetBinContent(42,1);
   htemp__1->SetBinContent(45,1);
   htemp__1->SetBinContent(50,1);
   htemp__1->SetBinContent(52,4);
   htemp__1->SetBinContent(53,1);
   htemp__1->SetBinContent(54,6);
   htemp__1->SetBinContent(55,1);
   htemp__1->SetBinContent(59,1);
   htemp__1->SetBinContent(60,3);
   htemp__1->SetBinContent(62,1);
   htemp__1->SetBinContent(63,2);
   htemp__1->SetBinContent(67,4);
   htemp__1->SetBinContent(71,4);
   htemp__1->SetBinContent(72,1);
   htemp__1->SetBinContent(86,1);
   htemp__1->SetBinContent(89,3);
   htemp__1->SetBinContent(93,4);
   htemp__1->SetEntries(84);
   htemp__1->SetDirectory(0);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("htemp");
   text->SetTextSize(0.0368);
   text = ptstats->AddText("Entries = 84     ");
   text = ptstats->AddText("Mean  =   1487");
   text = ptstats->AddText("RMS   =  62.97");
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
