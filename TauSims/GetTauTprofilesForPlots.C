#include <Math/Polynomial.h>  
#include <Math/Interpolator.h>
#include <TFile.h>

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

double densityATMProfile[Npts] = {1.23E-03, 1.11E-03, 1.01E-03, 9.09E-04, 8.19E-04, 7.36E-04, 6.60E-04, 5.90E-04, 5.25E-04, 4.66E-04, 4.13E-04, 3.64E-04, 3.11E-04, 2.66E-04, 2.27E-04, 1.94E-04, 1.65E-04, 1.41E-04, 1.21E-04, 1.03E-04, 8.80E-05, 7.49E-05, 6.37E-05, 5.43E-05, 4.63E-05, 3.95E-05, 3.37E-05, 2.88E-05, 2.46E-05, 2.10E-05, 1.80E-05, 1.0e-09};

double pressureATMProfile[Npts] = {1013.25, 898.7, 795.0, 701.1, 616.4, 540.2, 471.8, 410.6, 356.0, 307.4, 264.4, 226.3, 193.3, 165.1, 141.0, 120.4, 102.9, 87.87, 75.05, 64.10, 54.75, 46.78, 40.00, 34.22, 29.30, 25.11, 21.53, 18.47, 15.86, 13.63, 11.72, 0.001};

double temperatureATMProfile[Npts] = {288.15, 281.65, 275.15, 268.65, 262.15, 255.65, 249.15, 242.65, 236.15,229.65, 223.15, 216.65, 216.65, 216.65, 216.65, 216.65, 216.65, 216.65, 216.65, 216.65, 216.65, 217.65, 218.65, 219.65, 220.65, 221.65, 222.65, 223.65, 224.65, 225.65, 226.65, 100.0};


double LogDepth[Npts];

double HeightATMProfileReversed[Npts];
double LogDepthReversed[Npts];

const double kOverburdenSeaLevel = 1033;
const double atmosphere = 101325;



 //Start Plotting
