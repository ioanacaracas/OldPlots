void PlotXmaxMCvsXmaxGHWrongH0()

{
//=========Macro generated from canvas: c1/c1
//=========  (Fri Jan 21 11:48:04 2022) by ROOT version5.34/38
   TCanvas *c1 = new TCanvas("c1", "c1",700,530);
   //c1->Range(0.190725,-2.3625,0.244275,21.2625);
   c1->SetBottomMargin(0.18);
  c1->SetTopMargin(0.07);
  c1->SetFrameLineWidth(2);
  c1->SetLineWidth(2);
  //gStyle->SetTickLength(0.02,"z");
  c1->SetLeftMargin(0.15);
  c1->SetRightMargin(0.05);
   
TH1F *XmaxMCH0Wrong = new TH1F("XmaxMCH0Wrong","event.fGenShower.fXmax",100,620,915);
   XmaxMCH0Wrong->SetBinContent(8,2);
   XmaxMCH0Wrong->SetBinContent(9,1);
   XmaxMCH0Wrong->SetBinContent(10,2);
   XmaxMCH0Wrong->SetBinContent(11,4);
   XmaxMCH0Wrong->SetBinContent(13,2);
   XmaxMCH0Wrong->SetBinContent(14,2);
   XmaxMCH0Wrong->SetBinContent(15,2);
   XmaxMCH0Wrong->SetBinContent(16,3);
   XmaxMCH0Wrong->SetBinContent(18,3);
   XmaxMCH0Wrong->SetBinContent(19,2);
   XmaxMCH0Wrong->SetBinContent(20,3);
   XmaxMCH0Wrong->SetBinContent(21,11);
   XmaxMCH0Wrong->SetBinContent(22,13);
   XmaxMCH0Wrong->SetBinContent(24,4);
   XmaxMCH0Wrong->SetBinContent(25,15);
   XmaxMCH0Wrong->SetBinContent(26,7);
   XmaxMCH0Wrong->SetBinContent(27,3);
   XmaxMCH0Wrong->SetBinContent(28,7);
   XmaxMCH0Wrong->SetBinContent(29,3);
   XmaxMCH0Wrong->SetBinContent(30,16);
   XmaxMCH0Wrong->SetBinContent(31,7);
   XmaxMCH0Wrong->SetBinContent(32,7);
   XmaxMCH0Wrong->SetBinContent(33,7);
   XmaxMCH0Wrong->SetBinContent(34,2);
   XmaxMCH0Wrong->SetBinContent(35,3);
   XmaxMCH0Wrong->SetBinContent(36,2);
   XmaxMCH0Wrong->SetBinContent(37,6);
   XmaxMCH0Wrong->SetBinContent(38,9);
   XmaxMCH0Wrong->SetBinContent(39,10);
   XmaxMCH0Wrong->SetBinContent(40,11);
   XmaxMCH0Wrong->SetBinContent(44,4);
   XmaxMCH0Wrong->SetBinContent(45,2);
   XmaxMCH0Wrong->SetBinContent(46,6);
   XmaxMCH0Wrong->SetBinContent(47,3);
   XmaxMCH0Wrong->SetBinContent(49,2);
   XmaxMCH0Wrong->SetBinContent(51,1);
   XmaxMCH0Wrong->SetBinContent(52,2);
   XmaxMCH0Wrong->SetBinContent(53,1);
   XmaxMCH0Wrong->SetBinContent(56,1);
   XmaxMCH0Wrong->SetBinContent(80,1);
   XmaxMCH0Wrong->SetBinContent(86,3);
   XmaxMCH0Wrong->SetBinContent(88,1);
   XmaxMCH0Wrong->SetBinContent(93,3);
   XmaxMCH0Wrong->SetEntries(199);
   XmaxMCH0Wrong->SetDirectory(0);
   
   // TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   // ptstats->SetName("stats");
   // ptstats->SetBorderSize(1);
   // ptstats->SetFillColor(0);
   // ptstats->SetTextAlign(12);
   // ptstats->SetTextFont(42);
   // TText *text = ptstats->AddText("htemp");
   // text->SetTextSize(0.0368);
   // text = ptstats->AddText("Entries = 363    ");
   // text = ptstats->AddText("Mean  =  719.6");
   // text = ptstats->AddText("RMS   =  43.02");
   // ptstats->SetOptStat(1111);
   // ptstats->SetOptFit(0);
   // ptstats->Draw();
   // XmaxMCH0Wrong->GetListOfFunctions()->Add(ptstats);
   // ptstats->SetParent(XmaxMCH0Wrong);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   XmaxMCH0Wrong->SetLineColor(4);
   XmaxMCH0Wrong->GetXaxis()->SetTitle("event.fGenShower.fXmax");
   XmaxMCH0Wrong->GetXaxis()->SetRange(1,100);
   XmaxMCH0Wrong->GetXaxis()->SetLabelFont(42);
   XmaxMCH0Wrong->GetXaxis()->SetLabelSize(0.035);
   XmaxMCH0Wrong->GetXaxis()->SetTitleSize(0.035);
   XmaxMCH0Wrong->GetXaxis()->SetTitleFont(42);
   XmaxMCH0Wrong->GetYaxis()->SetLabelFont(42);
   XmaxMCH0Wrong->GetYaxis()->SetLabelSize(0.035);
   XmaxMCH0Wrong->GetYaxis()->SetTitleSize(0.035);
   XmaxMCH0Wrong->GetYaxis()->SetTitleFont(42);
   XmaxMCH0Wrong->GetZaxis()->SetLabelFont(42);
   XmaxMCH0Wrong->GetZaxis()->SetLabelSize(0.035);
   XmaxMCH0Wrong->GetZaxis()->SetTitleSize(0.035);
   XmaxMCH0Wrong->GetZaxis()->SetTitleFont(42);
   

    TH1F *XmaxGHH0Wrong = new TH1F("XmaxGHH0Wrong","event.fGenShower.fXmaxGH",100,0,1440);
   XmaxGHH0Wrong->SetBinContent(2,2);
   XmaxGHH0Wrong->SetBinContent(5,4);
   XmaxGHH0Wrong->SetBinContent(6,3);
   XmaxGHH0Wrong->SetBinContent(7,5);
   XmaxGHH0Wrong->SetBinContent(20,4);
   XmaxGHH0Wrong->SetBinContent(34,1);
   XmaxGHH0Wrong->SetBinContent(60,1);
   XmaxGHH0Wrong->SetBinContent(63,5);
   XmaxGHH0Wrong->SetBinContent(66,5);
   XmaxGHH0Wrong->SetBinContent(67,1);
   XmaxGHH0Wrong->SetBinContent(68,5);
   XmaxGHH0Wrong->SetBinContent(69,5);
   XmaxGHH0Wrong->SetBinContent(70,6);
   XmaxGHH0Wrong->SetBinContent(71,20);
   XmaxGHH0Wrong->SetBinContent(72,5);
   XmaxGHH0Wrong->SetBinContent(73,13);
   XmaxGHH0Wrong->SetBinContent(74,12);
   XmaxGHH0Wrong->SetBinContent(75,5);
   XmaxGHH0Wrong->SetBinContent(76,15);
   XmaxGHH0Wrong->SetBinContent(77,8);
   XmaxGHH0Wrong->SetBinContent(78,10);
   XmaxGHH0Wrong->SetBinContent(79,4);
   XmaxGHH0Wrong->SetBinContent(80,3);
   XmaxGHH0Wrong->SetBinContent(81,12);
   XmaxGHH0Wrong->SetBinContent(82,6);
   XmaxGHH0Wrong->SetBinContent(83,12);
   XmaxGHH0Wrong->SetBinContent(84,6);
   XmaxGHH0Wrong->SetBinContent(85,8);
   XmaxGHH0Wrong->SetBinContent(86,2);
   XmaxGHH0Wrong->SetBinContent(87,6);
   XmaxGHH0Wrong->SetBinContent(88,2);
   XmaxGHH0Wrong->SetBinContent(90,1);
   XmaxGHH0Wrong->SetBinContent(92,2);
   XmaxGHH0Wrong->SetEntries(199);
   XmaxGHH0Wrong->SetDirectory(0);

   XmaxGHH0Wrong->SetLineColor(2);

   TH1F* Axis2 = new TH1F("Axis2","",10,0,1800);
    Axis2->GetYaxis()->SetRangeUser(0,80); //sets the Y axis range
  Axis2->GetXaxis()->SetRangeUser(0,1800); //sets the X axis range
  Axis2->GetYaxis()->SetTitle("Events");
  Axis2->GetXaxis()->SetTitle("X_{max} [g/cm^{2}]");
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
  XmaxMCH0Wrong->Rebin(5);
  XmaxGHH0Wrong->Rebin(5);

  XmaxMCH0Wrong->SetLineWidth(2);
  XmaxGHH0Wrong->SetLineWidth(2);


  XmaxMCH0Wrong->Draw("sames");

   XmaxGHH0Wrong->Draw("sames");

   cout<<XmaxMCH0Wrong->GetBinWidth(2)<<" nbins:"<< XmaxMCH0Wrong->GetXaxis()->GetNbins()<<endl;

   double AverageXmaxMC = XmaxMCH0Wrong->GetMean();
   double AverageXmaxGH = XmaxGHH0Wrong->GetMean();

   TPaveText *ptText = new TPaveText(1100,55,1500,80, "NB" );

   ptText->AddText(TString::Format("< X_{max}^{MC} > = %g", AverageXmaxMC));
   ((TText*)ptText->GetListOfLines()->Last())->SetTextColor(kBlue);
   ptText->AddText(TString::Format("< X_{max}^{GH} > = %g", AverageXmaxGH));
   ((TText*)ptText->GetListOfLines()->Last())->SetTextColor(kRed);


  ptText->SetFillStyle(0);
  ptText->SetBorderSize(0);
  ptText->SetTextSize(.07);    
  ptText->SetTextFont(132);

   ptText->Draw("same");

   c1->Print("XmaxMCvsGHWrongH0.pdf");

   
   // TPaveText *pt = new TPaveText(0.2829799,0.94,0.7170201,0.995,"blNDC");
   // pt->SetName("title");
   // pt->SetBorderSize(0);
   // pt->SetFillColor(0);
   // pt->SetFillStyle(0);
   // pt->SetTextFont(42);
   // text = pt->AddText("event.fGenShower.fXmax");
   // pt->Draw();
   // c1->Modified();
   // c1->cd();
   // c1->SetSelected(c1);
}
