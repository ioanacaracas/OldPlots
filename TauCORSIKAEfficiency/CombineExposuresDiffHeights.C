void CombineExposuresDiffHeights(){ //run via root Plot.C

  //Start Plotting

 // gStyle->SetOptStat(1);

  gStyle->SetStatX(.95);
  gStyle->SetStatY(.9);
  // Set x-position (fraction of pad size)
  gStyle->SetStatW(0.4);
  // Set width of stat-box (fraction of pad size)
  gStyle->SetStatH(0.12);
  // Set height of stat-box (fraction of pad size)
  gStyle->SetOptFit(1);
  gStyle->SetPalette(1);
  gStyle->SetCanvasColor(0); //make a white background
  gStyle->SetCanvasBorderMode(0); //turn off the 'raised picture' look
  gStyle->SetFrameBorderMode(0);  //turn off the red axis frames
  gStyle->SetTitleFillColor(0);
  gStyle->SetTitleBorderSize(0);
  gStyle->SetStatColor(0);
  gStyle->SetStatBorderSize(0);
  gStyle->SetPadColor(0);
  gStyle->SetLegendBorderSize(0);
  gStyle->SetFrameLineWidth(1.5);
  gStyle->SetLineWidth(1);
  gStyle->SetEndErrorSize(0);
  gStyle->SetOptStat(1);
  gStyle->SetPalette(1);


  TFile *TauThetamin115H0 = new TFile("./ExposureInfoTauE17_18.5_Theta115-130_H0.root  ","READ");
  TFile *TauThetamin115H1 = new TFile("./ExposureInfoTauE17_18.5_Theta115-130_H1.root  ","READ");
  TFile *TauThetamin115H2 = new TFile("./ExposureInfoTauE17_18.5_Theta115-130_H2.root  ","READ");
  TFile *TauThetamin115H3 = new TFile("./ExposureInfoTauE17_18.5_Theta115-130_H3.root  ","READ");
  TFile *TauThetamin115H4 = new TFile("./ExposureInfoTauE17_18.5_Theta115-130_H4.root  ","READ");

  TauThetamin115H0->cd();
  TGraphErrors *GraphExposureAllEH0        = ((TGraphErrors*) TauThetamin115H0->Get("GraphExposureAllEH0"));
  TGraphErrors *graphExposureCO1yearH0        = ((TGraphErrors*) TauThetamin115H0->Get("graphExposureCO1year"));
  TGraphErrors *graphExposureHEAT1yearH0        = ((TGraphErrors*) TauThetamin115H0->Get("graphExposureHEAT1year"));
  TGraphErrors *	graphTrigEfficiencyEMC17to175H0        = ((TGraphErrors*) TauThetamin115H0->Get("graphTrigEfficiencyEMC17to175"));
  TGraphErrors *	graphTrigEfficiencyEMC175to18H0        = ((TGraphErrors*) TauThetamin115H0->Get("graphTrigEfficiencyEMC175to18"));
  TGraphErrors *	graphTrigEfficiencyEMC18to185H0        = ((TGraphErrors*) TauThetamin115H0->Get("graphTrigEfficiencyEMC18to185"));
  TMultiGraph * mgRatioExposureH0         = ((TMultiGraph*) TauThetamin115H0->Get("mgRatioExposure"));
  TMultiGraph * mggraphTrigEfficiencyH0         = ((TMultiGraph*) TauThetamin115H0->Get("mggraphTrigEfficiency"));

  TauThetamin115H1->cd();
  TGraphErrors *GraphExposureAllEH1        = ((TGraphErrors*) TauThetamin115H1->Get("GraphExposureAllEH0"));
  TGraphErrors *graphExposureCO1yearH1        = ((TGraphErrors*) TauThetamin115H1->Get("graphExposureCO1year"));
  TGraphErrors *graphExposureHEAT1yearH1        = ((TGraphErrors*) TauThetamin115H1->Get("graphExposureHEAT1year"));
  TGraphErrors *	graphTrigEfficiencyEMC17to175H1        = ((TGraphErrors*) TauThetamin115H1->Get("graphTrigEfficiencyEMC17to175"));
  TGraphErrors *	graphTrigEfficiencyEMC175to18H1        = ((TGraphErrors*) TauThetamin115H1->Get("graphTrigEfficiencyEMC175to18"));
  TGraphErrors *	graphTrigEfficiencyEMC18to185H1        = ((TGraphErrors*) TauThetamin115H1->Get("graphTrigEfficiencyEMC18to185"));
  TMultiGraph * mgRatioExposureH1         = ((TMultiGraph*) TauThetamin115H1->Get("mgRatioExposure"));
  TMultiGraph * mggraphTrigEfficiencyH1         = ((TMultiGraph*) TauThetamin115H1->Get("mggraphTrigEfficiency"));

  TauThetamin115H2->cd();
  TGraphErrors *GraphExposureAllEH2        = ((TGraphErrors*) TauThetamin115H2->Get("GraphExposureAllEH0"));
  TGraphErrors *graphExposureCO1yearH2        = ((TGraphErrors*) TauThetamin115H2->Get("graphExposureCO1year"));
  TGraphErrors *graphExposureHEAT1yearH2        = ((TGraphErrors*) TauThetamin115H2->Get("graphExposureHEAT1year"));
  TGraphErrors *	graphTrigEfficiencyEMC17to175H2        = ((TGraphErrors*) TauThetamin115H2->Get("graphTrigEfficiencyEMC17to175"));
  TGraphErrors *	graphTrigEfficiencyEMC175to18H2        = ((TGraphErrors*) TauThetamin115H2->Get("graphTrigEfficiencyEMC175to18"));
  TGraphErrors *	graphTrigEfficiencyEMC18to185H2        = ((TGraphErrors*) TauThetamin115H2->Get("graphTrigEfficiencyEMC18to185"));
  TMultiGraph * mgRatioExposureH2         = ((TMultiGraph*) TauThetamin115H2->Get("mgRatioExposure"));
  TMultiGraph * mggraphTrigEfficiencyH2         = ((TMultiGraph*) TauThetamin115H2->Get("mggraphTrigEfficiency"));


  TauThetamin115H3->cd();
    TGraphErrors *GraphExposureAllEH3        = ((TGraphErrors*) TauThetamin115H3->Get("GraphExposureAllEH0"));
    TGraphErrors *graphExposureCO1yearH3        = ((TGraphErrors*) TauThetamin115H3->Get("graphExposureCO1year"));
    TGraphErrors *graphExposureHEAT1yearH3        = ((TGraphErrors*) TauThetamin115H3->Get("graphExposureHEAT1year"));
    TGraphErrors *	graphTrigEfficiencyEMC17to175H3        = ((TGraphErrors*) TauThetamin115H3->Get("graphTrigEfficiencyEMC17to175"));
    TGraphErrors *	graphTrigEfficiencyEMC175to18H3        = ((TGraphErrors*) TauThetamin115H3->Get("graphTrigEfficiencyEMC175to18"));
    TGraphErrors *	graphTrigEfficiencyEMC18to185H3        = ((TGraphErrors*) TauThetamin115H3->Get("graphTrigEfficiencyEMC18to185"));
    TMultiGraph * mgRatioExposureH3         = ((TMultiGraph*) TauThetamin115H3->Get("mgRatioExposure"));
    TMultiGraph * mggraphTrigEfficiencyH3         = ((TMultiGraph*) TauThetamin115H3->Get("mggraphTrigEfficiency"));

    TauThetamin115H4->cd();
      TGraphErrors *GraphExposureAllEH4        = ((TGraphErrors*) TauThetamin115H4->Get("GraphExposureAllEH0"));
      TGraphErrors *graphExposureCO1yearH4        = ((TGraphErrors*) TauThetamin115H4->Get("graphExposureCO1year"));
      TGraphErrors *graphExposureHEAT1yearH4        = ((TGraphErrors*) TauThetamin115H4->Get("graphExposureHEAT1year"));
      TGraphErrors *	graphTrigEfficiencyEMC17to175H4        = ((TGraphErrors*) TauThetamin115H4->Get("graphTrigEfficiencyEMC17to175"));
      TGraphErrors *	graphTrigEfficiencyEMC175to18H4        = ((TGraphErrors*) TauThetamin115H4->Get("graphTrigEfficiencyEMC175to18"));
      TGraphErrors *	graphTrigEfficiencyEMC18to185H4        = ((TGraphErrors*) TauThetamin115H4->Get("graphTrigEfficiencyEMC18to185"));
      TMultiGraph * mgRatioExposureH4         = ((TMultiGraph*) TauThetamin115H4->Get("mgRatioExposure"));
      TMultiGraph * mggraphTrigEfficiencyH4         = ((TMultiGraph*) TauThetamin115H4->Get("mggraphTrigEfficiency"));


  TCanvas *CanvasExposureCO1year = new TCanvas("CanvasExposureCO1year","CanvasExposureCO1year",200,10,700,400);
  TCanvas *CanvasExposureHEAT1year = new TCanvas("CanvasExposureHEAT1year","CanvasExposureHEAT1year",200,10,700,400);
  TCanvas *CanvasExposureFD = new TCanvas("CanvasExposureFD","CanvasExposureFD",700,530);
  TCanvas *CanvasH0HeatExposure1year = new TCanvas("CanvasExposureHEAT1yearH0","CanvasExposureHEAT1yearH0",200,10,700,400);
  TCanvas *CanvasTriggEfficiency = new TCanvas("CanvasTriggEfficiency", "CanvasTriggEfficiency", 200, 10, 700, 400);
  TCanvas *CanvasExposureFDZoomIn = new TCanvas("CanvasExposureFDZoomIn", "CanvasExposureFDZoomIn", 200, 10, 700, 400);

  CanvasTriggEfficiency->cd();

 graphTrigEfficiencyEMC17to175H0->SetMarkerStyle(20);
  graphTrigEfficiencyEMC17to175H0 ->SetMarkerSize(0.7);
  graphTrigEfficiencyEMC17to175H0 ->SetMarkerColor(kBlack);
  graphTrigEfficiencyEMC17to175H0  ->SetLineColor(kBlack);
  graphTrigEfficiencyEMC17to175H0->SetFillColorAlpha(kGray+2, .5);

    graphTrigEfficiencyEMC175to18H0->SetMarkerStyle(20);
    graphTrigEfficiencyEMC175to18H0 ->SetMarkerSize(0.7);
    graphTrigEfficiencyEMC175to18H0 ->SetMarkerColor(kBlue);
    graphTrigEfficiencyEMC175to18H0  ->SetLineColor(kBlue);
    graphTrigEfficiencyEMC175to18H0->SetFillColorAlpha(kAzure+2, .5);

    graphTrigEfficiencyEMC18to185H0->SetMarkerStyle(20);
    graphTrigEfficiencyEMC18to185H0 ->SetMarkerSize(0.7);
    graphTrigEfficiencyEMC18to185H0 ->SetMarkerColor(kRed);
    graphTrigEfficiencyEMC18to185H0  ->SetLineColor(kRed);
    graphTrigEfficiencyEMC18to185H0->SetFillColorAlpha(kRed-6, .5);

    TMultiGraph *mgTriggerEfficiency = new TMultiGraph();
    mgTriggerEfficiency-> Add(graphTrigEfficiencyEMC17to175H0);
    mgTriggerEfficiency-> Add(graphTrigEfficiencyEMC175to18H0);
    mgTriggerEfficiency-> Add(graphTrigEfficiencyEMC18to185H0);
    mgTriggerEfficiency->SetTitle("Triggering Efficiency, H_{decay} = 0 km, #theta #in [115 - 130#circ]; Distance_{FD} [km]; Triggered Ev / Generated Ev");
    mgTriggerEfficiency->Draw("aple3");

    legtrig = new TLegend(.65,0.15,.90,0.30); //size of legend

    legtrig->AddEntry(graphTrigEfficiencyEMC18to185H0,"#font[132]{lg E #in (18 - 18.5] eV}","lp");
    legtrig->AddEntry(graphTrigEfficiencyEMC175to18H0,"#font[132]{lg E #in (17.5 - 18] eV}","lp");
    legtrig->AddEntry(graphTrigEfficiencyEMC17to175H0,"#font[132]{lg E #in [17 - 17.5] eV}","lp"); //top right


    legtrig->Draw();

//  graphTrigEfficiencyEMC17to175H1->SetMarkerStyle(20);
//  graphTrigEfficiencyEMC17to175H1 ->SetMarkerSize(0.7);
//  graphTrigEfficiencyEMC17to175H1 ->SetMarkerColor(kBlack);
//  graphTrigEfficiencyEMC17to175H1  ->SetLineColor(kBlack);
//  graphTrigEfficiencyEMC17to175H1->SetFillColorAlpha(kGray+2, .5);
//
//    graphTrigEfficiencyEMC175to18H1->SetMarkerStyle(20);
//    graphTrigEfficiencyEMC175to18H1 ->SetMarkerSize(0.7);
//    graphTrigEfficiencyEMC175to18H1 ->SetMarkerColor(kBlue);
//    graphTrigEfficiencyEMC175to18H1  ->SetLineColor(kBlue);
//    graphTrigEfficiencyEMC175to18H1->SetFillColorAlpha(kAzure+2, .5);
//
//    graphTrigEfficiencyEMC18to185H1->SetMarkerStyle(20);
//    graphTrigEfficiencyEMC18to185H1 ->SetMarkerSize(0.7);
//    graphTrigEfficiencyEMC18to185H1 ->SetMarkerColor(kRed);
//    graphTrigEfficiencyEMC18to185H1  ->SetLineColor(kRed);
//    graphTrigEfficiencyEMC18to185H1->SetFillColorAlpha(kRed-6, .5);
//
//    TMultiGraph *mgTriggerEfficiency = new TMultiGraph();
//    mgTriggerEfficiency-> Add(graphTrigEfficiencyEMC17to175H1);
//    mgTriggerEfficiency-> Add(graphTrigEfficiencyEMC175to18H1);
//    mgTriggerEfficiency-> Add(graphTrigEfficiencyEMC18to185H1);
//    mgTriggerEfficiency->SetTitle("Triggering Efficiency, H_{decay} = 1 km, #theta #in [115 - 130#circ]; Distance_{FD} [km]; Triggered Ev / Generated Ev");
//    mgTriggerEfficiency->Draw("aple3");
//
//    legtrig = new TLegend(.65,0.15,.90,0.30); //size of legend
//
//    legtrig->AddEntry(graphTrigEfficiencyEMC18to185H1,"#font[132]{lg E #in (18 - 18.5] eV}","lp");
//    legtrig->AddEntry(graphTrigEfficiencyEMC175to18H1,"#font[132]{lg E #in (17.5 - 18] eV}","lp");
//    legtrig->AddEntry(graphTrigEfficiencyEMC17to175H1,"#font[132]{lg E #in [17 - 17.5] eV}","lp"); //top right
//
//
//    legtrig->Draw();

//  graphTrigEfficiencyEMC17to175H2->SetMarkerStyle(20);
//  graphTrigEfficiencyEMC17to175H2 ->SetMarkerSize(0.7);
//  graphTrigEfficiencyEMC17to175H2 ->SetMarkerColor(kBlack);
//  graphTrigEfficiencyEMC17to175H2  ->SetLineColor(kBlack);
//  graphTrigEfficiencyEMC17to175H2->SetFillColorAlpha(kGray+2, .5);
//
//    graphTrigEfficiencyEMC175to18H2->SetMarkerStyle(20);
//    graphTrigEfficiencyEMC175to18H2 ->SetMarkerSize(0.7);
//    graphTrigEfficiencyEMC175to18H2 ->SetMarkerColor(kBlue);
//    graphTrigEfficiencyEMC175to18H2  ->SetLineColor(kBlue);
//    graphTrigEfficiencyEMC175to18H2->SetFillColorAlpha(kAzure+2, .5);
//
//    graphTrigEfficiencyEMC18to185H2->SetMarkerStyle(20);
//    graphTrigEfficiencyEMC18to185H2 ->SetMarkerSize(0.7);
//    graphTrigEfficiencyEMC18to185H2 ->SetMarkerColor(kRed);
//    graphTrigEfficiencyEMC18to185H2  ->SetLineColor(kRed);
//    graphTrigEfficiencyEMC18to185H2->SetFillColorAlpha(kRed-6, .5);
//
//    TMultiGraph *mgTriggerEfficiency = new TMultiGraph();
//    mgTriggerEfficiency-> Add(graphTrigEfficiencyEMC17to175H2);
//    mgTriggerEfficiency-> Add(graphTrigEfficiencyEMC175to18H2);
//    mgTriggerEfficiency-> Add(graphTrigEfficiencyEMC18to185H2);
//    mgTriggerEfficiency->SetTitle("Triggering Efficiency, H_{decay} = 2 km, #theta #in [115 - 130#circ]; Distance_{FD} [km]; Triggered Ev / Generated Ev");
//    mgTriggerEfficiency->Draw("aple3");
//
//    legtrig = new TLegend(.65,0.15,.90,0.30); //size of legend
//    legtrig->AddEntry(graphTrigEfficiencyEMC18to185H2,"#font[132]{lg E #in (18 - 18.5] eV}","lp");
//    legtrig->AddEntry(graphTrigEfficiencyEMC175to18H2,"#font[132]{lg E #in (17.5 - 18] eV}","lp");
//    legtrig->AddEntry(graphTrigEfficiencyEMC17to175H2,"#font[132]{lg E #in [17 - 17.5] eV}","lp"); //top right
//
//
//    legtrig->Draw();

//
//  graphTrigEfficiencyEMC17to175H3->SetMarkerStyle(20);
//  graphTrigEfficiencyEMC17to175H3 ->SetMarkerSize(0.7);
//  graphTrigEfficiencyEMC17to175H3 ->SetMarkerColor(kBlack);
//  graphTrigEfficiencyEMC17to175H3  ->SetLineColor(kBlack);
//  graphTrigEfficiencyEMC17to175H3->SetFillColorAlpha(kGray+2, .5);
//
//    graphTrigEfficiencyEMC175to18H3->SetMarkerStyle(20);
//    graphTrigEfficiencyEMC175to18H3 ->SetMarkerSize(0.7);
//    graphTrigEfficiencyEMC175to18H3 ->SetMarkerColor(kBlue);
//    graphTrigEfficiencyEMC175to18H3  ->SetLineColor(kBlue);
//    graphTrigEfficiencyEMC175to18H3->SetFillColorAlpha(kAzure+2, .5);
//
//    graphTrigEfficiencyEMC18to185H3->SetMarkerStyle(20);
//    graphTrigEfficiencyEMC18to185H3 ->SetMarkerSize(0.7);
//    graphTrigEfficiencyEMC18to185H3 ->SetMarkerColor(kRed);
//    graphTrigEfficiencyEMC18to185H3  ->SetLineColor(kRed);
//    graphTrigEfficiencyEMC18to185H3->SetFillColorAlpha(kRed-6, .5);
//
//    TMultiGraph *mgTriggerEfficiency = new TMultiGraph();
//    mgTriggerEfficiency-> Add(graphTrigEfficiencyEMC17to175H3);
//    mgTriggerEfficiency-> Add(graphTrigEfficiencyEMC175to18H3);
//    mgTriggerEfficiency-> Add(graphTrigEfficiencyEMC18to185H3);
//    mgTriggerEfficiency->SetTitle("Triggering Efficiency, H_{decay} = 3 km, #theta #in [115 - 130#circ]; Distance_{FD} [km]; Triggered Ev / Generated Ev");
//    mgTriggerEfficiency->Draw("aple3");
//
//    legtrig = new TLegend(.65,0.15,.90,0.30); //size of legend
//
//    legtrig->AddEntry(graphTrigEfficiencyEMC18to185H3,"#font[132]{lg E #in (18 - 18.5] eV}","lp");
//    legtrig->AddEntry(graphTrigEfficiencyEMC175to18H3,"#font[132]{lg E #in (17.5 - 18] eV}","lp");
//    legtrig->AddEntry(graphTrigEfficiencyEMC17to175H3,"#font[132]{lg E #in [17 - 17.5] eV}","lp"); //top right
//
//
//    legtrig->Draw();


//  graphTrigEfficiencyEMC17to175H4->SetMarkerStyle(20);
//  graphTrigEfficiencyEMC17to175H4 ->SetMarkerSize(0.7);
//  graphTrigEfficiencyEMC17to175H4 ->SetMarkerColor(kBlack);
//  graphTrigEfficiencyEMC17to175H4  ->SetLineColor(kBlack);
//  graphTrigEfficiencyEMC17to175H4->SetFillColorAlpha(kGray+2, .5);
//
//    graphTrigEfficiencyEMC175to18H4->SetMarkerStyle(20);
//    graphTrigEfficiencyEMC175to18H4 ->SetMarkerSize(0.7);
//    graphTrigEfficiencyEMC175to18H4 ->SetMarkerColor(kBlue);
//    graphTrigEfficiencyEMC175to18H4  ->SetLineColor(kBlue);
//    graphTrigEfficiencyEMC175to18H4->SetFillColorAlpha(kAzure+2, .5);
//
//    graphTrigEfficiencyEMC18to185H4->SetMarkerStyle(20);
//    graphTrigEfficiencyEMC18to185H4 ->SetMarkerSize(0.7);
//    graphTrigEfficiencyEMC18to185H4 ->SetMarkerColor(kRed);
//    graphTrigEfficiencyEMC18to185H4  ->SetLineColor(kRed);
//    graphTrigEfficiencyEMC18to185H4->SetFillColorAlpha(kRed-6, .5);
//
//    TMultiGraph *mgTriggerEfficiency = new TMultiGraph();
//    mgTriggerEfficiency-> Add(graphTrigEfficiencyEMC17to175H4);
//    mgTriggerEfficiency-> Add(graphTrigEfficiencyEMC175to18H4);
//    mgTriggerEfficiency-> Add(graphTrigEfficiencyEMC18to185H4);
//    mgTriggerEfficiency->SetTitle("Triggering Efficiency, H_{decay} = 4 km, #theta #in [115 - 130#circ]; Distance_{FD} [km]; Triggered Ev / Generated Ev");
//    mgTriggerEfficiency->Draw("aple3");
//
//    legtrig = new TLegend(.65,0.15,.90,0.30); //size of legend
//
//    legtrig->AddEntry(graphTrigEfficiencyEMC18to185H4,"#font[132]{lg E #in (18 - 18.5] eV}","lp");
//    legtrig->AddEntry(graphTrigEfficiencyEMC175to18H4,"#font[132]{lg E #in (17.5 - 18] eV}","lp");
//    legtrig->AddEntry(graphTrigEfficiencyEMC17to175H4,"#font[132]{lg E #in [17 - 17.5] eV}","lp"); //top right
//
//
//    legtrig->Draw();

    //zoom in into the exposure graph for E in (17 - 17.8)

    vector<double> EnergyZoomedH0;
    vector<double> ErrEnergyZoomedH0;
    vector<double> ExposureZoomedH0;
    vector<double> ErrExposureZoomedH0;

    for(int var=0; var<GraphExposureAllEH0->GetN(); var++)
      {if(GraphExposureAllEH0->GetX()[var]<=17.8)
        { EnergyZoomedH0.push_back(GraphExposureAllEH0->GetX()[var]);
          ErrEnergyZoomedH0.push_back(GraphExposureAllEH0->GetErrorX(var));
          ExposureZoomedH0.push_back(GraphExposureAllEH0->GetY()[var]*3.5);
          ErrExposureZoomedH0.push_back(GraphExposureAllEH0->GetErrorY(var)*3.5);
        }
      }

    vector<double> EnergyZoomedH1;
    vector<double> ErrEnergyZoomedH1;
    vector<double> ExposureZoomedH1;
    vector<double> ErrExposureZoomedH1;

    for(int var=0; var<GraphExposureAllEH1->GetN(); var++)
      {if(GraphExposureAllEH1->GetX()[var]<=17.8)
        { EnergyZoomedH1.push_back(GraphExposureAllEH1->GetX()[var]);
          ErrEnergyZoomedH1.push_back(GraphExposureAllEH1->GetErrorX(var));
          ExposureZoomedH1.push_back(GraphExposureAllEH1->GetY()[var]*3.5);
          ErrExposureZoomedH1.push_back(GraphExposureAllEH1->GetErrorY(var)*3.5);
        }
      }

    vector<double> EnergyZoomedH2;
    vector<double> ErrEnergyZoomedH2;
    vector<double> ExposureZoomedH2;
    vector<double> ErrExposureZoomedH2;

    for(int var=0; var<GraphExposureAllEH2->GetN(); var++)
      {if(GraphExposureAllEH2->GetX()[var]<=17.8)
        { EnergyZoomedH2.push_back(GraphExposureAllEH2->GetX()[var]);
          ErrEnergyZoomedH2.push_back(GraphExposureAllEH2->GetErrorX(var));
          ExposureZoomedH2.push_back(GraphExposureAllEH2->GetY()[var]*3.5);
          ErrExposureZoomedH2.push_back(GraphExposureAllEH2->GetErrorY(var)*3.5);
        }
      }

    vector<double> EnergyZoomedH3;
    vector<double> ErrEnergyZoomedH3;
    vector<double> ExposureZoomedH3;
    vector<double> ErrExposureZoomedH3;

    for(int var=0; var<GraphExposureAllEH3->GetN(); var++)
      {if(GraphExposureAllEH3->GetX()[var]<=17.8)
        { EnergyZoomedH3.push_back(GraphExposureAllEH3->GetX()[var]);
          ErrEnergyZoomedH3.push_back(GraphExposureAllEH3->GetErrorX(var));
          ExposureZoomedH3.push_back(GraphExposureAllEH3->GetY()[var]*3.5);
          ErrExposureZoomedH3.push_back(GraphExposureAllEH3->GetErrorY(var)*3.5);
        }
      }

    vector<double> EnergyZoomedH4;
    vector<double> ErrEnergyZoomedH4;
    vector<double> ExposureZoomedH4;
    vector<double> ErrExposureZoomedH4;

    for(int var=0; var<GraphExposureAllEH4->GetN(); var++)
      {if(GraphExposureAllEH4->GetX()[var]<=17.8)
        { EnergyZoomedH4.push_back(GraphExposureAllEH4->GetX()[var]);
          ErrEnergyZoomedH4.push_back(GraphExposureAllEH4->GetErrorX(var));
          ExposureZoomedH4.push_back(GraphExposureAllEH4->GetY()[var]*3.5);
          ErrExposureZoomedH4.push_back(GraphExposureAllEH4->GetErrorY(var)*3.5);
        }
      }

      for(int itest=0; itest<EnergyZoomedH0.size(); itest++)
        if(EnergyZoomedH0[itest]==17.8)
        cout<<"h=0 "<<ExposureZoomedH0[itest]<<" h=1 "<<ExposureZoomedH1[itest]<<" h=2 "<<ExposureZoomedH2[itest]<<" h=3 "
            <<ExposureZoomedH3[itest]<<" h=4 "<<ExposureZoomedH4[itest]<<endl;
            
  CanvasExposureFDZoomIn->cd();
  TGraphErrors * graphExposureZoomH0 = new TGraphErrors (EnergyZoomedH0.size(), &EnergyZoomedH0[0], &ExposureZoomedH0[0],
                                &ErrEnergyZoomedH0[0], &ErrExposureZoomedH0[0]);
  TGraphErrors * graphExposureZoomH1 = new TGraphErrors (EnergyZoomedH1.size(), &EnergyZoomedH1[0], &ExposureZoomedH1[0],
                                &ErrEnergyZoomedH1[0], &ErrExposureZoomedH1[0]);
  TGraphErrors * graphExposureZoomH2 = new TGraphErrors (EnergyZoomedH2.size(), &EnergyZoomedH2[0], &ExposureZoomedH2[0],
                                &ErrEnergyZoomedH2[0], &ErrExposureZoomedH2[0]);
  TGraphErrors * graphExposureZoomH3 = new TGraphErrors (EnergyZoomedH3.size(), &EnergyZoomedH3[0], &ExposureZoomedH3[0],
                                &ErrEnergyZoomedH3[0], &ErrExposureZoomedH3[0]);
  TGraphErrors * graphExposureZoomH4 = new TGraphErrors (EnergyZoomedH4.size(), &EnergyZoomedH4[0], &ExposureZoomedH4[0],
                                &ErrEnergyZoomedH4[0], &ErrExposureZoomedH4[0]);


   graphExposureZoomH0->SetTitle("Exposure FD Zoom in, #theta #in [115 - 130#circ]");
   graphExposureZoomH0->GetXaxis()->SetTitle("lg E_{MC} / eV");
   graphExposureZoomH0->GetXaxis()->CenterTitle();
   graphExposureZoomH0->GetYaxis()->SetTitleOffset(1.2);
   graphExposureZoomH0->GetYaxis()->SetTitle("Exposure [km^{2} sr yr]");
   graphExposureZoomH0->GetYaxis()->CenterTitle();
   graphExposureZoomH0->SetMarkerStyle(20);
   graphExposureZoomH0->SetMarkerSize(0.7);
   graphExposureZoomH0->SetMarkerColor(kBlack);
   graphExposureZoomH0 ->SetFillColorAlpha(kGray+2, .5);

   graphExposureZoomH1->SetTitle("Exposure FD Zoom in, #theta #in [115 - 130#circ]");
   graphExposureZoomH1->GetXaxis()->SetTitle("lg E_{MC} / eV");
   graphExposureZoomH1->GetXaxis()->CenterTitle();
   graphExposureZoomH1->GetYaxis()->SetTitleOffset(1.2);
   graphExposureZoomH1->GetYaxis()->SetTitle("Exposure [km^{2} sr yr]");
   graphExposureZoomH1->GetYaxis()->CenterTitle();
   graphExposureZoomH1->SetMarkerStyle(21);
   graphExposureZoomH1->SetMarkerSize(0.7);
   graphExposureZoomH1->SetMarkerColor(kBlue);
   graphExposureZoomH1->SetLineColor(kBlue);
   graphExposureZoomH1 ->SetFillColorAlpha(kAzure+2, .5);

   graphExposureZoomH2->SetTitle("Exposure FD Zoom in, #theta #in [115 - 130#circ]");
   graphExposureZoomH2->GetXaxis()->SetTitle("lg E_{MC} / eV");
   graphExposureZoomH2->GetXaxis()->CenterTitle();
   graphExposureZoomH2->GetYaxis()->SetTitleOffset(1.2);
   graphExposureZoomH2->GetYaxis()->SetTitle("Exposure [km^{2} sr yr]");
   graphExposureZoomH2->GetYaxis()->CenterTitle();
   graphExposureZoomH2->SetMarkerStyle(23);
   graphExposureZoomH2->SetMarkerSize(0.7);
   graphExposureZoomH2->SetMarkerColor(kMagenta);
   graphExposureZoomH2->SetLineColor(kMagenta);
   graphExposureZoomH2 ->SetFillColorAlpha(kMagenta-9, .5);


    graphExposureZoomH3->SetTitle("Exposure FD Zoom in, #theta #in [115 - 130#circ]");
    graphExposureZoomH3->GetXaxis()->SetTitle("lg E_{MC} / eV");
    graphExposureZoomH3->GetXaxis()->CenterTitle();
    graphExposureZoomH3->GetYaxis()->SetTitleOffset(1.2);
    graphExposureZoomH3->GetYaxis()->SetTitle("Exposure [km^{2} sr yr]");
    graphExposureZoomH3->GetYaxis()->CenterTitle();
    graphExposureZoomH3->SetMarkerStyle(23);
    graphExposureZoomH3->SetMarkerSize(0.7);
    graphExposureZoomH3->SetMarkerColor(kOrange+4);
    graphExposureZoomH3->SetLineColor(kOrange+4);
    graphExposureZoomH3 ->SetFillColorAlpha(kOrange-7, .5);

    graphExposureZoomH4->SetTitle("Exposure FD Zoom in, #theta #in [115 - 130#circ]");
    graphExposureZoomH4->GetXaxis()->SetTitle("lg E_{MC} / eV");
    graphExposureZoomH4->GetXaxis()->CenterTitle();
    graphExposureZoomH4->GetYaxis()->SetTitleOffset(1.2);
    graphExposureZoomH4->GetYaxis()->SetTitle("Exposure [km^{2} sr yr]");
    graphExposureZoomH4->GetYaxis()->CenterTitle();
    graphExposureZoomH4->SetMarkerStyle(23);
    graphExposureZoomH4->SetMarkerSize(0.7);
    graphExposureZoomH4->SetMarkerColor(kGreen+4);
    graphExposureZoomH4->SetLineColor(kGreen+4);
    graphExposureZoomH4 ->SetFillColorAlpha(kGreen-7, .5);

   TMultiGraph *mgExposureFDZoom = new TMultiGraph();
     mgExposureFDZoom->Add(graphExposureZoomH0 );
     mgExposureFDZoom->Add(graphExposureZoomH1);
     mgExposureFDZoom->Add(graphExposureZoomH2 );
     mgExposureFDZoom->Add(graphExposureZoomH3 );
     mgExposureFDZoom->Add(graphExposureZoomH4 );
     mgExposureFDZoom->Draw("aple3");
     mgExposureFDZoom->SetTitle("Exposure FD, #theta #in [115 - 130#circ] ;  lg E (eV) ; Exposure [km^{2} sr yr]");


   legZoom = new TLegend(.65,0.15,.90,0.30); //size of legend
   legZoom->AddEntry(graphExposureZoomH0,"#font[132]{H_{decay} = 0 km}","lp"); //top left
     legZoom->AddEntry(graphExposureZoomH1,"#font[132]{H_{decay} = 1 km}","lp"); //top right
     legZoom->AddEntry(graphExposureZoomH2,"#font[132]{H_{decay} = 2 km}","lp");
     legZoom->AddEntry(graphExposureZoomH3,"#font[132]{H_{decay} = 3 km}","lp");
     legZoom->AddEntry(graphExposureZoomH4,"#font[132]{H_{decay} = 4 km}","lp");
   legZoom->Draw();



  CanvasExposureCO1year->cd();


  graphExposureCO1yearH0->SetTitle("Exposure Coihueco for 1 year, #theta #in [115 - 130#circ]");
  graphExposureCO1yearH0->GetXaxis()->SetTitle("lg E_{MC} / eV");
  graphExposureCO1yearH0->GetXaxis()->CenterTitle();
  graphExposureCO1yearH0->GetYaxis()->SetTitleOffset(1.2);
  graphExposureCO1yearH0->GetYaxis()->SetTitle("Exposure [km^{2} sr yr]");
  graphExposureCO1yearH0->GetYaxis()->CenterTitle();
  graphExposureCO1yearH0->SetMarkerStyle(20);
  graphExposureCO1yearH0->SetMarkerSize(0.7);
  graphExposureCO1yearH0->SetMarkerColor(kBlack);
  graphExposureCO1yearH0 ->SetFillColorAlpha(kGray+2, .5);



  graphExposureCO1yearH1->SetTitle("Exposure Coihueco for 1 year, #theta #in [115 - 130#circ]");
  graphExposureCO1yearH1->GetXaxis()->SetTitle("lg E_{MC} / eV");
  graphExposureCO1yearH1->GetXaxis()->CenterTitle();
  graphExposureCO1yearH1->GetYaxis()->SetTitleOffset(1.2);
  graphExposureCO1yearH1->GetYaxis()->SetTitle("Exposure [km^{2} sr yr]");
  graphExposureCO1yearH1->GetYaxis()->CenterTitle();
  graphExposureCO1yearH1->SetMarkerStyle(21);
  graphExposureCO1yearH1->SetMarkerSize(0.7);
  graphExposureCO1yearH1->SetMarkerColor(kBlue);
  graphExposureCO1yearH1->SetLineColor(kBlue);
  graphExposureCO1yearH1 ->SetFillColorAlpha(kAzure+2, .5);



  graphExposureCO1yearH2->SetTitle("Exposure Coihueco for 1 year, #theta #in [115 - 130#circ]");
  graphExposureCO1yearH2->GetXaxis()->SetTitle("lg E_{MC} / eV");
  graphExposureCO1yearH2->GetXaxis()->CenterTitle();
  graphExposureCO1yearH2->GetYaxis()->SetTitleOffset(1.2);
  graphExposureCO1yearH2->GetYaxis()->SetTitle("Exposure [km^{2} sr yr]");
  graphExposureCO1yearH2->GetYaxis()->CenterTitle();
  graphExposureCO1yearH2->SetMarkerStyle(23);
  graphExposureCO1yearH2->SetMarkerSize(0.7);
  graphExposureCO1yearH2->SetMarkerColor(kMagenta);
  graphExposureCO1yearH2->SetLineColor(kMagenta);
  graphExposureCO1yearH2 ->SetFillColorAlpha(kMagenta-9, .5);



  graphExposureCO1yearH3->SetTitle("Exposure Coihueco for 1 year, #theta #in [115 - 130#circ]");
  graphExposureCO1yearH3->GetXaxis()->SetTitle("lg E_{MC} / eV");
  graphExposureCO1yearH3->GetXaxis()->CenterTitle();
  graphExposureCO1yearH3->GetYaxis()->SetTitleOffset(1.2);
  graphExposureCO1yearH3->GetYaxis()->SetTitle("Exposure [km^{2} sr yr]");
  graphExposureCO1yearH3->GetYaxis()->CenterTitle();
  graphExposureCO1yearH3->SetMarkerStyle(23);
  graphExposureCO1yearH3->SetMarkerSize(0.7);
  graphExposureCO1yearH3->SetMarkerColor(kOrange+4);
  graphExposureCO1yearH3->SetLineColor(kOrange+4);
  graphExposureCO1yearH3 ->SetFillColorAlpha(kOrange-7, .5);


  graphExposureCO1yearH4->SetTitle("Exposure Coihueco for 1 year, #theta #in [115 - 130#circ]");
  graphExposureCO1yearH4->GetXaxis()->SetTitle("lg E_{MC} / eV");
  graphExposureCO1yearH4->GetXaxis()->CenterTitle();
  graphExposureCO1yearH4->GetYaxis()->SetTitleOffset(1.2);
  graphExposureCO1yearH4->GetYaxis()->SetTitle("Exposure [km^{2} sr yr]");
  graphExposureCO1yearH4->GetYaxis()->CenterTitle();
  graphExposureCO1yearH4->SetMarkerStyle(23);
  graphExposureCO1yearH4->SetMarkerSize(0.7);
  graphExposureCO1yearH4->SetMarkerColor(kGreen+4);
  graphExposureCO1yearH4->SetLineColor(kGreen+4);
  graphExposureCO1yearH4 ->SetFillColorAlpha(kGreen-7, .5);



  TMultiGraph *mgExposureCO1year = new TMultiGraph();
  mgExposureCO1year->Add(graphExposureCO1yearH0 );
  mgExposureCO1year->Add(graphExposureCO1yearH1 );
  mgExposureCO1year->Add(graphExposureCO1yearH2 );
  mgExposureCO1year->Add(graphExposureCO1yearH3 );
  mgExposureCO1year->Add(graphExposureCO1yearH4 );
  mgExposureCO1year->Draw("aple3");
  mgExposureCO1year->SetTitle("Exposure Coihueco for 1 year, #theta #in [115 - 130#circ] ;  lg E (eV) ; Exposure [km^{2} sr yr]");

  leg = new TLegend(.65,0.15,.90,0.30); //size of legend
  leg->AddEntry(graphExposureCO1yearH0,"#font[132]{H_{decay} = 0 km}","lp"); //top left
    leg->AddEntry(graphExposureCO1yearH1,"#font[132]{H_{decay} = 1 km}","lp"); //top right
    leg->AddEntry(graphExposureCO1yearH2,"#font[132]{H_{decay} = 2 km}","lp");
    leg->AddEntry(graphExposureCO1yearH3,"#font[132]{H_{decay} = 3 km}","lp");
    leg->AddEntry(graphExposureCO1yearH4,"#font[132]{H_{decay} = 4 km}","lp");
  leg->Draw();

 //CanvasExposureCO1year->Print("ExposureCO1yearDiffHeightsE17_18.5_Theta115_130.pdf");


  CanvasExposureHEAT1year->cd();
  graphExposureHEAT1yearH0->SetTitle("Exposure HEAT for 1 year, #theta #in [115 - 130#circ]");
  graphExposureHEAT1yearH0->GetXaxis()->SetTitle("lg E_{MC} / eV");
  graphExposureHEAT1yearH0->GetXaxis()->CenterTitle();
  graphExposureHEAT1yearH0->GetYaxis()->SetTitleOffset(1.2);
  graphExposureHEAT1yearH0->GetYaxis()->SetTitle("Exposure [km^{2} sr yr]");
  graphExposureHEAT1yearH0->GetYaxis()->CenterTitle();
  graphExposureHEAT1yearH0->SetMarkerStyle(20);
  graphExposureHEAT1yearH0->SetMarkerSize(0.7);
  graphExposureHEAT1yearH0->SetMarkerColor(kBlack);
  graphExposureHEAT1yearH0->SetLineColor(kBlack);
  graphExposureHEAT1yearH0 ->SetFillColorAlpha(kGray+2, .5);

  graphExposureHEAT1yearH1->SetTitle("Exposure HEAT for 1 year, #theta #in [115 - 130#circ]");
  graphExposureHEAT1yearH1->GetXaxis()->SetTitle("lg E_{MC} / eV");
  graphExposureHEAT1yearH1->GetXaxis()->CenterTitle();
  graphExposureHEAT1yearH1->GetYaxis()->SetTitleOffset(1.2);
  graphExposureHEAT1yearH1->GetYaxis()->SetTitle("Exposure [km^{2} sr yr]");
  graphExposureHEAT1yearH1->GetYaxis()->CenterTitle();
  graphExposureHEAT1yearH1->SetMarkerStyle(21);
  graphExposureHEAT1yearH1->SetMarkerSize(0.7);
  graphExposureHEAT1yearH1->SetMarkerColor(kBlue);
  graphExposureHEAT1yearH1->SetLineColor(kBlue);
  graphExposureHEAT1yearH1 ->SetFillColorAlpha(kAzure+2, .5);

  graphExposureHEAT1yearH2->SetTitle("Exposure HEAT for 1 year, #theta #in [115 - 130#circ]");
  graphExposureHEAT1yearH2->GetXaxis()->SetTitle("lg E_{MC} / eV");
  graphExposureHEAT1yearH2->GetXaxis()->CenterTitle();
  graphExposureHEAT1yearH2->GetYaxis()->SetTitleOffset(1.2);
  graphExposureHEAT1yearH2->GetYaxis()->SetTitle("Exposure [km^{2} sr yr]");
  graphExposureHEAT1yearH2->GetYaxis()->CenterTitle();
  graphExposureHEAT1yearH2->SetMarkerStyle(23);
  graphExposureHEAT1yearH2->SetMarkerSize(0.7);
  graphExposureHEAT1yearH2->SetMarkerColor(kMagenta);
  graphExposureHEAT1yearH2->SetLineColor(kMagenta);
  graphExposureHEAT1yearH2 ->SetFillColorAlpha(kMagenta-9, .5);

  graphExposureHEAT1yearH3->SetTitle("Exposure HEAT for 1 year, #theta #in [115 - 130#circ]");
  graphExposureHEAT1yearH3->GetXaxis()->SetTitle("lg E_{MC} / eV");
  graphExposureHEAT1yearH3->GetXaxis()->CenterTitle();
  graphExposureHEAT1yearH3->GetYaxis()->SetTitleOffset(1.2);
  graphExposureHEAT1yearH3->GetYaxis()->SetTitle("Exposure [km^{2} sr yr]");
  graphExposureHEAT1yearH3->GetYaxis()->CenterTitle();
  graphExposureHEAT1yearH3->SetMarkerStyle(23);
  graphExposureHEAT1yearH3->SetMarkerSize(0.7);
  graphExposureHEAT1yearH3->SetMarkerColor(kOrange+4);
  graphExposureHEAT1yearH3->SetLineColor(kOrange+4);
  graphExposureHEAT1yearH3 ->SetFillColorAlpha(kOrange-7, .5);

  graphExposureHEAT1yearH4->SetTitle("Exposure HEAT for 1 year, #theta #in [115 - 130#circ]");
  graphExposureHEAT1yearH4->GetXaxis()->SetTitle("lg E_{MC} / eV");
  graphExposureHEAT1yearH4->GetXaxis()->CenterTitle();
  graphExposureHEAT1yearH4->GetYaxis()->SetTitleOffset(1.2);
  graphExposureHEAT1yearH4->GetYaxis()->SetTitle("Exposure [km^{2} sr yr]");
  graphExposureHEAT1yearH4->GetYaxis()->CenterTitle();
  graphExposureHEAT1yearH4->SetMarkerStyle(23);
  graphExposureHEAT1yearH4->SetMarkerSize(0.7);
  graphExposureHEAT1yearH4->SetMarkerColor(kGreen+4);
  graphExposureHEAT1yearH4->SetLineColor(kGreen+4);
  graphExposureHEAT1yearH4 ->SetFillColorAlpha(kGreen-7, .5);


  TMultiGraph *mgExposureHEAT1year = new TMultiGraph();
  mgExposureHEAT1year->Add(graphExposureHEAT1yearH0 );
  mgExposureHEAT1year->Add(graphExposureHEAT1yearH1 );
  mgExposureHEAT1year->Add(graphExposureHEAT1yearH2 );
  mgExposureHEAT1year->Add(graphExposureHEAT1yearH3 );
  mgExposureHEAT1year->Add(graphExposureHEAT1yearH4 );
  mgExposureHEAT1year->Draw("aple3");
  mgExposureHEAT1year->SetTitle("Exposure HEAT for 1 year, #theta #in [115 - 130#circ] ;  lg E (eV) ; Exposure [km^{2} sr yr]");

  leg2 = new TLegend(.65,0.15,.90,0.30); //size of legend
  leg2->AddEntry(graphExposureHEAT1yearH0,"#font[132]{H_{decay} = 0 km}","lp"); //top left
    leg2->AddEntry(graphExposureHEAT1yearH1,"#font[132]{H_{decay} = 1 km}","lp"); //top right
    leg2->AddEntry(graphExposureHEAT1yearH2,"#font[132]{H_{decay} = 2 km}","lp");
    leg2->AddEntry(graphExposureHEAT1yearH3,"#font[132]{H_{decay} = 3 km}","lp");
    leg2->AddEntry(graphExposureHEAT1yearH4,"#font[132]{H_{decay} = 4 km}","lp");
  leg2->Draw();

  //CanvasExposureHEAT1year->Print("ExposureHEAT1yearDiffHeightsE17_18.5_Theta115_130.pdf");
//=====get rid of points with exposure = 0========

  int nPointsGraphH2 = GraphExposureAllEH2->GetN();
  vector<double> ExposureH2vector;
  vector<double> EnergyH2Vector;
  vector<double> ErrorExposureH2Vector;
  vector<double> ErrorEnergyH2Vector;

  for(int i =0; i < nPointsGraphH2; i++){
    double Exposure;
    double Energy;
    GraphExposureAllEH2->GetPoint(i, Energy, Exposure);



    if(Exposure!=0){    
      ExposureH2vector.push_back(Exposure);
      EnergyH2Vector.push_back(Energy);
      ErrorExposureH2Vector.push_back(GraphExposureAllEH2->GetErrorY(i));
      ErrorEnergyH2Vector.push_back(0);
    }
  }

  int nH2PointsNoZeroVals = ExposureH2vector.size();

  TGraphErrors *GraphExposureAllEH2NoZeroVals = new TGraphErrors(nH2PointsNoZeroVals, &EnergyH2Vector[0], &ExposureH2vector[0], &ErrorEnergyH2Vector[0], &ErrorExposureH2Vector[0] );

  int nPointsGraphH3 = GraphExposureAllEH3->GetN();
  vector<double> ExposureH3vector;
  vector<double> EnergyH3Vector;
  vector<double> ErrorExposureH3Vector;
  vector<double> ErrorEnergyH3Vector;

  for(int i =0; i < nPointsGraphH3; i++){
    double Exposure;
    double Energy;
    GraphExposureAllEH3->GetPoint(i, Energy, Exposure);



    if(Exposure!=0){    
      ExposureH3vector.push_back(Exposure);
      EnergyH3Vector.push_back(Energy);
      ErrorExposureH3Vector.push_back(GraphExposureAllEH3->GetErrorY(i));
      ErrorEnergyH3Vector.push_back(0);
    }
  }

  int nH3PointsNoZeroVals = ExposureH3vector.size();

  TGraphErrors *GraphExposureAllEH3NoZeroVals = new TGraphErrors(nH3PointsNoZeroVals, &EnergyH3Vector[0], &ExposureH3vector[0], &ErrorEnergyH3Vector[0], &ErrorExposureH3Vector[0] );

  int nPointsGraphH4 = GraphExposureAllEH4->GetN();
  vector<double> ExposureH4vector;
  vector<double> EnergyH4Vector;
  vector<double> ErrorExposureH4Vector;
  vector<double> ErrorEnergyH4Vector;

  for(int i =0; i < nPointsGraphH4; i++){
    double Exposure;
    double Energy;
    GraphExposureAllEH4->GetPoint(i, Energy, Exposure);



    if(Exposure!=0){    
      ExposureH4vector.push_back(Exposure);
      EnergyH4Vector.push_back(Energy);
      ErrorExposureH4Vector.push_back(GraphExposureAllEH4->GetErrorY(i));
      ErrorEnergyH4Vector.push_back(0);
    }
  }

  int nH4PointsNoZeroVals = ExposureH4vector.size();

  TGraphErrors *GraphExposureAllEH4NoZeroVals = new TGraphErrors(nH4PointsNoZeroVals, &EnergyH4Vector[0], &ExposureH4vector[0], &ErrorEnergyH4Vector[0], &ErrorExposureH4Vector[0] );




  for(int i = 0; i<ExposureH4vector.size(); i++)
  cout<< " e = "<<EnergyH4Vector[i]<<" exposure: "<<ExposureH4vector[i]<<" error exposure" <<ErrorExposureH4Vector[i] <<endl;

  //==========DONE==========
  CanvasExposureFD->cd();
  CanvasExposureFD->SetBottomMargin(0.18);
  CanvasExposureFD->SetTopMargin(0.1);
  CanvasExposureFD->SetFrameLineWidth(2);
  CanvasExposureFD->SetLineWidth(2);
  //gStyle->SetTickLength(0.02,"z");
  CanvasExposureFD->SetLeftMargin(0.15);
  CanvasExposureFD->SetRightMargin(0.04);

  gPad->SetLogy();
  GraphExposureAllEH0->SetTitle("Exposure Coihueco for 1 year, #theta #in [115 - 130#circ]");
   GraphExposureAllEH0->GetXaxis()->SetTitle("lg E_{MC} / eV");
   GraphExposureAllEH0->GetXaxis()->CenterTitle();
   GraphExposureAllEH0->GetYaxis()->SetTitleOffset(1.2);
   GraphExposureAllEH0->GetYaxis()->SetTitle("Exposure [km^{2} sr yr]");
   GraphExposureAllEH0->GetYaxis()->CenterTitle();
   GraphExposureAllEH0->SetMarkerStyle(20);
   GraphExposureAllEH0->SetMarkerSize(1);
   GraphExposureAllEH0->SetMarkerColor(kBlack);
   GraphExposureAllEH0 ->SetFillColorAlpha(kGray+2, .5);

   GraphExposureAllEH1->SetTitle("Exposure Coihueco for 1 year, #theta #in [115 - 130#circ]");
   GraphExposureAllEH1->GetXaxis()->SetTitle("lg E_{MC} / eV");
   GraphExposureAllEH1->GetXaxis()->CenterTitle();
   GraphExposureAllEH1->GetYaxis()->SetTitleOffset(1.2);
   GraphExposureAllEH1->GetYaxis()->SetTitle("Exposure [km^{2} sr yr]");
   GraphExposureAllEH1->GetYaxis()->CenterTitle();
   GraphExposureAllEH1->SetMarkerStyle(21);
   GraphExposureAllEH1->SetMarkerSize(1);
   GraphExposureAllEH1->SetMarkerColor(kBlue);
   GraphExposureAllEH1->SetLineColor(kBlue);
   GraphExposureAllEH1 ->SetFillColorAlpha(kAzure+2, .5);

   GraphExposureAllEH2NoZeroVals->SetTitle("Exposure Coihueco for 1 year, #theta #in [115 - 130#circ]");
   GraphExposureAllEH2NoZeroVals->GetXaxis()->SetTitle("lg E_{MC} / eV");
   GraphExposureAllEH2NoZeroVals->GetXaxis()->CenterTitle();
   GraphExposureAllEH2NoZeroVals->GetYaxis()->SetTitleOffset(1.2);
   GraphExposureAllEH2NoZeroVals->GetYaxis()->SetTitle("Exposure [km^{2} sr yr]");
   GraphExposureAllEH2NoZeroVals->GetYaxis()->CenterTitle();
   GraphExposureAllEH2NoZeroVals->SetMarkerStyle(23);
   GraphExposureAllEH2NoZeroVals->SetMarkerSize(1);
   GraphExposureAllEH2NoZeroVals->SetMarkerColor(kMagenta);
   GraphExposureAllEH2NoZeroVals->SetLineColor(kMagenta);
   GraphExposureAllEH2NoZeroVals ->SetFillColorAlpha(kMagenta-9, .5);


    GraphExposureAllEH3NoZeroVals->SetTitle("Exposure Coihueco for 1 year, #theta #in [115 - 130#circ]");
    GraphExposureAllEH3NoZeroVals->GetXaxis()->SetTitle("lg E_{MC} / eV");
    GraphExposureAllEH3NoZeroVals->GetXaxis()->CenterTitle();
    GraphExposureAllEH3NoZeroVals->GetYaxis()->SetTitleOffset(1.2);
    GraphExposureAllEH3NoZeroVals->GetYaxis()->SetTitle("Exposure [km^{2} sr yr]");
    GraphExposureAllEH3NoZeroVals->GetYaxis()->CenterTitle();
    GraphExposureAllEH3NoZeroVals->SetMarkerStyle(23);
    GraphExposureAllEH3NoZeroVals->SetMarkerSize(1);
    GraphExposureAllEH3NoZeroVals->SetMarkerColor(kOrange+4);
    GraphExposureAllEH3NoZeroVals->SetLineColor(kOrange+4);
    GraphExposureAllEH3NoZeroVals ->SetFillColorAlpha(kOrange-7, .5);

    GraphExposureAllEH4NoZeroVals->SetTitle("Exposure Coihueco for 1 year, #theta #in [115 - 130#circ]");
    GraphExposureAllEH4NoZeroVals->GetXaxis()->SetTitle("lg E_{MC} / eV");
    GraphExposureAllEH4NoZeroVals->GetXaxis()->CenterTitle();
    GraphExposureAllEH4NoZeroVals->GetYaxis()->SetTitleOffset(1.2);
    GraphExposureAllEH4NoZeroVals->GetYaxis()->SetTitle("Exposure [km^{2} sr yr]");
    GraphExposureAllEH4NoZeroVals->GetYaxis()->CenterTitle();
    GraphExposureAllEH4NoZeroVals->SetMarkerStyle(23);
    GraphExposureAllEH4NoZeroVals->SetMarkerSize(1);
    GraphExposureAllEH4NoZeroVals->SetMarkerColor(kGreen+4);
    GraphExposureAllEH4NoZeroVals->SetLineColor(kGreen+4);
    GraphExposureAllEH4NoZeroVals ->SetFillColorAlpha(kGreen-7, .5);

  TMultiGraph *mgExposureFD = new TMultiGraph();
  mgExposureFD->Add(GraphExposureAllEH0 );
  mgExposureFD->Add(GraphExposureAllEH1);
  mgExposureFD->Add(GraphExposureAllEH2NoZeroVals );
  mgExposureFD->Add(GraphExposureAllEH3NoZeroVals );
  mgExposureFD->Add(GraphExposureAllEH4NoZeroVals );
  mgExposureFD->Draw("aple3");
  //mgExposureFD->SetTitle("Exposure FD, #theta #in [115 - 130#circ] ;  lg E (eV) ; Exposure [km^{2} sr yr]");

  //mgExposureFD->SetMaximum(1E4);
  mgExposureFD->GetXaxis()->SetTitle("lg E / eV");
  mgExposureFD->GetYaxis()->SetTitle("Exposure [km^{2} sr yr]");
  mgExposureFD->GetYaxis()->SetTitleOffset(1.15);
  mgExposureFD->GetXaxis()->SetTitleOffset(1.2);
  mgExposureFD->GetYaxis()->SetLabelSize(.06);
  mgExposureFD->GetYaxis()->SetTitleSize(.065);
  mgExposureFD->GetXaxis()->SetLabelSize(.06);
  mgExposureFD->GetXaxis()->SetTitleSize(.065);
  mgExposureFD->GetXaxis()->SetLabelFont(132);
  mgExposureFD->GetYaxis()->SetLabelFont(132);
  mgExposureFD->GetXaxis()->SetTitleFont(132);
  mgExposureFD->GetYaxis()->SetTitleFont(132);
  mgExposureFD->GetXaxis()->CenterTitle();
  mgExposureFD->GetYaxis()->CenterTitle();

  

  leg3 = new TLegend(.69,0.25,.96,0.65); //size of legend
  //leg3->SetNColumns(2);
  leg3->SetBorderSize(1);
  leg3->SetTextSize(.06);
  leg3->SetTextFont(132);
  leg3->SetMargin(.2);
  leg3->SetFillColor(10);
  //leg3->SetFillStyle(0);
  leg3->AddEntry(GraphExposureAllEH0,"#font[132]{H_{1} = 1.4 km}","lp"); //top left
  leg3->AddEntry(GraphExposureAllEH1,"#font[132]{H_{1} = 2.4 km}","lp");
  leg3->AddEntry(GraphExposureAllEH2NoZeroVals,"#font[132]{H_{1} = 3.4 km}","lp");
  leg3->AddEntry(GraphExposureAllEH3NoZeroVals,"#font[132]{H_{1} = 4.4 km}","lp");
  
  leg3->AddEntry(GraphExposureAllEH4NoZeroVals,"#font[132]{H_{1} = 5.4 km}","lp");
  
  
  leg3->Draw();

   CanvasExposureFD->Print("ExposureFDTauDiffHeightsE17_18.5_Theta115_130.pdf");



   CanvasH0HeatExposure1year->cd();
   graphExposureHEAT1yearH0->SetTitle("Exposure HEAT for 1 year, #theta #in [115 - 130#circ]");
   graphExposureHEAT1yearH0->GetXaxis()->SetTitle("lg E_{MC} / eV");
   graphExposureHEAT1yearH0->GetXaxis()->CenterTitle();
   graphExposureHEAT1yearH0->GetYaxis()->SetTitleOffset(1.2);
   graphExposureHEAT1yearH0->GetYaxis()->SetTitle("Exposure [km^{2} sr yr]");
   graphExposureHEAT1yearH0->GetYaxis()->CenterTitle();
   graphExposureHEAT1yearH0->SetMarkerStyle(20);
   graphExposureHEAT1yearH0->SetMarkerSize(0.7);
   graphExposureHEAT1yearH0->SetMarkerColor(kBlack);
   graphExposureHEAT1yearH0 ->SetFillColorAlpha(kGray+2, .5);
   graphExposureHEAT1yearH0 ->Draw("APL");



}