void GetTauTprofilesForPlots(){

//Defining the root file in which analysis will be stored



   TH1D* TauHistlgEPrimaryAllGenEvents = new TH1D("TauHistlgEPrimaryAllGenEvents", "TauHistlgEPrimaryAllGenEvents", 100, 0, 13);
   TH1D* ZenithHistAllGenEvents = new TH1D("ZenithHistAllGenEvents", "ZenithHistAllGenEvents", 100, 110, 180);
   TH1D* GenDistanceHist = new TH1D("GenDistanceHist", "GenDistanceHist", 100, -55, 30);
   TH1D* EarthDistanceHist = new TH1D("EarthDistanceHist", "EarthDistanceHist", 100, -55, 0);
   TH1D* AtmoDistanceHist = new TH1D("AtmoDistanceHist", "AtmoDistanceHist",100, 0, 30);
   TH1D* D0Hist = new TH1D("D0Hist", "D0Hist", 100, 0, 30E3);
   TH1D* DecayDistanceHist = new TH1D("DecayDistanceHist","DecayDistanceHist", 100, 0, 100);

   
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
   TH1D* EcalSumHist = new TH1D("EcalSumHist", "EcalSumHist", 40, 16.5, 18.5);
   TH1D* EPrimEventsOfInterest = new TH1D("EPrimEventsOfInterest", "EPrimEventsOfInterest", 110, 16.5, 22);
   TH2D* EprimVsEcalHist = new TH2D("EprimVsEcalHist", "EprimVsEcalHist", 110, 16.5, 22, 40, 16.5, 18.5);

   TH2D* D1VsEcalSumHist = new TH2D("D1VsEcalSumHist", "D1VsEcalSumHist",300, 0, 30E3, 40, 16.5, 18.5 );
   TH2D* D0VsEcalSumHist = new TH2D("D0VsEcalSumHist", "D0VsEcalSumHist", 300, 0, 30E3, 40, 16.5, 18.5);
   //TH2D* D1VsEcalSumHistWeightedEvPerZenithPerEbin = new TH2D("D1VsEcalSumHistWeightedEvPerZenithPerEbin", "D1VsEcalSumHistWeightedEvPerZenithPerEbin",300, 0, 30E3, 40, 16.5, 18.5 );
   TH2D* D1VsEcalSumHistWeightedEvPerZenithbin = new TH2D("D1VsEcalSumHistWeightedEvPerZenithbin", "D1VsEcalSumHistWeightedEvPerZenithbin",300, 0, 30E3, 40, 16.5, 18.5 );

   TH1D* EprimEarthGenEarthDecayed = new TH1D("EprimEarthGenEarthDecayed","EprimEarthGenEarthDecayed", 20, 7.5, 13);
   TH1D* EprimEarthGen = new TH1D("EprimEarthGen","EprimEarthGen", 20, 7.5, 13);
   TH1D* EprimEarthGenEarthKilled = new TH1D("EprimEarthGenEarthKilled", "EprimEarthGenEarthKilled", 20, 7.5, 13);
   TH1D* EprimAtmoGen = new TH1D("EprimAtmoGen", "EprimAtmoGen", 20, 7.5, 13);

   TH1D* EdecayEarthGenExitEarth = new TH1D("EdecayEarthGenExitEarth","EdecayEarthGenExitEarth", 20, 7.5, 13);
   TH1D* EdecayEarthGenDecayAtmoHist = new TH1D("EdecayEarthGenDecayAtmoHist", "EdecayEarthGenDecayAtmoHist", 20, 7.5, 13);
   TH1D* EprimEarthGenExitEarth = new TH1D("EprimEarthGenExitEarth", "EprimEarthGenExitEarth", 20, 7.5, 13);
   TH1D* EprimEarthGenNoAtmo = new TH1D("EprimEarthGenNoAtmo","EprimEarthGenNoAtmo", 20, 7.5, 13);

   TH2D* DecayDistanceWithRespectToEarthVsEprimTauHistEvEarthGen = 
            new TH2D("DecayDistanceWithRespectToEarthVsEprimTauHistEvEarthGen", 
                     "DecayDistanceWithRespectToEarthVsEprimTauHistEvEarthGen", 160, -50, 30, 350, 16.5 ,20);
  TH2D* DecayDistanceWithRespectToEarthVsEprimTauHistEvAtmoGen = 
            new TH2D("DecayDistanceWithRespectToEarthVsEprimTauHistEvAtmoGen", 
                     "DecayDistanceWithRespectToEarthVsEprimTauHistEvAtmoGen", 160, -50, 30, 350, 16.5 ,20);
  TH2D* DecayDistanceWithRespectToEarthVsEprimTauHistAllDecayingEvInAtmo = 
            new TH2D("DecayDistanceWithRespectToEarthVsEprimTauHistAllDecayingEvInAtmo", 
                     "DecayDistanceWithRespectToEarthVsEprimTauHistAllDecayingEvInAtmo", 160, -50, 30, 350, 16.5 ,20);


  TH2D* DecayDistanceWithRespectToEarthVsEdecayTauHistEvEarthGen = 
            new TH2D("DecayDistanceWithRespectToEarthVsEdecayTauHistEvEarthGen", 
                     "DecayDistanceWithRespectToEarthVsEdecayTauHistEvEarthGen", 160, -50, 30, 350, 16.5 ,20);
  TH2D* DecayDistanceWithRespectToEarthVsEdecayTauHistEvAtmoGen = 
            new TH2D("DecayDistanceWithRespectToEarthVsEdecayTauHistEvAtmoGen", 
                     "DecayDistanceWithRespectToEarthVsEdecayTauHistEvAtmoGen", 160, -50, 30, 350, 16.5 ,20);
  TH2D* DecayDistanceWithRespectToEarthVsEdecayTauHistAllDecayingEvInAtmo = 
            new TH2D("DecayDistanceWithRespectToEarthVsEdecayTauHistAllDecayingEvInAtmo", 
                     "DecayDistanceWithRespectToEarthVsEdecayTauHistAllDecayingEvInAtmo", 160, -50, 30, 350, 16.5 ,20);
                       
            


   double sumAtmoExitEvents = 0;
   double sumKilledEvents = 0;

   vector<double> EventIdVector;
   vector<double> EprimVector;
   vector<double> EcalSumVector;
   vector<double> D1Vector;

   const double D1maxAbove = 9/fabs(cos(110 * PI/180)) * 1E3; //in m
   cout<<"D1Max: "<<D1maxAbove<<endl;
 
  const int nEBins = 8;

  //all visible event: i.e gen both inside Earth and in atmo
  // TH1F* D1EnergyBins[nEBins];
  // string nameD1Hist[nEBins];

  // string name;
  // std::stringstream ss;

  // for(int i = 0; i < nEBins; ++i){
  //   ss.clear();
  //   ss.str(std::string());
  //   ss << "D1HistEbin_" << i;
  //   name = ss.str();
  //   nameD1Hist[i] = name;
  //   D1EnergyBins[i] = new TH1F(name.c_str(), "", 60, 0, 30E3);

  // } 

  //only events generated in the atmo (make parametrization in steps -> easier (expect 2 diff function for ev gen inside Earth and in atmo))
  // TH1F* D1AtmoGenEnergyBins[nEBins];
  // string nameD1AtmoGenHist[nEBins];

  // string name2;
  // std::stringstream ss2;

  // for(int i = 0; i < nEBins; ++i){
  //   ss2.clear();
  //   ss2.str(std::string());
  //   ss2 << "AtmoGenD1HistEbin_" << i;
  //   name2 = ss2.str();
  //   nameD1AtmoGenHist[i] = name2;
  //   D1AtmoGenEnergyBins[i] = new TH1F(name2.c_str(), "", 60, 0, 30E3);
  // } 


  // TH1F* D1EarthGenEnergyBins[nEBins];
  // string nameD1EarthGenHist[nEBins];

  // string name3;
  // std::stringstream ss3;

  // for(int i = 0; i < nEBins; ++i){
  //   ss3.clear();
  //   ss3.str(std::string());
  //   ss3 << "EarthGenD1HistEbin_" << i;
  //   name3 = ss3.str();
  //   nameD1EarthGenHist[i] = name3;
  //   D1EarthGenEnergyBins[i] = new TH1F(name3.c_str(), "", 60, 0, 30E3);

  // }


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
}

