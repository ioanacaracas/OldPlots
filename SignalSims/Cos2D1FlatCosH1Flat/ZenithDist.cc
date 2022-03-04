
#include <UtilityFunctions.h>

#include <cmath>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <unistd.h>
#include <ctime>
#include <random>

#include <TFile.h>
#include <TGraphErrors.h>
#include <TGraph.h>
#include <TGraphAsymmErrors.h>
#include <TH1F.h>
#include <TH2D.h>
#include <TCutG.h>
#include <TText.h>
#include <TRandom.h>
#include <TProfile.h>

#include "ZenithDist.h"

using namespace std;

static const int Runs = 1E8;

static const double Rad = 180/M_PI;
static const double Deg = M_PI/180;

static const double ZenMax = 70 * Deg;
static const double ZenMin = 0 * Deg;

static const double HMax = 9000;
static const double DMax = HMax/cos(ZenMax);
static const double HSimMax = 9500;

static const double MeanX1 = 63.3;
static const double Hn = 10400;
static const double Rho0 = 0.001225;


double GetX0ToX1Distance(const double h, const double x1){
  double atmDensity = Rho0 * exp(-h/Hn);
 // cout<<x1 <<" @ " << h <<" -> " << 63/atmDensity / 100 <<"m" <<endl;
  return x1/atmDensity  / 100;
}


