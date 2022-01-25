void PlotXmaxMCvsXmaxGHWrongH4()

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
   
 TH1F *XmaxMCH4Wrong = new TH1F("XmaxMCH4Wrong","event.fGenShower.fXmax",100,1365,1640);
   XmaxMCH4Wrong->SetBinContent(7,3);
   XmaxMCH4Wrong->SetBinContent(12,2);
   XmaxMCH4Wrong->SetBinContent(15,3);
   XmaxMCH4Wrong->SetBinContent(17,1);
   XmaxMCH4Wrong->SetBinContent(18,4);
   XmaxMCH4Wrong->SetBinContent(20,1);
   XmaxMCH4Wrong->SetBinContent(22,3);
   XmaxMCH4Wrong->SetBinContent(24,4);
   XmaxMCH4Wrong->SetBinContent(28,1);
   XmaxMCH4Wrong->SetBinContent(32,5);
   XmaxMCH4Wrong->SetBinContent(33,1);
   XmaxMCH4Wrong->SetBinContent(34,3);
   XmaxMCH4Wrong->SetBinContent(36,5);
   XmaxMCH4Wrong->SetBinContent(39,1);
   XmaxMCH4Wrong->SetBinContent(40,6);
   XmaxMCH4Wrong->SetBinContent(41,2);
   XmaxMCH4Wrong->SetBinContent(42,1);
   XmaxMCH4Wrong->SetBinContent(45,1);
   XmaxMCH4Wrong->SetBinContent(50,1);
   XmaxMCH4Wrong->SetBinContent(52,4);
   XmaxMCH4Wrong->SetBinContent(53,1);
   XmaxMCH4Wrong->SetBinContent(54,6);
   XmaxMCH4Wrong->SetBinContent(55,1);
   XmaxMCH4Wrong->SetBinContent(59,1);
   XmaxMCH4Wrong->SetBinContent(60,3);
   XmaxMCH4Wrong->SetBinContent(62,1);
   XmaxMCH4Wrong->SetBinContent(63,2);
   XmaxMCH4Wrong->SetBinContent(67,4);
   XmaxMCH4Wrong->SetBinContent(71,4);
   XmaxMCH4Wrong->SetBinContent(72,1);
   XmaxMCH4Wrong->SetBinContent(86,1);
   XmaxMCH4Wrong->SetBinContent(89,3);
   XmaxMCH4Wrong->SetBinContent(93,4);
   XmaxMCH4Wrong->SetEntries(84);
   XmaxMCH4Wrong->SetDirectory(0);
   
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
   // XmaxMCH4Wrong->GetListOfFunctions()->Add(ptstats);
   // ptstats->SetParent(XmaxMCH4Wrong);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   XmaxMCH4Wrong->SetLineColor(4);
   XmaxMCH4Wrong->GetXaxis()->SetTitle("event.fGenShower.fXmax");
   XmaxMCH4Wrong->GetXaxis()->SetRange(1,100);
   XmaxMCH4Wrong->GetXaxis()->SetLabelFont(42);
   XmaxMCH4Wrong->GetXaxis()->SetLabelSize(0.035);
   XmaxMCH4Wrong->GetXaxis()->SetTitleSize(0.035);
   XmaxMCH4Wrong->GetXaxis()->SetTitleFont(42);
   XmaxMCH4Wrong->GetYaxis()->SetLabelFont(42);
   XmaxMCH4Wrong->GetYaxis()->SetLabelSize(0.035);
   XmaxMCH4Wrong->GetYaxis()->SetTitleSize(0.035);
   XmaxMCH4Wrong->GetYaxis()->SetTitleFont(42);
   XmaxMCH4Wrong->GetZaxis()->SetLabelFont(42);
   XmaxMCH4Wrong->GetZaxis()->SetLabelSize(0.035);
   XmaxMCH4Wrong->GetZaxis()->SetTitleSize(0.035);
   XmaxMCH4Wrong->GetZaxis()->SetTitleFont(42);
   

   TH1F *XmaxGHH4Wrong = new TH1F("XmaxGHH4Wrong","event.fGenShower.fXmaxGH",100,60,500);
   XmaxGHH4Wrong->SetBinContent(9,3);
   XmaxGHH4Wrong->SetBinContent(14,3);
   XmaxGHH4Wrong->SetBinContent(16,4);
   XmaxGHH4Wrong->SetBinContent(17,4);
   XmaxGHH4Wrong->SetBinContent(18,4);
   XmaxGHH4Wrong->SetBinContent(19,1);
   XmaxGHH4Wrong->SetBinContent(20,4);
   XmaxGHH4Wrong->SetBinContent(21,6);
   XmaxGHH4Wrong->SetBinContent(22,3);
   XmaxGHH4Wrong->SetBinContent(23,2);
   XmaxGHH4Wrong->SetBinContent(24,7);
   XmaxGHH4Wrong->SetBinContent(25,4);
   XmaxGHH4Wrong->SetBinContent(26,9);
   XmaxGHH4Wrong->SetBinContent(27,6);
   XmaxGHH4Wrong->SetBinContent(28,1);
   XmaxGHH4Wrong->SetBinContent(30,4);
   XmaxGHH4Wrong->SetBinContent(32,2);
   XmaxGHH4Wrong->SetBinContent(33,2);
   XmaxGHH4Wrong->SetBinContent(34,1);
   XmaxGHH4Wrong->SetBinContent(36,1);
   XmaxGHH4Wrong->SetBinContent(41,3);
   XmaxGHH4Wrong->SetBinContent(42,1);
   XmaxGHH4Wrong->SetBinContent(43,3);
   XmaxGHH4Wrong->SetBinContent(46,2);
   XmaxGHH4Wrong->SetBinContent(50,1);
   XmaxGHH4Wrong->SetBinContent(54,1);
   XmaxGHH4Wrong->SetBinContent(55,1);
   XmaxGHH4Wrong->SetBinContent(92,1);
   XmaxGHH4Wrong->SetEntries(84);
   XmaxGHH4Wrong->SetDirectory(0);

   XmaxGHH4Wrong->SetLineColor(2);

   TH1F* Axis2 = new TH1F("Axis2","",10,0,1800);
    Axis2->GetYaxis()->SetRangeUser(0,50); //sets the Y axis range
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
  XmaxMCH4Wrong->Rebin(5);
  XmaxGHH4Wrong->Rebin(5);

  XmaxMCH4Wrong->SetLineWidth(2);
  XmaxGHH4Wrong->SetLineWidth(2);


  XmaxMCH4Wrong->Draw("sames");

   XmaxGHH4Wrong->Draw("sames");

   cout<<XmaxMCH4Wrong->GetBinWidth(2)<<" nbins:"<< XmaxMCH4Wrong->GetXaxis()->GetNbins()<<endl;

   double AverageXmaxMC = XmaxMCH4Wrong->GetMean();
   double AverageXmaxGH = XmaxGHH4Wrong->GetMean();

   TPaveText *ptText = new TPaveText(1100,35,1500,50, "NB" );

   ptText->AddText(TString::Format("< X_{max}^{MC} > = %g", AverageXmaxMC));
   ((TText*)ptText->GetListOfLines()->Last())->SetTextColor(kBlue);
   ptText->AddText(TString::Format("< X_{max}^{GH} > = %g", AverageXmaxGH));
   ((TText*)ptText->GetListOfLines()->Last())->SetTextColor(kRed);


  ptText->SetFillStyle(0);
  ptText->SetBorderSize(0);
  ptText->SetTextSize(.07);    
  ptText->SetTextFont(132);

   ptText->Draw("same");

   c1->Print("XmaxMCvsGHWrongH4.pdf");

   
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
