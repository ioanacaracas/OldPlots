void PlotXmaxMCvsXmaxGHCorrectH4()

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
   
 TH1F *XmaxMCH4Correct = new TH1F("XmaxMCH4Correct","event.fGenShower.fXmax",100,1360,1660);
   XmaxMCH4Correct->SetBinContent(8,3);
   XmaxMCH4Correct->SetBinContent(9,9);
   XmaxMCH4Correct->SetBinContent(10,2);
   XmaxMCH4Correct->SetBinContent(12,6);
   XmaxMCH4Correct->SetBinContent(13,14);
   XmaxMCH4Correct->SetBinContent(15,4);
   XmaxMCH4Correct->SetBinContent(16,5);
   XmaxMCH4Correct->SetBinContent(17,4);
   XmaxMCH4Correct->SetBinContent(18,6);
   XmaxMCH4Correct->SetBinContent(19,1);
   XmaxMCH4Correct->SetBinContent(22,7);
   XmaxMCH4Correct->SetBinContent(23,3);
   XmaxMCH4Correct->SetBinContent(24,16);
   XmaxMCH4Correct->SetBinContent(25,4);
   XmaxMCH4Correct->SetBinContent(28,4);
   XmaxMCH4Correct->SetBinContent(31,16);
   XmaxMCH4Correct->SetBinContent(32,8);
   XmaxMCH4Correct->SetBinContent(33,15);
   XmaxMCH4Correct->SetBinContent(34,6);
   XmaxMCH4Correct->SetBinContent(37,5);
   XmaxMCH4Correct->SetBinContent(38,12);
   XmaxMCH4Correct->SetBinContent(39,13);
   XmaxMCH4Correct->SetBinContent(40,8);
   XmaxMCH4Correct->SetBinContent(41,4);
   XmaxMCH4Correct->SetBinContent(42,3);
   XmaxMCH4Correct->SetBinContent(43,3);
   XmaxMCH4Correct->SetBinContent(44,2);
   XmaxMCH4Correct->SetBinContent(45,5);
   XmaxMCH4Correct->SetBinContent(47,2);
   XmaxMCH4Correct->SetBinContent(49,10);
   XmaxMCH4Correct->SetBinContent(51,7);
   XmaxMCH4Correct->SetBinContent(52,4);
   XmaxMCH4Correct->SetBinContent(55,2);
   XmaxMCH4Correct->SetBinContent(56,4);
   XmaxMCH4Correct->SetBinContent(57,2);
   XmaxMCH4Correct->SetBinContent(58,6);
   XmaxMCH4Correct->SetBinContent(59,2);
   XmaxMCH4Correct->SetBinContent(63,5);
   XmaxMCH4Correct->SetBinContent(67,1);
   XmaxMCH4Correct->SetBinContent(68,4);
   XmaxMCH4Correct->SetBinContent(81,1);
   XmaxMCH4Correct->SetBinContent(84,6);
   XmaxMCH4Correct->SetBinContent(87,3);
   XmaxMCH4Correct->SetBinContent(94,1);
   XmaxMCH4Correct->SetEntries(248);
   XmaxMCH4Correct->SetDirectory(0);
   
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
   // XmaxMCH4Correct->GetListOfFunctions()->Add(ptstats);
   // ptstats->SetParent(XmaxMCH4Correct);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   XmaxMCH4Correct->SetLineColor(4);
   XmaxMCH4Correct->GetXaxis()->SetTitle("event.fGenShower.fXmax");
   XmaxMCH4Correct->GetXaxis()->SetRange(1,100);
   XmaxMCH4Correct->GetXaxis()->SetLabelFont(42);
   XmaxMCH4Correct->GetXaxis()->SetLabelSize(0.035);
   XmaxMCH4Correct->GetXaxis()->SetTitleSize(0.035);
   XmaxMCH4Correct->GetXaxis()->SetTitleFont(42);
   XmaxMCH4Correct->GetYaxis()->SetLabelFont(42);
   XmaxMCH4Correct->GetYaxis()->SetLabelSize(0.035);
   XmaxMCH4Correct->GetYaxis()->SetTitleSize(0.035);
   XmaxMCH4Correct->GetYaxis()->SetTitleFont(42);
   XmaxMCH4Correct->GetZaxis()->SetLabelFont(42);
   XmaxMCH4Correct->GetZaxis()->SetLabelSize(0.035);
   XmaxMCH4Correct->GetZaxis()->SetTitleSize(0.035);
   XmaxMCH4Correct->GetZaxis()->SetTitleFont(42);
   

