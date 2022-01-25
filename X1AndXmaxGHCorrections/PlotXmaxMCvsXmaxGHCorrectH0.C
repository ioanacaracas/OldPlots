void PlotXmaxMCvsXmaxGHCorrectH0()

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
   
   TH1F *XmaxMCH0Correct = new TH1F("XmaxMCH0Correct","event.fGenShower.fXmax",100,620,915);
   XmaxMCH0Correct->SetBinContent(8,2);
   XmaxMCH0Correct->SetBinContent(9,1);
   XmaxMCH0Correct->SetBinContent(10,1);
   XmaxMCH0Correct->SetBinContent(11,4);
   XmaxMCH0Correct->SetBinContent(12,4);
   XmaxMCH0Correct->SetBinContent(13,1);
   XmaxMCH0Correct->SetBinContent(14,3);
   XmaxMCH0Correct->SetBinContent(15,1);
   XmaxMCH0Correct->SetBinContent(16,3);
   XmaxMCH0Correct->SetBinContent(18,2);
   XmaxMCH0Correct->SetBinContent(19,8);
   XmaxMCH0Correct->SetBinContent(20,9);
   XmaxMCH0Correct->SetBinContent(21,15);
   XmaxMCH0Correct->SetBinContent(22,21);
   XmaxMCH0Correct->SetBinContent(24,4);
   XmaxMCH0Correct->SetBinContent(25,19);
   XmaxMCH0Correct->SetBinContent(26,12);
   XmaxMCH0Correct->SetBinContent(27,11);
   XmaxMCH0Correct->SetBinContent(28,11);
   XmaxMCH0Correct->SetBinContent(29,10);
   XmaxMCH0Correct->SetBinContent(30,21);
   XmaxMCH0Correct->SetBinContent(31,14);
   XmaxMCH0Correct->SetBinContent(32,11);
   XmaxMCH0Correct->SetBinContent(33,12);
   XmaxMCH0Correct->SetBinContent(34,10);
   XmaxMCH0Correct->SetBinContent(35,5);
   XmaxMCH0Correct->SetBinContent(36,8);
   XmaxMCH0Correct->SetBinContent(37,10);
   XmaxMCH0Correct->SetBinContent(38,17);
   XmaxMCH0Correct->SetBinContent(39,19);
   XmaxMCH0Correct->SetBinContent(40,18);
   XmaxMCH0Correct->SetBinContent(44,9);
   XmaxMCH0Correct->SetBinContent(45,7);
   XmaxMCH0Correct->SetBinContent(46,15);
   XmaxMCH0Correct->SetBinContent(47,9);
   XmaxMCH0Correct->SetBinContent(49,4);
   XmaxMCH0Correct->SetBinContent(51,3);
   XmaxMCH0Correct->SetBinContent(52,9);
   XmaxMCH0Correct->SetBinContent(53,5);
   XmaxMCH0Correct->SetBinContent(56,1);
   XmaxMCH0Correct->SetBinContent(80,2);
   XmaxMCH0Correct->SetBinContent(86,3);
   XmaxMCH0Correct->SetBinContent(88,6);
   XmaxMCH0Correct->SetBinContent(93,3);
   XmaxMCH0Correct->SetEntries(363);
   XmaxMCH0Correct->SetDirectory(0);
   
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
   // XmaxMCH0Correct->GetListOfFunctions()->Add(ptstats);
   // ptstats->SetParent(XmaxMCH0Correct);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   XmaxMCH0Correct->SetLineColor(4);
   XmaxMCH0Correct->GetXaxis()->SetTitle("event.fGenShower.fXmax");
   XmaxMCH0Correct->GetXaxis()->SetRange(1,100);
   XmaxMCH0Correct->GetXaxis()->SetLabelFont(42);
   XmaxMCH0Correct->GetXaxis()->SetLabelSize(0.035);
   XmaxMCH0Correct->GetXaxis()->SetTitleSize(0.035);
   XmaxMCH0Correct->GetXaxis()->SetTitleFont(42);
   XmaxMCH0Correct->GetYaxis()->SetLabelFont(42);
   XmaxMCH0Correct->GetYaxis()->SetLabelSize(0.035);
   XmaxMCH0Correct->GetYaxis()->SetTitleSize(0.035);
   XmaxMCH0Correct->GetYaxis()->SetTitleFont(42);
   XmaxMCH0Correct->GetZaxis()->SetLabelFont(42);
   XmaxMCH0Correct->GetZaxis()->SetLabelSize(0.035);
   XmaxMCH0Correct->GetZaxis()->SetTitleSize(0.035);
   XmaxMCH0Correct->GetZaxis()->SetTitleFont(42);
   

    TH1F *XmaxGHH0Correct = new TH1F("XmaxGHH0Correct","event.fGenShower.fXmaxGH",100,605,915);
   XmaxGHH0Correct->SetBinContent(9,2);
   XmaxGHH0Correct->SetBinContent(15,1);
   XmaxGHH0Correct->SetBinContent(16,3);
   XmaxGHH0Correct->SetBinContent(17,5);
   XmaxGHH0Correct->SetBinContent(18,3);
   XmaxGHH0Correct->SetBinContent(19,1);
   XmaxGHH0Correct->SetBinContent(20,6);
   XmaxGHH0Correct->SetBinContent(21,5);
   XmaxGHH0Correct->SetBinContent(22,1);
   XmaxGHH0Correct->SetBinContent(23,12);
   XmaxGHH0Correct->SetBinContent(25,27);
   XmaxGHH0Correct->SetBinContent(26,6);
   XmaxGHH0Correct->SetBinContent(27,14);
   XmaxGHH0Correct->SetBinContent(28,16);
   XmaxGHH0Correct->SetBinContent(29,10);
   XmaxGHH0Correct->SetBinContent(30,13);
   XmaxGHH0Correct->SetBinContent(32,12);
   XmaxGHH0Correct->SetBinContent(33,21);
   XmaxGHH0Correct->SetBinContent(34,5);
   XmaxGHH0Correct->SetBinContent(35,20);
   XmaxGHH0Correct->SetBinContent(36,9);
   XmaxGHH0Correct->SetBinContent(37,20);
   XmaxGHH0Correct->SetBinContent(38,8);
   XmaxGHH0Correct->SetBinContent(39,9);
   XmaxGHH0Correct->SetBinContent(40,22);
   XmaxGHH0Correct->SetBinContent(41,17);
   XmaxGHH0Correct->SetBinContent(42,15);
   XmaxGHH0Correct->SetBinContent(44,17);
   XmaxGHH0Correct->SetBinContent(45,2);
   XmaxGHH0Correct->SetBinContent(46,9);
   XmaxGHH0Correct->SetBinContent(49,12);
   XmaxGHH0Correct->SetBinContent(52,5);
   XmaxGHH0Correct->SetBinContent(53,5);
   XmaxGHH0Correct->SetBinContent(55,6);
   XmaxGHH0Correct->SetBinContent(56,1);
   XmaxGHH0Correct->SetBinContent(57,9);
   XmaxGHH0Correct->SetBinContent(82,2);
   XmaxGHH0Correct->SetBinContent(84,6);
   XmaxGHH0Correct->SetBinContent(88,3);
   XmaxGHH0Correct->SetBinContent(93,3);
   XmaxGHH0Correct->SetEntries(363);
   XmaxGHH0Correct->SetDirectory(0);

   XmaxGHH0Correct->SetLineColor(2);

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
  XmaxMCH0Correct->Rebin(5);
  XmaxGHH0Correct->Rebin(5);

  XmaxMCH0Correct->SetLineWidth(2);
  XmaxGHH0Correct->SetLineWidth(2);


  XmaxMCH0Correct->Draw("sames");

   XmaxGHH0Correct->Draw("sames");

   cout<<XmaxMCH0Correct->GetBinWidth(2)<<" nbins:"<< XmaxMCH0Correct->GetXaxis()->GetNbins()<<endl;

   double AverageXmaxMC = XmaxMCH0Correct->GetMean();
   double AverageXmaxGH = XmaxGHH0Correct->GetMean();

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

   c1->Print("XmaxMCvsGHCorrectH0.pdf");

   
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