ROOT::Math::Interpolator interLogDepthVsHeight(Npts, ROOT::Math::Interpolation::kAKIMA );
interLogDepthVsHeight.SetData (Npts, HeightATMProfile, LogDepth);

//reverse the elements of height and depth, as since depth is going to be on x axis, it has to always have increasing values
for(int i=Npts-1; i>=0; i--)
  {HeightATMProfileReversed[Npts-i-1] =HeightATMProfile[i];
  LogDepthReversed[Npts-i-1] = LogDepth[i];}

ROOT::Math::Interpolator interHeightVsLogDepth(Npts, ROOT::Math::Interpolation::kAKIMA );
interHeightVsLogDepth.SetData (Npts, LogDepthReversed, HeightATMProfileReversed);


  ifstream readPar1;
 // readPar1.open("TauSimTotal1E9EvFromPleiades/1E8Events_LmaxInside50km_TauSimSet_0_1E8Ev_Test1DSim_E16.5-22_LmaxBelowEarth50km_Elim16.5_info_reg0_0.dat");
   //begin zenith bins loop
for(int iZenithBinIterator = 0; iZenithBinIterator<NZenithBins; iZenithBinIterator++)
 {if(iZenithBinIterator == NZenithBins-1)
   { //zenithVal = ZenithValues[iZenithBinIterator]; 
    zenithVal = 180;
      //create 1 tfile/zenith bin
   ssTfile.clear();
   ssTfile.str(std::string());
   ssTfile << "BullshitDelete_" << iZenithBinIterator<<".root";
   nameTfile = ssTfile.str();
   nameTfileZenith[iZenithBinIterator] = nameTfile;
   AnalysisHistosRootFile[iZenithBinIterator] = new TFile(nameTfile.c_str(), "RECREATE");
   // TTree *VectorsTree =new TTree("VectorsTree","VectorsTree");
   // VectorsTree->Branch("lgEPrim",&EprimVector);
   // VectorsTree->Branch("lgEcalSum",&EcalSumVector);
   // VectorsTree->Branch("D1", &D1Vector);
   // VectorsTree->Branch("EvID", &EventIdVector);
   cout<<"creating file: "<<nameTfile.c_str()<<endl;
   

     cout<<"ZenithVal sssss = "<<zenithVal<<endl;
   readPar1.open("1E7Ev_Test1DSim_E16.5-22_LmaxBelowEarth50km_Elim16.5_info_reg0_0.dat");
 cout<<"here?"<<endl;
   readPar1>>nEvents;
   getline(readPar1, holder);
   getline(readPar1, holder);
 
   for(int i=0; i<nEvents;i++)
     { 
      readPar1>>evnr>>eprimtau>>zenith>>dgen>>dearth>>datmo>>dtotal>>etaudecay>>epiminus>>epiplus>>epi0>>eKminus>>eKplus>>eK0>>eelectron;
      
      if(evnr - (int)evnr!=0)
        {cout<<"wrong entry for ev:"<<i<<" This should only happen if the random nr is set to 0. it only happened 1 time in 1E8 events. 
                  Instead of event nr it is: "<<evnr<<endl;
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
  
      // tree->Fill();
  
  
      //histograms
  
      TauHistlgEPrimaryAllGenEvents->Fill(lgEprimTau);
      ZenithHistAllGenEvents->Fill(Zenith);
      GenDistanceHist->Fill(GenDistance);
  
  
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
  
   
  
  
      if(EarthGenEv == true){     //Events generated inside Earth
        EarthDistanceHist->Fill(EarthDistance);
        if(ExitAtmoWithNoDecay == false){
          if(EarthDecayedEv==true){
            EprimEarthGenEarthDecayed->Fill(lgEprimTau);
          }
          if(KilledEv==true){
            EprimEarthGenEarthKilled->Fill(lgEprimTau);
          }
         }
          if(KilledEv == false  &&  EarthDecayedEv == false){
            EdecayEarthGenExitEarth->Fill(lgTauDecayEnergy);
            EprimEarthGenExitEarth->Fill(lgEprimTau);
          }
          else{
            EprimEarthGenNoAtmo->Fill(lgEprimTau);
          }
  
      }

      if(ExitAtmoWithNoDecay == true)
        sumAtmoExitEvents+=1;
      if(KilledEv == true)
        sumKilledEvents+=1;

     //uncomment if interested in any variables regarding only events gen in the atmosphere 
     // else{ //ev gen inside atmo
  
     // }

      //=======Events with Eprim<=10^20 eV

      if(lgEprimTau+9 <= 20){

        //Events Gen Inside Earth Decaying
        if(EarthGenEv == true && KilledEv ==false && ExitAtmoWithNoDecay == false){

          if(EarthDecayedEv == true){//decay inside Earth{
            DecayDistanceWithRespectToEarthVsEprimTauHistEvEarthGen->Fill(-( fabs(GenDistance) - fabs(EarthDistance) ), lgEprimTau+9);
            DecayDistanceWithRespectToEarthVsEdecayTauHistEvEarthGen->Fill(-( fabs(GenDistance) - fabs(EarthDistance) ), lgTauDecayEnergy+9);
          }
            
          
          else{//decay in atmo in Fd-FoV
            DecayDistanceWithRespectToEarthVsEprimTauHistEvEarthGen->Fill(AtmoDistance, lgEprimTau+9);
            DecayDistanceWithRespectToEarthVsEdecayTauHistEvEarthGen->Fill(AtmoDistance, lgTauDecayEnergy+9);
          }

        }


        //Events Gen In the Atmo Decaying in FD-FoV
        if(EarthGenEv == false && ExitAtmoWithNoDecay == false){
          DecayDistanceWithRespectToEarthVsEprimTauHistEvAtmoGen->Fill(AtmoDistance, lgEprimTau+9);
          DecayDistanceWithRespectToEarthVsEdecayTauHistEvAtmoGen->Fill(AtmoDistance, lgTauDecayEnergy+9);
        }
        //All events decaying in FD-FoB
        if(EarthDecayedEv == false  &&  KilledEv == false  &&  ExitAtmoWithNoDecay == false){      
          DecayDistanceWithRespectToEarthVsEprimTauHistAllDecayingEvInAtmo->Fill(AtmoDistance, lgEprimTau+9);
          DecayDistanceWithRespectToEarthVsEdecayTauHistAllDecayingEvInAtmo->Fill(AtmoDistance, lgTauDecayEnergy+9);
        }
      
      }


      // if(ExitAtmoWithNoDecay == false){ //no events exitting atmo with no decay
        
      //   DecayDistanceHist->Fill(DecayDistance);
      //   if(EarthDecayedEv == false  &&  KilledEv == false){ //only events which decay in the atmo (no matter wehere generated)
      //     AtmoDistanceHist->Fill(AtmoDistance);
      //     if(EarthGenEv == false){ //events generated and decayed in atmo
      //       DecayDistanceFromEarth = AtmoDistance;
      //      // DecayDistanceWithRespectToEarthVsEprimTauHistEvAtmoGenAndEarthGen->Fill(DecayDistanceFromEarth, lgEprimTau);
      //       p2dSeparate->Fill(DecayDistanceFromEarth, lgEprimTau, lgTauDecayEnergy);
  
      //     }
      //   }
      //   if(EarthDecayedEv == true && KilledEv == false ){
      //     DecayDistanceFromEarth = -( fabs(GenDistance) - fabs(EarthDistance) ); 
     
      //    // DecayDistanceWithRespectToEarthVsEprimTauHistEvAtmoGenAndEarthGen->Fill(DecayDistanceFromEarth, lgEprimTau);
      //     p2dSeparate->Fill(DecayDistanceFromEarth, lgEprimTau, lgTauDecayEnergy);
  
      //     p2dAll->Fill(DecayDistanceFromEarth, lgEprimTau, lgTauDecayEnergy);
      //     DecayDistanceWithRespectToEarthVsEprimTauHistAllEv->Fill(DecayDistanceFromEarth, lgEprimTau);
      //   }
  
      // }
  
  
      // if(EarthDecayedEv == false  &&  KilledEv == false  &&  ExitAtmoWithNoDecay == false) //all of the events that decayed in the atmosphere, no matter where they were produced
      // {
      //   DecayDistanceFromEarth = AtmoDistance;
      //   DecayDistanceWithRespectToEarthVsEprimTauHistAllEv->Fill(DecayDistanceFromEarth, lgEprimTau);
      //   p2dAll->Fill(DecayDistanceFromEarth, lgEprimTau, lgTauDecayEnergy);
  
      //   if(EcalSum!=0){
  
      //     //weights calculation
      //     weightPiPlus = (PiPlusEnergy) / EcalSum;
      //     weightPiMinus = (PiMinusEnergy) / EcalSum;
      //     weightPi0 = (Pi0Energy) / EcalSum;
      //     weightKMinus = (KMinusEnergy) / EcalSum;
      //     weightKPlus = (KPlusEnergy) / EcalSum;
      //     weightK0 = (K0Energy) / EcalSum;
      //     weightElectron = (ElectronEnergy) / EcalSum;
  
      //     //==============Xvert0 (corresponding to H0+1.4 km --> takes into account the height above sea level (Offline Parametrization))========
          
  
      //     //here loop over the zenith bins
  
      //     H0 = AtmoDistance * (-1) * cos(zenithVal * PI/180) *1E3; //H0 in m 
      //     if( (H0+1400) <= HeightATMProfile[Npts-1] )
      //       LogXVert0 = interLogDepthVsHeight.Eval(H0 + 1400);
          
          
      //     Xvert0 = exp(LogXVert0);
      //     //cout<<"check: "<<Xvert0<<" hegith: "<<H0<<endl;
  
      //     Xvert0Hist->Fill(Xvert0);
      //   // Calculate average X1 for charged pions and Kaons as a function of energy, as taken from CONEX
      //     lgEcaleV = log10(EcalSum) + 9;
      //     avX1PiCharged = P0X1PiConexFit + P1X1PiConexFit * lgEcaleV + P2X1PiConexFit * pow(lgEcaleV,2) + P3X1PiConexFit * pow(lgEcaleV,3);
      //     avX1K = avX1PiCharged;
  
      //     //cout<<"check Pi average int length: "<<avX1PiCharged<<" at lgE / eV = "<<lgEcaleV<<" lgE / GeV: "<<log10(EcalSum)<<endl;
  
      //    //get X1 from exponential distribution of average X1 corresp to each secondaries: x 100 for each event
  
      //     for(int j=0; j<NrOfX1Generation; j++){
  
      //       X1FromExpDistribPiCharged=random->Exp(avX1PiCharged);
      //       X1FromExpDistribPi0=random->Exp(avX1Pi0);
      //       X1FromExpDistribK=random->Exp(avX1K);
      //       X1FromExpDistribElectron=random->Exp(avX1Electron);
  
      //       X1FromExpDistrib=X1FromExpDistribPiCharged * (weightPiPlus + weightPiMinus) + X1FromExpDistribPi0 * weightPi0+
      //                         X1FromExpDistribK * (weightK0 + weightKMinus + weightKPlus) + X1FromExpDistribElectron * weightElectron;
  
      //       X1FromExpDistribHist->Fill(X1FromExpDistrib, 1/NrOfX1Generation);
  
      //       X1FromExpDistribVert=X1FromExpDistrib*(-1) * cos(zenithVal * PI/180);
      //       X1FromExpDistribVertFinal = Xvert0 - X1FromExpDistribVert; //xvert from top to bottom.
  
      //       if(X1FromExpDistribVertFinal>=exp(LogDepth[Npts-1])){ //else it is out of the atmo
                      
      //         X1FromExpDistribVertFinalHist->Fill(X1FromExpDistribVertFinal, 1/NrOfX1Generation);
      //         //========get to H from Xvertical===== 
              
      //         H1=interHeightVsLogDepth.Eval(log(X1FromExpDistribVertFinal)) - 1400;
            
      //         H1Hist->Fill(H1, 1/NrOfX1Generation);
              
      //         D1 = H1 / ( (-1) * cos(zenithVal * PI/180) );
  
      //         if(EarthGenEv == true)
      //           {EprimEarthGen->Fill(lgEprimTau, 1/NrOfX1Generation);
      //             EdecayEarthGenDecayAtmoHist->Fill(lgTauDecayEnergy, 1/NrOfX1Generation);
      //           }            
      //         else
      //           {EprimAtmoGen->Fill(lgEprimTau, 1/NrOfX1Generation);}
               
  
      //         if(log10(EcalSum)>= 7.5 && log10(EcalSum)<=9.5 && D1<=D1maxAbove){
      //           if( (log10(EcalSum)+9) > 18 && (log10(EcalSum)+9) < 18.05 && H1>=0 && H1<500  )
      //           //cout<<"check it got here2"<<endl;
      //             { D0Hist->Fill(AtmoDistance*1E3);
      //               D1Hist->Fill(D1, 1/NrOfX1Generation);
      //               EcalSumHist->Fill(log10(EcalSum) + 9, 1/NrOfX1Generation);
      //               EPrimEventsOfInterest->Fill(lgEprimTau + 9, 1/NrOfX1Generation);
      //               EprimVsEcalHist->Fill(lgEprimTau + 9, log10(EcalSum) + 9, 1/NrOfX1Generation );
      //               EventIdVector.push_back(eventId);
      //               EprimVector.push_back(lgEprimTau + 9);
      //               EcalSumVector.push_back(log10(EcalSum) + 9);
      //               D1Vector.push_back(D1);
                     
      //               D1VsEcalSumHist->Fill(D1, log10(EcalSum)+9, 1/NrOfX1Generation);
      //               D0VsEcalSumHist->Fill(AtmoDistance*1E3, log10(EcalSum)+9, 1/NrOfX1Generation);
     
      //               //cout<<"atmo dista: "<<AtmoDistance*1E3<<" D1: "<<D1<<endl;
      //                //D1VsEcalSumHistWeightedEvPerZenithPerEbin->Fill(D1, log10(EcalSum)+9, 1/NrOfX1Generation); //lgE/ev
      //               D1VsEcalSumHistWeightedEvPerZenithbin->Fill(D1, log10(EcalSum)+9, 1/NrOfX1Generation); //lgE /ev
                               
       
      //                //try to make D1 histos for each 0.25 lg E bin
      
      //                // double EnergyDiff = (log10(EcalSum) - 7.5) *4;
      //                // //cout<<"Ecal: "<<log10(EcalSum)<<endl;
      //                // int nE = (int) EnergyDiff;
      //                // //cout<<"nE: "<<nE<<endl;
      //                // D1EnergyBins[nE]->Fill(D1, 1/NrOfX1Generation);
       
      //                // if(EarthGenEv == true)
      //                //   D1EarthGenEnergyBins[nE]->Fill(D1, 1/NrOfX1Generation);
      //                // else
      //                //   D1AtmoGenEnergyBins[nE]->Fill(D1, 1/NrOfX1Generation);
      //             }
  
      //         }
  
      //       }
  
      //     }
  
  
      //   }
  
      // }
  
 //VectorsTree->Fill();
//cout<<"ev: "<<evnr<<endl;

  }

// cout<<"KilledEv: "<<sumKilledEvents<<" ExitAtmoEv: "<<sumAtmoExitEvents<<endl;
  
//   double Nscale = 1/(D1VsEcalSumHist->Integral());
  
//   D1VsEcalSumHistWeightedEvPerZenithbin->Scale(Nscale);
//   double binContent;
//   double EventsInEbinScaledIntegral = 0;
//   double ZenithBin=18;
  
//   double TotalBinsD1Energy = D1VsEcalSumHistWeightedEvPerZenithbin->GetXaxis()->GetNbins() * D1VsEcalSumHistWeightedEvPerZenithbin->GetYaxis()->GetNbins();
//   double D1Bins = D1VsEcalSumHistWeightedEvPerZenithbin->GetXaxis()->GetNbins();
//   double lgEbins =  D1VsEcalSumHistWeightedEvPerZenithbin->GetYaxis()->GetNbins();
  
//   for(int ybins=1; ybins<=lgEbins; ybins++){
//     for(int xbins=1; xbins<=D1Bins; xbins++){
//       // if(D1VsEcalSumHistWeightedEvPerZenithPerEbin->GetBinContent(xbins,ybins)!=0)  
//         {//EventsInEbinScaledIntegral+= D1VsEcalSumHistWeightedEvPerZenithPerEbin->GetBinContent(xbins,ybins);
//           binContent = D1VsEcalSumHistWeightedEvPerZenithbin->GetBinContent(xbins,ybins);
//           D1VsEcalSumHistWeightedEvPerZenithbin->SetBinContent( xbins, ybins, binContent * (TotalBinsD1Energy) );
//         }
//     }
//   EventsInEbinScaledIntegral=0;
//   //cout<<"got here at  least"<<endl;
  
//   }
  
  
//   cout<<"Integral after re-weighting / ZenithBin: "<<D1VsEcalSumHistWeightedEvPerZenithbin->Integral()<<endl;
  
//   cout<<"Events/ZenithBin (protonADST) = "<<EventsPerZenithBin<<endl;
 
  
  
   //VectorsTree->Print();
  
    //cout<<endl; 
    cout<<"Done!"<<endl;
  
  


    
    //VectorsTree->Write();

    EprimVector.clear();
    EcalSumVector.clear();
    EventIdVector.clear();
    D1Vector.clear();
   
    
    DecayDistanceWithRespectToEarthVsEprimTauHistEvEarthGen->Write();
    DecayDistanceWithRespectToEarthVsEprimTauHistEvAtmoGen->Write();
    DecayDistanceWithRespectToEarthVsEprimTauHistAllDecayingEvInAtmo->Write();

    DecayDistanceWithRespectToEarthVsEdecayTauHistEvEarthGen->Write();
    DecayDistanceWithRespectToEarthVsEdecayTauHistEvAtmoGen->Write();
    DecayDistanceWithRespectToEarthVsEdecayTauHistAllDecayingEvInAtmo->Write();
  
   AnalysisHistosRootFile[iZenithBinIterator]->Write();
   AnalysisHistosRootFile[iZenithBinIterator]->Close();


 readPar1.close();
 }
 } //end of zenith bins loop


}