

#include <Math/Polynomial.h>  
#include <Math/Interpolator.h>
#include <TFile.h>
#include <TObject.h>
#include <TRandom.h>
#include <TH1D.h>
#include <TH2D.h>
#include <TProfile.h>
#include <TProfile2D.h>
#include <TTree.h>
#include <TStyle.h>
#include <Riostream.h>
#include <TMath.h>

#include <iostream>
#include <string>
#include <cmath>






const double PI = 3.141592653589;

   double DecayDistanceFromEarth;

   double EcalSum;

   double weightPiPlus;
   double weightPiMinus;
   double weightPi0;
   double weightKPlus;
   double weightKMinus;
   double weightK0;
   double weightElectron;

  double avX1PiCharged;
  double avX1K;
  //avX1PiCharged(lgE/ev) = avx1K(lgE/ev) = P0+P1*lgE + P2*lgE^2 + P3*lgE^3 
  double P0X1PiConexFit = 655.301;
  double P1X1PiConexFit = -80.0338;
  double P2X1PiConexFit = 3.58671;
  double P3X1PiConexFit = -0.0559;
  double lgEcaleV;

  double avX1Electron = 37;
  double avX1Pi0 = (9.0/7.0) * avX1Electron;
  
  

   double AverageX1;

   TRandom* random = new TRandom();

   double X1FromExpDistribPiCharged;
   double X1FromExpDistribPi0;
   double X1FromExpDistribK;
   double X1FromExpDistribElectron;

   double X1FromExpDistrib;
   double X1FromExpDistribVert;

   double X1FromExpDistribVertFinal;

   //double zenithVal = 180; //vertical events for now
   double zenithVal;
   double H0; //H0 = D0 * cosZenith
   double LogXVert0;
   double Xvert0;

   double H1;
   double D1;

   double EventsPerEbinPerZenithBin = 17872.88716;
   double EventsPerZenithBin = 160855.9845;

   const double NrOfX1Generation = 100; //the number used to get x1 from the exponential distribution; i.e: for each tau decaying in atmo 
                                  // x1 is extracted NrOfX1Generation times i.e TotEvent = AtmoDecayEvents*NrOfX1Generation

   //==============Xvert0 (corresponding to H0+1.4 km --> takes into account the height above sea level ---->Linsley 5 layers paramterization)========
 

//Offline interpolation from ParametricXMLProfileModel.xml ->suggetsted by M. Unger
const int Npts = 32; //nr of input data up to 30 km above sea level

double  HeightATMProfile[Npts] = {0.0, 1000.0, 2000.0, 3000.0, 4000.0, 5000.0, 6000.0, 7000.0, 8000.0, 9000.0, 10000.0, 11000.0, 12000.0, 13000.0, 14000.0, 15000.0, 16000.0, 17000.0, 18000.0, 19000.0, 20000.0, 21000.0, 22000.0, 23000.0, 24000.0, 25000.0, 26000.0, 27000.0, 28000.0, 29000.0, 30000.0,100000.0}; 
//m

double densityATMProfile[Npts] = {1.23E-03, 1.11E-03, 1.01E-03, 9.09E-04, 8.19E-04, 7.36E-04, 6.60E-04, 5.90E-04, 5.25E-04, 4.66E-04, 4.13E-04, 3.64E-04, 3.11E-04, 2.66E-04, 2.27E-04, 1.94E-04, 1.65E-04, 1.41E-04, 1.21E-04, 1.03E-04, 8.80E-05, 7.49E-05, 6.37E-05, 5.43E-05, 4.63E-05, 3.95E-05, 3.37E-05, 2.88E-05, 2.46E-05, 2.10E-05, 1.80E-05, 1.0e-09};
//g/cm3

double pressureATMProfile[Npts] = {1013.25, 898.7, 795.0, 701.1, 616.4, 540.2, 471.8, 410.6, 356.0, 307.4, 264.4, 226.3, 193.3, 165.1, 141.0, 120.4, 102.9, 87.87, 75.05, 64.10, 54.75, 46.78, 40.00, 34.22, 29.30, 25.11, 21.53, 18.47, 15.86, 13.63, 11.72, 0.001};
//100*Pa

double temperatureATMProfile[Npts] = {288.15, 281.65, 275.15, 268.65, 262.15, 255.65, 249.15, 242.65, 236.15,229.65, 223.15, 216.65, 216.65, 216.65, 216.65, 216.65, 216.65, 216.65, 216.65, 216.65, 216.65, 217.65, 218.65, 219.65, 220.65, 221.65, 222.65, 223.65, 224.65, 225.65, 226.65, 100.0};
//Kelvin

