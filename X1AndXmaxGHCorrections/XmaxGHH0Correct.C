{
//=========Macro generated from canvas: c1/c1
//=========  (Fri Jan 21 11:48:24 2022) by ROOT version5.34/38
   TCanvas *c1 = new TCanvas("c1", "c1",10,55,700,500);
   c1->Range(566.25,-3.54375,953.75,31.89375);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH1F *htemp__2 = new TH1F("htemp__2","event.fGenShower.fXmaxGH",100,605,915);
   htemp__2->SetBinContent(9,2);
   htemp__2->SetBinContent(15,1);
   htemp__2->SetBinContent(16,3);
   htemp__2->SetBinContent(17,5);
   htemp__2->SetBinContent(18,3);
   htemp__2->SetBinContent(19,1);
   htemp__2->SetBinContent(20,6);
   htemp__2->SetBinContent(21,5);
   htemp__2->SetBinContent(22,1);
   htemp__2->SetBinContent(23,12);
   htemp__2->SetBinContent(25,27);
   htemp__2->SetBinContent(26,6);
   htemp__2->SetBinContent(27,14);
   htemp__2->SetBinContent(28,16);
   htemp__2->SetBinContent(29,10);
   htemp__2->SetBinContent(30,13);
   htemp__2->SetBinContent(32,12);
   htemp__2->SetBinContent(33,21);
   htemp__2->SetBinContent(34,5);
   htemp__2->SetBinContent(35,20);
   htemp__2->SetBinContent(36,9);
   htemp__2->SetBinContent(37,20);
   htemp__2->SetBinContent(38,8);
   htemp__2->SetBinContent(39,9);
   htemp__2->SetBinContent(40,22);
   htemp__2->SetBinContent(41,17);
   htemp__2->SetBinContent(42,15);
   htemp__2->SetBinContent(44,17);
   htemp__2->SetBinContent(45,2);
   htemp__2->SetBinContent(46,9);
   htemp__2->SetBinContent(49,12);
   htemp__2->SetBinContent(52,5);
   htemp__2->SetBinContent(53,5);
   htemp__2->SetBinContent(55,6);
   htemp__2->SetBinContent(56,1);
   htemp__2->SetBinContent(57,9);
   htemp__2->SetBinContent(82,2);
   htemp__2->SetBinContent(84,6);
   htemp__2->SetBinContent(88,3);
   htemp__2->SetBinContent(93,3);
   htemp__2->SetEntries(363);
   htemp__2->SetDirectory(0);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("htemp");
   text->SetTextSize(0.0368);
   text = ptstats->AddText("Entries = 363    ");
   text = ptstats->AddText("Mean  =  718.3");
   text = ptstats->AddText("RMS   =   42.6");
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