TH1F *XmaxGHH4Correct = new TH1F("XmaxGHH4Correct","event.fGenShower.fXmaxGH",100,1370,1655);
   XmaxGHH4Correct->SetBinContent(8,1);
   XmaxGHH4Correct->SetBinContent(9,11);
   XmaxGHH4Correct->SetBinContent(12,9);
   XmaxGHH4Correct->SetBinContent(14,4);
   XmaxGHH4Correct->SetBinContent(15,10);
   XmaxGHH4Correct->SetBinContent(18,3);
   XmaxGHH4Correct->SetBinContent(19,16);
   XmaxGHH4Correct->SetBinContent(23,1);
   XmaxGHH4Correct->SetBinContent(24,7);
   XmaxGHH4Correct->SetBinContent(25,3);
   XmaxGHH4Correct->SetBinContent(27,10);
   XmaxGHH4Correct->SetBinContent(28,1);
   XmaxGHH4Correct->SetBinContent(29,8);
   XmaxGHH4Correct->SetBinContent(30,2);
   XmaxGHH4Correct->SetBinContent(31,10);
   XmaxGHH4Correct->SetBinContent(32,2);
   XmaxGHH4Correct->SetBinContent(34,4);
   XmaxGHH4Correct->SetBinContent(35,16);
   XmaxGHH4Correct->SetBinContent(37,10);
   XmaxGHH4Correct->SetBinContent(38,4);
   XmaxGHH4Correct->SetBinContent(39,6);
   XmaxGHH4Correct->SetBinContent(40,15);
   XmaxGHH4Correct->SetBinContent(41,3);
   XmaxGHH4Correct->SetBinContent(42,5);
   XmaxGHH4Correct->SetBinContent(44,11);
   XmaxGHH4Correct->SetBinContent(45,8);
   XmaxGHH4Correct->SetBinContent(46,3);
   XmaxGHH4Correct->SetBinContent(47,3);
   XmaxGHH4Correct->SetBinContent(49,2);
   XmaxGHH4Correct->SetBinContent(50,1);
   XmaxGHH4Correct->SetBinContent(51,9);
   XmaxGHH4Correct->SetBinContent(52,3);
   XmaxGHH4Correct->SetBinContent(53,4);
   XmaxGHH4Correct->SetBinContent(54,9);
   XmaxGHH4Correct->SetBinContent(55,2);
   XmaxGHH4Correct->SetBinContent(56,1);
   XmaxGHH4Correct->SetBinContent(57,3);
   XmaxGHH4Correct->SetBinContent(59,1);
   XmaxGHH4Correct->SetBinContent(61,4);
   XmaxGHH4Correct->SetBinContent(63,2);
   XmaxGHH4Correct->SetBinContent(66,1);
   XmaxGHH4Correct->SetBinContent(69,4);
   XmaxGHH4Correct->SetBinContent(71,5);
   XmaxGHH4Correct->SetBinContent(82,6);
   XmaxGHH4Correct->SetBinContent(83,1);
   XmaxGHH4Correct->SetBinContent(93,4);
   XmaxGHH4Correct->SetEntries(248);
   XmaxGHH4Correct->SetDirectory(0);

   XmaxGHH4Correct->SetLineColor(2);

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
  XmaxMCH4Correct->Rebin(5);
  XmaxGHH4Correct->Rebin(5);

  XmaxMCH4Correct->SetLineWidth(2);
  XmaxGHH4Correct->SetLineWidth(2);


  XmaxMCH4Correct->Draw("sames");

   XmaxGHH4Correct->Draw("sames");

   cout<<XmaxMCH4Correct->GetBinWidth(2)<<" nbins:"<< XmaxMCH4Correct->GetXaxis()->GetNbins()<<endl;

   double AverageXmaxMC = XmaxMCH4Correct->GetMean();
   double AverageXmaxGH = XmaxGHH4Correct->GetMean();

   TPaveText *ptText = new TPaveText(400,35,800,50, "NB" );

   ptText->AddText(TString::Format("< X_{max}^{MC} > = %g", AverageXmaxMC));
   ((TText*)ptText->GetListOfLines()->Last())->SetTextColor(kBlue);
   ptText->AddText(TString::Format("< X_{max}^{GH} > = %g", AverageXmaxGH));
   ((TText*)ptText->GetListOfLines()->Last())->SetTextColor(kRed);


  ptText->SetFillStyle(0);
  ptText->SetBorderSize(0);
  ptText->SetTextSize(.07);    
  ptText->SetTextFont(132);

   ptText->Draw("same");

   c1->Print("XmaxMCvsGHCorrectH4.pdf");

   
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
