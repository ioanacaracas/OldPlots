{
//=========Macro generated from canvas: c1/c1
//=========  (Mon Feb 28 15:32:46 2022) by ROOT version5.34/38
   TCanvas *c1 = new TCanvas("c1", "c1",700,530);
   //c1->Range(0.190725,-2.3625,0.244275,21.2625);
   c1->SetBottomMargin(0.18);
  c1->SetTopMargin(0.07);
  c1->SetFrameLineWidth(2);
  c1->SetLineWidth(2);
  //gStyle->SetTickLength(0.02,"z");
  c1->SetLeftMargin(0.15);
  c1->SetRightMargin(0.05);
   
   TH2F *htemp__1 = new TH2F("htemp__1","lambdaPion:lambdaLgE",40,14.4,21.6,40,36,76);
   htemp__1->SetDirectory(0);
   htemp__1->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   htemp__1->SetTitle("");
   htemp__1->SetLineColor(ci);
   htemp__1->GetXaxis()->SetTitle("lg E / eV");
   htemp__1->GetXaxis()->SetRange(1,40);
   htemp__1->GetXaxis()->SetLabelFont(42);
   htemp__1->GetXaxis()->SetLabelSize(0.035);
   htemp__1->GetXaxis()->SetTitleSize(0.035);
   htemp__1->GetXaxis()->SetTitleFont(42);
   htemp__1->GetYaxis()->SetTitle("<X_{1}>  [g cm^{-2}]");
   htemp__1->GetYaxis()->SetRange(1,40);
   htemp__1->GetYaxis()->SetLabelFont(42);
   htemp__1->GetYaxis()->SetLabelSize(0.035);
   htemp__1->GetYaxis()->SetTitleSize(0.035);
   htemp__1->GetYaxis()->SetTitleFont(42);
   htemp__1->GetZaxis()->SetLabelFont(42);
   htemp__1->GetZaxis()->SetLabelSize(0.035);
   htemp__1->GetZaxis()->SetTitleSize(0.035);
   htemp__1->GetZaxis()->SetTitleFont(42);

   htemp__1->GetYaxis()->SetTitleOffset(1.1);
   htemp__1->GetXaxis()->SetTitleOffset(1.2);
   htemp__1->GetYaxis()->SetLabelSize(.06);
   htemp__1->GetYaxis()->SetTitleSize(.065);
   htemp__1->GetXaxis()->SetLabelSize(.06);
   htemp__1->GetXaxis()->SetTitleSize(.065);
   htemp__1->GetXaxis()->SetLabelFont(132);
   htemp__1->GetYaxis()->SetLabelFont(132);
   htemp__1->GetXaxis()->SetTitleFont(132);
   htemp__1->GetYaxis()->SetTitleFont(132);
   htemp__1->GetXaxis()->CenterTitle();
   htemp__1->GetYaxis()->CenterTitle();

   htemp__1->GetXaxis()->SetRangeUser(16.4, 18.6);
   htemp__1->GetYaxis()->SetRangeUser(40, 65);
   htemp__1->Draw("");
   
   TPaveText *pt = new TPaveText(0.2944413,0.9343684,0.7055587,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   //TText *text = pt->AddText("lambdaPion:lambdaLgE");
  // pt->Draw();
   
   TGraph *graph = new TGraph(31);
   graph->SetName("Graph0");
   // graph->SetTitle("Graph");

   ci = TColor::GetColor("#000099");
   graph->SetLineColor(ci);
   graph->SetMarkerStyle(20);
   graph->SetPoint(0,15,72.90558792);
   graph->SetPoint(1,15.2,70.87625928);
   graph->SetPoint(2,15.4,68.93415431);
   graph->SetPoint(3,15.6,67.07784445);
   graph->SetPoint(4,15.8,65.30474183);
   graph->SetPoint(5,16,63.61181946);
   graph->SetPoint(6,16.2,61.99656959);
   graph->SetPoint(7,16.4,60.45477334);
   graph->SetPoint(8,16.6,58.98295245);
   graph->SetPoint(9,16.8,57.57706534);
   graph->SetPoint(10,17,56.23313756);
   graph->SetPoint(11,17.2,54.94764296);
   graph->SetPoint(12,17.4,53.71679471);
   graph->SetPoint(13,17.6,52.53719482);
   graph->SetPoint(14,17.8,51.40547727);
   graph->SetPoint(15,18,50.3186765);
   graph->SetPoint(16,18.2,49.27401701);
   graph->SetPoint(17,18.4,48.26886918);
   graph->SetPoint(18,18.6,47.30081288);
   graph->SetPoint(19,18.8,46.36778615);
   graph->SetPoint(20,19,45.46750092);
   graph->SetPoint(21,19.2,44.59793794);
   graph->SetPoint(22,19.4,43.75783183);
   graph->SetPoint(23,19.6,42.94518831);
   graph->SetPoint(24,19.8,42.15859437);
   graph->SetPoint(25,20,41.39689234);
   graph->SetPoint(26,20.2,40.6585831);
   graph->SetPoint(27,20.4,39.94270632);
   graph->SetPoint(28,20.6,39.24812391);
   graph->SetPoint(29,20.8,38.57390928);
   graph->SetPoint(30,21,37.91909256);
   
   TH1F *Graph_Graph1 = new TH1F("Graph_Graph1","Graph",100,14.4,21.6);
   Graph_Graph1->SetMinimum(34.42044);
   Graph_Graph1->SetMaximum(76.40424);
   Graph_Graph1->SetDirectory(0);
   Graph_Graph1->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1->SetLineColor(ci);
   Graph_Graph1->GetXaxis()->SetLabelFont(42);
   Graph_Graph1->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1->GetXaxis()->SetTitleFont(42);
   Graph_Graph1->GetYaxis()->SetLabelFont(42);
   Graph_Graph1->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1->GetYaxis()->SetTitleFont(42);
   Graph_Graph1->GetZaxis()->SetLabelFont(42);
   Graph_Graph1->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1->GetZaxis()->SetTitleFont(42);


   graph->SetHistogram(Graph_Graph1);
   
   
   TF1 *PrevFitTMP = new TF1("PrevFitTMP","pol3",14.4,21.6);
   PrevFitTMP->SetFillColor(19);
   PrevFitTMP->SetFillStyle(0);
   PrevFitTMP->SetLineColor(2);
   PrevFitTMP->SetLineWidth(2);
   PrevFitTMP->SetChisquare(0.02307344);
   PrevFitTMP->SetNDF(27);
   PrevFitTMP->GetXaxis()->SetLabelFont(42);
   PrevFitTMP->GetXaxis()->SetLabelSize(0.035);
   PrevFitTMP->GetXaxis()->SetTitleSize(0.035);
   PrevFitTMP->GetXaxis()->SetTitleFont(42);
   PrevFitTMP->GetYaxis()->SetLabelFont(42);
   PrevFitTMP->GetYaxis()->SetLabelSize(0.035);
   PrevFitTMP->GetYaxis()->SetTitleSize(0.035);
   PrevFitTMP->GetYaxis()->SetTitleFont(42);
   PrevFitTMP->SetParameter(0,655.3014);
   PrevFitTMP->SetParError(0,6.752813);
   PrevFitTMP->SetParLimits(0,0,0);
   PrevFitTMP->SetParameter(1,-80.03384);
   PrevFitTMP->SetParError(1,1.136578);
   PrevFitTMP->SetParLimits(1,0,0);
   PrevFitTMP->SetParameter(2,3.586712);
   PrevFitTMP->SetParError(2,0.06343784);
   PrevFitTMP->SetParLimits(2,0,0);
   PrevFitTMP->SetParameter(3,-0.05598447);
   PrevFitTMP->SetParError(3,0.001174282);
   PrevFitTMP->SetParLimits(3,0,0);
   graph->GetListOfFunctions()->Add(PrevFitTMP);
   graph->Draw("p");
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
   c1->Print("Plots/AverageX1Pions.pdf");
}