int main(int argc, char** argv) {
  static TRandom* random = new TRandom();
  random->SetSeed(0);

  string OutFileName = argv[1];
  TFile* outFile = new TFile(OutFileName.c_str(), "RECREATE");


  TH1F* ZenithD = new TH1F("ZenithD", "Flat zenith flat distance", 180, 90, 180);
  TH1F* CosZenithD = new TH1F("CosZenithD", "Flat in Cos(zenith) flat distance", 180, 90, 180);
  TH1F* CosSqZenithD = new TH1F("CosSqZenithD", "Flat in Cos(zenith)^2 flat distance", 180, 90, 180);

  TH1F* HFromD = new TH1F("HFromD", "Height from flat distance flat zenith", 100, 0, HMax);
  TH1F* HFromDCos = new TH1F("HFromDCos", "Height from distance height Cos(zenith)", 100, 0, HMax);
  TH1F* HFromDCosSq = new TH1F("HFromDCosSq", "Height from distance height Cos(zenith)^2", 100, 0, HMax);

  TProfile* HFromDvsZenith = new TProfile("HFromDvsZenith","Height from flat distance flat zenith vs Zenith",100, 0, HMax, 90, 180); 
  TProfile* HFromDCosvsZenith = new TProfile("HFromDCosvsZenith","Height from flat distance Cos(zenith) vs Zenith",100, 0, HMax, 90, 180); 
  TProfile* HFromDCosSqvsZenith = new TProfile("HFromDCosSqvsZenith","Height from flat distance Cos(zenith)^2 vs Zenith",100, 0, HMax, 90, 180); 

  TH1F* FlatDCosSqCut = new TH1F("FlatDCosSqCut", "Flat Distance, Cos(zenith)^2, With Hmax Cut", 100, 0, DMax);
  TProfile* FlatDCosSqvsZenithCut = new TProfile("FlatDCosSqvsZenithCut","Flat Distance, Cos(zenith)^2, With Hmax Cut vs Zenith",100, 0, DMax, 90, 180);

  TProfile* FlatDCosSqvsZenith = new TProfile("FlatDCosSqvsZenith","Flat Distance, Cos(zenith)^2 vs Zenith",100, 0, DMax, 90, 180);  
  TH1F* FlatDCosSq = new TH1F("FlatDCosSq","Flat Distance, Cos(zenith)^2 vs Zenith",100, 0, DMax); 
  

  TH1F* ZenithH = new TH1F("ZenithH", "Flat zenith flat height", 180, 90, 180);
  TH1F* CosZenithH = new TH1F("CosZenithH", "Flat in Cos(zenith) flat height", 180, 90, 180);
  TH1F* CosSqZenithH = new TH1F("CosSqZenithH", "Flat in Cos(zenith)^2 flat height", 180, 90, 180);
  TH1F* Cos3ZenithH = new TH1F("Cos3ZenithH", "Flat in Cos(zenith)^3 flat height", 180, 90, 180);

  TH1F* DFromH = new TH1F("DFromH", "Distance from flat height flat zenith", 100, 0, DMax);
  TH1F* DFromHCos = new TH1F("DFromHCos", "Distance from flat height Cos(zenith)", 100, 0, DMax);
  TH1F* DFromHCosSq = new TH1F("DFromHCosSq", "Distance from flat height Cos(zenith)^2", 100, 0, DMax);

  TProfile* DFromHvsZenith = new TProfile("DFromHvsZenith","Distance from flat height flat zenith vs Zenith",100, 0, DMax, 90, 180); 
  TProfile* DFromHCosvsZenith = new TProfile("DFromHCosvsZenith","Distance from flat height Cos(zenith) vs Zenith",100, 0, DMax, 90, 180); 
  TProfile* DFromHCosSqvsZenith = new TProfile("DFromHCosSqvsZenith","Distance from flat height Cos(zenith)^2 vs Zenith",100, 0, DMax, 90, 180); 


  TH1F* ZenithDFromHmax = new TH1F("ZenithDFromHmax", "Flat zenith flat distance in allowed height range", 180, 90, 180);
  TH1F* CosZenithDFromHmax = new TH1F("CosZenithDFromHmax", "Flat in Cos(zenith) flat distance in allowed height range", 180, 90, 180);
  TH1F* CosSqZenithDFromHmax = new TH1F("CosSqZenithDFromHmax", "Flat in Cos(zenith)^2 flat distance in allowed height range", 180, 90, 180);

  TH1F* DFromDFromHmax = new TH1F("DFromDFromHmax", "Distance from flat distance in allowed height range flat zenith", 100, 0, DMax);
  TH1F* DFromDFromHmaxCos = new TH1F("DFromDFromHmaxCos", "Distance from flat distance in allowed height range Cos(zenith)", 100, 0, DMax);
  TH1F* DFromDFromHmaxCosSq = new TH1F("DFromDFromHmaxCosSq", "Distance from flat distance in allowed height range Cos(zenith)^2", 100, 0, DMax);

  TProfile* DFromDFromHmaxvsZenith = new TProfile("DFromDFromHmaxvsZenith","Distance from flat distance in allowed height range flat zenith vs Zenith",100, 0, DMax, 90, 180); 
  TProfile* DFromDFromHmaxCosvsZenith = new TProfile("DFromDFromHmaxCosvsZenith","Distance from flat distance in allowed height range Cos(zenith) vs Zenith",100, 0, DMax, 90, 180); 
  TProfile* DFromDFromHmaxCosSqvsZenith = new TProfile("DFromDFromHmaxCosSqvsZenith","Distance from flat distance in allowed height range Cos(zenith)^2 vs Zenith",100, 0, DMax, 90, 180); 


  TH1F* X1Depth = new TH1F("X1Depth", "Depth of X1", 100, 0, 600);
  TH1F* Dist2X1 = new TH1F("Dist2X1", "Dist from X0 to X1", 100, 0, 20000);
  TH1F* X0FromDFromHmaxCos = new TH1F("X0FromDFromHmaxCos", "Distance to X0 from flat distance in allowed height range Cos(zenith)", 100, 0, DMax);
  TProfile* X0FromDFromHmaxCosvsZenith = new TProfile("X0FromDFromHmaxCosvsZenith","Distance to X0 from flat distance in allowed height range Cos(zenith) vs Zenith",100, 0, DMax, 90, 180); 

  //MC Runs
  for(int i = 0; i < Runs; ++i){

    double zen = random->Uniform(ZenMin, ZenMax);
    double zenCosZen = acos(random->Uniform(cos(ZenMin), cos(ZenMax)));
    double zenCosSqZen = acos(sqrt(random->Uniform(cos(ZenMin)*cos(ZenMin), cos(ZenMax)*cos(ZenMax))));
    
    double Cos3Zen = random->Uniform(cos(ZenMin)*cos(ZenMin)*cos(ZenMin), cos(ZenMax)*cos(ZenMax)*cos(ZenMax));
    double zenCos3Zen = acos(exp(log(Cos3Zen) / 3));

    double X0X1Depth = random->Exp(MeanX1);
    X1Depth->Fill(X0X1Depth);

    //Flat Distance Plots
    double dist = random->Uniform(0, DMax);

    //Flat Distance and Zenith
    if(dist <= HMax/cos(zen)){
      ZenithD->Fill(zen * Rad);
      HFromD->Fill(dist * cos(zen));
      HFromDvsZenith->Fill(dist * cos(zen), 180 - (zen * Rad));
    }

    //Flat Distance and Cos(Zenith)
    if(dist <= HMax/cos(zenCosZen)){
      CosZenithD->Fill(zenCosZen * Rad);
      HFromDCos->Fill(dist * cos(zenCosZen));
      HFromDCosvsZenith->Fill(dist * cos(zenCosZen), 180 - (zenCosZen * Rad));
    }

    //Flat Distance and Cos(Zenith)^2
    if(dist <= HMax/cos(zenCosSqZen)){
      CosSqZenithD->Fill(180 - (zenCosSqZen * Rad));
      HFromDCosSq->Fill(dist * cos(zenCosSqZen));
      HFromDCosSqvsZenith->Fill(dist * cos(zenCosSqZen), 180 - (zenCosSqZen * Rad));

      FlatDCosSqCut->Fill(dist);
      FlatDCosSqvsZenithCut->Fill(dist, 180 - (zenCosSqZen * Rad) );
    }

    cout<<"dist = "<<dist<<" theta: "<<zenCosSqZen * Rad<<endl;
    FlatDCosSqvsZenith->Fill(dist, 180 - (zenCosSqZen * Rad));
    FlatDCosSq->Fill(dist);

    //Flat Height Plots
    double height = random->Uniform(0, HMax);

    //Flat in height flat in zenith
    ZenithH->Fill(180 - (zen*Rad));
    DFromH->Fill(height/cos(zen));
    DFromHvsZenith->Fill(height/cos(zen),180 - (zen*Rad));

    //Flat in height flat in Cos(zenith)
    CosZenithH->Fill(180 - (zenCosZen*Rad));
    DFromHCos->Fill(height/cos(zenCosZen));
    DFromHCosvsZenith->Fill(height/cos(zenCosZen),180 - (zenCosZen*Rad));

    //Flat in height flat in CosSq(zenith)
    CosSqZenithH->Fill(180 - (zenCosSqZen*Rad));
    DFromHCosSq->Fill(height/cos(zenCosSqZen));
    DFromHCosSqvsZenith->Fill(height/cos(zenCosSqZen),180 - (zenCosSqZen*Rad));


    Cos3ZenithH->Fill(zenCos3Zen*Rad);

    //Flat Distance in Max Height range
    double distZen = random->Uniform(0, HMax / cos(zen));

    ZenithDFromHmax->Fill(180 - (zen*Rad));
    DFromDFromHmax->Fill(distZen);
    DFromDFromHmaxvsZenith->Fill(distZen,180 - (zen*Rad));


    double distZenCos = random->Uniform(0, HMax / cos(zenCosZen));

    CosZenithDFromHmax->Fill(180 - (zenCosZen*Rad));
    DFromDFromHmaxCos->Fill(distZenCos);
    DFromDFromHmaxCosvsZenith->Fill(distZenCos,180 -(zenCosZen*Rad));


    double distZenCosSq = random->Uniform(0, HMax / cos(zenCosSqZen));

    CosSqZenithDFromHmax->Fill(180 - (zenCosSqZen*Rad));
    DFromDFromHmaxCosSq->Fill(distZenCosSq);
    DFromDFromHmaxCosSqvsZenith->Fill(distZenCosSq, 180 - (zenCosSqZen*Rad));


    //X0 plots

    double DToX0 = GetX0ToX1Distance(distZenCos * cos(zenCosZen), X0X1Depth);
    Dist2X1->Fill(DToX0);
    X0FromDFromHmaxCos->Fill(distZenCos - DToX0);
    X0FromDFromHmaxCosvsZenith->Fill(distZenCos - DToX0, zenCosSqZen*Rad);

    UtilityFunctions::ShowProgress(i, Runs - 1);
  }

  outFile->Write();
  outFile->Close();
  return 0;
}  //end main