double LogDepth[Npts];
double LogAtmoDensityOffline[Npts]; //the interpolation in Offline is LogDenistyVsHeight

double HeightATMProfileReversed[Npts];
double LogDepthReversed[Npts];

const double kOverburdenSeaLevel = 1033;
const double atmosphere = 101325;

//function to calculate the random nr from the specific TauDecay Energy Ratio distrib (for Eearth -> Ecal for not decaying events)





 //Start Plotting
void PlotTauDecaysDistanceVsEcalDiffZenithGammaMinus1(){

  //Define root file with the histograms with energyRatio taken by secondaries not contributing to Ecal
  TFile* RootFileEcalRatioFromEtauTAUOLA = new TFile("/home/ioana/PHD/AnalysisXmaxHeightIntEtc/AnitaAnalysis/TauDecay/TauPropagation/TauEfficiencyAndExposure/RootFileEcalRatioFromEtauTAUOLA.root", "READ");
  RootFileEcalRatioFromEtauTAUOLA->cd();

  TH1D* EcalSumOverEtauHist = ((TH1D*) RootFileEcalRatioFromEtauTAUOLA->Get("EcalSumOVerEtauHist"));
  

  EcalSumOverEtauHist->SetDirectory(0);


  RootFileEcalRatioFromEtauTAUOLA->Close();
  double MuDecaysWeight = EcalSumOverEtauHist->GetBinContent(0);

  EcalSumOverEtauHist->Draw();

//Defining the root file in which analysis will be stored

   TH1D* TauHistlgEPrimaryAllGenEvents = new TH1D("TauHistlgEPrimaryAllGenEvents", "TauHistlgEPrimaryAllGenEvents", 100, 0, 13);
   TH1D* ZenithHistAllGenEvents = new TH1D("ZenithHistAllGenEvents", "ZenithHistAllGenEvents", 100, 110, 180);
   TH1D* GenDistanceHist = new TH1D("GenDistanceHist", "GenDistanceHist", 100, -55, 30);
   TH1D* GenDistanceDensityWeightedHist = new TH1D("GenDistanceDensityWeightedHist", "GenDistanceDensityWeightedHist", 100, -55, 30);
   TH1D* EarthDistanceHist = new TH1D("EarthDistanceHist", "EarthDistanceHist", 100, -55, 0);
   TH1D* AtmoDistanceHist = new TH1D("AtmoDistanceHist", "AtmoDistanceHist",100, 0, 30);
   TH1D* AtmoGenAtmoDecayingD1Hist = new TH1D("AtmoGenAtmoDecayingD1Hist", "AtmoGenAtmoDecayingD1Hist", 100, 0, 30);
   TH1D* D0Hist = new TH1D("D0Hist", "D0Hist", 100, 0, 30E3);
   TH1D* D0DensityWeightedHist = new TH1D("D0DensityWeightedHist","D0DensityWeightedHist", 100, 0, 30E3);
   TH1D* DecayDistanceHist = new TH1D("DecayDistanceHist","DecayDistanceHist", 100, 0, 100);

   TH2D* DecayDistanceWithRespectToEarthVsEprimTauHistEvAtmoGenAndEarthGen = 
            new TH2D("DecayDistanceWithRespectToEarthVsEprimTauHistEvAtmoGenAndEarthGen", 
                     "DecayDistanceWithRespectToEarthVsEprimTauHistEvAtmoGenAndEarthGen", 100, -50, 30, 100, 7 ,13);
   TH2D* DecayDistanceWithRespectToEarthVsEprimTauHistAllEv = 
            new TH2D("DecayDistanceWithRespectToEarthVsEprimTauHistAllEv", 
                     "DecayDistanceWithRespectToEarthVsEprimTauHistAllEv", 100, -50, 30, 100, 7 ,13);
   TProfile2D *p2dSeparate = new TProfile2D("p2dSeparate","EprimVsDecayDistVsEtauDecayEvAtmoGenAndEarthGen",100, -100, 30, 100, 7 ,13);
   TProfile2D *p2dAll = new TProfile2D("p2dAll","EprimVsDecayDistVsEtauDecayAllEv",100, -100, 30, 100, 7 ,13);

   TH1D* AverageX1Hist = new TH1D("AverageX1Hist","AverageX1Hist", 500, 0, 125);
   TH1D* X1FromExpDistribHist = new TH1D("X1FromExpDistribHist","X1FromExpDistribHist", 500, 0, 5000);

   TH1D* Xvert0Hist = new TH1D("Xvert0Hist", "Xvert0Hist", 100, 0, 880);

   //TF1* ExpoFunction = new TF1("ExpoFunction", "[0]*exp(-x) + [1]*exp(-x) + [2]*exp(-x) +[3]*exp(-x)", 0, 2500);

   TH1D* X1FromExpDistribVertFinalHist = new TH1D("X1FromExpDistribVertFinalHist", "X1FromExpDistribVertFinalHist", 100,0, 880);

   TH1D* H1Hist = new TH1D("H1Hist", "H1Hist", 100, 0, 50E3); 
   TH1D* D1Hist = new TH1D("D1Hist", "D1Hist", 500, 0, 50E3);
   TH1D* D1DensityWeightedHist = new TH1D("D1DensityWeightedHist", "D1DensityWeightedHist", 500, 0, 50E3);
   
   TH1D* EcalSumHist = new TH1D("EcalSumHist", "EcalSumHist", 40, 16.5, 18.5);
   TH1D* EcalSumDensityWeightedHist = new TH1D("EcalSumDensityWeightedHist", "EcalSumDensityWeightedHist", 40, 16.5, 18.5);
   
   TH1D* EPrimEventsOfInterest = new TH1D("EPrimEventsOfInterest", "EPrimEventsOfInterest", 110, 16.5, 22);
   TH1D* EPrimEventsOfInterestDensityWeighted = new TH1D("EPrimEventsOfInterestDensityWeighted", "EPrimEventsOfInterestDensityWeighted", 110, 16.5, 22);   
   TH2D* EprimVsEcalHist = new TH2D("EprimVsEcalHist", "EprimVsEcalHist", 110, 16.5, 22, 40, 16.5, 18.5);
   TH2D* EprimVsEcalDensityWeightedHist = new TH2D("EprimVsEcalDensityWeightedHist", "EprimVsEcalDensityWeightedHist", 110, 16.5, 22, 40, 16.5, 18.5);
   
   TH2D* D1VsEcalSumHist = new TH2D("D1VsEcalSumHist", "D1VsEcalSumHist",300, 0, 30E3, 40, 16.5, 18.5 );
   TH2D* D1VsEcalSumDensityWeightedHist = new TH2D("D1VsEcalSumDensityWeightedHist", "D1VsEcalSumDensityWeightedHist", 20, 16.5, 19, 60, 0, 30 );
   
   TH2D* D0VsEcalSumHist = new TH2D("D0VsEcalSumHist", "D0VsEcalSumHist", 300, 0, 30E3, 40, 16.5, 18.5);
   TH2D* D0VsEcalSumDensityWeightedHist = new TH2D("D0VsEcalSumDensityWeightedHist", "D0VsEcalSumDensityWeightedHist", 20, 16.5, 19, 60, 0, 30 );
   TH2D* H1VsEcalSumDensityWeightedHist = new TH2D("H1VsEcalSumDensityWeightedHist", "H1VsEcalSumDensityWeightedHist", 20, 16.5, 19 ,60, 0, 30);
   
   
   
 

   TH1D* EprimEarthGenEarthDecayed = new TH1D("EprimEarthGenEarthDecayed","EprimEarthGenEarthDecayed", 20, 7.5, 13);
   TH1D* EprimEarthGen = new TH1D("EprimEarthGen","EprimEarthGen", 20, 7.5, 13);
   TH1D* EprimEarthGenEarthKilled = new TH1D("EprimEarthGenEarthKilled", "EprimEarthGenEarthKilled", 20, 7.5, 13);
   TH1D* EprimAtmoGen = new TH1D("EprimAtmoGen", "EprimAtmoGen", 20, 7.5, 13);

   TH1D* EdecayEarthGenExitEarth = new TH1D("EdecayEarthGenExitEarth","EdecayEarthGenExitEarth", 20, 7.5, 13);
   TH1D* EdecayEarthGenDecayAtmoHist = new TH1D("EdecayEarthGenDecayAtmoHist", "EdecayEarthGenDecayAtmoHist", 20, 7.5, 13);
   TH1D* EprimEarthGenExitEarth = new TH1D("EprimEarthGenExitEarth", "EprimEarthGenExitEarth", 20, 7.5, 13);
   TH1D* EprimEarthGenNoAtmo = new TH1D("EprimEarthGenNoAtmo","EprimEarthGenNoAtmo", 20, 7.5, 13);

   //histogram with H1VsEcal
   TH2D* H1VsEcalSumHist = new TH2D("H1VsEcalSumHist", "H1VsEcalSumHist", 18, 0, 9, 40, 16.5, 18.5);
   TH2D* H1VsEcalSumHistWeightedMedium = new TH2D("H1VsEcalSumHistWeightedMedium", "H1VsEcalSumHistWeightedMedium", 18, 0, 9, 40, 16.5, 18.5);

   TH1D* EEarthConexLike = new TH1D("EEarthConexLike", "EEarthConexLike", 25, 16.375, 22.625);  //energy of events when exit earth / created in atmo
   TH1D* EPrimConexLike = new TH1D("EPrimConexLike", "EPrimConexLike", 25, 16.375, 22.625);
   TH1D* EcalSumDecayingEventsHist = new TH1D("EcalSumDecayingEventsHist", "EcalSumDecayingEventsHist", 420, 1, 22);
   TH1D* EcalHistFromTauolaPerEdecay = new TH1D("EcalHistFromTauolaPerEdecay", "EcalHistFromTauolaPerEdecay", 160, 14, 22); 

    TH2D* AtmoGenEvGenDistanceVsEdecay = new TH2D("AtmoGenEvGenDistanceVsEdecay", "AtmoGenEvGenDistanceVsEdecay", 54, 0, 27, 110, 16.5, 22);
    TH2D* EarthGenEvAtmoDistanceVsEdecay = new TH2D("EarthGenEvAtmoDistanceVsEdecay", "EarthGenEvAtmoDistanceVsEdecay", 54, 0, 27, 110, 16.5, 22);


   double sumAtmoExitEvents = 0;
   double sumKilledEvents = 0;
   double EvOfInterestConexLike = 0;

   vector<double> EventIdVector;
   vector<double> EprimVector;
   vector<double> EcalSumVector;
   vector<double> D1Vector;

   //vectors for making the plot of interpolation between logdensity and Height
    //can delete or comment after this check

   vector<double> LogDensityPlot;
   vector<double> DensityPlot;
   vector<double> HeightPlot;





   const double D1maxAbove = 9/fabs(cos(110 * PI/180)) * 1E3; //in m
   cout<<"D1Max: "<<D1maxAbove<<endl;
 
 // const int nEBins = 40; //every 0.05 lgE
  //const int nEBins = 9; //every 0.25 lgE as Vladimir
  const int nEBins = 20; //every 0.125 lgE as Massimo; make histos from 16.5-19
  const int nH1Bins = 18; //every 500 m / 0.5 km


  //histograms of Eprim for different Ecal H1 bins


  // TH1D* H1HistoForEcalBin[nEBins];
  // string nameH1HistoForEcalBin[nEBins];

  // string nameH1;
  // std::stringstream ssH1;

  // for(int i = 0; i < nEBins; ++i){
  //     ssH1.clear();
  //     ssH1.str(std::string());
  //     ssH1 << "H1HistEcalbin_" << i ;
  //     nameH1 = ssH1.str();
  //     nameH1HistoForEcalBin[i] = nameH1;
  //     H1HistoForEcalBin[i] = new TH1D(nameH1.c_str(), "", 18, 0, 9);
    
  // } 

  TH1D* EprimHistoForEcalBinForH1Bin[nEBins][nH1Bins];
  string nameEprimHistoForEcalBinForH1Bin[nEBins][nH1Bins];

  string nameEdecay;
  std::stringstream ssEdecay;

  for(int i = 0; i < nEBins; ++i){
    for(int ih1 = 0; ih1<nH1Bins; ++ih1){
      ssEdecay.clear();
      ssEdecay.str(std::string());
      ssEdecay <<"Eprim_Ecalbin_"<<i<<"H1bin_"<<ih1;
      nameEdecay = ssEdecay.str();
      nameEprimHistoForEcalBinForH1Bin[i][ih1] = nameEdecay;
      EprimHistoForEcalBinForH1Bin[i][ih1] = new TH1D(nameEdecay.c_str(), "", 44, 16.5, 22);
    }
  }

 // gStyle->SetOptStat(1);

  gStyle->SetStatX(.95);
  gStyle->SetStatY(.9);
  // Set x-position (fraction of pad size)
  gStyle->SetStatW(0.2);
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


  double lgEprimTau;
  double Zenith;
  double GenDistance;
  double EarthDistance;
  double AtmoDistance;
  double DecayDistance;
  double Pi0Energy;
  double PiMinusEnergy;
  double PiPlusEnergy;
  double K0Energy;
  double KMinusEnergy;
  double KPlusEnergy;
  double ElectronEnergy;
  double lgTauDecayEnergy;
  double ESumSecondaries;



  bool EarthGenEv;
  bool EarthDecayedEv;
  bool KilledEv;
  bool ExitAtmoWithNoDecay;


string holder; 
string holder2;
int nEvents;
double evnr;
double eprimtau;
double zenith;
double dgen;
double dearth;
double datmo;
double dtotal;
double epiminus;
double epiplus;
double epi0;
double eKminus;
double eKplus;
double eK0;
double eelectron;
double etaudecay;
double eventId;

const double NZenithBins = 30;
double ZenithValues[NZenithBins];

double CosSqZenithValues[NZenithBins] = {0.1317166667, 0.16115, 0.1905833333, 0.2200166667, 0.24945, 0.2788833333, 0.3083166667, 
                                        0.33775, 0.3671833333, 0.3966166667, 0.42605, 0.4554833333, 0.4849166667, 0.51435, 0.5437833333, 0.5732166667, 
                                        0.60265, 0.6320833333, 0.6615166667, 0.69095, 0.7203833333, 0.7498166667, 0.77925, 0.8086833333, 0.8381166667, 
                                        0.86755, 0.8969833333, 0.9264166667, 0.95585, 0.9852833333};


for(int i=0; i<NZenithBins; i++)
  ZenithValues[i] = 180 - acos( sqrt(CosSqZenithValues[i]) ) * 180/PI;


TFile* AnalysisHistosRootFile[NZenithBins];
string nameTfileZenith[NZenithBins];
string nameTfile;
std::stringstream ssTfile;

//atmospheric profile from Offline:
for(int i=0; i<Npts; i++){
      LogDepth[i] = log( (pressureATMProfile[i])*100*kOverburdenSeaLevel/atmosphere ); //log depth Vs height -> linear parametrization
      LogAtmoDensityOffline[i] = log(densityATMProfile[i]);
}

ROOT::Math::Interpolator interLogDepthVsHeight(Npts, ROOT::Math::Interpolation::kAKIMA );
interLogDepthVsHeight.SetData (Npts, HeightATMProfile, LogDepth);

//check interpolation between LogDensity and Height
ROOT::Math::Interpolator interLogDensityVsHeight(Npts, ROOT::Math::Interpolation::kAKIMA );
interLogDensityVsHeight.SetData (Npts, HeightATMProfile, LogAtmoDensityOffline);

//reverse the elements of height and depth, as since depth is going to be on x axis, it has to always have increasing values
for(int i=Npts-1; i>=0; i--)
  {HeightATMProfileReversed[Npts-i-1] =HeightATMProfile[i];
  LogDepthReversed[Npts-i-1] = LogDepth[i];}

ROOT::Math::Interpolator interHeightVsLogDepth(Npts, ROOT::Math::Interpolation::kAKIMA );
interHeightVsLogDepth.SetData (Npts, LogDepthReversed, HeightATMProfileReversed);

double TauEventsGeneratedInSensitiveVolume = 0; //only events passing through the volume: no events decayed or Killed inside Earth
TVectorD VectorTauEventsGeneratedInSensitiveVolume(1);

double EarthDensity = 2.6; // g/cm3
double AtmoDensityGenDistance;
double weightsMediumDensity;

double weightEnergySpectrum;
double EminTauSim = pow(10, 19.0); // re weight to 17.5 as the reference re weighting bin
double gamma = -1; //E^-2



ifstream readPar1;



double weightTAUOLA;
double EcalRatioTAUOLA;
double lgEsumFromTauola;

//int TotalDecayEventsConexLike = 0;

double GenEventsEcalBin;

  cout<<"got here!!"<<endl;

  int CountConexLike;
 // readPar1.open("TauSimTotal1E9EvFromPleiades/1E8Events_LmaxInside50km_TauSimSet_0_1E8Ev_Test1DSim_E16.5-22_LmaxBelowEarth50km_Elim16.5_info_reg0_0.dat");
   //begin zenith bins loop
for(int iZenithBinIterator = 0; iZenithBinIterator<NZenithBins; iZenithBinIterator++)
 {CountConexLike = 0;
 // if(iZenithBinIterator >= 4 )
   { zenithVal = ZenithValues[iZenithBinIterator]; 
    //zenithVal = 180;
      //create 1 tfile/zenith bin
   ssTfile.clear();
   ssTfile.str(std::string());
   ssTfile << "./RootFiles/RootFileHistosDistanceAndHeightVsEcal_Zenith_"<< iZenithBinIterator<<".root";
   nameTfile = ssTfile.str();
   nameTfileZenith[iZenithBinIterator] = nameTfile;
   AnalysisHistosRootFile[iZenithBinIterator] = new TFile(nameTfile.c_str(), "RECREATE");
  
   cout<<"creating file: "<<nameTfile.c_str()<<endl;
   

    cout<<"ZenithVal sssss = "<<zenithVal<<endl;
   readPar1.open("/home/ioana/PHD/AnalysisXmaxHeightIntEtc/AnitaAnalysis/TauDecay/TauPropagation/1E7Ev_Test1DSim_E16.5-22_LmaxBelowEarth50km_Elim16.5_info_reg0_0.dat");

   readPar1>>nEvents;
   getline(readPar1, holder);
   getline(readPar1, holder);
 

   for(int i=0; i<nEvents;i++)
     { 
      readPar1>>evnr>>eprimtau>>zenith>>dgen>>dearth>>datmo>>dtotal>>etaudecay>>epiminus>>epiplus>>epi0>>eKminus>>eKplus>>eK0>>eelectron;
      
      if(evnr - (int)evnr!=0)
        {cout<<"wrong entry for ev:"<<i<<" This should only happen if the random nr is set to 0. it only happened 1 time in 1E8 events. Instead of event nr it is: "<<evnr<<endl;
        continue;}
  
      eventId = evnr;
      lgEprimTau=log10(eprimtau);    
  
      Zenith=zenith;    
  
      GenDistance=dgen;
        
      EarthDistance=dearth;
      
      AtmoDistance=datmo;
  
      DecayDistance=dtotal;
  
      lgTauDecayEnergy = log10(etaudecay);
  
      PiMinusEnergy = (epiminus);
      PiPlusEnergy = (epiplus);
      Pi0Energy = (epi0);
  
      KMinusEnergy = (eKminus);
      KPlusEnergy = (eKplus);
      K0Energy = (eK0);
  
      ElectronEnergy = (eelectron);
  
      ESumSecondaries = (epiminus + epiplus + epi0 + eKminus + eKplus + eK0 + eelectron);
      EcalSum = (epiminus + epiplus + epi0 + eKminus + eKplus + eK0 + eelectron);
  
      getline(readPar1,holder);   
  
      
      if(GenDistance<0)
        weightsMediumDensity = 1; //densitiy of Earth is constant
      else{
        AtmoDensityGenDistance = exp( interLogDensityVsHeight.Eval(GenDistance * (-1) * cos(zenithVal * PI/180) * 1E3 + 1400) );
        weightsMediumDensity = AtmoDensityGenDistance / EarthDensity;
      }

      weightEnergySpectrum = pow( (eprimtau * 1E9 / EminTauSim), gamma + 1);
   
      //histograms
      // TauHistlgEPrimaryAllGenEvents->Fill(lgEprimTau);
      // ZenithHistAllGenEvents->Fill(Zenith);
      // GenDistanceHist->Fill(GenDistance);
      //GenDistanceDensityWeightedHist->Fill(GenDistance, weightsMediumDensity);
  
  
    EarthGenEv = false;
    EarthDecayedEv = false;
    KilledEv = false;
    ExitAtmoWithNoDecay = false;
  
      if(EarthDistance != 0)
        EarthGenEv = true;
      if(AtmoDistance == -1)
        EarthDecayedEv = true;
      if(AtmoDistance == -2)
        KilledEv = true;
      if(DecayDistance == -1)
        ExitAtmoWithNoDecay=true;
  
   
      if(EarthGenEv == false){
        AtmoGenEvGenDistanceVsEdecay->Fill(AtmoDistance, lgTauDecayEnergy+9);
        
      }
     if(EarthGenEv == true && EarthDecayedEv == false  &&  KilledEv == false){
        EarthGenEvAtmoDistanceVsEdecay->Fill(AtmoDistance, lgTauDecayEnergy + 9);
     }
  


     ///=============Events of interest, i.e "conex" gen events: all events which make it above Earth



      // if(EarthDecayedEv == false  &&  KilledEv == false){
      

      //   CountConexLike +=1;
      //   EEarthConexLike->Fill(lgTauDecayEnergy+9, weightsMediumDensity * weightEnergySpectrum);
      //   EPrimConexLike->Fill(lgEprimTau + 9, weightsMediumDensity * weightEnergySpectrum);

      //   //=======get the Ecal from Eearth ====
            
      //   for(int ibinHistTauola = 0; ibinHistTauola<=EcalSumOverEtauHist->GetXaxis()->GetNbins(); ibinHistTauola++){
      //     weightTAUOLA = EcalSumOverEtauHist->GetBinContent(ibinHistTauola);
      //     EcalRatioTAUOLA = EcalSumOverEtauHist->GetBinCenter(ibinHistTauola);
      //     lgEsumFromTauola = log10(EcalRatioTAUOLA) + (lgTauDecayEnergy+9);
         
      //     if(ibinHistTauola == 0)
      //       EcalHistFromTauolaPerEdecay->Fill(-1, MuDecaysWeight*weightsMediumDensity);
      //     else
      //       EcalHistFromTauolaPerEdecay->Fill(lgEsumFromTauola, weightTAUOLA * weightsMediumDensity * weightEnergySpectrum);
         
      //   }

      //   if(CountConexLike == 1) //first event of interest
      //     TH1D* EcalSumOVerEtauHistCheckTry = (TH1D*) EcalHistFromTauolaPerEdecay->Clone("");
      //   else
      //     EcalSumOVerEtauHistCheckTry->Add(EcalHistFromTauolaPerEdecay);

      //   EcalHistFromTauolaPerEdecay->Reset(); //clear the histogram after every decaying event, but add it first to EcalSumOverEtauHist
      //   // }
      // }





  ///================================TEMPORARY COMMENTED=============================


      if(EarthDecayedEv == false  &&  KilledEv == false  &&  ExitAtmoWithNoDecay == false && ( (lgEprimTau + 9) <=20 ) ) //all of the events that decayed in the atmosphere, no matter where they were produced
      {
        DecayDistanceFromEarth = AtmoDistance;
        // DecayDistanceWithRespectToEarthVsEprimTauHistAllEv->Fill(DecayDistanceFromEarth, lgEprimTau);
        // p2dAll->Fill(DecayDistanceFromEarth, lgEprimTau, lgTauDecayEnergy);
  
        if(EcalSum!=0){
  
          //weights calculation
          weightPiPlus = (PiPlusEnergy) / EcalSum;
          weightPiMinus = (PiMinusEnergy) / EcalSum;
          weightPi0 = (Pi0Energy) / EcalSum;
          weightKMinus = (KMinusEnergy) / EcalSum;
          weightKPlus = (KPlusEnergy) / EcalSum;
          weightK0 = (K0Energy) / EcalSum;
          weightElectron = (ElectronEnergy) / EcalSum;
  
          //==============Xvert0 (corresponding to H0+1.4 km --> takes into account the height above sea level (Offline Parametrization))========
          
  
          //here loop over the zenith bins
  
          H0 = AtmoDistance * (-1) * cos(zenithVal * PI/180) *1E3; //H0 in m 
          if( (H0+1400) <= HeightATMProfile[Npts-1] ){
            LogXVert0 = interLogDepthVsHeight.Eval(H0 + 1400);
            LogDensityPlot.push_back(interLogDensityVsHeight.Eval(H0 + 1400));
            DensityPlot.push_back(exp( interLogDensityVsHeight.Eval(H0 + 1400) ));
            HeightPlot.push_back(H0+1400);

          }          
          
          Xvert0 = exp(LogXVert0);
          Xvert0Hist->Fill(Xvert0);
        // Calculate average X1 for charged pions and Kaons as a function of energy, as taken from CONEX
          lgEcaleV = log10(EcalSum) + 9;
          avX1PiCharged = P0X1PiConexFit + P1X1PiConexFit * lgEcaleV + P2X1PiConexFit * pow(lgEcaleV,2) + P3X1PiConexFit * pow(lgEcaleV,3);
          avX1K = avX1PiCharged;
  
        
         //get X1 from exponential distribution of average X1 corresp to each secondaries: x 100 for each event
          
         
  
          for(int j=0; j<NrOfX1Generation; j++){
  
            X1FromExpDistribPiCharged=random->Exp(avX1PiCharged);
            X1FromExpDistribPi0=random->Exp(avX1Pi0);
            X1FromExpDistribK=random->Exp(avX1K);
            X1FromExpDistribElectron=random->Exp(avX1Electron);
  
            X1FromExpDistrib=X1FromExpDistribPiCharged * (weightPiPlus + weightPiMinus) + X1FromExpDistribPi0 * weightPi0+
                              X1FromExpDistribK * (weightK0 + weightKMinus + weightKPlus) + X1FromExpDistribElectron * weightElectron;
  
            //X1FromExpDistribHist->Fill(X1FromExpDistrib, 1/NrOfX1Generation);
  
            X1FromExpDistribVert=X1FromExpDistrib*(-1) * cos(zenithVal * PI/180);
            X1FromExpDistribVertFinal = Xvert0 - X1FromExpDistribVert; //xvert from top to bottom.
  
            if(X1FromExpDistribVertFinal>=exp(LogDepth[Npts-1])){ //else it is out of the atmo
                      
              X1FromExpDistribVertFinalHist->Fill(X1FromExpDistribVertFinal, 1/NrOfX1Generation);
              //========get to H from Xvertical===== 
              
              H1=interHeightVsLogDepth.Eval(log(X1FromExpDistribVertFinal)) - 1400;
            
              //H1Hist->Fill(H1, 1/NrOfX1Generation);
              
              D1 = H1 / ( (-1) * cos(zenithVal * PI/180) );

               
  
              if(log10(EcalSum)>= 7.5 && log10(EcalSum)<=9.5 && D1<=D1maxAbove){
               
                  { 
                        

                    D1VsEcalSumDensityWeightedHist->Fill(lgEcaleV, D1/1000, 1/NrOfX1Generation * weightsMediumDensity);
                    H1VsEcalSumDensityWeightedHist->Fill(lgEcaleV, H1/1000, 1/NrOfX1Generation * weightsMediumDensity);
                    D0VsEcalSumDensityWeightedHist->Fill(lgEcaleV, AtmoDistance, 1/NrOfX1Generation * weightsMediumDensity);
                   // cout<<"d0: "<<AtmoDistance<<endl;
                    
                  }
  
              }
  
            }
  
          }
  
  
        }
  
      }
   ///================================TEMPORARY COMMENTED untill here=============================


  }

 
    cout<<"Done!"<<endl;
  
  
    D1VsEcalSumDensityWeightedHist->Write();
    D0VsEcalSumDensityWeightedHist->Write();
    H1VsEcalSumDensityWeightedHist->Write();

    // H1VsEcalSumHist->Write();
    // H1VsEcalSumHistWeightedMedium->Write();


    // EEarthConexLike->Write();
    // EPrimConexLike->Write();


  
  
    
    
  // for(int i=0; i<nEBins; i++){    
  //     H1HistoForEcalBin[i]->Write();    
  // }

  // for(int i=0; i<nEBins; i++){
  //   for(int j=0; j<nH1Bins; j++){
  //     EprimHistoForEcalBinForH1Bin[i][j]->Write();
  //   }
  // }
  

   // cout<<"total Gen Events in the sensitive volume = "<<TauEventsGeneratedInSensitiveVolume<<endl;

   // cout<<"count : "<<CountConexLike<<endl;
   // //EcalSumOVerEtauHistCheckTry->Scale(1.0/CountConexLike);


   // cout<<"entries of this fucking hist before Write: "<<EcalSumOVerEtauHistCheckTry->GetEntries()<<endl;

   // EcalSumOVerEtauHistCheckTry->SetDirectory(0);
   // EcalSumOVerEtauHistCheckTry->SetTitle("EcalSumAllDecayingEvents");

   // EcalSumOVerEtauHistCheckTry->Write();
   // AtmoGenEvGenDistanceVsEdecay->Write();
   // EarthGenEvAtmoDistanceVsEdecay->Write();

   AnalysisHistosRootFile[iZenithBinIterator]->Write();
   AnalysisHistosRootFile[iZenithBinIterator]->Close();
 
  // cout<<"entries of this fucking hist: "<<EcalSumOVerEtauHistCheckTry->GetEntries()<<endl;

   // EcalHistFromTauolaPerEdecay->Reset();

   //  H1VsEcalSumHist->Reset();
   //  H1VsEcalSumHistWeightedMedium->Reset();
   //  AtmoGenEvGenDistanceVsEdecay->Reset();
   //  EarthGenEvAtmoDistanceVsEdecay->Reset();

   //  EEarthConexLike->Reset();
   //  EPrimConexLike->Reset();
 

    // for(int i=0; i<nEBins; i++){      
    //   H1HistoForEcalBin[i]->Reset();      
    // }

  //     for(int i=0; i<nEBins; i++){
  //   for(int j=0; j<nH1Bins; j++){
  //     EprimHistoForEcalBinForH1Bin[i][j]->Reset();
  //   }
  // }

 D1VsEcalSumDensityWeightedHist->Reset();
 D0VsEcalSumDensityWeightedHist->Reset();
 H1VsEcalSumDensityWeightedHist->Reset();
 readPar1.close();
 }

 // cout<<"counts = "<<CountConexLike<<endl;

 } //end of zenith bins loop


 // EcalSumOVerEtauHistCheckTry->Draw();

}