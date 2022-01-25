{
//=========Macro generated from canvas: c1/c1
//=========  (Fri Jan 21 11:53:05 2022) by ROOT version5.34/38
   TCanvas *c1 = new TCanvas("c1", "c1",10,55,700,500);
   c1->Range(-180,-2.625,1620,23.625);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH1F *htemp__2 = new TH1F("htemp__2","event.fGenShower.fXmaxGH",100,0,1440);
   htemp__2->SetBinContent(2,2);
   htemp__2->SetBinContent(5,4);
   htemp__2->SetBinContent(6,3);
   htemp__2->SetBinContent(7,5);
   htemp__2->SetBinContent(20,4);
   htemp__2->SetBinContent(34,1);
   htemp__2->SetBinContent(60,1);
   htemp__2->SetBinContent(63,5);
   htemp__2->SetBinContent(66,5);
   htemp__2->SetBinContent(67,1);
   htemp__2->SetBinContent(68,5);
   htemp__2->SetBinContent(69,5);
   htemp__2->SetBinContent(70,6);
   htemp__2->SetBinContent(71,20);
   htemp__2->SetBinContent(72,5);
   htemp__2->SetBinContent(73,13);
   htemp__2->SetBinContent(74,12);
   htemp__2->SetBinContent(75,5);
   htemp__2->SetBinContent(76,15);
   htemp__2->SetBinContent(77,8);
   htemp__2->SetBinContent(78,10);
   htemp__2->SetBinContent(79,4);
   htemp__2->SetBinContent(80,3);
   htemp__2->SetBinContent(81,12);
   htemp__2->SetBinContent(82,6);
   htemp__2->SetBinContent(83,12);
   htemp__2->SetBinContent(84,6);
   htemp__2->SetBinContent(85,8);
   htemp__2->SetBinContent(86,2);
   htemp__2->SetBinContent(87,6);
   htemp__2->SetBinContent(88,2);
   htemp__2->SetBinContent(90,1);
   htemp__2->SetBinContent(92,2);
   htemp__2->SetEntries(199);
   htemp__2->SetDirectory(0);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("htemp");
   text->SetTextSize(0.0368);
   text = ptstats->AddText("Entries = 199    ");
   text = ptstats->AddText("Mean  =   1001");
   text = ptstats->AddText("RMS   =  295.9");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   htemp__2->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(htemp__2);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   htemp__2->SetLineColor(ci);
   htemp__2->GetXaxis()->SetTitle("event.fGenShower.fXmaxGH");
   htemp__2->GetXaxis()->SetRange(1,100);
   htemp__2->GetXaxis()->SetLabelFont(42);
   htemp__2->GetXaxis()->SetLabelSize(0.035);
   htemp__2->GetXaxis()->SetTitleSize(0.035);
   htemp__2->GetXaxis()->SetTitleFont(42);
   htemp__2->GetYaxis()->SetLabelFont(42);
   htemp__2->GetYaxis()->SetLabelSize(0.035);
   htemp__2->GetYaxis()->SetTitleSize(0.035);
   htemp__2->GetYaxis()->SetTitleFont(42);
   htemp__2->GetZaxis()->SetLabelFont(42);
   htemp__2->GetZaxis()->SetLabelSize(0.035);
   htemp__2->GetZaxis()->SetTitleSize(0.035);
   htemp__2->GetZaxis()->SetTitleFont(42);
   htemp__2->Draw("");
   
   TPaveText *pt = new TPaveText(0.2579083,0.94,0.7420917,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   text = pt->AddText("event.fGenShower.fXmaxGH");
   pt->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
