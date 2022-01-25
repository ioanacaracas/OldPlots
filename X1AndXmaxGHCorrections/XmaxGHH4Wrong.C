{
//=========Macro generated from canvas: c1/c1
//=========  (Fri Jan 21 11:54:23 2022) by ROOT version5.34/38
   TCanvas *c1 = new TCanvas("c1", "c1",10,55,700,500);
   c1->Range(4.999996,-1.18125,555,10.63125);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH1F *htemp__2 = new TH1F("htemp__2","event.fGenShower.fXmaxGH",100,60,500);
   htemp__2->SetBinContent(9,3);
   htemp__2->SetBinContent(14,3);
   htemp__2->SetBinContent(16,4);
   htemp__2->SetBinContent(17,4);
   htemp__2->SetBinContent(18,4);
   htemp__2->SetBinContent(19,1);
   htemp__2->SetBinContent(20,4);
   htemp__2->SetBinContent(21,6);
   htemp__2->SetBinContent(22,3);
   htemp__2->SetBinContent(23,2);
   htemp__2->SetBinContent(24,7);
   htemp__2->SetBinContent(25,4);
   htemp__2->SetBinContent(26,9);
   htemp__2->SetBinContent(27,6);
   htemp__2->SetBinContent(28,1);
   htemp__2->SetBinContent(30,4);
   htemp__2->SetBinContent(32,2);
   htemp__2->SetBinContent(33,2);
   htemp__2->SetBinContent(34,1);
   htemp__2->SetBinContent(36,1);
   htemp__2->SetBinContent(41,3);
   htemp__2->SetBinContent(42,1);
   htemp__2->SetBinContent(43,3);
   htemp__2->SetBinContent(46,2);
   htemp__2->SetBinContent(50,1);
   htemp__2->SetBinContent(54,1);
   htemp__2->SetBinContent(55,1);
   htemp__2->SetBinContent(92,1);
   htemp__2->SetEntries(84);
   htemp__2->SetDirectory(0);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("htemp");
   text->SetTextSize(0.0368);
   text = ptstats->AddText("Entries = 84     ");
   text = ptstats->AddText("Mean  =    176");
   text = ptstats->AddText("RMS   =  53.51");
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
