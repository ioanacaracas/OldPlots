/*
 * Plot.C
 *
 *  Created on: Dec 6, 2016
 *      Author: mayotte
 */
void ExposureCalcAllEAllAngles(){ //run via root Plot.C

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

  const Int_t NRGBs = 5;
  const Int_t NCont = 80;

  Double_t stops[9] = { 0.0000000000, 0.1250, 0.2500, 0.3750, 0.5000000000, 0.6250, 0.7500, 0.8750, 1.0000000000};
  Double_t red[9]   = { 0.2082, 0.0592, 0.0780, 0.0232, 0.1802, 0.5301, 0.8186, 0.9956, 0.9764};
  Double_t green[9] = { 0.1664, 0.3599, 0.5041, 0.6419, 0.7178, 0.7492, 0.7328, 0.7862, 0.9832};
  Double_t blue[9]  = { 0.5293, 0.8684, 0.8385, 0.7914, 0.6425, 0.4662, 0.3499, 0.1968, 0.0539};
  TColor::CreateGradientColorTable(9, stops, red, green, blue, NCont);
  gStyle->SetNumberContours(NCont);

  const double XRange[2] = {17.4,21};
  const double MeanRange[2] = {600,820};
  const double SigmaRange[2] = {0,100};


TFile *TauThetamin115H0 = new TFile("./Analysis50e3Events_TauE17_18.5_theta115-130_H0_CO_Heat.root  ","READ");
//TFile *TauThetamin120H0 = new TFile("./Analysis50e3Events_TauE17_17.5_theta120-125_H0_CO_Heat_COandHEAT.root ","READ");
//TFile *TauThetamin125H0 = new TFile("./Analysis50e3Events_TauE17_17.5_theta125-130_H0_CO_Heat_COandHEAT.root ","READ");





TauThetamin115H0->cd(); //change to file 1
  TGraphErrors *TriggeringEfficiencyThetamin115H0        = ((TGraphErrors*) TauThetamin115H0->Get("TriggeringEfficiency"));
  TVectorD *MeanDiffErecEmcThetamin115H0 =    ((TVectorD*) TauThetamin115H0->Get("MeanDiffErecEmc"));
  TVectorD *SigmaDiffErecEmcThetamin115H0 =    ((TVectorD*) TauThetamin115H0->Get("SigmaDiffErecEmc"));


  TGraphErrors *TriggeringEfficiencyCoihuecoThetamin115H0        = ((TGraphErrors*) TauThetamin115H0->Get("TriggeringEfficiencyCoihueco"));
  TVectorD *MeanDiffErecEmcCoihuecoThetamin115H0 =    ((TVectorD*) TauThetamin115H0->Get("MeanDiffErecEmcCoihueco"));
  TVectorD *SigmaDiffErecEmcCoihuecoThetamin115H0 =    ((TVectorD*) TauThetamin115H0->Get("SigmaDiffErecEmcCoihueco"));
  TVectorD *TriggeringEfficiencyCoihuecoValueThetamin115H0 = ((TVectorD*) TauThetamin115H0->Get("TriggEfficiencyCoihueco"));
  TVectorD *GeomEfficiencyCoihuecoValueThetamin115H0 = ((TVectorD*) TauThetamin115H0->Get("GeomEfficiencyCoihueco"));
  TVectorD *EnergyRecEfficiencyCoihuecoValueThetamin115H0 = ((TVectorD*) TauThetamin115H0->Get("EnergyRecEfficiencyCoihueco"));

  TH1F *HistoEnergylgErecThetamin115H0 = ((TH1F*) TauThetamin115H0->Get("HistoLgErecCoihueco"));
  TH1F *HistoLgEMCcorrespLgErecCoihuecoThetamin115H0 = ((TH1F*) TauThetamin115H0->Get("HistoLgEMCcorrespLgErecCoihueco"));

    // for COIHUECO: vectors with EvId, lgEMc, lgErec, Rp for all events: generated and triggered. generated but no triggered: EVID = 0.
    //Rp = -1, Erec = -1 for the events with no trigger or no geom/energy rec
  //if Rp!=-1 %% Rp!=0 -> geom reconstruction
  //if(pow(10, lgErec)!=0 && lgErec!=-1) -> energy rec
  TVectorD *RootVectorEVENTidCOThetamin115 = ((TVectorD*) TauThetamin115H0->Get("RootVectorEVENTidCO"));
  TVectorD *RootVectorlgEMCCOThetamin115 = ((TVectorD*) TauThetamin115H0->Get("RootVectorlgEMCCO"));
  TVectorD *RootVectorlgErecCOThetamin115 = ((TVectorD*) TauThetamin115H0->Get("RootVectorlgErecCO"));
  TVectorD *RootVectorRpCOThetamin115 = ((TVectorD*) TauThetamin115H0->Get("RootVectorRpCO"));
  TVectorD *RootVectorDistanceFdCOThetamin115  = ((TVectorD*) TauThetamin115H0->Get("RootVectorDistanceFdCO"));
  TVectorD *RootVectorGenDistanceFdCOThetamin115  = ((TVectorD*) TauThetamin115H0->Get("RootVectorGenDistanceFdCO"));
  TVectorD *RootVectorZenithCOThetamin115  = ((TVectorD*) TauThetamin115H0->Get("RootVectorZenith"));

  TVectorD *RootVectorEVENTidHEATThetamin115 = ((TVectorD*) TauThetamin115H0->Get("RootVectorEVENTidHEAT"));
  TVectorD *RootVectorlgEMCHEATThetamin115 = ((TVectorD*) TauThetamin115H0->Get("RootVectorlgEMCHEAT"));
  TVectorD *RootVectorlgErecHEATThetamin115 = ((TVectorD*) TauThetamin115H0->Get("RootVectorlgErecHEAT"));
  TVectorD *RootVectorRpHEATThetamin115 = ((TVectorD*) TauThetamin115H0->Get("RootVectorRpHEAT"));
  TVectorD *RootVectorDistanceFdHEATThetamin115  = ((TVectorD*) TauThetamin115H0->Get("RootVectorDistanceFdHEAT"));
  TVectorD *RootVectorGenDistanceFdHEATThetamin115  = ((TVectorD*) TauThetamin115H0->Get("RootVectorGenDistanceFdHEAT"));
  TVectorD *RootVectorZenithHEATThetamin115  = ((TVectorD*) TauThetamin115H0->Get("RootVectorZenithHEAT"));


 TGraphErrors *TriggeringEfficiencyHEATThetamin115H0        = ((TGraphErrors*) TauThetamin115H0->Get("TriggeringEfficiencyHEAT"));
  TVectorD *MeanDiffErecEmcHEATThetamin115H0 =    ((TVectorD*) TauThetamin115H0->Get("MeanDiffErecEmcHEAT"));
  TVectorD *SigmaDiffErecEmcHEATThetamin115H0 =    ((TVectorD*) TauThetamin115H0->Get("SigmaDiffErecEmcHEAT"));
  TVectorD *TriggeringEfficiencyHEATValueThetamin115H0 = ((TVectorD*) TauThetamin115H0->Get("TriggEfficiencyHEAT"));
  TVectorD *GeomEfficiencyHEATValueThetamin115H0 = ((TVectorD*) TauThetamin115H0->Get("GeomEfficiencyHEAT"));
  TVectorD *EnergyRecEfficiencyHEATValueThetamin115H0 = ((TVectorD*) TauThetamin115H0->Get("EnergyRecEfficiencyHEAT"));
  //TH1F *HistoTrigEvOverGenEventsThetamin115H0 = ((TH1F*) TauThetamin115H0->Get("CloneHisto"));
  TH1F *HistoEnergyDifferenceThetamin115H0 = ((TH1F*) TauThetamin115H0->Get("HistoDifferenceE"));
  TH1F *HistoEnergylgEmcThetamin115H0 = ((TH1F*) TauThetamin115H0->Get("HistoLgEMC"));


/*TauThetamin120H0->cd(); //change to file 1
  TGraphErrors *TriggeringEfficiencyThetamin120H0        = ((TGraphErrors*) TauThetamin120H0->Get("TriggeringEfficiency"));
  TVectorD *MeanDiffErecEmcThetamin120H0 =    ((TVectorD*) TauThetamin120H0->Get("MeanDiffErecEmc"));
  TVectorD *SigmaDiffErecEmcThetamin120H0 =    ((TVectorD*) TauThetamin120H0->Get("SigmaDiffErecEmc"));

  TGraphErrors *TriggeringEfficiencyCoihuecoThetamin120H0        = ((TGraphErrors*) TauThetamin120H0->Get("TriggeringEfficiencyCoihueco"));
  TVectorD *MeanDiffErecEmcCoihuecoThetamin120H0 =    ((TVectorD*) TauThetamin120H0->Get("MeanDiffErecEmcCoihueco"));
  TVectorD *SigmaDiffErecEmcCoihuecoThetamin120H0 =    ((TVectorD*) TauThetamin120H0->Get("SigmaDiffErecEmcCoihueco"));
  TVectorD *TriggeringEfficiencyCoihuecoValueThetamin120H0 = ((TVectorD*) TauThetamin120H0->Get("TriggEfficiencyCoihueco"));
  TVectorD *GeomEfficiencyCoihuecoValueThetamin120H0 = ((TVectorD*) TauThetamin120H0->Get("GeomEfficiencyCoihueco"));
  TVectorD *EnergyRecEfficiencyCoihuecoValueThetamin120H0 = ((TVectorD*) TauThetamin120H0->Get("EnergyRecEfficiencyCoihueco"));

 TGraphErrors *TriggeringEfficiencyHEATThetamin120H0        = ((TGraphErrors*) TauThetamin120H0->Get("TriggeringEfficiencyHEAT"));
  TVectorD *MeanDiffErecEmcHEATThetamin120H0 =    ((TVectorD*) TauThetamin120H0->Get("MeanDiffErecEmcHEAT"));
  TVectorD *SigmaDiffErecEmcHEATThetamin120H0 =    ((TVectorD*) TauThetamin120H0->Get("SigmaDiffErecEmcHEAT"));
  TVectorD *TriggeringEfficiencyHEATValueThetamin120H0 = ((TVectorD*) TauThetamin120H0->Get("TriggEfficiencyHEAT"));
  TVectorD *GeomEfficiencyHEATValueThetamin120H0 = ((TVectorD*) TauThetamin120H0->Get("GeomEfficiencyHEAT"));
  TVectorD *EnergyRecEfficiencyHEATValueThetamin120H0 = ((TVectorD*) TauThetamin120H0->Get("EnergyRecEfficiencyHEAT"));

  //TH1F *HistoTrigEvOverGenEventsThetamin120H0 = ((TH1F*) TauThetamin120H0->Get("CloneHisto"));
  TH1F *HistoEnergyDifferenceThetamin120H0 = ((TH1F*) TauThetamin120H0->Get("HistoDifferenceE"));
  TH1F *HistoEnergylgEmcThetamin120H0 = ((TH1F*) TauThetamin120H0->Get("HistoLgEMC"));


TauThetamin125H0->cd(); //change to file 1
  TGraphErrors *TriggeringEfficiencyThetamin125H0        = ((TGraphErrors*) TauThetamin125H0->Get("TriggeringEfficiency"));
  TVectorD *MeanDiffErecEmcThetamin125H0 =    ((TVectorD*) TauThetamin125H0->Get("MeanDiffErecEmc"));
  TVectorD *SigmaDiffErecEmcThetamin125H0 =    ((TVectorD*) TauThetamin125H0->Get("SigmaDiffErecEmc"));

  TGraphErrors *TriggeringEfficiencyCoihuecoThetamin125H0        = ((TGraphErrors*) TauThetamin125H0->Get("TriggeringEfficiencyCoihueco"));
  TVectorD *MeanDiffErecEmcCoihuecoThetamin125H0 =    ((TVectorD*) TauThetamin125H0->Get("MeanDiffErecEmcCoihueco"));
  TVectorD *SigmaDiffErecEmcCoihuecoThetamin125H0 =    ((TVectorD*) TauThetamin125H0->Get("SigmaDiffErecEmcCoihueco"));
  TVectorD *TriggeringEfficiencyCoihuecoValueThetamin125H0 = ((TVectorD*) TauThetamin125H0->Get("TriggEfficiencyCoihueco"));
  TVectorD *GeomEfficiencyCoihuecoValueThetamin125H0 = ((TVectorD*) TauThetamin125H0->Get("GeomEfficiencyCoihueco"));
  TVectorD *EnergyRecEfficiencyCoihuecoValueThetamin125H0 = ((TVectorD*) TauThetamin125H0->Get("EnergyRecEfficiencyCoihueco"));

 TGraphErrors *TriggeringEfficiencyHEATThetamin125H0        = ((TGraphErrors*) TauThetamin125H0->Get("TriggeringEfficiencyHEAT"));
  TVectorD *MeanDiffErecEmcHEATThetamin125H0 =    ((TVectorD*) TauThetamin125H0->Get("MeanDiffErecEmcHEAT"));
  TVectorD *SigmaDiffErecEmcHEATThetamin125H0 =    ((TVectorD*) TauThetamin125H0->Get("SigmaDiffErecEmcHEAT"));
  TVectorD *TriggeringEfficiencyHEATValueThetamin125H0 = ((TVectorD*) TauThetamin125H0->Get("TriggEfficiencyHEAT"));
  TVectorD *GeomEfficiencyHEATValueThetamin125H0 = ((TVectorD*) TauThetamin125H0->Get("GeomEfficiencyHEAT"));
  TVectorD *EnergyRecEfficiencyHEATValueThetamin125H0 = ((TVectorD*) TauThetamin125H0->Get("EnergyRecEfficiencyHEAT"));

  //TH1F *HistoTrigEvOverGenEventsThetamin125H0 = ((TH1F*) TauThetamin125H0->Get("CloneHisto"));
  TH1F *HistoEnergyDifferenceThetamin125H0 = ((TH1F*) TauThetamin125H0->Get("HistoDifferenceE"));
  TH1F *HistoEnergylgEmcThetamin125H0 = ((TH1F*) TauThetamin125H0->Get("HistoLgEMC"));

*/

vector<double> ErrorEvents;
vector<double> ErrorPointOnGraphExposurePlus;
vector<double> ErrorPointOnGraphExposureMinus;
vector<double> ErrorExposurePlus;
vector<double> ErrorExposureMinus;



int TotalNrGenEvents = RootVectorEVENTidCOThetamin115->GetNoElements();

vector<double> VectorEVENTidCOThetamin115;
vector<double> VectorlgEMCCOThetamin115;
vector<double> VectorlgErecCOThetamin115;
vector<double> VectorRpCOThetamin115;
vector<double> VectorDistanceFdCOThetamin115;
vector<double> VectorGenDistanceFdCOThetamin115;
vector<double> VectorZenithCOThetamin115;


vector<double> VectorEVENTidHEATThetamin115;
vector<double> VectorlgEMCHEATThetamin115;
vector<double> VectorlgErecHEATThetamin115;
vector<double> VectorRpHEATThetamin115;
vector<double> VectorDistanceFdHEATThetamin115;
vector<double> VectorGenDistanceFdHEATThetamin115;
vector<double> VectorZenithHEATThetamin115;

//save the vector from the tree: EventdId = 0 -> generated events but not triggered
//DistanceFdCO = -1 -> generated events but not triggered
//RpCO = -1 -> Generated events with NO geometry reconstruction
//lgErec=-1 -> Generated events with NO energy reconstruction
for(int i=0; i<TotalNrGenEvents; i++)
  {
    VectorEVENTidCOThetamin115.push_back( ((*RootVectorEVENTidCOThetamin115))[i] );
    VectorlgEMCCOThetamin115.push_back( ((*RootVectorlgEMCCOThetamin115))[i] );
    VectorlgErecCOThetamin115.push_back( ((*RootVectorlgErecCOThetamin115))[i] );
    VectorRpCOThetamin115.push_back( ((*RootVectorRpCOThetamin115))[i] );
    VectorDistanceFdCOThetamin115.push_back( ((* RootVectorDistanceFdCO))[i] );
    VectorGenDistanceFdCOThetamin115.push_back( ((* RootVectorGenDistanceFdCOThetamin115))[i] );
    VectorZenithCOThetamin115.push_back( ((* RootVectorZenithCOThetamin115))[i] );

        VectorEVENTidHEATThetamin115.push_back( ((*RootVectorEVENTidHEATThetamin115))[i] );
        VectorlgEMCHEATThetamin115.push_back( ((*RootVectorlgEMCHEATThetamin115))[i] );
        VectorlgErecHEATThetamin115.push_back( ((*RootVectorlgErecHEATThetamin115))[i] );
        VectorRpHEATThetamin115.push_back( ((*RootVectorRpHEATThetamin115))[i] );
        VectorDistanceFdHEATThetamin115.push_back( ((* RootVectorDistanceFdHEAT))[i] );
        VectorGenDistanceFdHEATThetamin115.push_back( ((* RootVectorGenDistanceFdHEATThetamin115))[i] );
        VectorZenithHEATThetamin115.push_back( ((* RootVectorZenithHEATThetamin115))[i] );

  }

//checking generated events for each energy bin
TH1F* HistoLgEMCTEST =  new TH1F("HistoLgEMCTEST", "HistoLgEMCTEST", 100, 16.9, 18.6);

for(int ihist=0; ihist<VectorlgEMCCOThetamin115.size(); ihist++)
{HistoLgEMCTEST->Fill(VectorlgEMCCOThetamin115[ihist]);
}

double TotalNrTriggEvents=0;
double TotalNrTriggEventsHEAT=0;

for(int i=0; i<VectorEVENTidCOThetamin115.size(); i++)
    {
      if(VectorEVENTidCOThetamin115[i]!=0)
        TotalNrTriggEvents+=1;
    }

for(int i=0; i<VectorEVENTidHEATThetamin115.size(); i++)
    {
      if(VectorEVENTidHEATThetamin115[i]!=0)
        TotalNrTriggEventsHEAT+=1;
    }

double trigeff = TotalNrTriggEvents/TotalNrGenEvents;
cout<<"TotalNrGenEvents: "<<TotalNrGenEvents<<" TotalNrTriggEvents CO "<<TotalNrTriggEvents<<" trigg efficiency CO "<<trigeff<<endl;
cout<<"TotalNrGenEvents: "<< RootVectorEVENTidHEATThetamin115->GetNoElements()<<" TotalNrTriggEvents HEAT"<<TotalNrTriggEventsHEAT
		<<" trigg efficiency HEAT "<<TotalNrTriggEventsHEAT / ( RootVectorEVENTidHEATThetamin115->GetNoElements() )<<endl;


double EventsWithErecCOEMCmax171 = 0; //first range: [17-17.1)
double GeneratedEventsEMCmax171 = 0;
double EventsWithErecCOEMCmax171RFdgt1km = 0; //first range: [17-17.1)
double GeneratedEventsEMCmax171RFdgt1km = 0;
double EventsWithErecCOEMCmax171RFdgt2km = 0;
double GeneratedEventsEMCmax171RFdgt2km = 0;
double EventsWithErecCOEMCmax171RFdgt3km = 0;
double GeneratedEventsEMCmax171RFdgt3km = 0;
double EventsWithErecCOEMCmax171RFdgt4km = 0;
double GeneratedEventsEMCmax171RFdgt4km = 0;
double EventsWithErecCOEMCmax171RFdgt5km = 0;
double GeneratedEventsEMCmax171RFdgt5km = 0;
double EventsWithErecHEATEMCmax171 = 0; //first range: [17-17.1)
double EventsWithErecHEATEMCmax171RFdgt1km = 0; //first range: [17-17.1)
double EventsWithErecHEATEMCmax171RFdgt2km = 0;
double EventsWithErecHEATEMCmax171RFdgt3km = 0;
double EventsWithErecHEATEMCmax171RFdgt4km = 0;
double EventsWithErecHEATEMCmax171RFdgt5km = 0;


double EventsWithErecCOEMCmax172 = 0; //2nd range: [17.1-17.2)
double GeneratedEventsEMCmax172 = 0;
double EventsWithErecCOEMCmax172RFdgt1km = 0;
double GeneratedEventsEMCmax172RFdgt1km = 0;
double EventsWithErecCOEMCmax172RFdgt2km = 0;
double GeneratedEventsEMCmax172RFdgt2km = 0;
double EventsWithErecCOEMCmax172RFdgt3km = 0;
double GeneratedEventsEMCmax172RFdgt3km = 0;
double EventsWithErecCOEMCmax172RFdgt4km = 0;
double GeneratedEventsEMCmax172RFdgt4km = 0;
double EventsWithErecCOEMCmax172RFdgt5km = 0;
double GeneratedEventsEMCmax172RFdgt5km = 0;
double EventsWithErecHEATEMCmax172 = 0; //first range: [17-17.1)
double EventsWithErecHEATEMCmax172RFdgt1km = 0; //first range: [17-17.1)
double EventsWithErecHEATEMCmax172RFdgt2km = 0;
double EventsWithErecHEATEMCmax172RFdgt3km = 0;
double EventsWithErecHEATEMCmax172RFdgt4km = 0;
double EventsWithErecHEATEMCmax172RFdgt5km = 0;


double EventsWithErecCOEMCmax173 = 0; //3rd range: 17.2-17.3
double GeneratedEventsEMCmax173 = 0;
double EventsWithErecCOEMCmax173RFdgt1km = 0;
double GeneratedEventsEMCmax173RFdgt1km = 0;
double EventsWithErecCOEMCmax173RFdgt2km = 0;
double GeneratedEventsEMCmax173RFdgt2km = 0;
double EventsWithErecCOEMCmax173RFdgt3km = 0;
double GeneratedEventsEMCmax173RFdgt3km = 0;
double EventsWithErecCOEMCmax173RFdgt4km = 0;
double GeneratedEventsEMCmax173RFdgt4km = 0;
double EventsWithErecCOEMCmax173RFdgt5km = 0;
double GeneratedEventsEMCmax173RFdgt5km = 0;
double EventsWithErecHEATEMCmax173 = 0; //first range: [17-17.1)
double EventsWithErecHEATEMCmax173RFdgt1km = 0; //first range: [17-17.1)
double EventsWithErecHEATEMCmax173RFdgt2km = 0;
double EventsWithErecHEATEMCmax173RFdgt3km = 0;
double EventsWithErecHEATEMCmax173RFdgt4km = 0;
double EventsWithErecHEATEMCmax173RFdgt5km = 0;

double EventsWithErecCOEMCmax174 = 0; //3rd range: 17.3-17.4
double GeneratedEventsEMCmax174 = 0;
double EventsWithErecCOEMCmax174RFdgt1km = 0;
double GeneratedEventsEMCmax174RFdgt1km = 0;
double EventsWithErecCOEMCmax174RFdgt2km = 0;
double GeneratedEventsEMCmax174RFdgt2km = 0;
double EventsWithErecCOEMCmax174RFdgt3km = 0;
double GeneratedEventsEMCmax174RFdgt3km = 0;
double EventsWithErecCOEMCmax174RFdgt4km = 0;
double GeneratedEventsEMCmax174RFdgt4km = 0;
double EventsWithErecCOEMCmax174RFdgt5km = 0;
double GeneratedEventsEMCmax174RFdgt5km = 0;
double EventsWithErecHEATEMCmax174 = 0; //first range: [17-17.1)
double EventsWithErecHEATEMCmax174RFdgt1km = 0; //first range: [17-17.1)
double EventsWithErecHEATEMCmax174RFdgt2km = 0;
double EventsWithErecHEATEMCmax174RFdgt3km = 0;
double EventsWithErecHEATEMCmax174RFdgt4km = 0;
double EventsWithErecHEATEMCmax174RFdgt5km = 0;

double EventsWithErecCOEMCmax175 = 0; //3rd range: 17.4-17.5
double GeneratedEventsEMCmax175 = 0;
double EventsWithErecCOEMCmax175RFdgt1km = 0;
double GeneratedEventsEMCmax175RFdgt1km = 0;
double EventsWithErecCOEMCmax175RFdgt2km = 0;
double GeneratedEventsEMCmax175RFdgt2km = 0;
double EventsWithErecCOEMCmax175RFdgt3km = 0;
double GeneratedEventsEMCmax175RFdgt3km = 0;
double EventsWithErecCOEMCmax175RFdgt4km = 0;
double GeneratedEventsEMCmax175RFdgt4km = 0;
double EventsWithErecCOEMCmax175RFdgt5km = 0;
double GeneratedEventsEMCmax175RFdgt5km = 0;
double EventsWithErecHEATEMCmax175 = 0; //first range: [17-17.1)
double EventsWithErecHEATEMCmax175RFdgt1km = 0; //first range: [17-17.1)
double EventsWithErecHEATEMCmax175RFdgt2km = 0;
double EventsWithErecHEATEMCmax175RFdgt3km = 0;
double EventsWithErecHEATEMCmax175RFdgt4km = 0;
double EventsWithErecHEATEMCmax175RFdgt5km = 0;



double EventsWithErecCOEMCmax176 = 0; //3rd range: 17.5-17.6
double GeneratedEventsEMCmax176 = 0;
double EventsWithErecCOEMCmax176RFdgt1km = 0;
double GeneratedEventsEMCmax176RFdgt1km = 0;
double EventsWithErecCOEMCmax176RFdgt2km = 0;
double GeneratedEventsEMCmax176RFdgt2km = 0;
double EventsWithErecCOEMCmax176RFdgt3km = 0;
double GeneratedEventsEMCmax176RFdgt3km = 0;
double EventsWithErecCOEMCmax176RFdgt4km = 0;
double GeneratedEventsEMCmax176RFdgt4km = 0;
double EventsWithErecCOEMCmax176RFdgt5km = 0;
double GeneratedEventsEMCmax176RFdgt5km = 0;
double EventsWithErecHEATEMCmax176 = 0; //first range: [17-17.1)
double EventsWithErecHEATEMCmax176RFdgt1km = 0; //first range: [17-17.1)
double EventsWithErecHEATEMCmax176RFdgt2km = 0;
double EventsWithErecHEATEMCmax176RFdgt3km = 0;
double EventsWithErecHEATEMCmax176RFdgt4km = 0;
double EventsWithErecHEATEMCmax176RFdgt5km = 0;

double EventsWithErecCOEMCmax177 = 0; //3rd range: 17.6-17.7
double GeneratedEventsEMCmax177 = 0;
double EventsWithErecCOEMCmax177RFdgt1km = 0;
double GeneratedEventsEMCmax177RFdgt1km = 0;
double EventsWithErecCOEMCmax177RFdgt2km = 0;
double GeneratedEventsEMCmax177RFdgt2km = 0;
double EventsWithErecCOEMCmax177RFdgt3km = 0;
double GeneratedEventsEMCmax177RFdgt3km = 0;
double EventsWithErecCOEMCmax177RFdgt4km = 0;
double GeneratedEventsEMCmax177RFdgt4km = 0;
double EventsWithErecCOEMCmax177RFdgt5km = 0;
double GeneratedEventsEMCmax177RFdgt5km = 0;
double EventsWithErecHEATEMCmax177 = 0; //first range: [17-17.1)
double EventsWithErecHEATEMCmax177RFdgt1km = 0; //first range: [17-17.1)
double EventsWithErecHEATEMCmax177RFdgt2km = 0;
double EventsWithErecHEATEMCmax177RFdgt3km = 0;
double EventsWithErecHEATEMCmax177RFdgt4km = 0;
double EventsWithErecHEATEMCmax177RFdgt5km = 0;


double EventsWithErecCOEMCmax178 = 0; //3rd range: 17.7-17.8
double GeneratedEventsEMCmax178 = 0;
double EventsWithErecCOEMCmax178RFdgt1km = 0;
double GeneratedEventsEMCmax178RFdgt1km = 0;
double EventsWithErecCOEMCmax178RFdgt2km = 0;
double GeneratedEventsEMCmax178RFdgt2km = 0;
double EventsWithErecCOEMCmax178RFdgt3km = 0;
double GeneratedEventsEMCmax178RFdgt3km = 0;
double EventsWithErecCOEMCmax178RFdgt4km = 0;
double GeneratedEventsEMCmax178RFdgt4km = 0;
double EventsWithErecCOEMCmax178RFdgt5km = 0;
double GeneratedEventsEMCmax178RFdgt5km = 0;
double EventsWithErecHEATEMCmax178 = 0; //first range: [17-17.1)
double EventsWithErecHEATEMCmax178RFdgt1km = 0; //first range: [17-17.1)
double EventsWithErecHEATEMCmax178RFdgt2km = 0;
double EventsWithErecHEATEMCmax178RFdgt3km = 0;
double EventsWithErecHEATEMCmax178RFdgt4km = 0;
double EventsWithErecHEATEMCmax178RFdgt5km = 0;

double EventsWithErecCOEMCmax179 = 0; //3rd range: 17.8-17.9
double GeneratedEventsEMCmax179 = 0;
double EventsWithErecCOEMCmax179RFdgt1km = 0;
double GeneratedEventsEMCmax179RFdgt1km = 0;
double EventsWithErecCOEMCmax179RFdgt2km = 0;
double GeneratedEventsEMCmax179RFdgt2km = 0;
double EventsWithErecCOEMCmax179RFdgt3km = 0;
double GeneratedEventsEMCmax179RFdgt3km = 0;
double EventsWithErecCOEMCmax179RFdgt4km = 0;
double GeneratedEventsEMCmax179RFdgt4km = 0;
double EventsWithErecCOEMCmax179RFdgt5km = 0;
double GeneratedEventsEMCmax179RFdgt5km = 0;
double EventsWithErecHEATEMCmax179 = 0; //first range: [17-17.1)
double EventsWithErecHEATEMCmax179RFdgt1km = 0; //first range: [17-17.1)
double EventsWithErecHEATEMCmax179RFdgt2km = 0;
double EventsWithErecHEATEMCmax179RFdgt3km = 0;
double EventsWithErecHEATEMCmax179RFdgt4km = 0;
double EventsWithErecHEATEMCmax179RFdgt5km = 0;

double EventsWithErecCOEMCmax18 = 0; //3rd range: 17.9-18
double GeneratedEventsEMCmax18 = 0;
double EventsWithErecCOEMCmax18RFdgt1km = 0;
double GeneratedEventsEMCmax18RFdgt1km = 0;
double EventsWithErecCOEMCmax18RFdgt2km = 0;
double GeneratedEventsEMCmax18RFdgt2km = 0;
double EventsWithErecCOEMCmax18RFdgt3km = 0;
double GeneratedEventsEMCmax18RFdgt3km = 0;
double EventsWithErecCOEMCmax18RFdgt4km = 0;
double GeneratedEventsEMCmax18RFdgt4km = 0;
double EventsWithErecCOEMCmax18RFdgt5km = 0;
double GeneratedEventsEMCmax18RFdgt5km = 0;
double EventsWithErecHEATEMCmax18 = 0; //first range: [17-17.1)
double EventsWithErecHEATEMCmax18RFdgt1km = 0; //first range: [17-17.1)
double EventsWithErecHEATEMCmax18RFdgt2km = 0;
double EventsWithErecHEATEMCmax18RFdgt3km = 0;
double EventsWithErecHEATEMCmax18RFdgt4km = 0;
double EventsWithErecHEATEMCmax18RFdgt5km = 0;


double EventsWithErecCOEMCmax181 = 0; // range: 18-18.1
double GeneratedEventsEMCmax181 = 0;
double EventsWithErecCOEMCmax181RFdgt1km = 0;
double GeneratedEventsEMCmax181RFdgt1km = 0;
double EventsWithErecCOEMCmax181RFdgt2km = 0;
double GeneratedEventsEMCmax181RFdgt2km = 0;
double EventsWithErecCOEMCmax181RFdgt3km = 0;
double GeneratedEventsEMCmax181RFdgt3km = 0;
double EventsWithErecCOEMCmax181RFdgt4km = 0;
double GeneratedEventsEMCmax181RFdgt4km = 0;
double EventsWithErecCOEMCmax181RFdgt5km = 0;
double GeneratedEventsEMCmax181RFdgt5km = 0;
double EventsWithErecHEATEMCmax181 = 0; //first range: [17-17.1)
double EventsWithErecHEATEMCmax181RFdgt1km = 0; //first range: [17-17.1)
double EventsWithErecHEATEMCmax181RFdgt2km = 0;
double EventsWithErecHEATEMCmax181RFdgt3km = 0;
double EventsWithErecHEATEMCmax181RFdgt4km = 0;
double EventsWithErecHEATEMCmax181RFdgt5km = 0;


double EventsWithErecCOEMCmax182 = 0; //3rd range: 18.1 - 18.2
double GeneratedEventsEMCmax182 = 0;
double EventsWithErecCOEMCmax182RFdgt1km = 0;
double GeneratedEventsEMCmax182RFdgt1km = 0;
double EventsWithErecCOEMCmax182RFdgt2km = 0;
double GeneratedEventsEMCmax182RFdgt2km = 0;
double EventsWithErecCOEMCmax182RFdgt3km = 0;
double GeneratedEventsEMCmax182RFdgt3km = 0;
double EventsWithErecCOEMCmax182RFdgt4km = 0;
double GeneratedEventsEMCmax182RFdgt4km = 0;
double EventsWithErecCOEMCmax182RFdgt5km = 0;
double GeneratedEventsEMCmax182RFdgt5km = 0;
double EventsWithErecHEATEMCmax182 = 0; //first range: [17-17.1)
double EventsWithErecHEATEMCmax182RFdgt1km = 0; //first range: [17-17.1)
double EventsWithErecHEATEMCmax182RFdgt2km = 0;
double EventsWithErecHEATEMCmax182RFdgt3km = 0;
double EventsWithErecHEATEMCmax182RFdgt4km = 0;
double EventsWithErecHEATEMCmax182RFdgt5km = 0;


double EventsWithErecCOEMCmax183 = 0; //3rd range: 18.2 - 18.3
double GeneratedEventsEMCmax183 = 0;
double EventsWithErecCOEMCmax183RFdgt1km = 0;
double GeneratedEventsEMCmax183RFdgt1km = 0;
double EventsWithErecCOEMCmax183RFdgt2km = 0;
double GeneratedEventsEMCmax183RFdgt2km = 0;
double EventsWithErecCOEMCmax183RFdgt3km = 0;
double GeneratedEventsEMCmax183RFdgt3km = 0;
double EventsWithErecCOEMCmax183RFdgt4km = 0;
double GeneratedEventsEMCmax183RFdgt4km = 0;
double EventsWithErecCOEMCmax183RFdgt5km = 0;
double GeneratedEventsEMCmax183RFdgt5km = 0;
double EventsWithErecHEATEMCmax183 = 0; //first range: [17-17.1)
double EventsWithErecHEATEMCmax183RFdgt1km = 0; //first range: [17-17.1)
double EventsWithErecHEATEMCmax183RFdgt2km = 0;
double EventsWithErecHEATEMCmax183RFdgt3km = 0;
double EventsWithErecHEATEMCmax183RFdgt4km = 0;
double EventsWithErecHEATEMCmax183RFdgt5km = 0;



double EventsWithErecCOEMCmax184 = 0; //range: 18.3 - 18.4
double GeneratedEventsEMCmax184 = 0;
double EventsWithErecCOEMCmax184RFdgt1km = 0;
double GeneratedEventsEMCmax184RFdgt1km = 0;
double EventsWithErecCOEMCmax184RFdgt2km = 0;
double GeneratedEventsEMCmax184RFdgt2km = 0;
double EventsWithErecCOEMCmax184RFdgt3km = 0;
double GeneratedEventsEMCmax184RFdgt3km = 0;
double EventsWithErecCOEMCmax184RFdgt4km = 0;
double GeneratedEventsEMCmax184RFdgt4km = 0;
double EventsWithErecCOEMCmax184RFdgt5km = 0;
double GeneratedEventsEMCmax184RFdgt5km = 0;
double EventsWithErecHEATEMCmax184 = 0; //first range: [17-17.1)
double EventsWithErecHEATEMCmax184RFdgt1km = 0; //first range: [17-17.1)
double EventsWithErecHEATEMCmax184RFdgt2km = 0;
double EventsWithErecHEATEMCmax184RFdgt3km = 0;
double EventsWithErecHEATEMCmax184RFdgt4km = 0;
double EventsWithErecHEATEMCmax184RFdgt5km = 0;


double EventsWithErecCOEMCmax185 = 0; //  range: 18.4 - 18.5
double GeneratedEventsEMCmax185 = 0;
double EventsWithErecCOEMCmax185RFdgt1km = 0;
double GeneratedEventsEMCmax185RFdgt1km = 0;
double EventsWithErecCOEMCmax185RFdgt2km = 0;
double GeneratedEventsEMCmax185RFdgt2km = 0;
double EventsWithErecCOEMCmax185RFdgt3km = 0;
double GeneratedEventsEMCmax185RFdgt3km = 0;
double EventsWithErecCOEMCmax185RFdgt4km = 0;
double GeneratedEventsEMCmax185RFdgt4km = 0;
double EventsWithErecCOEMCmax185RFdgt5km = 0;
double GeneratedEventsEMCmax185RFdgt5km = 0;
double EventsWithErecHEATEMCmax185 = 0; //first range: [17-17.1)
double EventsWithErecHEATEMCmax185RFdgt1km = 0; //first range: [17-17.1)
double EventsWithErecHEATEMCmax185RFdgt2km = 0;
double EventsWithErecHEATEMCmax185RFdgt3km = 0;
double EventsWithErecHEATEMCmax185RFdgt4km = 0;
double EventsWithErecHEATEMCmax185RFdgt5km = 0;


double EventsWithErecCOEMCeq185 = 0; //  E= 18.5
double GeneratedEventsEMCeq185 = 0;
double EventsWithErecCOEMCeq185RFdgt1km = 0;
double GeneratedEventsEMCeq185RFdgt1km = 0;
double EventsWithErecCOEMCeq185RFdgt2km = 0;
double GeneratedEventsEMCeq185RFdgt2km = 0;
double EventsWithErecCOEMCeq185RFdgt3km = 0;
double GeneratedEventsEMCeq185RFdgt3km = 0;
double EventsWithErecCOEMCeq185RFdgt4km = 0;
double GeneratedEventsEMCeq185RFdgt4km = 0;
double EventsWithErecCOEMCeq185RFdgt5km = 0;
double GeneratedEventsEMCeq185RFdgt5km = 0;
double EventsWithErecHEATEMCeq185 = 0; //first range: [17-17.1)
double EventsWithErecHEATEMCeq185RFdgt1km = 0; //first range: [17-17.1)
double EventsWithErecHEATEMCeq185RFdgt2km = 0;
double EventsWithErecHEATEMCeq185RFdgt3km = 0;
double EventsWithErecHEATEMCeq185RFdgt4km = 0;
double EventsWithErecHEATEMCeq185RFdgt5km = 0;




for(int i=0; i<VectorEVENTidCOThetamin115.size(); i++)
  { double EnergyDouble = double(floor(VectorlgEMCCOThetamin115[i]*10.0 + 0.5))/10.0 ;
    if( EnergyDouble>=17 && EnergyDouble<17.1)
          {  GeneratedEventsEMCmax171+=1;
          //  cout<<"E double : "<<EnergyDouble<<" EMC ="<<VectorlgEMCCOThetamin115[i] << endl;
          	  	if (VectorGenDistanceFdCOThetamin115[i] > 1)
          	  	  		 GeneratedEventsEMCmax171RFdgt1km +=1;
          	  	if (VectorGenDistanceFdCOThetamin115[i] > 2)
          	  	         GeneratedEventsEMCmax171RFdgt2km +=1;
          	  	if (VectorGenDistanceFdCOThetamin115[i] > 3)
          	  	         GeneratedEventsEMCmax171RFdgt3km +=1;
          	  	if (VectorGenDistanceFdCOThetamin115[i] > 4)
          	  	         GeneratedEventsEMCmax171RFdgt4km +=1;
          	  	if (VectorGenDistanceFdCOThetamin115[i] > 5)
          	  	         GeneratedEventsEMCmax171RFdgt5km +=1;

            if(VectorEVENTidCOThetamin115[i]!=0 && pow(10, VectorlgErecCOThetamin115[i])!=0 && VectorlgErecCOThetamin115[i]!=-1)
            	{    EventsWithErecCOEMCmax171 += 1;
            		if (VectorGenDistanceFdCOThetamin115[i] > 1)
            			EventsWithErecCOEMCmax171RFdgt1km  +=1;
            		if(VectorGenDistanceFdCOThetamin115[i]> 2)
            			EventsWithErecCOEMCmax171RFdgt2km +=1;
            		if(VectorGenDistanceFdCOThetamin115[i]> 3)
            		EventsWithErecCOEMCmax171RFdgt3km +=1;
            		if(VectorGenDistanceFdCOThetamin115[i]> 4)
            		EventsWithErecCOEMCmax171RFdgt4km +=1;
            		if(VectorGenDistanceFdCOThetamin115[i]> 5)
            		EventsWithErecCOEMCmax171RFdgt5km +=1;
            	}
            if(VectorEVENTidHEATThetamin115[i]!=0 && pow(10, VectorlgErecHEATThetamin115[i])!=0 && VectorlgErecHEATThetamin115[i]!=-1)
            	{    EventsWithErecHEATEMCmax171 += 1;
            		if (VectorGenDistanceFdHEATThetamin115[i] > 1)
            			EventsWithErecHEATEMCmax171RFdgt1km  +=1;
            		if(VectorGenDistanceFdHEATThetamin115[i]> 2)
            			EventsWithErecHEATEMCmax171RFdgt2km +=1;
            		if(VectorGenDistanceFdHEATThetamin115[i]> 3)
            		EventsWithErecHEATEMCmax171RFdgt3km +=1;
            		if(VectorGenDistanceFdHEATThetamin115[i]> 4)
            		EventsWithErecHEATEMCmax171RFdgt4km +=1;
            		if(VectorGenDistanceFdHEATThetamin115[i]> 5)
            		EventsWithErecHEATEMCmax171RFdgt5km +=1;
            	}
          }
    else if(EnergyDouble>=17.1 && EnergyDouble<17.2)
    			{	GeneratedEventsEMCmax172+=1;

          	  	if (VectorGenDistanceFdCOThetamin115[i] > 1)
          	  	  		 GeneratedEventsEMCmax172RFdgt1km +=1;
          	  	if (VectorGenDistanceFdCOThetamin115[i] > 2)
          	  	         GeneratedEventsEMCmax172RFdgt2km +=1;
          	  	if (VectorGenDistanceFdCOThetamin115[i] > 3)
          	  	         GeneratedEventsEMCmax172RFdgt3km +=1;
          	  	if (VectorGenDistanceFdCOThetamin115[i] > 4)
          	  	         GeneratedEventsEMCmax172RFdgt4km +=1;
          	  	if (VectorGenDistanceFdCOThetamin115[i] > 5)
          	  	         GeneratedEventsEMCmax172RFdgt5km +=1;

    		if(VectorEVENTidCOThetamin115[i]!=0 && pow(10, VectorlgErecCOThetamin115[i])!=0 && VectorlgErecCOThetamin115[i]!=-1)
    					{      EventsWithErecCOEMCmax172 += 1;
    					if (VectorGenDistanceFdCOThetamin115[i] > 1)
    					    EventsWithErecCOEMCmax172RFdgt1km  +=1;
    					if(VectorGenDistanceFdCOThetamin115[i]> 2)
    						EventsWithErecCOEMCmax172RFdgt2km +=1;
    					if(VectorGenDistanceFdCOThetamin115[i]> 3)
    						EventsWithErecCOEMCmax172RFdgt3km +=1;
    					if(VectorGenDistanceFdCOThetamin115[i]> 4)
    						EventsWithErecCOEMCmax172RFdgt4km +=1;
    					if(VectorGenDistanceFdCOThetamin115[i]> 5)
    						EventsWithErecCOEMCmax172RFdgt5km +=1;
    					}
            if(VectorEVENTidHEATThetamin115[i]!=0 && pow(10, VectorlgErecHEATThetamin115[i])!=0 && VectorlgErecHEATThetamin115[i]!=-1)
            	{    EventsWithErecHEATEMCmax172 += 1;
            		if (VectorGenDistanceFdHEATThetamin115[i] > 1)
            			EventsWithErecHEATEMCmax172RFdgt1km  +=1;
            		if(VectorGenDistanceFdHEATThetamin115[i]> 2)
            			EventsWithErecHEATEMCmax172RFdgt2km +=1;
            		if(VectorGenDistanceFdHEATThetamin115[i]> 3)
            		EventsWithErecHEATEMCmax172RFdgt3km +=1;
            		if(VectorGenDistanceFdHEATThetamin115[i]> 4)
            		EventsWithErecHEATEMCmax172RFdgt4km +=1;
            		if(VectorGenDistanceFdHEATThetamin115[i]> 5)
            		EventsWithErecHEATEMCmax172RFdgt5km +=1;
            	}
    			}
    else if(EnergyDouble>=17.2 && EnergyDouble<17.3)
        			{	GeneratedEventsEMCmax173+=1;

        			if (VectorGenDistanceFdCOThetamin115[i] > 1)
        					GeneratedEventsEMCmax173RFdgt1km +=1;
        		  	if (VectorGenDistanceFdCOThetamin115[i] > 2)
        		  			GeneratedEventsEMCmax173RFdgt2km +=1;
        		  	if (VectorGenDistanceFdCOThetamin115[i] > 3)
        		  			GeneratedEventsEMCmax173RFdgt3km +=1;
        		  	if (VectorGenDistanceFdCOThetamin115[i] > 4)
        		  			GeneratedEventsEMCmax173RFdgt4km +=1;
        		  	if (VectorGenDistanceFdCOThetamin115[i] > 5)
        		  			GeneratedEventsEMCmax173RFdgt5km +=1;

        				if(VectorEVENTidCOThetamin115[i]!=0 && pow(10, VectorlgErecCOThetamin115[i])!=0 && VectorlgErecCOThetamin115[i]!=-1)
        					{      EventsWithErecCOEMCmax173 += 1;
        					if (VectorGenDistanceFdCOThetamin115[i] > 1)
        					    EventsWithErecCOEMCmax173RFdgt1km  +=1;
        					if(VectorGenDistanceFdCOThetamin115[i]> 2)
        						EventsWithErecCOEMCmax173RFdgt2km +=1;
        					if(VectorGenDistanceFdCOThetamin115[i]> 3)
        						EventsWithErecCOEMCmax173RFdgt3km +=1;
        					if(VectorGenDistanceFdCOThetamin115[i]> 4)
        						EventsWithErecCOEMCmax173RFdgt4km +=1;
        					if(VectorGenDistanceFdCOThetamin115[i]> 5)
        						EventsWithErecCOEMCmax173RFdgt5km +=1;

        					}
        	            if(VectorEVENTidHEATThetamin115[i]!=0 && pow(10, VectorlgErecHEATThetamin115[i])!=0 && VectorlgErecHEATThetamin115[i]!=-1)
        	            	{    EventsWithErecHEATEMCmax173 += 1;
        	            		if (VectorGenDistanceFdHEATThetamin115[i] > 1)
        	            			EventsWithErecHEATEMCmax173RFdgt1km  +=1;
        	            		if(VectorGenDistanceFdHEATThetamin115[i]> 2)
        	            			EventsWithErecHEATEMCmax173RFdgt2km +=1;
        	            		if(VectorGenDistanceFdHEATThetamin115[i]> 3)
        	            		EventsWithErecHEATEMCmax173RFdgt3km +=1;
        	            		if(VectorGenDistanceFdHEATThetamin115[i]> 4)
        	            		EventsWithErecHEATEMCmax173RFdgt4km +=1;
        	            		if(VectorGenDistanceFdHEATThetamin115[i]> 5)
        	            		EventsWithErecHEATEMCmax173RFdgt5km +=1;
        	            	}
        			}

    else if(EnergyDouble>=17.3 && EnergyDouble<17.4)
        			{	GeneratedEventsEMCmax174+=1;
        			if (VectorGenDistanceFdCOThetamin115[i] > 1)
        					GeneratedEventsEMCmax174RFdgt1km +=1;
        		  	if (VectorGenDistanceFdCOThetamin115[i] > 2)
        		  			GeneratedEventsEMCmax174RFdgt2km +=1;
        		  	if (VectorGenDistanceFdCOThetamin115[i] > 3)
        		  			GeneratedEventsEMCmax174RFdgt3km +=1;
        		  	if (VectorGenDistanceFdCOThetamin115[i] > 4)
        		  			GeneratedEventsEMCmax174RFdgt4km +=1;
        		  	if (VectorGenDistanceFdCOThetamin115[i] > 5)
        		  			GeneratedEventsEMCmax174RFdgt5km +=1;

        				if(VectorEVENTidCOThetamin115[i]!=0 && pow(10, VectorlgErecCOThetamin115[i])!=0 && VectorlgErecCOThetamin115[i]!=-1)
        					{      EventsWithErecCOEMCmax174 += 1;
        					if (VectorGenDistanceFdCOThetamin115[i] > 1)
        					    EventsWithErecCOEMCmax174RFdgt1km  +=1;
        					if(VectorGenDistanceFdCOThetamin115[i]> 2)
        						EventsWithErecCOEMCmax174RFdgt2km +=1;
        					if(VectorGenDistanceFdCOThetamin115[i]> 3)
        						EventsWithErecCOEMCmax174RFdgt3km +=1;
        					if(VectorGenDistanceFdCOThetamin115[i]> 4)
        						EventsWithErecCOEMCmax174RFdgt4km +=1;
        					if(VectorGenDistanceFdCOThetamin115[i]> 5)
        						EventsWithErecCOEMCmax174RFdgt5km +=1;

        					}
        	            if(VectorEVENTidHEATThetamin115[i]!=0 && pow(10, VectorlgErecHEATThetamin115[i])!=0 && VectorlgErecHEATThetamin115[i]!=-1)
        	            	{    EventsWithErecHEATEMCmax174 += 1;
        	            		if (VectorGenDistanceFdHEATThetamin115[i] > 1)
        	            			EventsWithErecHEATEMCmax174RFdgt1km  +=1;
        	            		if(VectorGenDistanceFdHEATThetamin115[i]> 2)
        	            			EventsWithErecHEATEMCmax174RFdgt2km +=1;
        	            		if(VectorGenDistanceFdHEATThetamin115[i]> 3)
        	            		EventsWithErecHEATEMCmax174RFdgt3km +=1;
        	            		if(VectorGenDistanceFdHEATThetamin115[i]> 4)
        	            		EventsWithErecHEATEMCmax174RFdgt4km +=1;
        	            		if(VectorGenDistanceFdHEATThetamin115[i]> 5)
        	            		EventsWithErecHEATEMCmax174RFdgt5km +=1;
        	            	}
        			}
    else if(EnergyDouble>=17.4 && EnergyDouble<17.5)
        			{	GeneratedEventsEMCmax175+=1;
        			if (VectorGenDistanceFdCOThetamin115[i] > 1)
        					GeneratedEventsEMCmax175RFdgt1km +=1;
        		  	if (VectorGenDistanceFdCOThetamin115[i] > 2)
        		  			GeneratedEventsEMCmax175RFdgt2km +=1;
        		  	if (VectorGenDistanceFdCOThetamin115[i] > 3)
        		  			GeneratedEventsEMCmax175RFdgt3km +=1;
        		  	if (VectorGenDistanceFdCOThetamin115[i] > 4)
        		  			GeneratedEventsEMCmax175RFdgt4km +=1;
        		  	if (VectorGenDistanceFdCOThetamin115[i] > 5)
        		  			GeneratedEventsEMCmax175RFdgt5km +=1;

        				if(VectorEVENTidCOThetamin115[i]!=0 && pow(10, VectorlgErecCOThetamin115[i])!=0 && VectorlgErecCOThetamin115[i]!=-1)
        					{      EventsWithErecCOEMCmax175 += 1;
        					if (VectorGenDistanceFdCOThetamin115[i] > 1)
        					    EventsWithErecCOEMCmax175RFdgt1km  +=1;
        					if(VectorGenDistanceFdCOThetamin115[i]> 2)
        						EventsWithErecCOEMCmax175RFdgt2km +=1;
        					if(VectorGenDistanceFdCOThetamin115[i]> 3)
        						EventsWithErecCOEMCmax175RFdgt3km +=1;
        					if(VectorGenDistanceFdCOThetamin115[i]> 4)
        						EventsWithErecCOEMCmax175RFdgt4km +=1;
        					if(VectorGenDistanceFdCOThetamin115[i]> 5)
        						EventsWithErecCOEMCmax175RFdgt5km +=1;
        					}
        	            if(VectorEVENTidHEATThetamin115[i]!=0 && pow(10, VectorlgErecHEATThetamin115[i])!=0 && VectorlgErecHEATThetamin115[i]!=-1)
        	            	{    EventsWithErecHEATEMCmax175 += 1;
        	            		if (VectorGenDistanceFdHEATThetamin115[i] > 1)
        	            			EventsWithErecHEATEMCmax175RFdgt1km  +=1;
        	            		if(VectorGenDistanceFdHEATThetamin115[i]> 2)
        	            			EventsWithErecHEATEMCmax175RFdgt2km +=1;
        	            		if(VectorGenDistanceFdHEATThetamin115[i]> 3)
        	            		EventsWithErecHEATEMCmax175RFdgt3km +=1;
        	            		if(VectorGenDistanceFdHEATThetamin115[i]> 4)
        	            		EventsWithErecHEATEMCmax175RFdgt4km +=1;
        	            		if(VectorGenDistanceFdHEATThetamin115[i]> 5)
        	            		EventsWithErecHEATEMCmax175RFdgt5km +=1;
        	            	}
        			}
    else if(EnergyDouble>=17.5 && EnergyDouble<17.6)
        			{	GeneratedEventsEMCmax176+=1;
        			if (VectorGenDistanceFdCOThetamin115[i] > 1)
        					GeneratedEventsEMCmax176RFdgt1km +=1;
        		  	if (VectorGenDistanceFdCOThetamin115[i] > 2)
        		  			GeneratedEventsEMCmax176RFdgt2km +=1;
        		  	if (VectorGenDistanceFdCOThetamin115[i] > 3)
        		  			GeneratedEventsEMCmax176RFdgt3km +=1;
        		  	if (VectorGenDistanceFdCOThetamin115[i] > 4)
        		  			GeneratedEventsEMCmax176RFdgt4km +=1;
        		  	if (VectorGenDistanceFdCOThetamin115[i] > 5)
        		  			GeneratedEventsEMCmax176RFdgt5km +=1;

        				if(VectorEVENTidCOThetamin115[i]!=0 && pow(10, VectorlgErecCOThetamin115[i])!=0 && VectorlgErecCOThetamin115[i]!=-1)
        					{      EventsWithErecCOEMCmax176 += 1;
        					if (VectorGenDistanceFdCOThetamin115[i] > 1)
        					    EventsWithErecCOEMCmax176RFdgt1km  +=1;
        					if(VectorGenDistanceFdCOThetamin115[i]> 2)
        						EventsWithErecCOEMCmax176RFdgt2km +=1;
        					if(VectorGenDistanceFdCOThetamin115[i]> 3)
        						EventsWithErecCOEMCmax176RFdgt3km +=1;
        					if(VectorGenDistanceFdCOThetamin115[i]> 4)
        						EventsWithErecCOEMCmax176RFdgt4km +=1;
        					if(VectorGenDistanceFdCOThetamin115[i]> 5)
        						EventsWithErecCOEMCmax176RFdgt5km +=1;
        					}
        	            if(VectorEVENTidHEATThetamin115[i]!=0 && pow(10, VectorlgErecHEATThetamin115[i])!=0 && VectorlgErecHEATThetamin115[i]!=-1)
        	            	{    EventsWithErecHEATEMCmax176 += 1;
        	            		if (VectorGenDistanceFdHEATThetamin115[i] > 1)
        	            			EventsWithErecHEATEMCmax176RFdgt1km  +=1;
        	            		if(VectorGenDistanceFdHEATThetamin115[i]> 2)
        	            			EventsWithErecHEATEMCmax176RFdgt2km +=1;
        	            		if(VectorGenDistanceFdHEATThetamin115[i]> 3)
        	            		EventsWithErecHEATEMCmax176RFdgt3km +=1;
        	            		if(VectorGenDistanceFdHEATThetamin115[i]> 4)
        	            		EventsWithErecHEATEMCmax176RFdgt4km +=1;
        	            		if(VectorGenDistanceFdHEATThetamin115[i]> 5)
        	            		EventsWithErecHEATEMCmax176RFdgt5km +=1;
        	            	}
        			}
    else if(EnergyDouble>=17.6 && EnergyDouble<17.7)
        			{	GeneratedEventsEMCmax177+=1;
        			if (VectorGenDistanceFdCOThetamin115[i] > 1)
        					GeneratedEventsEMCmax177RFdgt1km +=1;
        		  	if (VectorGenDistanceFdCOThetamin115[i] > 2)
        		  			GeneratedEventsEMCmax177RFdgt2km +=1;
        		  	if (VectorGenDistanceFdCOThetamin115[i] > 3)
        		  			GeneratedEventsEMCmax177RFdgt3km +=1;
        		  	if (VectorGenDistanceFdCOThetamin115[i] > 4)
        		  			GeneratedEventsEMCmax177RFdgt4km +=1;
        		  	if (VectorGenDistanceFdCOThetamin115[i] > 5)
        		  			GeneratedEventsEMCmax177RFdgt5km +=1;

        				if(VectorEVENTidCOThetamin115[i]!=0 && pow(10, VectorlgErecCOThetamin115[i])!=0 && VectorlgErecCOThetamin115[i]!=-1)
        					{      EventsWithErecCOEMCmax177 += 1;
        					if (VectorGenDistanceFdCOThetamin115[i] > 1)
        					    EventsWithErecCOEMCmax177RFdgt1km  +=1;
        					if(VectorGenDistanceFdCOThetamin115[i]> 2)
        						EventsWithErecCOEMCmax177RFdgt2km +=1;
        					if(VectorGenDistanceFdCOThetamin115[i]> 3)
        						EventsWithErecCOEMCmax177RFdgt3km +=1;
        					if(VectorGenDistanceFdCOThetamin115[i]> 4)
        						EventsWithErecCOEMCmax177RFdgt4km +=1;
        					if(VectorGenDistanceFdCOThetamin115[i]> 5)
        						EventsWithErecCOEMCmax177RFdgt5km +=1;
        					}
        	            if(VectorEVENTidHEATThetamin115[i]!=0 && pow(10, VectorlgErecHEATThetamin115[i])!=0 && VectorlgErecHEATThetamin115[i]!=-1)
        	            	{    EventsWithErecHEATEMCmax177 += 1;
        	            		if (VectorGenDistanceFdHEATThetamin115[i] > 1)
        	            			EventsWithErecHEATEMCmax177RFdgt1km  +=1;
        	            		if(VectorGenDistanceFdHEATThetamin115[i]> 2)
        	            			EventsWithErecHEATEMCmax177RFdgt2km +=1;
        	            		if(VectorGenDistanceFdHEATThetamin115[i]> 3)
        	            		EventsWithErecHEATEMCmax177RFdgt3km +=1;
        	            		if(VectorGenDistanceFdHEATThetamin115[i]> 4)
        	            		EventsWithErecHEATEMCmax177RFdgt4km +=1;
        	            		if(VectorGenDistanceFdHEATThetamin115[i]> 5)
        	            		EventsWithErecHEATEMCmax177RFdgt5km +=1;
        	            	}
        			}
    else if(EnergyDouble>=17.7 && EnergyDouble<17.8)
        			{	GeneratedEventsEMCmax178+=1;
        			if (VectorGenDistanceFdCOThetamin115[i] > 1)
        					GeneratedEventsEMCmax178RFdgt1km +=1;
        		  	if (VectorGenDistanceFdCOThetamin115[i] > 2)
        		  			GeneratedEventsEMCmax178RFdgt2km +=1;
        		  	if (VectorGenDistanceFdCOThetamin115[i] > 3)
        		  			GeneratedEventsEMCmax178RFdgt3km +=1;
        		  	if (VectorGenDistanceFdCOThetamin115[i] > 4)
        		  			GeneratedEventsEMCmax178RFdgt4km +=1;
        		  	if (VectorGenDistanceFdCOThetamin115[i] > 5)
        		  			GeneratedEventsEMCmax178RFdgt5km +=1;

        				if(VectorEVENTidCOThetamin115[i]!=0 && pow(10, VectorlgErecCOThetamin115[i])!=0 && VectorlgErecCOThetamin115[i]!=-1)
        					{      EventsWithErecCOEMCmax178 += 1;
        					if (VectorGenDistanceFdCOThetamin115[i] > 1)
        					    EventsWithErecCOEMCmax178RFdgt1km  +=1;
        					if(VectorGenDistanceFdCOThetamin115[i]> 2)
        						EventsWithErecCOEMCmax178RFdgt2km +=1;
        					if(VectorGenDistanceFdCOThetamin115[i]> 3)
        						EventsWithErecCOEMCmax178RFdgt3km +=1;
        					if(VectorGenDistanceFdCOThetamin115[i]> 4)
        						EventsWithErecCOEMCmax178RFdgt4km +=1;
        					if(VectorGenDistanceFdCOThetamin115[i]> 5)
        						EventsWithErecCOEMCmax178RFdgt5km +=1;
        					}
        	            if(VectorEVENTidHEATThetamin115[i]!=0 && pow(10, VectorlgErecHEATThetamin115[i])!=0 && VectorlgErecHEATThetamin115[i]!=-1)
        	            	{    EventsWithErecHEATEMCmax178 += 1;
        	            		if (VectorGenDistanceFdHEATThetamin115[i] > 1)
        	            			EventsWithErecHEATEMCmax178RFdgt1km  +=1;
        	            		if(VectorGenDistanceFdHEATThetamin115[i]> 2)
        	            			EventsWithErecHEATEMCmax178RFdgt2km +=1;
        	            		if(VectorGenDistanceFdHEATThetamin115[i]> 3)
        	            		EventsWithErecHEATEMCmax178RFdgt3km +=1;
        	            		if(VectorGenDistanceFdHEATThetamin115[i]> 4)
        	            		EventsWithErecHEATEMCmax178RFdgt4km +=1;
        	            		if(VectorGenDistanceFdHEATThetamin115[i]> 5)
        	            		EventsWithErecHEATEMCmax178RFdgt5km +=1;
        	            	}
        			}
    else if(EnergyDouble>=17.8 && EnergyDouble<17.9)
        			{	GeneratedEventsEMCmax179+=1;
        			if (VectorGenDistanceFdCOThetamin115[i] > 1)
        					GeneratedEventsEMCmax179RFdgt1km +=1;
        		  	if (VectorGenDistanceFdCOThetamin115[i] > 2)
        		  			GeneratedEventsEMCmax179RFdgt2km +=1;
        		  	if (VectorGenDistanceFdCOThetamin115[i] > 3)
        		  			GeneratedEventsEMCmax179RFdgt3km +=1;
        		  	if (VectorGenDistanceFdCOThetamin115[i] > 4)
        		  			GeneratedEventsEMCmax179RFdgt4km +=1;
        		  	if (VectorGenDistanceFdCOThetamin115[i] > 5)
        		  			GeneratedEventsEMCmax179RFdgt5km +=1;

        				if(VectorEVENTidCOThetamin115[i]!=0 && pow(10, VectorlgErecCOThetamin115[i])!=0 && VectorlgErecCOThetamin115[i]!=-1)
        					{      EventsWithErecCOEMCmax179 += 1;
        					if (VectorGenDistanceFdCOThetamin115[i] > 1)
        					    EventsWithErecCOEMCmax179RFdgt1km  +=1;
        					if(VectorGenDistanceFdCOThetamin115[i]> 2)
        						EventsWithErecCOEMCmax179RFdgt2km +=1;
        					if(VectorGenDistanceFdCOThetamin115[i]> 3)
        						EventsWithErecCOEMCmax179RFdgt3km +=1;
        					if(VectorGenDistanceFdCOThetamin115[i]> 4)
        						EventsWithErecCOEMCmax179RFdgt4km +=1;
        					if(VectorGenDistanceFdCOThetamin115[i]> 5)
        						EventsWithErecCOEMCmax179RFdgt5km +=1;
        					}
        	            if(VectorEVENTidHEATThetamin115[i]!=0 && pow(10, VectorlgErecHEATThetamin115[i])!=0 && VectorlgErecHEATThetamin115[i]!=-1)
        	            	{    EventsWithErecHEATEMCmax179 += 1;
        	            		if (VectorGenDistanceFdHEATThetamin115[i] > 1)
        	            			EventsWithErecHEATEMCmax179RFdgt1km  +=1;
        	            		if(VectorGenDistanceFdHEATThetamin115[i]> 2)
        	            			EventsWithErecHEATEMCmax179RFdgt2km +=1;
        	            		if(VectorGenDistanceFdHEATThetamin115[i]> 3)
        	            		EventsWithErecHEATEMCmax179RFdgt3km +=1;
        	            		if(VectorGenDistanceFdHEATThetamin115[i]> 4)
        	            		EventsWithErecHEATEMCmax179RFdgt4km +=1;
        	            		if(VectorGenDistanceFdHEATThetamin115[i]> 5)
        	            		EventsWithErecHEATEMCmax179RFdgt5km +=1;
        	            	}
        			}
    else if(EnergyDouble>=17.9 && EnergyDouble<18)
        			{	GeneratedEventsEMCmax18+=1;
        			if (VectorGenDistanceFdCOThetamin115[i] > 1)
        					GeneratedEventsEMCmax18RFdgt1km +=1;
        		  	if (VectorGenDistanceFdCOThetamin115[i] > 2)
        		  			GeneratedEventsEMCmax18RFdgt2km +=1;
        		  	if (VectorGenDistanceFdCOThetamin115[i] > 3)
        		  			GeneratedEventsEMCmax18RFdgt3km +=1;
        		  	if (VectorGenDistanceFdCOThetamin115[i] > 4)
        		  			GeneratedEventsEMCmax18RFdgt4km +=1;
        		  	if (VectorGenDistanceFdCOThetamin115[i] > 5)
        		  			GeneratedEventsEMCmax18RFdgt5km +=1;

        				if(VectorEVENTidCOThetamin115[i]!=0 && pow(10, VectorlgErecCOThetamin115[i])!=0 && VectorlgErecCOThetamin115[i]!=-1)
        					{      EventsWithErecCOEMCmax18 += 1;
        					if (VectorGenDistanceFdCOThetamin115[i] > 1)
        					    EventsWithErecCOEMCmax18RFdgt1km  +=1;
        					if(VectorGenDistanceFdCOThetamin115[i]> 2)
        						EventsWithErecCOEMCmax18RFdgt2km +=1;
        					if(VectorGenDistanceFdCOThetamin115[i]> 3)
        						EventsWithErecCOEMCmax18RFdgt3km +=1;
        					if(VectorGenDistanceFdCOThetamin115[i]> 4)
        						EventsWithErecCOEMCmax18RFdgt4km +=1;
        					if(VectorGenDistanceFdCOThetamin115[i]> 5)
        						EventsWithErecCOEMCmax18RFdgt5km +=1;
        					}
        	            if(VectorEVENTidHEATThetamin115[i]!=0 && pow(10, VectorlgErecHEATThetamin115[i])!=0 && VectorlgErecHEATThetamin115[i]!=-1)
        	            	{    EventsWithErecHEATEMCmax18 += 1;
        	            		if (VectorGenDistanceFdHEATThetamin115[i] > 1)
        	            			EventsWithErecHEATEMCmax18RFdgt1km  +=1;
        	            		if(VectorGenDistanceFdHEATThetamin115[i]> 2)
        	            			EventsWithErecHEATEMCmax18RFdgt2km +=1;
        	            		if(VectorGenDistanceFdHEATThetamin115[i]> 3)
        	            		EventsWithErecHEATEMCmax18RFdgt3km +=1;
        	            		if(VectorGenDistanceFdHEATThetamin115[i]> 4)
        	            		EventsWithErecHEATEMCmax18RFdgt4km +=1;
        	            		if(VectorGenDistanceFdHEATThetamin115[i]> 5)
        	            		EventsWithErecHEATEMCmax18RFdgt5km +=1;
        	            	}
        			}
    else if(EnergyDouble>=18 && EnergyDouble<18.1)
        			{	GeneratedEventsEMCmax181+=1;
        			if (VectorGenDistanceFdCOThetamin115[i] > 1)
        					GeneratedEventsEMCmax181RFdgt1km +=1;
        		  	if (VectorGenDistanceFdCOThetamin115[i] > 2)
        		  			GeneratedEventsEMCmax181RFdgt2km +=1;
        		  	if (VectorGenDistanceFdCOThetamin115[i] > 3)
        		  			GeneratedEventsEMCmax181RFdgt3km +=1;
        		  	if (VectorGenDistanceFdCOThetamin115[i] > 4)
        		  			GeneratedEventsEMCmax181RFdgt4km +=1;
        		  	if (VectorGenDistanceFdCOThetamin115[i] > 5)
        		  			GeneratedEventsEMCmax181RFdgt5km +=1;

        				if(VectorEVENTidCOThetamin115[i]!=0 && pow(10, VectorlgErecCOThetamin115[i])!=0 && VectorlgErecCOThetamin115[i]!=-1)
        					{      EventsWithErecCOEMCmax181+= 1;
        					if (VectorGenDistanceFdCOThetamin115[i] > 1)
        					    EventsWithErecCOEMCmax181RFdgt1km  +=1;
        					if(VectorGenDistanceFdCOThetamin115[i]> 2)
        						EventsWithErecCOEMCmax181RFdgt2km +=1;
        					if(VectorGenDistanceFdCOThetamin115[i]> 3)
        						EventsWithErecCOEMCmax181RFdgt3km +=1;
        					if(VectorGenDistanceFdCOThetamin115[i]> 4)
        						EventsWithErecCOEMCmax181RFdgt4km +=1;
        					if(VectorGenDistanceFdCOThetamin115[i]> 5)
        						EventsWithErecCOEMCmax181RFdgt5km +=1;
        					}
        	            if(VectorEVENTidHEATThetamin115[i]!=0 && pow(10, VectorlgErecHEATThetamin115[i])!=0 && VectorlgErecHEATThetamin115[i]!=-1)
        	            	{    EventsWithErecHEATEMCmax181 += 1;
        	            		if (VectorGenDistanceFdHEATThetamin115[i] > 1)
        	            			EventsWithErecHEATEMCmax181RFdgt1km  +=1;
        	            		if(VectorGenDistanceFdHEATThetamin115[i]> 2)
        	            			EventsWithErecHEATEMCmax181RFdgt2km +=1;
        	            		if(VectorGenDistanceFdHEATThetamin115[i]> 3)
        	            		EventsWithErecHEATEMCmax181RFdgt3km +=1;
        	            		if(VectorGenDistanceFdHEATThetamin115[i]> 4)
        	            		EventsWithErecHEATEMCmax181RFdgt4km +=1;
        	            		if(VectorGenDistanceFdHEATThetamin115[i]> 5)
        	            		EventsWithErecHEATEMCmax181RFdgt5km +=1;
        	            	}
        			}
    else if(EnergyDouble>=18.1 && EnergyDouble<18.2)
        			{	GeneratedEventsEMCmax182+=1;
        			if (VectorGenDistanceFdCOThetamin115[i] > 1)
        					GeneratedEventsEMCmax182RFdgt1km +=1;
        		  	if (VectorGenDistanceFdCOThetamin115[i] > 2)
        		  			GeneratedEventsEMCmax182RFdgt2km +=1;
        		  	if (VectorGenDistanceFdCOThetamin115[i] > 3)
        		  			GeneratedEventsEMCmax182RFdgt3km +=1;
        		  	if (VectorGenDistanceFdCOThetamin115[i] > 4)
        		  			GeneratedEventsEMCmax182RFdgt4km +=1;
        		  	if (VectorGenDistanceFdCOThetamin115[i] > 5)
        		  			GeneratedEventsEMCmax182RFdgt5km +=1;

        				if(VectorEVENTidCOThetamin115[i]!=0 && pow(10, VectorlgErecCOThetamin115[i])!=0 && VectorlgErecCOThetamin115[i]!=-1)
        					{      EventsWithErecCOEMCmax182 += 1;
        					if (VectorGenDistanceFdCOThetamin115[i] > 1)
        					    EventsWithErecCOEMCmax182RFdgt1km  +=1;
        					if(VectorGenDistanceFdCOThetamin115[i]> 2)
        						EventsWithErecCOEMCmax182RFdgt2km +=1;
        					if(VectorGenDistanceFdCOThetamin115[i]> 3)
        						EventsWithErecCOEMCmax182RFdgt3km +=1;
        					if(VectorGenDistanceFdCOThetamin115[i]> 4)
        						EventsWithErecCOEMCmax182RFdgt4km +=1;
        					if(VectorGenDistanceFdCOThetamin115[i]> 5)
        						EventsWithErecCOEMCmax182RFdgt5km +=1;
        					}
        	            if(VectorEVENTidHEATThetamin115[i]!=0 && pow(10, VectorlgErecHEATThetamin115[i])!=0 && VectorlgErecHEATThetamin115[i]!=-1)
        	            	{    EventsWithErecHEATEMCmax182 += 1;
        	            		if (VectorGenDistanceFdHEATThetamin115[i] > 1)
        	            			EventsWithErecHEATEMCmax182RFdgt1km  +=1;
        	            		if(VectorGenDistanceFdHEATThetamin115[i]> 2)
        	            			EventsWithErecHEATEMCmax182RFdgt2km +=1;
        	            		if(VectorGenDistanceFdHEATThetamin115[i]> 3)
        	            		EventsWithErecHEATEMCmax182RFdgt3km +=1;
        	            		if(VectorGenDistanceFdHEATThetamin115[i]> 4)
        	            		EventsWithErecHEATEMCmax182RFdgt4km +=1;
        	            		if(VectorGenDistanceFdHEATThetamin115[i]> 5)
        	            		EventsWithErecHEATEMCmax182RFdgt5km +=1;
        	            	}
        			}
    else if(EnergyDouble>=18.2 && EnergyDouble<18.3)
        			{	GeneratedEventsEMCmax183+=1;
        			if (VectorGenDistanceFdCOThetamin115[i] > 1)
        					GeneratedEventsEMCmax183RFdgt1km +=1;
        		  	if (VectorGenDistanceFdCOThetamin115[i] > 2)
        		  			GeneratedEventsEMCmax183RFdgt2km +=1;
        		  	if (VectorGenDistanceFdCOThetamin115[i] > 3)
        		  			GeneratedEventsEMCmax183RFdgt3km +=1;
        		  	if (VectorGenDistanceFdCOThetamin115[i] > 4)
        		  			GeneratedEventsEMCmax183RFdgt4km +=1;
        		  	if (VectorGenDistanceFdCOThetamin115[i] > 5)
        		  			GeneratedEventsEMCmax183RFdgt5km +=1;

        				if(VectorEVENTidCOThetamin115[i]!=0 && pow(10, VectorlgErecCOThetamin115[i])!=0 && VectorlgErecCOThetamin115[i]!=-1)
        					{      EventsWithErecCOEMCmax183 += 1;
        					if (VectorGenDistanceFdCOThetamin115[i] > 1)
        					    EventsWithErecCOEMCmax183RFdgt1km  +=1;
        					if(VectorGenDistanceFdCOThetamin115[i]> 2)
        						EventsWithErecCOEMCmax183RFdgt2km +=1;
        					if(VectorGenDistanceFdCOThetamin115[i]> 3)
        						EventsWithErecCOEMCmax183RFdgt3km +=1;
        					if(VectorGenDistanceFdCOThetamin115[i]> 4)
        						EventsWithErecCOEMCmax183RFdgt4km +=1;
        					if(VectorGenDistanceFdCOThetamin115[i]> 5)
        						EventsWithErecCOEMCmax183RFdgt5km +=1;
        					}
        	            if(VectorEVENTidHEATThetamin115[i]!=0 && pow(10, VectorlgErecHEATThetamin115[i])!=0 && VectorlgErecHEATThetamin115[i]!=-1)
        	            	{    EventsWithErecHEATEMCmax183 += 1;
        	            		if (VectorGenDistanceFdHEATThetamin115[i] > 1)
        	            			EventsWithErecHEATEMCmax183RFdgt1km  +=1;
        	            		if(VectorGenDistanceFdHEATThetamin115[i]> 2)
        	            			EventsWithErecHEATEMCmax183RFdgt2km +=1;
        	            		if(VectorGenDistanceFdHEATThetamin115[i]> 3)
        	            		EventsWithErecHEATEMCmax183RFdgt3km +=1;
        	            		if(VectorGenDistanceFdHEATThetamin115[i]> 4)
        	            		EventsWithErecHEATEMCmax183RFdgt4km +=1;
        	            		if(VectorGenDistanceFdHEATThetamin115[i]> 5)
        	            		EventsWithErecHEATEMCmax183RFdgt5km +=1;
        	            	}
        			}
    else if(EnergyDouble>=18.3 && EnergyDouble<18.4)
        			{	GeneratedEventsEMCmax184+=1;
        			if (VectorGenDistanceFdCOThetamin115[i] > 1)
        					GeneratedEventsEMCmax184RFdgt1km +=1;
        		  	if (VectorGenDistanceFdCOThetamin115[i] > 2)
        		  			GeneratedEventsEMCmax184RFdgt2km +=1;
        		  	if (VectorGenDistanceFdCOThetamin115[i] > 3)
        		  			GeneratedEventsEMCmax184RFdgt3km +=1;
        		  	if (VectorGenDistanceFdCOThetamin115[i] > 4)
        		  			GeneratedEventsEMCmax184RFdgt4km +=1;
        		  	if (VectorGenDistanceFdCOThetamin115[i] > 5)
        		  			GeneratedEventsEMCmax184RFdgt5km +=1;

        				if(VectorEVENTidCOThetamin115[i]!=0 && pow(10, VectorlgErecCOThetamin115[i])!=0 && VectorlgErecCOThetamin115[i]!=-1)
        					{      EventsWithErecCOEMCmax184 += 1;
        					if (VectorGenDistanceFdCOThetamin115[i] > 1)
        					    EventsWithErecCOEMCmax184RFdgt1km  +=1;
        					if(VectorGenDistanceFdCOThetamin115[i]> 2)
        						EventsWithErecCOEMCmax184RFdgt2km +=1;
        					if(VectorGenDistanceFdCOThetamin115[i]> 3)
        						EventsWithErecCOEMCmax184RFdgt3km +=1;
        					if(VectorGenDistanceFdCOThetamin115[i]> 4)
        						EventsWithErecCOEMCmax184RFdgt4km +=1;
        					if(VectorGenDistanceFdCOThetamin115[i]> 5)
        						EventsWithErecCOEMCmax184RFdgt5km +=1;
        					}
        	            if(VectorEVENTidHEATThetamin115[i]!=0 && pow(10, VectorlgErecHEATThetamin115[i])!=0 && VectorlgErecHEATThetamin115[i]!=-1)
        	            	{    EventsWithErecHEATEMCmax184 += 1;
        	            		if (VectorGenDistanceFdHEATThetamin115[i] > 1)
        	            			EventsWithErecHEATEMCmax184RFdgt1km  +=1;
        	            		if(VectorGenDistanceFdHEATThetamin115[i]> 2)
        	            			EventsWithErecHEATEMCmax184RFdgt2km +=1;
        	            		if(VectorGenDistanceFdHEATThetamin115[i]> 3)
        	            		EventsWithErecHEATEMCmax184RFdgt3km +=1;
        	            		if(VectorGenDistanceFdHEATThetamin115[i]> 4)
        	            		EventsWithErecHEATEMCmax184RFdgt4km +=1;
        	            		if(VectorGenDistanceFdHEATThetamin115[i]> 5)
        	            		EventsWithErecHEATEMCmax184RFdgt5km +=1;
        	            	}
        			}
    else if(EnergyDouble>=18.4 && EnergyDouble<18.5)
        			{	GeneratedEventsEMCmax185+=1;
        			if (VectorGenDistanceFdCOThetamin115[i] > 1)
        					GeneratedEventsEMCmax185RFdgt1km +=1;
        		  	if (VectorGenDistanceFdCOThetamin115[i] > 2)
        		  			GeneratedEventsEMCmax185RFdgt2km +=1;
        		  	if (VectorGenDistanceFdCOThetamin115[i] > 3)
        		  			GeneratedEventsEMCmax185RFdgt3km +=1;
        		  	if (VectorGenDistanceFdCOThetamin115[i] > 4)
        		  			GeneratedEventsEMCmax185RFdgt4km +=1;
        		  	if (VectorGenDistanceFdCOThetamin115[i] > 5)
        		  			GeneratedEventsEMCmax185RFdgt5km +=1;

        				if(VectorEVENTidCOThetamin115[i]!=0 && pow(10, VectorlgErecCOThetamin115[i])!=0 && VectorlgErecCOThetamin115[i]!=-1)
        					{      EventsWithErecCOEMCmax185 += 1;
        					if (VectorGenDistanceFdCOThetamin115[i] > 1)
        					    EventsWithErecCOEMCmax185RFdgt1km  +=1;
        					if(VectorGenDistanceFdCOThetamin115[i]> 2)
        						EventsWithErecCOEMCmax185RFdgt2km +=1;
        					if(VectorGenDistanceFdCOThetamin115[i]> 3)
        						EventsWithErecCOEMCmax185RFdgt3km +=1;
        					if(VectorGenDistanceFdCOThetamin115[i]> 4)
        						EventsWithErecCOEMCmax185RFdgt4km +=1;
        					if(VectorGenDistanceFdCOThetamin115[i]> 5)
        						EventsWithErecCOEMCmax185RFdgt5km +=1;
        					}
        	            if(VectorEVENTidHEATThetamin115[i]!=0 && pow(10, VectorlgErecHEATThetamin115[i])!=0 && VectorlgErecHEATThetamin115[i]!=-1)
        	            	{    EventsWithErecHEATEMCmax185 += 1;
        	            		if (VectorGenDistanceFdHEATThetamin115[i] > 1)
        	            			EventsWithErecHEATEMCmax185RFdgt1km  +=1;
        	            		if(VectorGenDistanceFdHEATThetamin115[i]> 2)
        	            			EventsWithErecHEATEMCmax185RFdgt2km +=1;
        	            		if(VectorGenDistanceFdHEATThetamin115[i]> 3)
        	            		EventsWithErecHEATEMCmax185RFdgt3km +=1;
        	            		if(VectorGenDistanceFdHEATThetamin115[i]> 4)
        	            		EventsWithErecHEATEMCmax185RFdgt4km +=1;
        	            		if(VectorGenDistanceFdHEATThetamin115[i]> 5)
        	            		EventsWithErecHEATEMCmax185RFdgt5km +=1;
        	            	}
        			}
    else if(EnergyDouble>=18.5)
        			{	GeneratedEventsEMCeq185+=1;
        			if (VectorGenDistanceFdCOThetamin115[i] > 1)
        					GeneratedEventsEMCeq185RFdgt1km +=1;
        		  	if (VectorGenDistanceFdCOThetamin115[i] > 2)
        		  			GeneratedEventsEMCeq185RFdgt2km +=1;
        		  	if (VectorGenDistanceFdCOThetamin115[i] > 3)
        		  			GeneratedEventsEMCeq185RFdgt3km +=1;
        		  	if (VectorGenDistanceFdCOThetamin115[i] > 4)
        		  			GeneratedEventsEMCeq185RFdgt4km +=1;
        		  	if (VectorGenDistanceFdCOThetamin115[i] > 5)
        		  			GeneratedEventsEMCeq185RFdgt5km +=1;

        				if(VectorEVENTidCOThetamin115[i]!=0 && pow(10, VectorlgErecCOThetamin115[i])!=0 && VectorlgErecCOThetamin115[i]!=-1)
        					{      EventsWithErecCOEMCeq185 += 1;
        					if (VectorGenDistanceFdCOThetamin115[i] > 1)
        					    EventsWithErecCOEMCeq185RFdgt1km  +=1;
        					if(VectorGenDistanceFdCOThetamin115[i]> 2)
        						EventsWithErecCOEMCeq185RFdgt2km +=1;
        					if(VectorGenDistanceFdCOThetamin115[i]> 3)
        						EventsWithErecCOEMCeq185RFdgt3km +=1;
        					if(VectorGenDistanceFdCOThetamin115[i]>4)
        						EventsWithErecCOEMCeq185RFdgt4km +=1;
        					if(VectorGenDistanceFdCOThetamin115[i]> 5)
        						EventsWithErecCOEMCeq185RFdgt5km +=1;
        					}
        	            if(VectorEVENTidHEATThetamin115[i]!=0 && pow(10, VectorlgErecHEATThetamin115[i])!=0 && VectorlgErecHEATThetamin115[i]!=-1)
        	            	{    EventsWithErecHEATEMCeq185 += 1;
        	            		if (VectorGenDistanceFdHEATThetamin115[i] > 1)
        	            			EventsWithErecHEATEMCeq185RFdgt1km  +=1;
        	            		if(VectorGenDistanceFdHEATThetamin115[i]> 2)
        	            			EventsWithErecHEATEMCeq185RFdgt2km +=1;
        	            		if(VectorGenDistanceFdHEATThetamin115[i]> 3)
        	            		EventsWithErecHEATEMCeq185RFdgt3km +=1;
        	            		if(VectorGenDistanceFdHEATThetamin115[i]> 4)
        	            		EventsWithErecHEATEMCeq185RFdgt4km +=1;
        	            		if(VectorGenDistanceFdHEATThetamin115[i]> 5)
        	            		EventsWithErecHEATEMCeq185RFdgt5km +=1;
        	            	}
        			}


    }






double etaEEMCmax171; //etaE=recEvents/GenEvents ->reconstruction efficiency
etaEEMCmax171 = EventsWithErecCOEMCmax171 / GeneratedEventsEMCmax171;

double etaEHEATEMCmax171;
etaEHEATEMCmax171 = EventsWithErecHEATEMCmax171 / GeneratedEventsEMCmax171;
cout<<"etaE: "<<etaEEMCmax171<<endl;
ErrorEvents.push_back(sqrt(EventsWithErecCOEMCmax171 )/ GeneratedEventsEMCmax171);

double etaEEMCmax171RFdgt1km;
etaEEMCmax171RFdgt1km = EventsWithErecCOEMCmax171RFdgt1km / GeneratedEventsEMCmax171RFdgt1km;
double etaEEMCmax171RFdgt2km;
etaEEMCmax171RFdgt2km = EventsWithErecCOEMCmax171RFdgt2km / GeneratedEventsEMCmax171RFdgt2km;
double etaEEMCmax171RFdgt3km;
etaEEMCmax171RFdgt3km = EventsWithErecCOEMCmax171RFdgt3km / GeneratedEventsEMCmax171RFdgt3km;
double etaEEMCmax171RFdgt4km;
etaEEMCmax171RFdgt4km = EventsWithErecCOEMCmax171RFdgt4km / GeneratedEventsEMCmax171RFdgt4km;
double etaEEMCmax171RFdgt5km;
etaEEMCmax171RFdgt5km = EventsWithErecCOEMCmax171RFdgt5km / GeneratedEventsEMCmax171RFdgt5km;

double etaEHEATEMCmax171RFdgt1km;
etaEHEATEMCmax171RFdgt1km = EventsWithErecHEATEMCmax171RFdgt1km / GeneratedEventsEMCmax171RFdgt1km;
double etaEHEATEMCmax171RFdgt2km;
etaEHEATEMCmax171RFdgt2km = EventsWithErecHEATEMCmax171RFdgt2km / GeneratedEventsEMCmax171RFdgt2km;
double etaEHEATEMCmax171RFdgt3km;
etaEHEATEMCmax171RFdgt3km = EventsWithErecHEATEMCmax171RFdgt3km / GeneratedEventsEMCmax171RFdgt3km;
double etaEHEATEMCmax171RFdgt4km;
etaEHEATEMCmax171RFdgt4km = EventsWithErecHEATEMCmax171RFdgt4km / GeneratedEventsEMCmax171RFdgt4km;
double etaEHEATEMCmax171RFdgt5km;
etaEHEATEMCmax171RFdgt5km = EventsWithErecHEATEMCmax171RFdgt5km / GeneratedEventsEMCmax171RFdgt5km;

cout<<"total gen events: "<<TotalNrGenEvents<<" in (17, 17.1) nr of gen Events = "<<GeneratedEventsEMCmax171<<endl;


cout<<"nr or reconstructed ev: "<<EventsWithErecCOEMCmax171<<"  rec events with r>1 for E = 17  is : "<<EventsWithErecCOEMCmax171RFdgt1km
		<<"  rec events with r>2 for E = 17  is : "<<EventsWithErecCOEMCmax171RFdgt2km<<"  rec events with r>1 for E = 17  is : "<<EventsWithErecCOEMCmax171RFdgt3km<<endl;





const double pi =  3.14159265;
const double Rfd = 35; //(in km) max radius away from FD.

const double genAreaCO = pi * Rfd * Rfd / 2;       //events thrown only in front of FD. area = half of circle in km^2
const double genAreaLM = genAreaCO;
const double genAreaLA = genAreaCO;
const double genAreaLL180FOV = genAreaCO;
const double genAreaLL162FOV = 0.9 * genAreaCO; //162/360 pi r^2 = 0.45 * 2 * ACO
const double genAreaHEAT = genAreaCO;

const double R1 = 1;  // for rejecting events in 1, 2 or 3 km vecinity of the FD
const double R2 = 2;
const double R3 = 3;
const double R4 = 4;
const double R5 = 5;

//for calculating the area for events with R_FD > 1, 2 or 3 km: from the area we have (half a circle of radius = 35 km) substract the area of half a circle with R = 1, 2 or 3 km
const double genAreaCORgt1 = genAreaCO - ( pi * R1 * R1 /2 );
const double genAreaLMRgt1 = genAreaCORgt1;
const double genAreaLARgt1 = genAreaCORgt1;
const double genAreaLL180FOVRgt1 =  genAreaCORgt1;
const double genAreaLL162FOVRgt1 = 0.9 * genAreaCORgt1;
const double genAreaHEATRgt1 =  genAreaCORgt1;

const double genAreaCORgt2 = genAreaCO - ( pi * R2 * R2 /2 );
const double genAreaLMRgt2 = genAreaCORgt2;
const double genAreaLARgt2 = genAreaCORgt2;
const double genAreaLL180FOVRgt2 =  genAreaCORgt2;
const double genAreaLL162FOVRgt2 = 0.9 * genAreaCORgt2;
const double genAreaHEATRgt2 =  genAreaCORgt2;

const double genAreaCORgt3 = genAreaCO - ( pi * R3 * R3 /2 );
const double genAreaLMRgt3 = genAreaCORgt3;
const double genAreaLARgt3 = genAreaCORgt3;
const double genAreaLL180FOVRgt3 =  genAreaCORgt3;
const double genAreaLL162FOVRgt3 = 0.9 * genAreaCORgt3;
const double genAreaHEATRgt3 =  genAreaCORgt3;

const double genAreaCORgt4 = genAreaCO - ( pi * R4 * R4 /2 );
const double genAreaLMRgt4 = genAreaCORgt4;
const double genAreaLARgt4 = genAreaCORgt4;
const double genAreaLL180FOVRgt4 =  genAreaCORgt4;
const double genAreaLL162FOVRgt4 = 0.9 * genAreaCORgt4;
const double genAreaHEATRgt4 =  genAreaCORgt4;

const double genAreaCORgt5 = genAreaCO - ( pi * R5 * R5 /2 );
const double genAreaLMRgt5 = genAreaCORgt5;
const double genAreaLARgt5 = genAreaCORgt5;
const double genAreaLL180FOVRgt5 =  genAreaCORgt5;
const double genAreaLL162FOVRgt5 = 0.9 * genAreaCORgt5;
const double genAreaHEATRgt5 =  genAreaCORgt5;

const double secondsToYears = 3.17098E-8;
// FD upTime values are for period: 01.07.2007 - 01.10.2019 (root trees made by Julian) [in years]
double yearsCO = secondsToYears * 5.59668E7;
double yearsLM = secondsToYears * 5.65838E7;
double yearsLA = secondsToYears * 5.37016E7;

double yearsHEAT = secondsToYears * 3.54701E7;         //taking into account Heat Up Position
		//before taking into accoutn HEAT up positon: tHEAT = 4.29719E7;


//since LL doesnt have the full FOV anymore, FOV = 162 deg since 14.07.2009, we divide the exposure calc in 2 periods: 1 with FOV = 180 (before 14.07.2009)
//, 1 with FOV = 162 (after 14.07.2009). this will appear in the exposure calculation for LL

double yearsLL180FOV = secondsToYears * 8.50147E6;
double yearsLL162FOV = secondsToYears * 4.65102E7;




//cout<<"years CO: "<<yearsCO <<"years LM: "<<yearsLM<<"years LA: "<<yearsLA<<" years LL FOV-180"<<yearsLL180FOV<<"  "<<"years LL FOv-162"<<yearsLL162FOV<<endl;
//cout<<"gen area CO:" <<genAreaCO<<" LM: "<<genAreaLM<<" LA: "<<genAreaLA<<"LL 180 fov: "<<genAreaLL180FOV<<" LL162 FOV: "<<genAreaLL162FOV<<endl;



//vector< vector<double> > ExposureCoihuecoH0; //array with all exposure as a fct of energy and angles
//vector<double> ExposureCoihuecoAllEnergiesH0; //vector with all Exposures for H0
//vector<double> ExposureLMAllEnergiesH0;
//vector<double> ExposureLAAllEnergiesH0;
//vector<double> ExposureLLAllEnergiesH0;

vector<double> Exposure4EyesAllEnergiesThetamin115H0; // vector with the total exposure of the FD for 4 telescopes. HEAT TO BE ADDED!!!
vector<double> EnergyRangeVector;

vector<double> Exposure4EyesAllEnergiesThetamin115H0Rgt1;
vector<double> Exposure4EyesAllEnergiesThetamin115H0Rgt2;
vector<double> Exposure4EyesAllEnergiesThetamin115H0Rgt3;
vector<double> Exposure4EyesAllEnergiesThetamin115H0Rgt4;
vector<double> Exposure4EyesAllEnergiesThetamin115H0Rgt5;


vector<double>ErrorExposureRgt1;
vector<double>ErrorExposureRgt2;
vector<double>ErrorExposureRgt3;
vector<double>ErrorExposureRgt4;
vector<double>ErrorExposureRgt5;


//vector< vector<double> > Exposure4EyesH0; //array with all exposure as a fct of energy and angles



double apertureCoihuecoThetamin115EMCmax171 = etaEEMCmax171 * genAreaCO *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureCoihuecoThetamin115EMCmax171 = apertureCoihuecoThetamin115EMCmax171 * yearsCO;

double apertureLMThetamin115EMCmax171 = etaEEMCmax171 * genAreaLM *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLMThetamin115EMCmax171 = apertureLMThetamin115EMCmax171 * yearsLM;

  double apertureLAThetamin115EMCmax171 = etaEEMCmax171 * genAreaLA *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLAThetamin115EMCmax171 = apertureLAThetamin115EMCmax171 * yearsLA;

    double apertureLL180FOVThetamin115EMCmax171 = etaEEMCmax171 * genAreaLL180FOV *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLL180FOVThetamin115EMCmax171 = apertureLL180FOVThetamin115EMCmax171 * yearsLL180FOV;

  double apertureLL162FOVThetamin115EMCmax171 = etaEEMCmax171 * genAreaLL162FOV *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLL162FOVThetamin115EMCmax171 = apertureLL162FOVThetamin115EMCmax171 * yearsLL162FOV;

  double exposureLLEmin17Thetamin115EMCmax171 = exposureLL180FOVThetamin115EMCmax171 + exposureLL162FOVThetamin115EMCmax171;

  double apertureHEATThetamin115EMCmax171 = etaEHEATEMCmax171 * genAreaHEAT *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureHEATThetamin115EMCmax171 = apertureHEATThetamin115EMCmax171 * yearsHEAT;


  double Exposure4EyesThetamin115EMCmax171 = exposureCoihuecoThetamin115EMCmax171 + exposureLMThetamin115EMCmax171 +
                                            exposureLAThetamin115EMCmax171 + exposureLLEmin17Thetamin115EMCmax171 +	exposureHEATThetamin115EMCmax171;

  Exposure4EyesAllEnergiesThetamin115H0.push_back(Exposure4EyesThetamin115EMCmax171);


  double exposureCoihuecoThetamin115EMCmax171Rgt1 = etaEEMCmax171RFdgt1km * genAreaCORgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;
  double exposureCoihuecoThetamin115EMCmax171Rgt2 = etaEEMCmax171RFdgt2km * genAreaCORgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;
  double exposureCoihuecoThetamin115EMCmax171Rgt3 = etaEEMCmax171RFdgt3km * genAreaCORgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;

  double exposureLMThetamin115EMCmax171Rgt1 = etaEEMCmax171RFdgt1km * genAreaLMRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;
  double exposureLMThetamin115EMCmax171Rgt2 = etaEEMCmax171RFdgt2km * genAreaLMRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;
  double exposureLMThetamin115EMCmax171Rgt3 = etaEEMCmax171RFdgt3km * genAreaLMRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;

  double exposureLAThetamin115EMCmax171Rgt1 = etaEEMCmax171RFdgt1km * genAreaLARgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;
  double exposureLAThetamin115EMCmax171Rgt2 = etaEEMCmax171RFdgt2km * genAreaLARgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;
  double exposureLAThetamin115EMCmax171Rgt3 = etaEEMCmax171RFdgt3km * genAreaLARgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;

  double exposureLL180FOVThetamin115EMCmax171Rgt1 = etaEEMCmax171RFdgt1km * genAreaLL180FOVRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;
  double exposureLL180FOVThetamin115EMCmax171Rgt2 = etaEEMCmax171RFdgt2km * genAreaLL180FOVRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;
  double exposureLL180FOVThetamin115EMCmax171Rgt3 = etaEEMCmax171RFdgt3km * genAreaLL180FOVRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;

  double exposureLL162FOVThetamin115EMCmax171Rgt1 = etaEEMCmax171RFdgt1km * genAreaLL162FOVRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;
  double exposureLL162FOVThetamin115EMCmax171Rgt2 = etaEEMCmax171RFdgt2km * genAreaLL162FOVRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;
  double exposureLL162FOVThetamin115EMCmax171Rgt3 = etaEEMCmax171RFdgt3km * genAreaLL162FOVRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;

  double exposureLLEmin17Thetamin115EMCmax171Rgt1 =  exposureLL180FOVThetamin115EMCmax171Rgt1 + exposureLL162FOVThetamin115EMCmax171Rgt1;
  double exposureLLEmin17Thetamin115EMCmax171Rgt2 =  exposureLL180FOVThetamin115EMCmax171Rgt2 + exposureLL162FOVThetamin115EMCmax171Rgt2;
  double exposureLLEmin17Thetamin115EMCmax171Rgt3 =  exposureLL180FOVThetamin115EMCmax171Rgt3 + exposureLL162FOVThetamin115EMCmax171Rgt3;



  double exposureCoihuecoThetamin115EMCmax171Rgt4 = etaEEMCmax171RFdgt4km * genAreaCORgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;
  double exposureCoihuecoThetamin115EMCmax171Rgt5 = etaEEMCmax171RFdgt5km * genAreaCORgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;

  double exposureLMThetamin115EMCmax171Rgt4 = etaEEMCmax171RFdgt4km * genAreaLMRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;
  double exposureLMThetamin115EMCmax171Rgt5 = etaEEMCmax171RFdgt5km * genAreaLMRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;

  double exposureLAThetamin115EMCmax171Rgt4 = etaEEMCmax171RFdgt4km * genAreaLARgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;
  double exposureLAThetamin115EMCmax171Rgt5 = etaEEMCmax171RFdgt5km * genAreaLARgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;

  double exposureLL180FOVThetamin115EMCmax171Rgt4 = etaEEMCmax171RFdgt4km * genAreaLL180FOVRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;
  double exposureLL180FOVThetamin115EMCmax171Rgt5 = etaEEMCmax171RFdgt5km * genAreaLL180FOVRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;

  double exposureLL162FOVThetamin115EMCmax171Rgt4 = etaEEMCmax171RFdgt4km * genAreaLL162FOVRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;
  double exposureLL162FOVThetamin115EMCmax171Rgt5 = etaEEMCmax171RFdgt5km * genAreaLL162FOVRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;

  double exposureLLEmin17Thetamin115EMCmax171Rgt4 =  exposureLL180FOVThetamin115EMCmax171Rgt4 + exposureLL162FOVThetamin115EMCmax171Rgt4;
  double exposureLLEmin17Thetamin115EMCmax171Rgt5 =  exposureLL180FOVThetamin115EMCmax171Rgt5 + exposureLL162FOVThetamin115EMCmax171Rgt5;


  double exposureHEATThetamin115EMCmax171Rgt1 = etaEHEATEMCmax171RFdgt1km* genAreaHEATRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCmax171Rgt2 = etaEHEATEMCmax171RFdgt2km* genAreaHEATRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCmax171Rgt3 = etaEHEATEMCmax171RFdgt3km* genAreaHEATRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCmax171Rgt4 = etaEHEATEMCmax171RFdgt4km* genAreaHEATRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCmax171Rgt5 = etaEHEATEMCmax171RFdgt5km* genAreaHEATRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;


  Exposure4EyesAllEnergiesThetamin115H0Rgt4.push_back( exposureCoihuecoThetamin115EMCmax171Rgt4 +   exposureLMThetamin115EMCmax171Rgt4
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax171Rgt4 + exposureLLEmin17Thetamin115EMCmax171Rgt4
																													+ exposureHEATThetamin115EMCmax171Rgt4 );
  Exposure4EyesAllEnergiesThetamin115H0Rgt5.push_back( exposureCoihuecoThetamin115EMCmax171Rgt5 +   exposureLMThetamin115EMCmax171Rgt5
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax171Rgt5 + exposureLLEmin17Thetamin115EMCmax171Rgt5
																													+ exposureHEATThetamin115EMCmax171Rgt5);

  Exposure4EyesAllEnergiesThetamin115H0Rgt1.push_back( exposureCoihuecoThetamin115EMCmax171Rgt1 +   exposureLMThetamin115EMCmax171Rgt1
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax171Rgt1 + exposureLLEmin17Thetamin115EMCmax171Rgt1
																													+ exposureHEATThetamin115EMCmax171Rgt1);
  Exposure4EyesAllEnergiesThetamin115H0Rgt2.push_back( exposureCoihuecoThetamin115EMCmax171Rgt2 +   exposureLMThetamin115EMCmax171Rgt2
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax171Rgt2 + exposureLLEmin17Thetamin115EMCmax171Rgt2
																													+  exposureHEATThetamin115EMCmax171Rgt2);
  Exposure4EyesAllEnergiesThetamin115H0Rgt3.push_back( exposureCoihuecoThetamin115EMCmax171Rgt3 +   exposureLMThetamin115EMCmax171Rgt3
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax171Rgt3 + exposureLLEmin17Thetamin115EMCmax171Rgt3
																													+  exposureHEATThetamin115EMCmax171Rgt3);

 EnergyRangeVector.push_back(17);

double etaErrorExposurePlusEMCmax171 ;
double etaErrorCOPlusEMCmax171;
double etaErrorLMPlusEMCmax171;
double etaErrorLAPlusEMCmax171;
double etaErrorLLPlusEMCmax171;
double etaErrorHEATPlusEMCmax171;

if( etaEEMCmax171!=0)
		{
		etaErrorCOPlusEMCmax171 = (sqrt(EventsWithErecCOEMCmax171 ) / GeneratedEventsEMCmax171 ) * (exposureCoihuecoThetamin115EMCmax171 /  etaEEMCmax171) ;
		etaErrorLMPlusEMCmax171 = ( sqrt(EventsWithErecCOEMCmax171 ) / GeneratedEventsEMCmax171 ) * (exposureLMThetamin115EMCmax171) /  etaEEMCmax171;
		etaErrorLAPlusEMCmax171 = ( sqrt(EventsWithErecCOEMCmax171 ) / GeneratedEventsEMCmax171 ) * (exposureLAThetamin115EMCmax171)/  etaEEMCmax171 ;
		etaErrorLLPlusEMCmax171 = (sqrt(EventsWithErecCOEMCmax171 ) / GeneratedEventsEMCmax171 ) *	(exposureLLEmin17Thetamin115EMCmax171) /  etaEEMCmax171;

		cout<<"check shit: "<<etaErrorCOPlusEMCmax171<<endl;
		}
else
		{
			etaErrorCOPlusEMCmax171 = 0 ;
			etaErrorLMPlusEMCmax171 = 0;
			etaErrorLAPlusEMCmax171 =0 ;
			etaErrorLLPlusEMCmax171 =0;
		}
	if(etaEHEATEMCmax171!=0)
		etaErrorHEATPlusEMCmax171 = (sqrt(EventsWithErecHEATEMCmax171 ) / GeneratedEventsEMCmax171 ) * (exposureHEATThetamin115EMCmax171)/  etaEHEATEMCmax171 ;
	else
		etaErrorHEATPlusEMCmax171 = 0;


etaErrorExposurePlusEMCmax171 = sqrt(  etaErrorCOPlusEMCmax171*etaErrorCOPlusEMCmax171 + etaErrorLMPlusEMCmax171*etaErrorLMPlusEMCmax171 +
																etaErrorLAPlusEMCmax171*etaErrorLAPlusEMCmax171 +  etaErrorLLPlusEMCmax171* etaErrorLLPlusEMCmax171
																+etaErrorHEATPlusEMCmax171*etaErrorHEATPlusEMCmax171);

cout<<" E=17  "<<"Error Total Exposure  "<<etaErrorExposurePlusEMCmax171 <<endl;

cout<<"exposure CO: "<<exposureCoihuecoThetamin115EMCmax171 << " error: "<<etaErrorCOPlusEMCmax171<<endl;
cout<<"exposure LA: "<<exposureLAThetamin115EMCmax171 << " error: "<<etaErrorLAPlusEMCmax171<<endl;
cout<<"exposure LM: "<<exposureLMThetamin115EMCmax171 << " error: "<<etaErrorLMPlusEMCmax171<<endl;
cout<<"exposure LL: "<<exposureLLEmin17Thetamin115EMCmax171 << " error: "<<etaErrorLLPlusEMCmax171<<endl;
cout<<"exposure HEAT: "<<exposureHEATThetamin115EMCmax171 << " error: "<<etaErrorHEATPlusEMCmax171<<endl;


ErrorExposurePlus.push_back(etaErrorExposurePlusEMCmax171);


double etaErrorExposureEMCmax171Rgt1;
double etaErrorCOPlusEMCmax171Rgt1;
double etaErrorLMPlusEMCmax171Rgt1;
double etaErrorLAPlusEMCmax171Rgt1;
double etaErrorLLPlusEMCmax171Rgt1;
double etaErrorHEATPlusEMCmax171Rgt1;

if(etaEEMCmax171RFdgt1km!=0)
		{
		etaErrorCOPlusEMCmax171Rgt1 = (sqrt(EventsWithErecCOEMCmax171RFdgt1km ) / GeneratedEventsEMCmax171RFdgt1km ) * (exposureCoihuecoThetamin115EMCmax171Rgt1 /  etaEEMCmax171RFdgt1km) ;
		etaErrorLMPlusEMCmax171Rgt1 = ( sqrt(EventsWithErecCOEMCmax171RFdgt1km ) / GeneratedEventsEMCmax171RFdgt1km ) * (exposureLMThetamin115EMCmax171Rgt1) /  etaEEMCmax171RFdgt1km;
		etaErrorLAPlusEMCmax171Rgt1 = ( sqrt(EventsWithErecCOEMCmax171RFdgt1km ) / GeneratedEventsEMCmax171RFdgt1km ) * (exposureLAThetamin115EMCmax171Rgt1)/  etaEEMCmax171RFdgt1km ;
		etaErrorLLPlusEMCmax171Rgt1 = (sqrt(EventsWithErecCOEMCmax171RFdgt1km ) / GeneratedEventsEMCmax171RFdgt1km ) *	(exposureLLEmin17Thetamin115EMCmax171Rgt1) /  etaEEMCmax171RFdgt1km;
		}
else
		{
		etaErrorCOPlusEMCmax171Rgt1 =0;
		etaErrorLMPlusEMCmax171Rgt1 = 0;
		etaErrorLAPlusEMCmax171Rgt1 = 0 ;
		etaErrorLLPlusEMCmax171Rgt1 =0;
		}

	if( etaEHEATEMCmax171RFdgt1km!=0)
	etaErrorHEATPlusEMCmax171Rgt1 = (sqrt(EventsWithErecHEATEMCmax171RFdgt1km ) / GeneratedEventsEMCmax171RFdgt1km ) * (exposureHEATThetamin115EMCmax171Rgt1)/  etaEHEATEMCmax171RFdgt1km ;
	else
	etaErrorHEATPlusEMCmax171Rgt1 =0;

etaErrorExposureEMCmax171Rgt1 = sqrt(  etaErrorCOPlusEMCmax171Rgt1*etaErrorCOPlusEMCmax171Rgt1 + etaErrorLMPlusEMCmax171Rgt1*etaErrorLMPlusEMCmax171Rgt1 +
		etaErrorLAPlusEMCmax171Rgt1*etaErrorLAPlusEMCmax171Rgt1 +  etaErrorLLPlusEMCmax171Rgt1* etaErrorLLPlusEMCmax171Rgt1
		+etaErrorHEATPlusEMCmax171Rgt1*etaErrorHEATPlusEMCmax171Rgt1);

ErrorExposureRgt1.push_back(  etaErrorExposureEMCmax171Rgt1  );


double etaErrorExposureEMCmax171Rgt2;
double etaErrorCOPlusEMCmax171Rgt2;
double etaErrorLMPlusEMCmax171Rgt2;
double etaErrorLAPlusEMCmax171Rgt2;
double etaErrorLLPlusEMCmax171Rgt2;
double etaErrorHEATPlusEMCmax171Rgt2;

if(etaEEMCmax171RFdgt2km!=0)
		{
		etaErrorCOPlusEMCmax171Rgt2 = (sqrt(EventsWithErecCOEMCmax171RFdgt2km ) / GeneratedEventsEMCmax171RFdgt2km ) * (exposureCoihuecoThetamin115EMCmax171Rgt2 /  etaEEMCmax171RFdgt2km) ;
		etaErrorLMPlusEMCmax171Rgt2 = ( sqrt(EventsWithErecCOEMCmax171RFdgt2km ) / GeneratedEventsEMCmax171RFdgt2km ) * (exposureLMThetamin115EMCmax171Rgt2) /  etaEEMCmax171RFdgt2km;
		etaErrorLAPlusEMCmax171Rgt2 = ( sqrt(EventsWithErecCOEMCmax171RFdgt2km ) / GeneratedEventsEMCmax171RFdgt2km ) * (exposureLAThetamin115EMCmax171Rgt2)/  etaEEMCmax171RFdgt2km ;
		etaErrorLLPlusEMCmax171Rgt2 = (sqrt(EventsWithErecCOEMCmax171RFdgt2km ) / GeneratedEventsEMCmax171RFdgt2km ) *	(exposureLLEmin17Thetamin115EMCmax171Rgt2) /  etaEEMCmax171RFdgt2km;
		}
else
		{
		etaErrorCOPlusEMCmax171Rgt2 =0;
		etaErrorLMPlusEMCmax171Rgt2 = 0;
		etaErrorLAPlusEMCmax171Rgt2 = 0 ;
		etaErrorLLPlusEMCmax171Rgt2 =0;
		}

	if( etaEHEATEMCmax171RFdgt2km!=0)
	etaErrorHEATPlusEMCmax171Rgt2 = (sqrt(EventsWithErecHEATEMCmax171RFdgt2km ) / GeneratedEventsEMCmax171RFdgt2km ) * (exposureHEATThetamin115EMCmax171Rgt2)/  etaEHEATEMCmax171RFdgt2km ;
	else
	etaErrorHEATPlusEMCmax171Rgt2 =0;

etaErrorExposureEMCmax171Rgt2 = sqrt(  etaErrorCOPlusEMCmax171Rgt2*etaErrorCOPlusEMCmax171Rgt2 + etaErrorLMPlusEMCmax171Rgt2*etaErrorLMPlusEMCmax171Rgt2 +
		etaErrorLAPlusEMCmax171Rgt2*etaErrorLAPlusEMCmax171Rgt2 +  etaErrorLLPlusEMCmax171Rgt2* etaErrorLLPlusEMCmax171Rgt2
		+etaErrorHEATPlusEMCmax171Rgt2*etaErrorHEATPlusEMCmax171Rgt2);

ErrorExposureRgt2.push_back(  etaErrorExposureEMCmax171Rgt2  );

double etaErrorExposureEMCmax171Rgt3;
double etaErrorCOPlusEMCmax171Rgt3;
double etaErrorLMPlusEMCmax171Rgt3;
double etaErrorLAPlusEMCmax171Rgt3;
double etaErrorLLPlusEMCmax171Rgt3;
double etaErrorHEATPlusEMCmax171Rgt3;

if(etaEEMCmax171RFdgt3km!=0)
		{
		etaErrorCOPlusEMCmax171Rgt3 = (sqrt(EventsWithErecCOEMCmax171RFdgt3km ) / GeneratedEventsEMCmax171RFdgt3km ) * (exposureCoihuecoThetamin115EMCmax171Rgt3 /  etaEEMCmax171RFdgt3km) ;
		etaErrorLMPlusEMCmax171Rgt3 = ( sqrt(EventsWithErecCOEMCmax171RFdgt3km ) / GeneratedEventsEMCmax171RFdgt3km ) * (exposureLMThetamin115EMCmax171Rgt3) /  etaEEMCmax171RFdgt3km;
		etaErrorLAPlusEMCmax171Rgt3 = ( sqrt(EventsWithErecCOEMCmax171RFdgt3km ) / GeneratedEventsEMCmax171RFdgt3km ) * (exposureLAThetamin115EMCmax171Rgt3)/  etaEEMCmax171RFdgt3km ;
		etaErrorLLPlusEMCmax171Rgt3 = (sqrt(EventsWithErecCOEMCmax171RFdgt3km ) / GeneratedEventsEMCmax171RFdgt3km ) *	(exposureLLEmin17Thetamin115EMCmax171Rgt3) /  etaEEMCmax171RFdgt3km;
		}
else
		{
		etaErrorCOPlusEMCmax171Rgt3 =0;
		etaErrorLMPlusEMCmax171Rgt3 = 0;
		etaErrorLAPlusEMCmax171Rgt3 = 0 ;
		etaErrorLLPlusEMCmax171Rgt3 =0;
		}

	if( etaEHEATEMCmax171RFdgt3km!=0)
	etaErrorHEATPlusEMCmax171Rgt3 = (sqrt(EventsWithErecHEATEMCmax171RFdgt3km ) / GeneratedEventsEMCmax171RFdgt3km ) * (exposureHEATThetamin115EMCmax171Rgt3)/  etaEHEATEMCmax171RFdgt3km ;
	else
	etaErrorHEATPlusEMCmax171Rgt3 =0;

etaErrorExposureEMCmax171Rgt3 = sqrt(  etaErrorCOPlusEMCmax171Rgt3*etaErrorCOPlusEMCmax171Rgt3 + etaErrorLMPlusEMCmax171Rgt3*etaErrorLMPlusEMCmax171Rgt3 +
		etaErrorLAPlusEMCmax171Rgt3*etaErrorLAPlusEMCmax171Rgt3 +  etaErrorLLPlusEMCmax171Rgt3* etaErrorLLPlusEMCmax171Rgt3
		+etaErrorHEATPlusEMCmax171Rgt3*etaErrorHEATPlusEMCmax171Rgt3);

ErrorExposureRgt3.push_back(  etaErrorExposureEMCmax171Rgt3  );


double etaErrorExposureEMCmax171Rgt4;
double etaErrorCOPlusEMCmax171Rgt4;
double etaErrorLMPlusEMCmax171Rgt4;
double etaErrorLAPlusEMCmax171Rgt4;
double etaErrorLLPlusEMCmax171Rgt4;
double etaErrorHEATPlusEMCmax171Rgt4;

if(etaEEMCmax171RFdgt4km!=0)
		{
		etaErrorCOPlusEMCmax171Rgt4 = (sqrt(EventsWithErecCOEMCmax171RFdgt4km ) / GeneratedEventsEMCmax171RFdgt4km ) * (exposureCoihuecoThetamin115EMCmax171Rgt4 /  etaEEMCmax171RFdgt4km) ;
		etaErrorLMPlusEMCmax171Rgt4 = ( sqrt(EventsWithErecCOEMCmax171RFdgt4km ) / GeneratedEventsEMCmax171RFdgt4km ) * (exposureLMThetamin115EMCmax171Rgt4) /  etaEEMCmax171RFdgt4km;
		etaErrorLAPlusEMCmax171Rgt4 = ( sqrt(EventsWithErecCOEMCmax171RFdgt4km ) / GeneratedEventsEMCmax171RFdgt4km ) * (exposureLAThetamin115EMCmax171Rgt4)/  etaEEMCmax171RFdgt4km ;
		etaErrorLLPlusEMCmax171Rgt4 = (sqrt(EventsWithErecCOEMCmax171RFdgt4km ) / GeneratedEventsEMCmax171RFdgt4km ) *	(exposureLLEmin17Thetamin115EMCmax171Rgt4) /  etaEEMCmax171RFdgt4km;
		}
else
		{
		etaErrorCOPlusEMCmax171Rgt4 =0;
		etaErrorLMPlusEMCmax171Rgt4 = 0;
		etaErrorLAPlusEMCmax171Rgt4 = 0 ;
		etaErrorLLPlusEMCmax171Rgt4 =0;
		}

	if( etaEHEATEMCmax171RFdgt4km!=0)
	etaErrorHEATPlusEMCmax171Rgt4 = (sqrt(EventsWithErecHEATEMCmax171RFdgt4km ) / GeneratedEventsEMCmax171RFdgt4km ) * (exposureHEATThetamin115EMCmax171Rgt4)/  etaEHEATEMCmax171RFdgt4km ;
	else
	etaErrorHEATPlusEMCmax171Rgt4 =0;

etaErrorExposureEMCmax171Rgt4 = sqrt(  etaErrorCOPlusEMCmax171Rgt4*etaErrorCOPlusEMCmax171Rgt4 + etaErrorLMPlusEMCmax171Rgt4*etaErrorLMPlusEMCmax171Rgt4 +
		etaErrorLAPlusEMCmax171Rgt4*etaErrorLAPlusEMCmax171Rgt4 +  etaErrorLLPlusEMCmax171Rgt4* etaErrorLLPlusEMCmax171Rgt4
		+etaErrorHEATPlusEMCmax171Rgt4*etaErrorHEATPlusEMCmax171Rgt4);

ErrorExposureRgt4.push_back(  etaErrorExposureEMCmax171Rgt4  );


double etaErrorExposureEMCmax171Rgt5;
double etaErrorCOPlusEMCmax171Rgt5;
double etaErrorLMPlusEMCmax171Rgt5;
double etaErrorLAPlusEMCmax171Rgt5;
double etaErrorLLPlusEMCmax171Rgt5;
double etaErrorHEATPlusEMCmax171Rgt5;

if(etaEEMCmax171RFdgt5km!=0)
		{
		etaErrorCOPlusEMCmax171Rgt5 = (sqrt(EventsWithErecCOEMCmax171RFdgt5km ) / GeneratedEventsEMCmax171RFdgt5km ) * (exposureCoihuecoThetamin115EMCmax171Rgt5 /  etaEEMCmax171RFdgt5km) ;
		etaErrorLMPlusEMCmax171Rgt5 = ( sqrt(EventsWithErecCOEMCmax171RFdgt5km ) / GeneratedEventsEMCmax171RFdgt5km ) * (exposureLMThetamin115EMCmax171Rgt5) /  etaEEMCmax171RFdgt5km;
		etaErrorLAPlusEMCmax171Rgt5 = ( sqrt(EventsWithErecCOEMCmax171RFdgt5km ) / GeneratedEventsEMCmax171RFdgt5km ) * (exposureLAThetamin115EMCmax171Rgt5)/  etaEEMCmax171RFdgt5km ;
		etaErrorLLPlusEMCmax171Rgt5 = (sqrt(EventsWithErecCOEMCmax171RFdgt5km ) / GeneratedEventsEMCmax171RFdgt5km ) *	(exposureLLEmin17Thetamin115EMCmax171Rgt5) /  etaEEMCmax171RFdgt5km;
		}
else
		{
		etaErrorCOPlusEMCmax171Rgt5 =0;
		etaErrorLMPlusEMCmax171Rgt5 = 0;
		etaErrorLAPlusEMCmax171Rgt5 = 0 ;
		etaErrorLLPlusEMCmax171Rgt5 =0;
		}

	if( etaEHEATEMCmax171RFdgt5km!=0)
	etaErrorHEATPlusEMCmax171Rgt5 = (sqrt(EventsWithErecHEATEMCmax171RFdgt5km ) / GeneratedEventsEMCmax171RFdgt5km ) * (exposureHEATThetamin115EMCmax171Rgt5)/  etaEHEATEMCmax171RFdgt5km ;
	else
	etaErrorHEATPlusEMCmax171Rgt5 =0;

etaErrorExposureEMCmax171Rgt5 = sqrt(  etaErrorCOPlusEMCmax171Rgt5*etaErrorCOPlusEMCmax171Rgt5 + etaErrorLMPlusEMCmax171Rgt5*etaErrorLMPlusEMCmax171Rgt5 +
		etaErrorLAPlusEMCmax171Rgt5*etaErrorLAPlusEMCmax171Rgt5 +  etaErrorLLPlusEMCmax171Rgt5* etaErrorLLPlusEMCmax171Rgt5
		+etaErrorHEATPlusEMCmax171Rgt5*etaErrorHEATPlusEMCmax171Rgt5);

ErrorExposureRgt5.push_back(  etaErrorExposureEMCmax171Rgt5  );


cout<<"E = 17 , etaErrorExposureEMCmax171Rgt5 = "<<etaErrorExposureEMCmax171Rgt5<<   "etaErrorHEATPlusEMCmax171Rgt5"<<etaErrorHEATPlusEMCmax171Rgt5 <<
		"GeneratedEventsEMCmax171RFdgt5km"<<GeneratedEventsEMCmax171RFdgt5km<<endl;




//cout<<" r > 1      Exposure =  : " << exposureCoihuecoThetamin115EMCmax171Rgt1 +   exposureLMThetamin115EMCmax171Rgt1
//	  	  	  	  	+ exposureLAThetamin115EMCmax171Rgt1 + exposureLLEmin17Thetamin115EMCmax171Rgt1 << " error exposure: = "<<
//					 ( (exposureCoihuecoThetamin115EMCmax171Rgt1 +   exposureLMThetamin115EMCmax171Rgt1
//						  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax171Rgt1 + exposureLLEmin17Thetamin115EMCmax171Rgt1 ) / etaEEMCmax171RFdgt1km ) *etaErrorExposureEMCmax171Rgt1
//																- (exposureCoihuecoThetamin115EMCmax171Rgt1 +   exposureLMThetamin115EMCmax171Rgt1
//								  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax171Rgt1 + exposureLLEmin17Thetamin115EMCmax171Rgt1 ) <<endl;


double etaEEMCmax172; //etaE=recEvents/GenEvents ->reconstruction efficiency
etaEEMCmax172 = EventsWithErecCOEMCmax172 / GeneratedEventsEMCmax172;

double etaEHEATEMCmax172;
etaEHEATEMCmax172 = EventsWithErecHEATEMCmax172 / GeneratedEventsEMCmax172;
cout<<"etaE (E = 17.1): "<<etaEEMCmax172<<endl;
ErrorEvents.push_back(sqrt(EventsWithErecCOEMCmax172 ));

double etaEEMCmax172RFdgt1km;
etaEEMCmax172RFdgt1km = EventsWithErecCOEMCmax172RFdgt1km / GeneratedEventsEMCmax172RFdgt1km;
double etaEEMCmax172RFdgt2km;
etaEEMCmax172RFdgt2km = EventsWithErecCOEMCmax172RFdgt2km / GeneratedEventsEMCmax172RFdgt2km;
double etaEEMCmax172RFdgt3km;
etaEEMCmax172RFdgt3km = EventsWithErecCOEMCmax172RFdgt3km / GeneratedEventsEMCmax172RFdgt3km;
double etaEEMCmax172RFdgt4km;
etaEEMCmax172RFdgt4km = EventsWithErecCOEMCmax172RFdgt4km / GeneratedEventsEMCmax172RFdgt4km;
double etaEEMCmax172RFdgt5km;
etaEEMCmax172RFdgt5km = EventsWithErecCOEMCmax172RFdgt5km / GeneratedEventsEMCmax172RFdgt5km;

double etaEHEATEMCmax172RFdgt1km;
etaEHEATEMCmax172RFdgt1km = EventsWithErecHEATEMCmax172RFdgt1km / GeneratedEventsEMCmax172RFdgt1km;
double etaEHEATEMCmax172RFdgt2km;
etaEHEATEMCmax172RFdgt2km = EventsWithErecHEATEMCmax172RFdgt2km / GeneratedEventsEMCmax172RFdgt2km;
double etaEHEATEMCmax172RFdgt3km;
etaEHEATEMCmax172RFdgt3km = EventsWithErecHEATEMCmax172RFdgt3km / GeneratedEventsEMCmax172RFdgt3km;
double etaEHEATEMCmax172RFdgt4km;
etaEHEATEMCmax172RFdgt4km = EventsWithErecHEATEMCmax172RFdgt4km / GeneratedEventsEMCmax172RFdgt4km;
double etaEHEATEMCmax172RFdgt5km;
etaEHEATEMCmax172RFdgt5km = EventsWithErecHEATEMCmax172RFdgt5km / GeneratedEventsEMCmax172RFdgt5km;


cout<<"total gen events: "<<TotalNrGenEvents<<" in (17.1, 17.2) nr of gen Events XXXXXXX= "<<GeneratedEventsEMCmax172<<endl;


cout<<"nr or reconstructed ev: "<<EventsWithErecCOEMCmax172<<endl;

double apertureCoihuecoThetamin115EMCmax172 = etaEEMCmax172 * genAreaCO *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureCoihuecoThetamin115EMCmax172 = apertureCoihuecoThetamin115EMCmax172 * yearsCO;

double apertureLMThetamin115EMCmax172 = etaEEMCmax172 * genAreaLM *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLMThetamin115EMCmax172 = apertureLMThetamin115EMCmax172 * yearsLM;

  double apertureLAThetamin115EMCmax172 = etaEEMCmax172 * genAreaLA *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLAThetamin115EMCmax172 = apertureLAThetamin115EMCmax172 * yearsLA;

    double apertureLL180FOVThetamin115EMCmax172 = etaEEMCmax172 * genAreaLL180FOV *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLL180FOVThetamin115EMCmax172 = apertureLL180FOVThetamin115EMCmax172 * yearsLL180FOV;

  double apertureLL162FOVThetamin115EMCmax172 = etaEEMCmax172 * genAreaLL162FOV *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLL162FOVThetamin115EMCmax172 = apertureLL162FOVThetamin115EMCmax172 * yearsLL162FOV;

  double exposureLLEmin17Thetamin115EMCmax172 = exposureLL180FOVThetamin115EMCmax172 + exposureLL162FOVThetamin115EMCmax172;

  double apertureHEATThetamin115EMCmax172 = etaEHEATEMCmax172 * genAreaHEAT *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureHEATThetamin115EMCmax172 = apertureHEATThetamin115EMCmax172 * yearsHEAT;


  double Exposure4EyesThetamin115EMCmax172 = exposureCoihuecoThetamin115EMCmax172 + exposureLMThetamin115EMCmax172 +
                                            exposureLAThetamin115EMCmax172 + exposureLLEmin17Thetamin115EMCmax172 +	exposureHEATThetamin115EMCmax172;

  Exposure4EyesAllEnergiesThetamin115H0.push_back(Exposure4EyesThetamin115EMCmax172);


  double exposureCoihuecoThetamin115EMCmax172Rgt1 = etaEEMCmax172RFdgt1km * genAreaCORgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;
  double exposureCoihuecoThetamin115EMCmax172Rgt2 = etaEEMCmax172RFdgt2km * genAreaCORgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;
  double exposureCoihuecoThetamin115EMCmax172Rgt3 = etaEEMCmax172RFdgt3km * genAreaCORgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;

  double exposureLMThetamin115EMCmax172Rgt1 = etaEEMCmax172RFdgt1km * genAreaLMRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;
  double exposureLMThetamin115EMCmax172Rgt2 = etaEEMCmax172RFdgt2km * genAreaLMRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;
  double exposureLMThetamin115EMCmax172Rgt3 = etaEEMCmax172RFdgt3km * genAreaLMRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;

  double exposureLAThetamin115EMCmax172Rgt1 = etaEEMCmax172RFdgt1km * genAreaLARgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;
  double exposureLAThetamin115EMCmax172Rgt2 = etaEEMCmax172RFdgt2km * genAreaLARgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;
  double exposureLAThetamin115EMCmax172Rgt3 = etaEEMCmax172RFdgt3km * genAreaLARgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;

  double exposureLL180FOVThetamin115EMCmax172Rgt1 = etaEEMCmax172RFdgt1km * genAreaLL180FOVRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;
  double exposureLL180FOVThetamin115EMCmax172Rgt2 = etaEEMCmax172RFdgt2km * genAreaLL180FOVRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;
  double exposureLL180FOVThetamin115EMCmax172Rgt3 = etaEEMCmax172RFdgt3km * genAreaLL180FOVRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;

  double exposureLL162FOVThetamin115EMCmax172Rgt1 = etaEEMCmax172RFdgt1km * genAreaLL162FOVRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;
  double exposureLL162FOVThetamin115EMCmax172Rgt2 = etaEEMCmax172RFdgt2km * genAreaLL162FOVRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;
  double exposureLL162FOVThetamin115EMCmax172Rgt3 = etaEEMCmax172RFdgt3km * genAreaLL162FOVRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;

  double exposureLLEmin17Thetamin115EMCmax172Rgt1 =  exposureLL180FOVThetamin115EMCmax172Rgt1 + exposureLL162FOVThetamin115EMCmax172Rgt1;
  double exposureLLEmin17Thetamin115EMCmax172Rgt2 =  exposureLL180FOVThetamin115EMCmax172Rgt2 + exposureLL162FOVThetamin115EMCmax172Rgt2;
  double exposureLLEmin17Thetamin115EMCmax172Rgt3 =  exposureLL180FOVThetamin115EMCmax172Rgt3 + exposureLL162FOVThetamin115EMCmax172Rgt3;



  double exposureCoihuecoThetamin115EMCmax172Rgt4 = etaEEMCmax172RFdgt4km * genAreaCORgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;
  double exposureCoihuecoThetamin115EMCmax172Rgt5 = etaEEMCmax172RFdgt5km * genAreaCORgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;

  double exposureLMThetamin115EMCmax172Rgt4 = etaEEMCmax172RFdgt4km * genAreaLMRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;
  double exposureLMThetamin115EMCmax172Rgt5 = etaEEMCmax172RFdgt5km * genAreaLMRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;

  double exposureLAThetamin115EMCmax172Rgt4 = etaEEMCmax172RFdgt4km * genAreaLARgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;
  double exposureLAThetamin115EMCmax172Rgt5 = etaEEMCmax172RFdgt5km * genAreaLARgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;

  double exposureLL180FOVThetamin115EMCmax172Rgt4 = etaEEMCmax172RFdgt4km * genAreaLL180FOVRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;
  double exposureLL180FOVThetamin115EMCmax172Rgt5 = etaEEMCmax172RFdgt5km * genAreaLL180FOVRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;

  double exposureLL162FOVThetamin115EMCmax172Rgt4 = etaEEMCmax172RFdgt4km * genAreaLL162FOVRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;
  double exposureLL162FOVThetamin115EMCmax172Rgt5 = etaEEMCmax172RFdgt5km * genAreaLL162FOVRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;

  double exposureLLEmin17Thetamin115EMCmax172Rgt4 =  exposureLL180FOVThetamin115EMCmax172Rgt4 + exposureLL162FOVThetamin115EMCmax172Rgt4;
  double exposureLLEmin17Thetamin115EMCmax172Rgt5 =  exposureLL180FOVThetamin115EMCmax172Rgt5 + exposureLL162FOVThetamin115EMCmax172Rgt5;


  double exposureHEATThetamin115EMCmax172Rgt1 = etaEHEATEMCmax172RFdgt1km* genAreaHEATRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCmax172Rgt2 = etaEHEATEMCmax172RFdgt2km* genAreaHEATRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCmax172Rgt3 = etaEHEATEMCmax172RFdgt3km* genAreaHEATRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCmax172Rgt4 = etaEHEATEMCmax172RFdgt4km* genAreaHEATRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCmax172Rgt5 = etaEHEATEMCmax172RFdgt5km* genAreaHEATRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;


  Exposure4EyesAllEnergiesThetamin115H0Rgt4.push_back( exposureCoihuecoThetamin115EMCmax172Rgt4 +   exposureLMThetamin115EMCmax172Rgt4
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax172Rgt4 + exposureLLEmin17Thetamin115EMCmax172Rgt4
																													+ exposureHEATThetamin115EMCmax172Rgt4 );
  Exposure4EyesAllEnergiesThetamin115H0Rgt5.push_back( exposureCoihuecoThetamin115EMCmax172Rgt5 +   exposureLMThetamin115EMCmax172Rgt5
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax172Rgt5 + exposureLLEmin17Thetamin115EMCmax172Rgt5
																													+ exposureHEATThetamin115EMCmax172Rgt5);

  Exposure4EyesAllEnergiesThetamin115H0Rgt1.push_back( exposureCoihuecoThetamin115EMCmax172Rgt1 +   exposureLMThetamin115EMCmax172Rgt1
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax172Rgt1 + exposureLLEmin17Thetamin115EMCmax172Rgt1
																													+ exposureHEATThetamin115EMCmax172Rgt1);
  Exposure4EyesAllEnergiesThetamin115H0Rgt2.push_back( exposureCoihuecoThetamin115EMCmax172Rgt2 +   exposureLMThetamin115EMCmax172Rgt2
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax172Rgt2 + exposureLLEmin17Thetamin115EMCmax172Rgt2
																													+  exposureHEATThetamin115EMCmax172Rgt2);
  Exposure4EyesAllEnergiesThetamin115H0Rgt3.push_back( exposureCoihuecoThetamin115EMCmax172Rgt3 +   exposureLMThetamin115EMCmax172Rgt3
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax172Rgt3 + exposureLLEmin17Thetamin115EMCmax172Rgt3
																													+  exposureHEATThetamin115EMCmax172Rgt3);

 EnergyRangeVector.push_back(17.1);

 double etaErrorExposurePlusEMCmax172 ;
 double etaErrorCOPlusEMCmax172;
 double etaErrorLMPlusEMCmax172;
 double etaErrorLAPlusEMCmax172;
 double etaErrorLLPlusEMCmax172;
 double etaErrorHEATPlusEMCmax172;

 if( etaEEMCmax172!=0)
 		{
 		etaErrorCOPlusEMCmax172 = (sqrt(EventsWithErecCOEMCmax172 ) / GeneratedEventsEMCmax172 ) * (exposureCoihuecoThetamin115EMCmax172 /  etaEEMCmax172) ;
 		etaErrorLMPlusEMCmax172 = ( sqrt(EventsWithErecCOEMCmax172 ) / GeneratedEventsEMCmax172 ) * (exposureLMThetamin115EMCmax172) /  etaEEMCmax172;
 		etaErrorLAPlusEMCmax172 = ( sqrt(EventsWithErecCOEMCmax172 ) / GeneratedEventsEMCmax172 ) * (exposureLAThetamin115EMCmax172)/  etaEEMCmax172 ;
 		etaErrorLLPlusEMCmax172 = (sqrt(EventsWithErecCOEMCmax172 ) / GeneratedEventsEMCmax172 ) *	(exposureLLEmin17Thetamin115EMCmax172) /  etaEEMCmax172;
 		}
 else
 		{
 			etaErrorCOPlusEMCmax172 = 0 ;
 			etaErrorLMPlusEMCmax172 = 0;
 			etaErrorLAPlusEMCmax172 =0 ;
 			etaErrorLLPlusEMCmax172 =0;
 		}
 	if(etaEHEATEMCmax172!=0)
 		etaErrorHEATPlusEMCmax172 = (sqrt(EventsWithErecHEATEMCmax172 ) / GeneratedEventsEMCmax172 ) * (exposureHEATThetamin115EMCmax172)/  etaEHEATEMCmax172 ;
 	else
 		etaErrorHEATPlusEMCmax172 = 0;


 etaErrorExposurePlusEMCmax172 = sqrt(  etaErrorCOPlusEMCmax172*etaErrorCOPlusEMCmax172 + etaErrorLMPlusEMCmax172*etaErrorLMPlusEMCmax172 +
 																etaErrorLAPlusEMCmax172*etaErrorLAPlusEMCmax172 +  etaErrorLLPlusEMCmax172* etaErrorLLPlusEMCmax172
 																+etaErrorHEATPlusEMCmax172*etaErrorHEATPlusEMCmax172);

 cout<<" E=17  "<<"Error Total Exposure  "<<etaErrorExposurePlusEMCmax172 <<endl;

 cout<<"exposure CO: "<<exposureCoihuecoThetamin115EMCmax172 << " error: "<<etaErrorCOPlusEMCmax172<<endl;
 cout<<"exposure LA: "<<exposureLAThetamin115EMCmax172 << " error: "<<etaErrorLAPlusEMCmax172<<endl;
 cout<<"exposure LM: "<<exposureLMThetamin115EMCmax172 << " error: "<<etaErrorLMPlusEMCmax172<<endl;
 cout<<"exposure LL: "<<exposureLLEmin17Thetamin115EMCmax172 << " error: "<<etaErrorLLPlusEMCmax172<<endl;
 cout<<"exposure HEAT: "<<exposureHEATThetamin115EMCmax172 << " error: "<<etaErrorHEATPlusEMCmax172<<endl;


 ErrorExposurePlus.push_back(etaErrorExposurePlusEMCmax172);


 double etaErrorExposureEMCmax172Rgt1;
 double etaErrorCOPlusEMCmax172Rgt1;
 double etaErrorLMPlusEMCmax172Rgt1;
 double etaErrorLAPlusEMCmax172Rgt1;
 double etaErrorLLPlusEMCmax172Rgt1;
 double etaErrorHEATPlusEMCmax172Rgt1;

 if(etaEEMCmax172RFdgt1km!=0)
 		{
 		etaErrorCOPlusEMCmax172Rgt1 = (sqrt(EventsWithErecCOEMCmax172RFdgt1km ) / GeneratedEventsEMCmax172RFdgt1km ) * (exposureCoihuecoThetamin115EMCmax172Rgt1 /  etaEEMCmax172RFdgt1km) ;
 		etaErrorLMPlusEMCmax172Rgt1 = ( sqrt(EventsWithErecCOEMCmax172RFdgt1km ) / GeneratedEventsEMCmax172RFdgt1km ) * (exposureLMThetamin115EMCmax172Rgt1) /  etaEEMCmax172RFdgt1km;
 		etaErrorLAPlusEMCmax172Rgt1 = ( sqrt(EventsWithErecCOEMCmax172RFdgt1km ) / GeneratedEventsEMCmax172RFdgt1km ) * (exposureLAThetamin115EMCmax172Rgt1)/  etaEEMCmax172RFdgt1km ;
 		etaErrorLLPlusEMCmax172Rgt1 = (sqrt(EventsWithErecCOEMCmax172RFdgt1km ) / GeneratedEventsEMCmax172RFdgt1km ) *	(exposureLLEmin17Thetamin115EMCmax172Rgt1) /  etaEEMCmax172RFdgt1km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax172Rgt1 =0;
 		etaErrorLMPlusEMCmax172Rgt1 = 0;
 		etaErrorLAPlusEMCmax172Rgt1 = 0 ;
 		etaErrorLLPlusEMCmax172Rgt1 =0;
 		}

 	if( etaEHEATEMCmax172RFdgt1km!=0)
 	etaErrorHEATPlusEMCmax172Rgt1 = (sqrt(EventsWithErecHEATEMCmax172RFdgt1km ) / GeneratedEventsEMCmax172RFdgt1km ) * (exposureHEATThetamin115EMCmax172Rgt1)/  etaEHEATEMCmax172RFdgt1km ;
 	else
 	etaErrorHEATPlusEMCmax172Rgt1 =0;

 etaErrorExposureEMCmax172Rgt1 = sqrt(  etaErrorCOPlusEMCmax172Rgt1*etaErrorCOPlusEMCmax172Rgt1 + etaErrorLMPlusEMCmax172Rgt1*etaErrorLMPlusEMCmax172Rgt1 +
 		etaErrorLAPlusEMCmax172Rgt1*etaErrorLAPlusEMCmax172Rgt1 +  etaErrorLLPlusEMCmax172Rgt1* etaErrorLLPlusEMCmax172Rgt1
 		+etaErrorHEATPlusEMCmax172Rgt1*etaErrorHEATPlusEMCmax172Rgt1);

 ErrorExposureRgt1.push_back(  etaErrorExposureEMCmax172Rgt1  );


 double etaErrorExposureEMCmax172Rgt2;
 double etaErrorCOPlusEMCmax172Rgt2;
 double etaErrorLMPlusEMCmax172Rgt2;
 double etaErrorLAPlusEMCmax172Rgt2;
 double etaErrorLLPlusEMCmax172Rgt2;
 double etaErrorHEATPlusEMCmax172Rgt2;

 if(etaEEMCmax172RFdgt2km!=0)
 		{
 		etaErrorCOPlusEMCmax172Rgt2 = (sqrt(EventsWithErecCOEMCmax172RFdgt2km ) / GeneratedEventsEMCmax172RFdgt2km ) * (exposureCoihuecoThetamin115EMCmax172Rgt2 /  etaEEMCmax172RFdgt2km) ;
 		etaErrorLMPlusEMCmax172Rgt2 = ( sqrt(EventsWithErecCOEMCmax172RFdgt2km ) / GeneratedEventsEMCmax172RFdgt2km ) * (exposureLMThetamin115EMCmax172Rgt2) /  etaEEMCmax172RFdgt2km;
 		etaErrorLAPlusEMCmax172Rgt2 = ( sqrt(EventsWithErecCOEMCmax172RFdgt2km ) / GeneratedEventsEMCmax172RFdgt2km ) * (exposureLAThetamin115EMCmax172Rgt2)/  etaEEMCmax172RFdgt2km ;
 		etaErrorLLPlusEMCmax172Rgt2 = (sqrt(EventsWithErecCOEMCmax172RFdgt2km ) / GeneratedEventsEMCmax172RFdgt2km ) *	(exposureLLEmin17Thetamin115EMCmax172Rgt2) /  etaEEMCmax172RFdgt2km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax172Rgt2 =0;
 		etaErrorLMPlusEMCmax172Rgt2 = 0;
 		etaErrorLAPlusEMCmax172Rgt2 = 0 ;
 		etaErrorLLPlusEMCmax172Rgt2 =0;
 		}

 	if( etaEHEATEMCmax172RFdgt2km!=0)
 	etaErrorHEATPlusEMCmax172Rgt2 = (sqrt(EventsWithErecHEATEMCmax172RFdgt2km ) / GeneratedEventsEMCmax172RFdgt2km ) * (exposureHEATThetamin115EMCmax172Rgt2)/  etaEHEATEMCmax172RFdgt2km ;
 	else
 	etaErrorHEATPlusEMCmax172Rgt2 =0;

 etaErrorExposureEMCmax172Rgt2 = sqrt(  etaErrorCOPlusEMCmax172Rgt2*etaErrorCOPlusEMCmax172Rgt2 + etaErrorLMPlusEMCmax172Rgt2*etaErrorLMPlusEMCmax172Rgt2 +
 		etaErrorLAPlusEMCmax172Rgt2*etaErrorLAPlusEMCmax172Rgt2 +  etaErrorLLPlusEMCmax172Rgt2* etaErrorLLPlusEMCmax172Rgt2
 		+etaErrorHEATPlusEMCmax172Rgt2*etaErrorHEATPlusEMCmax172Rgt2);

 ErrorExposureRgt2.push_back(  etaErrorExposureEMCmax172Rgt2  );

 double etaErrorExposureEMCmax172Rgt3;
 double etaErrorCOPlusEMCmax172Rgt3;
 double etaErrorLMPlusEMCmax172Rgt3;
 double etaErrorLAPlusEMCmax172Rgt3;
 double etaErrorLLPlusEMCmax172Rgt3;
 double etaErrorHEATPlusEMCmax172Rgt3;

 if(etaEEMCmax172RFdgt3km!=0)
 		{
 		etaErrorCOPlusEMCmax172Rgt3 = (sqrt(EventsWithErecCOEMCmax172RFdgt3km ) / GeneratedEventsEMCmax172RFdgt3km ) * (exposureCoihuecoThetamin115EMCmax172Rgt3 /  etaEEMCmax172RFdgt3km) ;
 		etaErrorLMPlusEMCmax172Rgt3 = ( sqrt(EventsWithErecCOEMCmax172RFdgt3km ) / GeneratedEventsEMCmax172RFdgt3km ) * (exposureLMThetamin115EMCmax172Rgt3) /  etaEEMCmax172RFdgt3km;
 		etaErrorLAPlusEMCmax172Rgt3 = ( sqrt(EventsWithErecCOEMCmax172RFdgt3km ) / GeneratedEventsEMCmax172RFdgt3km ) * (exposureLAThetamin115EMCmax172Rgt3)/  etaEEMCmax172RFdgt3km ;
 		etaErrorLLPlusEMCmax172Rgt3 = (sqrt(EventsWithErecCOEMCmax172RFdgt3km ) / GeneratedEventsEMCmax172RFdgt3km ) *	(exposureLLEmin17Thetamin115EMCmax172Rgt3) /  etaEEMCmax172RFdgt3km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax172Rgt3 =0;
 		etaErrorLMPlusEMCmax172Rgt3 = 0;
 		etaErrorLAPlusEMCmax172Rgt3 = 0 ;
 		etaErrorLLPlusEMCmax172Rgt3 =0;
 		}

 	if( etaEHEATEMCmax172RFdgt3km!=0)
 	etaErrorHEATPlusEMCmax172Rgt3 = (sqrt(EventsWithErecHEATEMCmax172RFdgt3km ) / GeneratedEventsEMCmax172RFdgt3km ) * (exposureHEATThetamin115EMCmax172Rgt3)/  etaEHEATEMCmax172RFdgt3km ;
 	else
 	etaErrorHEATPlusEMCmax172Rgt3 =0;

 etaErrorExposureEMCmax172Rgt3 = sqrt(  etaErrorCOPlusEMCmax172Rgt3*etaErrorCOPlusEMCmax172Rgt3 + etaErrorLMPlusEMCmax172Rgt3*etaErrorLMPlusEMCmax172Rgt3 +
 		etaErrorLAPlusEMCmax172Rgt3*etaErrorLAPlusEMCmax172Rgt3 +  etaErrorLLPlusEMCmax172Rgt3* etaErrorLLPlusEMCmax172Rgt3
 		+etaErrorHEATPlusEMCmax172Rgt3*etaErrorHEATPlusEMCmax172Rgt3);

 ErrorExposureRgt3.push_back(  etaErrorExposureEMCmax172Rgt3  );


 double etaErrorExposureEMCmax172Rgt4;
 double etaErrorCOPlusEMCmax172Rgt4;
 double etaErrorLMPlusEMCmax172Rgt4;
 double etaErrorLAPlusEMCmax172Rgt4;
 double etaErrorLLPlusEMCmax172Rgt4;
 double etaErrorHEATPlusEMCmax172Rgt4;

 if(etaEEMCmax172RFdgt4km!=0)
 		{
 		etaErrorCOPlusEMCmax172Rgt4 = (sqrt(EventsWithErecCOEMCmax172RFdgt4km ) / GeneratedEventsEMCmax172RFdgt4km ) * (exposureCoihuecoThetamin115EMCmax172Rgt4 /  etaEEMCmax172RFdgt4km) ;
 		etaErrorLMPlusEMCmax172Rgt4 = ( sqrt(EventsWithErecCOEMCmax172RFdgt4km ) / GeneratedEventsEMCmax172RFdgt4km ) * (exposureLMThetamin115EMCmax172Rgt4) /  etaEEMCmax172RFdgt4km;
 		etaErrorLAPlusEMCmax172Rgt4 = ( sqrt(EventsWithErecCOEMCmax172RFdgt4km ) / GeneratedEventsEMCmax172RFdgt4km ) * (exposureLAThetamin115EMCmax172Rgt4)/  etaEEMCmax172RFdgt4km ;
 		etaErrorLLPlusEMCmax172Rgt4 = (sqrt(EventsWithErecCOEMCmax172RFdgt4km ) / GeneratedEventsEMCmax172RFdgt4km ) *	(exposureLLEmin17Thetamin115EMCmax172Rgt4) /  etaEEMCmax172RFdgt4km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax172Rgt4 =0;
 		etaErrorLMPlusEMCmax172Rgt4 = 0;
 		etaErrorLAPlusEMCmax172Rgt4 = 0 ;
 		etaErrorLLPlusEMCmax172Rgt4 =0;
 		}

 	if( etaEHEATEMCmax172RFdgt4km!=0)
 	etaErrorHEATPlusEMCmax172Rgt4 = (sqrt(EventsWithErecHEATEMCmax172RFdgt4km ) / GeneratedEventsEMCmax172RFdgt4km ) * (exposureHEATThetamin115EMCmax172Rgt4)/  etaEHEATEMCmax172RFdgt4km ;
 	else
 	etaErrorHEATPlusEMCmax172Rgt4 =0;

 etaErrorExposureEMCmax172Rgt4 = sqrt(  etaErrorCOPlusEMCmax172Rgt4*etaErrorCOPlusEMCmax172Rgt4 + etaErrorLMPlusEMCmax172Rgt4*etaErrorLMPlusEMCmax172Rgt4 +
 		etaErrorLAPlusEMCmax172Rgt4*etaErrorLAPlusEMCmax172Rgt4 +  etaErrorLLPlusEMCmax172Rgt4* etaErrorLLPlusEMCmax172Rgt4
 		+etaErrorHEATPlusEMCmax172Rgt4*etaErrorHEATPlusEMCmax172Rgt4);

 ErrorExposureRgt4.push_back(  etaErrorExposureEMCmax172Rgt4  );


 double etaErrorExposureEMCmax172Rgt5;
 double etaErrorCOPlusEMCmax172Rgt5;
 double etaErrorLMPlusEMCmax172Rgt5;
 double etaErrorLAPlusEMCmax172Rgt5;
 double etaErrorLLPlusEMCmax172Rgt5;
 double etaErrorHEATPlusEMCmax172Rgt5;

 if(etaEEMCmax172RFdgt5km!=0)
 		{
 		etaErrorCOPlusEMCmax172Rgt5 = (sqrt(EventsWithErecCOEMCmax172RFdgt5km ) / GeneratedEventsEMCmax172RFdgt5km ) * (exposureCoihuecoThetamin115EMCmax172Rgt5 /  etaEEMCmax172RFdgt5km) ;
 		etaErrorLMPlusEMCmax172Rgt5 = ( sqrt(EventsWithErecCOEMCmax172RFdgt5km ) / GeneratedEventsEMCmax172RFdgt5km ) * (exposureLMThetamin115EMCmax172Rgt5) /  etaEEMCmax172RFdgt5km;
 		etaErrorLAPlusEMCmax172Rgt5 = ( sqrt(EventsWithErecCOEMCmax172RFdgt5km ) / GeneratedEventsEMCmax172RFdgt5km ) * (exposureLAThetamin115EMCmax172Rgt5)/  etaEEMCmax172RFdgt5km ;
 		etaErrorLLPlusEMCmax172Rgt5 = (sqrt(EventsWithErecCOEMCmax172RFdgt5km ) / GeneratedEventsEMCmax172RFdgt5km ) *	(exposureLLEmin17Thetamin115EMCmax172Rgt5) /  etaEEMCmax172RFdgt5km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax172Rgt5 =0;
 		etaErrorLMPlusEMCmax172Rgt5 = 0;
 		etaErrorLAPlusEMCmax172Rgt5 = 0 ;
 		etaErrorLLPlusEMCmax172Rgt5 =0;
 		}

 	if( etaEHEATEMCmax172RFdgt5km!=0)
 	etaErrorHEATPlusEMCmax172Rgt5 = (sqrt(EventsWithErecHEATEMCmax172RFdgt5km ) / GeneratedEventsEMCmax172RFdgt5km ) * (exposureHEATThetamin115EMCmax172Rgt5)/  etaEHEATEMCmax172RFdgt5km ;
 	else
 	etaErrorHEATPlusEMCmax172Rgt5 =0;

 etaErrorExposureEMCmax172Rgt5 = sqrt(  etaErrorCOPlusEMCmax172Rgt5*etaErrorCOPlusEMCmax172Rgt5 + etaErrorLMPlusEMCmax172Rgt5*etaErrorLMPlusEMCmax172Rgt5 +
 		etaErrorLAPlusEMCmax172Rgt5*etaErrorLAPlusEMCmax172Rgt5 +  etaErrorLLPlusEMCmax172Rgt5* etaErrorLLPlusEMCmax172Rgt5
 		+etaErrorHEATPlusEMCmax172Rgt5*etaErrorHEATPlusEMCmax172Rgt5);

 ErrorExposureRgt5.push_back(  etaErrorExposureEMCmax172Rgt5  );


double etaEEMCmax173; //etaE=recEvents/GenEvents ->reconstruction efficiency
etaEEMCmax173 = EventsWithErecCOEMCmax173 / GeneratedEventsEMCmax173;

double etaEHEATEMCmax173;
etaEHEATEMCmax173 = EventsWithErecHEATEMCmax173 / GeneratedEventsEMCmax173;
cout<<"etaE (E = 17.2): "<<etaEEMCmax173<<endl;
ErrorEvents.push_back(sqrt(EventsWithErecCOEMCmax173 ));

double etaEEMCmax173RFdgt1km;
etaEEMCmax173RFdgt1km = EventsWithErecCOEMCmax173RFdgt1km / GeneratedEventsEMCmax173RFdgt1km;
double etaEEMCmax173RFdgt2km;
etaEEMCmax173RFdgt2km = EventsWithErecCOEMCmax173RFdgt2km / GeneratedEventsEMCmax173RFdgt2km;
double etaEEMCmax173RFdgt3km;
etaEEMCmax173RFdgt3km = EventsWithErecCOEMCmax173RFdgt3km / GeneratedEventsEMCmax173RFdgt3km;
double etaEEMCmax173RFdgt4km;
etaEEMCmax173RFdgt4km = EventsWithErecCOEMCmax173RFdgt4km / GeneratedEventsEMCmax173RFdgt4km;
double etaEEMCmax173RFdgt5km;
etaEEMCmax173RFdgt5km = EventsWithErecCOEMCmax173RFdgt5km / GeneratedEventsEMCmax173RFdgt5km;

double etaEHEATEMCmax173RFdgt1km;
etaEHEATEMCmax173RFdgt1km = EventsWithErecHEATEMCmax173RFdgt1km / GeneratedEventsEMCmax173RFdgt1km;
double etaEHEATEMCmax173RFdgt2km;
etaEHEATEMCmax173RFdgt2km = EventsWithErecHEATEMCmax173RFdgt2km / GeneratedEventsEMCmax173RFdgt2km;
double etaEHEATEMCmax173RFdgt3km;
etaEHEATEMCmax173RFdgt3km = EventsWithErecHEATEMCmax173RFdgt3km / GeneratedEventsEMCmax173RFdgt3km;
double etaEHEATEMCmax173RFdgt4km;
etaEHEATEMCmax173RFdgt4km = EventsWithErecHEATEMCmax173RFdgt4km / GeneratedEventsEMCmax173RFdgt4km;
double etaEHEATEMCmax173RFdgt5km;
etaEHEATEMCmax173RFdgt5km = EventsWithErecHEATEMCmax173RFdgt5km / GeneratedEventsEMCmax173RFdgt5km;

cout<<"total gen events: "<<TotalNrGenEvents<<" in (17.2, 17.3) nr of gen Events = "<<GeneratedEventsEMCmax173<<endl;


cout<<"nr or reconstructed ev: "<<EventsWithErecCOEMCmax173<<endl;



double apertureCoihuecoThetamin115EMCmax173 = etaEEMCmax173 * genAreaCO *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureCoihuecoThetamin115EMCmax173 = apertureCoihuecoThetamin115EMCmax173 * yearsCO;

double apertureLMThetamin115EMCmax173 = etaEEMCmax173 * genAreaLM *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLMThetamin115EMCmax173 = apertureLMThetamin115EMCmax173 * yearsLM;

  double apertureLAThetamin115EMCmax173 = etaEEMCmax173 * genAreaLA *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLAThetamin115EMCmax173 = apertureLAThetamin115EMCmax173 * yearsLA;

    double apertureLL180FOVThetamin115EMCmax173 = etaEEMCmax173 * genAreaLL180FOV *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLL180FOVThetamin115EMCmax173 = apertureLL180FOVThetamin115EMCmax173 * yearsLL180FOV;

  double apertureLL162FOVThetamin115EMCmax173 = etaEEMCmax173 * genAreaLL162FOV *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLL162FOVThetamin115EMCmax173 = apertureLL162FOVThetamin115EMCmax173 * yearsLL162FOV;

  double exposureLLEmin17Thetamin115EMCmax173 = exposureLL180FOVThetamin115EMCmax173 + exposureLL162FOVThetamin115EMCmax173;

  double apertureHEATThetamin115EMCmax173 = etaEHEATEMCmax173 * genAreaHEAT *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureHEATThetamin115EMCmax173 = apertureHEATThetamin115EMCmax173 * yearsHEAT;


  double Exposure4EyesThetamin115EMCmax173 = exposureCoihuecoThetamin115EMCmax173 + exposureLMThetamin115EMCmax173 +
                                            exposureLAThetamin115EMCmax173 + exposureLLEmin17Thetamin115EMCmax173 +	exposureHEATThetamin115EMCmax173;

  Exposure4EyesAllEnergiesThetamin115H0.push_back(Exposure4EyesThetamin115EMCmax173);


  double exposureCoihuecoThetamin115EMCmax173Rgt1 = etaEEMCmax173RFdgt1km * genAreaCORgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;
  double exposureCoihuecoThetamin115EMCmax173Rgt2 = etaEEMCmax173RFdgt2km * genAreaCORgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;
  double exposureCoihuecoThetamin115EMCmax173Rgt3 = etaEEMCmax173RFdgt3km * genAreaCORgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;

  double exposureLMThetamin115EMCmax173Rgt1 = etaEEMCmax173RFdgt1km * genAreaLMRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;
  double exposureLMThetamin115EMCmax173Rgt2 = etaEEMCmax173RFdgt2km * genAreaLMRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;
  double exposureLMThetamin115EMCmax173Rgt3 = etaEEMCmax173RFdgt3km * genAreaLMRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;

  double exposureLAThetamin115EMCmax173Rgt1 = etaEEMCmax173RFdgt1km * genAreaLARgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;
  double exposureLAThetamin115EMCmax173Rgt2 = etaEEMCmax173RFdgt2km * genAreaLARgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;
  double exposureLAThetamin115EMCmax173Rgt3 = etaEEMCmax173RFdgt3km * genAreaLARgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;

  double exposureLL180FOVThetamin115EMCmax173Rgt1 = etaEEMCmax173RFdgt1km * genAreaLL180FOVRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;
  double exposureLL180FOVThetamin115EMCmax173Rgt2 = etaEEMCmax173RFdgt2km * genAreaLL180FOVRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;
  double exposureLL180FOVThetamin115EMCmax173Rgt3 = etaEEMCmax173RFdgt3km * genAreaLL180FOVRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;

  double exposureLL162FOVThetamin115EMCmax173Rgt1 = etaEEMCmax173RFdgt1km * genAreaLL162FOVRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;
  double exposureLL162FOVThetamin115EMCmax173Rgt2 = etaEEMCmax173RFdgt2km * genAreaLL162FOVRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;
  double exposureLL162FOVThetamin115EMCmax173Rgt3 = etaEEMCmax173RFdgt3km * genAreaLL162FOVRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;

  double exposureLLEmin17Thetamin115EMCmax173Rgt1 =  exposureLL180FOVThetamin115EMCmax173Rgt1 + exposureLL162FOVThetamin115EMCmax173Rgt1;
  double exposureLLEmin17Thetamin115EMCmax173Rgt2 =  exposureLL180FOVThetamin115EMCmax173Rgt2 + exposureLL162FOVThetamin115EMCmax173Rgt2;
  double exposureLLEmin17Thetamin115EMCmax173Rgt3 =  exposureLL180FOVThetamin115EMCmax173Rgt3 + exposureLL162FOVThetamin115EMCmax173Rgt3;



  double exposureCoihuecoThetamin115EMCmax173Rgt4 = etaEEMCmax173RFdgt4km * genAreaCORgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;
  double exposureCoihuecoThetamin115EMCmax173Rgt5 = etaEEMCmax173RFdgt5km * genAreaCORgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;

  double exposureLMThetamin115EMCmax173Rgt4 = etaEEMCmax173RFdgt4km * genAreaLMRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;
  double exposureLMThetamin115EMCmax173Rgt5 = etaEEMCmax173RFdgt5km * genAreaLMRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;

  double exposureLAThetamin115EMCmax173Rgt4 = etaEEMCmax173RFdgt4km * genAreaLARgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;
  double exposureLAThetamin115EMCmax173Rgt5 = etaEEMCmax173RFdgt5km * genAreaLARgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;

  double exposureLL180FOVThetamin115EMCmax173Rgt4 = etaEEMCmax173RFdgt4km * genAreaLL180FOVRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;
  double exposureLL180FOVThetamin115EMCmax173Rgt5 = etaEEMCmax173RFdgt5km * genAreaLL180FOVRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;

  double exposureLL162FOVThetamin115EMCmax173Rgt4 = etaEEMCmax173RFdgt4km * genAreaLL162FOVRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;
  double exposureLL162FOVThetamin115EMCmax173Rgt5 = etaEEMCmax173RFdgt5km * genAreaLL162FOVRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;

  double exposureLLEmin17Thetamin115EMCmax173Rgt4 =  exposureLL180FOVThetamin115EMCmax173Rgt4 + exposureLL162FOVThetamin115EMCmax173Rgt4;
  double exposureLLEmin17Thetamin115EMCmax173Rgt5 =  exposureLL180FOVThetamin115EMCmax173Rgt5 + exposureLL162FOVThetamin115EMCmax173Rgt5;


  double exposureHEATThetamin115EMCmax173Rgt1 = etaEHEATEMCmax173RFdgt1km* genAreaHEATRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCmax173Rgt2 = etaEHEATEMCmax173RFdgt2km* genAreaHEATRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCmax173Rgt3 = etaEHEATEMCmax173RFdgt3km* genAreaHEATRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCmax173Rgt4 = etaEHEATEMCmax173RFdgt4km* genAreaHEATRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCmax173Rgt5 = etaEHEATEMCmax173RFdgt5km* genAreaHEATRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;


  Exposure4EyesAllEnergiesThetamin115H0Rgt4.push_back( exposureCoihuecoThetamin115EMCmax173Rgt4 +   exposureLMThetamin115EMCmax173Rgt4
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax173Rgt4 + exposureLLEmin17Thetamin115EMCmax173Rgt4
																													+ exposureHEATThetamin115EMCmax173Rgt4 );
  Exposure4EyesAllEnergiesThetamin115H0Rgt5.push_back( exposureCoihuecoThetamin115EMCmax173Rgt5 +   exposureLMThetamin115EMCmax173Rgt5
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax173Rgt5 + exposureLLEmin17Thetamin115EMCmax173Rgt5
																													+ exposureHEATThetamin115EMCmax173Rgt5);

  Exposure4EyesAllEnergiesThetamin115H0Rgt1.push_back( exposureCoihuecoThetamin115EMCmax173Rgt1 +   exposureLMThetamin115EMCmax173Rgt1
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax173Rgt1 + exposureLLEmin17Thetamin115EMCmax173Rgt1
																													+ exposureHEATThetamin115EMCmax173Rgt1);
  Exposure4EyesAllEnergiesThetamin115H0Rgt2.push_back( exposureCoihuecoThetamin115EMCmax173Rgt2 +   exposureLMThetamin115EMCmax173Rgt2
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax173Rgt2 + exposureLLEmin17Thetamin115EMCmax173Rgt2
																													+  exposureHEATThetamin115EMCmax173Rgt2);
  Exposure4EyesAllEnergiesThetamin115H0Rgt3.push_back( exposureCoihuecoThetamin115EMCmax173Rgt3 +   exposureLMThetamin115EMCmax173Rgt3
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax173Rgt3 + exposureLLEmin17Thetamin115EMCmax173Rgt3
																													+  exposureHEATThetamin115EMCmax173Rgt3);

 EnergyRangeVector.push_back(17.2);

 double etaErrorExposurePlusEMCmax173 ;
 double etaErrorCOPlusEMCmax173;
 double etaErrorLMPlusEMCmax173;
 double etaErrorLAPlusEMCmax173;
 double etaErrorLLPlusEMCmax173;
 double etaErrorHEATPlusEMCmax173;

 if( etaEEMCmax173!=0)
 		{
 		etaErrorCOPlusEMCmax173 = (sqrt(EventsWithErecCOEMCmax173 ) / GeneratedEventsEMCmax173 ) * (exposureCoihuecoThetamin115EMCmax173 /  etaEEMCmax173) ;
 		etaErrorLMPlusEMCmax173 = ( sqrt(EventsWithErecCOEMCmax173 ) / GeneratedEventsEMCmax173 ) * (exposureLMThetamin115EMCmax173) /  etaEEMCmax173;
 		etaErrorLAPlusEMCmax173 = ( sqrt(EventsWithErecCOEMCmax173 ) / GeneratedEventsEMCmax173 ) * (exposureLAThetamin115EMCmax173)/  etaEEMCmax173 ;
 		etaErrorLLPlusEMCmax173 = (sqrt(EventsWithErecCOEMCmax173 ) / GeneratedEventsEMCmax173 ) *	(exposureLLEmin17Thetamin115EMCmax173) /  etaEEMCmax173;
 		}
 else
 		{
 			etaErrorCOPlusEMCmax173 = 0 ;
 			etaErrorLMPlusEMCmax173 = 0;
 			etaErrorLAPlusEMCmax173 =0 ;
 			etaErrorLLPlusEMCmax173 =0;
 		}
 	if(etaEHEATEMCmax173!=0)
 		etaErrorHEATPlusEMCmax173 = (sqrt(EventsWithErecHEATEMCmax173 ) / GeneratedEventsEMCmax173 ) * (exposureHEATThetamin115EMCmax173)/  etaEHEATEMCmax173 ;
 	else
 		etaErrorHEATPlusEMCmax173 = 0;


 etaErrorExposurePlusEMCmax173 = sqrt(  etaErrorCOPlusEMCmax173*etaErrorCOPlusEMCmax173 + etaErrorLMPlusEMCmax173*etaErrorLMPlusEMCmax173 +
 																etaErrorLAPlusEMCmax173*etaErrorLAPlusEMCmax173 +  etaErrorLLPlusEMCmax173* etaErrorLLPlusEMCmax173
 																+etaErrorHEATPlusEMCmax173*etaErrorHEATPlusEMCmax173);

 cout<<" E=17  "<<"Error Total Exposure  "<<etaErrorExposurePlusEMCmax173 <<endl;

 cout<<"exposure CO: "<<exposureCoihuecoThetamin115EMCmax173 << " error: "<<etaErrorCOPlusEMCmax173<<endl;
 cout<<"exposure LA: "<<exposureLAThetamin115EMCmax173 << " error: "<<etaErrorLAPlusEMCmax173<<endl;
 cout<<"exposure LM: "<<exposureLMThetamin115EMCmax173 << " error: "<<etaErrorLMPlusEMCmax173<<endl;
 cout<<"exposure LL: "<<exposureLLEmin17Thetamin115EMCmax173 << " error: "<<etaErrorLLPlusEMCmax173<<endl;
 cout<<"exposure HEAT: "<<exposureHEATThetamin115EMCmax173 << " error: "<<etaErrorHEATPlusEMCmax173<<endl;


 ErrorExposurePlus.push_back(etaErrorExposurePlusEMCmax173);


 double etaErrorExposureEMCmax173Rgt1;
 double etaErrorCOPlusEMCmax173Rgt1;
 double etaErrorLMPlusEMCmax173Rgt1;
 double etaErrorLAPlusEMCmax173Rgt1;
 double etaErrorLLPlusEMCmax173Rgt1;
 double etaErrorHEATPlusEMCmax173Rgt1;

 if(etaEEMCmax173RFdgt1km!=0)
 		{
 		etaErrorCOPlusEMCmax173Rgt1 = (sqrt(EventsWithErecCOEMCmax173RFdgt1km ) / GeneratedEventsEMCmax173RFdgt1km ) * (exposureCoihuecoThetamin115EMCmax173Rgt1 /  etaEEMCmax173RFdgt1km) ;
 		etaErrorLMPlusEMCmax173Rgt1 = ( sqrt(EventsWithErecCOEMCmax173RFdgt1km ) / GeneratedEventsEMCmax173RFdgt1km ) * (exposureLMThetamin115EMCmax173Rgt1) /  etaEEMCmax173RFdgt1km;
 		etaErrorLAPlusEMCmax173Rgt1 = ( sqrt(EventsWithErecCOEMCmax173RFdgt1km ) / GeneratedEventsEMCmax173RFdgt1km ) * (exposureLAThetamin115EMCmax173Rgt1)/  etaEEMCmax173RFdgt1km ;
 		etaErrorLLPlusEMCmax173Rgt1 = (sqrt(EventsWithErecCOEMCmax173RFdgt1km ) / GeneratedEventsEMCmax173RFdgt1km ) *	(exposureLLEmin17Thetamin115EMCmax173Rgt1) /  etaEEMCmax173RFdgt1km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax173Rgt1 =0;
 		etaErrorLMPlusEMCmax173Rgt1 = 0;
 		etaErrorLAPlusEMCmax173Rgt1 = 0 ;
 		etaErrorLLPlusEMCmax173Rgt1 =0;
 		}

 	if( etaEHEATEMCmax173RFdgt1km!=0)
 	etaErrorHEATPlusEMCmax173Rgt1 = (sqrt(EventsWithErecHEATEMCmax173RFdgt1km ) / GeneratedEventsEMCmax173RFdgt1km ) * (exposureHEATThetamin115EMCmax173Rgt1)/  etaEHEATEMCmax173RFdgt1km ;
 	else
 	etaErrorHEATPlusEMCmax173Rgt1 =0;

 etaErrorExposureEMCmax173Rgt1 = sqrt(  etaErrorCOPlusEMCmax173Rgt1*etaErrorCOPlusEMCmax173Rgt1 + etaErrorLMPlusEMCmax173Rgt1*etaErrorLMPlusEMCmax173Rgt1 +
 		etaErrorLAPlusEMCmax173Rgt1*etaErrorLAPlusEMCmax173Rgt1 +  etaErrorLLPlusEMCmax173Rgt1* etaErrorLLPlusEMCmax173Rgt1
 		+etaErrorHEATPlusEMCmax173Rgt1*etaErrorHEATPlusEMCmax173Rgt1);

 ErrorExposureRgt1.push_back(  etaErrorExposureEMCmax173Rgt1  );


 double etaErrorExposureEMCmax173Rgt2;
 double etaErrorCOPlusEMCmax173Rgt2;
 double etaErrorLMPlusEMCmax173Rgt2;
 double etaErrorLAPlusEMCmax173Rgt2;
 double etaErrorLLPlusEMCmax173Rgt2;
 double etaErrorHEATPlusEMCmax173Rgt2;

 if(etaEEMCmax173RFdgt2km!=0)
 		{
 		etaErrorCOPlusEMCmax173Rgt2 = (sqrt(EventsWithErecCOEMCmax173RFdgt2km ) / GeneratedEventsEMCmax173RFdgt2km ) * (exposureCoihuecoThetamin115EMCmax173Rgt2 /  etaEEMCmax173RFdgt2km) ;
 		etaErrorLMPlusEMCmax173Rgt2 = ( sqrt(EventsWithErecCOEMCmax173RFdgt2km ) / GeneratedEventsEMCmax173RFdgt2km ) * (exposureLMThetamin115EMCmax173Rgt2) /  etaEEMCmax173RFdgt2km;
 		etaErrorLAPlusEMCmax173Rgt2 = ( sqrt(EventsWithErecCOEMCmax173RFdgt2km ) / GeneratedEventsEMCmax173RFdgt2km ) * (exposureLAThetamin115EMCmax173Rgt2)/  etaEEMCmax173RFdgt2km ;
 		etaErrorLLPlusEMCmax173Rgt2 = (sqrt(EventsWithErecCOEMCmax173RFdgt2km ) / GeneratedEventsEMCmax173RFdgt2km ) *	(exposureLLEmin17Thetamin115EMCmax173Rgt2) /  etaEEMCmax173RFdgt2km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax173Rgt2 =0;
 		etaErrorLMPlusEMCmax173Rgt2 = 0;
 		etaErrorLAPlusEMCmax173Rgt2 = 0 ;
 		etaErrorLLPlusEMCmax173Rgt2 =0;
 		}

 	if( etaEHEATEMCmax173RFdgt2km!=0)
 	etaErrorHEATPlusEMCmax173Rgt2 = (sqrt(EventsWithErecHEATEMCmax173RFdgt2km ) / GeneratedEventsEMCmax173RFdgt2km ) * (exposureHEATThetamin115EMCmax173Rgt2)/  etaEHEATEMCmax173RFdgt2km ;
 	else
 	etaErrorHEATPlusEMCmax173Rgt2 =0;

 etaErrorExposureEMCmax173Rgt2 = sqrt(  etaErrorCOPlusEMCmax173Rgt2*etaErrorCOPlusEMCmax173Rgt2 + etaErrorLMPlusEMCmax173Rgt2*etaErrorLMPlusEMCmax173Rgt2 +
 		etaErrorLAPlusEMCmax173Rgt2*etaErrorLAPlusEMCmax173Rgt2 +  etaErrorLLPlusEMCmax173Rgt2* etaErrorLLPlusEMCmax173Rgt2
 		+etaErrorHEATPlusEMCmax173Rgt2*etaErrorHEATPlusEMCmax173Rgt2);

 ErrorExposureRgt2.push_back(  etaErrorExposureEMCmax173Rgt2  );

 double etaErrorExposureEMCmax173Rgt3;
 double etaErrorCOPlusEMCmax173Rgt3;
 double etaErrorLMPlusEMCmax173Rgt3;
 double etaErrorLAPlusEMCmax173Rgt3;
 double etaErrorLLPlusEMCmax173Rgt3;
 double etaErrorHEATPlusEMCmax173Rgt3;

 if(etaEEMCmax173RFdgt3km!=0)
 		{
 		etaErrorCOPlusEMCmax173Rgt3 = (sqrt(EventsWithErecCOEMCmax173RFdgt3km ) / GeneratedEventsEMCmax173RFdgt3km ) * (exposureCoihuecoThetamin115EMCmax173Rgt3 /  etaEEMCmax173RFdgt3km) ;
 		etaErrorLMPlusEMCmax173Rgt3 = ( sqrt(EventsWithErecCOEMCmax173RFdgt3km ) / GeneratedEventsEMCmax173RFdgt3km ) * (exposureLMThetamin115EMCmax173Rgt3) /  etaEEMCmax173RFdgt3km;
 		etaErrorLAPlusEMCmax173Rgt3 = ( sqrt(EventsWithErecCOEMCmax173RFdgt3km ) / GeneratedEventsEMCmax173RFdgt3km ) * (exposureLAThetamin115EMCmax173Rgt3)/  etaEEMCmax173RFdgt3km ;
 		etaErrorLLPlusEMCmax173Rgt3 = (sqrt(EventsWithErecCOEMCmax173RFdgt3km ) / GeneratedEventsEMCmax173RFdgt3km ) *	(exposureLLEmin17Thetamin115EMCmax173Rgt3) /  etaEEMCmax173RFdgt3km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax173Rgt3 =0;
 		etaErrorLMPlusEMCmax173Rgt3 = 0;
 		etaErrorLAPlusEMCmax173Rgt3 = 0 ;
 		etaErrorLLPlusEMCmax173Rgt3 =0;
 		}

 	if( etaEHEATEMCmax173RFdgt3km!=0)
 	etaErrorHEATPlusEMCmax173Rgt3 = (sqrt(EventsWithErecHEATEMCmax173RFdgt3km ) / GeneratedEventsEMCmax173RFdgt3km ) * (exposureHEATThetamin115EMCmax173Rgt3)/  etaEHEATEMCmax173RFdgt3km ;
 	else
 	etaErrorHEATPlusEMCmax173Rgt3 =0;

 etaErrorExposureEMCmax173Rgt3 = sqrt(  etaErrorCOPlusEMCmax173Rgt3*etaErrorCOPlusEMCmax173Rgt3 + etaErrorLMPlusEMCmax173Rgt3*etaErrorLMPlusEMCmax173Rgt3 +
 		etaErrorLAPlusEMCmax173Rgt3*etaErrorLAPlusEMCmax173Rgt3 +  etaErrorLLPlusEMCmax173Rgt3* etaErrorLLPlusEMCmax173Rgt3
 		+etaErrorHEATPlusEMCmax173Rgt3*etaErrorHEATPlusEMCmax173Rgt3);

 ErrorExposureRgt3.push_back(  etaErrorExposureEMCmax173Rgt3  );


 double etaErrorExposureEMCmax173Rgt4;
 double etaErrorCOPlusEMCmax173Rgt4;
 double etaErrorLMPlusEMCmax173Rgt4;
 double etaErrorLAPlusEMCmax173Rgt4;
 double etaErrorLLPlusEMCmax173Rgt4;
 double etaErrorHEATPlusEMCmax173Rgt4;

 if(etaEEMCmax173RFdgt4km!=0)
 		{
 		etaErrorCOPlusEMCmax173Rgt4 = (sqrt(EventsWithErecCOEMCmax173RFdgt4km ) / GeneratedEventsEMCmax173RFdgt4km ) * (exposureCoihuecoThetamin115EMCmax173Rgt4 /  etaEEMCmax173RFdgt4km) ;
 		etaErrorLMPlusEMCmax173Rgt4 = ( sqrt(EventsWithErecCOEMCmax173RFdgt4km ) / GeneratedEventsEMCmax173RFdgt4km ) * (exposureLMThetamin115EMCmax173Rgt4) /  etaEEMCmax173RFdgt4km;
 		etaErrorLAPlusEMCmax173Rgt4 = ( sqrt(EventsWithErecCOEMCmax173RFdgt4km ) / GeneratedEventsEMCmax173RFdgt4km ) * (exposureLAThetamin115EMCmax173Rgt4)/  etaEEMCmax173RFdgt4km ;
 		etaErrorLLPlusEMCmax173Rgt4 = (sqrt(EventsWithErecCOEMCmax173RFdgt4km ) / GeneratedEventsEMCmax173RFdgt4km ) *	(exposureLLEmin17Thetamin115EMCmax173Rgt4) /  etaEEMCmax173RFdgt4km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax173Rgt4 =0;
 		etaErrorLMPlusEMCmax173Rgt4 = 0;
 		etaErrorLAPlusEMCmax173Rgt4 = 0 ;
 		etaErrorLLPlusEMCmax173Rgt4 =0;
 		}

 	if( etaEHEATEMCmax173RFdgt4km!=0)
 	etaErrorHEATPlusEMCmax173Rgt4 = (sqrt(EventsWithErecHEATEMCmax173RFdgt4km ) / GeneratedEventsEMCmax173RFdgt4km ) * (exposureHEATThetamin115EMCmax173Rgt4)/  etaEHEATEMCmax173RFdgt4km ;
 	else
 	etaErrorHEATPlusEMCmax173Rgt4 =0;

 etaErrorExposureEMCmax173Rgt4 = sqrt(  etaErrorCOPlusEMCmax173Rgt4*etaErrorCOPlusEMCmax173Rgt4 + etaErrorLMPlusEMCmax173Rgt4*etaErrorLMPlusEMCmax173Rgt4 +
 		etaErrorLAPlusEMCmax173Rgt4*etaErrorLAPlusEMCmax173Rgt4 +  etaErrorLLPlusEMCmax173Rgt4* etaErrorLLPlusEMCmax173Rgt4
 		+etaErrorHEATPlusEMCmax173Rgt4*etaErrorHEATPlusEMCmax173Rgt4);

 ErrorExposureRgt4.push_back(  etaErrorExposureEMCmax173Rgt4  );


 double etaErrorExposureEMCmax173Rgt5;
 double etaErrorCOPlusEMCmax173Rgt5;
 double etaErrorLMPlusEMCmax173Rgt5;
 double etaErrorLAPlusEMCmax173Rgt5;
 double etaErrorLLPlusEMCmax173Rgt5;
 double etaErrorHEATPlusEMCmax173Rgt5;

 if(etaEEMCmax173RFdgt5km!=0)
 		{
 		etaErrorCOPlusEMCmax173Rgt5 = (sqrt(EventsWithErecCOEMCmax173RFdgt5km ) / GeneratedEventsEMCmax173RFdgt5km ) * (exposureCoihuecoThetamin115EMCmax173Rgt5 /  etaEEMCmax173RFdgt5km) ;
 		etaErrorLMPlusEMCmax173Rgt5 = ( sqrt(EventsWithErecCOEMCmax173RFdgt5km ) / GeneratedEventsEMCmax173RFdgt5km ) * (exposureLMThetamin115EMCmax173Rgt5) /  etaEEMCmax173RFdgt5km;
 		etaErrorLAPlusEMCmax173Rgt5 = ( sqrt(EventsWithErecCOEMCmax173RFdgt5km ) / GeneratedEventsEMCmax173RFdgt5km ) * (exposureLAThetamin115EMCmax173Rgt5)/  etaEEMCmax173RFdgt5km ;
 		etaErrorLLPlusEMCmax173Rgt5 = (sqrt(EventsWithErecCOEMCmax173RFdgt5km ) / GeneratedEventsEMCmax173RFdgt5km ) *	(exposureLLEmin17Thetamin115EMCmax173Rgt5) /  etaEEMCmax173RFdgt5km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax173Rgt5 =0;
 		etaErrorLMPlusEMCmax173Rgt5 = 0;
 		etaErrorLAPlusEMCmax173Rgt5 = 0 ;
 		etaErrorLLPlusEMCmax173Rgt5 =0;
 		}

 	if( etaEHEATEMCmax173RFdgt5km!=0)
 	etaErrorHEATPlusEMCmax173Rgt5 = (sqrt(EventsWithErecHEATEMCmax173RFdgt5km ) / GeneratedEventsEMCmax173RFdgt5km ) * (exposureHEATThetamin115EMCmax173Rgt5)/  etaEHEATEMCmax173RFdgt5km ;
 	else
 	etaErrorHEATPlusEMCmax173Rgt5 =0;

 etaErrorExposureEMCmax173Rgt5 = sqrt(  etaErrorCOPlusEMCmax173Rgt5*etaErrorCOPlusEMCmax173Rgt5 + etaErrorLMPlusEMCmax173Rgt5*etaErrorLMPlusEMCmax173Rgt5 +
 		etaErrorLAPlusEMCmax173Rgt5*etaErrorLAPlusEMCmax173Rgt5 +  etaErrorLLPlusEMCmax173Rgt5* etaErrorLLPlusEMCmax173Rgt5
 		+etaErrorHEATPlusEMCmax173Rgt5*etaErrorHEATPlusEMCmax173Rgt5);

 ErrorExposureRgt5.push_back(  etaErrorExposureEMCmax173Rgt5  );



double etaEEMCmax174; //etaE=recEvents/GenEvents ->reconstruction efficiency
etaEEMCmax174 = EventsWithErecCOEMCmax174 / GeneratedEventsEMCmax174;

double etaEHEATEMCmax174;
etaEHEATEMCmax174 = EventsWithErecHEATEMCmax174 / GeneratedEventsEMCmax174;
cout<<"etaE (E=17.3): "<<etaEEMCmax174<<endl;
ErrorEvents.push_back(sqrt(EventsWithErecCOEMCmax174 ));

double etaEEMCmax174RFdgt1km;
etaEEMCmax174RFdgt1km = EventsWithErecCOEMCmax174RFdgt1km / GeneratedEventsEMCmax174RFdgt1km;
double etaEEMCmax174RFdgt2km;
etaEEMCmax174RFdgt2km = EventsWithErecCOEMCmax174RFdgt2km / GeneratedEventsEMCmax174RFdgt2km;
double etaEEMCmax174RFdgt3km;
etaEEMCmax174RFdgt3km = EventsWithErecCOEMCmax174RFdgt3km / GeneratedEventsEMCmax174RFdgt3km;
double etaEEMCmax174RFdgt4km;
etaEEMCmax174RFdgt4km = EventsWithErecCOEMCmax174RFdgt4km / GeneratedEventsEMCmax174RFdgt4km;
double etaEEMCmax174RFdgt5km;
etaEEMCmax174RFdgt5km = EventsWithErecCOEMCmax174RFdgt5km / GeneratedEventsEMCmax174RFdgt5km;

double etaEHEATEMCmax174RFdgt1km;
etaEHEATEMCmax174RFdgt1km = EventsWithErecHEATEMCmax174RFdgt1km / GeneratedEventsEMCmax174RFdgt1km;
double etaEHEATEMCmax174RFdgt2km;
etaEHEATEMCmax174RFdgt2km = EventsWithErecHEATEMCmax174RFdgt2km / GeneratedEventsEMCmax174RFdgt2km;
double etaEHEATEMCmax174RFdgt3km;
etaEHEATEMCmax174RFdgt3km = EventsWithErecHEATEMCmax174RFdgt3km / GeneratedEventsEMCmax174RFdgt3km;
double etaEHEATEMCmax174RFdgt4km;
etaEHEATEMCmax174RFdgt4km = EventsWithErecHEATEMCmax174RFdgt4km / GeneratedEventsEMCmax174RFdgt4km;
double etaEHEATEMCmax174RFdgt5km;
etaEHEATEMCmax174RFdgt5km = EventsWithErecHEATEMCmax174RFdgt5km / GeneratedEventsEMCmax174RFdgt5km;

cout<<"total gen events: "<<TotalNrGenEvents<<" in (17.3, 17.4) nr of gen Events = "<<GeneratedEventsEMCmax174<<endl;


cout<<"nr or reconstructed ev: "<<EventsWithErecCOEMCmax174<<endl;



double apertureCoihuecoThetamin115EMCmax174 = etaEEMCmax174 * genAreaCO *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureCoihuecoThetamin115EMCmax174 = apertureCoihuecoThetamin115EMCmax174 * yearsCO;

double apertureLMThetamin115EMCmax174 = etaEEMCmax174 * genAreaLM *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLMThetamin115EMCmax174 = apertureLMThetamin115EMCmax174 * yearsLM;

  double apertureLAThetamin115EMCmax174 = etaEEMCmax174 * genAreaLA *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLAThetamin115EMCmax174 = apertureLAThetamin115EMCmax174 * yearsLA;

    double apertureLL180FOVThetamin115EMCmax174 = etaEEMCmax174 * genAreaLL180FOV *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLL180FOVThetamin115EMCmax174 = apertureLL180FOVThetamin115EMCmax174 * yearsLL180FOV;

  double apertureLL162FOVThetamin115EMCmax174 = etaEEMCmax174 * genAreaLL162FOV *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLL162FOVThetamin115EMCmax174 = apertureLL162FOVThetamin115EMCmax174 * yearsLL162FOV;

  double exposureLLEmin17Thetamin115EMCmax174 = exposureLL180FOVThetamin115EMCmax174 + exposureLL162FOVThetamin115EMCmax174;

  double apertureHEATThetamin115EMCmax174 = etaEHEATEMCmax174 * genAreaHEAT *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureHEATThetamin115EMCmax174 = apertureHEATThetamin115EMCmax174 * yearsHEAT;


  double Exposure4EyesThetamin115EMCmax174 = exposureCoihuecoThetamin115EMCmax174 + exposureLMThetamin115EMCmax174 +
                                            exposureLAThetamin115EMCmax174 + exposureLLEmin17Thetamin115EMCmax174 +	exposureHEATThetamin115EMCmax174;

  Exposure4EyesAllEnergiesThetamin115H0.push_back(Exposure4EyesThetamin115EMCmax174);


  double exposureCoihuecoThetamin115EMCmax174Rgt1 = etaEEMCmax174RFdgt1km * genAreaCORgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;
  double exposureCoihuecoThetamin115EMCmax174Rgt2 = etaEEMCmax174RFdgt2km * genAreaCORgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;
  double exposureCoihuecoThetamin115EMCmax174Rgt3 = etaEEMCmax174RFdgt3km * genAreaCORgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;

  double exposureLMThetamin115EMCmax174Rgt1 = etaEEMCmax174RFdgt1km * genAreaLMRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;
  double exposureLMThetamin115EMCmax174Rgt2 = etaEEMCmax174RFdgt2km * genAreaLMRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;
  double exposureLMThetamin115EMCmax174Rgt3 = etaEEMCmax174RFdgt3km * genAreaLMRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;

  double exposureLAThetamin115EMCmax174Rgt1 = etaEEMCmax174RFdgt1km * genAreaLARgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;
  double exposureLAThetamin115EMCmax174Rgt2 = etaEEMCmax174RFdgt2km * genAreaLARgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;
  double exposureLAThetamin115EMCmax174Rgt3 = etaEEMCmax174RFdgt3km * genAreaLARgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;

  double exposureLL180FOVThetamin115EMCmax174Rgt1 = etaEEMCmax174RFdgt1km * genAreaLL180FOVRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;
  double exposureLL180FOVThetamin115EMCmax174Rgt2 = etaEEMCmax174RFdgt2km * genAreaLL180FOVRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;
  double exposureLL180FOVThetamin115EMCmax174Rgt3 = etaEEMCmax174RFdgt3km * genAreaLL180FOVRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;

  double exposureLL162FOVThetamin115EMCmax174Rgt1 = etaEEMCmax174RFdgt1km * genAreaLL162FOVRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;
  double exposureLL162FOVThetamin115EMCmax174Rgt2 = etaEEMCmax174RFdgt2km * genAreaLL162FOVRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;
  double exposureLL162FOVThetamin115EMCmax174Rgt3 = etaEEMCmax174RFdgt3km * genAreaLL162FOVRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;

  double exposureLLEmin17Thetamin115EMCmax174Rgt1 =  exposureLL180FOVThetamin115EMCmax174Rgt1 + exposureLL162FOVThetamin115EMCmax174Rgt1;
  double exposureLLEmin17Thetamin115EMCmax174Rgt2 =  exposureLL180FOVThetamin115EMCmax174Rgt2 + exposureLL162FOVThetamin115EMCmax174Rgt2;
  double exposureLLEmin17Thetamin115EMCmax174Rgt3 =  exposureLL180FOVThetamin115EMCmax174Rgt3 + exposureLL162FOVThetamin115EMCmax174Rgt3;



  double exposureCoihuecoThetamin115EMCmax174Rgt4 = etaEEMCmax174RFdgt4km * genAreaCORgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;
  double exposureCoihuecoThetamin115EMCmax174Rgt5 = etaEEMCmax174RFdgt5km * genAreaCORgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;

  double exposureLMThetamin115EMCmax174Rgt4 = etaEEMCmax174RFdgt4km * genAreaLMRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;
  double exposureLMThetamin115EMCmax174Rgt5 = etaEEMCmax174RFdgt5km * genAreaLMRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;

  double exposureLAThetamin115EMCmax174Rgt4 = etaEEMCmax174RFdgt4km * genAreaLARgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;
  double exposureLAThetamin115EMCmax174Rgt5 = etaEEMCmax174RFdgt5km * genAreaLARgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;

  double exposureLL180FOVThetamin115EMCmax174Rgt4 = etaEEMCmax174RFdgt4km * genAreaLL180FOVRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;
  double exposureLL180FOVThetamin115EMCmax174Rgt5 = etaEEMCmax174RFdgt5km * genAreaLL180FOVRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;

  double exposureLL162FOVThetamin115EMCmax174Rgt4 = etaEEMCmax174RFdgt4km * genAreaLL162FOVRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;
  double exposureLL162FOVThetamin115EMCmax174Rgt5 = etaEEMCmax174RFdgt5km * genAreaLL162FOVRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;

  double exposureLLEmin17Thetamin115EMCmax174Rgt4 =  exposureLL180FOVThetamin115EMCmax174Rgt4 + exposureLL162FOVThetamin115EMCmax174Rgt4;
  double exposureLLEmin17Thetamin115EMCmax174Rgt5 =  exposureLL180FOVThetamin115EMCmax174Rgt5 + exposureLL162FOVThetamin115EMCmax174Rgt5;


  double exposureHEATThetamin115EMCmax174Rgt1 = etaEHEATEMCmax174RFdgt1km* genAreaHEATRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCmax174Rgt2 = etaEHEATEMCmax174RFdgt2km* genAreaHEATRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCmax174Rgt3 = etaEHEATEMCmax174RFdgt3km* genAreaHEATRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCmax174Rgt4 = etaEHEATEMCmax174RFdgt4km* genAreaHEATRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCmax174Rgt5 = etaEHEATEMCmax174RFdgt5km* genAreaHEATRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;


  Exposure4EyesAllEnergiesThetamin115H0Rgt4.push_back( exposureCoihuecoThetamin115EMCmax174Rgt4 +   exposureLMThetamin115EMCmax174Rgt4
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax174Rgt4 + exposureLLEmin17Thetamin115EMCmax174Rgt4
																													+ exposureHEATThetamin115EMCmax174Rgt4 );
  Exposure4EyesAllEnergiesThetamin115H0Rgt5.push_back( exposureCoihuecoThetamin115EMCmax174Rgt5 +   exposureLMThetamin115EMCmax174Rgt5
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax174Rgt5 + exposureLLEmin17Thetamin115EMCmax174Rgt5
																													+ exposureHEATThetamin115EMCmax174Rgt5);

  Exposure4EyesAllEnergiesThetamin115H0Rgt1.push_back( exposureCoihuecoThetamin115EMCmax174Rgt1 +   exposureLMThetamin115EMCmax174Rgt1
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax174Rgt1 + exposureLLEmin17Thetamin115EMCmax174Rgt1
																													+ exposureHEATThetamin115EMCmax174Rgt1);
  Exposure4EyesAllEnergiesThetamin115H0Rgt2.push_back( exposureCoihuecoThetamin115EMCmax174Rgt2 +   exposureLMThetamin115EMCmax174Rgt2
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax174Rgt2 + exposureLLEmin17Thetamin115EMCmax174Rgt2
																													+  exposureHEATThetamin115EMCmax174Rgt2);
  Exposure4EyesAllEnergiesThetamin115H0Rgt3.push_back( exposureCoihuecoThetamin115EMCmax174Rgt3 +   exposureLMThetamin115EMCmax174Rgt3
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax174Rgt3 + exposureLLEmin17Thetamin115EMCmax174Rgt3
																													+  exposureHEATThetamin115EMCmax174Rgt3);

 EnergyRangeVector.push_back(17.3);

 double etaErrorExposurePlusEMCmax174 ;
 double etaErrorCOPlusEMCmax174;
 double etaErrorLMPlusEMCmax174;
 double etaErrorLAPlusEMCmax174;
 double etaErrorLLPlusEMCmax174;
 double etaErrorHEATPlusEMCmax174;

 if( etaEEMCmax174!=0)
 		{
 		etaErrorCOPlusEMCmax174 = (sqrt(EventsWithErecCOEMCmax174 ) / GeneratedEventsEMCmax174 ) * (exposureCoihuecoThetamin115EMCmax174 /  etaEEMCmax174) ;
 		etaErrorLMPlusEMCmax174 = ( sqrt(EventsWithErecCOEMCmax174 ) / GeneratedEventsEMCmax174 ) * (exposureLMThetamin115EMCmax174) /  etaEEMCmax174;
 		etaErrorLAPlusEMCmax174 = ( sqrt(EventsWithErecCOEMCmax174 ) / GeneratedEventsEMCmax174 ) * (exposureLAThetamin115EMCmax174)/  etaEEMCmax174 ;
 		etaErrorLLPlusEMCmax174 = (sqrt(EventsWithErecCOEMCmax174 ) / GeneratedEventsEMCmax174 ) *	(exposureLLEmin17Thetamin115EMCmax174) /  etaEEMCmax174;
 		}
 else
 		{
 			etaErrorCOPlusEMCmax174 = 0 ;
 			etaErrorLMPlusEMCmax174 = 0;
 			etaErrorLAPlusEMCmax174 =0 ;
 			etaErrorLLPlusEMCmax174 =0;
 		}
 	if(etaEHEATEMCmax174!=0)
 		etaErrorHEATPlusEMCmax174 = (sqrt(EventsWithErecHEATEMCmax174 ) / GeneratedEventsEMCmax174 ) * (exposureHEATThetamin115EMCmax174)/  etaEHEATEMCmax174 ;
 	else
 		etaErrorHEATPlusEMCmax174 = 0;


 etaErrorExposurePlusEMCmax174 = sqrt(  etaErrorCOPlusEMCmax174*etaErrorCOPlusEMCmax174 + etaErrorLMPlusEMCmax174*etaErrorLMPlusEMCmax174 +
 																etaErrorLAPlusEMCmax174*etaErrorLAPlusEMCmax174 +  etaErrorLLPlusEMCmax174* etaErrorLLPlusEMCmax174
 																+etaErrorHEATPlusEMCmax174*etaErrorHEATPlusEMCmax174);

 cout<<" E=17  "<<"Error Total Exposure  "<<etaErrorExposurePlusEMCmax174 <<endl;

 cout<<"exposure CO: "<<exposureCoihuecoThetamin115EMCmax174 << " error: "<<etaErrorCOPlusEMCmax174<<endl;
 cout<<"exposure LA: "<<exposureLAThetamin115EMCmax174 << " error: "<<etaErrorLAPlusEMCmax174<<endl;
 cout<<"exposure LM: "<<exposureLMThetamin115EMCmax174 << " error: "<<etaErrorLMPlusEMCmax174<<endl;
 cout<<"exposure LL: "<<exposureLLEmin17Thetamin115EMCmax174 << " error: "<<etaErrorLLPlusEMCmax174<<endl;
 cout<<"exposure HEAT: "<<exposureHEATThetamin115EMCmax174 << " error: "<<etaErrorHEATPlusEMCmax174<<endl;


 ErrorExposurePlus.push_back(etaErrorExposurePlusEMCmax174);


 double etaErrorExposureEMCmax174Rgt1;
 double etaErrorCOPlusEMCmax174Rgt1;
 double etaErrorLMPlusEMCmax174Rgt1;
 double etaErrorLAPlusEMCmax174Rgt1;
 double etaErrorLLPlusEMCmax174Rgt1;
 double etaErrorHEATPlusEMCmax174Rgt1;

 if(etaEEMCmax174RFdgt1km!=0)
 		{
 		etaErrorCOPlusEMCmax174Rgt1 = (sqrt(EventsWithErecCOEMCmax174RFdgt1km ) / GeneratedEventsEMCmax174RFdgt1km ) * (exposureCoihuecoThetamin115EMCmax174Rgt1 /  etaEEMCmax174RFdgt1km) ;
 		etaErrorLMPlusEMCmax174Rgt1 = ( sqrt(EventsWithErecCOEMCmax174RFdgt1km ) / GeneratedEventsEMCmax174RFdgt1km ) * (exposureLMThetamin115EMCmax174Rgt1) /  etaEEMCmax174RFdgt1km;
 		etaErrorLAPlusEMCmax174Rgt1 = ( sqrt(EventsWithErecCOEMCmax174RFdgt1km ) / GeneratedEventsEMCmax174RFdgt1km ) * (exposureLAThetamin115EMCmax174Rgt1)/  etaEEMCmax174RFdgt1km ;
 		etaErrorLLPlusEMCmax174Rgt1 = (sqrt(EventsWithErecCOEMCmax174RFdgt1km ) / GeneratedEventsEMCmax174RFdgt1km ) *	(exposureLLEmin17Thetamin115EMCmax174Rgt1) /  etaEEMCmax174RFdgt1km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax174Rgt1 =0;
 		etaErrorLMPlusEMCmax174Rgt1 = 0;
 		etaErrorLAPlusEMCmax174Rgt1 = 0 ;
 		etaErrorLLPlusEMCmax174Rgt1 =0;
 		}

 	if( etaEHEATEMCmax174RFdgt1km!=0)
 	etaErrorHEATPlusEMCmax174Rgt1 = (sqrt(EventsWithErecHEATEMCmax174RFdgt1km ) / GeneratedEventsEMCmax174RFdgt1km ) * (exposureHEATThetamin115EMCmax174Rgt1)/  etaEHEATEMCmax174RFdgt1km ;
 	else
 	etaErrorHEATPlusEMCmax174Rgt1 =0;

 etaErrorExposureEMCmax174Rgt1 = sqrt(  etaErrorCOPlusEMCmax174Rgt1*etaErrorCOPlusEMCmax174Rgt1 + etaErrorLMPlusEMCmax174Rgt1*etaErrorLMPlusEMCmax174Rgt1 +
 		etaErrorLAPlusEMCmax174Rgt1*etaErrorLAPlusEMCmax174Rgt1 +  etaErrorLLPlusEMCmax174Rgt1* etaErrorLLPlusEMCmax174Rgt1
 		+etaErrorHEATPlusEMCmax174Rgt1*etaErrorHEATPlusEMCmax174Rgt1);

 ErrorExposureRgt1.push_back(  etaErrorExposureEMCmax174Rgt1  );


 double etaErrorExposureEMCmax174Rgt2;
 double etaErrorCOPlusEMCmax174Rgt2;
 double etaErrorLMPlusEMCmax174Rgt2;
 double etaErrorLAPlusEMCmax174Rgt2;
 double etaErrorLLPlusEMCmax174Rgt2;
 double etaErrorHEATPlusEMCmax174Rgt2;

 if(etaEEMCmax174RFdgt2km!=0)
 		{
 		etaErrorCOPlusEMCmax174Rgt2 = (sqrt(EventsWithErecCOEMCmax174RFdgt2km ) / GeneratedEventsEMCmax174RFdgt2km ) * (exposureCoihuecoThetamin115EMCmax174Rgt2 /  etaEEMCmax174RFdgt2km) ;
 		etaErrorLMPlusEMCmax174Rgt2 = ( sqrt(EventsWithErecCOEMCmax174RFdgt2km ) / GeneratedEventsEMCmax174RFdgt2km ) * (exposureLMThetamin115EMCmax174Rgt2) /  etaEEMCmax174RFdgt2km;
 		etaErrorLAPlusEMCmax174Rgt2 = ( sqrt(EventsWithErecCOEMCmax174RFdgt2km ) / GeneratedEventsEMCmax174RFdgt2km ) * (exposureLAThetamin115EMCmax174Rgt2)/  etaEEMCmax174RFdgt2km ;
 		etaErrorLLPlusEMCmax174Rgt2 = (sqrt(EventsWithErecCOEMCmax174RFdgt2km ) / GeneratedEventsEMCmax174RFdgt2km ) *	(exposureLLEmin17Thetamin115EMCmax174Rgt2) /  etaEEMCmax174RFdgt2km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax174Rgt2 =0;
 		etaErrorLMPlusEMCmax174Rgt2 = 0;
 		etaErrorLAPlusEMCmax174Rgt2 = 0 ;
 		etaErrorLLPlusEMCmax174Rgt2 =0;
 		}

 	if( etaEHEATEMCmax174RFdgt2km!=0)
 	etaErrorHEATPlusEMCmax174Rgt2 = (sqrt(EventsWithErecHEATEMCmax174RFdgt2km ) / GeneratedEventsEMCmax174RFdgt2km ) * (exposureHEATThetamin115EMCmax174Rgt2)/  etaEHEATEMCmax174RFdgt2km ;
 	else
 	etaErrorHEATPlusEMCmax174Rgt2 =0;

 etaErrorExposureEMCmax174Rgt2 = sqrt(  etaErrorCOPlusEMCmax174Rgt2*etaErrorCOPlusEMCmax174Rgt2 + etaErrorLMPlusEMCmax174Rgt2*etaErrorLMPlusEMCmax174Rgt2 +
 		etaErrorLAPlusEMCmax174Rgt2*etaErrorLAPlusEMCmax174Rgt2 +  etaErrorLLPlusEMCmax174Rgt2* etaErrorLLPlusEMCmax174Rgt2
 		+etaErrorHEATPlusEMCmax174Rgt2*etaErrorHEATPlusEMCmax174Rgt2);

 ErrorExposureRgt2.push_back(  etaErrorExposureEMCmax174Rgt2  );

 double etaErrorExposureEMCmax174Rgt3;
 double etaErrorCOPlusEMCmax174Rgt3;
 double etaErrorLMPlusEMCmax174Rgt3;
 double etaErrorLAPlusEMCmax174Rgt3;
 double etaErrorLLPlusEMCmax174Rgt3;
 double etaErrorHEATPlusEMCmax174Rgt3;

 if(etaEEMCmax174RFdgt3km!=0)
 		{
 		etaErrorCOPlusEMCmax174Rgt3 = (sqrt(EventsWithErecCOEMCmax174RFdgt3km ) / GeneratedEventsEMCmax174RFdgt3km ) * (exposureCoihuecoThetamin115EMCmax174Rgt3 /  etaEEMCmax174RFdgt3km) ;
 		etaErrorLMPlusEMCmax174Rgt3 = ( sqrt(EventsWithErecCOEMCmax174RFdgt3km ) / GeneratedEventsEMCmax174RFdgt3km ) * (exposureLMThetamin115EMCmax174Rgt3) /  etaEEMCmax174RFdgt3km;
 		etaErrorLAPlusEMCmax174Rgt3 = ( sqrt(EventsWithErecCOEMCmax174RFdgt3km ) / GeneratedEventsEMCmax174RFdgt3km ) * (exposureLAThetamin115EMCmax174Rgt3)/  etaEEMCmax174RFdgt3km ;
 		etaErrorLLPlusEMCmax174Rgt3 = (sqrt(EventsWithErecCOEMCmax174RFdgt3km ) / GeneratedEventsEMCmax174RFdgt3km ) *	(exposureLLEmin17Thetamin115EMCmax174Rgt3) /  etaEEMCmax174RFdgt3km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax174Rgt3 =0;
 		etaErrorLMPlusEMCmax174Rgt3 = 0;
 		etaErrorLAPlusEMCmax174Rgt3 = 0 ;
 		etaErrorLLPlusEMCmax174Rgt3 =0;
 		}

 	if( etaEHEATEMCmax174RFdgt3km!=0)
 	etaErrorHEATPlusEMCmax174Rgt3 = (sqrt(EventsWithErecHEATEMCmax174RFdgt3km ) / GeneratedEventsEMCmax174RFdgt3km ) * (exposureHEATThetamin115EMCmax174Rgt3)/  etaEHEATEMCmax174RFdgt3km ;
 	else
 	etaErrorHEATPlusEMCmax174Rgt3 =0;

 etaErrorExposureEMCmax174Rgt3 = sqrt(  etaErrorCOPlusEMCmax174Rgt3*etaErrorCOPlusEMCmax174Rgt3 + etaErrorLMPlusEMCmax174Rgt3*etaErrorLMPlusEMCmax174Rgt3 +
 		etaErrorLAPlusEMCmax174Rgt3*etaErrorLAPlusEMCmax174Rgt3 +  etaErrorLLPlusEMCmax174Rgt3* etaErrorLLPlusEMCmax174Rgt3
 		+etaErrorHEATPlusEMCmax174Rgt3*etaErrorHEATPlusEMCmax174Rgt3);

 ErrorExposureRgt3.push_back(  etaErrorExposureEMCmax174Rgt3  );


 double etaErrorExposureEMCmax174Rgt4;
 double etaErrorCOPlusEMCmax174Rgt4;
 double etaErrorLMPlusEMCmax174Rgt4;
 double etaErrorLAPlusEMCmax174Rgt4;
 double etaErrorLLPlusEMCmax174Rgt4;
 double etaErrorHEATPlusEMCmax174Rgt4;

 if(etaEEMCmax174RFdgt4km!=0)
 		{
 		etaErrorCOPlusEMCmax174Rgt4 = (sqrt(EventsWithErecCOEMCmax174RFdgt4km ) / GeneratedEventsEMCmax174RFdgt4km ) * (exposureCoihuecoThetamin115EMCmax174Rgt4 /  etaEEMCmax174RFdgt4km) ;
 		etaErrorLMPlusEMCmax174Rgt4 = ( sqrt(EventsWithErecCOEMCmax174RFdgt4km ) / GeneratedEventsEMCmax174RFdgt4km ) * (exposureLMThetamin115EMCmax174Rgt4) /  etaEEMCmax174RFdgt4km;
 		etaErrorLAPlusEMCmax174Rgt4 = ( sqrt(EventsWithErecCOEMCmax174RFdgt4km ) / GeneratedEventsEMCmax174RFdgt4km ) * (exposureLAThetamin115EMCmax174Rgt4)/  etaEEMCmax174RFdgt4km ;
 		etaErrorLLPlusEMCmax174Rgt4 = (sqrt(EventsWithErecCOEMCmax174RFdgt4km ) / GeneratedEventsEMCmax174RFdgt4km ) *	(exposureLLEmin17Thetamin115EMCmax174Rgt4) /  etaEEMCmax174RFdgt4km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax174Rgt4 =0;
 		etaErrorLMPlusEMCmax174Rgt4 = 0;
 		etaErrorLAPlusEMCmax174Rgt4 = 0 ;
 		etaErrorLLPlusEMCmax174Rgt4 =0;
 		}

 	if( etaEHEATEMCmax174RFdgt4km!=0)
 	etaErrorHEATPlusEMCmax174Rgt4 = (sqrt(EventsWithErecHEATEMCmax174RFdgt4km ) / GeneratedEventsEMCmax174RFdgt4km ) * (exposureHEATThetamin115EMCmax174Rgt4)/  etaEHEATEMCmax174RFdgt4km ;
 	else
 	etaErrorHEATPlusEMCmax174Rgt4 =0;

 etaErrorExposureEMCmax174Rgt4 = sqrt(  etaErrorCOPlusEMCmax174Rgt4*etaErrorCOPlusEMCmax174Rgt4 + etaErrorLMPlusEMCmax174Rgt4*etaErrorLMPlusEMCmax174Rgt4 +
 		etaErrorLAPlusEMCmax174Rgt4*etaErrorLAPlusEMCmax174Rgt4 +  etaErrorLLPlusEMCmax174Rgt4* etaErrorLLPlusEMCmax174Rgt4
 		+etaErrorHEATPlusEMCmax174Rgt4*etaErrorHEATPlusEMCmax174Rgt4);

 ErrorExposureRgt4.push_back(  etaErrorExposureEMCmax174Rgt4  );


 double etaErrorExposureEMCmax174Rgt5;
 double etaErrorCOPlusEMCmax174Rgt5;
 double etaErrorLMPlusEMCmax174Rgt5;
 double etaErrorLAPlusEMCmax174Rgt5;
 double etaErrorLLPlusEMCmax174Rgt5;
 double etaErrorHEATPlusEMCmax174Rgt5;

 if(etaEEMCmax174RFdgt5km!=0)
 		{
 		etaErrorCOPlusEMCmax174Rgt5 = (sqrt(EventsWithErecCOEMCmax174RFdgt5km ) / GeneratedEventsEMCmax174RFdgt5km ) * (exposureCoihuecoThetamin115EMCmax174Rgt5 /  etaEEMCmax174RFdgt5km) ;
 		etaErrorLMPlusEMCmax174Rgt5 = ( sqrt(EventsWithErecCOEMCmax174RFdgt5km ) / GeneratedEventsEMCmax174RFdgt5km ) * (exposureLMThetamin115EMCmax174Rgt5) /  etaEEMCmax174RFdgt5km;
 		etaErrorLAPlusEMCmax174Rgt5 = ( sqrt(EventsWithErecCOEMCmax174RFdgt5km ) / GeneratedEventsEMCmax174RFdgt5km ) * (exposureLAThetamin115EMCmax174Rgt5)/  etaEEMCmax174RFdgt5km ;
 		etaErrorLLPlusEMCmax174Rgt5 = (sqrt(EventsWithErecCOEMCmax174RFdgt5km ) / GeneratedEventsEMCmax174RFdgt5km ) *	(exposureLLEmin17Thetamin115EMCmax174Rgt5) /  etaEEMCmax174RFdgt5km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax174Rgt5 =0;
 		etaErrorLMPlusEMCmax174Rgt5 = 0;
 		etaErrorLAPlusEMCmax174Rgt5 = 0 ;
 		etaErrorLLPlusEMCmax174Rgt5 =0;
 		}

 	if( etaEHEATEMCmax174RFdgt5km!=0)
 	etaErrorHEATPlusEMCmax174Rgt5 = (sqrt(EventsWithErecHEATEMCmax174RFdgt5km ) / GeneratedEventsEMCmax174RFdgt5km ) * (exposureHEATThetamin115EMCmax174Rgt5)/  etaEHEATEMCmax174RFdgt5km ;
 	else
 	etaErrorHEATPlusEMCmax174Rgt5 =0;

 etaErrorExposureEMCmax174Rgt5 = sqrt(  etaErrorCOPlusEMCmax174Rgt5*etaErrorCOPlusEMCmax174Rgt5 + etaErrorLMPlusEMCmax174Rgt5*etaErrorLMPlusEMCmax174Rgt5 +
 		etaErrorLAPlusEMCmax174Rgt5*etaErrorLAPlusEMCmax174Rgt5 +  etaErrorLLPlusEMCmax174Rgt5* etaErrorLLPlusEMCmax174Rgt5
 		+etaErrorHEATPlusEMCmax174Rgt5*etaErrorHEATPlusEMCmax174Rgt5);

 ErrorExposureRgt5.push_back(  etaErrorExposureEMCmax174Rgt5  );


double etaEEMCmax175; //etaE=recEvents/GenEvents ->reconstruction efficiency
etaEEMCmax175 = EventsWithErecCOEMCmax175 / GeneratedEventsEMCmax175;

double etaEHEATEMCmax175;
etaEHEATEMCmax175 = EventsWithErecHEATEMCmax175 / GeneratedEventsEMCmax175;
cout<<"etaE (E=17.4 "<<etaEEMCmax175<<endl;
ErrorEvents.push_back(sqrt(EventsWithErecCOEMCmax175 ));

double etaEEMCmax175RFdgt1km;
etaEEMCmax175RFdgt1km = EventsWithErecCOEMCmax175RFdgt1km / GeneratedEventsEMCmax175RFdgt1km;
double etaEEMCmax175RFdgt2km;
etaEEMCmax175RFdgt2km = EventsWithErecCOEMCmax175RFdgt2km / GeneratedEventsEMCmax175RFdgt2km;
double etaEEMCmax175RFdgt3km;
etaEEMCmax175RFdgt3km = EventsWithErecCOEMCmax175RFdgt3km / GeneratedEventsEMCmax175RFdgt3km;
double etaEEMCmax175RFdgt4km;
etaEEMCmax175RFdgt4km = EventsWithErecCOEMCmax175RFdgt4km / GeneratedEventsEMCmax175RFdgt4km;
double etaEEMCmax175RFdgt5km;
etaEEMCmax175RFdgt5km = EventsWithErecCOEMCmax175RFdgt5km / GeneratedEventsEMCmax175RFdgt5km;

double etaEHEATEMCmax175RFdgt1km;
etaEHEATEMCmax175RFdgt1km = EventsWithErecHEATEMCmax175RFdgt1km / GeneratedEventsEMCmax175RFdgt1km;
double etaEHEATEMCmax175RFdgt2km;
etaEHEATEMCmax175RFdgt2km = EventsWithErecHEATEMCmax175RFdgt2km / GeneratedEventsEMCmax175RFdgt2km;
double etaEHEATEMCmax175RFdgt3km;
etaEHEATEMCmax175RFdgt3km = EventsWithErecHEATEMCmax175RFdgt3km / GeneratedEventsEMCmax175RFdgt3km;
double etaEHEATEMCmax175RFdgt4km;
etaEHEATEMCmax175RFdgt4km = EventsWithErecHEATEMCmax175RFdgt4km / GeneratedEventsEMCmax175RFdgt4km;
double etaEHEATEMCmax175RFdgt5km;
etaEHEATEMCmax175RFdgt5km = EventsWithErecHEATEMCmax175RFdgt5km / GeneratedEventsEMCmax175RFdgt5km;

cout<<"total gen events: "<<TotalNrGenEvents<<" in (17.4, 17.5) nr of gen Events = "<<GeneratedEventsEMCmax175<<endl;


cout<<"nr or reconstructed ev: "<<EventsWithErecCOEMCmax175<<endl;



double apertureCoihuecoThetamin115EMCmax175 = etaEEMCmax175 * genAreaCO *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureCoihuecoThetamin115EMCmax175 = apertureCoihuecoThetamin115EMCmax175 * yearsCO;

double apertureLMThetamin115EMCmax175 = etaEEMCmax175 * genAreaLM *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLMThetamin115EMCmax175 = apertureLMThetamin115EMCmax175 * yearsLM;

  double apertureLAThetamin115EMCmax175 = etaEEMCmax175 * genAreaLA *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLAThetamin115EMCmax175 = apertureLAThetamin115EMCmax175 * yearsLA;

    double apertureLL180FOVThetamin115EMCmax175 = etaEEMCmax175 * genAreaLL180FOV *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLL180FOVThetamin115EMCmax175 = apertureLL180FOVThetamin115EMCmax175 * yearsLL180FOV;

  double apertureLL162FOVThetamin115EMCmax175 = etaEEMCmax175 * genAreaLL162FOV *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLL162FOVThetamin115EMCmax175 = apertureLL162FOVThetamin115EMCmax175 * yearsLL162FOV;

  double exposureLLEmin17Thetamin115EMCmax175 = exposureLL180FOVThetamin115EMCmax175 + exposureLL162FOVThetamin115EMCmax175;

  double apertureHEATThetamin115EMCmax175 = etaEHEATEMCmax175 * genAreaHEAT *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureHEATThetamin115EMCmax175 = apertureHEATThetamin115EMCmax175 * yearsHEAT;


  double Exposure4EyesThetamin115EMCmax175 = exposureCoihuecoThetamin115EMCmax175 + exposureLMThetamin115EMCmax175 +
                                            exposureLAThetamin115EMCmax175 + exposureLLEmin17Thetamin115EMCmax175 +	exposureHEATThetamin115EMCmax175;

  Exposure4EyesAllEnergiesThetamin115H0.push_back(Exposure4EyesThetamin115EMCmax175);


  double exposureCoihuecoThetamin115EMCmax175Rgt1 = etaEEMCmax175RFdgt1km * genAreaCORgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;
  double exposureCoihuecoThetamin115EMCmax175Rgt2 = etaEEMCmax175RFdgt2km * genAreaCORgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;
  double exposureCoihuecoThetamin115EMCmax175Rgt3 = etaEEMCmax175RFdgt3km * genAreaCORgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;

  double exposureLMThetamin115EMCmax175Rgt1 = etaEEMCmax175RFdgt1km * genAreaLMRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;
  double exposureLMThetamin115EMCmax175Rgt2 = etaEEMCmax175RFdgt2km * genAreaLMRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;
  double exposureLMThetamin115EMCmax175Rgt3 = etaEEMCmax175RFdgt3km * genAreaLMRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;

  double exposureLAThetamin115EMCmax175Rgt1 = etaEEMCmax175RFdgt1km * genAreaLARgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;
  double exposureLAThetamin115EMCmax175Rgt2 = etaEEMCmax175RFdgt2km * genAreaLARgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;
  double exposureLAThetamin115EMCmax175Rgt3 = etaEEMCmax175RFdgt3km * genAreaLARgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;

  double exposureLL180FOVThetamin115EMCmax175Rgt1 = etaEEMCmax175RFdgt1km * genAreaLL180FOVRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;
  double exposureLL180FOVThetamin115EMCmax175Rgt2 = etaEEMCmax175RFdgt2km * genAreaLL180FOVRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;
  double exposureLL180FOVThetamin115EMCmax175Rgt3 = etaEEMCmax175RFdgt3km * genAreaLL180FOVRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;

  double exposureLL162FOVThetamin115EMCmax175Rgt1 = etaEEMCmax175RFdgt1km * genAreaLL162FOVRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;
  double exposureLL162FOVThetamin115EMCmax175Rgt2 = etaEEMCmax175RFdgt2km * genAreaLL162FOVRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;
  double exposureLL162FOVThetamin115EMCmax175Rgt3 = etaEEMCmax175RFdgt3km * genAreaLL162FOVRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;

  double exposureLLEmin17Thetamin115EMCmax175Rgt1 =  exposureLL180FOVThetamin115EMCmax175Rgt1 + exposureLL162FOVThetamin115EMCmax175Rgt1;
  double exposureLLEmin17Thetamin115EMCmax175Rgt2 =  exposureLL180FOVThetamin115EMCmax175Rgt2 + exposureLL162FOVThetamin115EMCmax175Rgt2;
  double exposureLLEmin17Thetamin115EMCmax175Rgt3 =  exposureLL180FOVThetamin115EMCmax175Rgt3 + exposureLL162FOVThetamin115EMCmax175Rgt3;



  double exposureCoihuecoThetamin115EMCmax175Rgt4 = etaEEMCmax175RFdgt4km * genAreaCORgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;
  double exposureCoihuecoThetamin115EMCmax175Rgt5 = etaEEMCmax175RFdgt5km * genAreaCORgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;

  double exposureLMThetamin115EMCmax175Rgt4 = etaEEMCmax175RFdgt4km * genAreaLMRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;
  double exposureLMThetamin115EMCmax175Rgt5 = etaEEMCmax175RFdgt5km * genAreaLMRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;

  double exposureLAThetamin115EMCmax175Rgt4 = etaEEMCmax175RFdgt4km * genAreaLARgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;
  double exposureLAThetamin115EMCmax175Rgt5 = etaEEMCmax175RFdgt5km * genAreaLARgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;

  double exposureLL180FOVThetamin115EMCmax175Rgt4 = etaEEMCmax175RFdgt4km * genAreaLL180FOVRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;
  double exposureLL180FOVThetamin115EMCmax175Rgt5 = etaEEMCmax175RFdgt5km * genAreaLL180FOVRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;

  double exposureLL162FOVThetamin115EMCmax175Rgt4 = etaEEMCmax175RFdgt4km * genAreaLL162FOVRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;
  double exposureLL162FOVThetamin115EMCmax175Rgt5 = etaEEMCmax175RFdgt5km * genAreaLL162FOVRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;

  double exposureLLEmin17Thetamin115EMCmax175Rgt4 =  exposureLL180FOVThetamin115EMCmax175Rgt4 + exposureLL162FOVThetamin115EMCmax175Rgt4;
  double exposureLLEmin17Thetamin115EMCmax175Rgt5 =  exposureLL180FOVThetamin115EMCmax175Rgt5 + exposureLL162FOVThetamin115EMCmax175Rgt5;


  double exposureHEATThetamin115EMCmax175Rgt1 = etaEHEATEMCmax175RFdgt1km* genAreaHEATRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCmax175Rgt2 = etaEHEATEMCmax175RFdgt2km* genAreaHEATRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCmax175Rgt3 = etaEHEATEMCmax175RFdgt3km* genAreaHEATRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCmax175Rgt4 = etaEHEATEMCmax175RFdgt4km* genAreaHEATRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCmax175Rgt5 = etaEHEATEMCmax175RFdgt5km* genAreaHEATRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;


  Exposure4EyesAllEnergiesThetamin115H0Rgt4.push_back( exposureCoihuecoThetamin115EMCmax175Rgt4 +   exposureLMThetamin115EMCmax175Rgt4
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax175Rgt4 + exposureLLEmin17Thetamin115EMCmax175Rgt4
																													+ exposureHEATThetamin115EMCmax175Rgt4 );
  Exposure4EyesAllEnergiesThetamin115H0Rgt5.push_back( exposureCoihuecoThetamin115EMCmax175Rgt5 +   exposureLMThetamin115EMCmax175Rgt5
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax175Rgt5 + exposureLLEmin17Thetamin115EMCmax175Rgt5
																													+ exposureHEATThetamin115EMCmax175Rgt5);

  Exposure4EyesAllEnergiesThetamin115H0Rgt1.push_back( exposureCoihuecoThetamin115EMCmax175Rgt1 +   exposureLMThetamin115EMCmax175Rgt1
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax175Rgt1 + exposureLLEmin17Thetamin115EMCmax175Rgt1
																													+ exposureHEATThetamin115EMCmax175Rgt1);
  Exposure4EyesAllEnergiesThetamin115H0Rgt2.push_back( exposureCoihuecoThetamin115EMCmax175Rgt2 +   exposureLMThetamin115EMCmax175Rgt2
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax175Rgt2 + exposureLLEmin17Thetamin115EMCmax175Rgt2
																													+  exposureHEATThetamin115EMCmax175Rgt2);
  Exposure4EyesAllEnergiesThetamin115H0Rgt3.push_back( exposureCoihuecoThetamin115EMCmax175Rgt3 +   exposureLMThetamin115EMCmax175Rgt3
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax175Rgt3 + exposureLLEmin17Thetamin115EMCmax175Rgt3
																													+  exposureHEATThetamin115EMCmax175Rgt3);

 EnergyRangeVector.push_back(17.4);

 double etaErrorExposurePlusEMCmax175 ;
 double etaErrorCOPlusEMCmax175;
 double etaErrorLMPlusEMCmax175;
 double etaErrorLAPlusEMCmax175;
 double etaErrorLLPlusEMCmax175;
 double etaErrorHEATPlusEMCmax175;

 if( etaEEMCmax175!=0)
 		{
 		etaErrorCOPlusEMCmax175 = (sqrt(EventsWithErecCOEMCmax175 ) / GeneratedEventsEMCmax175 ) * (exposureCoihuecoThetamin115EMCmax175 /  etaEEMCmax175) ;
 		etaErrorLMPlusEMCmax175 = ( sqrt(EventsWithErecCOEMCmax175 ) / GeneratedEventsEMCmax175 ) * (exposureLMThetamin115EMCmax175) /  etaEEMCmax175;
 		etaErrorLAPlusEMCmax175 = ( sqrt(EventsWithErecCOEMCmax175 ) / GeneratedEventsEMCmax175 ) * (exposureLAThetamin115EMCmax175)/  etaEEMCmax175 ;
 		etaErrorLLPlusEMCmax175 = (sqrt(EventsWithErecCOEMCmax175 ) / GeneratedEventsEMCmax175 ) *	(exposureLLEmin17Thetamin115EMCmax175) /  etaEEMCmax175;
 		}
 else
 		{
 			etaErrorCOPlusEMCmax175 = 0 ;
 			etaErrorLMPlusEMCmax175 = 0;
 			etaErrorLAPlusEMCmax175 =0 ;
 			etaErrorLLPlusEMCmax175 =0;
 		}
 	if(etaEHEATEMCmax175!=0)
 		etaErrorHEATPlusEMCmax175 = (sqrt(EventsWithErecHEATEMCmax175 ) / GeneratedEventsEMCmax175 ) * (exposureHEATThetamin115EMCmax175)/  etaEHEATEMCmax175 ;
 	else
 		etaErrorHEATPlusEMCmax175 = 0;


 etaErrorExposurePlusEMCmax175 = sqrt(  etaErrorCOPlusEMCmax175*etaErrorCOPlusEMCmax175 + etaErrorLMPlusEMCmax175*etaErrorLMPlusEMCmax175 +
 																etaErrorLAPlusEMCmax175*etaErrorLAPlusEMCmax175 +  etaErrorLLPlusEMCmax175* etaErrorLLPlusEMCmax175
 																+etaErrorHEATPlusEMCmax175*etaErrorHEATPlusEMCmax175);

 cout<<" E=17  "<<"Error Total Exposure  "<<etaErrorExposurePlusEMCmax175 <<endl;

 cout<<"exposure CO: "<<exposureCoihuecoThetamin115EMCmax175 << " error: "<<etaErrorCOPlusEMCmax175<<endl;
 cout<<"exposure LA: "<<exposureLAThetamin115EMCmax175 << " error: "<<etaErrorLAPlusEMCmax175<<endl;
 cout<<"exposure LM: "<<exposureLMThetamin115EMCmax175 << " error: "<<etaErrorLMPlusEMCmax175<<endl;
 cout<<"exposure LL: "<<exposureLLEmin17Thetamin115EMCmax175 << " error: "<<etaErrorLLPlusEMCmax175<<endl;
 cout<<"exposure HEAT: "<<exposureHEATThetamin115EMCmax175 << " error: "<<etaErrorHEATPlusEMCmax175<<endl;


 ErrorExposurePlus.push_back(etaErrorExposurePlusEMCmax175);


 double etaErrorExposureEMCmax175Rgt1;
 double etaErrorCOPlusEMCmax175Rgt1;
 double etaErrorLMPlusEMCmax175Rgt1;
 double etaErrorLAPlusEMCmax175Rgt1;
 double etaErrorLLPlusEMCmax175Rgt1;
 double etaErrorHEATPlusEMCmax175Rgt1;

 if(etaEEMCmax175RFdgt1km!=0)
 		{
 		etaErrorCOPlusEMCmax175Rgt1 = (sqrt(EventsWithErecCOEMCmax175RFdgt1km ) / GeneratedEventsEMCmax175RFdgt1km ) * (exposureCoihuecoThetamin115EMCmax175Rgt1 /  etaEEMCmax175RFdgt1km) ;
 		etaErrorLMPlusEMCmax175Rgt1 = ( sqrt(EventsWithErecCOEMCmax175RFdgt1km ) / GeneratedEventsEMCmax175RFdgt1km ) * (exposureLMThetamin115EMCmax175Rgt1) /  etaEEMCmax175RFdgt1km;
 		etaErrorLAPlusEMCmax175Rgt1 = ( sqrt(EventsWithErecCOEMCmax175RFdgt1km ) / GeneratedEventsEMCmax175RFdgt1km ) * (exposureLAThetamin115EMCmax175Rgt1)/  etaEEMCmax175RFdgt1km ;
 		etaErrorLLPlusEMCmax175Rgt1 = (sqrt(EventsWithErecCOEMCmax175RFdgt1km ) / GeneratedEventsEMCmax175RFdgt1km ) *	(exposureLLEmin17Thetamin115EMCmax175Rgt1) /  etaEEMCmax175RFdgt1km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax175Rgt1 =0;
 		etaErrorLMPlusEMCmax175Rgt1 = 0;
 		etaErrorLAPlusEMCmax175Rgt1 = 0 ;
 		etaErrorLLPlusEMCmax175Rgt1 =0;
 		}

 	if( etaEHEATEMCmax175RFdgt1km!=0)
 	etaErrorHEATPlusEMCmax175Rgt1 = (sqrt(EventsWithErecHEATEMCmax175RFdgt1km ) / GeneratedEventsEMCmax175RFdgt1km ) * (exposureHEATThetamin115EMCmax175Rgt1)/  etaEHEATEMCmax175RFdgt1km ;
 	else
 	etaErrorHEATPlusEMCmax175Rgt1 =0;

 etaErrorExposureEMCmax175Rgt1 = sqrt(  etaErrorCOPlusEMCmax175Rgt1*etaErrorCOPlusEMCmax175Rgt1 + etaErrorLMPlusEMCmax175Rgt1*etaErrorLMPlusEMCmax175Rgt1 +
 		etaErrorLAPlusEMCmax175Rgt1*etaErrorLAPlusEMCmax175Rgt1 +  etaErrorLLPlusEMCmax175Rgt1* etaErrorLLPlusEMCmax175Rgt1
 		+etaErrorHEATPlusEMCmax175Rgt1*etaErrorHEATPlusEMCmax175Rgt1);

 ErrorExposureRgt1.push_back(  etaErrorExposureEMCmax175Rgt1  );


 double etaErrorExposureEMCmax175Rgt2;
 double etaErrorCOPlusEMCmax175Rgt2;
 double etaErrorLMPlusEMCmax175Rgt2;
 double etaErrorLAPlusEMCmax175Rgt2;
 double etaErrorLLPlusEMCmax175Rgt2;
 double etaErrorHEATPlusEMCmax175Rgt2;

 if(etaEEMCmax175RFdgt2km!=0)
 		{
 		etaErrorCOPlusEMCmax175Rgt2 = (sqrt(EventsWithErecCOEMCmax175RFdgt2km ) / GeneratedEventsEMCmax175RFdgt2km ) * (exposureCoihuecoThetamin115EMCmax175Rgt2 /  etaEEMCmax175RFdgt2km) ;
 		etaErrorLMPlusEMCmax175Rgt2 = ( sqrt(EventsWithErecCOEMCmax175RFdgt2km ) / GeneratedEventsEMCmax175RFdgt2km ) * (exposureLMThetamin115EMCmax175Rgt2) /  etaEEMCmax175RFdgt2km;
 		etaErrorLAPlusEMCmax175Rgt2 = ( sqrt(EventsWithErecCOEMCmax175RFdgt2km ) / GeneratedEventsEMCmax175RFdgt2km ) * (exposureLAThetamin115EMCmax175Rgt2)/  etaEEMCmax175RFdgt2km ;
 		etaErrorLLPlusEMCmax175Rgt2 = (sqrt(EventsWithErecCOEMCmax175RFdgt2km ) / GeneratedEventsEMCmax175RFdgt2km ) *	(exposureLLEmin17Thetamin115EMCmax175Rgt2) /  etaEEMCmax175RFdgt2km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax175Rgt2 =0;
 		etaErrorLMPlusEMCmax175Rgt2 = 0;
 		etaErrorLAPlusEMCmax175Rgt2 = 0 ;
 		etaErrorLLPlusEMCmax175Rgt2 =0;
 		}

 	if( etaEHEATEMCmax175RFdgt2km!=0)
 	etaErrorHEATPlusEMCmax175Rgt2 = (sqrt(EventsWithErecHEATEMCmax175RFdgt2km ) / GeneratedEventsEMCmax175RFdgt2km ) * (exposureHEATThetamin115EMCmax175Rgt2)/  etaEHEATEMCmax175RFdgt2km ;
 	else
 	etaErrorHEATPlusEMCmax175Rgt2 =0;

 etaErrorExposureEMCmax175Rgt2 = sqrt(  etaErrorCOPlusEMCmax175Rgt2*etaErrorCOPlusEMCmax175Rgt2 + etaErrorLMPlusEMCmax175Rgt2*etaErrorLMPlusEMCmax175Rgt2 +
 		etaErrorLAPlusEMCmax175Rgt2*etaErrorLAPlusEMCmax175Rgt2 +  etaErrorLLPlusEMCmax175Rgt2* etaErrorLLPlusEMCmax175Rgt2
 		+etaErrorHEATPlusEMCmax175Rgt2*etaErrorHEATPlusEMCmax175Rgt2);

 ErrorExposureRgt2.push_back(  etaErrorExposureEMCmax175Rgt2  );

 double etaErrorExposureEMCmax175Rgt3;
 double etaErrorCOPlusEMCmax175Rgt3;
 double etaErrorLMPlusEMCmax175Rgt3;
 double etaErrorLAPlusEMCmax175Rgt3;
 double etaErrorLLPlusEMCmax175Rgt3;
 double etaErrorHEATPlusEMCmax175Rgt3;

 if(etaEEMCmax175RFdgt3km!=0)
 		{
 		etaErrorCOPlusEMCmax175Rgt3 = (sqrt(EventsWithErecCOEMCmax175RFdgt3km ) / GeneratedEventsEMCmax175RFdgt3km ) * (exposureCoihuecoThetamin115EMCmax175Rgt3 /  etaEEMCmax175RFdgt3km) ;
 		etaErrorLMPlusEMCmax175Rgt3 = ( sqrt(EventsWithErecCOEMCmax175RFdgt3km ) / GeneratedEventsEMCmax175RFdgt3km ) * (exposureLMThetamin115EMCmax175Rgt3) /  etaEEMCmax175RFdgt3km;
 		etaErrorLAPlusEMCmax175Rgt3 = ( sqrt(EventsWithErecCOEMCmax175RFdgt3km ) / GeneratedEventsEMCmax175RFdgt3km ) * (exposureLAThetamin115EMCmax175Rgt3)/  etaEEMCmax175RFdgt3km ;
 		etaErrorLLPlusEMCmax175Rgt3 = (sqrt(EventsWithErecCOEMCmax175RFdgt3km ) / GeneratedEventsEMCmax175RFdgt3km ) *	(exposureLLEmin17Thetamin115EMCmax175Rgt3) /  etaEEMCmax175RFdgt3km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax175Rgt3 =0;
 		etaErrorLMPlusEMCmax175Rgt3 = 0;
 		etaErrorLAPlusEMCmax175Rgt3 = 0 ;
 		etaErrorLLPlusEMCmax175Rgt3 =0;
 		}

 	if( etaEHEATEMCmax175RFdgt3km!=0)
 	etaErrorHEATPlusEMCmax175Rgt3 = (sqrt(EventsWithErecHEATEMCmax175RFdgt3km ) / GeneratedEventsEMCmax175RFdgt3km ) * (exposureHEATThetamin115EMCmax175Rgt3)/  etaEHEATEMCmax175RFdgt3km ;
 	else
 	etaErrorHEATPlusEMCmax175Rgt3 =0;

 etaErrorExposureEMCmax175Rgt3 = sqrt(  etaErrorCOPlusEMCmax175Rgt3*etaErrorCOPlusEMCmax175Rgt3 + etaErrorLMPlusEMCmax175Rgt3*etaErrorLMPlusEMCmax175Rgt3 +
 		etaErrorLAPlusEMCmax175Rgt3*etaErrorLAPlusEMCmax175Rgt3 +  etaErrorLLPlusEMCmax175Rgt3* etaErrorLLPlusEMCmax175Rgt3
 		+etaErrorHEATPlusEMCmax175Rgt3*etaErrorHEATPlusEMCmax175Rgt3);

 ErrorExposureRgt3.push_back(  etaErrorExposureEMCmax175Rgt3  );


 double etaErrorExposureEMCmax175Rgt4;
 double etaErrorCOPlusEMCmax175Rgt4;
 double etaErrorLMPlusEMCmax175Rgt4;
 double etaErrorLAPlusEMCmax175Rgt4;
 double etaErrorLLPlusEMCmax175Rgt4;
 double etaErrorHEATPlusEMCmax175Rgt4;

 if(etaEEMCmax175RFdgt4km!=0)
 		{
 		etaErrorCOPlusEMCmax175Rgt4 = (sqrt(EventsWithErecCOEMCmax175RFdgt4km ) / GeneratedEventsEMCmax175RFdgt4km ) * (exposureCoihuecoThetamin115EMCmax175Rgt4 /  etaEEMCmax175RFdgt4km) ;
 		etaErrorLMPlusEMCmax175Rgt4 = ( sqrt(EventsWithErecCOEMCmax175RFdgt4km ) / GeneratedEventsEMCmax175RFdgt4km ) * (exposureLMThetamin115EMCmax175Rgt4) /  etaEEMCmax175RFdgt4km;
 		etaErrorLAPlusEMCmax175Rgt4 = ( sqrt(EventsWithErecCOEMCmax175RFdgt4km ) / GeneratedEventsEMCmax175RFdgt4km ) * (exposureLAThetamin115EMCmax175Rgt4)/  etaEEMCmax175RFdgt4km ;
 		etaErrorLLPlusEMCmax175Rgt4 = (sqrt(EventsWithErecCOEMCmax175RFdgt4km ) / GeneratedEventsEMCmax175RFdgt4km ) *	(exposureLLEmin17Thetamin115EMCmax175Rgt4) /  etaEEMCmax175RFdgt4km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax175Rgt4 =0;
 		etaErrorLMPlusEMCmax175Rgt4 = 0;
 		etaErrorLAPlusEMCmax175Rgt4 = 0 ;
 		etaErrorLLPlusEMCmax175Rgt4 =0;
 		}

 	if( etaEHEATEMCmax175RFdgt4km!=0)
 	etaErrorHEATPlusEMCmax175Rgt4 = (sqrt(EventsWithErecHEATEMCmax175RFdgt4km ) / GeneratedEventsEMCmax175RFdgt4km ) * (exposureHEATThetamin115EMCmax175Rgt4)/  etaEHEATEMCmax175RFdgt4km ;
 	else
 	etaErrorHEATPlusEMCmax175Rgt4 =0;

 etaErrorExposureEMCmax175Rgt4 = sqrt(  etaErrorCOPlusEMCmax175Rgt4*etaErrorCOPlusEMCmax175Rgt4 + etaErrorLMPlusEMCmax175Rgt4*etaErrorLMPlusEMCmax175Rgt4 +
 		etaErrorLAPlusEMCmax175Rgt4*etaErrorLAPlusEMCmax175Rgt4 +  etaErrorLLPlusEMCmax175Rgt4* etaErrorLLPlusEMCmax175Rgt4
 		+etaErrorHEATPlusEMCmax175Rgt4*etaErrorHEATPlusEMCmax175Rgt4);

 ErrorExposureRgt4.push_back(  etaErrorExposureEMCmax175Rgt4  );


 double etaErrorExposureEMCmax175Rgt5;
 double etaErrorCOPlusEMCmax175Rgt5;
 double etaErrorLMPlusEMCmax175Rgt5;
 double etaErrorLAPlusEMCmax175Rgt5;
 double etaErrorLLPlusEMCmax175Rgt5;
 double etaErrorHEATPlusEMCmax175Rgt5;

 if(etaEEMCmax175RFdgt5km!=0)
 		{
 		etaErrorCOPlusEMCmax175Rgt5 = (sqrt(EventsWithErecCOEMCmax175RFdgt5km ) / GeneratedEventsEMCmax175RFdgt5km ) * (exposureCoihuecoThetamin115EMCmax175Rgt5 /  etaEEMCmax175RFdgt5km) ;
 		etaErrorLMPlusEMCmax175Rgt5 = ( sqrt(EventsWithErecCOEMCmax175RFdgt5km ) / GeneratedEventsEMCmax175RFdgt5km ) * (exposureLMThetamin115EMCmax175Rgt5) /  etaEEMCmax175RFdgt5km;
 		etaErrorLAPlusEMCmax175Rgt5 = ( sqrt(EventsWithErecCOEMCmax175RFdgt5km ) / GeneratedEventsEMCmax175RFdgt5km ) * (exposureLAThetamin115EMCmax175Rgt5)/  etaEEMCmax175RFdgt5km ;
 		etaErrorLLPlusEMCmax175Rgt5 = (sqrt(EventsWithErecCOEMCmax175RFdgt5km ) / GeneratedEventsEMCmax175RFdgt5km ) *	(exposureLLEmin17Thetamin115EMCmax175Rgt5) /  etaEEMCmax175RFdgt5km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax175Rgt5 =0;
 		etaErrorLMPlusEMCmax175Rgt5 = 0;
 		etaErrorLAPlusEMCmax175Rgt5 = 0 ;
 		etaErrorLLPlusEMCmax175Rgt5 =0;
 		}

 	if( etaEHEATEMCmax175RFdgt5km!=0)
 	etaErrorHEATPlusEMCmax175Rgt5 = (sqrt(EventsWithErecHEATEMCmax175RFdgt5km ) / GeneratedEventsEMCmax175RFdgt5km ) * (exposureHEATThetamin115EMCmax175Rgt5)/  etaEHEATEMCmax175RFdgt5km ;
 	else
 	etaErrorHEATPlusEMCmax175Rgt5 =0;

 etaErrorExposureEMCmax175Rgt5 = sqrt(  etaErrorCOPlusEMCmax175Rgt5*etaErrorCOPlusEMCmax175Rgt5 + etaErrorLMPlusEMCmax175Rgt5*etaErrorLMPlusEMCmax175Rgt5 +
 		etaErrorLAPlusEMCmax175Rgt5*etaErrorLAPlusEMCmax175Rgt5 +  etaErrorLLPlusEMCmax175Rgt5* etaErrorLLPlusEMCmax175Rgt5
 		+etaErrorHEATPlusEMCmax175Rgt5*etaErrorHEATPlusEMCmax175Rgt5);

 ErrorExposureRgt5.push_back(  etaErrorExposureEMCmax175Rgt5  );


double etaEEMCmax176; //etaE=recEvents/GenEvents ->reconstruction efficiency
etaEEMCmax176 = EventsWithErecCOEMCmax176 / GeneratedEventsEMCmax176;

double etaEHEATEMCmax176;
etaEHEATEMCmax176 = EventsWithErecHEATEMCmax176 / GeneratedEventsEMCmax176;
cout<<"etaE (E=17.5): "<<etaEEMCmax176<<endl;
ErrorEvents.push_back(sqrt(EventsWithErecCOEMCmax176 ));

double etaEEMCmax176RFdgt1km;
etaEEMCmax176RFdgt1km = EventsWithErecCOEMCmax176RFdgt1km / GeneratedEventsEMCmax176RFdgt1km;
double etaEEMCmax176RFdgt2km;
etaEEMCmax176RFdgt2km = EventsWithErecCOEMCmax176RFdgt2km / GeneratedEventsEMCmax176RFdgt2km;
double etaEEMCmax176RFdgt3km;
etaEEMCmax176RFdgt3km = EventsWithErecCOEMCmax176RFdgt3km / GeneratedEventsEMCmax176RFdgt3km;
double etaEEMCmax176RFdgt4km;
etaEEMCmax176RFdgt4km = EventsWithErecCOEMCmax176RFdgt4km / GeneratedEventsEMCmax176RFdgt4km;
double etaEEMCmax176RFdgt5km;
etaEEMCmax176RFdgt5km = EventsWithErecCOEMCmax176RFdgt5km / GeneratedEventsEMCmax176RFdgt5km;

double etaEHEATEMCmax176RFdgt1km;
etaEHEATEMCmax176RFdgt1km = EventsWithErecHEATEMCmax176RFdgt1km / GeneratedEventsEMCmax176RFdgt1km;
double etaEHEATEMCmax176RFdgt2km;
etaEHEATEMCmax176RFdgt2km = EventsWithErecHEATEMCmax176RFdgt2km / GeneratedEventsEMCmax176RFdgt2km;
double etaEHEATEMCmax176RFdgt3km;
etaEHEATEMCmax176RFdgt3km = EventsWithErecHEATEMCmax176RFdgt3km / GeneratedEventsEMCmax176RFdgt3km;
double etaEHEATEMCmax176RFdgt4km;
etaEHEATEMCmax176RFdgt4km = EventsWithErecHEATEMCmax176RFdgt4km / GeneratedEventsEMCmax176RFdgt4km;
double etaEHEATEMCmax176RFdgt5km;
etaEHEATEMCmax176RFdgt5km = EventsWithErecHEATEMCmax176RFdgt5km / GeneratedEventsEMCmax176RFdgt5km;

cout<<"total gen events: "<<TotalNrGenEvents<<" in (17.5, 17.6) nr of gen Events = "<<GeneratedEventsEMCmax176<<endl;


cout<<"nr or reconstructed ev: "<<EventsWithErecCOEMCmax176<<endl;



double apertureCoihuecoThetamin115EMCmax176 = etaEEMCmax176 * genAreaCO *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureCoihuecoThetamin115EMCmax176 = apertureCoihuecoThetamin115EMCmax176 * yearsCO;

double apertureLMThetamin115EMCmax176 = etaEEMCmax176 * genAreaLM *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLMThetamin115EMCmax176 = apertureLMThetamin115EMCmax176 * yearsLM;

  double apertureLAThetamin115EMCmax176 = etaEEMCmax176 * genAreaLA *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLAThetamin115EMCmax176 = apertureLAThetamin115EMCmax176 * yearsLA;

    double apertureLL180FOVThetamin115EMCmax176 = etaEEMCmax176 * genAreaLL180FOV *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLL180FOVThetamin115EMCmax176 = apertureLL180FOVThetamin115EMCmax176 * yearsLL180FOV;

  double apertureLL162FOVThetamin115EMCmax176 = etaEEMCmax176 * genAreaLL162FOV *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLL162FOVThetamin115EMCmax176 = apertureLL162FOVThetamin115EMCmax176 * yearsLL162FOV;

  double exposureLLEmin17Thetamin115EMCmax176 = exposureLL180FOVThetamin115EMCmax176 + exposureLL162FOVThetamin115EMCmax176;

  double apertureHEATThetamin115EMCmax176 = etaEHEATEMCmax176 * genAreaHEAT *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureHEATThetamin115EMCmax176 = apertureHEATThetamin115EMCmax176 * yearsHEAT;


  double Exposure4EyesThetamin115EMCmax176 = exposureCoihuecoThetamin115EMCmax176 + exposureLMThetamin115EMCmax176 +
                                            exposureLAThetamin115EMCmax176 + exposureLLEmin17Thetamin115EMCmax176 +	exposureHEATThetamin115EMCmax176;

  Exposure4EyesAllEnergiesThetamin115H0.push_back(Exposure4EyesThetamin115EMCmax176);


  double exposureCoihuecoThetamin115EMCmax176Rgt1 = etaEEMCmax176RFdgt1km * genAreaCORgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;
  double exposureCoihuecoThetamin115EMCmax176Rgt2 = etaEEMCmax176RFdgt2km * genAreaCORgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;
  double exposureCoihuecoThetamin115EMCmax176Rgt3 = etaEEMCmax176RFdgt3km * genAreaCORgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;

  double exposureLMThetamin115EMCmax176Rgt1 = etaEEMCmax176RFdgt1km * genAreaLMRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;
  double exposureLMThetamin115EMCmax176Rgt2 = etaEEMCmax176RFdgt2km * genAreaLMRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;
  double exposureLMThetamin115EMCmax176Rgt3 = etaEEMCmax176RFdgt3km * genAreaLMRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;

  double exposureLAThetamin115EMCmax176Rgt1 = etaEEMCmax176RFdgt1km * genAreaLARgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;
  double exposureLAThetamin115EMCmax176Rgt2 = etaEEMCmax176RFdgt2km * genAreaLARgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;
  double exposureLAThetamin115EMCmax176Rgt3 = etaEEMCmax176RFdgt3km * genAreaLARgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;

  double exposureLL180FOVThetamin115EMCmax176Rgt1 = etaEEMCmax176RFdgt1km * genAreaLL180FOVRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;
  double exposureLL180FOVThetamin115EMCmax176Rgt2 = etaEEMCmax176RFdgt2km * genAreaLL180FOVRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;
  double exposureLL180FOVThetamin115EMCmax176Rgt3 = etaEEMCmax176RFdgt3km * genAreaLL180FOVRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;

  double exposureLL162FOVThetamin115EMCmax176Rgt1 = etaEEMCmax176RFdgt1km * genAreaLL162FOVRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;
  double exposureLL162FOVThetamin115EMCmax176Rgt2 = etaEEMCmax176RFdgt2km * genAreaLL162FOVRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;
  double exposureLL162FOVThetamin115EMCmax176Rgt3 = etaEEMCmax176RFdgt3km * genAreaLL162FOVRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;

  double exposureLLEmin17Thetamin115EMCmax176Rgt1 =  exposureLL180FOVThetamin115EMCmax176Rgt1 + exposureLL162FOVThetamin115EMCmax176Rgt1;
  double exposureLLEmin17Thetamin115EMCmax176Rgt2 =  exposureLL180FOVThetamin115EMCmax176Rgt2 + exposureLL162FOVThetamin115EMCmax176Rgt2;
  double exposureLLEmin17Thetamin115EMCmax176Rgt3 =  exposureLL180FOVThetamin115EMCmax176Rgt3 + exposureLL162FOVThetamin115EMCmax176Rgt3;



  double exposureCoihuecoThetamin115EMCmax176Rgt4 = etaEEMCmax176RFdgt4km * genAreaCORgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;
  double exposureCoihuecoThetamin115EMCmax176Rgt5 = etaEEMCmax176RFdgt5km * genAreaCORgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;

  double exposureLMThetamin115EMCmax176Rgt4 = etaEEMCmax176RFdgt4km * genAreaLMRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;
  double exposureLMThetamin115EMCmax176Rgt5 = etaEEMCmax176RFdgt5km * genAreaLMRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;

  double exposureLAThetamin115EMCmax176Rgt4 = etaEEMCmax176RFdgt4km * genAreaLARgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;
  double exposureLAThetamin115EMCmax176Rgt5 = etaEEMCmax176RFdgt5km * genAreaLARgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;

  double exposureLL180FOVThetamin115EMCmax176Rgt4 = etaEEMCmax176RFdgt4km * genAreaLL180FOVRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;
  double exposureLL180FOVThetamin115EMCmax176Rgt5 = etaEEMCmax176RFdgt5km * genAreaLL180FOVRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;

  double exposureLL162FOVThetamin115EMCmax176Rgt4 = etaEEMCmax176RFdgt4km * genAreaLL162FOVRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;
  double exposureLL162FOVThetamin115EMCmax176Rgt5 = etaEEMCmax176RFdgt5km * genAreaLL162FOVRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;

  double exposureLLEmin17Thetamin115EMCmax176Rgt4 =  exposureLL180FOVThetamin115EMCmax176Rgt4 + exposureLL162FOVThetamin115EMCmax176Rgt4;
  double exposureLLEmin17Thetamin115EMCmax176Rgt5 =  exposureLL180FOVThetamin115EMCmax176Rgt5 + exposureLL162FOVThetamin115EMCmax176Rgt5;


  double exposureHEATThetamin115EMCmax176Rgt1 = etaEHEATEMCmax176RFdgt1km* genAreaHEATRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCmax176Rgt2 = etaEHEATEMCmax176RFdgt2km* genAreaHEATRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCmax176Rgt3 = etaEHEATEMCmax176RFdgt3km* genAreaHEATRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCmax176Rgt4 = etaEHEATEMCmax176RFdgt4km* genAreaHEATRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCmax176Rgt5 = etaEHEATEMCmax176RFdgt5km* genAreaHEATRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;


  Exposure4EyesAllEnergiesThetamin115H0Rgt4.push_back( exposureCoihuecoThetamin115EMCmax176Rgt4 +   exposureLMThetamin115EMCmax176Rgt4
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax176Rgt4 + exposureLLEmin17Thetamin115EMCmax176Rgt4
																													+ exposureHEATThetamin115EMCmax176Rgt4 );
  Exposure4EyesAllEnergiesThetamin115H0Rgt5.push_back( exposureCoihuecoThetamin115EMCmax176Rgt5 +   exposureLMThetamin115EMCmax176Rgt5
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax176Rgt5 + exposureLLEmin17Thetamin115EMCmax176Rgt5
																													+ exposureHEATThetamin115EMCmax176Rgt5);

  Exposure4EyesAllEnergiesThetamin115H0Rgt1.push_back( exposureCoihuecoThetamin115EMCmax176Rgt1 +   exposureLMThetamin115EMCmax176Rgt1
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax176Rgt1 + exposureLLEmin17Thetamin115EMCmax176Rgt1
																													+ exposureHEATThetamin115EMCmax176Rgt1);
  Exposure4EyesAllEnergiesThetamin115H0Rgt2.push_back( exposureCoihuecoThetamin115EMCmax176Rgt2 +   exposureLMThetamin115EMCmax176Rgt2
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax176Rgt2 + exposureLLEmin17Thetamin115EMCmax176Rgt2
																													+  exposureHEATThetamin115EMCmax176Rgt2);
  Exposure4EyesAllEnergiesThetamin115H0Rgt3.push_back( exposureCoihuecoThetamin115EMCmax176Rgt3 +   exposureLMThetamin115EMCmax176Rgt3
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax176Rgt3 + exposureLLEmin17Thetamin115EMCmax176Rgt3
																													+  exposureHEATThetamin115EMCmax176Rgt3);

 EnergyRangeVector.push_back(17.5);

 double etaErrorExposurePlusEMCmax176 ;
 double etaErrorCOPlusEMCmax176;
 double etaErrorLMPlusEMCmax176;
 double etaErrorLAPlusEMCmax176;
 double etaErrorLLPlusEMCmax176;
 double etaErrorHEATPlusEMCmax176;

 if( etaEEMCmax176!=0)
 		{
 		etaErrorCOPlusEMCmax176 = (sqrt(EventsWithErecCOEMCmax176 ) / GeneratedEventsEMCmax176 ) * (exposureCoihuecoThetamin115EMCmax176 /  etaEEMCmax176) ;
 		etaErrorLMPlusEMCmax176 = ( sqrt(EventsWithErecCOEMCmax176 ) / GeneratedEventsEMCmax176 ) * (exposureLMThetamin115EMCmax176) /  etaEEMCmax176;
 		etaErrorLAPlusEMCmax176 = ( sqrt(EventsWithErecCOEMCmax176 ) / GeneratedEventsEMCmax176 ) * (exposureLAThetamin115EMCmax176)/  etaEEMCmax176 ;
 		etaErrorLLPlusEMCmax176 = (sqrt(EventsWithErecCOEMCmax176 ) / GeneratedEventsEMCmax176 ) *	(exposureLLEmin17Thetamin115EMCmax176) /  etaEEMCmax176;
 		}
 else
 		{
 			etaErrorCOPlusEMCmax176 = 0 ;
 			etaErrorLMPlusEMCmax176 = 0;
 			etaErrorLAPlusEMCmax176 =0 ;
 			etaErrorLLPlusEMCmax176 =0;
 		}
 	if(etaEHEATEMCmax176!=0)
 		etaErrorHEATPlusEMCmax176 = (sqrt(EventsWithErecHEATEMCmax176 ) / GeneratedEventsEMCmax176 ) * (exposureHEATThetamin115EMCmax176)/  etaEHEATEMCmax176 ;
 	else
 		etaErrorHEATPlusEMCmax176 = 0;


 etaErrorExposurePlusEMCmax176 = sqrt(  etaErrorCOPlusEMCmax176*etaErrorCOPlusEMCmax176 + etaErrorLMPlusEMCmax176*etaErrorLMPlusEMCmax176 +
 																etaErrorLAPlusEMCmax176*etaErrorLAPlusEMCmax176 +  etaErrorLLPlusEMCmax176* etaErrorLLPlusEMCmax176
 																+etaErrorHEATPlusEMCmax176*etaErrorHEATPlusEMCmax176);

 cout<<" E=17  "<<"Error Total Exposure  "<<etaErrorExposurePlusEMCmax176 <<endl;

 cout<<"exposure CO: "<<exposureCoihuecoThetamin115EMCmax176 << " error: "<<etaErrorCOPlusEMCmax176<<endl;
 cout<<"exposure LA: "<<exposureLAThetamin115EMCmax176 << " error: "<<etaErrorLAPlusEMCmax176<<endl;
 cout<<"exposure LM: "<<exposureLMThetamin115EMCmax176 << " error: "<<etaErrorLMPlusEMCmax176<<endl;
 cout<<"exposure LL: "<<exposureLLEmin17Thetamin115EMCmax176 << " error: "<<etaErrorLLPlusEMCmax176<<endl;
 cout<<"exposure HEAT: "<<exposureHEATThetamin115EMCmax176 << " error: "<<etaErrorHEATPlusEMCmax176<<endl;


 ErrorExposurePlus.push_back(etaErrorExposurePlusEMCmax176);


 double etaErrorExposureEMCmax176Rgt1;
 double etaErrorCOPlusEMCmax176Rgt1;
 double etaErrorLMPlusEMCmax176Rgt1;
 double etaErrorLAPlusEMCmax176Rgt1;
 double etaErrorLLPlusEMCmax176Rgt1;
 double etaErrorHEATPlusEMCmax176Rgt1;

 if(etaEEMCmax176RFdgt1km!=0)
 		{
 		etaErrorCOPlusEMCmax176Rgt1 = (sqrt(EventsWithErecCOEMCmax176RFdgt1km ) / GeneratedEventsEMCmax176RFdgt1km ) * (exposureCoihuecoThetamin115EMCmax176Rgt1 /  etaEEMCmax176RFdgt1km) ;
 		etaErrorLMPlusEMCmax176Rgt1 = ( sqrt(EventsWithErecCOEMCmax176RFdgt1km ) / GeneratedEventsEMCmax176RFdgt1km ) * (exposureLMThetamin115EMCmax176Rgt1) /  etaEEMCmax176RFdgt1km;
 		etaErrorLAPlusEMCmax176Rgt1 = ( sqrt(EventsWithErecCOEMCmax176RFdgt1km ) / GeneratedEventsEMCmax176RFdgt1km ) * (exposureLAThetamin115EMCmax176Rgt1)/  etaEEMCmax176RFdgt1km ;
 		etaErrorLLPlusEMCmax176Rgt1 = (sqrt(EventsWithErecCOEMCmax176RFdgt1km ) / GeneratedEventsEMCmax176RFdgt1km ) *	(exposureLLEmin17Thetamin115EMCmax176Rgt1) /  etaEEMCmax176RFdgt1km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax176Rgt1 =0;
 		etaErrorLMPlusEMCmax176Rgt1 = 0;
 		etaErrorLAPlusEMCmax176Rgt1 = 0 ;
 		etaErrorLLPlusEMCmax176Rgt1 =0;
 		}

 	if( etaEHEATEMCmax176RFdgt1km!=0)
 	etaErrorHEATPlusEMCmax176Rgt1 = (sqrt(EventsWithErecHEATEMCmax176RFdgt1km ) / GeneratedEventsEMCmax176RFdgt1km ) * (exposureHEATThetamin115EMCmax176Rgt1)/  etaEHEATEMCmax176RFdgt1km ;
 	else
 	etaErrorHEATPlusEMCmax176Rgt1 =0;

 etaErrorExposureEMCmax176Rgt1 = sqrt(  etaErrorCOPlusEMCmax176Rgt1*etaErrorCOPlusEMCmax176Rgt1 + etaErrorLMPlusEMCmax176Rgt1*etaErrorLMPlusEMCmax176Rgt1 +
 		etaErrorLAPlusEMCmax176Rgt1*etaErrorLAPlusEMCmax176Rgt1 +  etaErrorLLPlusEMCmax176Rgt1* etaErrorLLPlusEMCmax176Rgt1
 		+etaErrorHEATPlusEMCmax176Rgt1*etaErrorHEATPlusEMCmax176Rgt1);

 ErrorExposureRgt1.push_back(  etaErrorExposureEMCmax176Rgt1  );


 double etaErrorExposureEMCmax176Rgt2;
 double etaErrorCOPlusEMCmax176Rgt2;
 double etaErrorLMPlusEMCmax176Rgt2;
 double etaErrorLAPlusEMCmax176Rgt2;
 double etaErrorLLPlusEMCmax176Rgt2;
 double etaErrorHEATPlusEMCmax176Rgt2;

 if(etaEEMCmax176RFdgt2km!=0)
 		{
 		etaErrorCOPlusEMCmax176Rgt2 = (sqrt(EventsWithErecCOEMCmax176RFdgt2km ) / GeneratedEventsEMCmax176RFdgt2km ) * (exposureCoihuecoThetamin115EMCmax176Rgt2 /  etaEEMCmax176RFdgt2km) ;
 		etaErrorLMPlusEMCmax176Rgt2 = ( sqrt(EventsWithErecCOEMCmax176RFdgt2km ) / GeneratedEventsEMCmax176RFdgt2km ) * (exposureLMThetamin115EMCmax176Rgt2) /  etaEEMCmax176RFdgt2km;
 		etaErrorLAPlusEMCmax176Rgt2 = ( sqrt(EventsWithErecCOEMCmax176RFdgt2km ) / GeneratedEventsEMCmax176RFdgt2km ) * (exposureLAThetamin115EMCmax176Rgt2)/  etaEEMCmax176RFdgt2km ;
 		etaErrorLLPlusEMCmax176Rgt2 = (sqrt(EventsWithErecCOEMCmax176RFdgt2km ) / GeneratedEventsEMCmax176RFdgt2km ) *	(exposureLLEmin17Thetamin115EMCmax176Rgt2) /  etaEEMCmax176RFdgt2km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax176Rgt2 =0;
 		etaErrorLMPlusEMCmax176Rgt2 = 0;
 		etaErrorLAPlusEMCmax176Rgt2 = 0 ;
 		etaErrorLLPlusEMCmax176Rgt2 =0;
 		}

 	if( etaEHEATEMCmax176RFdgt2km!=0)
 	etaErrorHEATPlusEMCmax176Rgt2 = (sqrt(EventsWithErecHEATEMCmax176RFdgt2km ) / GeneratedEventsEMCmax176RFdgt2km ) * (exposureHEATThetamin115EMCmax176Rgt2)/  etaEHEATEMCmax176RFdgt2km ;
 	else
 	etaErrorHEATPlusEMCmax176Rgt2 =0;

 etaErrorExposureEMCmax176Rgt2 = sqrt(  etaErrorCOPlusEMCmax176Rgt2*etaErrorCOPlusEMCmax176Rgt2 + etaErrorLMPlusEMCmax176Rgt2*etaErrorLMPlusEMCmax176Rgt2 +
 		etaErrorLAPlusEMCmax176Rgt2*etaErrorLAPlusEMCmax176Rgt2 +  etaErrorLLPlusEMCmax176Rgt2* etaErrorLLPlusEMCmax176Rgt2
 		+etaErrorHEATPlusEMCmax176Rgt2*etaErrorHEATPlusEMCmax176Rgt2);

 ErrorExposureRgt2.push_back(  etaErrorExposureEMCmax176Rgt2  );

 double etaErrorExposureEMCmax176Rgt3;
 double etaErrorCOPlusEMCmax176Rgt3;
 double etaErrorLMPlusEMCmax176Rgt3;
 double etaErrorLAPlusEMCmax176Rgt3;
 double etaErrorLLPlusEMCmax176Rgt3;
 double etaErrorHEATPlusEMCmax176Rgt3;

 if(etaEEMCmax176RFdgt3km!=0)
 		{
 		etaErrorCOPlusEMCmax176Rgt3 = (sqrt(EventsWithErecCOEMCmax176RFdgt3km ) / GeneratedEventsEMCmax176RFdgt3km ) * (exposureCoihuecoThetamin115EMCmax176Rgt3 /  etaEEMCmax176RFdgt3km) ;
 		etaErrorLMPlusEMCmax176Rgt3 = ( sqrt(EventsWithErecCOEMCmax176RFdgt3km ) / GeneratedEventsEMCmax176RFdgt3km ) * (exposureLMThetamin115EMCmax176Rgt3) /  etaEEMCmax176RFdgt3km;
 		etaErrorLAPlusEMCmax176Rgt3 = ( sqrt(EventsWithErecCOEMCmax176RFdgt3km ) / GeneratedEventsEMCmax176RFdgt3km ) * (exposureLAThetamin115EMCmax176Rgt3)/  etaEEMCmax176RFdgt3km ;
 		etaErrorLLPlusEMCmax176Rgt3 = (sqrt(EventsWithErecCOEMCmax176RFdgt3km ) / GeneratedEventsEMCmax176RFdgt3km ) *	(exposureLLEmin17Thetamin115EMCmax176Rgt3) /  etaEEMCmax176RFdgt3km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax176Rgt3 =0;
 		etaErrorLMPlusEMCmax176Rgt3 = 0;
 		etaErrorLAPlusEMCmax176Rgt3 = 0 ;
 		etaErrorLLPlusEMCmax176Rgt3 =0;
 		}

 	if( etaEHEATEMCmax176RFdgt3km!=0)
 	etaErrorHEATPlusEMCmax176Rgt3 = (sqrt(EventsWithErecHEATEMCmax176RFdgt3km ) / GeneratedEventsEMCmax176RFdgt3km ) * (exposureHEATThetamin115EMCmax176Rgt3)/  etaEHEATEMCmax176RFdgt3km ;
 	else
 	etaErrorHEATPlusEMCmax176Rgt3 =0;

 etaErrorExposureEMCmax176Rgt3 = sqrt(  etaErrorCOPlusEMCmax176Rgt3*etaErrorCOPlusEMCmax176Rgt3 + etaErrorLMPlusEMCmax176Rgt3*etaErrorLMPlusEMCmax176Rgt3 +
 		etaErrorLAPlusEMCmax176Rgt3*etaErrorLAPlusEMCmax176Rgt3 +  etaErrorLLPlusEMCmax176Rgt3* etaErrorLLPlusEMCmax176Rgt3
 		+etaErrorHEATPlusEMCmax176Rgt3*etaErrorHEATPlusEMCmax176Rgt3);

 ErrorExposureRgt3.push_back(  etaErrorExposureEMCmax176Rgt3  );


 double etaErrorExposureEMCmax176Rgt4;
 double etaErrorCOPlusEMCmax176Rgt4;
 double etaErrorLMPlusEMCmax176Rgt4;
 double etaErrorLAPlusEMCmax176Rgt4;
 double etaErrorLLPlusEMCmax176Rgt4;
 double etaErrorHEATPlusEMCmax176Rgt4;

 if(etaEEMCmax176RFdgt4km!=0)
 		{
 		etaErrorCOPlusEMCmax176Rgt4 = (sqrt(EventsWithErecCOEMCmax176RFdgt4km ) / GeneratedEventsEMCmax176RFdgt4km ) * (exposureCoihuecoThetamin115EMCmax176Rgt4 /  etaEEMCmax176RFdgt4km) ;
 		etaErrorLMPlusEMCmax176Rgt4 = ( sqrt(EventsWithErecCOEMCmax176RFdgt4km ) / GeneratedEventsEMCmax176RFdgt4km ) * (exposureLMThetamin115EMCmax176Rgt4) /  etaEEMCmax176RFdgt4km;
 		etaErrorLAPlusEMCmax176Rgt4 = ( sqrt(EventsWithErecCOEMCmax176RFdgt4km ) / GeneratedEventsEMCmax176RFdgt4km ) * (exposureLAThetamin115EMCmax176Rgt4)/  etaEEMCmax176RFdgt4km ;
 		etaErrorLLPlusEMCmax176Rgt4 = (sqrt(EventsWithErecCOEMCmax176RFdgt4km ) / GeneratedEventsEMCmax176RFdgt4km ) *	(exposureLLEmin17Thetamin115EMCmax176Rgt4) /  etaEEMCmax176RFdgt4km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax176Rgt4 =0;
 		etaErrorLMPlusEMCmax176Rgt4 = 0;
 		etaErrorLAPlusEMCmax176Rgt4 = 0 ;
 		etaErrorLLPlusEMCmax176Rgt4 =0;
 		}

 	if( etaEHEATEMCmax176RFdgt4km!=0)
 	etaErrorHEATPlusEMCmax176Rgt4 = (sqrt(EventsWithErecHEATEMCmax176RFdgt4km ) / GeneratedEventsEMCmax176RFdgt4km ) * (exposureHEATThetamin115EMCmax176Rgt4)/  etaEHEATEMCmax176RFdgt4km ;
 	else
 	etaErrorHEATPlusEMCmax176Rgt4 =0;

 etaErrorExposureEMCmax176Rgt4 = sqrt(  etaErrorCOPlusEMCmax176Rgt4*etaErrorCOPlusEMCmax176Rgt4 + etaErrorLMPlusEMCmax176Rgt4*etaErrorLMPlusEMCmax176Rgt4 +
 		etaErrorLAPlusEMCmax176Rgt4*etaErrorLAPlusEMCmax176Rgt4 +  etaErrorLLPlusEMCmax176Rgt4* etaErrorLLPlusEMCmax176Rgt4
 		+etaErrorHEATPlusEMCmax176Rgt4*etaErrorHEATPlusEMCmax176Rgt4);

 ErrorExposureRgt4.push_back(  etaErrorExposureEMCmax176Rgt4  );


 double etaErrorExposureEMCmax176Rgt5;
 double etaErrorCOPlusEMCmax176Rgt5;
 double etaErrorLMPlusEMCmax176Rgt5;
 double etaErrorLAPlusEMCmax176Rgt5;
 double etaErrorLLPlusEMCmax176Rgt5;
 double etaErrorHEATPlusEMCmax176Rgt5;

 if(etaEEMCmax176RFdgt5km!=0)
 		{
 		etaErrorCOPlusEMCmax176Rgt5 = (sqrt(EventsWithErecCOEMCmax176RFdgt5km ) / GeneratedEventsEMCmax176RFdgt5km ) * (exposureCoihuecoThetamin115EMCmax176Rgt5 /  etaEEMCmax176RFdgt5km) ;
 		etaErrorLMPlusEMCmax176Rgt5 = ( sqrt(EventsWithErecCOEMCmax176RFdgt5km ) / GeneratedEventsEMCmax176RFdgt5km ) * (exposureLMThetamin115EMCmax176Rgt5) /  etaEEMCmax176RFdgt5km;
 		etaErrorLAPlusEMCmax176Rgt5 = ( sqrt(EventsWithErecCOEMCmax176RFdgt5km ) / GeneratedEventsEMCmax176RFdgt5km ) * (exposureLAThetamin115EMCmax176Rgt5)/  etaEEMCmax176RFdgt5km ;
 		etaErrorLLPlusEMCmax176Rgt5 = (sqrt(EventsWithErecCOEMCmax176RFdgt5km ) / GeneratedEventsEMCmax176RFdgt5km ) *	(exposureLLEmin17Thetamin115EMCmax176Rgt5) /  etaEEMCmax176RFdgt5km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax176Rgt5 =0;
 		etaErrorLMPlusEMCmax176Rgt5 = 0;
 		etaErrorLAPlusEMCmax176Rgt5 = 0 ;
 		etaErrorLLPlusEMCmax176Rgt5 =0;
 		}

 	if( etaEHEATEMCmax176RFdgt5km!=0)
 	etaErrorHEATPlusEMCmax176Rgt5 = (sqrt(EventsWithErecHEATEMCmax176RFdgt5km ) / GeneratedEventsEMCmax176RFdgt5km ) * (exposureHEATThetamin115EMCmax176Rgt5)/  etaEHEATEMCmax176RFdgt5km ;
 	else
 	etaErrorHEATPlusEMCmax176Rgt5 =0;

 etaErrorExposureEMCmax176Rgt5 = sqrt(  etaErrorCOPlusEMCmax176Rgt5*etaErrorCOPlusEMCmax176Rgt5 + etaErrorLMPlusEMCmax176Rgt5*etaErrorLMPlusEMCmax176Rgt5 +
 		etaErrorLAPlusEMCmax176Rgt5*etaErrorLAPlusEMCmax176Rgt5 +  etaErrorLLPlusEMCmax176Rgt5* etaErrorLLPlusEMCmax176Rgt5
 		+etaErrorHEATPlusEMCmax176Rgt5*etaErrorHEATPlusEMCmax176Rgt5);

 ErrorExposureRgt5.push_back(  etaErrorExposureEMCmax176Rgt5  );



double etaEEMCmax177; //etaE=recEvents/GenEvents ->reconstruction efficiency
etaEEMCmax177 = EventsWithErecCOEMCmax177 / GeneratedEventsEMCmax177;

double etaEHEATEMCmax177;
etaEHEATEMCmax177 = EventsWithErecHEATEMCmax177 / GeneratedEventsEMCmax177;
cout<<"etaE (E=17.6 ): "<<etaEEMCmax177<<endl;
ErrorEvents.push_back(sqrt(EventsWithErecCOEMCmax177 ));

double etaEEMCmax177RFdgt1km;
etaEEMCmax177RFdgt1km = EventsWithErecCOEMCmax177RFdgt1km / GeneratedEventsEMCmax177RFdgt1km;
double etaEEMCmax177RFdgt2km;
etaEEMCmax177RFdgt2km = EventsWithErecCOEMCmax177RFdgt2km / GeneratedEventsEMCmax177RFdgt2km;
double etaEEMCmax177RFdgt3km;
etaEEMCmax177RFdgt3km = EventsWithErecCOEMCmax177RFdgt3km / GeneratedEventsEMCmax177RFdgt3km;
double etaEEMCmax177RFdgt4km;
etaEEMCmax177RFdgt4km = EventsWithErecCOEMCmax177RFdgt4km / GeneratedEventsEMCmax177RFdgt4km;
double etaEEMCmax177RFdgt5km;
etaEEMCmax177RFdgt5km = EventsWithErecCOEMCmax177RFdgt5km / GeneratedEventsEMCmax177RFdgt5km;

double etaEHEATEMCmax177RFdgt1km;
etaEHEATEMCmax177RFdgt1km = EventsWithErecHEATEMCmax177RFdgt1km / GeneratedEventsEMCmax177RFdgt1km;
double etaEHEATEMCmax177RFdgt2km;
etaEHEATEMCmax177RFdgt2km = EventsWithErecHEATEMCmax177RFdgt2km / GeneratedEventsEMCmax177RFdgt2km;
double etaEHEATEMCmax177RFdgt3km;
etaEHEATEMCmax177RFdgt3km = EventsWithErecHEATEMCmax177RFdgt3km / GeneratedEventsEMCmax177RFdgt3km;
double etaEHEATEMCmax177RFdgt4km;
etaEHEATEMCmax177RFdgt4km = EventsWithErecHEATEMCmax177RFdgt4km / GeneratedEventsEMCmax177RFdgt4km;
double etaEHEATEMCmax177RFdgt5km;
etaEHEATEMCmax177RFdgt5km = EventsWithErecHEATEMCmax177RFdgt5km / GeneratedEventsEMCmax177RFdgt5km;

cout<<"total gen events: "<<TotalNrGenEvents<<" in (17.6, 17.7) nr of gen Events = "<<GeneratedEventsEMCmax177<<endl;


cout<<"nr or reconstructed ev: "<<EventsWithErecCOEMCmax177<<endl;



double apertureCoihuecoThetamin115EMCmax177 = etaEEMCmax177 * genAreaCO *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureCoihuecoThetamin115EMCmax177 = apertureCoihuecoThetamin115EMCmax177 * yearsCO;

double apertureLMThetamin115EMCmax177 = etaEEMCmax177 * genAreaLM *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLMThetamin115EMCmax177 = apertureLMThetamin115EMCmax177 * yearsLM;

  double apertureLAThetamin115EMCmax177 = etaEEMCmax177 * genAreaLA *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLAThetamin115EMCmax177 = apertureLAThetamin115EMCmax177 * yearsLA;

    double apertureLL180FOVThetamin115EMCmax177 = etaEEMCmax177 * genAreaLL180FOV *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLL180FOVThetamin115EMCmax177 = apertureLL180FOVThetamin115EMCmax177 * yearsLL180FOV;

  double apertureLL162FOVThetamin115EMCmax177 = etaEEMCmax177 * genAreaLL162FOV *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLL162FOVThetamin115EMCmax177 = apertureLL162FOVThetamin115EMCmax177 * yearsLL162FOV;

  double exposureLLEmin17Thetamin115EMCmax177 = exposureLL180FOVThetamin115EMCmax177 + exposureLL162FOVThetamin115EMCmax177;

  double apertureHEATThetamin115EMCmax177 = etaEHEATEMCmax177 * genAreaHEAT *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureHEATThetamin115EMCmax177 = apertureHEATThetamin115EMCmax177 * yearsHEAT;


  double Exposure4EyesThetamin115EMCmax177 = exposureCoihuecoThetamin115EMCmax177 + exposureLMThetamin115EMCmax177 +
                                            exposureLAThetamin115EMCmax177 + exposureLLEmin17Thetamin115EMCmax177 +	exposureHEATThetamin115EMCmax177;

  Exposure4EyesAllEnergiesThetamin115H0.push_back(Exposure4EyesThetamin115EMCmax177);


  double exposureCoihuecoThetamin115EMCmax177Rgt1 = etaEEMCmax177RFdgt1km * genAreaCORgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;
  double exposureCoihuecoThetamin115EMCmax177Rgt2 = etaEEMCmax177RFdgt2km * genAreaCORgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;
  double exposureCoihuecoThetamin115EMCmax177Rgt3 = etaEEMCmax177RFdgt3km * genAreaCORgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;

  double exposureLMThetamin115EMCmax177Rgt1 = etaEEMCmax177RFdgt1km * genAreaLMRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;
  double exposureLMThetamin115EMCmax177Rgt2 = etaEEMCmax177RFdgt2km * genAreaLMRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;
  double exposureLMThetamin115EMCmax177Rgt3 = etaEEMCmax177RFdgt3km * genAreaLMRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;

  double exposureLAThetamin115EMCmax177Rgt1 = etaEEMCmax177RFdgt1km * genAreaLARgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;
  double exposureLAThetamin115EMCmax177Rgt2 = etaEEMCmax177RFdgt2km * genAreaLARgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;
  double exposureLAThetamin115EMCmax177Rgt3 = etaEEMCmax177RFdgt3km * genAreaLARgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;

  double exposureLL180FOVThetamin115EMCmax177Rgt1 = etaEEMCmax177RFdgt1km * genAreaLL180FOVRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;
  double exposureLL180FOVThetamin115EMCmax177Rgt2 = etaEEMCmax177RFdgt2km * genAreaLL180FOVRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;
  double exposureLL180FOVThetamin115EMCmax177Rgt3 = etaEEMCmax177RFdgt3km * genAreaLL180FOVRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;

  double exposureLL162FOVThetamin115EMCmax177Rgt1 = etaEEMCmax177RFdgt1km * genAreaLL162FOVRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;
  double exposureLL162FOVThetamin115EMCmax177Rgt2 = etaEEMCmax177RFdgt2km * genAreaLL162FOVRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;
  double exposureLL162FOVThetamin115EMCmax177Rgt3 = etaEEMCmax177RFdgt3km * genAreaLL162FOVRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;

  double exposureLLEmin17Thetamin115EMCmax177Rgt1 =  exposureLL180FOVThetamin115EMCmax177Rgt1 + exposureLL162FOVThetamin115EMCmax177Rgt1;
  double exposureLLEmin17Thetamin115EMCmax177Rgt2 =  exposureLL180FOVThetamin115EMCmax177Rgt2 + exposureLL162FOVThetamin115EMCmax177Rgt2;
  double exposureLLEmin17Thetamin115EMCmax177Rgt3 =  exposureLL180FOVThetamin115EMCmax177Rgt3 + exposureLL162FOVThetamin115EMCmax177Rgt3;



  double exposureCoihuecoThetamin115EMCmax177Rgt4 = etaEEMCmax177RFdgt4km * genAreaCORgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;
  double exposureCoihuecoThetamin115EMCmax177Rgt5 = etaEEMCmax177RFdgt5km * genAreaCORgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;

  double exposureLMThetamin115EMCmax177Rgt4 = etaEEMCmax177RFdgt4km * genAreaLMRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;
  double exposureLMThetamin115EMCmax177Rgt5 = etaEEMCmax177RFdgt5km * genAreaLMRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;

  double exposureLAThetamin115EMCmax177Rgt4 = etaEEMCmax177RFdgt4km * genAreaLARgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;
  double exposureLAThetamin115EMCmax177Rgt5 = etaEEMCmax177RFdgt5km * genAreaLARgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;

  double exposureLL180FOVThetamin115EMCmax177Rgt4 = etaEEMCmax177RFdgt4km * genAreaLL180FOVRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;
  double exposureLL180FOVThetamin115EMCmax177Rgt5 = etaEEMCmax177RFdgt5km * genAreaLL180FOVRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;

  double exposureLL162FOVThetamin115EMCmax177Rgt4 = etaEEMCmax177RFdgt4km * genAreaLL162FOVRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;
  double exposureLL162FOVThetamin115EMCmax177Rgt5 = etaEEMCmax177RFdgt5km * genAreaLL162FOVRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;

  double exposureLLEmin17Thetamin115EMCmax177Rgt4 =  exposureLL180FOVThetamin115EMCmax177Rgt4 + exposureLL162FOVThetamin115EMCmax177Rgt4;
  double exposureLLEmin17Thetamin115EMCmax177Rgt5 =  exposureLL180FOVThetamin115EMCmax177Rgt5 + exposureLL162FOVThetamin115EMCmax177Rgt5;


  double exposureHEATThetamin115EMCmax177Rgt1 = etaEHEATEMCmax177RFdgt1km* genAreaHEATRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCmax177Rgt2 = etaEHEATEMCmax177RFdgt2km* genAreaHEATRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCmax177Rgt3 = etaEHEATEMCmax177RFdgt3km* genAreaHEATRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCmax177Rgt4 = etaEHEATEMCmax177RFdgt4km* genAreaHEATRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCmax177Rgt5 = etaEHEATEMCmax177RFdgt5km* genAreaHEATRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;


  Exposure4EyesAllEnergiesThetamin115H0Rgt4.push_back( exposureCoihuecoThetamin115EMCmax177Rgt4 +   exposureLMThetamin115EMCmax177Rgt4
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax177Rgt4 + exposureLLEmin17Thetamin115EMCmax177Rgt4
																													+ exposureHEATThetamin115EMCmax177Rgt4 );
  Exposure4EyesAllEnergiesThetamin115H0Rgt5.push_back( exposureCoihuecoThetamin115EMCmax177Rgt5 +   exposureLMThetamin115EMCmax177Rgt5
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax177Rgt5 + exposureLLEmin17Thetamin115EMCmax177Rgt5
																													+ exposureHEATThetamin115EMCmax177Rgt5);

  Exposure4EyesAllEnergiesThetamin115H0Rgt1.push_back( exposureCoihuecoThetamin115EMCmax177Rgt1 +   exposureLMThetamin115EMCmax177Rgt1
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax177Rgt1 + exposureLLEmin17Thetamin115EMCmax177Rgt1
																													+ exposureHEATThetamin115EMCmax177Rgt1);
  Exposure4EyesAllEnergiesThetamin115H0Rgt2.push_back( exposureCoihuecoThetamin115EMCmax177Rgt2 +   exposureLMThetamin115EMCmax177Rgt2
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax177Rgt2 + exposureLLEmin17Thetamin115EMCmax177Rgt2
																													+  exposureHEATThetamin115EMCmax177Rgt2);
  Exposure4EyesAllEnergiesThetamin115H0Rgt3.push_back( exposureCoihuecoThetamin115EMCmax177Rgt3 +   exposureLMThetamin115EMCmax177Rgt3
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax177Rgt3 + exposureLLEmin17Thetamin115EMCmax177Rgt3
																													+  exposureHEATThetamin115EMCmax177Rgt3);

 EnergyRangeVector.push_back(17.6);

 double etaErrorExposurePlusEMCmax177 ;
 double etaErrorCOPlusEMCmax177;
 double etaErrorLMPlusEMCmax177;
 double etaErrorLAPlusEMCmax177;
 double etaErrorLLPlusEMCmax177;
 double etaErrorHEATPlusEMCmax177;

 if( etaEEMCmax177!=0)
 		{
 		etaErrorCOPlusEMCmax177 = (sqrt(EventsWithErecCOEMCmax177 ) / GeneratedEventsEMCmax177 ) * (exposureCoihuecoThetamin115EMCmax177 /  etaEEMCmax177) ;
 		etaErrorLMPlusEMCmax177 = ( sqrt(EventsWithErecCOEMCmax177 ) / GeneratedEventsEMCmax177 ) * (exposureLMThetamin115EMCmax177) /  etaEEMCmax177;
 		etaErrorLAPlusEMCmax177 = ( sqrt(EventsWithErecCOEMCmax177 ) / GeneratedEventsEMCmax177 ) * (exposureLAThetamin115EMCmax177)/  etaEEMCmax177 ;
 		etaErrorLLPlusEMCmax177 = (sqrt(EventsWithErecCOEMCmax177 ) / GeneratedEventsEMCmax177 ) *	(exposureLLEmin17Thetamin115EMCmax177) /  etaEEMCmax177;
 		}
 else
 		{
 			etaErrorCOPlusEMCmax177 = 0 ;
 			etaErrorLMPlusEMCmax177 = 0;
 			etaErrorLAPlusEMCmax177 =0 ;
 			etaErrorLLPlusEMCmax177 =0;
 		}
 	if(etaEHEATEMCmax177!=0)
 		etaErrorHEATPlusEMCmax177 = (sqrt(EventsWithErecHEATEMCmax177 ) / GeneratedEventsEMCmax177 ) * (exposureHEATThetamin115EMCmax177)/  etaEHEATEMCmax177 ;
 	else
 		etaErrorHEATPlusEMCmax177 = 0;


 etaErrorExposurePlusEMCmax177 = sqrt(  etaErrorCOPlusEMCmax177*etaErrorCOPlusEMCmax177 + etaErrorLMPlusEMCmax177*etaErrorLMPlusEMCmax177 +
 																etaErrorLAPlusEMCmax177*etaErrorLAPlusEMCmax177 +  etaErrorLLPlusEMCmax177* etaErrorLLPlusEMCmax177
 																+etaErrorHEATPlusEMCmax177*etaErrorHEATPlusEMCmax177);

 cout<<" E=17  "<<"Error Total Exposure  "<<etaErrorExposurePlusEMCmax177 <<endl;

 cout<<"exposure CO: "<<exposureCoihuecoThetamin115EMCmax177 << " error: "<<etaErrorCOPlusEMCmax177<<endl;
 cout<<"exposure LA: "<<exposureLAThetamin115EMCmax177 << " error: "<<etaErrorLAPlusEMCmax177<<endl;
 cout<<"exposure LM: "<<exposureLMThetamin115EMCmax177 << " error: "<<etaErrorLMPlusEMCmax177<<endl;
 cout<<"exposure LL: "<<exposureLLEmin17Thetamin115EMCmax177 << " error: "<<etaErrorLLPlusEMCmax177<<endl;
 cout<<"exposure HEAT: "<<exposureHEATThetamin115EMCmax177 << " error: "<<etaErrorHEATPlusEMCmax177<<endl;


 ErrorExposurePlus.push_back(etaErrorExposurePlusEMCmax177);


 double etaErrorExposureEMCmax177Rgt1;
 double etaErrorCOPlusEMCmax177Rgt1;
 double etaErrorLMPlusEMCmax177Rgt1;
 double etaErrorLAPlusEMCmax177Rgt1;
 double etaErrorLLPlusEMCmax177Rgt1;
 double etaErrorHEATPlusEMCmax177Rgt1;

 if(etaEEMCmax177RFdgt1km!=0)
 		{
 		etaErrorCOPlusEMCmax177Rgt1 = (sqrt(EventsWithErecCOEMCmax177RFdgt1km ) / GeneratedEventsEMCmax177RFdgt1km ) * (exposureCoihuecoThetamin115EMCmax177Rgt1 /  etaEEMCmax177RFdgt1km) ;
 		etaErrorLMPlusEMCmax177Rgt1 = ( sqrt(EventsWithErecCOEMCmax177RFdgt1km ) / GeneratedEventsEMCmax177RFdgt1km ) * (exposureLMThetamin115EMCmax177Rgt1) /  etaEEMCmax177RFdgt1km;
 		etaErrorLAPlusEMCmax177Rgt1 = ( sqrt(EventsWithErecCOEMCmax177RFdgt1km ) / GeneratedEventsEMCmax177RFdgt1km ) * (exposureLAThetamin115EMCmax177Rgt1)/  etaEEMCmax177RFdgt1km ;
 		etaErrorLLPlusEMCmax177Rgt1 = (sqrt(EventsWithErecCOEMCmax177RFdgt1km ) / GeneratedEventsEMCmax177RFdgt1km ) *	(exposureLLEmin17Thetamin115EMCmax177Rgt1) /  etaEEMCmax177RFdgt1km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax177Rgt1 =0;
 		etaErrorLMPlusEMCmax177Rgt1 = 0;
 		etaErrorLAPlusEMCmax177Rgt1 = 0 ;
 		etaErrorLLPlusEMCmax177Rgt1 =0;
 		}

 	if( etaEHEATEMCmax177RFdgt1km!=0)
 	etaErrorHEATPlusEMCmax177Rgt1 = (sqrt(EventsWithErecHEATEMCmax177RFdgt1km ) / GeneratedEventsEMCmax177RFdgt1km ) * (exposureHEATThetamin115EMCmax177Rgt1)/  etaEHEATEMCmax177RFdgt1km ;
 	else
 	etaErrorHEATPlusEMCmax177Rgt1 =0;

 etaErrorExposureEMCmax177Rgt1 = sqrt(  etaErrorCOPlusEMCmax177Rgt1*etaErrorCOPlusEMCmax177Rgt1 + etaErrorLMPlusEMCmax177Rgt1*etaErrorLMPlusEMCmax177Rgt1 +
 		etaErrorLAPlusEMCmax177Rgt1*etaErrorLAPlusEMCmax177Rgt1 +  etaErrorLLPlusEMCmax177Rgt1* etaErrorLLPlusEMCmax177Rgt1
 		+etaErrorHEATPlusEMCmax177Rgt1*etaErrorHEATPlusEMCmax177Rgt1);

 ErrorExposureRgt1.push_back(  etaErrorExposureEMCmax177Rgt1  );


 double etaErrorExposureEMCmax177Rgt2;
 double etaErrorCOPlusEMCmax177Rgt2;
 double etaErrorLMPlusEMCmax177Rgt2;
 double etaErrorLAPlusEMCmax177Rgt2;
 double etaErrorLLPlusEMCmax177Rgt2;
 double etaErrorHEATPlusEMCmax177Rgt2;

 if(etaEEMCmax177RFdgt2km!=0)
 		{
 		etaErrorCOPlusEMCmax177Rgt2 = (sqrt(EventsWithErecCOEMCmax177RFdgt2km ) / GeneratedEventsEMCmax177RFdgt2km ) * (exposureCoihuecoThetamin115EMCmax177Rgt2 /  etaEEMCmax177RFdgt2km) ;
 		etaErrorLMPlusEMCmax177Rgt2 = ( sqrt(EventsWithErecCOEMCmax177RFdgt2km ) / GeneratedEventsEMCmax177RFdgt2km ) * (exposureLMThetamin115EMCmax177Rgt2) /  etaEEMCmax177RFdgt2km;
 		etaErrorLAPlusEMCmax177Rgt2 = ( sqrt(EventsWithErecCOEMCmax177RFdgt2km ) / GeneratedEventsEMCmax177RFdgt2km ) * (exposureLAThetamin115EMCmax177Rgt2)/  etaEEMCmax177RFdgt2km ;
 		etaErrorLLPlusEMCmax177Rgt2 = (sqrt(EventsWithErecCOEMCmax177RFdgt2km ) / GeneratedEventsEMCmax177RFdgt2km ) *	(exposureLLEmin17Thetamin115EMCmax177Rgt2) /  etaEEMCmax177RFdgt2km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax177Rgt2 =0;
 		etaErrorLMPlusEMCmax177Rgt2 = 0;
 		etaErrorLAPlusEMCmax177Rgt2 = 0 ;
 		etaErrorLLPlusEMCmax177Rgt2 =0;
 		}

 	if( etaEHEATEMCmax177RFdgt2km!=0)
 	etaErrorHEATPlusEMCmax177Rgt2 = (sqrt(EventsWithErecHEATEMCmax177RFdgt2km ) / GeneratedEventsEMCmax177RFdgt2km ) * (exposureHEATThetamin115EMCmax177Rgt2)/  etaEHEATEMCmax177RFdgt2km ;
 	else
 	etaErrorHEATPlusEMCmax177Rgt2 =0;

 etaErrorExposureEMCmax177Rgt2 = sqrt(  etaErrorCOPlusEMCmax177Rgt2*etaErrorCOPlusEMCmax177Rgt2 + etaErrorLMPlusEMCmax177Rgt2*etaErrorLMPlusEMCmax177Rgt2 +
 		etaErrorLAPlusEMCmax177Rgt2*etaErrorLAPlusEMCmax177Rgt2 +  etaErrorLLPlusEMCmax177Rgt2* etaErrorLLPlusEMCmax177Rgt2
 		+etaErrorHEATPlusEMCmax177Rgt2*etaErrorHEATPlusEMCmax177Rgt2);

 ErrorExposureRgt2.push_back(  etaErrorExposureEMCmax177Rgt2  );

 double etaErrorExposureEMCmax177Rgt3;
 double etaErrorCOPlusEMCmax177Rgt3;
 double etaErrorLMPlusEMCmax177Rgt3;
 double etaErrorLAPlusEMCmax177Rgt3;
 double etaErrorLLPlusEMCmax177Rgt3;
 double etaErrorHEATPlusEMCmax177Rgt3;

 if(etaEEMCmax177RFdgt3km!=0)
 		{
 		etaErrorCOPlusEMCmax177Rgt3 = (sqrt(EventsWithErecCOEMCmax177RFdgt3km ) / GeneratedEventsEMCmax177RFdgt3km ) * (exposureCoihuecoThetamin115EMCmax177Rgt3 /  etaEEMCmax177RFdgt3km) ;
 		etaErrorLMPlusEMCmax177Rgt3 = ( sqrt(EventsWithErecCOEMCmax177RFdgt3km ) / GeneratedEventsEMCmax177RFdgt3km ) * (exposureLMThetamin115EMCmax177Rgt3) /  etaEEMCmax177RFdgt3km;
 		etaErrorLAPlusEMCmax177Rgt3 = ( sqrt(EventsWithErecCOEMCmax177RFdgt3km ) / GeneratedEventsEMCmax177RFdgt3km ) * (exposureLAThetamin115EMCmax177Rgt3)/  etaEEMCmax177RFdgt3km ;
 		etaErrorLLPlusEMCmax177Rgt3 = (sqrt(EventsWithErecCOEMCmax177RFdgt3km ) / GeneratedEventsEMCmax177RFdgt3km ) *	(exposureLLEmin17Thetamin115EMCmax177Rgt3) /  etaEEMCmax177RFdgt3km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax177Rgt3 =0;
 		etaErrorLMPlusEMCmax177Rgt3 = 0;
 		etaErrorLAPlusEMCmax177Rgt3 = 0 ;
 		etaErrorLLPlusEMCmax177Rgt3 =0;
 		}

 	if( etaEHEATEMCmax177RFdgt3km!=0)
 	etaErrorHEATPlusEMCmax177Rgt3 = (sqrt(EventsWithErecHEATEMCmax177RFdgt3km ) / GeneratedEventsEMCmax177RFdgt3km ) * (exposureHEATThetamin115EMCmax177Rgt3)/  etaEHEATEMCmax177RFdgt3km ;
 	else
 	etaErrorHEATPlusEMCmax177Rgt3 =0;

 etaErrorExposureEMCmax177Rgt3 = sqrt(  etaErrorCOPlusEMCmax177Rgt3*etaErrorCOPlusEMCmax177Rgt3 + etaErrorLMPlusEMCmax177Rgt3*etaErrorLMPlusEMCmax177Rgt3 +
 		etaErrorLAPlusEMCmax177Rgt3*etaErrorLAPlusEMCmax177Rgt3 +  etaErrorLLPlusEMCmax177Rgt3* etaErrorLLPlusEMCmax177Rgt3
 		+etaErrorHEATPlusEMCmax177Rgt3*etaErrorHEATPlusEMCmax177Rgt3);

 ErrorExposureRgt3.push_back(  etaErrorExposureEMCmax177Rgt3  );


 double etaErrorExposureEMCmax177Rgt4;
 double etaErrorCOPlusEMCmax177Rgt4;
 double etaErrorLMPlusEMCmax177Rgt4;
 double etaErrorLAPlusEMCmax177Rgt4;
 double etaErrorLLPlusEMCmax177Rgt4;
 double etaErrorHEATPlusEMCmax177Rgt4;

 if(etaEEMCmax177RFdgt4km!=0)
 		{
 		etaErrorCOPlusEMCmax177Rgt4 = (sqrt(EventsWithErecCOEMCmax177RFdgt4km ) / GeneratedEventsEMCmax177RFdgt4km ) * (exposureCoihuecoThetamin115EMCmax177Rgt4 /  etaEEMCmax177RFdgt4km) ;
 		etaErrorLMPlusEMCmax177Rgt4 = ( sqrt(EventsWithErecCOEMCmax177RFdgt4km ) / GeneratedEventsEMCmax177RFdgt4km ) * (exposureLMThetamin115EMCmax177Rgt4) /  etaEEMCmax177RFdgt4km;
 		etaErrorLAPlusEMCmax177Rgt4 = ( sqrt(EventsWithErecCOEMCmax177RFdgt4km ) / GeneratedEventsEMCmax177RFdgt4km ) * (exposureLAThetamin115EMCmax177Rgt4)/  etaEEMCmax177RFdgt4km ;
 		etaErrorLLPlusEMCmax177Rgt4 = (sqrt(EventsWithErecCOEMCmax177RFdgt4km ) / GeneratedEventsEMCmax177RFdgt4km ) *	(exposureLLEmin17Thetamin115EMCmax177Rgt4) /  etaEEMCmax177RFdgt4km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax177Rgt4 =0;
 		etaErrorLMPlusEMCmax177Rgt4 = 0;
 		etaErrorLAPlusEMCmax177Rgt4 = 0 ;
 		etaErrorLLPlusEMCmax177Rgt4 =0;
 		}

 	if( etaEHEATEMCmax177RFdgt4km!=0)
 	etaErrorHEATPlusEMCmax177Rgt4 = (sqrt(EventsWithErecHEATEMCmax177RFdgt4km ) / GeneratedEventsEMCmax177RFdgt4km ) * (exposureHEATThetamin115EMCmax177Rgt4)/  etaEHEATEMCmax177RFdgt4km ;
 	else
 	etaErrorHEATPlusEMCmax177Rgt4 =0;

 etaErrorExposureEMCmax177Rgt4 = sqrt(  etaErrorCOPlusEMCmax177Rgt4*etaErrorCOPlusEMCmax177Rgt4 + etaErrorLMPlusEMCmax177Rgt4*etaErrorLMPlusEMCmax177Rgt4 +
 		etaErrorLAPlusEMCmax177Rgt4*etaErrorLAPlusEMCmax177Rgt4 +  etaErrorLLPlusEMCmax177Rgt4* etaErrorLLPlusEMCmax177Rgt4
 		+etaErrorHEATPlusEMCmax177Rgt4*etaErrorHEATPlusEMCmax177Rgt4);

 ErrorExposureRgt4.push_back(  etaErrorExposureEMCmax177Rgt4  );


 double etaErrorExposureEMCmax177Rgt5;
 double etaErrorCOPlusEMCmax177Rgt5;
 double etaErrorLMPlusEMCmax177Rgt5;
 double etaErrorLAPlusEMCmax177Rgt5;
 double etaErrorLLPlusEMCmax177Rgt5;
 double etaErrorHEATPlusEMCmax177Rgt5;

 if(etaEEMCmax177RFdgt5km!=0)
 		{
 		etaErrorCOPlusEMCmax177Rgt5 = (sqrt(EventsWithErecCOEMCmax177RFdgt5km ) / GeneratedEventsEMCmax177RFdgt5km ) * (exposureCoihuecoThetamin115EMCmax177Rgt5 /  etaEEMCmax177RFdgt5km) ;
 		etaErrorLMPlusEMCmax177Rgt5 = ( sqrt(EventsWithErecCOEMCmax177RFdgt5km ) / GeneratedEventsEMCmax177RFdgt5km ) * (exposureLMThetamin115EMCmax177Rgt5) /  etaEEMCmax177RFdgt5km;
 		etaErrorLAPlusEMCmax177Rgt5 = ( sqrt(EventsWithErecCOEMCmax177RFdgt5km ) / GeneratedEventsEMCmax177RFdgt5km ) * (exposureLAThetamin115EMCmax177Rgt5)/  etaEEMCmax177RFdgt5km ;
 		etaErrorLLPlusEMCmax177Rgt5 = (sqrt(EventsWithErecCOEMCmax177RFdgt5km ) / GeneratedEventsEMCmax177RFdgt5km ) *	(exposureLLEmin17Thetamin115EMCmax177Rgt5) /  etaEEMCmax177RFdgt5km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax177Rgt5 =0;
 		etaErrorLMPlusEMCmax177Rgt5 = 0;
 		etaErrorLAPlusEMCmax177Rgt5 = 0 ;
 		etaErrorLLPlusEMCmax177Rgt5 =0;
 		}

 	if( etaEHEATEMCmax177RFdgt5km!=0)
 	etaErrorHEATPlusEMCmax177Rgt5 = (sqrt(EventsWithErecHEATEMCmax177RFdgt5km ) / GeneratedEventsEMCmax177RFdgt5km ) * (exposureHEATThetamin115EMCmax177Rgt5)/  etaEHEATEMCmax177RFdgt5km ;
 	else
 	etaErrorHEATPlusEMCmax177Rgt5 =0;

 etaErrorExposureEMCmax177Rgt5 = sqrt(  etaErrorCOPlusEMCmax177Rgt5*etaErrorCOPlusEMCmax177Rgt5 + etaErrorLMPlusEMCmax177Rgt5*etaErrorLMPlusEMCmax177Rgt5 +
 		etaErrorLAPlusEMCmax177Rgt5*etaErrorLAPlusEMCmax177Rgt5 +  etaErrorLLPlusEMCmax177Rgt5* etaErrorLLPlusEMCmax177Rgt5
 		+etaErrorHEATPlusEMCmax177Rgt5*etaErrorHEATPlusEMCmax177Rgt5);

 ErrorExposureRgt5.push_back(  etaErrorExposureEMCmax177Rgt5  );


double etaEEMCmax178; //etaE=recEvents/GenEvents ->reconstruction efficiency
etaEEMCmax178 = EventsWithErecCOEMCmax178 / GeneratedEventsEMCmax178;

double etaEHEATEMCmax178;
etaEHEATEMCmax178 = EventsWithErecHEATEMCmax178 / GeneratedEventsEMCmax178;
cout<<"etaE (E = 17.7): "<<etaEEMCmax178<<endl;
ErrorEvents.push_back(sqrt(EventsWithErecCOEMCmax178 ));

double etaEEMCmax178RFdgt1km;
etaEEMCmax178RFdgt1km = EventsWithErecCOEMCmax178RFdgt1km / GeneratedEventsEMCmax178RFdgt1km;
double etaEEMCmax178RFdgt2km;
etaEEMCmax178RFdgt2km = EventsWithErecCOEMCmax178RFdgt2km / GeneratedEventsEMCmax178RFdgt2km;
double etaEEMCmax178RFdgt3km;
etaEEMCmax178RFdgt3km = EventsWithErecCOEMCmax178RFdgt3km / GeneratedEventsEMCmax178RFdgt3km;
double etaEEMCmax178RFdgt4km;
etaEEMCmax178RFdgt4km = EventsWithErecCOEMCmax178RFdgt4km / GeneratedEventsEMCmax178RFdgt4km;
double etaEEMCmax178RFdgt5km;
etaEEMCmax178RFdgt5km = EventsWithErecCOEMCmax178RFdgt5km / GeneratedEventsEMCmax178RFdgt5km;

double etaEHEATEMCmax178RFdgt1km;
etaEHEATEMCmax178RFdgt1km = EventsWithErecHEATEMCmax178RFdgt1km / GeneratedEventsEMCmax178RFdgt1km;
double etaEHEATEMCmax178RFdgt2km;
etaEHEATEMCmax178RFdgt2km = EventsWithErecHEATEMCmax178RFdgt2km / GeneratedEventsEMCmax178RFdgt2km;
double etaEHEATEMCmax178RFdgt3km;
etaEHEATEMCmax178RFdgt3km = EventsWithErecHEATEMCmax178RFdgt3km / GeneratedEventsEMCmax178RFdgt3km;
double etaEHEATEMCmax178RFdgt4km;
etaEHEATEMCmax178RFdgt4km = EventsWithErecHEATEMCmax178RFdgt4km / GeneratedEventsEMCmax178RFdgt4km;
double etaEHEATEMCmax178RFdgt5km;
etaEHEATEMCmax178RFdgt5km = EventsWithErecHEATEMCmax178RFdgt5km / GeneratedEventsEMCmax178RFdgt5km;

cout<<"total gen events: "<<TotalNrGenEvents<<" in (17.7, 17.8) nr of gen Events = "<<GeneratedEventsEMCmax178<<endl;


cout<<"nr or reconstructed ev: "<<EventsWithErecCOEMCmax178<<endl;



double apertureCoihuecoThetamin115EMCmax178 = etaEEMCmax178 * genAreaCO *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureCoihuecoThetamin115EMCmax178 = apertureCoihuecoThetamin115EMCmax178 * yearsCO;

double apertureLMThetamin115EMCmax178 = etaEEMCmax178 * genAreaLM *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLMThetamin115EMCmax178 = apertureLMThetamin115EMCmax178 * yearsLM;

  double apertureLAThetamin115EMCmax178 = etaEEMCmax178 * genAreaLA *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLAThetamin115EMCmax178 = apertureLAThetamin115EMCmax178 * yearsLA;

    double apertureLL180FOVThetamin115EMCmax178 = etaEEMCmax178 * genAreaLL180FOV *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLL180FOVThetamin115EMCmax178 = apertureLL180FOVThetamin115EMCmax178 * yearsLL180FOV;

  double apertureLL162FOVThetamin115EMCmax178 = etaEEMCmax178 * genAreaLL162FOV *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLL162FOVThetamin115EMCmax178 = apertureLL162FOVThetamin115EMCmax178 * yearsLL162FOV;

  double exposureLLEmin17Thetamin115EMCmax178 = exposureLL180FOVThetamin115EMCmax178 + exposureLL162FOVThetamin115EMCmax178;

  double apertureHEATThetamin115EMCmax178 = etaEHEATEMCmax178 * genAreaHEAT *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureHEATThetamin115EMCmax178 = apertureHEATThetamin115EMCmax178 * yearsHEAT;


  double Exposure4EyesThetamin115EMCmax178 = exposureCoihuecoThetamin115EMCmax178 + exposureLMThetamin115EMCmax178 +
                                            exposureLAThetamin115EMCmax178 + exposureLLEmin17Thetamin115EMCmax178 +	exposureHEATThetamin115EMCmax178;

  Exposure4EyesAllEnergiesThetamin115H0.push_back(Exposure4EyesThetamin115EMCmax178);


  double exposureCoihuecoThetamin115EMCmax178Rgt1 = etaEEMCmax178RFdgt1km * genAreaCORgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;
  double exposureCoihuecoThetamin115EMCmax178Rgt2 = etaEEMCmax178RFdgt2km * genAreaCORgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;
  double exposureCoihuecoThetamin115EMCmax178Rgt3 = etaEEMCmax178RFdgt3km * genAreaCORgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;

  double exposureLMThetamin115EMCmax178Rgt1 = etaEEMCmax178RFdgt1km * genAreaLMRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;
  double exposureLMThetamin115EMCmax178Rgt2 = etaEEMCmax178RFdgt2km * genAreaLMRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;
  double exposureLMThetamin115EMCmax178Rgt3 = etaEEMCmax178RFdgt3km * genAreaLMRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;

  double exposureLAThetamin115EMCmax178Rgt1 = etaEEMCmax178RFdgt1km * genAreaLARgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;
  double exposureLAThetamin115EMCmax178Rgt2 = etaEEMCmax178RFdgt2km * genAreaLARgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;
  double exposureLAThetamin115EMCmax178Rgt3 = etaEEMCmax178RFdgt3km * genAreaLARgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;

  double exposureLL180FOVThetamin115EMCmax178Rgt1 = etaEEMCmax178RFdgt1km * genAreaLL180FOVRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;
  double exposureLL180FOVThetamin115EMCmax178Rgt2 = etaEEMCmax178RFdgt2km * genAreaLL180FOVRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;
  double exposureLL180FOVThetamin115EMCmax178Rgt3 = etaEEMCmax178RFdgt3km * genAreaLL180FOVRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;

  double exposureLL162FOVThetamin115EMCmax178Rgt1 = etaEEMCmax178RFdgt1km * genAreaLL162FOVRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;
  double exposureLL162FOVThetamin115EMCmax178Rgt2 = etaEEMCmax178RFdgt2km * genAreaLL162FOVRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;
  double exposureLL162FOVThetamin115EMCmax178Rgt3 = etaEEMCmax178RFdgt3km * genAreaLL162FOVRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;

  double exposureLLEmin17Thetamin115EMCmax178Rgt1 =  exposureLL180FOVThetamin115EMCmax178Rgt1 + exposureLL162FOVThetamin115EMCmax178Rgt1;
  double exposureLLEmin17Thetamin115EMCmax178Rgt2 =  exposureLL180FOVThetamin115EMCmax178Rgt2 + exposureLL162FOVThetamin115EMCmax178Rgt2;
  double exposureLLEmin17Thetamin115EMCmax178Rgt3 =  exposureLL180FOVThetamin115EMCmax178Rgt3 + exposureLL162FOVThetamin115EMCmax178Rgt3;



  double exposureCoihuecoThetamin115EMCmax178Rgt4 = etaEEMCmax178RFdgt4km * genAreaCORgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;
  double exposureCoihuecoThetamin115EMCmax178Rgt5 = etaEEMCmax178RFdgt5km * genAreaCORgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;

  double exposureLMThetamin115EMCmax178Rgt4 = etaEEMCmax178RFdgt4km * genAreaLMRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;
  double exposureLMThetamin115EMCmax178Rgt5 = etaEEMCmax178RFdgt5km * genAreaLMRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;

  double exposureLAThetamin115EMCmax178Rgt4 = etaEEMCmax178RFdgt4km * genAreaLARgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;
  double exposureLAThetamin115EMCmax178Rgt5 = etaEEMCmax178RFdgt5km * genAreaLARgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;

  double exposureLL180FOVThetamin115EMCmax178Rgt4 = etaEEMCmax178RFdgt4km * genAreaLL180FOVRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;
  double exposureLL180FOVThetamin115EMCmax178Rgt5 = etaEEMCmax178RFdgt5km * genAreaLL180FOVRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;

  double exposureLL162FOVThetamin115EMCmax178Rgt4 = etaEEMCmax178RFdgt4km * genAreaLL162FOVRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;
  double exposureLL162FOVThetamin115EMCmax178Rgt5 = etaEEMCmax178RFdgt5km * genAreaLL162FOVRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;

  double exposureLLEmin17Thetamin115EMCmax178Rgt4 =  exposureLL180FOVThetamin115EMCmax178Rgt4 + exposureLL162FOVThetamin115EMCmax178Rgt4;
  double exposureLLEmin17Thetamin115EMCmax178Rgt5 =  exposureLL180FOVThetamin115EMCmax178Rgt5 + exposureLL162FOVThetamin115EMCmax178Rgt5;


  double exposureHEATThetamin115EMCmax178Rgt1 = etaEHEATEMCmax178RFdgt1km* genAreaHEATRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCmax178Rgt2 = etaEHEATEMCmax178RFdgt2km* genAreaHEATRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCmax178Rgt3 = etaEHEATEMCmax178RFdgt3km* genAreaHEATRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCmax178Rgt4 = etaEHEATEMCmax178RFdgt4km* genAreaHEATRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCmax178Rgt5 = etaEHEATEMCmax178RFdgt5km* genAreaHEATRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;


  Exposure4EyesAllEnergiesThetamin115H0Rgt4.push_back( exposureCoihuecoThetamin115EMCmax178Rgt4 +   exposureLMThetamin115EMCmax178Rgt4
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax178Rgt4 + exposureLLEmin17Thetamin115EMCmax178Rgt4
																													+ exposureHEATThetamin115EMCmax178Rgt4 );
  Exposure4EyesAllEnergiesThetamin115H0Rgt5.push_back( exposureCoihuecoThetamin115EMCmax178Rgt5 +   exposureLMThetamin115EMCmax178Rgt5
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax178Rgt5 + exposureLLEmin17Thetamin115EMCmax178Rgt5
																													+ exposureHEATThetamin115EMCmax178Rgt5);

  Exposure4EyesAllEnergiesThetamin115H0Rgt1.push_back( exposureCoihuecoThetamin115EMCmax178Rgt1 +   exposureLMThetamin115EMCmax178Rgt1
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax178Rgt1 + exposureLLEmin17Thetamin115EMCmax178Rgt1
																													+ exposureHEATThetamin115EMCmax178Rgt1);
  Exposure4EyesAllEnergiesThetamin115H0Rgt2.push_back( exposureCoihuecoThetamin115EMCmax178Rgt2 +   exposureLMThetamin115EMCmax178Rgt2
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax178Rgt2 + exposureLLEmin17Thetamin115EMCmax178Rgt2
																													+  exposureHEATThetamin115EMCmax178Rgt2);
  Exposure4EyesAllEnergiesThetamin115H0Rgt3.push_back( exposureCoihuecoThetamin115EMCmax178Rgt3 +   exposureLMThetamin115EMCmax178Rgt3
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax178Rgt3 + exposureLLEmin17Thetamin115EMCmax178Rgt3
																													+  exposureHEATThetamin115EMCmax178Rgt3);

 EnergyRangeVector.push_back(17.7);

 double etaErrorExposurePlusEMCmax178 ;
 double etaErrorCOPlusEMCmax178;
 double etaErrorLMPlusEMCmax178;
 double etaErrorLAPlusEMCmax178;
 double etaErrorLLPlusEMCmax178;
 double etaErrorHEATPlusEMCmax178;

 if( etaEEMCmax178!=0)
 		{
 		etaErrorCOPlusEMCmax178 = (sqrt(EventsWithErecCOEMCmax178 ) / GeneratedEventsEMCmax178 ) * (exposureCoihuecoThetamin115EMCmax178 /  etaEEMCmax178) ;
 		etaErrorLMPlusEMCmax178 = ( sqrt(EventsWithErecCOEMCmax178 ) / GeneratedEventsEMCmax178 ) * (exposureLMThetamin115EMCmax178) /  etaEEMCmax178;
 		etaErrorLAPlusEMCmax178 = ( sqrt(EventsWithErecCOEMCmax178 ) / GeneratedEventsEMCmax178 ) * (exposureLAThetamin115EMCmax178)/  etaEEMCmax178 ;
 		etaErrorLLPlusEMCmax178 = (sqrt(EventsWithErecCOEMCmax178 ) / GeneratedEventsEMCmax178 ) *	(exposureLLEmin17Thetamin115EMCmax178) /  etaEEMCmax178;
 		}
 else
 		{
 			etaErrorCOPlusEMCmax178 = 0 ;
 			etaErrorLMPlusEMCmax178 = 0;
 			etaErrorLAPlusEMCmax178 =0 ;
 			etaErrorLLPlusEMCmax178 =0;
 		}
 	if(etaEHEATEMCmax178!=0)
 		etaErrorHEATPlusEMCmax178 = (sqrt(EventsWithErecHEATEMCmax178 ) / GeneratedEventsEMCmax178 ) * (exposureHEATThetamin115EMCmax178)/  etaEHEATEMCmax178 ;
 	else
 		etaErrorHEATPlusEMCmax178 = 0;


 etaErrorExposurePlusEMCmax178 = sqrt(  etaErrorCOPlusEMCmax178*etaErrorCOPlusEMCmax178 + etaErrorLMPlusEMCmax178*etaErrorLMPlusEMCmax178 +
 																etaErrorLAPlusEMCmax178*etaErrorLAPlusEMCmax178 +  etaErrorLLPlusEMCmax178* etaErrorLLPlusEMCmax178
 																+etaErrorHEATPlusEMCmax178*etaErrorHEATPlusEMCmax178);

 cout<<" E=17  "<<"Error Total Exposure  "<<etaErrorExposurePlusEMCmax178 <<endl;

 cout<<"exposure CO: "<<exposureCoihuecoThetamin115EMCmax178 << " error: "<<etaErrorCOPlusEMCmax178<<endl;
 cout<<"exposure LA: "<<exposureLAThetamin115EMCmax178 << " error: "<<etaErrorLAPlusEMCmax178<<endl;
 cout<<"exposure LM: "<<exposureLMThetamin115EMCmax178 << " error: "<<etaErrorLMPlusEMCmax178<<endl;
 cout<<"exposure LL: "<<exposureLLEmin17Thetamin115EMCmax178 << " error: "<<etaErrorLLPlusEMCmax178<<endl;
 cout<<"exposure HEAT: "<<exposureHEATThetamin115EMCmax178 << " error: "<<etaErrorHEATPlusEMCmax178<<endl;


 ErrorExposurePlus.push_back(etaErrorExposurePlusEMCmax178);


 double etaErrorExposureEMCmax178Rgt1;
 double etaErrorCOPlusEMCmax178Rgt1;
 double etaErrorLMPlusEMCmax178Rgt1;
 double etaErrorLAPlusEMCmax178Rgt1;
 double etaErrorLLPlusEMCmax178Rgt1;
 double etaErrorHEATPlusEMCmax178Rgt1;

 if(etaEEMCmax178RFdgt1km!=0)
 		{
 		etaErrorCOPlusEMCmax178Rgt1 = (sqrt(EventsWithErecCOEMCmax178RFdgt1km ) / GeneratedEventsEMCmax178RFdgt1km ) * (exposureCoihuecoThetamin115EMCmax178Rgt1 /  etaEEMCmax178RFdgt1km) ;
 		etaErrorLMPlusEMCmax178Rgt1 = ( sqrt(EventsWithErecCOEMCmax178RFdgt1km ) / GeneratedEventsEMCmax178RFdgt1km ) * (exposureLMThetamin115EMCmax178Rgt1) /  etaEEMCmax178RFdgt1km;
 		etaErrorLAPlusEMCmax178Rgt1 = ( sqrt(EventsWithErecCOEMCmax178RFdgt1km ) / GeneratedEventsEMCmax178RFdgt1km ) * (exposureLAThetamin115EMCmax178Rgt1)/  etaEEMCmax178RFdgt1km ;
 		etaErrorLLPlusEMCmax178Rgt1 = (sqrt(EventsWithErecCOEMCmax178RFdgt1km ) / GeneratedEventsEMCmax178RFdgt1km ) *	(exposureLLEmin17Thetamin115EMCmax178Rgt1) /  etaEEMCmax178RFdgt1km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax178Rgt1 =0;
 		etaErrorLMPlusEMCmax178Rgt1 = 0;
 		etaErrorLAPlusEMCmax178Rgt1 = 0 ;
 		etaErrorLLPlusEMCmax178Rgt1 =0;
 		}

 	if( etaEHEATEMCmax178RFdgt1km!=0)
 	etaErrorHEATPlusEMCmax178Rgt1 = (sqrt(EventsWithErecHEATEMCmax178RFdgt1km ) / GeneratedEventsEMCmax178RFdgt1km ) * (exposureHEATThetamin115EMCmax178Rgt1)/  etaEHEATEMCmax178RFdgt1km ;
 	else
 	etaErrorHEATPlusEMCmax178Rgt1 =0;

 etaErrorExposureEMCmax178Rgt1 = sqrt(  etaErrorCOPlusEMCmax178Rgt1*etaErrorCOPlusEMCmax178Rgt1 + etaErrorLMPlusEMCmax178Rgt1*etaErrorLMPlusEMCmax178Rgt1 +
 		etaErrorLAPlusEMCmax178Rgt1*etaErrorLAPlusEMCmax178Rgt1 +  etaErrorLLPlusEMCmax178Rgt1* etaErrorLLPlusEMCmax178Rgt1
 		+etaErrorHEATPlusEMCmax178Rgt1*etaErrorHEATPlusEMCmax178Rgt1);

 ErrorExposureRgt1.push_back(  etaErrorExposureEMCmax178Rgt1  );


 double etaErrorExposureEMCmax178Rgt2;
 double etaErrorCOPlusEMCmax178Rgt2;
 double etaErrorLMPlusEMCmax178Rgt2;
 double etaErrorLAPlusEMCmax178Rgt2;
 double etaErrorLLPlusEMCmax178Rgt2;
 double etaErrorHEATPlusEMCmax178Rgt2;

 if(etaEEMCmax178RFdgt2km!=0)
 		{
 		etaErrorCOPlusEMCmax178Rgt2 = (sqrt(EventsWithErecCOEMCmax178RFdgt2km ) / GeneratedEventsEMCmax178RFdgt2km ) * (exposureCoihuecoThetamin115EMCmax178Rgt2 /  etaEEMCmax178RFdgt2km) ;
 		etaErrorLMPlusEMCmax178Rgt2 = ( sqrt(EventsWithErecCOEMCmax178RFdgt2km ) / GeneratedEventsEMCmax178RFdgt2km ) * (exposureLMThetamin115EMCmax178Rgt2) /  etaEEMCmax178RFdgt2km;
 		etaErrorLAPlusEMCmax178Rgt2 = ( sqrt(EventsWithErecCOEMCmax178RFdgt2km ) / GeneratedEventsEMCmax178RFdgt2km ) * (exposureLAThetamin115EMCmax178Rgt2)/  etaEEMCmax178RFdgt2km ;
 		etaErrorLLPlusEMCmax178Rgt2 = (sqrt(EventsWithErecCOEMCmax178RFdgt2km ) / GeneratedEventsEMCmax178RFdgt2km ) *	(exposureLLEmin17Thetamin115EMCmax178Rgt2) /  etaEEMCmax178RFdgt2km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax178Rgt2 =0;
 		etaErrorLMPlusEMCmax178Rgt2 = 0;
 		etaErrorLAPlusEMCmax178Rgt2 = 0 ;
 		etaErrorLLPlusEMCmax178Rgt2 =0;
 		}

 	if( etaEHEATEMCmax178RFdgt2km!=0)
 	etaErrorHEATPlusEMCmax178Rgt2 = (sqrt(EventsWithErecHEATEMCmax178RFdgt2km ) / GeneratedEventsEMCmax178RFdgt2km ) * (exposureHEATThetamin115EMCmax178Rgt2)/  etaEHEATEMCmax178RFdgt2km ;
 	else
 	etaErrorHEATPlusEMCmax178Rgt2 =0;

 etaErrorExposureEMCmax178Rgt2 = sqrt(  etaErrorCOPlusEMCmax178Rgt2*etaErrorCOPlusEMCmax178Rgt2 + etaErrorLMPlusEMCmax178Rgt2*etaErrorLMPlusEMCmax178Rgt2 +
 		etaErrorLAPlusEMCmax178Rgt2*etaErrorLAPlusEMCmax178Rgt2 +  etaErrorLLPlusEMCmax178Rgt2* etaErrorLLPlusEMCmax178Rgt2
 		+etaErrorHEATPlusEMCmax178Rgt2*etaErrorHEATPlusEMCmax178Rgt2);

 ErrorExposureRgt2.push_back(  etaErrorExposureEMCmax178Rgt2  );

 double etaErrorExposureEMCmax178Rgt3;
 double etaErrorCOPlusEMCmax178Rgt3;
 double etaErrorLMPlusEMCmax178Rgt3;
 double etaErrorLAPlusEMCmax178Rgt3;
 double etaErrorLLPlusEMCmax178Rgt3;
 double etaErrorHEATPlusEMCmax178Rgt3;

 if(etaEEMCmax178RFdgt3km!=0)
 		{
 		etaErrorCOPlusEMCmax178Rgt3 = (sqrt(EventsWithErecCOEMCmax178RFdgt3km ) / GeneratedEventsEMCmax178RFdgt3km ) * (exposureCoihuecoThetamin115EMCmax178Rgt3 /  etaEEMCmax178RFdgt3km) ;
 		etaErrorLMPlusEMCmax178Rgt3 = ( sqrt(EventsWithErecCOEMCmax178RFdgt3km ) / GeneratedEventsEMCmax178RFdgt3km ) * (exposureLMThetamin115EMCmax178Rgt3) /  etaEEMCmax178RFdgt3km;
 		etaErrorLAPlusEMCmax178Rgt3 = ( sqrt(EventsWithErecCOEMCmax178RFdgt3km ) / GeneratedEventsEMCmax178RFdgt3km ) * (exposureLAThetamin115EMCmax178Rgt3)/  etaEEMCmax178RFdgt3km ;
 		etaErrorLLPlusEMCmax178Rgt3 = (sqrt(EventsWithErecCOEMCmax178RFdgt3km ) / GeneratedEventsEMCmax178RFdgt3km ) *	(exposureLLEmin17Thetamin115EMCmax178Rgt3) /  etaEEMCmax178RFdgt3km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax178Rgt3 =0;
 		etaErrorLMPlusEMCmax178Rgt3 = 0;
 		etaErrorLAPlusEMCmax178Rgt3 = 0 ;
 		etaErrorLLPlusEMCmax178Rgt3 =0;
 		}

 	if( etaEHEATEMCmax178RFdgt3km!=0)
 	etaErrorHEATPlusEMCmax178Rgt3 = (sqrt(EventsWithErecHEATEMCmax178RFdgt3km ) / GeneratedEventsEMCmax178RFdgt3km ) * (exposureHEATThetamin115EMCmax178Rgt3)/  etaEHEATEMCmax178RFdgt3km ;
 	else
 	etaErrorHEATPlusEMCmax178Rgt3 =0;

 etaErrorExposureEMCmax178Rgt3 = sqrt(  etaErrorCOPlusEMCmax178Rgt3*etaErrorCOPlusEMCmax178Rgt3 + etaErrorLMPlusEMCmax178Rgt3*etaErrorLMPlusEMCmax178Rgt3 +
 		etaErrorLAPlusEMCmax178Rgt3*etaErrorLAPlusEMCmax178Rgt3 +  etaErrorLLPlusEMCmax178Rgt3* etaErrorLLPlusEMCmax178Rgt3
 		+etaErrorHEATPlusEMCmax178Rgt3*etaErrorHEATPlusEMCmax178Rgt3);

 ErrorExposureRgt3.push_back(  etaErrorExposureEMCmax178Rgt3  );


 double etaErrorExposureEMCmax178Rgt4;
 double etaErrorCOPlusEMCmax178Rgt4;
 double etaErrorLMPlusEMCmax178Rgt4;
 double etaErrorLAPlusEMCmax178Rgt4;
 double etaErrorLLPlusEMCmax178Rgt4;
 double etaErrorHEATPlusEMCmax178Rgt4;

 if(etaEEMCmax178RFdgt4km!=0)
 		{
 		etaErrorCOPlusEMCmax178Rgt4 = (sqrt(EventsWithErecCOEMCmax178RFdgt4km ) / GeneratedEventsEMCmax178RFdgt4km ) * (exposureCoihuecoThetamin115EMCmax178Rgt4 /  etaEEMCmax178RFdgt4km) ;
 		etaErrorLMPlusEMCmax178Rgt4 = ( sqrt(EventsWithErecCOEMCmax178RFdgt4km ) / GeneratedEventsEMCmax178RFdgt4km ) * (exposureLMThetamin115EMCmax178Rgt4) /  etaEEMCmax178RFdgt4km;
 		etaErrorLAPlusEMCmax178Rgt4 = ( sqrt(EventsWithErecCOEMCmax178RFdgt4km ) / GeneratedEventsEMCmax178RFdgt4km ) * (exposureLAThetamin115EMCmax178Rgt4)/  etaEEMCmax178RFdgt4km ;
 		etaErrorLLPlusEMCmax178Rgt4 = (sqrt(EventsWithErecCOEMCmax178RFdgt4km ) / GeneratedEventsEMCmax178RFdgt4km ) *	(exposureLLEmin17Thetamin115EMCmax178Rgt4) /  etaEEMCmax178RFdgt4km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax178Rgt4 =0;
 		etaErrorLMPlusEMCmax178Rgt4 = 0;
 		etaErrorLAPlusEMCmax178Rgt4 = 0 ;
 		etaErrorLLPlusEMCmax178Rgt4 =0;
 		}

 	if( etaEHEATEMCmax178RFdgt4km!=0)
 	etaErrorHEATPlusEMCmax178Rgt4 = (sqrt(EventsWithErecHEATEMCmax178RFdgt4km ) / GeneratedEventsEMCmax178RFdgt4km ) * (exposureHEATThetamin115EMCmax178Rgt4)/  etaEHEATEMCmax178RFdgt4km ;
 	else
 	etaErrorHEATPlusEMCmax178Rgt4 =0;

 etaErrorExposureEMCmax178Rgt4 = sqrt(  etaErrorCOPlusEMCmax178Rgt4*etaErrorCOPlusEMCmax178Rgt4 + etaErrorLMPlusEMCmax178Rgt4*etaErrorLMPlusEMCmax178Rgt4 +
 		etaErrorLAPlusEMCmax178Rgt4*etaErrorLAPlusEMCmax178Rgt4 +  etaErrorLLPlusEMCmax178Rgt4* etaErrorLLPlusEMCmax178Rgt4
 		+etaErrorHEATPlusEMCmax178Rgt4*etaErrorHEATPlusEMCmax178Rgt4);

 ErrorExposureRgt4.push_back(  etaErrorExposureEMCmax178Rgt4  );


 double etaErrorExposureEMCmax178Rgt5;
 double etaErrorCOPlusEMCmax178Rgt5;
 double etaErrorLMPlusEMCmax178Rgt5;
 double etaErrorLAPlusEMCmax178Rgt5;
 double etaErrorLLPlusEMCmax178Rgt5;
 double etaErrorHEATPlusEMCmax178Rgt5;

 if(etaEEMCmax178RFdgt5km!=0)
 		{
 		etaErrorCOPlusEMCmax178Rgt5 = (sqrt(EventsWithErecCOEMCmax178RFdgt5km ) / GeneratedEventsEMCmax178RFdgt5km ) * (exposureCoihuecoThetamin115EMCmax178Rgt5 /  etaEEMCmax178RFdgt5km) ;
 		etaErrorLMPlusEMCmax178Rgt5 = ( sqrt(EventsWithErecCOEMCmax178RFdgt5km ) / GeneratedEventsEMCmax178RFdgt5km ) * (exposureLMThetamin115EMCmax178Rgt5) /  etaEEMCmax178RFdgt5km;
 		etaErrorLAPlusEMCmax178Rgt5 = ( sqrt(EventsWithErecCOEMCmax178RFdgt5km ) / GeneratedEventsEMCmax178RFdgt5km ) * (exposureLAThetamin115EMCmax178Rgt5)/  etaEEMCmax178RFdgt5km ;
 		etaErrorLLPlusEMCmax178Rgt5 = (sqrt(EventsWithErecCOEMCmax178RFdgt5km ) / GeneratedEventsEMCmax178RFdgt5km ) *	(exposureLLEmin17Thetamin115EMCmax178Rgt5) /  etaEEMCmax178RFdgt5km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax178Rgt5 =0;
 		etaErrorLMPlusEMCmax178Rgt5 = 0;
 		etaErrorLAPlusEMCmax178Rgt5 = 0 ;
 		etaErrorLLPlusEMCmax178Rgt5 =0;
 		}

 	if( etaEHEATEMCmax178RFdgt5km!=0)
 	etaErrorHEATPlusEMCmax178Rgt5 = (sqrt(EventsWithErecHEATEMCmax178RFdgt5km ) / GeneratedEventsEMCmax178RFdgt5km ) * (exposureHEATThetamin115EMCmax178Rgt5)/  etaEHEATEMCmax178RFdgt5km ;
 	else
 	etaErrorHEATPlusEMCmax178Rgt5 =0;

 etaErrorExposureEMCmax178Rgt5 = sqrt(  etaErrorCOPlusEMCmax178Rgt5*etaErrorCOPlusEMCmax178Rgt5 + etaErrorLMPlusEMCmax178Rgt5*etaErrorLMPlusEMCmax178Rgt5 +
 		etaErrorLAPlusEMCmax178Rgt5*etaErrorLAPlusEMCmax178Rgt5 +  etaErrorLLPlusEMCmax178Rgt5* etaErrorLLPlusEMCmax178Rgt5
 		+etaErrorHEATPlusEMCmax178Rgt5*etaErrorHEATPlusEMCmax178Rgt5);

 ErrorExposureRgt5.push_back(  etaErrorExposureEMCmax178Rgt5  );



double etaEEMCmax179; //etaE=recEvents/GenEvents ->reconstruction efficiency
etaEEMCmax179 = EventsWithErecCOEMCmax179 / GeneratedEventsEMCmax179;

double etaEHEATEMCmax179;
etaEHEATEMCmax179 = EventsWithErecHEATEMCmax179 / GeneratedEventsEMCmax179;
cout<<"etaE (E = 17.8: "<<etaEEMCmax179<<endl;
ErrorEvents.push_back(sqrt(EventsWithErecCOEMCmax179 ));

double etaEEMCmax179RFdgt1km;
etaEEMCmax179RFdgt1km = EventsWithErecCOEMCmax179RFdgt1km / GeneratedEventsEMCmax179RFdgt1km;
double etaEEMCmax179RFdgt2km;
etaEEMCmax179RFdgt2km = EventsWithErecCOEMCmax179RFdgt2km / GeneratedEventsEMCmax179RFdgt2km;
double etaEEMCmax179RFdgt3km;
etaEEMCmax179RFdgt3km = EventsWithErecCOEMCmax179RFdgt3km / GeneratedEventsEMCmax179RFdgt3km;
double etaEEMCmax179RFdgt4km;
etaEEMCmax179RFdgt4km = EventsWithErecCOEMCmax179RFdgt4km / GeneratedEventsEMCmax179RFdgt4km;
double etaEEMCmax179RFdgt5km;
etaEEMCmax179RFdgt5km = EventsWithErecCOEMCmax179RFdgt5km / GeneratedEventsEMCmax179RFdgt5km;

double etaEHEATEMCmax179RFdgt1km;
etaEHEATEMCmax179RFdgt1km = EventsWithErecHEATEMCmax179RFdgt1km / GeneratedEventsEMCmax179RFdgt1km;
double etaEHEATEMCmax179RFdgt2km;
etaEHEATEMCmax179RFdgt2km = EventsWithErecHEATEMCmax179RFdgt2km / GeneratedEventsEMCmax179RFdgt2km;
double etaEHEATEMCmax179RFdgt3km;
etaEHEATEMCmax179RFdgt3km = EventsWithErecHEATEMCmax179RFdgt3km / GeneratedEventsEMCmax179RFdgt3km;
double etaEHEATEMCmax179RFdgt4km;
etaEHEATEMCmax179RFdgt4km = EventsWithErecHEATEMCmax179RFdgt4km / GeneratedEventsEMCmax179RFdgt4km;
double etaEHEATEMCmax179RFdgt5km;
etaEHEATEMCmax179RFdgt5km = EventsWithErecHEATEMCmax179RFdgt5km / GeneratedEventsEMCmax179RFdgt5km;

cout<<"total gen events: "<<TotalNrGenEvents<<" in (17.8, 17.9) nr of gen Events = "<<GeneratedEventsEMCmax179<<endl;


cout<<"nr or reconstructed ev: "<<EventsWithErecCOEMCmax179<<endl;



double apertureCoihuecoThetamin115EMCmax179 = etaEEMCmax179 * genAreaCO *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureCoihuecoThetamin115EMCmax179 = apertureCoihuecoThetamin115EMCmax179 * yearsCO;

double apertureLMThetamin115EMCmax179 = etaEEMCmax179 * genAreaLM *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLMThetamin115EMCmax179 = apertureLMThetamin115EMCmax179 * yearsLM;

  double apertureLAThetamin115EMCmax179 = etaEEMCmax179 * genAreaLA *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLAThetamin115EMCmax179 = apertureLAThetamin115EMCmax179 * yearsLA;

    double apertureLL180FOVThetamin115EMCmax179 = etaEEMCmax179 * genAreaLL180FOV *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLL180FOVThetamin115EMCmax179 = apertureLL180FOVThetamin115EMCmax179 * yearsLL180FOV;

  double apertureLL162FOVThetamin115EMCmax179 = etaEEMCmax179 * genAreaLL162FOV *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLL162FOVThetamin115EMCmax179 = apertureLL162FOVThetamin115EMCmax179 * yearsLL162FOV;

  double exposureLLEmin17Thetamin115EMCmax179 = exposureLL180FOVThetamin115EMCmax179 + exposureLL162FOVThetamin115EMCmax179;

  double apertureHEATThetamin115EMCmax179 = etaEHEATEMCmax179 * genAreaHEAT *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureHEATThetamin115EMCmax179 = apertureHEATThetamin115EMCmax179 * yearsHEAT;


  double Exposure4EyesThetamin115EMCmax179 = exposureCoihuecoThetamin115EMCmax179 + exposureLMThetamin115EMCmax179 +
                                            exposureLAThetamin115EMCmax179 + exposureLLEmin17Thetamin115EMCmax179 +	exposureHEATThetamin115EMCmax179;

  Exposure4EyesAllEnergiesThetamin115H0.push_back(Exposure4EyesThetamin115EMCmax179);


  double exposureCoihuecoThetamin115EMCmax179Rgt1 = etaEEMCmax179RFdgt1km * genAreaCORgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;
  double exposureCoihuecoThetamin115EMCmax179Rgt2 = etaEEMCmax179RFdgt2km * genAreaCORgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;
  double exposureCoihuecoThetamin115EMCmax179Rgt3 = etaEEMCmax179RFdgt3km * genAreaCORgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;

  double exposureLMThetamin115EMCmax179Rgt1 = etaEEMCmax179RFdgt1km * genAreaLMRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;
  double exposureLMThetamin115EMCmax179Rgt2 = etaEEMCmax179RFdgt2km * genAreaLMRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;
  double exposureLMThetamin115EMCmax179Rgt3 = etaEEMCmax179RFdgt3km * genAreaLMRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;

  double exposureLAThetamin115EMCmax179Rgt1 = etaEEMCmax179RFdgt1km * genAreaLARgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;
  double exposureLAThetamin115EMCmax179Rgt2 = etaEEMCmax179RFdgt2km * genAreaLARgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;
  double exposureLAThetamin115EMCmax179Rgt3 = etaEEMCmax179RFdgt3km * genAreaLARgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;

  double exposureLL180FOVThetamin115EMCmax179Rgt1 = etaEEMCmax179RFdgt1km * genAreaLL180FOVRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;
  double exposureLL180FOVThetamin115EMCmax179Rgt2 = etaEEMCmax179RFdgt2km * genAreaLL180FOVRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;
  double exposureLL180FOVThetamin115EMCmax179Rgt3 = etaEEMCmax179RFdgt3km * genAreaLL180FOVRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;

  double exposureLL162FOVThetamin115EMCmax179Rgt1 = etaEEMCmax179RFdgt1km * genAreaLL162FOVRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;
  double exposureLL162FOVThetamin115EMCmax179Rgt2 = etaEEMCmax179RFdgt2km * genAreaLL162FOVRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;
  double exposureLL162FOVThetamin115EMCmax179Rgt3 = etaEEMCmax179RFdgt3km * genAreaLL162FOVRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;

  double exposureLLEmin17Thetamin115EMCmax179Rgt1 =  exposureLL180FOVThetamin115EMCmax179Rgt1 + exposureLL162FOVThetamin115EMCmax179Rgt1;
  double exposureLLEmin17Thetamin115EMCmax179Rgt2 =  exposureLL180FOVThetamin115EMCmax179Rgt2 + exposureLL162FOVThetamin115EMCmax179Rgt2;
  double exposureLLEmin17Thetamin115EMCmax179Rgt3 =  exposureLL180FOVThetamin115EMCmax179Rgt3 + exposureLL162FOVThetamin115EMCmax179Rgt3;



  double exposureCoihuecoThetamin115EMCmax179Rgt4 = etaEEMCmax179RFdgt4km * genAreaCORgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;
  double exposureCoihuecoThetamin115EMCmax179Rgt5 = etaEEMCmax179RFdgt5km * genAreaCORgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;

  double exposureLMThetamin115EMCmax179Rgt4 = etaEEMCmax179RFdgt4km * genAreaLMRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;
  double exposureLMThetamin115EMCmax179Rgt5 = etaEEMCmax179RFdgt5km * genAreaLMRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;

  double exposureLAThetamin115EMCmax179Rgt4 = etaEEMCmax179RFdgt4km * genAreaLARgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;
  double exposureLAThetamin115EMCmax179Rgt5 = etaEEMCmax179RFdgt5km * genAreaLARgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;

  double exposureLL180FOVThetamin115EMCmax179Rgt4 = etaEEMCmax179RFdgt4km * genAreaLL180FOVRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;
  double exposureLL180FOVThetamin115EMCmax179Rgt5 = etaEEMCmax179RFdgt5km * genAreaLL180FOVRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;

  double exposureLL162FOVThetamin115EMCmax179Rgt4 = etaEEMCmax179RFdgt4km * genAreaLL162FOVRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;
  double exposureLL162FOVThetamin115EMCmax179Rgt5 = etaEEMCmax179RFdgt5km * genAreaLL162FOVRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;

  double exposureLLEmin17Thetamin115EMCmax179Rgt4 =  exposureLL180FOVThetamin115EMCmax179Rgt4 + exposureLL162FOVThetamin115EMCmax179Rgt4;
  double exposureLLEmin17Thetamin115EMCmax179Rgt5 =  exposureLL180FOVThetamin115EMCmax179Rgt5 + exposureLL162FOVThetamin115EMCmax179Rgt5;


  double exposureHEATThetamin115EMCmax179Rgt1 = etaEHEATEMCmax179RFdgt1km* genAreaHEATRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCmax179Rgt2 = etaEHEATEMCmax179RFdgt2km* genAreaHEATRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCmax179Rgt3 = etaEHEATEMCmax179RFdgt3km* genAreaHEATRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCmax179Rgt4 = etaEHEATEMCmax179RFdgt4km* genAreaHEATRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCmax179Rgt5 = etaEHEATEMCmax179RFdgt5km* genAreaHEATRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;


  Exposure4EyesAllEnergiesThetamin115H0Rgt4.push_back( exposureCoihuecoThetamin115EMCmax179Rgt4 +   exposureLMThetamin115EMCmax179Rgt4
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax179Rgt4 + exposureLLEmin17Thetamin115EMCmax179Rgt4
																													+ exposureHEATThetamin115EMCmax179Rgt4 );
  Exposure4EyesAllEnergiesThetamin115H0Rgt5.push_back( exposureCoihuecoThetamin115EMCmax179Rgt5 +   exposureLMThetamin115EMCmax179Rgt5
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax179Rgt5 + exposureLLEmin17Thetamin115EMCmax179Rgt5
																													+ exposureHEATThetamin115EMCmax179Rgt5);

  Exposure4EyesAllEnergiesThetamin115H0Rgt1.push_back( exposureCoihuecoThetamin115EMCmax179Rgt1 +   exposureLMThetamin115EMCmax179Rgt1
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax179Rgt1 + exposureLLEmin17Thetamin115EMCmax179Rgt1
																													+ exposureHEATThetamin115EMCmax179Rgt1);
  Exposure4EyesAllEnergiesThetamin115H0Rgt2.push_back( exposureCoihuecoThetamin115EMCmax179Rgt2 +   exposureLMThetamin115EMCmax179Rgt2
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax179Rgt2 + exposureLLEmin17Thetamin115EMCmax179Rgt2
																													+  exposureHEATThetamin115EMCmax179Rgt2);
  Exposure4EyesAllEnergiesThetamin115H0Rgt3.push_back( exposureCoihuecoThetamin115EMCmax179Rgt3 +   exposureLMThetamin115EMCmax179Rgt3
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax179Rgt3 + exposureLLEmin17Thetamin115EMCmax179Rgt3
																													+  exposureHEATThetamin115EMCmax179Rgt3);

 EnergyRangeVector.push_back(17.8);

 double etaErrorExposurePlusEMCmax179 ;
 double etaErrorCOPlusEMCmax179;
 double etaErrorLMPlusEMCmax179;
 double etaErrorLAPlusEMCmax179;
 double etaErrorLLPlusEMCmax179;
 double etaErrorHEATPlusEMCmax179;

 if( etaEEMCmax179!=0)
 		{
 		etaErrorCOPlusEMCmax179 = (sqrt(EventsWithErecCOEMCmax179 ) / GeneratedEventsEMCmax179 ) * (exposureCoihuecoThetamin115EMCmax179 /  etaEEMCmax179) ;
 		etaErrorLMPlusEMCmax179 = ( sqrt(EventsWithErecCOEMCmax179 ) / GeneratedEventsEMCmax179 ) * (exposureLMThetamin115EMCmax179) /  etaEEMCmax179;
 		etaErrorLAPlusEMCmax179 = ( sqrt(EventsWithErecCOEMCmax179 ) / GeneratedEventsEMCmax179 ) * (exposureLAThetamin115EMCmax179)/  etaEEMCmax179 ;
 		etaErrorLLPlusEMCmax179 = (sqrt(EventsWithErecCOEMCmax179 ) / GeneratedEventsEMCmax179 ) *	(exposureLLEmin17Thetamin115EMCmax179) /  etaEEMCmax179;
 		}
 else
 		{
 			etaErrorCOPlusEMCmax179 = 0 ;
 			etaErrorLMPlusEMCmax179 = 0;
 			etaErrorLAPlusEMCmax179 =0 ;
 			etaErrorLLPlusEMCmax179 =0;
 		}
 	if(etaEHEATEMCmax179!=0)
 		etaErrorHEATPlusEMCmax179 = (sqrt(EventsWithErecHEATEMCmax179 ) / GeneratedEventsEMCmax179 ) * (exposureHEATThetamin115EMCmax179)/  etaEHEATEMCmax179 ;
 	else
 		etaErrorHEATPlusEMCmax179 = 0;


 etaErrorExposurePlusEMCmax179 = sqrt(  etaErrorCOPlusEMCmax179*etaErrorCOPlusEMCmax179 + etaErrorLMPlusEMCmax179*etaErrorLMPlusEMCmax179 +
 																etaErrorLAPlusEMCmax179*etaErrorLAPlusEMCmax179 +  etaErrorLLPlusEMCmax179* etaErrorLLPlusEMCmax179
 																+etaErrorHEATPlusEMCmax179*etaErrorHEATPlusEMCmax179);

 cout<<" E=17  "<<"Error Total Exposure  "<<etaErrorExposurePlusEMCmax179 <<endl;

 cout<<"exposure CO: "<<exposureCoihuecoThetamin115EMCmax179 << " error: "<<etaErrorCOPlusEMCmax179<<endl;
 cout<<"exposure LA: "<<exposureLAThetamin115EMCmax179 << " error: "<<etaErrorLAPlusEMCmax179<<endl;
 cout<<"exposure LM: "<<exposureLMThetamin115EMCmax179 << " error: "<<etaErrorLMPlusEMCmax179<<endl;
 cout<<"exposure LL: "<<exposureLLEmin17Thetamin115EMCmax179 << " error: "<<etaErrorLLPlusEMCmax179<<endl;
 cout<<"exposure HEAT: "<<exposureHEATThetamin115EMCmax179 << " error: "<<etaErrorHEATPlusEMCmax179<<endl;


 ErrorExposurePlus.push_back(etaErrorExposurePlusEMCmax179);


 double etaErrorExposureEMCmax179Rgt1;
 double etaErrorCOPlusEMCmax179Rgt1;
 double etaErrorLMPlusEMCmax179Rgt1;
 double etaErrorLAPlusEMCmax179Rgt1;
 double etaErrorLLPlusEMCmax179Rgt1;
 double etaErrorHEATPlusEMCmax179Rgt1;

 if(etaEEMCmax179RFdgt1km!=0)
 		{
 		etaErrorCOPlusEMCmax179Rgt1 = (sqrt(EventsWithErecCOEMCmax179RFdgt1km ) / GeneratedEventsEMCmax179RFdgt1km ) * (exposureCoihuecoThetamin115EMCmax179Rgt1 /  etaEEMCmax179RFdgt1km) ;
 		etaErrorLMPlusEMCmax179Rgt1 = ( sqrt(EventsWithErecCOEMCmax179RFdgt1km ) / GeneratedEventsEMCmax179RFdgt1km ) * (exposureLMThetamin115EMCmax179Rgt1) /  etaEEMCmax179RFdgt1km;
 		etaErrorLAPlusEMCmax179Rgt1 = ( sqrt(EventsWithErecCOEMCmax179RFdgt1km ) / GeneratedEventsEMCmax179RFdgt1km ) * (exposureLAThetamin115EMCmax179Rgt1)/  etaEEMCmax179RFdgt1km ;
 		etaErrorLLPlusEMCmax179Rgt1 = (sqrt(EventsWithErecCOEMCmax179RFdgt1km ) / GeneratedEventsEMCmax179RFdgt1km ) *	(exposureLLEmin17Thetamin115EMCmax179Rgt1) /  etaEEMCmax179RFdgt1km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax179Rgt1 =0;
 		etaErrorLMPlusEMCmax179Rgt1 = 0;
 		etaErrorLAPlusEMCmax179Rgt1 = 0 ;
 		etaErrorLLPlusEMCmax179Rgt1 =0;
 		}

 	if( etaEHEATEMCmax179RFdgt1km!=0)
 	etaErrorHEATPlusEMCmax179Rgt1 = (sqrt(EventsWithErecHEATEMCmax179RFdgt1km ) / GeneratedEventsEMCmax179RFdgt1km ) * (exposureHEATThetamin115EMCmax179Rgt1)/  etaEHEATEMCmax179RFdgt1km ;
 	else
 	etaErrorHEATPlusEMCmax179Rgt1 =0;

 etaErrorExposureEMCmax179Rgt1 = sqrt(  etaErrorCOPlusEMCmax179Rgt1*etaErrorCOPlusEMCmax179Rgt1 + etaErrorLMPlusEMCmax179Rgt1*etaErrorLMPlusEMCmax179Rgt1 +
 		etaErrorLAPlusEMCmax179Rgt1*etaErrorLAPlusEMCmax179Rgt1 +  etaErrorLLPlusEMCmax179Rgt1* etaErrorLLPlusEMCmax179Rgt1
 		+etaErrorHEATPlusEMCmax179Rgt1*etaErrorHEATPlusEMCmax179Rgt1);

 ErrorExposureRgt1.push_back(  etaErrorExposureEMCmax179Rgt1  );


 double etaErrorExposureEMCmax179Rgt2;
 double etaErrorCOPlusEMCmax179Rgt2;
 double etaErrorLMPlusEMCmax179Rgt2;
 double etaErrorLAPlusEMCmax179Rgt2;
 double etaErrorLLPlusEMCmax179Rgt2;
 double etaErrorHEATPlusEMCmax179Rgt2;

 if(etaEEMCmax179RFdgt2km!=0)
 		{
 		etaErrorCOPlusEMCmax179Rgt2 = (sqrt(EventsWithErecCOEMCmax179RFdgt2km ) / GeneratedEventsEMCmax179RFdgt2km ) * (exposureCoihuecoThetamin115EMCmax179Rgt2 /  etaEEMCmax179RFdgt2km) ;
 		etaErrorLMPlusEMCmax179Rgt2 = ( sqrt(EventsWithErecCOEMCmax179RFdgt2km ) / GeneratedEventsEMCmax179RFdgt2km ) * (exposureLMThetamin115EMCmax179Rgt2) /  etaEEMCmax179RFdgt2km;
 		etaErrorLAPlusEMCmax179Rgt2 = ( sqrt(EventsWithErecCOEMCmax179RFdgt2km ) / GeneratedEventsEMCmax179RFdgt2km ) * (exposureLAThetamin115EMCmax179Rgt2)/  etaEEMCmax179RFdgt2km ;
 		etaErrorLLPlusEMCmax179Rgt2 = (sqrt(EventsWithErecCOEMCmax179RFdgt2km ) / GeneratedEventsEMCmax179RFdgt2km ) *	(exposureLLEmin17Thetamin115EMCmax179Rgt2) /  etaEEMCmax179RFdgt2km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax179Rgt2 =0;
 		etaErrorLMPlusEMCmax179Rgt2 = 0;
 		etaErrorLAPlusEMCmax179Rgt2 = 0 ;
 		etaErrorLLPlusEMCmax179Rgt2 =0;
 		}

 	if( etaEHEATEMCmax179RFdgt2km!=0)
 	etaErrorHEATPlusEMCmax179Rgt2 = (sqrt(EventsWithErecHEATEMCmax179RFdgt2km ) / GeneratedEventsEMCmax179RFdgt2km ) * (exposureHEATThetamin115EMCmax179Rgt2)/  etaEHEATEMCmax179RFdgt2km ;
 	else
 	etaErrorHEATPlusEMCmax179Rgt2 =0;

 etaErrorExposureEMCmax179Rgt2 = sqrt(  etaErrorCOPlusEMCmax179Rgt2*etaErrorCOPlusEMCmax179Rgt2 + etaErrorLMPlusEMCmax179Rgt2*etaErrorLMPlusEMCmax179Rgt2 +
 		etaErrorLAPlusEMCmax179Rgt2*etaErrorLAPlusEMCmax179Rgt2 +  etaErrorLLPlusEMCmax179Rgt2* etaErrorLLPlusEMCmax179Rgt2
 		+etaErrorHEATPlusEMCmax179Rgt2*etaErrorHEATPlusEMCmax179Rgt2);

 ErrorExposureRgt2.push_back(  etaErrorExposureEMCmax179Rgt2  );

 double etaErrorExposureEMCmax179Rgt3;
 double etaErrorCOPlusEMCmax179Rgt3;
 double etaErrorLMPlusEMCmax179Rgt3;
 double etaErrorLAPlusEMCmax179Rgt3;
 double etaErrorLLPlusEMCmax179Rgt3;
 double etaErrorHEATPlusEMCmax179Rgt3;

 if(etaEEMCmax179RFdgt3km!=0)
 		{
 		etaErrorCOPlusEMCmax179Rgt3 = (sqrt(EventsWithErecCOEMCmax179RFdgt3km ) / GeneratedEventsEMCmax179RFdgt3km ) * (exposureCoihuecoThetamin115EMCmax179Rgt3 /  etaEEMCmax179RFdgt3km) ;
 		etaErrorLMPlusEMCmax179Rgt3 = ( sqrt(EventsWithErecCOEMCmax179RFdgt3km ) / GeneratedEventsEMCmax179RFdgt3km ) * (exposureLMThetamin115EMCmax179Rgt3) /  etaEEMCmax179RFdgt3km;
 		etaErrorLAPlusEMCmax179Rgt3 = ( sqrt(EventsWithErecCOEMCmax179RFdgt3km ) / GeneratedEventsEMCmax179RFdgt3km ) * (exposureLAThetamin115EMCmax179Rgt3)/  etaEEMCmax179RFdgt3km ;
 		etaErrorLLPlusEMCmax179Rgt3 = (sqrt(EventsWithErecCOEMCmax179RFdgt3km ) / GeneratedEventsEMCmax179RFdgt3km ) *	(exposureLLEmin17Thetamin115EMCmax179Rgt3) /  etaEEMCmax179RFdgt3km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax179Rgt3 =0;
 		etaErrorLMPlusEMCmax179Rgt3 = 0;
 		etaErrorLAPlusEMCmax179Rgt3 = 0 ;
 		etaErrorLLPlusEMCmax179Rgt3 =0;
 		}

 	if( etaEHEATEMCmax179RFdgt3km!=0)
 	etaErrorHEATPlusEMCmax179Rgt3 = (sqrt(EventsWithErecHEATEMCmax179RFdgt3km ) / GeneratedEventsEMCmax179RFdgt3km ) * (exposureHEATThetamin115EMCmax179Rgt3)/  etaEHEATEMCmax179RFdgt3km ;
 	else
 	etaErrorHEATPlusEMCmax179Rgt3 =0;

 etaErrorExposureEMCmax179Rgt3 = sqrt(  etaErrorCOPlusEMCmax179Rgt3*etaErrorCOPlusEMCmax179Rgt3 + etaErrorLMPlusEMCmax179Rgt3*etaErrorLMPlusEMCmax179Rgt3 +
 		etaErrorLAPlusEMCmax179Rgt3*etaErrorLAPlusEMCmax179Rgt3 +  etaErrorLLPlusEMCmax179Rgt3* etaErrorLLPlusEMCmax179Rgt3
 		+etaErrorHEATPlusEMCmax179Rgt3*etaErrorHEATPlusEMCmax179Rgt3);

 ErrorExposureRgt3.push_back(  etaErrorExposureEMCmax179Rgt3  );


 double etaErrorExposureEMCmax179Rgt4;
 double etaErrorCOPlusEMCmax179Rgt4;
 double etaErrorLMPlusEMCmax179Rgt4;
 double etaErrorLAPlusEMCmax179Rgt4;
 double etaErrorLLPlusEMCmax179Rgt4;
 double etaErrorHEATPlusEMCmax179Rgt4;

 if(etaEEMCmax179RFdgt4km!=0)
 		{
 		etaErrorCOPlusEMCmax179Rgt4 = (sqrt(EventsWithErecCOEMCmax179RFdgt4km ) / GeneratedEventsEMCmax179RFdgt4km ) * (exposureCoihuecoThetamin115EMCmax179Rgt4 /  etaEEMCmax179RFdgt4km) ;
 		etaErrorLMPlusEMCmax179Rgt4 = ( sqrt(EventsWithErecCOEMCmax179RFdgt4km ) / GeneratedEventsEMCmax179RFdgt4km ) * (exposureLMThetamin115EMCmax179Rgt4) /  etaEEMCmax179RFdgt4km;
 		etaErrorLAPlusEMCmax179Rgt4 = ( sqrt(EventsWithErecCOEMCmax179RFdgt4km ) / GeneratedEventsEMCmax179RFdgt4km ) * (exposureLAThetamin115EMCmax179Rgt4)/  etaEEMCmax179RFdgt4km ;
 		etaErrorLLPlusEMCmax179Rgt4 = (sqrt(EventsWithErecCOEMCmax179RFdgt4km ) / GeneratedEventsEMCmax179RFdgt4km ) *	(exposureLLEmin17Thetamin115EMCmax179Rgt4) /  etaEEMCmax179RFdgt4km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax179Rgt4 =0;
 		etaErrorLMPlusEMCmax179Rgt4 = 0;
 		etaErrorLAPlusEMCmax179Rgt4 = 0 ;
 		etaErrorLLPlusEMCmax179Rgt4 =0;
 		}

 	if( etaEHEATEMCmax179RFdgt4km!=0)
 	etaErrorHEATPlusEMCmax179Rgt4 = (sqrt(EventsWithErecHEATEMCmax179RFdgt4km ) / GeneratedEventsEMCmax179RFdgt4km ) * (exposureHEATThetamin115EMCmax179Rgt4)/  etaEHEATEMCmax179RFdgt4km ;
 	else
 	etaErrorHEATPlusEMCmax179Rgt4 =0;

 etaErrorExposureEMCmax179Rgt4 = sqrt(  etaErrorCOPlusEMCmax179Rgt4*etaErrorCOPlusEMCmax179Rgt4 + etaErrorLMPlusEMCmax179Rgt4*etaErrorLMPlusEMCmax179Rgt4 +
 		etaErrorLAPlusEMCmax179Rgt4*etaErrorLAPlusEMCmax179Rgt4 +  etaErrorLLPlusEMCmax179Rgt4* etaErrorLLPlusEMCmax179Rgt4
 		+etaErrorHEATPlusEMCmax179Rgt4*etaErrorHEATPlusEMCmax179Rgt4);

 ErrorExposureRgt4.push_back(  etaErrorExposureEMCmax179Rgt4  );


 double etaErrorExposureEMCmax179Rgt5;
 double etaErrorCOPlusEMCmax179Rgt5;
 double etaErrorLMPlusEMCmax179Rgt5;
 double etaErrorLAPlusEMCmax179Rgt5;
 double etaErrorLLPlusEMCmax179Rgt5;
 double etaErrorHEATPlusEMCmax179Rgt5;

 if(etaEEMCmax179RFdgt5km!=0)
 		{
 		etaErrorCOPlusEMCmax179Rgt5 = (sqrt(EventsWithErecCOEMCmax179RFdgt5km ) / GeneratedEventsEMCmax179RFdgt5km ) * (exposureCoihuecoThetamin115EMCmax179Rgt5 /  etaEEMCmax179RFdgt5km) ;
 		etaErrorLMPlusEMCmax179Rgt5 = ( sqrt(EventsWithErecCOEMCmax179RFdgt5km ) / GeneratedEventsEMCmax179RFdgt5km ) * (exposureLMThetamin115EMCmax179Rgt5) /  etaEEMCmax179RFdgt5km;
 		etaErrorLAPlusEMCmax179Rgt5 = ( sqrt(EventsWithErecCOEMCmax179RFdgt5km ) / GeneratedEventsEMCmax179RFdgt5km ) * (exposureLAThetamin115EMCmax179Rgt5)/  etaEEMCmax179RFdgt5km ;
 		etaErrorLLPlusEMCmax179Rgt5 = (sqrt(EventsWithErecCOEMCmax179RFdgt5km ) / GeneratedEventsEMCmax179RFdgt5km ) *	(exposureLLEmin17Thetamin115EMCmax179Rgt5) /  etaEEMCmax179RFdgt5km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax179Rgt5 =0;
 		etaErrorLMPlusEMCmax179Rgt5 = 0;
 		etaErrorLAPlusEMCmax179Rgt5 = 0 ;
 		etaErrorLLPlusEMCmax179Rgt5 =0;
 		}

 	if( etaEHEATEMCmax179RFdgt5km!=0)
 	etaErrorHEATPlusEMCmax179Rgt5 = (sqrt(EventsWithErecHEATEMCmax179RFdgt5km ) / GeneratedEventsEMCmax179RFdgt5km ) * (exposureHEATThetamin115EMCmax179Rgt5)/  etaEHEATEMCmax179RFdgt5km ;
 	else
 	etaErrorHEATPlusEMCmax179Rgt5 =0;

 etaErrorExposureEMCmax179Rgt5 = sqrt(  etaErrorCOPlusEMCmax179Rgt5*etaErrorCOPlusEMCmax179Rgt5 + etaErrorLMPlusEMCmax179Rgt5*etaErrorLMPlusEMCmax179Rgt5 +
 		etaErrorLAPlusEMCmax179Rgt5*etaErrorLAPlusEMCmax179Rgt5 +  etaErrorLLPlusEMCmax179Rgt5* etaErrorLLPlusEMCmax179Rgt5
 		+etaErrorHEATPlusEMCmax179Rgt5*etaErrorHEATPlusEMCmax179Rgt5);

 ErrorExposureRgt5.push_back(  etaErrorExposureEMCmax179Rgt5  );


double etaEEMCmax18; //etaE=recEvents/GenEvents ->reconstruction efficiency
etaEEMCmax18 = EventsWithErecCOEMCmax18 / GeneratedEventsEMCmax18;

double etaEHEATEMCmax18;
etaEHEATEMCmax18 = EventsWithErecHEATEMCmax18 / GeneratedEventsEMCmax18;
cout<<"etaE (E = 17.9: "<<etaEEMCmax18<<endl;
ErrorEvents.push_back(sqrt(EventsWithErecCOEMCmax18 ));

double etaEEMCmax18RFdgt1km;
etaEEMCmax18RFdgt1km = EventsWithErecCOEMCmax18RFdgt1km / GeneratedEventsEMCmax18RFdgt1km;
double etaEEMCmax18RFdgt2km;
etaEEMCmax18RFdgt2km = EventsWithErecCOEMCmax18RFdgt2km / GeneratedEventsEMCmax18RFdgt2km;
double etaEEMCmax18RFdgt3km;
etaEEMCmax18RFdgt3km = EventsWithErecCOEMCmax18RFdgt3km / GeneratedEventsEMCmax18RFdgt3km;
double etaEEMCmax18RFdgt4km;
etaEEMCmax18RFdgt4km = EventsWithErecCOEMCmax18RFdgt4km / GeneratedEventsEMCmax18RFdgt4km;
double etaEEMCmax18RFdgt5km;
etaEEMCmax18RFdgt5km = EventsWithErecCOEMCmax18RFdgt5km / GeneratedEventsEMCmax18RFdgt5km;

double etaEHEATEMCmax18RFdgt1km;
etaEHEATEMCmax18RFdgt1km = EventsWithErecHEATEMCmax18RFdgt1km / GeneratedEventsEMCmax18RFdgt1km;
double etaEHEATEMCmax18RFdgt2km;
etaEHEATEMCmax18RFdgt2km = EventsWithErecHEATEMCmax18RFdgt2km / GeneratedEventsEMCmax18RFdgt2km;
double etaEHEATEMCmax18RFdgt3km;
etaEHEATEMCmax18RFdgt3km = EventsWithErecHEATEMCmax18RFdgt3km / GeneratedEventsEMCmax18RFdgt3km;
double etaEHEATEMCmax18RFdgt4km;
etaEHEATEMCmax18RFdgt4km = EventsWithErecHEATEMCmax18RFdgt4km / GeneratedEventsEMCmax18RFdgt4km;
double etaEHEATEMCmax18RFdgt5km;
etaEHEATEMCmax18RFdgt5km = EventsWithErecHEATEMCmax18RFdgt5km / GeneratedEventsEMCmax18RFdgt5km;

cout<<"total gen events: "<<TotalNrGenEvents<<" in (17.9, 18) nr of gen Events = "<<GeneratedEventsEMCmax18<<endl;


cout<<"nr or reconstructed ev: "<<EventsWithErecCOEMCmax18<<endl;



double apertureCoihuecoThetamin115EMCmax18 = etaEEMCmax18 * genAreaCO *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureCoihuecoThetamin115EMCmax18 = apertureCoihuecoThetamin115EMCmax18 * yearsCO;

double apertureLMThetamin115EMCmax18 = etaEEMCmax18 * genAreaLM *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLMThetamin115EMCmax18 = apertureLMThetamin115EMCmax18 * yearsLM;

  double apertureLAThetamin115EMCmax18 = etaEEMCmax18 * genAreaLA *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLAThetamin115EMCmax18 = apertureLAThetamin115EMCmax18 * yearsLA;

    double apertureLL180FOVThetamin115EMCmax18 = etaEEMCmax18 * genAreaLL180FOV *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLL180FOVThetamin115EMCmax18 = apertureLL180FOVThetamin115EMCmax18 * yearsLL180FOV;

  double apertureLL162FOVThetamin115EMCmax18 = etaEEMCmax18 * genAreaLL162FOV *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLL162FOVThetamin115EMCmax18 = apertureLL162FOVThetamin115EMCmax18 * yearsLL162FOV;

  double exposureLLEmin17Thetamin115EMCmax18 = exposureLL180FOVThetamin115EMCmax18 + exposureLL162FOVThetamin115EMCmax18;

  double apertureHEATThetamin115EMCmax18 = etaEHEATEMCmax18 * genAreaHEAT *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureHEATThetamin115EMCmax18 = apertureHEATThetamin115EMCmax18 * yearsHEAT;


  double Exposure4EyesThetamin115EMCmax18 = exposureCoihuecoThetamin115EMCmax18 + exposureLMThetamin115EMCmax18 +
                                            exposureLAThetamin115EMCmax18 + exposureLLEmin17Thetamin115EMCmax18 +	exposureHEATThetamin115EMCmax18;

  Exposure4EyesAllEnergiesThetamin115H0.push_back(Exposure4EyesThetamin115EMCmax18);


  double exposureCoihuecoThetamin115EMCmax18Rgt1 = etaEEMCmax18RFdgt1km * genAreaCORgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;
  double exposureCoihuecoThetamin115EMCmax18Rgt2 = etaEEMCmax18RFdgt2km * genAreaCORgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;
  double exposureCoihuecoThetamin115EMCmax18Rgt3 = etaEEMCmax18RFdgt3km * genAreaCORgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;

  double exposureLMThetamin115EMCmax18Rgt1 = etaEEMCmax18RFdgt1km * genAreaLMRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;
  double exposureLMThetamin115EMCmax18Rgt2 = etaEEMCmax18RFdgt2km * genAreaLMRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;
  double exposureLMThetamin115EMCmax18Rgt3 = etaEEMCmax18RFdgt3km * genAreaLMRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;

  double exposureLAThetamin115EMCmax18Rgt1 = etaEEMCmax18RFdgt1km * genAreaLARgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;
  double exposureLAThetamin115EMCmax18Rgt2 = etaEEMCmax18RFdgt2km * genAreaLARgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;
  double exposureLAThetamin115EMCmax18Rgt3 = etaEEMCmax18RFdgt3km * genAreaLARgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;

  double exposureLL180FOVThetamin115EMCmax18Rgt1 = etaEEMCmax18RFdgt1km * genAreaLL180FOVRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;
  double exposureLL180FOVThetamin115EMCmax18Rgt2 = etaEEMCmax18RFdgt2km * genAreaLL180FOVRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;
  double exposureLL180FOVThetamin115EMCmax18Rgt3 = etaEEMCmax18RFdgt3km * genAreaLL180FOVRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;

  double exposureLL162FOVThetamin115EMCmax18Rgt1 = etaEEMCmax18RFdgt1km * genAreaLL162FOVRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;
  double exposureLL162FOVThetamin115EMCmax18Rgt2 = etaEEMCmax18RFdgt2km * genAreaLL162FOVRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;
  double exposureLL162FOVThetamin115EMCmax18Rgt3 = etaEEMCmax18RFdgt3km * genAreaLL162FOVRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;

  double exposureLLEmin17Thetamin115EMCmax18Rgt1 =  exposureLL180FOVThetamin115EMCmax18Rgt1 + exposureLL162FOVThetamin115EMCmax18Rgt1;
  double exposureLLEmin17Thetamin115EMCmax18Rgt2 =  exposureLL180FOVThetamin115EMCmax18Rgt2 + exposureLL162FOVThetamin115EMCmax18Rgt2;
  double exposureLLEmin17Thetamin115EMCmax18Rgt3 =  exposureLL180FOVThetamin115EMCmax18Rgt3 + exposureLL162FOVThetamin115EMCmax18Rgt3;



  double exposureCoihuecoThetamin115EMCmax18Rgt4 = etaEEMCmax18RFdgt4km * genAreaCORgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;
  double exposureCoihuecoThetamin115EMCmax18Rgt5 = etaEEMCmax18RFdgt5km * genAreaCORgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;

  double exposureLMThetamin115EMCmax18Rgt4 = etaEEMCmax18RFdgt4km * genAreaLMRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;
  double exposureLMThetamin115EMCmax18Rgt5 = etaEEMCmax18RFdgt5km * genAreaLMRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;

  double exposureLAThetamin115EMCmax18Rgt4 = etaEEMCmax18RFdgt4km * genAreaLARgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;
  double exposureLAThetamin115EMCmax18Rgt5 = etaEEMCmax18RFdgt5km * genAreaLARgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;

  double exposureLL180FOVThetamin115EMCmax18Rgt4 = etaEEMCmax18RFdgt4km * genAreaLL180FOVRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;
  double exposureLL180FOVThetamin115EMCmax18Rgt5 = etaEEMCmax18RFdgt5km * genAreaLL180FOVRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;

  double exposureLL162FOVThetamin115EMCmax18Rgt4 = etaEEMCmax18RFdgt4km * genAreaLL162FOVRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;
  double exposureLL162FOVThetamin115EMCmax18Rgt5 = etaEEMCmax18RFdgt5km * genAreaLL162FOVRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;

  double exposureLLEmin17Thetamin115EMCmax18Rgt4 =  exposureLL180FOVThetamin115EMCmax18Rgt4 + exposureLL162FOVThetamin115EMCmax18Rgt4;
  double exposureLLEmin17Thetamin115EMCmax18Rgt5 =  exposureLL180FOVThetamin115EMCmax18Rgt5 + exposureLL162FOVThetamin115EMCmax18Rgt5;


  double exposureHEATThetamin115EMCmax18Rgt1 = etaEHEATEMCmax18RFdgt1km* genAreaHEATRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCmax18Rgt2 = etaEHEATEMCmax18RFdgt2km* genAreaHEATRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCmax18Rgt3 = etaEHEATEMCmax18RFdgt3km* genAreaHEATRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCmax18Rgt4 = etaEHEATEMCmax18RFdgt4km* genAreaHEATRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCmax18Rgt5 = etaEHEATEMCmax18RFdgt5km* genAreaHEATRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;


  Exposure4EyesAllEnergiesThetamin115H0Rgt4.push_back( exposureCoihuecoThetamin115EMCmax18Rgt4 +   exposureLMThetamin115EMCmax18Rgt4
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax18Rgt4 + exposureLLEmin17Thetamin115EMCmax18Rgt4
																													+ exposureHEATThetamin115EMCmax18Rgt4 );
  Exposure4EyesAllEnergiesThetamin115H0Rgt5.push_back( exposureCoihuecoThetamin115EMCmax18Rgt5 +   exposureLMThetamin115EMCmax18Rgt5
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax18Rgt5 + exposureLLEmin17Thetamin115EMCmax18Rgt5
																													+ exposureHEATThetamin115EMCmax18Rgt5);

  Exposure4EyesAllEnergiesThetamin115H0Rgt1.push_back( exposureCoihuecoThetamin115EMCmax18Rgt1 +   exposureLMThetamin115EMCmax18Rgt1
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax18Rgt1 + exposureLLEmin17Thetamin115EMCmax18Rgt1
																													+ exposureHEATThetamin115EMCmax18Rgt1);
  Exposure4EyesAllEnergiesThetamin115H0Rgt2.push_back( exposureCoihuecoThetamin115EMCmax18Rgt2 +   exposureLMThetamin115EMCmax18Rgt2
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax18Rgt2 + exposureLLEmin17Thetamin115EMCmax18Rgt2
																													+  exposureHEATThetamin115EMCmax18Rgt2);
  Exposure4EyesAllEnergiesThetamin115H0Rgt3.push_back( exposureCoihuecoThetamin115EMCmax18Rgt3 +   exposureLMThetamin115EMCmax18Rgt3
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax18Rgt3 + exposureLLEmin17Thetamin115EMCmax18Rgt3
																													+  exposureHEATThetamin115EMCmax18Rgt3);

 EnergyRangeVector.push_back(17.9);

 double etaErrorExposurePlusEMCmax18 ;
 double etaErrorCOPlusEMCmax18;
 double etaErrorLMPlusEMCmax18;
 double etaErrorLAPlusEMCmax18;
 double etaErrorLLPlusEMCmax18;
 double etaErrorHEATPlusEMCmax18;

 if( etaEEMCmax18!=0)
 		{
 		etaErrorCOPlusEMCmax18 = (sqrt(EventsWithErecCOEMCmax18 ) / GeneratedEventsEMCmax18 ) * (exposureCoihuecoThetamin115EMCmax18 /  etaEEMCmax18) ;
 		etaErrorLMPlusEMCmax18 = ( sqrt(EventsWithErecCOEMCmax18 ) / GeneratedEventsEMCmax18 ) * (exposureLMThetamin115EMCmax18) /  etaEEMCmax18;
 		etaErrorLAPlusEMCmax18 = ( sqrt(EventsWithErecCOEMCmax18 ) / GeneratedEventsEMCmax18 ) * (exposureLAThetamin115EMCmax18)/  etaEEMCmax18 ;
 		etaErrorLLPlusEMCmax18 = (sqrt(EventsWithErecCOEMCmax18 ) / GeneratedEventsEMCmax18 ) *	(exposureLLEmin17Thetamin115EMCmax18) /  etaEEMCmax18;
 		}
 else
 		{
 			etaErrorCOPlusEMCmax18 = 0 ;
 			etaErrorLMPlusEMCmax18 = 0;
 			etaErrorLAPlusEMCmax18 =0 ;
 			etaErrorLLPlusEMCmax18 =0;
 		}
 	if(etaEHEATEMCmax18!=0)
 		etaErrorHEATPlusEMCmax18 = (sqrt(EventsWithErecHEATEMCmax18 ) / GeneratedEventsEMCmax18 ) * (exposureHEATThetamin115EMCmax18)/  etaEHEATEMCmax18 ;
 	else
 		etaErrorHEATPlusEMCmax18 = 0;


 etaErrorExposurePlusEMCmax18 = sqrt(  etaErrorCOPlusEMCmax18*etaErrorCOPlusEMCmax18 + etaErrorLMPlusEMCmax18*etaErrorLMPlusEMCmax18 +
 																etaErrorLAPlusEMCmax18*etaErrorLAPlusEMCmax18 +  etaErrorLLPlusEMCmax18* etaErrorLLPlusEMCmax18
 																+etaErrorHEATPlusEMCmax18*etaErrorHEATPlusEMCmax18);

 cout<<" E=17  "<<"Error Total Exposure  "<<etaErrorExposurePlusEMCmax18 <<endl;

 cout<<"exposure CO: "<<exposureCoihuecoThetamin115EMCmax18 << " error: "<<etaErrorCOPlusEMCmax18<<endl;
 cout<<"exposure LA: "<<exposureLAThetamin115EMCmax18 << " error: "<<etaErrorLAPlusEMCmax18<<endl;
 cout<<"exposure LM: "<<exposureLMThetamin115EMCmax18 << " error: "<<etaErrorLMPlusEMCmax18<<endl;
 cout<<"exposure LL: "<<exposureLLEmin17Thetamin115EMCmax18 << " error: "<<etaErrorLLPlusEMCmax18<<endl;
 cout<<"exposure HEAT: "<<exposureHEATThetamin115EMCmax18 << " error: "<<etaErrorHEATPlusEMCmax18<<endl;


 ErrorExposurePlus.push_back(etaErrorExposurePlusEMCmax18);


 double etaErrorExposureEMCmax18Rgt1;
 double etaErrorCOPlusEMCmax18Rgt1;
 double etaErrorLMPlusEMCmax18Rgt1;
 double etaErrorLAPlusEMCmax18Rgt1;
 double etaErrorLLPlusEMCmax18Rgt1;
 double etaErrorHEATPlusEMCmax18Rgt1;

 if(etaEEMCmax18RFdgt1km!=0)
 		{
 		etaErrorCOPlusEMCmax18Rgt1 = (sqrt(EventsWithErecCOEMCmax18RFdgt1km ) / GeneratedEventsEMCmax18RFdgt1km ) * (exposureCoihuecoThetamin115EMCmax18Rgt1 /  etaEEMCmax18RFdgt1km) ;
 		etaErrorLMPlusEMCmax18Rgt1 = ( sqrt(EventsWithErecCOEMCmax18RFdgt1km ) / GeneratedEventsEMCmax18RFdgt1km ) * (exposureLMThetamin115EMCmax18Rgt1) /  etaEEMCmax18RFdgt1km;
 		etaErrorLAPlusEMCmax18Rgt1 = ( sqrt(EventsWithErecCOEMCmax18RFdgt1km ) / GeneratedEventsEMCmax18RFdgt1km ) * (exposureLAThetamin115EMCmax18Rgt1)/  etaEEMCmax18RFdgt1km ;
 		etaErrorLLPlusEMCmax18Rgt1 = (sqrt(EventsWithErecCOEMCmax18RFdgt1km ) / GeneratedEventsEMCmax18RFdgt1km ) *	(exposureLLEmin17Thetamin115EMCmax18Rgt1) /  etaEEMCmax18RFdgt1km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax18Rgt1 =0;
 		etaErrorLMPlusEMCmax18Rgt1 = 0;
 		etaErrorLAPlusEMCmax18Rgt1 = 0 ;
 		etaErrorLLPlusEMCmax18Rgt1 =0;
 		}

 	if( etaEHEATEMCmax18RFdgt1km!=0)
 	etaErrorHEATPlusEMCmax18Rgt1 = (sqrt(EventsWithErecHEATEMCmax18RFdgt1km ) / GeneratedEventsEMCmax18RFdgt1km ) * (exposureHEATThetamin115EMCmax18Rgt1)/  etaEHEATEMCmax18RFdgt1km ;
 	else
 	etaErrorHEATPlusEMCmax18Rgt1 =0;

 etaErrorExposureEMCmax18Rgt1 = sqrt(  etaErrorCOPlusEMCmax18Rgt1*etaErrorCOPlusEMCmax18Rgt1 + etaErrorLMPlusEMCmax18Rgt1*etaErrorLMPlusEMCmax18Rgt1 +
 		etaErrorLAPlusEMCmax18Rgt1*etaErrorLAPlusEMCmax18Rgt1 +  etaErrorLLPlusEMCmax18Rgt1* etaErrorLLPlusEMCmax18Rgt1
 		+etaErrorHEATPlusEMCmax18Rgt1*etaErrorHEATPlusEMCmax18Rgt1);

 ErrorExposureRgt1.push_back(  etaErrorExposureEMCmax18Rgt1  );


 double etaErrorExposureEMCmax18Rgt2;
 double etaErrorCOPlusEMCmax18Rgt2;
 double etaErrorLMPlusEMCmax18Rgt2;
 double etaErrorLAPlusEMCmax18Rgt2;
 double etaErrorLLPlusEMCmax18Rgt2;
 double etaErrorHEATPlusEMCmax18Rgt2;

 if(etaEEMCmax18RFdgt2km!=0)
 		{
 		etaErrorCOPlusEMCmax18Rgt2 = (sqrt(EventsWithErecCOEMCmax18RFdgt2km ) / GeneratedEventsEMCmax18RFdgt2km ) * (exposureCoihuecoThetamin115EMCmax18Rgt2 /  etaEEMCmax18RFdgt2km) ;
 		etaErrorLMPlusEMCmax18Rgt2 = ( sqrt(EventsWithErecCOEMCmax18RFdgt2km ) / GeneratedEventsEMCmax18RFdgt2km ) * (exposureLMThetamin115EMCmax18Rgt2) /  etaEEMCmax18RFdgt2km;
 		etaErrorLAPlusEMCmax18Rgt2 = ( sqrt(EventsWithErecCOEMCmax18RFdgt2km ) / GeneratedEventsEMCmax18RFdgt2km ) * (exposureLAThetamin115EMCmax18Rgt2)/  etaEEMCmax18RFdgt2km ;
 		etaErrorLLPlusEMCmax18Rgt2 = (sqrt(EventsWithErecCOEMCmax18RFdgt2km ) / GeneratedEventsEMCmax18RFdgt2km ) *	(exposureLLEmin17Thetamin115EMCmax18Rgt2) /  etaEEMCmax18RFdgt2km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax18Rgt2 =0;
 		etaErrorLMPlusEMCmax18Rgt2 = 0;
 		etaErrorLAPlusEMCmax18Rgt2 = 0 ;
 		etaErrorLLPlusEMCmax18Rgt2 =0;
 		}

 	if( etaEHEATEMCmax18RFdgt2km!=0)
 	etaErrorHEATPlusEMCmax18Rgt2 = (sqrt(EventsWithErecHEATEMCmax18RFdgt2km ) / GeneratedEventsEMCmax18RFdgt2km ) * (exposureHEATThetamin115EMCmax18Rgt2)/  etaEHEATEMCmax18RFdgt2km ;
 	else
 	etaErrorHEATPlusEMCmax18Rgt2 =0;

 etaErrorExposureEMCmax18Rgt2 = sqrt(  etaErrorCOPlusEMCmax18Rgt2*etaErrorCOPlusEMCmax18Rgt2 + etaErrorLMPlusEMCmax18Rgt2*etaErrorLMPlusEMCmax18Rgt2 +
 		etaErrorLAPlusEMCmax18Rgt2*etaErrorLAPlusEMCmax18Rgt2 +  etaErrorLLPlusEMCmax18Rgt2* etaErrorLLPlusEMCmax18Rgt2
 		+etaErrorHEATPlusEMCmax18Rgt2*etaErrorHEATPlusEMCmax18Rgt2);

 ErrorExposureRgt2.push_back(  etaErrorExposureEMCmax18Rgt2  );

 double etaErrorExposureEMCmax18Rgt3;
 double etaErrorCOPlusEMCmax18Rgt3;
 double etaErrorLMPlusEMCmax18Rgt3;
 double etaErrorLAPlusEMCmax18Rgt3;
 double etaErrorLLPlusEMCmax18Rgt3;
 double etaErrorHEATPlusEMCmax18Rgt3;

 if(etaEEMCmax18RFdgt3km!=0)
 		{
 		etaErrorCOPlusEMCmax18Rgt3 = (sqrt(EventsWithErecCOEMCmax18RFdgt3km ) / GeneratedEventsEMCmax18RFdgt3km ) * (exposureCoihuecoThetamin115EMCmax18Rgt3 /  etaEEMCmax18RFdgt3km) ;
 		etaErrorLMPlusEMCmax18Rgt3 = ( sqrt(EventsWithErecCOEMCmax18RFdgt3km ) / GeneratedEventsEMCmax18RFdgt3km ) * (exposureLMThetamin115EMCmax18Rgt3) /  etaEEMCmax18RFdgt3km;
 		etaErrorLAPlusEMCmax18Rgt3 = ( sqrt(EventsWithErecCOEMCmax18RFdgt3km ) / GeneratedEventsEMCmax18RFdgt3km ) * (exposureLAThetamin115EMCmax18Rgt3)/  etaEEMCmax18RFdgt3km ;
 		etaErrorLLPlusEMCmax18Rgt3 = (sqrt(EventsWithErecCOEMCmax18RFdgt3km ) / GeneratedEventsEMCmax18RFdgt3km ) *	(exposureLLEmin17Thetamin115EMCmax18Rgt3) /  etaEEMCmax18RFdgt3km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax18Rgt3 =0;
 		etaErrorLMPlusEMCmax18Rgt3 = 0;
 		etaErrorLAPlusEMCmax18Rgt3 = 0 ;
 		etaErrorLLPlusEMCmax18Rgt3 =0;
 		}

 	if( etaEHEATEMCmax18RFdgt3km!=0)
 	etaErrorHEATPlusEMCmax18Rgt3 = (sqrt(EventsWithErecHEATEMCmax18RFdgt3km ) / GeneratedEventsEMCmax18RFdgt3km ) * (exposureHEATThetamin115EMCmax18Rgt3)/  etaEHEATEMCmax18RFdgt3km ;
 	else
 	etaErrorHEATPlusEMCmax18Rgt3 =0;

 etaErrorExposureEMCmax18Rgt3 = sqrt(  etaErrorCOPlusEMCmax18Rgt3*etaErrorCOPlusEMCmax18Rgt3 + etaErrorLMPlusEMCmax18Rgt3*etaErrorLMPlusEMCmax18Rgt3 +
 		etaErrorLAPlusEMCmax18Rgt3*etaErrorLAPlusEMCmax18Rgt3 +  etaErrorLLPlusEMCmax18Rgt3* etaErrorLLPlusEMCmax18Rgt3
 		+etaErrorHEATPlusEMCmax18Rgt3*etaErrorHEATPlusEMCmax18Rgt3);

 ErrorExposureRgt3.push_back(  etaErrorExposureEMCmax18Rgt3  );


 double etaErrorExposureEMCmax18Rgt4;
 double etaErrorCOPlusEMCmax18Rgt4;
 double etaErrorLMPlusEMCmax18Rgt4;
 double etaErrorLAPlusEMCmax18Rgt4;
 double etaErrorLLPlusEMCmax18Rgt4;
 double etaErrorHEATPlusEMCmax18Rgt4;

 if(etaEEMCmax18RFdgt4km!=0)
 		{
 		etaErrorCOPlusEMCmax18Rgt4 = (sqrt(EventsWithErecCOEMCmax18RFdgt4km ) / GeneratedEventsEMCmax18RFdgt4km ) * (exposureCoihuecoThetamin115EMCmax18Rgt4 /  etaEEMCmax18RFdgt4km) ;
 		etaErrorLMPlusEMCmax18Rgt4 = ( sqrt(EventsWithErecCOEMCmax18RFdgt4km ) / GeneratedEventsEMCmax18RFdgt4km ) * (exposureLMThetamin115EMCmax18Rgt4) /  etaEEMCmax18RFdgt4km;
 		etaErrorLAPlusEMCmax18Rgt4 = ( sqrt(EventsWithErecCOEMCmax18RFdgt4km ) / GeneratedEventsEMCmax18RFdgt4km ) * (exposureLAThetamin115EMCmax18Rgt4)/  etaEEMCmax18RFdgt4km ;
 		etaErrorLLPlusEMCmax18Rgt4 = (sqrt(EventsWithErecCOEMCmax18RFdgt4km ) / GeneratedEventsEMCmax18RFdgt4km ) *	(exposureLLEmin17Thetamin115EMCmax18Rgt4) /  etaEEMCmax18RFdgt4km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax18Rgt4 =0;
 		etaErrorLMPlusEMCmax18Rgt4 = 0;
 		etaErrorLAPlusEMCmax18Rgt4 = 0 ;
 		etaErrorLLPlusEMCmax18Rgt4 =0;
 		}

 	if( etaEHEATEMCmax18RFdgt4km!=0)
 	etaErrorHEATPlusEMCmax18Rgt4 = (sqrt(EventsWithErecHEATEMCmax18RFdgt4km ) / GeneratedEventsEMCmax18RFdgt4km ) * (exposureHEATThetamin115EMCmax18Rgt4)/  etaEHEATEMCmax18RFdgt4km ;
 	else
 	etaErrorHEATPlusEMCmax18Rgt4 =0;

 etaErrorExposureEMCmax18Rgt4 = sqrt(  etaErrorCOPlusEMCmax18Rgt4*etaErrorCOPlusEMCmax18Rgt4 + etaErrorLMPlusEMCmax18Rgt4*etaErrorLMPlusEMCmax18Rgt4 +
 		etaErrorLAPlusEMCmax18Rgt4*etaErrorLAPlusEMCmax18Rgt4 +  etaErrorLLPlusEMCmax18Rgt4* etaErrorLLPlusEMCmax18Rgt4
 		+etaErrorHEATPlusEMCmax18Rgt4*etaErrorHEATPlusEMCmax18Rgt4);

 ErrorExposureRgt4.push_back(  etaErrorExposureEMCmax18Rgt4  );


 double etaErrorExposureEMCmax18Rgt5;
 double etaErrorCOPlusEMCmax18Rgt5;
 double etaErrorLMPlusEMCmax18Rgt5;
 double etaErrorLAPlusEMCmax18Rgt5;
 double etaErrorLLPlusEMCmax18Rgt5;
 double etaErrorHEATPlusEMCmax18Rgt5;

 if(etaEEMCmax18RFdgt5km!=0)
 		{
 		etaErrorCOPlusEMCmax18Rgt5 = (sqrt(EventsWithErecCOEMCmax18RFdgt5km ) / GeneratedEventsEMCmax18RFdgt5km ) * (exposureCoihuecoThetamin115EMCmax18Rgt5 /  etaEEMCmax18RFdgt5km) ;
 		etaErrorLMPlusEMCmax18Rgt5 = ( sqrt(EventsWithErecCOEMCmax18RFdgt5km ) / GeneratedEventsEMCmax18RFdgt5km ) * (exposureLMThetamin115EMCmax18Rgt5) /  etaEEMCmax18RFdgt5km;
 		etaErrorLAPlusEMCmax18Rgt5 = ( sqrt(EventsWithErecCOEMCmax18RFdgt5km ) / GeneratedEventsEMCmax18RFdgt5km ) * (exposureLAThetamin115EMCmax18Rgt5)/  etaEEMCmax18RFdgt5km ;
 		etaErrorLLPlusEMCmax18Rgt5 = (sqrt(EventsWithErecCOEMCmax18RFdgt5km ) / GeneratedEventsEMCmax18RFdgt5km ) *	(exposureLLEmin17Thetamin115EMCmax18Rgt5) /  etaEEMCmax18RFdgt5km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax18Rgt5 =0;
 		etaErrorLMPlusEMCmax18Rgt5 = 0;
 		etaErrorLAPlusEMCmax18Rgt5 = 0 ;
 		etaErrorLLPlusEMCmax18Rgt5 =0;
 		}

 	if( etaEHEATEMCmax18RFdgt5km!=0)
 	etaErrorHEATPlusEMCmax18Rgt5 = (sqrt(EventsWithErecHEATEMCmax18RFdgt5km ) / GeneratedEventsEMCmax18RFdgt5km ) * (exposureHEATThetamin115EMCmax18Rgt5)/  etaEHEATEMCmax18RFdgt5km ;
 	else
 	etaErrorHEATPlusEMCmax18Rgt5 =0;

 etaErrorExposureEMCmax18Rgt5 = sqrt(  etaErrorCOPlusEMCmax18Rgt5*etaErrorCOPlusEMCmax18Rgt5 + etaErrorLMPlusEMCmax18Rgt5*etaErrorLMPlusEMCmax18Rgt5 +
 		etaErrorLAPlusEMCmax18Rgt5*etaErrorLAPlusEMCmax18Rgt5 +  etaErrorLLPlusEMCmax18Rgt5* etaErrorLLPlusEMCmax18Rgt5
 		+etaErrorHEATPlusEMCmax18Rgt5*etaErrorHEATPlusEMCmax18Rgt5);

 ErrorExposureRgt5.push_back(  etaErrorExposureEMCmax18Rgt5  );

double etaEEMCmax181; //etaE=recEvents/GenEvents ->reconstruction efficiency
etaEEMCmax181 = EventsWithErecCOEMCmax181 / GeneratedEventsEMCmax181;

double etaEHEATEMCmax181;
etaEHEATEMCmax181 = EventsWithErecHEATEMCmax181 / GeneratedEventsEMCmax181;
cout<<"etaE (E=18: "<<etaEEMCmax181<<endl;
ErrorEvents.push_back(sqrt(EventsWithErecCOEMCmax181 ));

double etaEEMCmax181RFdgt1km;
etaEEMCmax181RFdgt1km = EventsWithErecCOEMCmax181RFdgt1km / GeneratedEventsEMCmax181RFdgt1km;
double etaEEMCmax181RFdgt2km;
etaEEMCmax181RFdgt2km = EventsWithErecCOEMCmax181RFdgt2km / GeneratedEventsEMCmax181RFdgt2km;
double etaEEMCmax181RFdgt3km;
etaEEMCmax181RFdgt3km = EventsWithErecCOEMCmax181RFdgt3km / GeneratedEventsEMCmax181RFdgt3km;
double etaEEMCmax181RFdgt4km;
etaEEMCmax181RFdgt4km = EventsWithErecCOEMCmax181RFdgt4km / GeneratedEventsEMCmax181RFdgt4km;
double etaEEMCmax181RFdgt5km;
etaEEMCmax181RFdgt5km = EventsWithErecCOEMCmax181RFdgt5km / GeneratedEventsEMCmax181RFdgt5km;

double etaEHEATEMCmax181RFdgt1km;
etaEHEATEMCmax181RFdgt1km = EventsWithErecHEATEMCmax181RFdgt1km / GeneratedEventsEMCmax181RFdgt1km;
double etaEHEATEMCmax181RFdgt2km;
etaEHEATEMCmax181RFdgt2km = EventsWithErecHEATEMCmax181RFdgt2km / GeneratedEventsEMCmax181RFdgt2km;
double etaEHEATEMCmax181RFdgt3km;
etaEHEATEMCmax181RFdgt3km = EventsWithErecHEATEMCmax181RFdgt3km / GeneratedEventsEMCmax181RFdgt3km;
double etaEHEATEMCmax181RFdgt4km;
etaEHEATEMCmax181RFdgt4km = EventsWithErecHEATEMCmax181RFdgt4km / GeneratedEventsEMCmax181RFdgt4km;
double etaEHEATEMCmax181RFdgt5km;
etaEHEATEMCmax181RFdgt5km = EventsWithErecHEATEMCmax181RFdgt5km / GeneratedEventsEMCmax181RFdgt5km;

cout<<"total gen events: "<<TotalNrGenEvents<<" in (18, 18.1) nr of gen Events = "<<GeneratedEventsEMCmax181<<endl;


cout<<"nr or reconstructed ev: "<<EventsWithErecCOEMCmax181<<endl;



double apertureCoihuecoThetamin115EMCmax181 = etaEEMCmax181 * genAreaCO *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureCoihuecoThetamin115EMCmax181 = apertureCoihuecoThetamin115EMCmax181 * yearsCO;

double apertureLMThetamin115EMCmax181 = etaEEMCmax181 * genAreaLM *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLMThetamin115EMCmax181 = apertureLMThetamin115EMCmax181 * yearsLM;

  double apertureLAThetamin115EMCmax181 = etaEEMCmax181 * genAreaLA *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLAThetamin115EMCmax181 = apertureLAThetamin115EMCmax181 * yearsLA;

    double apertureLL180FOVThetamin115EMCmax181 = etaEEMCmax181 * genAreaLL180FOV *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLL180FOVThetamin115EMCmax181 = apertureLL180FOVThetamin115EMCmax181 * yearsLL180FOV;

  double apertureLL162FOVThetamin115EMCmax181 = etaEEMCmax181 * genAreaLL162FOV *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLL162FOVThetamin115EMCmax181 = apertureLL162FOVThetamin115EMCmax181 * yearsLL162FOV;

  double exposureLLEmin17Thetamin115EMCmax181 = exposureLL180FOVThetamin115EMCmax181 + exposureLL162FOVThetamin115EMCmax181;

  double apertureHEATThetamin115EMCmax181 = etaEHEATEMCmax181 * genAreaHEAT *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureHEATThetamin115EMCmax181 = apertureHEATThetamin115EMCmax181 * yearsHEAT;


  double Exposure4EyesThetamin115EMCmax181 = exposureCoihuecoThetamin115EMCmax181 + exposureLMThetamin115EMCmax181 +
                                            exposureLAThetamin115EMCmax181 + exposureLLEmin17Thetamin115EMCmax181 +	exposureHEATThetamin115EMCmax181;

  Exposure4EyesAllEnergiesThetamin115H0.push_back(Exposure4EyesThetamin115EMCmax181);


  double exposureCoihuecoThetamin115EMCmax181Rgt1 = etaEEMCmax181RFdgt1km * genAreaCORgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;
  double exposureCoihuecoThetamin115EMCmax181Rgt2 = etaEEMCmax181RFdgt2km * genAreaCORgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;
  double exposureCoihuecoThetamin115EMCmax181Rgt3 = etaEEMCmax181RFdgt3km * genAreaCORgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;

  double exposureLMThetamin115EMCmax181Rgt1 = etaEEMCmax181RFdgt1km * genAreaLMRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;
  double exposureLMThetamin115EMCmax181Rgt2 = etaEEMCmax181RFdgt2km * genAreaLMRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;
  double exposureLMThetamin115EMCmax181Rgt3 = etaEEMCmax181RFdgt3km * genAreaLMRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;

  double exposureLAThetamin115EMCmax181Rgt1 = etaEEMCmax181RFdgt1km * genAreaLARgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;
  double exposureLAThetamin115EMCmax181Rgt2 = etaEEMCmax181RFdgt2km * genAreaLARgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;
  double exposureLAThetamin115EMCmax181Rgt3 = etaEEMCmax181RFdgt3km * genAreaLARgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;

  double exposureLL180FOVThetamin115EMCmax181Rgt1 = etaEEMCmax181RFdgt1km * genAreaLL180FOVRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;
  double exposureLL180FOVThetamin115EMCmax181Rgt2 = etaEEMCmax181RFdgt2km * genAreaLL180FOVRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;
  double exposureLL180FOVThetamin115EMCmax181Rgt3 = etaEEMCmax181RFdgt3km * genAreaLL180FOVRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;

  double exposureLL162FOVThetamin115EMCmax181Rgt1 = etaEEMCmax181RFdgt1km * genAreaLL162FOVRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;
  double exposureLL162FOVThetamin115EMCmax181Rgt2 = etaEEMCmax181RFdgt2km * genAreaLL162FOVRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;
  double exposureLL162FOVThetamin115EMCmax181Rgt3 = etaEEMCmax181RFdgt3km * genAreaLL162FOVRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;

  double exposureLLEmin17Thetamin115EMCmax181Rgt1 =  exposureLL180FOVThetamin115EMCmax181Rgt1 + exposureLL162FOVThetamin115EMCmax181Rgt1;
  double exposureLLEmin17Thetamin115EMCmax181Rgt2 =  exposureLL180FOVThetamin115EMCmax181Rgt2 + exposureLL162FOVThetamin115EMCmax181Rgt2;
  double exposureLLEmin17Thetamin115EMCmax181Rgt3 =  exposureLL180FOVThetamin115EMCmax181Rgt3 + exposureLL162FOVThetamin115EMCmax181Rgt3;



  double exposureCoihuecoThetamin115EMCmax181Rgt4 = etaEEMCmax181RFdgt4km * genAreaCORgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;
  double exposureCoihuecoThetamin115EMCmax181Rgt5 = etaEEMCmax181RFdgt5km * genAreaCORgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;

  double exposureLMThetamin115EMCmax181Rgt4 = etaEEMCmax181RFdgt4km * genAreaLMRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;
  double exposureLMThetamin115EMCmax181Rgt5 = etaEEMCmax181RFdgt5km * genAreaLMRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;

  double exposureLAThetamin115EMCmax181Rgt4 = etaEEMCmax181RFdgt4km * genAreaLARgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;
  double exposureLAThetamin115EMCmax181Rgt5 = etaEEMCmax181RFdgt5km * genAreaLARgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;

  double exposureLL180FOVThetamin115EMCmax181Rgt4 = etaEEMCmax181RFdgt4km * genAreaLL180FOVRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;
  double exposureLL180FOVThetamin115EMCmax181Rgt5 = etaEEMCmax181RFdgt5km * genAreaLL180FOVRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;

  double exposureLL162FOVThetamin115EMCmax181Rgt4 = etaEEMCmax181RFdgt4km * genAreaLL162FOVRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;
  double exposureLL162FOVThetamin115EMCmax181Rgt5 = etaEEMCmax181RFdgt5km * genAreaLL162FOVRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;

  double exposureLLEmin17Thetamin115EMCmax181Rgt4 =  exposureLL180FOVThetamin115EMCmax181Rgt4 + exposureLL162FOVThetamin115EMCmax181Rgt4;
  double exposureLLEmin17Thetamin115EMCmax181Rgt5 =  exposureLL180FOVThetamin115EMCmax181Rgt5 + exposureLL162FOVThetamin115EMCmax181Rgt5;


  double exposureHEATThetamin115EMCmax181Rgt1 = etaEHEATEMCmax181RFdgt1km* genAreaHEATRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCmax181Rgt2 = etaEHEATEMCmax181RFdgt2km* genAreaHEATRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCmax181Rgt3 = etaEHEATEMCmax181RFdgt3km* genAreaHEATRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCmax181Rgt4 = etaEHEATEMCmax181RFdgt4km* genAreaHEATRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCmax181Rgt5 = etaEHEATEMCmax181RFdgt5km* genAreaHEATRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;


  Exposure4EyesAllEnergiesThetamin115H0Rgt4.push_back( exposureCoihuecoThetamin115EMCmax181Rgt4 +   exposureLMThetamin115EMCmax181Rgt4
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax181Rgt4 + exposureLLEmin17Thetamin115EMCmax181Rgt4
																													+ exposureHEATThetamin115EMCmax181Rgt4 );
  Exposure4EyesAllEnergiesThetamin115H0Rgt5.push_back( exposureCoihuecoThetamin115EMCmax181Rgt5 +   exposureLMThetamin115EMCmax181Rgt5
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax181Rgt5 + exposureLLEmin17Thetamin115EMCmax181Rgt5
																													+ exposureHEATThetamin115EMCmax181Rgt5);

  Exposure4EyesAllEnergiesThetamin115H0Rgt1.push_back( exposureCoihuecoThetamin115EMCmax181Rgt1 +   exposureLMThetamin115EMCmax181Rgt1
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax181Rgt1 + exposureLLEmin17Thetamin115EMCmax181Rgt1
																													+ exposureHEATThetamin115EMCmax181Rgt1);
  Exposure4EyesAllEnergiesThetamin115H0Rgt2.push_back( exposureCoihuecoThetamin115EMCmax181Rgt2 +   exposureLMThetamin115EMCmax181Rgt2
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax181Rgt2 + exposureLLEmin17Thetamin115EMCmax181Rgt2
																													+  exposureHEATThetamin115EMCmax181Rgt2);
  Exposure4EyesAllEnergiesThetamin115H0Rgt3.push_back( exposureCoihuecoThetamin115EMCmax181Rgt3 +   exposureLMThetamin115EMCmax181Rgt3
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax181Rgt3 + exposureLLEmin17Thetamin115EMCmax181Rgt3
																													+  exposureHEATThetamin115EMCmax181Rgt3);

 EnergyRangeVector.push_back(18);

 double etaErrorExposurePlusEMCmax181 ;
 double etaErrorCOPlusEMCmax181;
 double etaErrorLMPlusEMCmax181;
 double etaErrorLAPlusEMCmax181;
 double etaErrorLLPlusEMCmax181;
 double etaErrorHEATPlusEMCmax181;

 if( etaEEMCmax181!=0)
 		{
 		etaErrorCOPlusEMCmax181 = (sqrt(EventsWithErecCOEMCmax181 ) / GeneratedEventsEMCmax181 ) * (exposureCoihuecoThetamin115EMCmax181 /  etaEEMCmax181) ;
 		etaErrorLMPlusEMCmax181 = ( sqrt(EventsWithErecCOEMCmax181 ) / GeneratedEventsEMCmax181 ) * (exposureLMThetamin115EMCmax181) /  etaEEMCmax181;
 		etaErrorLAPlusEMCmax181 = ( sqrt(EventsWithErecCOEMCmax181 ) / GeneratedEventsEMCmax181 ) * (exposureLAThetamin115EMCmax181)/  etaEEMCmax181 ;
 		etaErrorLLPlusEMCmax181 = (sqrt(EventsWithErecCOEMCmax181 ) / GeneratedEventsEMCmax181 ) *	(exposureLLEmin17Thetamin115EMCmax181) /  etaEEMCmax181;
 		}
 else
 		{
 			etaErrorCOPlusEMCmax181 = 0 ;
 			etaErrorLMPlusEMCmax181 = 0;
 			etaErrorLAPlusEMCmax181 =0 ;
 			etaErrorLLPlusEMCmax181 =0;
 		}
 	if(etaEHEATEMCmax181!=0)
 		etaErrorHEATPlusEMCmax181 = (sqrt(EventsWithErecHEATEMCmax181 ) / GeneratedEventsEMCmax181 ) * (exposureHEATThetamin115EMCmax181)/  etaEHEATEMCmax181 ;
 	else
 		etaErrorHEATPlusEMCmax181 = 0;


 etaErrorExposurePlusEMCmax181 = sqrt(  etaErrorCOPlusEMCmax181*etaErrorCOPlusEMCmax181 + etaErrorLMPlusEMCmax181*etaErrorLMPlusEMCmax181 +
 																etaErrorLAPlusEMCmax181*etaErrorLAPlusEMCmax181 +  etaErrorLLPlusEMCmax181* etaErrorLLPlusEMCmax181
 																+etaErrorHEATPlusEMCmax181*etaErrorHEATPlusEMCmax181);

 cout<<" E=17  "<<"Error Total Exposure  "<<etaErrorExposurePlusEMCmax181 <<endl;

 cout<<"exposure CO: "<<exposureCoihuecoThetamin115EMCmax181 << " error: "<<etaErrorCOPlusEMCmax181<<endl;
 cout<<"exposure LA: "<<exposureLAThetamin115EMCmax181 << " error: "<<etaErrorLAPlusEMCmax181<<endl;
 cout<<"exposure LM: "<<exposureLMThetamin115EMCmax181 << " error: "<<etaErrorLMPlusEMCmax181<<endl;
 cout<<"exposure LL: "<<exposureLLEmin17Thetamin115EMCmax181 << " error: "<<etaErrorLLPlusEMCmax181<<endl;
 cout<<"exposure HEAT: "<<exposureHEATThetamin115EMCmax181 << " error: "<<etaErrorHEATPlusEMCmax181<<endl;


 ErrorExposurePlus.push_back(etaErrorExposurePlusEMCmax181);


 double etaErrorExposureEMCmax181Rgt1;
 double etaErrorCOPlusEMCmax181Rgt1;
 double etaErrorLMPlusEMCmax181Rgt1;
 double etaErrorLAPlusEMCmax181Rgt1;
 double etaErrorLLPlusEMCmax181Rgt1;
 double etaErrorHEATPlusEMCmax181Rgt1;

 if(etaEEMCmax181RFdgt1km!=0)
 		{
 		etaErrorCOPlusEMCmax181Rgt1 = (sqrt(EventsWithErecCOEMCmax181RFdgt1km ) / GeneratedEventsEMCmax181RFdgt1km ) * (exposureCoihuecoThetamin115EMCmax181Rgt1 /  etaEEMCmax181RFdgt1km) ;
 		etaErrorLMPlusEMCmax181Rgt1 = ( sqrt(EventsWithErecCOEMCmax181RFdgt1km ) / GeneratedEventsEMCmax181RFdgt1km ) * (exposureLMThetamin115EMCmax181Rgt1) /  etaEEMCmax181RFdgt1km;
 		etaErrorLAPlusEMCmax181Rgt1 = ( sqrt(EventsWithErecCOEMCmax181RFdgt1km ) / GeneratedEventsEMCmax181RFdgt1km ) * (exposureLAThetamin115EMCmax181Rgt1)/  etaEEMCmax181RFdgt1km ;
 		etaErrorLLPlusEMCmax181Rgt1 = (sqrt(EventsWithErecCOEMCmax181RFdgt1km ) / GeneratedEventsEMCmax181RFdgt1km ) *	(exposureLLEmin17Thetamin115EMCmax181Rgt1) /  etaEEMCmax181RFdgt1km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax181Rgt1 =0;
 		etaErrorLMPlusEMCmax181Rgt1 = 0;
 		etaErrorLAPlusEMCmax181Rgt1 = 0 ;
 		etaErrorLLPlusEMCmax181Rgt1 =0;
 		}

 	if( etaEHEATEMCmax181RFdgt1km!=0)
 	etaErrorHEATPlusEMCmax181Rgt1 = (sqrt(EventsWithErecHEATEMCmax181RFdgt1km ) / GeneratedEventsEMCmax181RFdgt1km ) * (exposureHEATThetamin115EMCmax181Rgt1)/  etaEHEATEMCmax181RFdgt1km ;
 	else
 	etaErrorHEATPlusEMCmax181Rgt1 =0;

 etaErrorExposureEMCmax181Rgt1 = sqrt(  etaErrorCOPlusEMCmax181Rgt1*etaErrorCOPlusEMCmax181Rgt1 + etaErrorLMPlusEMCmax181Rgt1*etaErrorLMPlusEMCmax181Rgt1 +
 		etaErrorLAPlusEMCmax181Rgt1*etaErrorLAPlusEMCmax181Rgt1 +  etaErrorLLPlusEMCmax181Rgt1* etaErrorLLPlusEMCmax181Rgt1
 		+etaErrorHEATPlusEMCmax181Rgt1*etaErrorHEATPlusEMCmax181Rgt1);

 ErrorExposureRgt1.push_back(  etaErrorExposureEMCmax181Rgt1  );


 double etaErrorExposureEMCmax181Rgt2;
 double etaErrorCOPlusEMCmax181Rgt2;
 double etaErrorLMPlusEMCmax181Rgt2;
 double etaErrorLAPlusEMCmax181Rgt2;
 double etaErrorLLPlusEMCmax181Rgt2;
 double etaErrorHEATPlusEMCmax181Rgt2;

 if(etaEEMCmax181RFdgt2km!=0)
 		{
 		etaErrorCOPlusEMCmax181Rgt2 = (sqrt(EventsWithErecCOEMCmax181RFdgt2km ) / GeneratedEventsEMCmax181RFdgt2km ) * (exposureCoihuecoThetamin115EMCmax181Rgt2 /  etaEEMCmax181RFdgt2km) ;
 		etaErrorLMPlusEMCmax181Rgt2 = ( sqrt(EventsWithErecCOEMCmax181RFdgt2km ) / GeneratedEventsEMCmax181RFdgt2km ) * (exposureLMThetamin115EMCmax181Rgt2) /  etaEEMCmax181RFdgt2km;
 		etaErrorLAPlusEMCmax181Rgt2 = ( sqrt(EventsWithErecCOEMCmax181RFdgt2km ) / GeneratedEventsEMCmax181RFdgt2km ) * (exposureLAThetamin115EMCmax181Rgt2)/  etaEEMCmax181RFdgt2km ;
 		etaErrorLLPlusEMCmax181Rgt2 = (sqrt(EventsWithErecCOEMCmax181RFdgt2km ) / GeneratedEventsEMCmax181RFdgt2km ) *	(exposureLLEmin17Thetamin115EMCmax181Rgt2) /  etaEEMCmax181RFdgt2km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax181Rgt2 =0;
 		etaErrorLMPlusEMCmax181Rgt2 = 0;
 		etaErrorLAPlusEMCmax181Rgt2 = 0 ;
 		etaErrorLLPlusEMCmax181Rgt2 =0;
 		}

 	if( etaEHEATEMCmax181RFdgt2km!=0)
 	etaErrorHEATPlusEMCmax181Rgt2 = (sqrt(EventsWithErecHEATEMCmax181RFdgt2km ) / GeneratedEventsEMCmax181RFdgt2km ) * (exposureHEATThetamin115EMCmax181Rgt2)/  etaEHEATEMCmax181RFdgt2km ;
 	else
 	etaErrorHEATPlusEMCmax181Rgt2 =0;

 etaErrorExposureEMCmax181Rgt2 = sqrt(  etaErrorCOPlusEMCmax181Rgt2*etaErrorCOPlusEMCmax181Rgt2 + etaErrorLMPlusEMCmax181Rgt2*etaErrorLMPlusEMCmax181Rgt2 +
 		etaErrorLAPlusEMCmax181Rgt2*etaErrorLAPlusEMCmax181Rgt2 +  etaErrorLLPlusEMCmax181Rgt2* etaErrorLLPlusEMCmax181Rgt2
 		+etaErrorHEATPlusEMCmax181Rgt2*etaErrorHEATPlusEMCmax181Rgt2);

 ErrorExposureRgt2.push_back(  etaErrorExposureEMCmax181Rgt2  );

 double etaErrorExposureEMCmax181Rgt3;
 double etaErrorCOPlusEMCmax181Rgt3;
 double etaErrorLMPlusEMCmax181Rgt3;
 double etaErrorLAPlusEMCmax181Rgt3;
 double etaErrorLLPlusEMCmax181Rgt3;
 double etaErrorHEATPlusEMCmax181Rgt3;

 if(etaEEMCmax181RFdgt3km!=0)
 		{
 		etaErrorCOPlusEMCmax181Rgt3 = (sqrt(EventsWithErecCOEMCmax181RFdgt3km ) / GeneratedEventsEMCmax181RFdgt3km ) * (exposureCoihuecoThetamin115EMCmax181Rgt3 /  etaEEMCmax181RFdgt3km) ;
 		etaErrorLMPlusEMCmax181Rgt3 = ( sqrt(EventsWithErecCOEMCmax181RFdgt3km ) / GeneratedEventsEMCmax181RFdgt3km ) * (exposureLMThetamin115EMCmax181Rgt3) /  etaEEMCmax181RFdgt3km;
 		etaErrorLAPlusEMCmax181Rgt3 = ( sqrt(EventsWithErecCOEMCmax181RFdgt3km ) / GeneratedEventsEMCmax181RFdgt3km ) * (exposureLAThetamin115EMCmax181Rgt3)/  etaEEMCmax181RFdgt3km ;
 		etaErrorLLPlusEMCmax181Rgt3 = (sqrt(EventsWithErecCOEMCmax181RFdgt3km ) / GeneratedEventsEMCmax181RFdgt3km ) *	(exposureLLEmin17Thetamin115EMCmax181Rgt3) /  etaEEMCmax181RFdgt3km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax181Rgt3 =0;
 		etaErrorLMPlusEMCmax181Rgt3 = 0;
 		etaErrorLAPlusEMCmax181Rgt3 = 0 ;
 		etaErrorLLPlusEMCmax181Rgt3 =0;
 		}

 	if( etaEHEATEMCmax181RFdgt3km!=0)
 	etaErrorHEATPlusEMCmax181Rgt3 = (sqrt(EventsWithErecHEATEMCmax181RFdgt3km ) / GeneratedEventsEMCmax181RFdgt3km ) * (exposureHEATThetamin115EMCmax181Rgt3)/  etaEHEATEMCmax181RFdgt3km ;
 	else
 	etaErrorHEATPlusEMCmax181Rgt3 =0;

 etaErrorExposureEMCmax181Rgt3 = sqrt(  etaErrorCOPlusEMCmax181Rgt3*etaErrorCOPlusEMCmax181Rgt3 + etaErrorLMPlusEMCmax181Rgt3*etaErrorLMPlusEMCmax181Rgt3 +
 		etaErrorLAPlusEMCmax181Rgt3*etaErrorLAPlusEMCmax181Rgt3 +  etaErrorLLPlusEMCmax181Rgt3* etaErrorLLPlusEMCmax181Rgt3
 		+etaErrorHEATPlusEMCmax181Rgt3*etaErrorHEATPlusEMCmax181Rgt3);

 ErrorExposureRgt3.push_back(  etaErrorExposureEMCmax181Rgt3  );


 double etaErrorExposureEMCmax181Rgt4;
 double etaErrorCOPlusEMCmax181Rgt4;
 double etaErrorLMPlusEMCmax181Rgt4;
 double etaErrorLAPlusEMCmax181Rgt4;
 double etaErrorLLPlusEMCmax181Rgt4;
 double etaErrorHEATPlusEMCmax181Rgt4;

 if(etaEEMCmax181RFdgt4km!=0)
 		{
 		etaErrorCOPlusEMCmax181Rgt4 = (sqrt(EventsWithErecCOEMCmax181RFdgt4km ) / GeneratedEventsEMCmax181RFdgt4km ) * (exposureCoihuecoThetamin115EMCmax181Rgt4 /  etaEEMCmax181RFdgt4km) ;
 		etaErrorLMPlusEMCmax181Rgt4 = ( sqrt(EventsWithErecCOEMCmax181RFdgt4km ) / GeneratedEventsEMCmax181RFdgt4km ) * (exposureLMThetamin115EMCmax181Rgt4) /  etaEEMCmax181RFdgt4km;
 		etaErrorLAPlusEMCmax181Rgt4 = ( sqrt(EventsWithErecCOEMCmax181RFdgt4km ) / GeneratedEventsEMCmax181RFdgt4km ) * (exposureLAThetamin115EMCmax181Rgt4)/  etaEEMCmax181RFdgt4km ;
 		etaErrorLLPlusEMCmax181Rgt4 = (sqrt(EventsWithErecCOEMCmax181RFdgt4km ) / GeneratedEventsEMCmax181RFdgt4km ) *	(exposureLLEmin17Thetamin115EMCmax181Rgt4) /  etaEEMCmax181RFdgt4km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax181Rgt4 =0;
 		etaErrorLMPlusEMCmax181Rgt4 = 0;
 		etaErrorLAPlusEMCmax181Rgt4 = 0 ;
 		etaErrorLLPlusEMCmax181Rgt4 =0;
 		}

 	if( etaEHEATEMCmax181RFdgt4km!=0)
 	etaErrorHEATPlusEMCmax181Rgt4 = (sqrt(EventsWithErecHEATEMCmax181RFdgt4km ) / GeneratedEventsEMCmax181RFdgt4km ) * (exposureHEATThetamin115EMCmax181Rgt4)/  etaEHEATEMCmax181RFdgt4km ;
 	else
 	etaErrorHEATPlusEMCmax181Rgt4 =0;

 etaErrorExposureEMCmax181Rgt4 = sqrt(  etaErrorCOPlusEMCmax181Rgt4*etaErrorCOPlusEMCmax181Rgt4 + etaErrorLMPlusEMCmax181Rgt4*etaErrorLMPlusEMCmax181Rgt4 +
 		etaErrorLAPlusEMCmax181Rgt4*etaErrorLAPlusEMCmax181Rgt4 +  etaErrorLLPlusEMCmax181Rgt4* etaErrorLLPlusEMCmax181Rgt4
 		+etaErrorHEATPlusEMCmax181Rgt4*etaErrorHEATPlusEMCmax181Rgt4);

 ErrorExposureRgt4.push_back(  etaErrorExposureEMCmax181Rgt4  );


 double etaErrorExposureEMCmax181Rgt5;
 double etaErrorCOPlusEMCmax181Rgt5;
 double etaErrorLMPlusEMCmax181Rgt5;
 double etaErrorLAPlusEMCmax181Rgt5;
 double etaErrorLLPlusEMCmax181Rgt5;
 double etaErrorHEATPlusEMCmax181Rgt5;

 if(etaEEMCmax181RFdgt5km!=0)
 		{
 		etaErrorCOPlusEMCmax181Rgt5 = (sqrt(EventsWithErecCOEMCmax181RFdgt5km ) / GeneratedEventsEMCmax181RFdgt5km ) * (exposureCoihuecoThetamin115EMCmax181Rgt5 /  etaEEMCmax181RFdgt5km) ;
 		etaErrorLMPlusEMCmax181Rgt5 = ( sqrt(EventsWithErecCOEMCmax181RFdgt5km ) / GeneratedEventsEMCmax181RFdgt5km ) * (exposureLMThetamin115EMCmax181Rgt5) /  etaEEMCmax181RFdgt5km;
 		etaErrorLAPlusEMCmax181Rgt5 = ( sqrt(EventsWithErecCOEMCmax181RFdgt5km ) / GeneratedEventsEMCmax181RFdgt5km ) * (exposureLAThetamin115EMCmax181Rgt5)/  etaEEMCmax181RFdgt5km ;
 		etaErrorLLPlusEMCmax181Rgt5 = (sqrt(EventsWithErecCOEMCmax181RFdgt5km ) / GeneratedEventsEMCmax181RFdgt5km ) *	(exposureLLEmin17Thetamin115EMCmax181Rgt5) /  etaEEMCmax181RFdgt5km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax181Rgt5 =0;
 		etaErrorLMPlusEMCmax181Rgt5 = 0;
 		etaErrorLAPlusEMCmax181Rgt5 = 0 ;
 		etaErrorLLPlusEMCmax181Rgt5 =0;
 		}

 	if( etaEHEATEMCmax181RFdgt5km!=0)
 	etaErrorHEATPlusEMCmax181Rgt5 = (sqrt(EventsWithErecHEATEMCmax181RFdgt5km ) / GeneratedEventsEMCmax181RFdgt5km ) * (exposureHEATThetamin115EMCmax181Rgt5)/  etaEHEATEMCmax181RFdgt5km ;
 	else
 	etaErrorHEATPlusEMCmax181Rgt5 =0;

 etaErrorExposureEMCmax181Rgt5 = sqrt(  etaErrorCOPlusEMCmax181Rgt5*etaErrorCOPlusEMCmax181Rgt5 + etaErrorLMPlusEMCmax181Rgt5*etaErrorLMPlusEMCmax181Rgt5 +
 		etaErrorLAPlusEMCmax181Rgt5*etaErrorLAPlusEMCmax181Rgt5 +  etaErrorLLPlusEMCmax181Rgt5* etaErrorLLPlusEMCmax181Rgt5
 		+etaErrorHEATPlusEMCmax181Rgt5*etaErrorHEATPlusEMCmax181Rgt5);

 ErrorExposureRgt5.push_back(  etaErrorExposureEMCmax181Rgt5  );



double etaEEMCmax182; //etaE=recEvents/GenEvents ->reconstruction efficiency
etaEEMCmax182 = EventsWithErecCOEMCmax182 / GeneratedEventsEMCmax182;

double etaEHEATEMCmax182;
etaEHEATEMCmax182 = EventsWithErecHEATEMCmax182 / GeneratedEventsEMCmax182;
cout<<"etaE (E=18.1: "<<etaEEMCmax182<<endl;
ErrorEvents.push_back(sqrt(EventsWithErecCOEMCmax182 ));

double etaEEMCmax182RFdgt1km;
etaEEMCmax182RFdgt1km = EventsWithErecCOEMCmax182RFdgt1km / GeneratedEventsEMCmax182RFdgt1km;
double etaEEMCmax182RFdgt2km;
etaEEMCmax182RFdgt2km = EventsWithErecCOEMCmax182RFdgt2km / GeneratedEventsEMCmax182RFdgt2km;
double etaEEMCmax182RFdgt3km;
etaEEMCmax182RFdgt3km = EventsWithErecCOEMCmax182RFdgt3km / GeneratedEventsEMCmax182RFdgt3km;
double etaEEMCmax182RFdgt4km;
etaEEMCmax182RFdgt4km = EventsWithErecCOEMCmax182RFdgt4km / GeneratedEventsEMCmax182RFdgt4km;
double etaEEMCmax182RFdgt5km;
etaEEMCmax182RFdgt5km = EventsWithErecCOEMCmax182RFdgt5km / GeneratedEventsEMCmax182RFdgt5km;

double etaEHEATEMCmax182RFdgt1km;
etaEHEATEMCmax182RFdgt1km = EventsWithErecHEATEMCmax182RFdgt1km / GeneratedEventsEMCmax182RFdgt1km;
double etaEHEATEMCmax182RFdgt2km;
etaEHEATEMCmax182RFdgt2km = EventsWithErecHEATEMCmax182RFdgt2km / GeneratedEventsEMCmax182RFdgt2km;
double etaEHEATEMCmax182RFdgt3km;
etaEHEATEMCmax182RFdgt3km = EventsWithErecHEATEMCmax182RFdgt3km / GeneratedEventsEMCmax182RFdgt3km;
double etaEHEATEMCmax182RFdgt4km;
etaEHEATEMCmax182RFdgt4km = EventsWithErecHEATEMCmax182RFdgt4km / GeneratedEventsEMCmax182RFdgt4km;
double etaEHEATEMCmax182RFdgt5km;
etaEHEATEMCmax182RFdgt5km = EventsWithErecHEATEMCmax182RFdgt5km / GeneratedEventsEMCmax182RFdgt5km;

cout<<"total gen events: "<<TotalNrGenEvents<<" in (18.1, 18.2) nr of gen Events = "<<GeneratedEventsEMCmax182<<endl;


cout<<"nr or reconstructed ev: "<<EventsWithErecCOEMCmax182<<endl;



double apertureCoihuecoThetamin115EMCmax182 = etaEEMCmax182 * genAreaCO *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureCoihuecoThetamin115EMCmax182 = apertureCoihuecoThetamin115EMCmax182 * yearsCO;

double apertureLMThetamin115EMCmax182 = etaEEMCmax182 * genAreaLM *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLMThetamin115EMCmax182 = apertureLMThetamin115EMCmax182 * yearsLM;

  double apertureLAThetamin115EMCmax182 = etaEEMCmax182 * genAreaLA *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLAThetamin115EMCmax182 = apertureLAThetamin115EMCmax182 * yearsLA;

    double apertureLL180FOVThetamin115EMCmax182 = etaEEMCmax182 * genAreaLL180FOV *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLL180FOVThetamin115EMCmax182 = apertureLL180FOVThetamin115EMCmax182 * yearsLL180FOV;

  double apertureLL162FOVThetamin115EMCmax182 = etaEEMCmax182 * genAreaLL162FOV *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLL162FOVThetamin115EMCmax182 = apertureLL162FOVThetamin115EMCmax182 * yearsLL162FOV;

  double exposureLLEmin17Thetamin115EMCmax182 = exposureLL180FOVThetamin115EMCmax182 + exposureLL162FOVThetamin115EMCmax182;

  double apertureHEATThetamin115EMCmax182 = etaEHEATEMCmax182 * genAreaHEAT *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureHEATThetamin115EMCmax182 = apertureHEATThetamin115EMCmax182 * yearsHEAT;


  double Exposure4EyesThetamin115EMCmax182 = exposureCoihuecoThetamin115EMCmax182 + exposureLMThetamin115EMCmax182 +
                                            exposureLAThetamin115EMCmax182 + exposureLLEmin17Thetamin115EMCmax182 +	exposureHEATThetamin115EMCmax182;

  Exposure4EyesAllEnergiesThetamin115H0.push_back(Exposure4EyesThetamin115EMCmax182);


  double exposureCoihuecoThetamin115EMCmax182Rgt1 = etaEEMCmax182RFdgt1km * genAreaCORgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;
  double exposureCoihuecoThetamin115EMCmax182Rgt2 = etaEEMCmax182RFdgt2km * genAreaCORgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;
  double exposureCoihuecoThetamin115EMCmax182Rgt3 = etaEEMCmax182RFdgt3km * genAreaCORgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;

  double exposureLMThetamin115EMCmax182Rgt1 = etaEEMCmax182RFdgt1km * genAreaLMRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;
  double exposureLMThetamin115EMCmax182Rgt2 = etaEEMCmax182RFdgt2km * genAreaLMRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;
  double exposureLMThetamin115EMCmax182Rgt3 = etaEEMCmax182RFdgt3km * genAreaLMRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;

  double exposureLAThetamin115EMCmax182Rgt1 = etaEEMCmax182RFdgt1km * genAreaLARgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;
  double exposureLAThetamin115EMCmax182Rgt2 = etaEEMCmax182RFdgt2km * genAreaLARgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;
  double exposureLAThetamin115EMCmax182Rgt3 = etaEEMCmax182RFdgt3km * genAreaLARgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;

  double exposureLL180FOVThetamin115EMCmax182Rgt1 = etaEEMCmax182RFdgt1km * genAreaLL180FOVRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;
  double exposureLL180FOVThetamin115EMCmax182Rgt2 = etaEEMCmax182RFdgt2km * genAreaLL180FOVRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;
  double exposureLL180FOVThetamin115EMCmax182Rgt3 = etaEEMCmax182RFdgt3km * genAreaLL180FOVRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;

  double exposureLL162FOVThetamin115EMCmax182Rgt1 = etaEEMCmax182RFdgt1km * genAreaLL162FOVRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;
  double exposureLL162FOVThetamin115EMCmax182Rgt2 = etaEEMCmax182RFdgt2km * genAreaLL162FOVRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;
  double exposureLL162FOVThetamin115EMCmax182Rgt3 = etaEEMCmax182RFdgt3km * genAreaLL162FOVRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;

  double exposureLLEmin17Thetamin115EMCmax182Rgt1 =  exposureLL180FOVThetamin115EMCmax182Rgt1 + exposureLL162FOVThetamin115EMCmax182Rgt1;
  double exposureLLEmin17Thetamin115EMCmax182Rgt2 =  exposureLL180FOVThetamin115EMCmax182Rgt2 + exposureLL162FOVThetamin115EMCmax182Rgt2;
  double exposureLLEmin17Thetamin115EMCmax182Rgt3 =  exposureLL180FOVThetamin115EMCmax182Rgt3 + exposureLL162FOVThetamin115EMCmax182Rgt3;



  double exposureCoihuecoThetamin115EMCmax182Rgt4 = etaEEMCmax182RFdgt4km * genAreaCORgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;
  double exposureCoihuecoThetamin115EMCmax182Rgt5 = etaEEMCmax182RFdgt5km * genAreaCORgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;

  double exposureLMThetamin115EMCmax182Rgt4 = etaEEMCmax182RFdgt4km * genAreaLMRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;
  double exposureLMThetamin115EMCmax182Rgt5 = etaEEMCmax182RFdgt5km * genAreaLMRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;

  double exposureLAThetamin115EMCmax182Rgt4 = etaEEMCmax182RFdgt4km * genAreaLARgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;
  double exposureLAThetamin115EMCmax182Rgt5 = etaEEMCmax182RFdgt5km * genAreaLARgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;

  double exposureLL180FOVThetamin115EMCmax182Rgt4 = etaEEMCmax182RFdgt4km * genAreaLL180FOVRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;
  double exposureLL180FOVThetamin115EMCmax182Rgt5 = etaEEMCmax182RFdgt5km * genAreaLL180FOVRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;

  double exposureLL162FOVThetamin115EMCmax182Rgt4 = etaEEMCmax182RFdgt4km * genAreaLL162FOVRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;
  double exposureLL162FOVThetamin115EMCmax182Rgt5 = etaEEMCmax182RFdgt5km * genAreaLL162FOVRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;

  double exposureLLEmin17Thetamin115EMCmax182Rgt4 =  exposureLL180FOVThetamin115EMCmax182Rgt4 + exposureLL162FOVThetamin115EMCmax182Rgt4;
  double exposureLLEmin17Thetamin115EMCmax182Rgt5 =  exposureLL180FOVThetamin115EMCmax182Rgt5 + exposureLL162FOVThetamin115EMCmax182Rgt5;


  double exposureHEATThetamin115EMCmax182Rgt1 = etaEHEATEMCmax182RFdgt1km* genAreaHEATRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCmax182Rgt2 = etaEHEATEMCmax182RFdgt2km* genAreaHEATRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCmax182Rgt3 = etaEHEATEMCmax182RFdgt3km* genAreaHEATRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCmax182Rgt4 = etaEHEATEMCmax182RFdgt4km* genAreaHEATRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCmax182Rgt5 = etaEHEATEMCmax182RFdgt5km* genAreaHEATRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;


  Exposure4EyesAllEnergiesThetamin115H0Rgt4.push_back( exposureCoihuecoThetamin115EMCmax182Rgt4 +   exposureLMThetamin115EMCmax182Rgt4
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax182Rgt4 + exposureLLEmin17Thetamin115EMCmax182Rgt4
																													+ exposureHEATThetamin115EMCmax182Rgt4 );
  Exposure4EyesAllEnergiesThetamin115H0Rgt5.push_back( exposureCoihuecoThetamin115EMCmax182Rgt5 +   exposureLMThetamin115EMCmax182Rgt5
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax182Rgt5 + exposureLLEmin17Thetamin115EMCmax182Rgt5
																													+ exposureHEATThetamin115EMCmax182Rgt5);

  Exposure4EyesAllEnergiesThetamin115H0Rgt1.push_back( exposureCoihuecoThetamin115EMCmax182Rgt1 +   exposureLMThetamin115EMCmax182Rgt1
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax182Rgt1 + exposureLLEmin17Thetamin115EMCmax182Rgt1
																													+ exposureHEATThetamin115EMCmax182Rgt1);
  Exposure4EyesAllEnergiesThetamin115H0Rgt2.push_back( exposureCoihuecoThetamin115EMCmax182Rgt2 +   exposureLMThetamin115EMCmax182Rgt2
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax182Rgt2 + exposureLLEmin17Thetamin115EMCmax182Rgt2
																													+  exposureHEATThetamin115EMCmax182Rgt2);
  Exposure4EyesAllEnergiesThetamin115H0Rgt3.push_back( exposureCoihuecoThetamin115EMCmax182Rgt3 +   exposureLMThetamin115EMCmax182Rgt3
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax182Rgt3 + exposureLLEmin17Thetamin115EMCmax182Rgt3
																													+  exposureHEATThetamin115EMCmax182Rgt3);

 EnergyRangeVector.push_back(18.1);

 double etaErrorExposurePlusEMCmax182 ;
 double etaErrorCOPlusEMCmax182;
 double etaErrorLMPlusEMCmax182;
 double etaErrorLAPlusEMCmax182;
 double etaErrorLLPlusEMCmax182;
 double etaErrorHEATPlusEMCmax182;

 if( etaEEMCmax182!=0)
 		{
 		etaErrorCOPlusEMCmax182 = (sqrt(EventsWithErecCOEMCmax182 ) / GeneratedEventsEMCmax182 ) * (exposureCoihuecoThetamin115EMCmax182 /  etaEEMCmax182) ;
 		etaErrorLMPlusEMCmax182 = ( sqrt(EventsWithErecCOEMCmax182 ) / GeneratedEventsEMCmax182 ) * (exposureLMThetamin115EMCmax182) /  etaEEMCmax182;
 		etaErrorLAPlusEMCmax182 = ( sqrt(EventsWithErecCOEMCmax182 ) / GeneratedEventsEMCmax182 ) * (exposureLAThetamin115EMCmax182)/  etaEEMCmax182 ;
 		etaErrorLLPlusEMCmax182 = (sqrt(EventsWithErecCOEMCmax182 ) / GeneratedEventsEMCmax182 ) *	(exposureLLEmin17Thetamin115EMCmax182) /  etaEEMCmax182;
 		}
 else
 		{
 			etaErrorCOPlusEMCmax182 = 0 ;
 			etaErrorLMPlusEMCmax182 = 0;
 			etaErrorLAPlusEMCmax182 =0 ;
 			etaErrorLLPlusEMCmax182 =0;
 		}
 	if(etaEHEATEMCmax182!=0)
 		etaErrorHEATPlusEMCmax182 = (sqrt(EventsWithErecHEATEMCmax182 ) / GeneratedEventsEMCmax182 ) * (exposureHEATThetamin115EMCmax182)/  etaEHEATEMCmax182 ;
 	else
 		etaErrorHEATPlusEMCmax182 = 0;


 etaErrorExposurePlusEMCmax182 = sqrt(  etaErrorCOPlusEMCmax182*etaErrorCOPlusEMCmax182 + etaErrorLMPlusEMCmax182*etaErrorLMPlusEMCmax182 +
 																etaErrorLAPlusEMCmax182*etaErrorLAPlusEMCmax182 +  etaErrorLLPlusEMCmax182* etaErrorLLPlusEMCmax182
 																+etaErrorHEATPlusEMCmax182*etaErrorHEATPlusEMCmax182);

 cout<<" E=17  "<<"Error Total Exposure  "<<etaErrorExposurePlusEMCmax182 <<endl;

 cout<<"exposure CO: "<<exposureCoihuecoThetamin115EMCmax182 << " error: "<<etaErrorCOPlusEMCmax182<<endl;
 cout<<"exposure LA: "<<exposureLAThetamin115EMCmax182 << " error: "<<etaErrorLAPlusEMCmax182<<endl;
 cout<<"exposure LM: "<<exposureLMThetamin115EMCmax182 << " error: "<<etaErrorLMPlusEMCmax182<<endl;
 cout<<"exposure LL: "<<exposureLLEmin17Thetamin115EMCmax182 << " error: "<<etaErrorLLPlusEMCmax182<<endl;
 cout<<"exposure HEAT: "<<exposureHEATThetamin115EMCmax182 << " error: "<<etaErrorHEATPlusEMCmax182<<endl;


 ErrorExposurePlus.push_back(etaErrorExposurePlusEMCmax182);


 double etaErrorExposureEMCmax182Rgt1;
 double etaErrorCOPlusEMCmax182Rgt1;
 double etaErrorLMPlusEMCmax182Rgt1;
 double etaErrorLAPlusEMCmax182Rgt1;
 double etaErrorLLPlusEMCmax182Rgt1;
 double etaErrorHEATPlusEMCmax182Rgt1;

 if(etaEEMCmax182RFdgt1km!=0)
 		{
 		etaErrorCOPlusEMCmax182Rgt1 = (sqrt(EventsWithErecCOEMCmax182RFdgt1km ) / GeneratedEventsEMCmax182RFdgt1km ) * (exposureCoihuecoThetamin115EMCmax182Rgt1 /  etaEEMCmax182RFdgt1km) ;
 		etaErrorLMPlusEMCmax182Rgt1 = ( sqrt(EventsWithErecCOEMCmax182RFdgt1km ) / GeneratedEventsEMCmax182RFdgt1km ) * (exposureLMThetamin115EMCmax182Rgt1) /  etaEEMCmax182RFdgt1km;
 		etaErrorLAPlusEMCmax182Rgt1 = ( sqrt(EventsWithErecCOEMCmax182RFdgt1km ) / GeneratedEventsEMCmax182RFdgt1km ) * (exposureLAThetamin115EMCmax182Rgt1)/  etaEEMCmax182RFdgt1km ;
 		etaErrorLLPlusEMCmax182Rgt1 = (sqrt(EventsWithErecCOEMCmax182RFdgt1km ) / GeneratedEventsEMCmax182RFdgt1km ) *	(exposureLLEmin17Thetamin115EMCmax182Rgt1) /  etaEEMCmax182RFdgt1km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax182Rgt1 =0;
 		etaErrorLMPlusEMCmax182Rgt1 = 0;
 		etaErrorLAPlusEMCmax182Rgt1 = 0 ;
 		etaErrorLLPlusEMCmax182Rgt1 =0;
 		}

 	if( etaEHEATEMCmax182RFdgt1km!=0)
 	etaErrorHEATPlusEMCmax182Rgt1 = (sqrt(EventsWithErecHEATEMCmax182RFdgt1km ) / GeneratedEventsEMCmax182RFdgt1km ) * (exposureHEATThetamin115EMCmax182Rgt1)/  etaEHEATEMCmax182RFdgt1km ;
 	else
 	etaErrorHEATPlusEMCmax182Rgt1 =0;

 etaErrorExposureEMCmax182Rgt1 = sqrt(  etaErrorCOPlusEMCmax182Rgt1*etaErrorCOPlusEMCmax182Rgt1 + etaErrorLMPlusEMCmax182Rgt1*etaErrorLMPlusEMCmax182Rgt1 +
 		etaErrorLAPlusEMCmax182Rgt1*etaErrorLAPlusEMCmax182Rgt1 +  etaErrorLLPlusEMCmax182Rgt1* etaErrorLLPlusEMCmax182Rgt1
 		+etaErrorHEATPlusEMCmax182Rgt1*etaErrorHEATPlusEMCmax182Rgt1);

 ErrorExposureRgt1.push_back(  etaErrorExposureEMCmax182Rgt1  );


 double etaErrorExposureEMCmax182Rgt2;
 double etaErrorCOPlusEMCmax182Rgt2;
 double etaErrorLMPlusEMCmax182Rgt2;
 double etaErrorLAPlusEMCmax182Rgt2;
 double etaErrorLLPlusEMCmax182Rgt2;
 double etaErrorHEATPlusEMCmax182Rgt2;

 if(etaEEMCmax182RFdgt2km!=0)
 		{
 		etaErrorCOPlusEMCmax182Rgt2 = (sqrt(EventsWithErecCOEMCmax182RFdgt2km ) / GeneratedEventsEMCmax182RFdgt2km ) * (exposureCoihuecoThetamin115EMCmax182Rgt2 /  etaEEMCmax182RFdgt2km) ;
 		etaErrorLMPlusEMCmax182Rgt2 = ( sqrt(EventsWithErecCOEMCmax182RFdgt2km ) / GeneratedEventsEMCmax182RFdgt2km ) * (exposureLMThetamin115EMCmax182Rgt2) /  etaEEMCmax182RFdgt2km;
 		etaErrorLAPlusEMCmax182Rgt2 = ( sqrt(EventsWithErecCOEMCmax182RFdgt2km ) / GeneratedEventsEMCmax182RFdgt2km ) * (exposureLAThetamin115EMCmax182Rgt2)/  etaEEMCmax182RFdgt2km ;
 		etaErrorLLPlusEMCmax182Rgt2 = (sqrt(EventsWithErecCOEMCmax182RFdgt2km ) / GeneratedEventsEMCmax182RFdgt2km ) *	(exposureLLEmin17Thetamin115EMCmax182Rgt2) /  etaEEMCmax182RFdgt2km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax182Rgt2 =0;
 		etaErrorLMPlusEMCmax182Rgt2 = 0;
 		etaErrorLAPlusEMCmax182Rgt2 = 0 ;
 		etaErrorLLPlusEMCmax182Rgt2 =0;
 		}

 	if( etaEHEATEMCmax182RFdgt2km!=0)
 	etaErrorHEATPlusEMCmax182Rgt2 = (sqrt(EventsWithErecHEATEMCmax182RFdgt2km ) / GeneratedEventsEMCmax182RFdgt2km ) * (exposureHEATThetamin115EMCmax182Rgt2)/  etaEHEATEMCmax182RFdgt2km ;
 	else
 	etaErrorHEATPlusEMCmax182Rgt2 =0;

 etaErrorExposureEMCmax182Rgt2 = sqrt(  etaErrorCOPlusEMCmax182Rgt2*etaErrorCOPlusEMCmax182Rgt2 + etaErrorLMPlusEMCmax182Rgt2*etaErrorLMPlusEMCmax182Rgt2 +
 		etaErrorLAPlusEMCmax182Rgt2*etaErrorLAPlusEMCmax182Rgt2 +  etaErrorLLPlusEMCmax182Rgt2* etaErrorLLPlusEMCmax182Rgt2
 		+etaErrorHEATPlusEMCmax182Rgt2*etaErrorHEATPlusEMCmax182Rgt2);

 ErrorExposureRgt2.push_back(  etaErrorExposureEMCmax182Rgt2  );

 double etaErrorExposureEMCmax182Rgt3;
 double etaErrorCOPlusEMCmax182Rgt3;
 double etaErrorLMPlusEMCmax182Rgt3;
 double etaErrorLAPlusEMCmax182Rgt3;
 double etaErrorLLPlusEMCmax182Rgt3;
 double etaErrorHEATPlusEMCmax182Rgt3;

 if(etaEEMCmax182RFdgt3km!=0)
 		{
 		etaErrorCOPlusEMCmax182Rgt3 = (sqrt(EventsWithErecCOEMCmax182RFdgt3km ) / GeneratedEventsEMCmax182RFdgt3km ) * (exposureCoihuecoThetamin115EMCmax182Rgt3 /  etaEEMCmax182RFdgt3km) ;
 		etaErrorLMPlusEMCmax182Rgt3 = ( sqrt(EventsWithErecCOEMCmax182RFdgt3km ) / GeneratedEventsEMCmax182RFdgt3km ) * (exposureLMThetamin115EMCmax182Rgt3) /  etaEEMCmax182RFdgt3km;
 		etaErrorLAPlusEMCmax182Rgt3 = ( sqrt(EventsWithErecCOEMCmax182RFdgt3km ) / GeneratedEventsEMCmax182RFdgt3km ) * (exposureLAThetamin115EMCmax182Rgt3)/  etaEEMCmax182RFdgt3km ;
 		etaErrorLLPlusEMCmax182Rgt3 = (sqrt(EventsWithErecCOEMCmax182RFdgt3km ) / GeneratedEventsEMCmax182RFdgt3km ) *	(exposureLLEmin17Thetamin115EMCmax182Rgt3) /  etaEEMCmax182RFdgt3km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax182Rgt3 =0;
 		etaErrorLMPlusEMCmax182Rgt3 = 0;
 		etaErrorLAPlusEMCmax182Rgt3 = 0 ;
 		etaErrorLLPlusEMCmax182Rgt3 =0;
 		}

 	if( etaEHEATEMCmax182RFdgt3km!=0)
 	etaErrorHEATPlusEMCmax182Rgt3 = (sqrt(EventsWithErecHEATEMCmax182RFdgt3km ) / GeneratedEventsEMCmax182RFdgt3km ) * (exposureHEATThetamin115EMCmax182Rgt3)/  etaEHEATEMCmax182RFdgt3km ;
 	else
 	etaErrorHEATPlusEMCmax182Rgt3 =0;

 etaErrorExposureEMCmax182Rgt3 = sqrt(  etaErrorCOPlusEMCmax182Rgt3*etaErrorCOPlusEMCmax182Rgt3 + etaErrorLMPlusEMCmax182Rgt3*etaErrorLMPlusEMCmax182Rgt3 +
 		etaErrorLAPlusEMCmax182Rgt3*etaErrorLAPlusEMCmax182Rgt3 +  etaErrorLLPlusEMCmax182Rgt3* etaErrorLLPlusEMCmax182Rgt3
 		+etaErrorHEATPlusEMCmax182Rgt3*etaErrorHEATPlusEMCmax182Rgt3);

 ErrorExposureRgt3.push_back(  etaErrorExposureEMCmax182Rgt3  );


 double etaErrorExposureEMCmax182Rgt4;
 double etaErrorCOPlusEMCmax182Rgt4;
 double etaErrorLMPlusEMCmax182Rgt4;
 double etaErrorLAPlusEMCmax182Rgt4;
 double etaErrorLLPlusEMCmax182Rgt4;
 double etaErrorHEATPlusEMCmax182Rgt4;

 if(etaEEMCmax182RFdgt4km!=0)
 		{
 		etaErrorCOPlusEMCmax182Rgt4 = (sqrt(EventsWithErecCOEMCmax182RFdgt4km ) / GeneratedEventsEMCmax182RFdgt4km ) * (exposureCoihuecoThetamin115EMCmax182Rgt4 /  etaEEMCmax182RFdgt4km) ;
 		etaErrorLMPlusEMCmax182Rgt4 = ( sqrt(EventsWithErecCOEMCmax182RFdgt4km ) / GeneratedEventsEMCmax182RFdgt4km ) * (exposureLMThetamin115EMCmax182Rgt4) /  etaEEMCmax182RFdgt4km;
 		etaErrorLAPlusEMCmax182Rgt4 = ( sqrt(EventsWithErecCOEMCmax182RFdgt4km ) / GeneratedEventsEMCmax182RFdgt4km ) * (exposureLAThetamin115EMCmax182Rgt4)/  etaEEMCmax182RFdgt4km ;
 		etaErrorLLPlusEMCmax182Rgt4 = (sqrt(EventsWithErecCOEMCmax182RFdgt4km ) / GeneratedEventsEMCmax182RFdgt4km ) *	(exposureLLEmin17Thetamin115EMCmax182Rgt4) /  etaEEMCmax182RFdgt4km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax182Rgt4 =0;
 		etaErrorLMPlusEMCmax182Rgt4 = 0;
 		etaErrorLAPlusEMCmax182Rgt4 = 0 ;
 		etaErrorLLPlusEMCmax182Rgt4 =0;
 		}

 	if( etaEHEATEMCmax182RFdgt4km!=0)
 	etaErrorHEATPlusEMCmax182Rgt4 = (sqrt(EventsWithErecHEATEMCmax182RFdgt4km ) / GeneratedEventsEMCmax182RFdgt4km ) * (exposureHEATThetamin115EMCmax182Rgt4)/  etaEHEATEMCmax182RFdgt4km ;
 	else
 	etaErrorHEATPlusEMCmax182Rgt4 =0;

 etaErrorExposureEMCmax182Rgt4 = sqrt(  etaErrorCOPlusEMCmax182Rgt4*etaErrorCOPlusEMCmax182Rgt4 + etaErrorLMPlusEMCmax182Rgt4*etaErrorLMPlusEMCmax182Rgt4 +
 		etaErrorLAPlusEMCmax182Rgt4*etaErrorLAPlusEMCmax182Rgt4 +  etaErrorLLPlusEMCmax182Rgt4* etaErrorLLPlusEMCmax182Rgt4
 		+etaErrorHEATPlusEMCmax182Rgt4*etaErrorHEATPlusEMCmax182Rgt4);

 ErrorExposureRgt4.push_back(  etaErrorExposureEMCmax182Rgt4  );


 double etaErrorExposureEMCmax182Rgt5;
 double etaErrorCOPlusEMCmax182Rgt5;
 double etaErrorLMPlusEMCmax182Rgt5;
 double etaErrorLAPlusEMCmax182Rgt5;
 double etaErrorLLPlusEMCmax182Rgt5;
 double etaErrorHEATPlusEMCmax182Rgt5;

 if(etaEEMCmax182RFdgt5km!=0)
 		{
 		etaErrorCOPlusEMCmax182Rgt5 = (sqrt(EventsWithErecCOEMCmax182RFdgt5km ) / GeneratedEventsEMCmax182RFdgt5km ) * (exposureCoihuecoThetamin115EMCmax182Rgt5 /  etaEEMCmax182RFdgt5km) ;
 		etaErrorLMPlusEMCmax182Rgt5 = ( sqrt(EventsWithErecCOEMCmax182RFdgt5km ) / GeneratedEventsEMCmax182RFdgt5km ) * (exposureLMThetamin115EMCmax182Rgt5) /  etaEEMCmax182RFdgt5km;
 		etaErrorLAPlusEMCmax182Rgt5 = ( sqrt(EventsWithErecCOEMCmax182RFdgt5km ) / GeneratedEventsEMCmax182RFdgt5km ) * (exposureLAThetamin115EMCmax182Rgt5)/  etaEEMCmax182RFdgt5km ;
 		etaErrorLLPlusEMCmax182Rgt5 = (sqrt(EventsWithErecCOEMCmax182RFdgt5km ) / GeneratedEventsEMCmax182RFdgt5km ) *	(exposureLLEmin17Thetamin115EMCmax182Rgt5) /  etaEEMCmax182RFdgt5km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax182Rgt5 =0;
 		etaErrorLMPlusEMCmax182Rgt5 = 0;
 		etaErrorLAPlusEMCmax182Rgt5 = 0 ;
 		etaErrorLLPlusEMCmax182Rgt5 =0;
 		}

 	if( etaEHEATEMCmax182RFdgt5km!=0)
 	etaErrorHEATPlusEMCmax182Rgt5 = (sqrt(EventsWithErecHEATEMCmax182RFdgt5km ) / GeneratedEventsEMCmax182RFdgt5km ) * (exposureHEATThetamin115EMCmax182Rgt5)/  etaEHEATEMCmax182RFdgt5km ;
 	else
 	etaErrorHEATPlusEMCmax182Rgt5 =0;

 etaErrorExposureEMCmax182Rgt5 = sqrt(  etaErrorCOPlusEMCmax182Rgt5*etaErrorCOPlusEMCmax182Rgt5 + etaErrorLMPlusEMCmax182Rgt5*etaErrorLMPlusEMCmax182Rgt5 +
 		etaErrorLAPlusEMCmax182Rgt5*etaErrorLAPlusEMCmax182Rgt5 +  etaErrorLLPlusEMCmax182Rgt5* etaErrorLLPlusEMCmax182Rgt5
 		+etaErrorHEATPlusEMCmax182Rgt5*etaErrorHEATPlusEMCmax182Rgt5);

 ErrorExposureRgt5.push_back(  etaErrorExposureEMCmax182Rgt5  );



double etaEEMCmax183; //etaE=recEvents/GenEvents ->reconstruction efficiency
etaEEMCmax183 = EventsWithErecCOEMCmax183 / GeneratedEventsEMCmax183;

double etaEHEATEMCmax183;
etaEHEATEMCmax183 = EventsWithErecHEATEMCmax183 / GeneratedEventsEMCmax183;
cout<<"etaE (E=18.2: "<<etaEEMCmax183<<endl;
ErrorEvents.push_back(sqrt(EventsWithErecCOEMCmax183 ));

double etaEEMCmax183RFdgt1km;
etaEEMCmax183RFdgt1km = EventsWithErecCOEMCmax183RFdgt1km / GeneratedEventsEMCmax183RFdgt1km;
double etaEEMCmax183RFdgt2km;
etaEEMCmax183RFdgt2km = EventsWithErecCOEMCmax183RFdgt2km / GeneratedEventsEMCmax183RFdgt2km;
double etaEEMCmax183RFdgt3km;
etaEEMCmax183RFdgt3km = EventsWithErecCOEMCmax183RFdgt3km / GeneratedEventsEMCmax183RFdgt3km;
double etaEEMCmax183RFdgt4km;
etaEEMCmax183RFdgt4km = EventsWithErecCOEMCmax183RFdgt4km / GeneratedEventsEMCmax183RFdgt4km;
double etaEEMCmax183RFdgt5km;
etaEEMCmax183RFdgt5km = EventsWithErecCOEMCmax183RFdgt5km / GeneratedEventsEMCmax183RFdgt5km;

double etaEHEATEMCmax183RFdgt1km;
etaEHEATEMCmax183RFdgt1km = EventsWithErecHEATEMCmax183RFdgt1km / GeneratedEventsEMCmax183RFdgt1km;
double etaEHEATEMCmax183RFdgt2km;
etaEHEATEMCmax183RFdgt2km = EventsWithErecHEATEMCmax183RFdgt2km / GeneratedEventsEMCmax183RFdgt2km;
double etaEHEATEMCmax183RFdgt3km;
etaEHEATEMCmax183RFdgt3km = EventsWithErecHEATEMCmax183RFdgt3km / GeneratedEventsEMCmax183RFdgt3km;
double etaEHEATEMCmax183RFdgt4km;
etaEHEATEMCmax183RFdgt4km = EventsWithErecHEATEMCmax183RFdgt4km / GeneratedEventsEMCmax183RFdgt4km;
double etaEHEATEMCmax183RFdgt5km;
etaEHEATEMCmax183RFdgt5km = EventsWithErecHEATEMCmax183RFdgt5km / GeneratedEventsEMCmax183RFdgt5km;

cout<<"total gen events: "<<TotalNrGenEvents<<" in (18.2, 18.3) nr of gen Events = "<<GeneratedEventsEMCmax183<<endl;


cout<<"nr or reconstructed ev: "<<EventsWithErecCOEMCmax183<<endl;



double apertureCoihuecoThetamin115EMCmax183 = etaEEMCmax183 * genAreaCO *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureCoihuecoThetamin115EMCmax183 = apertureCoihuecoThetamin115EMCmax183 * yearsCO;

double apertureLMThetamin115EMCmax183 = etaEEMCmax183 * genAreaLM *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLMThetamin115EMCmax183 = apertureLMThetamin115EMCmax183 * yearsLM;

  double apertureLAThetamin115EMCmax183 = etaEEMCmax183 * genAreaLA *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLAThetamin115EMCmax183 = apertureLAThetamin115EMCmax183 * yearsLA;

    double apertureLL180FOVThetamin115EMCmax183 = etaEEMCmax183 * genAreaLL180FOV *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLL180FOVThetamin115EMCmax183 = apertureLL180FOVThetamin115EMCmax183 * yearsLL180FOV;

  double apertureLL162FOVThetamin115EMCmax183 = etaEEMCmax183 * genAreaLL162FOV *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLL162FOVThetamin115EMCmax183 = apertureLL162FOVThetamin115EMCmax183 * yearsLL162FOV;

  double exposureLLEmin17Thetamin115EMCmax183 = exposureLL180FOVThetamin115EMCmax183 + exposureLL162FOVThetamin115EMCmax183;

  double apertureHEATThetamin115EMCmax183 = etaEHEATEMCmax183 * genAreaHEAT *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureHEATThetamin115EMCmax183 = apertureHEATThetamin115EMCmax183 * yearsHEAT;


  double Exposure4EyesThetamin115EMCmax183 = exposureCoihuecoThetamin115EMCmax183 + exposureLMThetamin115EMCmax183 +
                                            exposureLAThetamin115EMCmax183 + exposureLLEmin17Thetamin115EMCmax183 +	exposureHEATThetamin115EMCmax183;

  Exposure4EyesAllEnergiesThetamin115H0.push_back(Exposure4EyesThetamin115EMCmax183);


  double exposureCoihuecoThetamin115EMCmax183Rgt1 = etaEEMCmax183RFdgt1km * genAreaCORgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;
  double exposureCoihuecoThetamin115EMCmax183Rgt2 = etaEEMCmax183RFdgt2km * genAreaCORgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;
  double exposureCoihuecoThetamin115EMCmax183Rgt3 = etaEEMCmax183RFdgt3km * genAreaCORgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;

  double exposureLMThetamin115EMCmax183Rgt1 = etaEEMCmax183RFdgt1km * genAreaLMRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;
  double exposureLMThetamin115EMCmax183Rgt2 = etaEEMCmax183RFdgt2km * genAreaLMRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;
  double exposureLMThetamin115EMCmax183Rgt3 = etaEEMCmax183RFdgt3km * genAreaLMRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;

  double exposureLAThetamin115EMCmax183Rgt1 = etaEEMCmax183RFdgt1km * genAreaLARgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;
  double exposureLAThetamin115EMCmax183Rgt2 = etaEEMCmax183RFdgt2km * genAreaLARgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;
  double exposureLAThetamin115EMCmax183Rgt3 = etaEEMCmax183RFdgt3km * genAreaLARgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;

  double exposureLL180FOVThetamin115EMCmax183Rgt1 = etaEEMCmax183RFdgt1km * genAreaLL180FOVRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;
  double exposureLL180FOVThetamin115EMCmax183Rgt2 = etaEEMCmax183RFdgt2km * genAreaLL180FOVRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;
  double exposureLL180FOVThetamin115EMCmax183Rgt3 = etaEEMCmax183RFdgt3km * genAreaLL180FOVRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;

  double exposureLL162FOVThetamin115EMCmax183Rgt1 = etaEEMCmax183RFdgt1km * genAreaLL162FOVRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;
  double exposureLL162FOVThetamin115EMCmax183Rgt2 = etaEEMCmax183RFdgt2km * genAreaLL162FOVRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;
  double exposureLL162FOVThetamin115EMCmax183Rgt3 = etaEEMCmax183RFdgt3km * genAreaLL162FOVRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;

  double exposureLLEmin17Thetamin115EMCmax183Rgt1 =  exposureLL180FOVThetamin115EMCmax183Rgt1 + exposureLL162FOVThetamin115EMCmax183Rgt1;
  double exposureLLEmin17Thetamin115EMCmax183Rgt2 =  exposureLL180FOVThetamin115EMCmax183Rgt2 + exposureLL162FOVThetamin115EMCmax183Rgt2;
  double exposureLLEmin17Thetamin115EMCmax183Rgt3 =  exposureLL180FOVThetamin115EMCmax183Rgt3 + exposureLL162FOVThetamin115EMCmax183Rgt3;



  double exposureCoihuecoThetamin115EMCmax183Rgt4 = etaEEMCmax183RFdgt4km * genAreaCORgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;
  double exposureCoihuecoThetamin115EMCmax183Rgt5 = etaEEMCmax183RFdgt5km * genAreaCORgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;

  double exposureLMThetamin115EMCmax183Rgt4 = etaEEMCmax183RFdgt4km * genAreaLMRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;
  double exposureLMThetamin115EMCmax183Rgt5 = etaEEMCmax183RFdgt5km * genAreaLMRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;

  double exposureLAThetamin115EMCmax183Rgt4 = etaEEMCmax183RFdgt4km * genAreaLARgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;
  double exposureLAThetamin115EMCmax183Rgt5 = etaEEMCmax183RFdgt5km * genAreaLARgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;

  double exposureLL180FOVThetamin115EMCmax183Rgt4 = etaEEMCmax183RFdgt4km * genAreaLL180FOVRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;
  double exposureLL180FOVThetamin115EMCmax183Rgt5 = etaEEMCmax183RFdgt5km * genAreaLL180FOVRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;

  double exposureLL162FOVThetamin115EMCmax183Rgt4 = etaEEMCmax183RFdgt4km * genAreaLL162FOVRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;
  double exposureLL162FOVThetamin115EMCmax183Rgt5 = etaEEMCmax183RFdgt5km * genAreaLL162FOVRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;

  double exposureLLEmin17Thetamin115EMCmax183Rgt4 =  exposureLL180FOVThetamin115EMCmax183Rgt4 + exposureLL162FOVThetamin115EMCmax183Rgt4;
  double exposureLLEmin17Thetamin115EMCmax183Rgt5 =  exposureLL180FOVThetamin115EMCmax183Rgt5 + exposureLL162FOVThetamin115EMCmax183Rgt5;


  double exposureHEATThetamin115EMCmax183Rgt1 = etaEHEATEMCmax183RFdgt1km* genAreaHEATRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCmax183Rgt2 = etaEHEATEMCmax183RFdgt2km* genAreaHEATRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCmax183Rgt3 = etaEHEATEMCmax183RFdgt3km* genAreaHEATRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCmax183Rgt4 = etaEHEATEMCmax183RFdgt4km* genAreaHEATRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCmax183Rgt5 = etaEHEATEMCmax183RFdgt5km* genAreaHEATRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;


  Exposure4EyesAllEnergiesThetamin115H0Rgt4.push_back( exposureCoihuecoThetamin115EMCmax183Rgt4 +   exposureLMThetamin115EMCmax183Rgt4
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax183Rgt4 + exposureLLEmin17Thetamin115EMCmax183Rgt4
																													+ exposureHEATThetamin115EMCmax183Rgt4 );
  Exposure4EyesAllEnergiesThetamin115H0Rgt5.push_back( exposureCoihuecoThetamin115EMCmax183Rgt5 +   exposureLMThetamin115EMCmax183Rgt5
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax183Rgt5 + exposureLLEmin17Thetamin115EMCmax183Rgt5
																													+ exposureHEATThetamin115EMCmax183Rgt5);

  Exposure4EyesAllEnergiesThetamin115H0Rgt1.push_back( exposureCoihuecoThetamin115EMCmax183Rgt1 +   exposureLMThetamin115EMCmax183Rgt1
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax183Rgt1 + exposureLLEmin17Thetamin115EMCmax183Rgt1
																													+ exposureHEATThetamin115EMCmax183Rgt1);
  Exposure4EyesAllEnergiesThetamin115H0Rgt2.push_back( exposureCoihuecoThetamin115EMCmax183Rgt2 +   exposureLMThetamin115EMCmax183Rgt2
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax183Rgt2 + exposureLLEmin17Thetamin115EMCmax183Rgt2
																													+  exposureHEATThetamin115EMCmax183Rgt2);
  Exposure4EyesAllEnergiesThetamin115H0Rgt3.push_back( exposureCoihuecoThetamin115EMCmax183Rgt3 +   exposureLMThetamin115EMCmax183Rgt3
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax183Rgt3 + exposureLLEmin17Thetamin115EMCmax183Rgt3
																													+  exposureHEATThetamin115EMCmax183Rgt3);

 EnergyRangeVector.push_back(18.2);

 double etaErrorExposurePlusEMCmax183 ;
 double etaErrorCOPlusEMCmax183;
 double etaErrorLMPlusEMCmax183;
 double etaErrorLAPlusEMCmax183;
 double etaErrorLLPlusEMCmax183;
 double etaErrorHEATPlusEMCmax183;

 if( etaEEMCmax183!=0)
 		{
 		etaErrorCOPlusEMCmax183 = (sqrt(EventsWithErecCOEMCmax183 ) / GeneratedEventsEMCmax183 ) * (exposureCoihuecoThetamin115EMCmax183 /  etaEEMCmax183) ;
 		etaErrorLMPlusEMCmax183 = ( sqrt(EventsWithErecCOEMCmax183 ) / GeneratedEventsEMCmax183 ) * (exposureLMThetamin115EMCmax183) /  etaEEMCmax183;
 		etaErrorLAPlusEMCmax183 = ( sqrt(EventsWithErecCOEMCmax183 ) / GeneratedEventsEMCmax183 ) * (exposureLAThetamin115EMCmax183)/  etaEEMCmax183 ;
 		etaErrorLLPlusEMCmax183 = (sqrt(EventsWithErecCOEMCmax183 ) / GeneratedEventsEMCmax183 ) *	(exposureLLEmin17Thetamin115EMCmax183) /  etaEEMCmax183;
 		}
 else
 		{
 			etaErrorCOPlusEMCmax183 = 0 ;
 			etaErrorLMPlusEMCmax183 = 0;
 			etaErrorLAPlusEMCmax183 =0 ;
 			etaErrorLLPlusEMCmax183 =0;
 		}
 	if(etaEHEATEMCmax183!=0)
 		etaErrorHEATPlusEMCmax183 = (sqrt(EventsWithErecHEATEMCmax183 ) / GeneratedEventsEMCmax183 ) * (exposureHEATThetamin115EMCmax183)/  etaEHEATEMCmax183 ;
 	else
 		etaErrorHEATPlusEMCmax183 = 0;


 etaErrorExposurePlusEMCmax183 = sqrt(  etaErrorCOPlusEMCmax183*etaErrorCOPlusEMCmax183 + etaErrorLMPlusEMCmax183*etaErrorLMPlusEMCmax183 +
 																etaErrorLAPlusEMCmax183*etaErrorLAPlusEMCmax183 +  etaErrorLLPlusEMCmax183* etaErrorLLPlusEMCmax183
 																+etaErrorHEATPlusEMCmax183*etaErrorHEATPlusEMCmax183);

 cout<<" E=17  "<<"Error Total Exposure  "<<etaErrorExposurePlusEMCmax183 <<endl;

 cout<<"exposure CO: "<<exposureCoihuecoThetamin115EMCmax183 << " error: "<<etaErrorCOPlusEMCmax183<<endl;
 cout<<"exposure LA: "<<exposureLAThetamin115EMCmax183 << " error: "<<etaErrorLAPlusEMCmax183<<endl;
 cout<<"exposure LM: "<<exposureLMThetamin115EMCmax183 << " error: "<<etaErrorLMPlusEMCmax183<<endl;
 cout<<"exposure LL: "<<exposureLLEmin17Thetamin115EMCmax183 << " error: "<<etaErrorLLPlusEMCmax183<<endl;
 cout<<"exposure HEAT: "<<exposureHEATThetamin115EMCmax183 << " error: "<<etaErrorHEATPlusEMCmax183<<endl;


 ErrorExposurePlus.push_back(etaErrorExposurePlusEMCmax183);


 double etaErrorExposureEMCmax183Rgt1;
 double etaErrorCOPlusEMCmax183Rgt1;
 double etaErrorLMPlusEMCmax183Rgt1;
 double etaErrorLAPlusEMCmax183Rgt1;
 double etaErrorLLPlusEMCmax183Rgt1;
 double etaErrorHEATPlusEMCmax183Rgt1;

 if(etaEEMCmax183RFdgt1km!=0)
 		{
 		etaErrorCOPlusEMCmax183Rgt1 = (sqrt(EventsWithErecCOEMCmax183RFdgt1km ) / GeneratedEventsEMCmax183RFdgt1km ) * (exposureCoihuecoThetamin115EMCmax183Rgt1 /  etaEEMCmax183RFdgt1km) ;
 		etaErrorLMPlusEMCmax183Rgt1 = ( sqrt(EventsWithErecCOEMCmax183RFdgt1km ) / GeneratedEventsEMCmax183RFdgt1km ) * (exposureLMThetamin115EMCmax183Rgt1) /  etaEEMCmax183RFdgt1km;
 		etaErrorLAPlusEMCmax183Rgt1 = ( sqrt(EventsWithErecCOEMCmax183RFdgt1km ) / GeneratedEventsEMCmax183RFdgt1km ) * (exposureLAThetamin115EMCmax183Rgt1)/  etaEEMCmax183RFdgt1km ;
 		etaErrorLLPlusEMCmax183Rgt1 = (sqrt(EventsWithErecCOEMCmax183RFdgt1km ) / GeneratedEventsEMCmax183RFdgt1km ) *	(exposureLLEmin17Thetamin115EMCmax183Rgt1) /  etaEEMCmax183RFdgt1km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax183Rgt1 =0;
 		etaErrorLMPlusEMCmax183Rgt1 = 0;
 		etaErrorLAPlusEMCmax183Rgt1 = 0 ;
 		etaErrorLLPlusEMCmax183Rgt1 =0;
 		}

 	if( etaEHEATEMCmax183RFdgt1km!=0)
 	etaErrorHEATPlusEMCmax183Rgt1 = (sqrt(EventsWithErecHEATEMCmax183RFdgt1km ) / GeneratedEventsEMCmax183RFdgt1km ) * (exposureHEATThetamin115EMCmax183Rgt1)/  etaEHEATEMCmax183RFdgt1km ;
 	else
 	etaErrorHEATPlusEMCmax183Rgt1 =0;

 etaErrorExposureEMCmax183Rgt1 = sqrt(  etaErrorCOPlusEMCmax183Rgt1*etaErrorCOPlusEMCmax183Rgt1 + etaErrorLMPlusEMCmax183Rgt1*etaErrorLMPlusEMCmax183Rgt1 +
 		etaErrorLAPlusEMCmax183Rgt1*etaErrorLAPlusEMCmax183Rgt1 +  etaErrorLLPlusEMCmax183Rgt1* etaErrorLLPlusEMCmax183Rgt1
 		+etaErrorHEATPlusEMCmax183Rgt1*etaErrorHEATPlusEMCmax183Rgt1);

 ErrorExposureRgt1.push_back(  etaErrorExposureEMCmax183Rgt1  );


 double etaErrorExposureEMCmax183Rgt2;
 double etaErrorCOPlusEMCmax183Rgt2;
 double etaErrorLMPlusEMCmax183Rgt2;
 double etaErrorLAPlusEMCmax183Rgt2;
 double etaErrorLLPlusEMCmax183Rgt2;
 double etaErrorHEATPlusEMCmax183Rgt2;

 if(etaEEMCmax183RFdgt2km!=0)
 		{
 		etaErrorCOPlusEMCmax183Rgt2 = (sqrt(EventsWithErecCOEMCmax183RFdgt2km ) / GeneratedEventsEMCmax183RFdgt2km ) * (exposureCoihuecoThetamin115EMCmax183Rgt2 /  etaEEMCmax183RFdgt2km) ;
 		etaErrorLMPlusEMCmax183Rgt2 = ( sqrt(EventsWithErecCOEMCmax183RFdgt2km ) / GeneratedEventsEMCmax183RFdgt2km ) * (exposureLMThetamin115EMCmax183Rgt2) /  etaEEMCmax183RFdgt2km;
 		etaErrorLAPlusEMCmax183Rgt2 = ( sqrt(EventsWithErecCOEMCmax183RFdgt2km ) / GeneratedEventsEMCmax183RFdgt2km ) * (exposureLAThetamin115EMCmax183Rgt2)/  etaEEMCmax183RFdgt2km ;
 		etaErrorLLPlusEMCmax183Rgt2 = (sqrt(EventsWithErecCOEMCmax183RFdgt2km ) / GeneratedEventsEMCmax183RFdgt2km ) *	(exposureLLEmin17Thetamin115EMCmax183Rgt2) /  etaEEMCmax183RFdgt2km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax183Rgt2 =0;
 		etaErrorLMPlusEMCmax183Rgt2 = 0;
 		etaErrorLAPlusEMCmax183Rgt2 = 0 ;
 		etaErrorLLPlusEMCmax183Rgt2 =0;
 		}

 	if( etaEHEATEMCmax183RFdgt2km!=0)
 	etaErrorHEATPlusEMCmax183Rgt2 = (sqrt(EventsWithErecHEATEMCmax183RFdgt2km ) / GeneratedEventsEMCmax183RFdgt2km ) * (exposureHEATThetamin115EMCmax183Rgt2)/  etaEHEATEMCmax183RFdgt2km ;
 	else
 	etaErrorHEATPlusEMCmax183Rgt2 =0;

 etaErrorExposureEMCmax183Rgt2 = sqrt(  etaErrorCOPlusEMCmax183Rgt2*etaErrorCOPlusEMCmax183Rgt2 + etaErrorLMPlusEMCmax183Rgt2*etaErrorLMPlusEMCmax183Rgt2 +
 		etaErrorLAPlusEMCmax183Rgt2*etaErrorLAPlusEMCmax183Rgt2 +  etaErrorLLPlusEMCmax183Rgt2* etaErrorLLPlusEMCmax183Rgt2
 		+etaErrorHEATPlusEMCmax183Rgt2*etaErrorHEATPlusEMCmax183Rgt2);

 ErrorExposureRgt2.push_back(  etaErrorExposureEMCmax183Rgt2  );

 double etaErrorExposureEMCmax183Rgt3;
 double etaErrorCOPlusEMCmax183Rgt3;
 double etaErrorLMPlusEMCmax183Rgt3;
 double etaErrorLAPlusEMCmax183Rgt3;
 double etaErrorLLPlusEMCmax183Rgt3;
 double etaErrorHEATPlusEMCmax183Rgt3;

 if(etaEEMCmax183RFdgt3km!=0)
 		{
 		etaErrorCOPlusEMCmax183Rgt3 = (sqrt(EventsWithErecCOEMCmax183RFdgt3km ) / GeneratedEventsEMCmax183RFdgt3km ) * (exposureCoihuecoThetamin115EMCmax183Rgt3 /  etaEEMCmax183RFdgt3km) ;
 		etaErrorLMPlusEMCmax183Rgt3 = ( sqrt(EventsWithErecCOEMCmax183RFdgt3km ) / GeneratedEventsEMCmax183RFdgt3km ) * (exposureLMThetamin115EMCmax183Rgt3) /  etaEEMCmax183RFdgt3km;
 		etaErrorLAPlusEMCmax183Rgt3 = ( sqrt(EventsWithErecCOEMCmax183RFdgt3km ) / GeneratedEventsEMCmax183RFdgt3km ) * (exposureLAThetamin115EMCmax183Rgt3)/  etaEEMCmax183RFdgt3km ;
 		etaErrorLLPlusEMCmax183Rgt3 = (sqrt(EventsWithErecCOEMCmax183RFdgt3km ) / GeneratedEventsEMCmax183RFdgt3km ) *	(exposureLLEmin17Thetamin115EMCmax183Rgt3) /  etaEEMCmax183RFdgt3km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax183Rgt3 =0;
 		etaErrorLMPlusEMCmax183Rgt3 = 0;
 		etaErrorLAPlusEMCmax183Rgt3 = 0 ;
 		etaErrorLLPlusEMCmax183Rgt3 =0;
 		}

 	if( etaEHEATEMCmax183RFdgt3km!=0)
 	etaErrorHEATPlusEMCmax183Rgt3 = (sqrt(EventsWithErecHEATEMCmax183RFdgt3km ) / GeneratedEventsEMCmax183RFdgt3km ) * (exposureHEATThetamin115EMCmax183Rgt3)/  etaEHEATEMCmax183RFdgt3km ;
 	else
 	etaErrorHEATPlusEMCmax183Rgt3 =0;

 etaErrorExposureEMCmax183Rgt3 = sqrt(  etaErrorCOPlusEMCmax183Rgt3*etaErrorCOPlusEMCmax183Rgt3 + etaErrorLMPlusEMCmax183Rgt3*etaErrorLMPlusEMCmax183Rgt3 +
 		etaErrorLAPlusEMCmax183Rgt3*etaErrorLAPlusEMCmax183Rgt3 +  etaErrorLLPlusEMCmax183Rgt3* etaErrorLLPlusEMCmax183Rgt3
 		+etaErrorHEATPlusEMCmax183Rgt3*etaErrorHEATPlusEMCmax183Rgt3);

 ErrorExposureRgt3.push_back(  etaErrorExposureEMCmax183Rgt3  );


 double etaErrorExposureEMCmax183Rgt4;
 double etaErrorCOPlusEMCmax183Rgt4;
 double etaErrorLMPlusEMCmax183Rgt4;
 double etaErrorLAPlusEMCmax183Rgt4;
 double etaErrorLLPlusEMCmax183Rgt4;
 double etaErrorHEATPlusEMCmax183Rgt4;

 if(etaEEMCmax183RFdgt4km!=0)
 		{
 		etaErrorCOPlusEMCmax183Rgt4 = (sqrt(EventsWithErecCOEMCmax183RFdgt4km ) / GeneratedEventsEMCmax183RFdgt4km ) * (exposureCoihuecoThetamin115EMCmax183Rgt4 /  etaEEMCmax183RFdgt4km) ;
 		etaErrorLMPlusEMCmax183Rgt4 = ( sqrt(EventsWithErecCOEMCmax183RFdgt4km ) / GeneratedEventsEMCmax183RFdgt4km ) * (exposureLMThetamin115EMCmax183Rgt4) /  etaEEMCmax183RFdgt4km;
 		etaErrorLAPlusEMCmax183Rgt4 = ( sqrt(EventsWithErecCOEMCmax183RFdgt4km ) / GeneratedEventsEMCmax183RFdgt4km ) * (exposureLAThetamin115EMCmax183Rgt4)/  etaEEMCmax183RFdgt4km ;
 		etaErrorLLPlusEMCmax183Rgt4 = (sqrt(EventsWithErecCOEMCmax183RFdgt4km ) / GeneratedEventsEMCmax183RFdgt4km ) *	(exposureLLEmin17Thetamin115EMCmax183Rgt4) /  etaEEMCmax183RFdgt4km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax183Rgt4 =0;
 		etaErrorLMPlusEMCmax183Rgt4 = 0;
 		etaErrorLAPlusEMCmax183Rgt4 = 0 ;
 		etaErrorLLPlusEMCmax183Rgt4 =0;
 		}

 	if( etaEHEATEMCmax183RFdgt4km!=0)
 	etaErrorHEATPlusEMCmax183Rgt4 = (sqrt(EventsWithErecHEATEMCmax183RFdgt4km ) / GeneratedEventsEMCmax183RFdgt4km ) * (exposureHEATThetamin115EMCmax183Rgt4)/  etaEHEATEMCmax183RFdgt4km ;
 	else
 	etaErrorHEATPlusEMCmax183Rgt4 =0;

 etaErrorExposureEMCmax183Rgt4 = sqrt(  etaErrorCOPlusEMCmax183Rgt4*etaErrorCOPlusEMCmax183Rgt4 + etaErrorLMPlusEMCmax183Rgt4*etaErrorLMPlusEMCmax183Rgt4 +
 		etaErrorLAPlusEMCmax183Rgt4*etaErrorLAPlusEMCmax183Rgt4 +  etaErrorLLPlusEMCmax183Rgt4* etaErrorLLPlusEMCmax183Rgt4
 		+etaErrorHEATPlusEMCmax183Rgt4*etaErrorHEATPlusEMCmax183Rgt4);

 ErrorExposureRgt4.push_back(  etaErrorExposureEMCmax183Rgt4  );


 double etaErrorExposureEMCmax183Rgt5;
 double etaErrorCOPlusEMCmax183Rgt5;
 double etaErrorLMPlusEMCmax183Rgt5;
 double etaErrorLAPlusEMCmax183Rgt5;
 double etaErrorLLPlusEMCmax183Rgt5;
 double etaErrorHEATPlusEMCmax183Rgt5;

 if(etaEEMCmax183RFdgt5km!=0)
 		{
 		etaErrorCOPlusEMCmax183Rgt5 = (sqrt(EventsWithErecCOEMCmax183RFdgt5km ) / GeneratedEventsEMCmax183RFdgt5km ) * (exposureCoihuecoThetamin115EMCmax183Rgt5 /  etaEEMCmax183RFdgt5km) ;
 		etaErrorLMPlusEMCmax183Rgt5 = ( sqrt(EventsWithErecCOEMCmax183RFdgt5km ) / GeneratedEventsEMCmax183RFdgt5km ) * (exposureLMThetamin115EMCmax183Rgt5) /  etaEEMCmax183RFdgt5km;
 		etaErrorLAPlusEMCmax183Rgt5 = ( sqrt(EventsWithErecCOEMCmax183RFdgt5km ) / GeneratedEventsEMCmax183RFdgt5km ) * (exposureLAThetamin115EMCmax183Rgt5)/  etaEEMCmax183RFdgt5km ;
 		etaErrorLLPlusEMCmax183Rgt5 = (sqrt(EventsWithErecCOEMCmax183RFdgt5km ) / GeneratedEventsEMCmax183RFdgt5km ) *	(exposureLLEmin17Thetamin115EMCmax183Rgt5) /  etaEEMCmax183RFdgt5km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax183Rgt5 =0;
 		etaErrorLMPlusEMCmax183Rgt5 = 0;
 		etaErrorLAPlusEMCmax183Rgt5 = 0 ;
 		etaErrorLLPlusEMCmax183Rgt5 =0;
 		}

 	if( etaEHEATEMCmax183RFdgt5km!=0)
 	etaErrorHEATPlusEMCmax183Rgt5 = (sqrt(EventsWithErecHEATEMCmax183RFdgt5km ) / GeneratedEventsEMCmax183RFdgt5km ) * (exposureHEATThetamin115EMCmax183Rgt5)/  etaEHEATEMCmax183RFdgt5km ;
 	else
 	etaErrorHEATPlusEMCmax183Rgt5 =0;

 etaErrorExposureEMCmax183Rgt5 = sqrt(  etaErrorCOPlusEMCmax183Rgt5*etaErrorCOPlusEMCmax183Rgt5 + etaErrorLMPlusEMCmax183Rgt5*etaErrorLMPlusEMCmax183Rgt5 +
 		etaErrorLAPlusEMCmax183Rgt5*etaErrorLAPlusEMCmax183Rgt5 +  etaErrorLLPlusEMCmax183Rgt5* etaErrorLLPlusEMCmax183Rgt5
 		+etaErrorHEATPlusEMCmax183Rgt5*etaErrorHEATPlusEMCmax183Rgt5);

 ErrorExposureRgt5.push_back(  etaErrorExposureEMCmax183Rgt5  );




double etaEEMCmax184; //etaE=recEvents/GenEvents ->reconstruction efficiency
etaEEMCmax184 = EventsWithErecCOEMCmax184 / GeneratedEventsEMCmax184;

double etaEHEATEMCmax184;
etaEHEATEMCmax184 = EventsWithErecHEATEMCmax184 / GeneratedEventsEMCmax184;
cout<<"etaE (E=18.3: "<<etaEEMCmax184<<endl;
ErrorEvents.push_back(sqrt(EventsWithErecCOEMCmax184 ));

double etaEEMCmax184RFdgt1km;
etaEEMCmax184RFdgt1km = EventsWithErecCOEMCmax184RFdgt1km / GeneratedEventsEMCmax184RFdgt1km;
double etaEEMCmax184RFdgt2km;
etaEEMCmax184RFdgt2km = EventsWithErecCOEMCmax184RFdgt2km / GeneratedEventsEMCmax184RFdgt2km;
double etaEEMCmax184RFdgt3km;
etaEEMCmax184RFdgt3km = EventsWithErecCOEMCmax184RFdgt3km / GeneratedEventsEMCmax184RFdgt3km;
double etaEEMCmax184RFdgt4km;
etaEEMCmax184RFdgt4km = EventsWithErecCOEMCmax184RFdgt4km / GeneratedEventsEMCmax184RFdgt4km;
double etaEEMCmax184RFdgt5km;
etaEEMCmax184RFdgt5km = EventsWithErecCOEMCmax184RFdgt5km / GeneratedEventsEMCmax184RFdgt5km;

double etaEHEATEMCmax184RFdgt1km;
etaEHEATEMCmax184RFdgt1km = EventsWithErecHEATEMCmax184RFdgt1km / GeneratedEventsEMCmax184RFdgt1km;
double etaEHEATEMCmax184RFdgt2km;
etaEHEATEMCmax184RFdgt2km = EventsWithErecHEATEMCmax184RFdgt2km / GeneratedEventsEMCmax184RFdgt2km;
double etaEHEATEMCmax184RFdgt3km;
etaEHEATEMCmax184RFdgt3km = EventsWithErecHEATEMCmax184RFdgt3km / GeneratedEventsEMCmax184RFdgt3km;
double etaEHEATEMCmax184RFdgt4km;
etaEHEATEMCmax184RFdgt4km = EventsWithErecHEATEMCmax184RFdgt4km / GeneratedEventsEMCmax184RFdgt4km;
double etaEHEATEMCmax184RFdgt5km;
etaEHEATEMCmax184RFdgt5km = EventsWithErecHEATEMCmax184RFdgt5km / GeneratedEventsEMCmax184RFdgt5km;

cout<<"total gen events: "<<TotalNrGenEvents<<" in (18.3, 18.4) nr of gen Events = "<<GeneratedEventsEMCmax184<<endl;


cout<<"nr or reconstructed ev: "<<EventsWithErecCOEMCmax184<<endl;



double apertureCoihuecoThetamin115EMCmax184 = etaEEMCmax184 * genAreaCO *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureCoihuecoThetamin115EMCmax184 = apertureCoihuecoThetamin115EMCmax184 * yearsCO;

double apertureLMThetamin115EMCmax184 = etaEEMCmax184 * genAreaLM *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLMThetamin115EMCmax184 = apertureLMThetamin115EMCmax184 * yearsLM;

  double apertureLAThetamin115EMCmax184 = etaEEMCmax184 * genAreaLA *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLAThetamin115EMCmax184 = apertureLAThetamin115EMCmax184 * yearsLA;

    double apertureLL180FOVThetamin115EMCmax184 = etaEEMCmax184 * genAreaLL180FOV *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLL180FOVThetamin115EMCmax184 = apertureLL180FOVThetamin115EMCmax184 * yearsLL180FOV;

  double apertureLL162FOVThetamin115EMCmax184 = etaEEMCmax184 * genAreaLL162FOV *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLL162FOVThetamin115EMCmax184 = apertureLL162FOVThetamin115EMCmax184 * yearsLL162FOV;

  double exposureLLEmin17Thetamin115EMCmax184 = exposureLL180FOVThetamin115EMCmax184 + exposureLL162FOVThetamin115EMCmax184;

  double apertureHEATThetamin115EMCmax184 = etaEHEATEMCmax184 * genAreaHEAT *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureHEATThetamin115EMCmax184 = apertureHEATThetamin115EMCmax184 * yearsHEAT;


  double Exposure4EyesThetamin115EMCmax184 = exposureCoihuecoThetamin115EMCmax184 + exposureLMThetamin115EMCmax184 +
                                            exposureLAThetamin115EMCmax184 + exposureLLEmin17Thetamin115EMCmax184 +	exposureHEATThetamin115EMCmax184;

  Exposure4EyesAllEnergiesThetamin115H0.push_back(Exposure4EyesThetamin115EMCmax184);


  double exposureCoihuecoThetamin115EMCmax184Rgt1 = etaEEMCmax184RFdgt1km * genAreaCORgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;
  double exposureCoihuecoThetamin115EMCmax184Rgt2 = etaEEMCmax184RFdgt2km * genAreaCORgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;
  double exposureCoihuecoThetamin115EMCmax184Rgt3 = etaEEMCmax184RFdgt3km * genAreaCORgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;

  double exposureLMThetamin115EMCmax184Rgt1 = etaEEMCmax184RFdgt1km * genAreaLMRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;
  double exposureLMThetamin115EMCmax184Rgt2 = etaEEMCmax184RFdgt2km * genAreaLMRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;
  double exposureLMThetamin115EMCmax184Rgt3 = etaEEMCmax184RFdgt3km * genAreaLMRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;

  double exposureLAThetamin115EMCmax184Rgt1 = etaEEMCmax184RFdgt1km * genAreaLARgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;
  double exposureLAThetamin115EMCmax184Rgt2 = etaEEMCmax184RFdgt2km * genAreaLARgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;
  double exposureLAThetamin115EMCmax184Rgt3 = etaEEMCmax184RFdgt3km * genAreaLARgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;

  double exposureLL180FOVThetamin115EMCmax184Rgt1 = etaEEMCmax184RFdgt1km * genAreaLL180FOVRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;
  double exposureLL180FOVThetamin115EMCmax184Rgt2 = etaEEMCmax184RFdgt2km * genAreaLL180FOVRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;
  double exposureLL180FOVThetamin115EMCmax184Rgt3 = etaEEMCmax184RFdgt3km * genAreaLL180FOVRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;

  double exposureLL162FOVThetamin115EMCmax184Rgt1 = etaEEMCmax184RFdgt1km * genAreaLL162FOVRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;
  double exposureLL162FOVThetamin115EMCmax184Rgt2 = etaEEMCmax184RFdgt2km * genAreaLL162FOVRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;
  double exposureLL162FOVThetamin115EMCmax184Rgt3 = etaEEMCmax184RFdgt3km * genAreaLL162FOVRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;

  double exposureLLEmin17Thetamin115EMCmax184Rgt1 =  exposureLL180FOVThetamin115EMCmax184Rgt1 + exposureLL162FOVThetamin115EMCmax184Rgt1;
  double exposureLLEmin17Thetamin115EMCmax184Rgt2 =  exposureLL180FOVThetamin115EMCmax184Rgt2 + exposureLL162FOVThetamin115EMCmax184Rgt2;
  double exposureLLEmin17Thetamin115EMCmax184Rgt3 =  exposureLL180FOVThetamin115EMCmax184Rgt3 + exposureLL162FOVThetamin115EMCmax184Rgt3;



  double exposureCoihuecoThetamin115EMCmax184Rgt4 = etaEEMCmax184RFdgt4km * genAreaCORgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;
  double exposureCoihuecoThetamin115EMCmax184Rgt5 = etaEEMCmax184RFdgt5km * genAreaCORgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;

  double exposureLMThetamin115EMCmax184Rgt4 = etaEEMCmax184RFdgt4km * genAreaLMRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;
  double exposureLMThetamin115EMCmax184Rgt5 = etaEEMCmax184RFdgt5km * genAreaLMRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;

  double exposureLAThetamin115EMCmax184Rgt4 = etaEEMCmax184RFdgt4km * genAreaLARgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;
  double exposureLAThetamin115EMCmax184Rgt5 = etaEEMCmax184RFdgt5km * genAreaLARgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;

  double exposureLL180FOVThetamin115EMCmax184Rgt4 = etaEEMCmax184RFdgt4km * genAreaLL180FOVRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;
  double exposureLL180FOVThetamin115EMCmax184Rgt5 = etaEEMCmax184RFdgt5km * genAreaLL180FOVRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;

  double exposureLL162FOVThetamin115EMCmax184Rgt4 = etaEEMCmax184RFdgt4km * genAreaLL162FOVRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;
  double exposureLL162FOVThetamin115EMCmax184Rgt5 = etaEEMCmax184RFdgt5km * genAreaLL162FOVRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;

  double exposureLLEmin17Thetamin115EMCmax184Rgt4 =  exposureLL180FOVThetamin115EMCmax184Rgt4 + exposureLL162FOVThetamin115EMCmax184Rgt4;
  double exposureLLEmin17Thetamin115EMCmax184Rgt5 =  exposureLL180FOVThetamin115EMCmax184Rgt5 + exposureLL162FOVThetamin115EMCmax184Rgt5;


  double exposureHEATThetamin115EMCmax184Rgt1 = etaEHEATEMCmax184RFdgt1km* genAreaHEATRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCmax184Rgt2 = etaEHEATEMCmax184RFdgt2km* genAreaHEATRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCmax184Rgt3 = etaEHEATEMCmax184RFdgt3km* genAreaHEATRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCmax184Rgt4 = etaEHEATEMCmax184RFdgt4km* genAreaHEATRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCmax184Rgt5 = etaEHEATEMCmax184RFdgt5km* genAreaHEATRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;


  Exposure4EyesAllEnergiesThetamin115H0Rgt4.push_back( exposureCoihuecoThetamin115EMCmax184Rgt4 +   exposureLMThetamin115EMCmax184Rgt4
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax184Rgt4 + exposureLLEmin17Thetamin115EMCmax184Rgt4
																													+ exposureHEATThetamin115EMCmax184Rgt4 );
  Exposure4EyesAllEnergiesThetamin115H0Rgt5.push_back( exposureCoihuecoThetamin115EMCmax184Rgt5 +   exposureLMThetamin115EMCmax184Rgt5
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax184Rgt5 + exposureLLEmin17Thetamin115EMCmax184Rgt5
																													+ exposureHEATThetamin115EMCmax184Rgt5);

  Exposure4EyesAllEnergiesThetamin115H0Rgt1.push_back( exposureCoihuecoThetamin115EMCmax184Rgt1 +   exposureLMThetamin115EMCmax184Rgt1
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax184Rgt1 + exposureLLEmin17Thetamin115EMCmax184Rgt1
																													+ exposureHEATThetamin115EMCmax184Rgt1);
  Exposure4EyesAllEnergiesThetamin115H0Rgt2.push_back( exposureCoihuecoThetamin115EMCmax184Rgt2 +   exposureLMThetamin115EMCmax184Rgt2
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax184Rgt2 + exposureLLEmin17Thetamin115EMCmax184Rgt2
																													+  exposureHEATThetamin115EMCmax184Rgt2);
  Exposure4EyesAllEnergiesThetamin115H0Rgt3.push_back( exposureCoihuecoThetamin115EMCmax184Rgt3 +   exposureLMThetamin115EMCmax184Rgt3
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax184Rgt3 + exposureLLEmin17Thetamin115EMCmax184Rgt3
																													+  exposureHEATThetamin115EMCmax184Rgt3);

 EnergyRangeVector.push_back(18.3);

 double etaErrorExposurePlusEMCmax184 ;
 double etaErrorCOPlusEMCmax184;
 double etaErrorLMPlusEMCmax184;
 double etaErrorLAPlusEMCmax184;
 double etaErrorLLPlusEMCmax184;
 double etaErrorHEATPlusEMCmax184;

 if( etaEEMCmax184!=0)
 		{
 		etaErrorCOPlusEMCmax184 = (sqrt(EventsWithErecCOEMCmax184 ) / GeneratedEventsEMCmax184 ) * (exposureCoihuecoThetamin115EMCmax184 /  etaEEMCmax184) ;
 		etaErrorLMPlusEMCmax184 = ( sqrt(EventsWithErecCOEMCmax184 ) / GeneratedEventsEMCmax184 ) * (exposureLMThetamin115EMCmax184) /  etaEEMCmax184;
 		etaErrorLAPlusEMCmax184 = ( sqrt(EventsWithErecCOEMCmax184 ) / GeneratedEventsEMCmax184 ) * (exposureLAThetamin115EMCmax184)/  etaEEMCmax184 ;
 		etaErrorLLPlusEMCmax184 = (sqrt(EventsWithErecCOEMCmax184 ) / GeneratedEventsEMCmax184 ) *	(exposureLLEmin17Thetamin115EMCmax184) /  etaEEMCmax184;
 		}
 else
 		{
 			etaErrorCOPlusEMCmax184 = 0 ;
 			etaErrorLMPlusEMCmax184 = 0;
 			etaErrorLAPlusEMCmax184 =0 ;
 			etaErrorLLPlusEMCmax184 =0;
 		}
 	if(etaEHEATEMCmax184!=0)
 		etaErrorHEATPlusEMCmax184 = (sqrt(EventsWithErecHEATEMCmax184 ) / GeneratedEventsEMCmax184 ) * (exposureHEATThetamin115EMCmax184)/  etaEHEATEMCmax184 ;
 	else
 		etaErrorHEATPlusEMCmax184 = 0;


 etaErrorExposurePlusEMCmax184 = sqrt(  etaErrorCOPlusEMCmax184*etaErrorCOPlusEMCmax184 + etaErrorLMPlusEMCmax184*etaErrorLMPlusEMCmax184 +
 																etaErrorLAPlusEMCmax184*etaErrorLAPlusEMCmax184 +  etaErrorLLPlusEMCmax184* etaErrorLLPlusEMCmax184
 																+etaErrorHEATPlusEMCmax184*etaErrorHEATPlusEMCmax184);

 cout<<" E=17  "<<"Error Total Exposure  "<<etaErrorExposurePlusEMCmax184 <<endl;

 cout<<"exposure CO: "<<exposureCoihuecoThetamin115EMCmax184 << " error: "<<etaErrorCOPlusEMCmax184<<endl;
 cout<<"exposure LA: "<<exposureLAThetamin115EMCmax184 << " error: "<<etaErrorLAPlusEMCmax184<<endl;
 cout<<"exposure LM: "<<exposureLMThetamin115EMCmax184 << " error: "<<etaErrorLMPlusEMCmax184<<endl;
 cout<<"exposure LL: "<<exposureLLEmin17Thetamin115EMCmax184 << " error: "<<etaErrorLLPlusEMCmax184<<endl;
 cout<<"exposure HEAT: "<<exposureHEATThetamin115EMCmax184 << " error: "<<etaErrorHEATPlusEMCmax184<<endl;


 ErrorExposurePlus.push_back(etaErrorExposurePlusEMCmax184);


 double etaErrorExposureEMCmax184Rgt1;
 double etaErrorCOPlusEMCmax184Rgt1;
 double etaErrorLMPlusEMCmax184Rgt1;
 double etaErrorLAPlusEMCmax184Rgt1;
 double etaErrorLLPlusEMCmax184Rgt1;
 double etaErrorHEATPlusEMCmax184Rgt1;

 if(etaEEMCmax184RFdgt1km!=0)
 		{
 		etaErrorCOPlusEMCmax184Rgt1 = (sqrt(EventsWithErecCOEMCmax184RFdgt1km ) / GeneratedEventsEMCmax184RFdgt1km ) * (exposureCoihuecoThetamin115EMCmax184Rgt1 /  etaEEMCmax184RFdgt1km) ;
 		etaErrorLMPlusEMCmax184Rgt1 = ( sqrt(EventsWithErecCOEMCmax184RFdgt1km ) / GeneratedEventsEMCmax184RFdgt1km ) * (exposureLMThetamin115EMCmax184Rgt1) /  etaEEMCmax184RFdgt1km;
 		etaErrorLAPlusEMCmax184Rgt1 = ( sqrt(EventsWithErecCOEMCmax184RFdgt1km ) / GeneratedEventsEMCmax184RFdgt1km ) * (exposureLAThetamin115EMCmax184Rgt1)/  etaEEMCmax184RFdgt1km ;
 		etaErrorLLPlusEMCmax184Rgt1 = (sqrt(EventsWithErecCOEMCmax184RFdgt1km ) / GeneratedEventsEMCmax184RFdgt1km ) *	(exposureLLEmin17Thetamin115EMCmax184Rgt1) /  etaEEMCmax184RFdgt1km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax184Rgt1 =0;
 		etaErrorLMPlusEMCmax184Rgt1 = 0;
 		etaErrorLAPlusEMCmax184Rgt1 = 0 ;
 		etaErrorLLPlusEMCmax184Rgt1 =0;
 		}

 	if( etaEHEATEMCmax184RFdgt1km!=0)
 	etaErrorHEATPlusEMCmax184Rgt1 = (sqrt(EventsWithErecHEATEMCmax184RFdgt1km ) / GeneratedEventsEMCmax184RFdgt1km ) * (exposureHEATThetamin115EMCmax184Rgt1)/  etaEHEATEMCmax184RFdgt1km ;
 	else
 	etaErrorHEATPlusEMCmax184Rgt1 =0;

 etaErrorExposureEMCmax184Rgt1 = sqrt(  etaErrorCOPlusEMCmax184Rgt1*etaErrorCOPlusEMCmax184Rgt1 + etaErrorLMPlusEMCmax184Rgt1*etaErrorLMPlusEMCmax184Rgt1 +
 		etaErrorLAPlusEMCmax184Rgt1*etaErrorLAPlusEMCmax184Rgt1 +  etaErrorLLPlusEMCmax184Rgt1* etaErrorLLPlusEMCmax184Rgt1
 		+etaErrorHEATPlusEMCmax184Rgt1*etaErrorHEATPlusEMCmax184Rgt1);

 ErrorExposureRgt1.push_back(  etaErrorExposureEMCmax184Rgt1  );


 double etaErrorExposureEMCmax184Rgt2;
 double etaErrorCOPlusEMCmax184Rgt2;
 double etaErrorLMPlusEMCmax184Rgt2;
 double etaErrorLAPlusEMCmax184Rgt2;
 double etaErrorLLPlusEMCmax184Rgt2;
 double etaErrorHEATPlusEMCmax184Rgt2;

 if(etaEEMCmax184RFdgt2km!=0)
 		{
 		etaErrorCOPlusEMCmax184Rgt2 = (sqrt(EventsWithErecCOEMCmax184RFdgt2km ) / GeneratedEventsEMCmax184RFdgt2km ) * (exposureCoihuecoThetamin115EMCmax184Rgt2 /  etaEEMCmax184RFdgt2km) ;
 		etaErrorLMPlusEMCmax184Rgt2 = ( sqrt(EventsWithErecCOEMCmax184RFdgt2km ) / GeneratedEventsEMCmax184RFdgt2km ) * (exposureLMThetamin115EMCmax184Rgt2) /  etaEEMCmax184RFdgt2km;
 		etaErrorLAPlusEMCmax184Rgt2 = ( sqrt(EventsWithErecCOEMCmax184RFdgt2km ) / GeneratedEventsEMCmax184RFdgt2km ) * (exposureLAThetamin115EMCmax184Rgt2)/  etaEEMCmax184RFdgt2km ;
 		etaErrorLLPlusEMCmax184Rgt2 = (sqrt(EventsWithErecCOEMCmax184RFdgt2km ) / GeneratedEventsEMCmax184RFdgt2km ) *	(exposureLLEmin17Thetamin115EMCmax184Rgt2) /  etaEEMCmax184RFdgt2km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax184Rgt2 =0;
 		etaErrorLMPlusEMCmax184Rgt2 = 0;
 		etaErrorLAPlusEMCmax184Rgt2 = 0 ;
 		etaErrorLLPlusEMCmax184Rgt2 =0;
 		}

 	if( etaEHEATEMCmax184RFdgt2km!=0)
 	etaErrorHEATPlusEMCmax184Rgt2 = (sqrt(EventsWithErecHEATEMCmax184RFdgt2km ) / GeneratedEventsEMCmax184RFdgt2km ) * (exposureHEATThetamin115EMCmax184Rgt2)/  etaEHEATEMCmax184RFdgt2km ;
 	else
 	etaErrorHEATPlusEMCmax184Rgt2 =0;

 etaErrorExposureEMCmax184Rgt2 = sqrt(  etaErrorCOPlusEMCmax184Rgt2*etaErrorCOPlusEMCmax184Rgt2 + etaErrorLMPlusEMCmax184Rgt2*etaErrorLMPlusEMCmax184Rgt2 +
 		etaErrorLAPlusEMCmax184Rgt2*etaErrorLAPlusEMCmax184Rgt2 +  etaErrorLLPlusEMCmax184Rgt2* etaErrorLLPlusEMCmax184Rgt2
 		+etaErrorHEATPlusEMCmax184Rgt2*etaErrorHEATPlusEMCmax184Rgt2);

 ErrorExposureRgt2.push_back(  etaErrorExposureEMCmax184Rgt2  );

 double etaErrorExposureEMCmax184Rgt3;
 double etaErrorCOPlusEMCmax184Rgt3;
 double etaErrorLMPlusEMCmax184Rgt3;
 double etaErrorLAPlusEMCmax184Rgt3;
 double etaErrorLLPlusEMCmax184Rgt3;
 double etaErrorHEATPlusEMCmax184Rgt3;

 if(etaEEMCmax184RFdgt3km!=0)
 		{
 		etaErrorCOPlusEMCmax184Rgt3 = (sqrt(EventsWithErecCOEMCmax184RFdgt3km ) / GeneratedEventsEMCmax184RFdgt3km ) * (exposureCoihuecoThetamin115EMCmax184Rgt3 /  etaEEMCmax184RFdgt3km) ;
 		etaErrorLMPlusEMCmax184Rgt3 = ( sqrt(EventsWithErecCOEMCmax184RFdgt3km ) / GeneratedEventsEMCmax184RFdgt3km ) * (exposureLMThetamin115EMCmax184Rgt3) /  etaEEMCmax184RFdgt3km;
 		etaErrorLAPlusEMCmax184Rgt3 = ( sqrt(EventsWithErecCOEMCmax184RFdgt3km ) / GeneratedEventsEMCmax184RFdgt3km ) * (exposureLAThetamin115EMCmax184Rgt3)/  etaEEMCmax184RFdgt3km ;
 		etaErrorLLPlusEMCmax184Rgt3 = (sqrt(EventsWithErecCOEMCmax184RFdgt3km ) / GeneratedEventsEMCmax184RFdgt3km ) *	(exposureLLEmin17Thetamin115EMCmax184Rgt3) /  etaEEMCmax184RFdgt3km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax184Rgt3 =0;
 		etaErrorLMPlusEMCmax184Rgt3 = 0;
 		etaErrorLAPlusEMCmax184Rgt3 = 0 ;
 		etaErrorLLPlusEMCmax184Rgt3 =0;
 		}

 	if( etaEHEATEMCmax184RFdgt3km!=0)
 	etaErrorHEATPlusEMCmax184Rgt3 = (sqrt(EventsWithErecHEATEMCmax184RFdgt3km ) / GeneratedEventsEMCmax184RFdgt3km ) * (exposureHEATThetamin115EMCmax184Rgt3)/  etaEHEATEMCmax184RFdgt3km ;
 	else
 	etaErrorHEATPlusEMCmax184Rgt3 =0;

 etaErrorExposureEMCmax184Rgt3 = sqrt(  etaErrorCOPlusEMCmax184Rgt3*etaErrorCOPlusEMCmax184Rgt3 + etaErrorLMPlusEMCmax184Rgt3*etaErrorLMPlusEMCmax184Rgt3 +
 		etaErrorLAPlusEMCmax184Rgt3*etaErrorLAPlusEMCmax184Rgt3 +  etaErrorLLPlusEMCmax184Rgt3* etaErrorLLPlusEMCmax184Rgt3
 		+etaErrorHEATPlusEMCmax184Rgt3*etaErrorHEATPlusEMCmax184Rgt3);

 ErrorExposureRgt3.push_back(  etaErrorExposureEMCmax184Rgt3  );


 double etaErrorExposureEMCmax184Rgt4;
 double etaErrorCOPlusEMCmax184Rgt4;
 double etaErrorLMPlusEMCmax184Rgt4;
 double etaErrorLAPlusEMCmax184Rgt4;
 double etaErrorLLPlusEMCmax184Rgt4;
 double etaErrorHEATPlusEMCmax184Rgt4;

 if(etaEEMCmax184RFdgt4km!=0)
 		{
 		etaErrorCOPlusEMCmax184Rgt4 = (sqrt(EventsWithErecCOEMCmax184RFdgt4km ) / GeneratedEventsEMCmax184RFdgt4km ) * (exposureCoihuecoThetamin115EMCmax184Rgt4 /  etaEEMCmax184RFdgt4km) ;
 		etaErrorLMPlusEMCmax184Rgt4 = ( sqrt(EventsWithErecCOEMCmax184RFdgt4km ) / GeneratedEventsEMCmax184RFdgt4km ) * (exposureLMThetamin115EMCmax184Rgt4) /  etaEEMCmax184RFdgt4km;
 		etaErrorLAPlusEMCmax184Rgt4 = ( sqrt(EventsWithErecCOEMCmax184RFdgt4km ) / GeneratedEventsEMCmax184RFdgt4km ) * (exposureLAThetamin115EMCmax184Rgt4)/  etaEEMCmax184RFdgt4km ;
 		etaErrorLLPlusEMCmax184Rgt4 = (sqrt(EventsWithErecCOEMCmax184RFdgt4km ) / GeneratedEventsEMCmax184RFdgt4km ) *	(exposureLLEmin17Thetamin115EMCmax184Rgt4) /  etaEEMCmax184RFdgt4km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax184Rgt4 =0;
 		etaErrorLMPlusEMCmax184Rgt4 = 0;
 		etaErrorLAPlusEMCmax184Rgt4 = 0 ;
 		etaErrorLLPlusEMCmax184Rgt4 =0;
 		}

 	if( etaEHEATEMCmax184RFdgt4km!=0)
 	etaErrorHEATPlusEMCmax184Rgt4 = (sqrt(EventsWithErecHEATEMCmax184RFdgt4km ) / GeneratedEventsEMCmax184RFdgt4km ) * (exposureHEATThetamin115EMCmax184Rgt4)/  etaEHEATEMCmax184RFdgt4km ;
 	else
 	etaErrorHEATPlusEMCmax184Rgt4 =0;

 etaErrorExposureEMCmax184Rgt4 = sqrt(  etaErrorCOPlusEMCmax184Rgt4*etaErrorCOPlusEMCmax184Rgt4 + etaErrorLMPlusEMCmax184Rgt4*etaErrorLMPlusEMCmax184Rgt4 +
 		etaErrorLAPlusEMCmax184Rgt4*etaErrorLAPlusEMCmax184Rgt4 +  etaErrorLLPlusEMCmax184Rgt4* etaErrorLLPlusEMCmax184Rgt4
 		+etaErrorHEATPlusEMCmax184Rgt4*etaErrorHEATPlusEMCmax184Rgt4);

 ErrorExposureRgt4.push_back(  etaErrorExposureEMCmax184Rgt4  );


 double etaErrorExposureEMCmax184Rgt5;
 double etaErrorCOPlusEMCmax184Rgt5;
 double etaErrorLMPlusEMCmax184Rgt5;
 double etaErrorLAPlusEMCmax184Rgt5;
 double etaErrorLLPlusEMCmax184Rgt5;
 double etaErrorHEATPlusEMCmax184Rgt5;

 if(etaEEMCmax184RFdgt5km!=0)
 		{
 		etaErrorCOPlusEMCmax184Rgt5 = (sqrt(EventsWithErecCOEMCmax184RFdgt5km ) / GeneratedEventsEMCmax184RFdgt5km ) * (exposureCoihuecoThetamin115EMCmax184Rgt5 /  etaEEMCmax184RFdgt5km) ;
 		etaErrorLMPlusEMCmax184Rgt5 = ( sqrt(EventsWithErecCOEMCmax184RFdgt5km ) / GeneratedEventsEMCmax184RFdgt5km ) * (exposureLMThetamin115EMCmax184Rgt5) /  etaEEMCmax184RFdgt5km;
 		etaErrorLAPlusEMCmax184Rgt5 = ( sqrt(EventsWithErecCOEMCmax184RFdgt5km ) / GeneratedEventsEMCmax184RFdgt5km ) * (exposureLAThetamin115EMCmax184Rgt5)/  etaEEMCmax184RFdgt5km ;
 		etaErrorLLPlusEMCmax184Rgt5 = (sqrt(EventsWithErecCOEMCmax184RFdgt5km ) / GeneratedEventsEMCmax184RFdgt5km ) *	(exposureLLEmin17Thetamin115EMCmax184Rgt5) /  etaEEMCmax184RFdgt5km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax184Rgt5 =0;
 		etaErrorLMPlusEMCmax184Rgt5 = 0;
 		etaErrorLAPlusEMCmax184Rgt5 = 0 ;
 		etaErrorLLPlusEMCmax184Rgt5 =0;
 		}

 	if( etaEHEATEMCmax184RFdgt5km!=0)
 	etaErrorHEATPlusEMCmax184Rgt5 = (sqrt(EventsWithErecHEATEMCmax184RFdgt5km ) / GeneratedEventsEMCmax184RFdgt5km ) * (exposureHEATThetamin115EMCmax184Rgt5)/  etaEHEATEMCmax184RFdgt5km ;
 	else
 	etaErrorHEATPlusEMCmax184Rgt5 =0;

 etaErrorExposureEMCmax184Rgt5 = sqrt(  etaErrorCOPlusEMCmax184Rgt5*etaErrorCOPlusEMCmax184Rgt5 + etaErrorLMPlusEMCmax184Rgt5*etaErrorLMPlusEMCmax184Rgt5 +
 		etaErrorLAPlusEMCmax184Rgt5*etaErrorLAPlusEMCmax184Rgt5 +  etaErrorLLPlusEMCmax184Rgt5* etaErrorLLPlusEMCmax184Rgt5
 		+etaErrorHEATPlusEMCmax184Rgt5*etaErrorHEATPlusEMCmax184Rgt5);

 ErrorExposureRgt5.push_back(  etaErrorExposureEMCmax184Rgt5  );



double etaEEMCmax185; //etaE=recEvents/GenEvents ->reconstruction efficiency
etaEEMCmax185 = EventsWithErecCOEMCmax185 / GeneratedEventsEMCmax185;

double etaEHEATEMCmax185;
etaEHEATEMCmax185 = EventsWithErecHEATEMCmax185 / GeneratedEventsEMCmax185;
cout<<"etaE: (E=18.4  "<<etaEEMCmax185<<endl;
ErrorEvents.push_back(sqrt(EventsWithErecCOEMCmax185 ));

double etaEEMCmax185RFdgt1km;
etaEEMCmax185RFdgt1km = EventsWithErecCOEMCmax185RFdgt1km / GeneratedEventsEMCmax185RFdgt1km;
double etaEEMCmax185RFdgt2km;
etaEEMCmax185RFdgt2km = EventsWithErecCOEMCmax185RFdgt2km / GeneratedEventsEMCmax185RFdgt2km;
double etaEEMCmax185RFdgt3km;
etaEEMCmax185RFdgt3km = EventsWithErecCOEMCmax185RFdgt3km / GeneratedEventsEMCmax185RFdgt3km;
double etaEEMCmax185RFdgt4km;
etaEEMCmax185RFdgt4km = EventsWithErecCOEMCmax185RFdgt4km / GeneratedEventsEMCmax185RFdgt4km;
double etaEEMCmax185RFdgt5km;
etaEEMCmax185RFdgt5km = EventsWithErecCOEMCmax185RFdgt5km / GeneratedEventsEMCmax185RFdgt5km;

double etaEHEATEMCmax185RFdgt1km;
etaEHEATEMCmax185RFdgt1km = EventsWithErecHEATEMCmax185RFdgt1km / GeneratedEventsEMCmax185RFdgt1km;
double etaEHEATEMCmax185RFdgt2km;
etaEHEATEMCmax185RFdgt2km = EventsWithErecHEATEMCmax185RFdgt2km / GeneratedEventsEMCmax185RFdgt2km;
double etaEHEATEMCmax185RFdgt3km;
etaEHEATEMCmax185RFdgt3km = EventsWithErecHEATEMCmax185RFdgt3km / GeneratedEventsEMCmax185RFdgt3km;
double etaEHEATEMCmax185RFdgt4km;
etaEHEATEMCmax185RFdgt4km = EventsWithErecHEATEMCmax185RFdgt4km / GeneratedEventsEMCmax185RFdgt4km;
double etaEHEATEMCmax185RFdgt5km;
etaEHEATEMCmax185RFdgt5km = EventsWithErecHEATEMCmax185RFdgt5km / GeneratedEventsEMCmax185RFdgt5km;

//double etaErrorExposurePlusEMCmax185;
//etaErrorExposurePlusEMCmax185 = (EventsWithErecCOEMCmax185 + sqrt(EventsWithErecCOEMCmax185 )) / GeneratedEventsEMCmax185;
//
//double etaErrorExposureMinusEMCmax185;
//etaErrorExposureMinusEMCmax185 = (1/GeneratedEventsEMCmax185 *sqrt(EventsWithErecCOEMCmax185 + etaEEMCmax185 * etaEEMCmax185 * GeneratedEventsEMCmax185)) ;



cout<<"total gen events: "<<TotalNrGenEvents<<" in (18.4, 18.5) nr of gen Events = "<<GeneratedEventsEMCmax185<<endl;


cout<<"nr or reconstructed ev: "<<EventsWithErecCOEMCmax185<<endl;


double apertureCoihuecoThetamin115EMCmax185 = etaEEMCmax185 * genAreaCO *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureCoihuecoThetamin115EMCmax185 = apertureCoihuecoThetamin115EMCmax185 * yearsCO;

double apertureLMThetamin115EMCmax185 = etaEEMCmax185 * genAreaLM *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLMThetamin115EMCmax185 = apertureLMThetamin115EMCmax185 * yearsLM;

  double apertureLAThetamin115EMCmax185 = etaEEMCmax185 * genAreaLA *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLAThetamin115EMCmax185 = apertureLAThetamin115EMCmax185 * yearsLA;

    double apertureLL180FOVThetamin115EMCmax185 = etaEEMCmax185 * genAreaLL180FOV *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLL180FOVThetamin115EMCmax185 = apertureLL180FOVThetamin115EMCmax185 * yearsLL180FOV;

  double apertureLL162FOVThetamin115EMCmax185 = etaEEMCmax185 * genAreaLL162FOV *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLL162FOVThetamin115EMCmax185 = apertureLL162FOVThetamin115EMCmax185 * yearsLL162FOV;

  double exposureLLEmin17Thetamin115EMCmax185 = exposureLL180FOVThetamin115EMCmax185 + exposureLL162FOVThetamin115EMCmax185;

  double apertureHEATThetamin115EMCmax185 = etaEHEATEMCmax185 * genAreaHEAT *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureHEATThetamin115EMCmax185 = apertureHEATThetamin115EMCmax185 * yearsHEAT;


  double Exposure4EyesThetamin115EMCmax185 = exposureCoihuecoThetamin115EMCmax185 + exposureLMThetamin115EMCmax185 +
                                            exposureLAThetamin115EMCmax185 + exposureLLEmin17Thetamin115EMCmax185 +	exposureHEATThetamin115EMCmax185;

  Exposure4EyesAllEnergiesThetamin115H0.push_back(Exposure4EyesThetamin115EMCmax185);


  double exposureCoihuecoThetamin115EMCmax185Rgt1 = etaEEMCmax185RFdgt1km * genAreaCORgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;
  double exposureCoihuecoThetamin115EMCmax185Rgt2 = etaEEMCmax185RFdgt2km * genAreaCORgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;
  double exposureCoihuecoThetamin115EMCmax185Rgt3 = etaEEMCmax185RFdgt3km * genAreaCORgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;

  double exposureLMThetamin115EMCmax185Rgt1 = etaEEMCmax185RFdgt1km * genAreaLMRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;
  double exposureLMThetamin115EMCmax185Rgt2 = etaEEMCmax185RFdgt2km * genAreaLMRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;
  double exposureLMThetamin115EMCmax185Rgt3 = etaEEMCmax185RFdgt3km * genAreaLMRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;

  double exposureLAThetamin115EMCmax185Rgt1 = etaEEMCmax185RFdgt1km * genAreaLARgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;
  double exposureLAThetamin115EMCmax185Rgt2 = etaEEMCmax185RFdgt2km * genAreaLARgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;
  double exposureLAThetamin115EMCmax185Rgt3 = etaEEMCmax185RFdgt3km * genAreaLARgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;

  double exposureLL180FOVThetamin115EMCmax185Rgt1 = etaEEMCmax185RFdgt1km * genAreaLL180FOVRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;
  double exposureLL180FOVThetamin115EMCmax185Rgt2 = etaEEMCmax185RFdgt2km * genAreaLL180FOVRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;
  double exposureLL180FOVThetamin115EMCmax185Rgt3 = etaEEMCmax185RFdgt3km * genAreaLL180FOVRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;

  double exposureLL162FOVThetamin115EMCmax185Rgt1 = etaEEMCmax185RFdgt1km * genAreaLL162FOVRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;
  double exposureLL162FOVThetamin115EMCmax185Rgt2 = etaEEMCmax185RFdgt2km * genAreaLL162FOVRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;
  double exposureLL162FOVThetamin115EMCmax185Rgt3 = etaEEMCmax185RFdgt3km * genAreaLL162FOVRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;

  double exposureLLEmin17Thetamin115EMCmax185Rgt1 =  exposureLL180FOVThetamin115EMCmax185Rgt1 + exposureLL162FOVThetamin115EMCmax185Rgt1;
  double exposureLLEmin17Thetamin115EMCmax185Rgt2 =  exposureLL180FOVThetamin115EMCmax185Rgt2 + exposureLL162FOVThetamin115EMCmax185Rgt2;
  double exposureLLEmin17Thetamin115EMCmax185Rgt3 =  exposureLL180FOVThetamin115EMCmax185Rgt3 + exposureLL162FOVThetamin115EMCmax185Rgt3;



  double exposureCoihuecoThetamin115EMCmax185Rgt4 = etaEEMCmax185RFdgt4km * genAreaCORgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;
  double exposureCoihuecoThetamin115EMCmax185Rgt5 = etaEEMCmax185RFdgt5km * genAreaCORgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;

  double exposureLMThetamin115EMCmax185Rgt4 = etaEEMCmax185RFdgt4km * genAreaLMRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;
  double exposureLMThetamin115EMCmax185Rgt5 = etaEEMCmax185RFdgt5km * genAreaLMRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;

  double exposureLAThetamin115EMCmax185Rgt4 = etaEEMCmax185RFdgt4km * genAreaLARgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;
  double exposureLAThetamin115EMCmax185Rgt5 = etaEEMCmax185RFdgt5km * genAreaLARgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;

  double exposureLL180FOVThetamin115EMCmax185Rgt4 = etaEEMCmax185RFdgt4km * genAreaLL180FOVRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;
  double exposureLL180FOVThetamin115EMCmax185Rgt5 = etaEEMCmax185RFdgt5km * genAreaLL180FOVRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;

  double exposureLL162FOVThetamin115EMCmax185Rgt4 = etaEEMCmax185RFdgt4km * genAreaLL162FOVRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;
  double exposureLL162FOVThetamin115EMCmax185Rgt5 = etaEEMCmax185RFdgt5km * genAreaLL162FOVRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;

  double exposureLLEmin17Thetamin115EMCmax185Rgt4 =  exposureLL180FOVThetamin115EMCmax185Rgt4 + exposureLL162FOVThetamin115EMCmax185Rgt4;
  double exposureLLEmin17Thetamin115EMCmax185Rgt5 =  exposureLL180FOVThetamin115EMCmax185Rgt5 + exposureLL162FOVThetamin115EMCmax185Rgt5;


  double exposureHEATThetamin115EMCmax185Rgt1 = etaEHEATEMCmax185RFdgt1km* genAreaHEATRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCmax185Rgt2 = etaEHEATEMCmax185RFdgt2km* genAreaHEATRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCmax185Rgt3 = etaEHEATEMCmax185RFdgt3km* genAreaHEATRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCmax185Rgt4 = etaEHEATEMCmax185RFdgt4km* genAreaHEATRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCmax185Rgt5 = etaEHEATEMCmax185RFdgt5km* genAreaHEATRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;


  Exposure4EyesAllEnergiesThetamin115H0Rgt4.push_back( exposureCoihuecoThetamin115EMCmax185Rgt4 +   exposureLMThetamin115EMCmax185Rgt4
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax185Rgt4 + exposureLLEmin17Thetamin115EMCmax185Rgt4
																													+ exposureHEATThetamin115EMCmax185Rgt4 );
  Exposure4EyesAllEnergiesThetamin115H0Rgt5.push_back( exposureCoihuecoThetamin115EMCmax185Rgt5 +   exposureLMThetamin115EMCmax185Rgt5
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax185Rgt5 + exposureLLEmin17Thetamin115EMCmax185Rgt5
																													+ exposureHEATThetamin115EMCmax185Rgt5);

  Exposure4EyesAllEnergiesThetamin115H0Rgt1.push_back( exposureCoihuecoThetamin115EMCmax185Rgt1 +   exposureLMThetamin115EMCmax185Rgt1
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax185Rgt1 + exposureLLEmin17Thetamin115EMCmax185Rgt1
																													+ exposureHEATThetamin115EMCmax185Rgt1);
  Exposure4EyesAllEnergiesThetamin115H0Rgt2.push_back( exposureCoihuecoThetamin115EMCmax185Rgt2 +   exposureLMThetamin115EMCmax185Rgt2
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax185Rgt2 + exposureLLEmin17Thetamin115EMCmax185Rgt2
																													+  exposureHEATThetamin115EMCmax185Rgt2);
  Exposure4EyesAllEnergiesThetamin115H0Rgt3.push_back( exposureCoihuecoThetamin115EMCmax185Rgt3 +   exposureLMThetamin115EMCmax185Rgt3
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCmax185Rgt3 + exposureLLEmin17Thetamin115EMCmax185Rgt3
																													+  exposureHEATThetamin115EMCmax185Rgt3);

 EnergyRangeVector.push_back(18.4);

 double etaErrorExposurePlusEMCmax185 ;
 double etaErrorCOPlusEMCmax185;
 double etaErrorLMPlusEMCmax185;
 double etaErrorLAPlusEMCmax185;
 double etaErrorLLPlusEMCmax185;
 double etaErrorHEATPlusEMCmax185;

 if( etaEEMCmax185!=0)
 		{
 		etaErrorCOPlusEMCmax185 = (sqrt(EventsWithErecCOEMCmax185 ) / GeneratedEventsEMCmax185 ) * (exposureCoihuecoThetamin115EMCmax185 /  etaEEMCmax185) ;
 		etaErrorLMPlusEMCmax185 = ( sqrt(EventsWithErecCOEMCmax185 ) / GeneratedEventsEMCmax185 ) * (exposureLMThetamin115EMCmax185) /  etaEEMCmax185;
 		etaErrorLAPlusEMCmax185 = ( sqrt(EventsWithErecCOEMCmax185 ) / GeneratedEventsEMCmax185 ) * (exposureLAThetamin115EMCmax185)/  etaEEMCmax185 ;
 		etaErrorLLPlusEMCmax185 = (sqrt(EventsWithErecCOEMCmax185 ) / GeneratedEventsEMCmax185 ) *	(exposureLLEmin17Thetamin115EMCmax185) /  etaEEMCmax185;
 		}
 else
 		{
 			etaErrorCOPlusEMCmax185 = 0 ;
 			etaErrorLMPlusEMCmax185 = 0;
 			etaErrorLAPlusEMCmax185 =0 ;
 			etaErrorLLPlusEMCmax185 =0;
 		}
 	if(etaEHEATEMCmax185!=0)
 		etaErrorHEATPlusEMCmax185 = (sqrt(EventsWithErecHEATEMCmax185 ) / GeneratedEventsEMCmax185 ) * (exposureHEATThetamin115EMCmax185)/  etaEHEATEMCmax185 ;
 	else
 		etaErrorHEATPlusEMCmax185 = 0;


 etaErrorExposurePlusEMCmax185 = sqrt(  etaErrorCOPlusEMCmax185*etaErrorCOPlusEMCmax185 + etaErrorLMPlusEMCmax185*etaErrorLMPlusEMCmax185 +
 																etaErrorLAPlusEMCmax185*etaErrorLAPlusEMCmax185 +  etaErrorLLPlusEMCmax185* etaErrorLLPlusEMCmax185
 																+etaErrorHEATPlusEMCmax185*etaErrorHEATPlusEMCmax185);

 cout<<" E=17  "<<"Error Total Exposure  "<<etaErrorExposurePlusEMCmax185 <<endl;

 cout<<"exposure CO: "<<exposureCoihuecoThetamin115EMCmax185 << " error: "<<etaErrorCOPlusEMCmax185<<endl;
 cout<<"exposure LA: "<<exposureLAThetamin115EMCmax185 << " error: "<<etaErrorLAPlusEMCmax185<<endl;
 cout<<"exposure LM: "<<exposureLMThetamin115EMCmax185 << " error: "<<etaErrorLMPlusEMCmax185<<endl;
 cout<<"exposure LL: "<<exposureLLEmin17Thetamin115EMCmax185 << " error: "<<etaErrorLLPlusEMCmax185<<endl;
 cout<<"exposure HEAT: "<<exposureHEATThetamin115EMCmax185 << " error: "<<etaErrorHEATPlusEMCmax185<<endl;


 ErrorExposurePlus.push_back(etaErrorExposurePlusEMCmax185);


 double etaErrorExposureEMCmax185Rgt1;
 double etaErrorCOPlusEMCmax185Rgt1;
 double etaErrorLMPlusEMCmax185Rgt1;
 double etaErrorLAPlusEMCmax185Rgt1;
 double etaErrorLLPlusEMCmax185Rgt1;
 double etaErrorHEATPlusEMCmax185Rgt1;

 if(etaEEMCmax185RFdgt1km!=0)
 		{
 		etaErrorCOPlusEMCmax185Rgt1 = (sqrt(EventsWithErecCOEMCmax185RFdgt1km ) / GeneratedEventsEMCmax185RFdgt1km ) * (exposureCoihuecoThetamin115EMCmax185Rgt1 /  etaEEMCmax185RFdgt1km) ;
 		etaErrorLMPlusEMCmax185Rgt1 = ( sqrt(EventsWithErecCOEMCmax185RFdgt1km ) / GeneratedEventsEMCmax185RFdgt1km ) * (exposureLMThetamin115EMCmax185Rgt1) /  etaEEMCmax185RFdgt1km;
 		etaErrorLAPlusEMCmax185Rgt1 = ( sqrt(EventsWithErecCOEMCmax185RFdgt1km ) / GeneratedEventsEMCmax185RFdgt1km ) * (exposureLAThetamin115EMCmax185Rgt1)/  etaEEMCmax185RFdgt1km ;
 		etaErrorLLPlusEMCmax185Rgt1 = (sqrt(EventsWithErecCOEMCmax185RFdgt1km ) / GeneratedEventsEMCmax185RFdgt1km ) *	(exposureLLEmin17Thetamin115EMCmax185Rgt1) /  etaEEMCmax185RFdgt1km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax185Rgt1 =0;
 		etaErrorLMPlusEMCmax185Rgt1 = 0;
 		etaErrorLAPlusEMCmax185Rgt1 = 0 ;
 		etaErrorLLPlusEMCmax185Rgt1 =0;
 		}

 	if( etaEHEATEMCmax185RFdgt1km!=0)
 	etaErrorHEATPlusEMCmax185Rgt1 = (sqrt(EventsWithErecHEATEMCmax185RFdgt1km ) / GeneratedEventsEMCmax185RFdgt1km ) * (exposureHEATThetamin115EMCmax185Rgt1)/  etaEHEATEMCmax185RFdgt1km ;
 	else
 	etaErrorHEATPlusEMCmax185Rgt1 =0;

 etaErrorExposureEMCmax185Rgt1 = sqrt(  etaErrorCOPlusEMCmax185Rgt1*etaErrorCOPlusEMCmax185Rgt1 + etaErrorLMPlusEMCmax185Rgt1*etaErrorLMPlusEMCmax185Rgt1 +
 		etaErrorLAPlusEMCmax185Rgt1*etaErrorLAPlusEMCmax185Rgt1 +  etaErrorLLPlusEMCmax185Rgt1* etaErrorLLPlusEMCmax185Rgt1
 		+etaErrorHEATPlusEMCmax185Rgt1*etaErrorHEATPlusEMCmax185Rgt1);

 ErrorExposureRgt1.push_back(  etaErrorExposureEMCmax185Rgt1  );


 double etaErrorExposureEMCmax185Rgt2;
 double etaErrorCOPlusEMCmax185Rgt2;
 double etaErrorLMPlusEMCmax185Rgt2;
 double etaErrorLAPlusEMCmax185Rgt2;
 double etaErrorLLPlusEMCmax185Rgt2;
 double etaErrorHEATPlusEMCmax185Rgt2;

 if(etaEEMCmax185RFdgt2km!=0)
 		{
 		etaErrorCOPlusEMCmax185Rgt2 = (sqrt(EventsWithErecCOEMCmax185RFdgt2km ) / GeneratedEventsEMCmax185RFdgt2km ) * (exposureCoihuecoThetamin115EMCmax185Rgt2 /  etaEEMCmax185RFdgt2km) ;
 		etaErrorLMPlusEMCmax185Rgt2 = ( sqrt(EventsWithErecCOEMCmax185RFdgt2km ) / GeneratedEventsEMCmax185RFdgt2km ) * (exposureLMThetamin115EMCmax185Rgt2) /  etaEEMCmax185RFdgt2km;
 		etaErrorLAPlusEMCmax185Rgt2 = ( sqrt(EventsWithErecCOEMCmax185RFdgt2km ) / GeneratedEventsEMCmax185RFdgt2km ) * (exposureLAThetamin115EMCmax185Rgt2)/  etaEEMCmax185RFdgt2km ;
 		etaErrorLLPlusEMCmax185Rgt2 = (sqrt(EventsWithErecCOEMCmax185RFdgt2km ) / GeneratedEventsEMCmax185RFdgt2km ) *	(exposureLLEmin17Thetamin115EMCmax185Rgt2) /  etaEEMCmax185RFdgt2km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax185Rgt2 =0;
 		etaErrorLMPlusEMCmax185Rgt2 = 0;
 		etaErrorLAPlusEMCmax185Rgt2 = 0 ;
 		etaErrorLLPlusEMCmax185Rgt2 =0;
 		}

 	if( etaEHEATEMCmax185RFdgt2km!=0)
 	etaErrorHEATPlusEMCmax185Rgt2 = (sqrt(EventsWithErecHEATEMCmax185RFdgt2km ) / GeneratedEventsEMCmax185RFdgt2km ) * (exposureHEATThetamin115EMCmax185Rgt2)/  etaEHEATEMCmax185RFdgt2km ;
 	else
 	etaErrorHEATPlusEMCmax185Rgt2 =0;

 etaErrorExposureEMCmax185Rgt2 = sqrt(  etaErrorCOPlusEMCmax185Rgt2*etaErrorCOPlusEMCmax185Rgt2 + etaErrorLMPlusEMCmax185Rgt2*etaErrorLMPlusEMCmax185Rgt2 +
 		etaErrorLAPlusEMCmax185Rgt2*etaErrorLAPlusEMCmax185Rgt2 +  etaErrorLLPlusEMCmax185Rgt2* etaErrorLLPlusEMCmax185Rgt2
 		+etaErrorHEATPlusEMCmax185Rgt2*etaErrorHEATPlusEMCmax185Rgt2);

 ErrorExposureRgt2.push_back(  etaErrorExposureEMCmax185Rgt2  );

 double etaErrorExposureEMCmax185Rgt3;
 double etaErrorCOPlusEMCmax185Rgt3;
 double etaErrorLMPlusEMCmax185Rgt3;
 double etaErrorLAPlusEMCmax185Rgt3;
 double etaErrorLLPlusEMCmax185Rgt3;
 double etaErrorHEATPlusEMCmax185Rgt3;

 if(etaEEMCmax185RFdgt3km!=0)
 		{
 		etaErrorCOPlusEMCmax185Rgt3 = (sqrt(EventsWithErecCOEMCmax185RFdgt3km ) / GeneratedEventsEMCmax185RFdgt3km ) * (exposureCoihuecoThetamin115EMCmax185Rgt3 /  etaEEMCmax185RFdgt3km) ;
 		etaErrorLMPlusEMCmax185Rgt3 = ( sqrt(EventsWithErecCOEMCmax185RFdgt3km ) / GeneratedEventsEMCmax185RFdgt3km ) * (exposureLMThetamin115EMCmax185Rgt3) /  etaEEMCmax185RFdgt3km;
 		etaErrorLAPlusEMCmax185Rgt3 = ( sqrt(EventsWithErecCOEMCmax185RFdgt3km ) / GeneratedEventsEMCmax185RFdgt3km ) * (exposureLAThetamin115EMCmax185Rgt3)/  etaEEMCmax185RFdgt3km ;
 		etaErrorLLPlusEMCmax185Rgt3 = (sqrt(EventsWithErecCOEMCmax185RFdgt3km ) / GeneratedEventsEMCmax185RFdgt3km ) *	(exposureLLEmin17Thetamin115EMCmax185Rgt3) /  etaEEMCmax185RFdgt3km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax185Rgt3 =0;
 		etaErrorLMPlusEMCmax185Rgt3 = 0;
 		etaErrorLAPlusEMCmax185Rgt3 = 0 ;
 		etaErrorLLPlusEMCmax185Rgt3 =0;
 		}

 	if( etaEHEATEMCmax185RFdgt3km!=0)
 	etaErrorHEATPlusEMCmax185Rgt3 = (sqrt(EventsWithErecHEATEMCmax185RFdgt3km ) / GeneratedEventsEMCmax185RFdgt3km ) * (exposureHEATThetamin115EMCmax185Rgt3)/  etaEHEATEMCmax185RFdgt3km ;
 	else
 	etaErrorHEATPlusEMCmax185Rgt3 =0;

 etaErrorExposureEMCmax185Rgt3 = sqrt(  etaErrorCOPlusEMCmax185Rgt3*etaErrorCOPlusEMCmax185Rgt3 + etaErrorLMPlusEMCmax185Rgt3*etaErrorLMPlusEMCmax185Rgt3 +
 		etaErrorLAPlusEMCmax185Rgt3*etaErrorLAPlusEMCmax185Rgt3 +  etaErrorLLPlusEMCmax185Rgt3* etaErrorLLPlusEMCmax185Rgt3
 		+etaErrorHEATPlusEMCmax185Rgt3*etaErrorHEATPlusEMCmax185Rgt3);

 ErrorExposureRgt3.push_back(  etaErrorExposureEMCmax185Rgt3  );


 double etaErrorExposureEMCmax185Rgt4;
 double etaErrorCOPlusEMCmax185Rgt4;
 double etaErrorLMPlusEMCmax185Rgt4;
 double etaErrorLAPlusEMCmax185Rgt4;
 double etaErrorLLPlusEMCmax185Rgt4;
 double etaErrorHEATPlusEMCmax185Rgt4;

 if(etaEEMCmax185RFdgt4km!=0)
 		{
 		etaErrorCOPlusEMCmax185Rgt4 = (sqrt(EventsWithErecCOEMCmax185RFdgt4km ) / GeneratedEventsEMCmax185RFdgt4km ) * (exposureCoihuecoThetamin115EMCmax185Rgt4 /  etaEEMCmax185RFdgt4km) ;
 		etaErrorLMPlusEMCmax185Rgt4 = ( sqrt(EventsWithErecCOEMCmax185RFdgt4km ) / GeneratedEventsEMCmax185RFdgt4km ) * (exposureLMThetamin115EMCmax185Rgt4) /  etaEEMCmax185RFdgt4km;
 		etaErrorLAPlusEMCmax185Rgt4 = ( sqrt(EventsWithErecCOEMCmax185RFdgt4km ) / GeneratedEventsEMCmax185RFdgt4km ) * (exposureLAThetamin115EMCmax185Rgt4)/  etaEEMCmax185RFdgt4km ;
 		etaErrorLLPlusEMCmax185Rgt4 = (sqrt(EventsWithErecCOEMCmax185RFdgt4km ) / GeneratedEventsEMCmax185RFdgt4km ) *	(exposureLLEmin17Thetamin115EMCmax185Rgt4) /  etaEEMCmax185RFdgt4km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax185Rgt4 =0;
 		etaErrorLMPlusEMCmax185Rgt4 = 0;
 		etaErrorLAPlusEMCmax185Rgt4 = 0 ;
 		etaErrorLLPlusEMCmax185Rgt4 =0;
 		}

 	if( etaEHEATEMCmax185RFdgt4km!=0)
 	etaErrorHEATPlusEMCmax185Rgt4 = (sqrt(EventsWithErecHEATEMCmax185RFdgt4km ) / GeneratedEventsEMCmax185RFdgt4km ) * (exposureHEATThetamin115EMCmax185Rgt4)/  etaEHEATEMCmax185RFdgt4km ;
 	else
 	etaErrorHEATPlusEMCmax185Rgt4 =0;

 etaErrorExposureEMCmax185Rgt4 = sqrt(  etaErrorCOPlusEMCmax185Rgt4*etaErrorCOPlusEMCmax185Rgt4 + etaErrorLMPlusEMCmax185Rgt4*etaErrorLMPlusEMCmax185Rgt4 +
 		etaErrorLAPlusEMCmax185Rgt4*etaErrorLAPlusEMCmax185Rgt4 +  etaErrorLLPlusEMCmax185Rgt4* etaErrorLLPlusEMCmax185Rgt4
 		+etaErrorHEATPlusEMCmax185Rgt4*etaErrorHEATPlusEMCmax185Rgt4);

 ErrorExposureRgt4.push_back(  etaErrorExposureEMCmax185Rgt4  );


 double etaErrorExposureEMCmax185Rgt5;
 double etaErrorCOPlusEMCmax185Rgt5;
 double etaErrorLMPlusEMCmax185Rgt5;
 double etaErrorLAPlusEMCmax185Rgt5;
 double etaErrorLLPlusEMCmax185Rgt5;
 double etaErrorHEATPlusEMCmax185Rgt5;

 if(etaEEMCmax185RFdgt5km!=0)
 		{
 		etaErrorCOPlusEMCmax185Rgt5 = (sqrt(EventsWithErecCOEMCmax185RFdgt5km ) / GeneratedEventsEMCmax185RFdgt5km ) * (exposureCoihuecoThetamin115EMCmax185Rgt5 /  etaEEMCmax185RFdgt5km) ;
 		etaErrorLMPlusEMCmax185Rgt5 = ( sqrt(EventsWithErecCOEMCmax185RFdgt5km ) / GeneratedEventsEMCmax185RFdgt5km ) * (exposureLMThetamin115EMCmax185Rgt5) /  etaEEMCmax185RFdgt5km;
 		etaErrorLAPlusEMCmax185Rgt5 = ( sqrt(EventsWithErecCOEMCmax185RFdgt5km ) / GeneratedEventsEMCmax185RFdgt5km ) * (exposureLAThetamin115EMCmax185Rgt5)/  etaEEMCmax185RFdgt5km ;
 		etaErrorLLPlusEMCmax185Rgt5 = (sqrt(EventsWithErecCOEMCmax185RFdgt5km ) / GeneratedEventsEMCmax185RFdgt5km ) *	(exposureLLEmin17Thetamin115EMCmax185Rgt5) /  etaEEMCmax185RFdgt5km;
 		}
 else
 		{
 		etaErrorCOPlusEMCmax185Rgt5 =0;
 		etaErrorLMPlusEMCmax185Rgt5 = 0;
 		etaErrorLAPlusEMCmax185Rgt5 = 0 ;
 		etaErrorLLPlusEMCmax185Rgt5 =0;
 		}

 	if( etaEHEATEMCmax185RFdgt5km!=0)
 	etaErrorHEATPlusEMCmax185Rgt5 = (sqrt(EventsWithErecHEATEMCmax185RFdgt5km ) / GeneratedEventsEMCmax185RFdgt5km ) * (exposureHEATThetamin115EMCmax185Rgt5)/  etaEHEATEMCmax185RFdgt5km ;
 	else
 	etaErrorHEATPlusEMCmax185Rgt5 =0;

 etaErrorExposureEMCmax185Rgt5 = sqrt(  etaErrorCOPlusEMCmax185Rgt5*etaErrorCOPlusEMCmax185Rgt5 + etaErrorLMPlusEMCmax185Rgt5*etaErrorLMPlusEMCmax185Rgt5 +
 		etaErrorLAPlusEMCmax185Rgt5*etaErrorLAPlusEMCmax185Rgt5 +  etaErrorLLPlusEMCmax185Rgt5* etaErrorLLPlusEMCmax185Rgt5
 		+etaErrorHEATPlusEMCmax185Rgt5*etaErrorHEATPlusEMCmax185Rgt5);

 ErrorExposureRgt5.push_back(  etaErrorExposureEMCmax185Rgt5  );



double etaEEMCeq185; //etaE=recEvents/GenEvents ->reconstruction efficiency
etaEEMCeq185 = EventsWithErecCOEMCeq185 / GeneratedEventsEMCeq185;

double etaEHEATEMCeq185;
etaEHEATEMCeq185 = EventsWithErecHEATEMCeq185 / GeneratedEventsEMCeq185;
cout<<"etaE( E = 18.5 : "<<etaEEMCeq185<<endl;
ErrorEvents.push_back(sqrt(EventsWithErecCOEMCeq185 ));

double etaEEMCeq185RFdgt1km;
etaEEMCeq185RFdgt1km = EventsWithErecCOEMCeq185RFdgt1km / GeneratedEventsEMCeq185RFdgt1km;
double etaEEMCeq185RFdgt2km;
etaEEMCeq185RFdgt2km = EventsWithErecCOEMCeq185RFdgt2km / GeneratedEventsEMCeq185RFdgt2km;
double etaEEMCeq185RFdgt3km;
etaEEMCeq185RFdgt3km = EventsWithErecCOEMCeq185RFdgt3km / GeneratedEventsEMCeq185RFdgt3km;
double etaEEMCeq185RFdgt4km;
etaEEMCeq185RFdgt4km = EventsWithErecCOEMCeq185RFdgt4km / GeneratedEventsEMCeq185RFdgt4km;
double etaEEMCeq185RFdgt5km;
etaEEMCeq185RFdgt5km = EventsWithErecCOEMCeq185RFdgt5km / GeneratedEventsEMCeq185RFdgt5km;

double etaEHEATEMCeq185RFdgt1km;
etaEHEATEMCeq185RFdgt1km = EventsWithErecHEATEMCeq185RFdgt1km / GeneratedEventsEMCeq185RFdgt1km;
double etaEHEATEMCeq185RFdgt2km;
etaEHEATEMCeq185RFdgt2km = EventsWithErecHEATEMCeq185RFdgt2km / GeneratedEventsEMCeq185RFdgt2km;
double etaEHEATEMCeq185RFdgt3km;
etaEHEATEMCeq185RFdgt3km = EventsWithErecHEATEMCeq185RFdgt3km / GeneratedEventsEMCeq185RFdgt3km;
double etaEHEATEMCeq185RFdgt4km;
etaEHEATEMCeq185RFdgt4km = EventsWithErecHEATEMCeq185RFdgt4km / GeneratedEventsEMCeq185RFdgt4km;
double etaEHEATEMCeq185RFdgt5km;
etaEHEATEMCeq185RFdgt5km = EventsWithErecHEATEMCeq185RFdgt5km / GeneratedEventsEMCeq185RFdgt5km;

//double etaErrorExposurePlusEMCeq185;
//etaErrorExposurePlusEMCeq185 = (EventsWithErecCOEMCeq185 + sqrt(EventsWithErecCOEMCeq185 )) / GeneratedEventsEMCeq185;
//
//double etaErrorExposureMinusEMCeq185;
//etaErrorExposureMinusEMCeq185 = (1/GeneratedEventsEMCeq185 *sqrt(EventsWithErecCOEMCeq185 + etaEEMCeq185 * etaEEMCeq185 * GeneratedEventsEMCeq185)) ;



cout<<"total gen events: "<<TotalNrGenEvents<<" in (18.4, 18.5) nr of gen Events = "<<GeneratedEventsEMCeq185<<endl;


cout<<"nr or reconstructed ev: "<<EventsWithErecCOEMCeq185<<endl;



double apertureCoihuecoThetamin115EMCeq185 = etaEEMCeq185 * genAreaCO *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureCoihuecoThetamin115EMCeq185 = apertureCoihuecoThetamin115EMCeq185 * yearsCO;

double apertureLMThetamin115EMCeq185 = etaEEMCeq185 * genAreaLM *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLMThetamin115EMCeq185 = apertureLMThetamin115EMCeq185 * yearsLM;

  double apertureLAThetamin115EMCeq185 = etaEEMCeq185 * genAreaLA *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLAThetamin115EMCeq185 = apertureLAThetamin115EMCeq185 * yearsLA;

    double apertureLL180FOVThetamin115EMCeq185 = etaEEMCeq185 * genAreaLL180FOV *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLL180FOVThetamin115EMCeq185 = apertureLL180FOVThetamin115EMCeq185 * yearsLL180FOV;

  double apertureLL162FOVThetamin115EMCeq185 = etaEEMCeq185 * genAreaLL162FOV *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureLL162FOVThetamin115EMCeq185 = apertureLL162FOVThetamin115EMCeq185 * yearsLL162FOV;

  double exposureLLEmin17Thetamin115EMCeq185 = exposureLL180FOVThetamin115EMCeq185 + exposureLL162FOVThetamin115EMCeq185;

  double apertureHEATThetamin115EMCeq185 = etaEHEATEMCeq185 * genAreaHEAT *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2));
  double exposureHEATThetamin115EMCeq185 = apertureHEATThetamin115EMCeq185 * yearsHEAT;


  double Exposure4EyesThetamin115EMCeq185 = exposureCoihuecoThetamin115EMCeq185 + exposureLMThetamin115EMCeq185 +
                                            exposureLAThetamin115EMCeq185 + exposureLLEmin17Thetamin115EMCeq185 +	exposureHEATThetamin115EMCeq185;

  Exposure4EyesAllEnergiesThetamin115H0.push_back(Exposure4EyesThetamin115EMCeq185);


  double exposureCoihuecoThetamin115EMCeq185Rgt1 = etaEEMCeq185RFdgt1km * genAreaCORgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;
  double exposureCoihuecoThetamin115EMCeq185Rgt2 = etaEEMCeq185RFdgt2km * genAreaCORgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;
  double exposureCoihuecoThetamin115EMCeq185Rgt3 = etaEEMCeq185RFdgt3km * genAreaCORgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;

  double exposureLMThetamin115EMCeq185Rgt1 = etaEEMCeq185RFdgt1km * genAreaLMRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;
  double exposureLMThetamin115EMCeq185Rgt2 = etaEEMCeq185RFdgt2km * genAreaLMRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;
  double exposureLMThetamin115EMCeq185Rgt3 = etaEEMCeq185RFdgt3km * genAreaLMRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;

  double exposureLAThetamin115EMCeq185Rgt1 = etaEEMCeq185RFdgt1km * genAreaLARgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;
  double exposureLAThetamin115EMCeq185Rgt2 = etaEEMCeq185RFdgt2km * genAreaLARgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;
  double exposureLAThetamin115EMCeq185Rgt3 = etaEEMCeq185RFdgt3km * genAreaLARgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;

  double exposureLL180FOVThetamin115EMCeq185Rgt1 = etaEEMCeq185RFdgt1km * genAreaLL180FOVRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;
  double exposureLL180FOVThetamin115EMCeq185Rgt2 = etaEEMCeq185RFdgt2km * genAreaLL180FOVRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;
  double exposureLL180FOVThetamin115EMCeq185Rgt3 = etaEEMCeq185RFdgt3km * genAreaLL180FOVRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;

  double exposureLL162FOVThetamin115EMCeq185Rgt1 = etaEEMCeq185RFdgt1km * genAreaLL162FOVRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;
  double exposureLL162FOVThetamin115EMCeq185Rgt2 = etaEEMCeq185RFdgt2km * genAreaLL162FOVRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;
  double exposureLL162FOVThetamin115EMCeq185Rgt3 = etaEEMCeq185RFdgt3km * genAreaLL162FOVRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;

  double exposureLLEmin17Thetamin115EMCeq185Rgt1 =  exposureLL180FOVThetamin115EMCeq185Rgt1 + exposureLL162FOVThetamin115EMCeq185Rgt1;
  double exposureLLEmin17Thetamin115EMCeq185Rgt2 =  exposureLL180FOVThetamin115EMCeq185Rgt2 + exposureLL162FOVThetamin115EMCeq185Rgt2;
  double exposureLLEmin17Thetamin115EMCeq185Rgt3 =  exposureLL180FOVThetamin115EMCeq185Rgt3 + exposureLL162FOVThetamin115EMCeq185Rgt3;



  double exposureCoihuecoThetamin115EMCeq185Rgt4 = etaEEMCeq185RFdgt4km * genAreaCORgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;
  double exposureCoihuecoThetamin115EMCeq185Rgt5 = etaEEMCeq185RFdgt5km * genAreaCORgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsCO;

  double exposureLMThetamin115EMCeq185Rgt4 = etaEEMCeq185RFdgt4km * genAreaLMRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;
  double exposureLMThetamin115EMCeq185Rgt5 = etaEEMCeq185RFdgt5km * genAreaLMRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLM;

  double exposureLAThetamin115EMCeq185Rgt4 = etaEEMCeq185RFdgt4km * genAreaLARgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;
  double exposureLAThetamin115EMCeq185Rgt5 = etaEEMCeq185RFdgt5km * genAreaLARgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsLA;

  double exposureLL180FOVThetamin115EMCeq185Rgt4 = etaEEMCeq185RFdgt4km * genAreaLL180FOVRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;
  double exposureLL180FOVThetamin115EMCeq185Rgt5 = etaEEMCeq185RFdgt5km * genAreaLL180FOVRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL180FOV;

  double exposureLL162FOVThetamin115EMCeq185Rgt4 = etaEEMCeq185RFdgt4km * genAreaLL162FOVRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;
  double exposureLL162FOVThetamin115EMCeq185Rgt5 = etaEEMCeq185RFdgt5km * genAreaLL162FOVRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) * yearsLL162FOV;

  double exposureLLEmin17Thetamin115EMCeq185Rgt4 =  exposureLL180FOVThetamin115EMCeq185Rgt4 + exposureLL162FOVThetamin115EMCeq185Rgt4;
  double exposureLLEmin17Thetamin115EMCeq185Rgt5 =  exposureLL180FOVThetamin115EMCeq185Rgt5 + exposureLL162FOVThetamin115EMCeq185Rgt5;


  double exposureHEATThetamin115EMCeq185Rgt1 = etaEHEATEMCeq185RFdgt1km* genAreaHEATRgt1 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCeq185Rgt2 = etaEHEATEMCeq185RFdgt2km* genAreaHEATRgt2 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCeq185Rgt3 = etaEHEATEMCeq185RFdgt3km* genAreaHEATRgt3 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCeq185Rgt4 = etaEHEATEMCeq185RFdgt4km* genAreaHEATRgt4 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;
  double exposureHEATThetamin115EMCeq185Rgt5 = etaEHEATEMCeq185RFdgt5km* genAreaHEATRgt5 *  pi * 2 *1/2 * ( pow( cos( 130*pi/180),2) - pow(cos (115*pi/180) ,2)) *  yearsHEAT;


  Exposure4EyesAllEnergiesThetamin115H0Rgt4.push_back( exposureCoihuecoThetamin115EMCeq185Rgt4 +   exposureLMThetamin115EMCeq185Rgt4
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCeq185Rgt4 + exposureLLEmin17Thetamin115EMCeq185Rgt4
																													+ exposureHEATThetamin115EMCeq185Rgt4 );
  Exposure4EyesAllEnergiesThetamin115H0Rgt5.push_back( exposureCoihuecoThetamin115EMCeq185Rgt5 +   exposureLMThetamin115EMCeq185Rgt5
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCeq185Rgt5 + exposureLLEmin17Thetamin115EMCeq185Rgt5
																													+ exposureHEATThetamin115EMCeq185Rgt5);

  Exposure4EyesAllEnergiesThetamin115H0Rgt1.push_back( exposureCoihuecoThetamin115EMCeq185Rgt1 +   exposureLMThetamin115EMCeq185Rgt1
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCeq185Rgt1 + exposureLLEmin17Thetamin115EMCeq185Rgt1
																													+ exposureHEATThetamin115EMCeq185Rgt1);
  Exposure4EyesAllEnergiesThetamin115H0Rgt2.push_back( exposureCoihuecoThetamin115EMCeq185Rgt2 +   exposureLMThetamin115EMCeq185Rgt2
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCeq185Rgt2 + exposureLLEmin17Thetamin115EMCeq185Rgt2
																													+  exposureHEATThetamin115EMCeq185Rgt2);
  Exposure4EyesAllEnergiesThetamin115H0Rgt3.push_back( exposureCoihuecoThetamin115EMCeq185Rgt3 +   exposureLMThetamin115EMCeq185Rgt3
		  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	+ exposureLAThetamin115EMCeq185Rgt3 + exposureLLEmin17Thetamin115EMCeq185Rgt3
																													+  exposureHEATThetamin115EMCeq185Rgt3);

 EnergyRangeVector.push_back(18.5);

 double etaErrorExposurePlusEMCeq185 ;
 double etaErrorCOPlusEMCeq185;
 double etaErrorLMPlusEMCeq185;
 double etaErrorLAPlusEMCeq185;
 double etaErrorLLPlusEMCeq185;
 double etaErrorHEATPlusEMCeq185;

 if( etaEEMCeq185!=0)
 		{
 		etaErrorCOPlusEMCeq185 = (sqrt(EventsWithErecCOEMCeq185 ) / GeneratedEventsEMCeq185 ) * (exposureCoihuecoThetamin115EMCeq185 /  etaEEMCeq185) ;
 		etaErrorLMPlusEMCeq185 = ( sqrt(EventsWithErecCOEMCeq185 ) / GeneratedEventsEMCeq185 ) * (exposureLMThetamin115EMCeq185) /  etaEEMCeq185;
 		etaErrorLAPlusEMCeq185 = ( sqrt(EventsWithErecCOEMCeq185 ) / GeneratedEventsEMCeq185 ) * (exposureLAThetamin115EMCeq185)/  etaEEMCeq185 ;
 		etaErrorLLPlusEMCeq185 = (sqrt(EventsWithErecCOEMCeq185 ) / GeneratedEventsEMCeq185 ) *	(exposureLLEmin17Thetamin115EMCeq185) /  etaEEMCeq185;
 		}
 else
 		{
 			etaErrorCOPlusEMCeq185 = 0 ;
 			etaErrorLMPlusEMCeq185 = 0;
 			etaErrorLAPlusEMCeq185 =0 ;
 			etaErrorLLPlusEMCeq185 =0;
 		}
 	if(etaEHEATEMCeq185!=0)
 		etaErrorHEATPlusEMCeq185 = (sqrt(EventsWithErecHEATEMCeq185 ) / GeneratedEventsEMCeq185 ) * (exposureHEATThetamin115EMCeq185)/  etaEHEATEMCeq185 ;
 	else
 		etaErrorHEATPlusEMCeq185 = 0;


 etaErrorExposurePlusEMCeq185 = sqrt(  etaErrorCOPlusEMCeq185*etaErrorCOPlusEMCeq185 + etaErrorLMPlusEMCeq185*etaErrorLMPlusEMCeq185 +
 																etaErrorLAPlusEMCeq185*etaErrorLAPlusEMCeq185 +  etaErrorLLPlusEMCeq185* etaErrorLLPlusEMCeq185
 																+etaErrorHEATPlusEMCeq185*etaErrorHEATPlusEMCeq185);

 cout<<" E=17  "<<"Error Total Exposure  "<<etaErrorExposurePlusEMCeq185 <<endl;

 cout<<"exposure CO: "<<exposureCoihuecoThetamin115EMCeq185 << " error: "<<etaErrorCOPlusEMCeq185<<endl;
 cout<<"exposure LA: "<<exposureLAThetamin115EMCeq185 << " error: "<<etaErrorLAPlusEMCeq185<<endl;
 cout<<"exposure LM: "<<exposureLMThetamin115EMCeq185 << " error: "<<etaErrorLMPlusEMCeq185<<endl;
 cout<<"exposure LL: "<<exposureLLEmin17Thetamin115EMCeq185 << " error: "<<etaErrorLLPlusEMCeq185<<endl;
 cout<<"exposure HEAT: "<<exposureHEATThetamin115EMCeq185 << " error: "<<etaErrorHEATPlusEMCeq185<<endl;


 ErrorExposurePlus.push_back(etaErrorExposurePlusEMCeq185);


 double etaErrorExposureEMCeq185Rgt1;
 double etaErrorCOPlusEMCeq185Rgt1;
 double etaErrorLMPlusEMCeq185Rgt1;
 double etaErrorLAPlusEMCeq185Rgt1;
 double etaErrorLLPlusEMCeq185Rgt1;
 double etaErrorHEATPlusEMCeq185Rgt1;

 if(etaEEMCeq185RFdgt1km!=0)
 		{
 		etaErrorCOPlusEMCeq185Rgt1 = (sqrt(EventsWithErecCOEMCeq185RFdgt1km ) / GeneratedEventsEMCeq185RFdgt1km ) * (exposureCoihuecoThetamin115EMCeq185Rgt1 /  etaEEMCeq185RFdgt1km) ;
 		etaErrorLMPlusEMCeq185Rgt1 = ( sqrt(EventsWithErecCOEMCeq185RFdgt1km ) / GeneratedEventsEMCeq185RFdgt1km ) * (exposureLMThetamin115EMCeq185Rgt1) /  etaEEMCeq185RFdgt1km;
 		etaErrorLAPlusEMCeq185Rgt1 = ( sqrt(EventsWithErecCOEMCeq185RFdgt1km ) / GeneratedEventsEMCeq185RFdgt1km ) * (exposureLAThetamin115EMCeq185Rgt1)/  etaEEMCeq185RFdgt1km ;
 		etaErrorLLPlusEMCeq185Rgt1 = (sqrt(EventsWithErecCOEMCeq185RFdgt1km ) / GeneratedEventsEMCeq185RFdgt1km ) *	(exposureLLEmin17Thetamin115EMCeq185Rgt1) /  etaEEMCeq185RFdgt1km;
 		}
 else
 		{
 		etaErrorCOPlusEMCeq185Rgt1 =0;
 		etaErrorLMPlusEMCeq185Rgt1 = 0;
 		etaErrorLAPlusEMCeq185Rgt1 = 0 ;
 		etaErrorLLPlusEMCeq185Rgt1 =0;
 		}

 	if( etaEHEATEMCeq185RFdgt1km!=0)
 	etaErrorHEATPlusEMCeq185Rgt1 = (sqrt(EventsWithErecHEATEMCeq185RFdgt1km ) / GeneratedEventsEMCeq185RFdgt1km ) * (exposureHEATThetamin115EMCeq185Rgt1)/  etaEHEATEMCeq185RFdgt1km ;
 	else
 	etaErrorHEATPlusEMCeq185Rgt1 =0;

 etaErrorExposureEMCeq185Rgt1 = sqrt(  etaErrorCOPlusEMCeq185Rgt1*etaErrorCOPlusEMCeq185Rgt1 + etaErrorLMPlusEMCeq185Rgt1*etaErrorLMPlusEMCeq185Rgt1 +
 		etaErrorLAPlusEMCeq185Rgt1*etaErrorLAPlusEMCeq185Rgt1 +  etaErrorLLPlusEMCeq185Rgt1* etaErrorLLPlusEMCeq185Rgt1
 		+etaErrorHEATPlusEMCeq185Rgt1*etaErrorHEATPlusEMCeq185Rgt1);

 ErrorExposureRgt1.push_back(  etaErrorExposureEMCeq185Rgt1  );


 double etaErrorExposureEMCeq185Rgt2;
 double etaErrorCOPlusEMCeq185Rgt2;
 double etaErrorLMPlusEMCeq185Rgt2;
 double etaErrorLAPlusEMCeq185Rgt2;
 double etaErrorLLPlusEMCeq185Rgt2;
 double etaErrorHEATPlusEMCeq185Rgt2;

 if(etaEEMCeq185RFdgt2km!=0)
 		{
 		etaErrorCOPlusEMCeq185Rgt2 = (sqrt(EventsWithErecCOEMCeq185RFdgt2km ) / GeneratedEventsEMCeq185RFdgt2km ) * (exposureCoihuecoThetamin115EMCeq185Rgt2 /  etaEEMCeq185RFdgt2km) ;
 		etaErrorLMPlusEMCeq185Rgt2 = ( sqrt(EventsWithErecCOEMCeq185RFdgt2km ) / GeneratedEventsEMCeq185RFdgt2km ) * (exposureLMThetamin115EMCeq185Rgt2) /  etaEEMCeq185RFdgt2km;
 		etaErrorLAPlusEMCeq185Rgt2 = ( sqrt(EventsWithErecCOEMCeq185RFdgt2km ) / GeneratedEventsEMCeq185RFdgt2km ) * (exposureLAThetamin115EMCeq185Rgt2)/  etaEEMCeq185RFdgt2km ;
 		etaErrorLLPlusEMCeq185Rgt2 = (sqrt(EventsWithErecCOEMCeq185RFdgt2km ) / GeneratedEventsEMCeq185RFdgt2km ) *	(exposureLLEmin17Thetamin115EMCeq185Rgt2) /  etaEEMCeq185RFdgt2km;
 		}
 else
 		{
 		etaErrorCOPlusEMCeq185Rgt2 =0;
 		etaErrorLMPlusEMCeq185Rgt2 = 0;
 		etaErrorLAPlusEMCeq185Rgt2 = 0 ;
 		etaErrorLLPlusEMCeq185Rgt2 =0;
 		}

 	if( etaEHEATEMCeq185RFdgt2km!=0)
 	etaErrorHEATPlusEMCeq185Rgt2 = (sqrt(EventsWithErecHEATEMCeq185RFdgt2km ) / GeneratedEventsEMCeq185RFdgt2km ) * (exposureHEATThetamin115EMCeq185Rgt2)/  etaEHEATEMCeq185RFdgt2km ;
 	else
 	etaErrorHEATPlusEMCeq185Rgt2 =0;

 etaErrorExposureEMCeq185Rgt2 = sqrt(  etaErrorCOPlusEMCeq185Rgt2*etaErrorCOPlusEMCeq185Rgt2 + etaErrorLMPlusEMCeq185Rgt2*etaErrorLMPlusEMCeq185Rgt2 +
 		etaErrorLAPlusEMCeq185Rgt2*etaErrorLAPlusEMCeq185Rgt2 +  etaErrorLLPlusEMCeq185Rgt2* etaErrorLLPlusEMCeq185Rgt2
 		+etaErrorHEATPlusEMCeq185Rgt2*etaErrorHEATPlusEMCeq185Rgt2);

 ErrorExposureRgt2.push_back(  etaErrorExposureEMCeq185Rgt2  );

 double etaErrorExposureEMCeq185Rgt3;
 double etaErrorCOPlusEMCeq185Rgt3;
 double etaErrorLMPlusEMCeq185Rgt3;
 double etaErrorLAPlusEMCeq185Rgt3;
 double etaErrorLLPlusEMCeq185Rgt3;
 double etaErrorHEATPlusEMCeq185Rgt3;

 if(etaEEMCeq185RFdgt3km!=0)
 		{
 		etaErrorCOPlusEMCeq185Rgt3 = (sqrt(EventsWithErecCOEMCeq185RFdgt3km ) / GeneratedEventsEMCeq185RFdgt3km ) * (exposureCoihuecoThetamin115EMCeq185Rgt3 /  etaEEMCeq185RFdgt3km) ;
 		etaErrorLMPlusEMCeq185Rgt3 = ( sqrt(EventsWithErecCOEMCeq185RFdgt3km ) / GeneratedEventsEMCeq185RFdgt3km ) * (exposureLMThetamin115EMCeq185Rgt3) /  etaEEMCeq185RFdgt3km;
 		etaErrorLAPlusEMCeq185Rgt3 = ( sqrt(EventsWithErecCOEMCeq185RFdgt3km ) / GeneratedEventsEMCeq185RFdgt3km ) * (exposureLAThetamin115EMCeq185Rgt3)/  etaEEMCeq185RFdgt3km ;
 		etaErrorLLPlusEMCeq185Rgt3 = (sqrt(EventsWithErecCOEMCeq185RFdgt3km ) / GeneratedEventsEMCeq185RFdgt3km ) *	(exposureLLEmin17Thetamin115EMCeq185Rgt3) /  etaEEMCeq185RFdgt3km;
 		}
 else
 		{
 		etaErrorCOPlusEMCeq185Rgt3 =0;
 		etaErrorLMPlusEMCeq185Rgt3 = 0;
 		etaErrorLAPlusEMCeq185Rgt3 = 0 ;
 		etaErrorLLPlusEMCeq185Rgt3 =0;
 		}

 	if( etaEHEATEMCeq185RFdgt3km!=0)
 	etaErrorHEATPlusEMCeq185Rgt3 = (sqrt(EventsWithErecHEATEMCeq185RFdgt3km ) / GeneratedEventsEMCeq185RFdgt3km ) * (exposureHEATThetamin115EMCeq185Rgt3)/  etaEHEATEMCeq185RFdgt3km ;
 	else
 	etaErrorHEATPlusEMCeq185Rgt3 =0;

 etaErrorExposureEMCeq185Rgt3 = sqrt(  etaErrorCOPlusEMCeq185Rgt3*etaErrorCOPlusEMCeq185Rgt3 + etaErrorLMPlusEMCeq185Rgt3*etaErrorLMPlusEMCeq185Rgt3 +
 		etaErrorLAPlusEMCeq185Rgt3*etaErrorLAPlusEMCeq185Rgt3 +  etaErrorLLPlusEMCeq185Rgt3* etaErrorLLPlusEMCeq185Rgt3
 		+etaErrorHEATPlusEMCeq185Rgt3*etaErrorHEATPlusEMCeq185Rgt3);

 ErrorExposureRgt3.push_back(  etaErrorExposureEMCeq185Rgt3  );


 double etaErrorExposureEMCeq185Rgt4;
 double etaErrorCOPlusEMCeq185Rgt4;
 double etaErrorLMPlusEMCeq185Rgt4;
 double etaErrorLAPlusEMCeq185Rgt4;
 double etaErrorLLPlusEMCeq185Rgt4;
 double etaErrorHEATPlusEMCeq185Rgt4;

 if(etaEEMCeq185RFdgt4km!=0)
 		{
 		etaErrorCOPlusEMCeq185Rgt4 = (sqrt(EventsWithErecCOEMCeq185RFdgt4km ) / GeneratedEventsEMCeq185RFdgt4km ) * (exposureCoihuecoThetamin115EMCeq185Rgt4 /  etaEEMCeq185RFdgt4km) ;
 		etaErrorLMPlusEMCeq185Rgt4 = ( sqrt(EventsWithErecCOEMCeq185RFdgt4km ) / GeneratedEventsEMCeq185RFdgt4km ) * (exposureLMThetamin115EMCeq185Rgt4) /  etaEEMCeq185RFdgt4km;
 		etaErrorLAPlusEMCeq185Rgt4 = ( sqrt(EventsWithErecCOEMCeq185RFdgt4km ) / GeneratedEventsEMCeq185RFdgt4km ) * (exposureLAThetamin115EMCeq185Rgt4)/  etaEEMCeq185RFdgt4km ;
 		etaErrorLLPlusEMCeq185Rgt4 = (sqrt(EventsWithErecCOEMCeq185RFdgt4km ) / GeneratedEventsEMCeq185RFdgt4km ) *	(exposureLLEmin17Thetamin115EMCeq185Rgt4) /  etaEEMCeq185RFdgt4km;
 		}
 else
 		{
 		etaErrorCOPlusEMCeq185Rgt4 =0;
 		etaErrorLMPlusEMCeq185Rgt4 = 0;
 		etaErrorLAPlusEMCeq185Rgt4 = 0 ;
 		etaErrorLLPlusEMCeq185Rgt4 =0;
 		}

 	if( etaEHEATEMCeq185RFdgt4km!=0)
 	etaErrorHEATPlusEMCeq185Rgt4 = (sqrt(EventsWithErecHEATEMCeq185RFdgt4km ) / GeneratedEventsEMCeq185RFdgt4km ) * (exposureHEATThetamin115EMCeq185Rgt4)/  etaEHEATEMCeq185RFdgt4km ;
 	else
 	etaErrorHEATPlusEMCeq185Rgt4 =0;

 etaErrorExposureEMCeq185Rgt4 = sqrt(  etaErrorCOPlusEMCeq185Rgt4*etaErrorCOPlusEMCeq185Rgt4 + etaErrorLMPlusEMCeq185Rgt4*etaErrorLMPlusEMCeq185Rgt4 +
 		etaErrorLAPlusEMCeq185Rgt4*etaErrorLAPlusEMCeq185Rgt4 +  etaErrorLLPlusEMCeq185Rgt4* etaErrorLLPlusEMCeq185Rgt4
 		+etaErrorHEATPlusEMCeq185Rgt4*etaErrorHEATPlusEMCeq185Rgt4);

 ErrorExposureRgt4.push_back(  etaErrorExposureEMCeq185Rgt4  );


 double etaErrorExposureEMCeq185Rgt5;
 double etaErrorCOPlusEMCeq185Rgt5;
 double etaErrorLMPlusEMCeq185Rgt5;
 double etaErrorLAPlusEMCeq185Rgt5;
 double etaErrorLLPlusEMCeq185Rgt5;
 double etaErrorHEATPlusEMCeq185Rgt5;

 if(etaEEMCeq185RFdgt5km!=0)
 		{
 		etaErrorCOPlusEMCeq185Rgt5 = (sqrt(EventsWithErecCOEMCeq185RFdgt5km ) / GeneratedEventsEMCeq185RFdgt5km ) * (exposureCoihuecoThetamin115EMCeq185Rgt5 /  etaEEMCeq185RFdgt5km) ;
 		etaErrorLMPlusEMCeq185Rgt5 = ( sqrt(EventsWithErecCOEMCeq185RFdgt5km ) / GeneratedEventsEMCeq185RFdgt5km ) * (exposureLMThetamin115EMCeq185Rgt5) /  etaEEMCeq185RFdgt5km;
 		etaErrorLAPlusEMCeq185Rgt5 = ( sqrt(EventsWithErecCOEMCeq185RFdgt5km ) / GeneratedEventsEMCeq185RFdgt5km ) * (exposureLAThetamin115EMCeq185Rgt5)/  etaEEMCeq185RFdgt5km ;
 		etaErrorLLPlusEMCeq185Rgt5 = (sqrt(EventsWithErecCOEMCeq185RFdgt5km ) / GeneratedEventsEMCeq185RFdgt5km ) *	(exposureLLEmin17Thetamin115EMCeq185Rgt5) /  etaEEMCeq185RFdgt5km;
 		}
 else
 		{
 		etaErrorCOPlusEMCeq185Rgt5 =0;
 		etaErrorLMPlusEMCeq185Rgt5 = 0;
 		etaErrorLAPlusEMCeq185Rgt5 = 0 ;
 		etaErrorLLPlusEMCeq185Rgt5 =0;
 		}

 	if( etaEHEATEMCeq185RFdgt5km!=0)
 	etaErrorHEATPlusEMCeq185Rgt5 = (sqrt(EventsWithErecHEATEMCeq185RFdgt5km ) / GeneratedEventsEMCeq185RFdgt5km ) * (exposureHEATThetamin115EMCeq185Rgt5)/  etaEHEATEMCeq185RFdgt5km ;
 	else
 	etaErrorHEATPlusEMCeq185Rgt5 =0;

 etaErrorExposureEMCeq185Rgt5 = sqrt(  etaErrorCOPlusEMCeq185Rgt5*etaErrorCOPlusEMCeq185Rgt5 + etaErrorLMPlusEMCeq185Rgt5*etaErrorLMPlusEMCeq185Rgt5 +
 		etaErrorLAPlusEMCeq185Rgt5*etaErrorLAPlusEMCeq185Rgt5 +  etaErrorLLPlusEMCeq185Rgt5* etaErrorLLPlusEMCeq185Rgt5
 		+etaErrorHEATPlusEMCeq185Rgt5*etaErrorHEATPlusEMCeq185Rgt5);

 ErrorExposureRgt5.push_back(  etaErrorExposureEMCeq185Rgt5  );



for(int i=0; i<Exposure4EyesAllEnergiesThetamin115H0.size();i++)
  cout<<"E range: "<<EnergyRangeVector[i]<< "exposure: "<<Exposure4EyesAllEnergiesThetamin115H0[i]<<"+ Error: "<< ErrorExposurePlus[i]<<endl;


//TODO; For now i still need the up time of HEAT. TODO for HEAT
vector<double> ErorrEnergy;

for(int i=0; i< ErrorEvents.size(); i++)
  {ErorrEnergy.push_back(0);
  //cout<<ErrorEvents[i]<<endl;
}


vector<double> AverageFdDistance;
vector<double> ErrorDistance;

vector<double> TriggEvEMC17to175;
vector<double> TriggEvEMC175to18;
vector<double> TriggEvEMC18to185;

vector<double> GenEvEMC17to175;
vector<double> GenEvEMC175to18;
vector<double> GenEvEMC18to185;

vector<double> TriggEvOverGenEvEMC17to175;
vector<double> TriggEvOverGenEvEMC175to18;
vector<double> TriggEvOverGenEvEMC18to185;

vector<double> ErrorTriggEvOverGenEvEMC17to175;
vector<double> ErrorTriggEvOverGenEvEMC175to18;
vector<double> ErrorTriggEvOverGenEvEMC18to185;

for(int i=0; i<40; i++)
{double trigeventsEmc17to175=0;
double trigeventsEmc175to18=0;
double trigeventsEmc18to185=0;
	for (int j=0; j<VectorEVENTidCOThetamin115.size(); j++)
	{ 	double EnergyDouble = double(floor(VectorlgEMCCOThetamin115[j]*10.0 + 0.5))/10.0 ;
			if(EnergyDouble>=17 && EnergyDouble<=17.5)
			{
					if( floor(VectorDistanceFdCOThetamin115[j]) == i && VectorDistanceFdCOThetamin115[j] != -1  )
						{	trigeventsEmc17to175+=1;}
			}
			else if(EnergyDouble>17.5 && EnergyDouble<=18)
			{
					if( floor(VectorDistanceFdCOThetamin115[j]) == i && VectorDistanceFdCOThetamin115[j] != -1  )
						{	trigeventsEmc175to18+=1;}
			}
			else if(EnergyDouble>18 && EnergyDouble<=18.5)
				{
						if( floor(VectorDistanceFdCOThetamin115[j]) == i && VectorDistanceFdCOThetamin115[j] != -1  )
							{	trigeventsEmc18to185+=1;}
				}

	}
	TriggEvEMC17to175.push_back(trigeventsEmc17to175);
	TriggEvEMC175to18.push_back(trigeventsEmc175to18);
	TriggEvEMC18to185.push_back(trigeventsEmc18to185);
	AverageFdDistance.push_back(i+0.5);
	ErrorDistance.push_back(0.5);

}

for(int i=0; i<40; i++)
{double geneventsEmc17to175=0;
double geneventsEmc175to18=0;
double geneventsEmc18to185=0;
	for (int j=0; j<VectorEVENTidCOThetamin115.size(); j++)
	{ 	double EnergyDouble = double(floor(VectorlgEMCCOThetamin115[j]*10.0 + 0.5))/10.0 ;
			if(EnergyDouble>=17 && EnergyDouble<=17.5)
			{
					if( floor(VectorGenDistanceFdCOThetamin115[j]) == i )
						{	geneventsEmc17to175+=1;}
			}
			else if(EnergyDouble>17.5 && EnergyDouble<=18)
			{
				if( floor(VectorGenDistanceFdCOThetamin115[j]) == i )
						{	geneventsEmc175to18+=1;}
			}
			else if(EnergyDouble>18 && EnergyDouble<=18.5)
				{
				if( floor(VectorGenDistanceFdCOThetamin115[j]) == i )
							{	geneventsEmc18to185+=1;}
				}

	}
	GenEvEMC17to175.push_back(geneventsEmc17to175);
	GenEvEMC175to18.push_back(geneventsEmc175to18);
	GenEvEMC18to185.push_back(geneventsEmc18to185);

}

for(int i=0; i<GenEvEMC17to175.size();i++)
{
	 TriggEvOverGenEvEMC17to175.push_back( TriggEvEMC17to175[i]/GenEvEMC17to175[i]   );
	 TriggEvOverGenEvEMC175to18.push_back( TriggEvEMC175to18[i]/GenEvEMC175to18[i]   );
	 TriggEvOverGenEvEMC18to185.push_back( TriggEvEMC18to185[i]/GenEvEMC18to185[i]   );

	 ErrorTriggEvOverGenEvEMC17to175.push_back( sqrt(TriggEvEMC17to175[i]) / GenEvEMC17to175[i]  );
	 ErrorTriggEvOverGenEvEMC175to18.push_back( sqrt(TriggEvEMC175to18[i]) / GenEvEMC175to18[i]  );
	 ErrorTriggEvOverGenEvEMC18to185.push_back( sqrt(TriggEvEMC18to185[i]) / GenEvEMC18to185[i]  );
}

//for(int ik=0; ik<AverageFdDistance.size(); ik++)
//	cout<<"distance: "<<AverageFdDistance[ik]<<" trig ev 18 - 18.5 : "<<   TriggEvEMC18to185 [ik]<< "gen ev: "<<GenEvEMC18to185[ik]<<endl;




vector<double> ExposureCO1year;
ExposureCO1year.push_back( apertureCoihuecoThetamin115EMCmax171 );
ExposureCO1year.push_back(apertureCoihuecoThetamin115EMCmax172 );
ExposureCO1year.push_back(apertureCoihuecoThetamin115EMCmax173 );
ExposureCO1year.push_back(apertureCoihuecoThetamin115EMCmax174 );
ExposureCO1year.push_back(apertureCoihuecoThetamin115EMCmax175 );
ExposureCO1year.push_back(apertureCoihuecoThetamin115EMCmax176 );
ExposureCO1year.push_back(apertureCoihuecoThetamin115EMCmax177 );
ExposureCO1year.push_back(apertureCoihuecoThetamin115EMCmax178 );
ExposureCO1year.push_back(apertureCoihuecoThetamin115EMCmax179 );
ExposureCO1year.push_back(apertureCoihuecoThetamin115EMCmax18 );
ExposureCO1year.push_back(apertureCoihuecoThetamin115EMCmax181 );
ExposureCO1year.push_back(apertureCoihuecoThetamin115EMCmax182 );
ExposureCO1year.push_back(apertureCoihuecoThetamin115EMCmax183);
ExposureCO1year.push_back(apertureCoihuecoThetamin115EMCmax184 );
ExposureCO1year.push_back(apertureCoihuecoThetamin115EMCmax185 );
ExposureCO1year.push_back(apertureCoihuecoThetamin115EMCeq185);
cout<<"apertureCoihuecoThetamin115EMCeq185  "<< apertureCoihuecoThetamin115EMCeq185<<   endl;

vector<double> ErrorExposureCO1year;

ErrorExposureCO1year.push_back(etaErrorCOPlusEMCmax171/yearsCO);
ErrorExposureCO1year.push_back(etaErrorCOPlusEMCmax172/yearsCO);
ErrorExposureCO1year.push_back(etaErrorCOPlusEMCmax173/yearsCO);
ErrorExposureCO1year.push_back(etaErrorCOPlusEMCmax174/yearsCO);
ErrorExposureCO1year.push_back(etaErrorCOPlusEMCmax175/yearsCO);
ErrorExposureCO1year.push_back(etaErrorCOPlusEMCmax176/yearsCO);
ErrorExposureCO1year.push_back(etaErrorCOPlusEMCmax177/yearsCO);
ErrorExposureCO1year.push_back(etaErrorCOPlusEMCmax178/yearsCO);
ErrorExposureCO1year.push_back(etaErrorCOPlusEMCmax179/yearsCO);
ErrorExposureCO1year.push_back(etaErrorCOPlusEMCmax18/yearsCO);
ErrorExposureCO1year.push_back(etaErrorCOPlusEMCmax181/yearsCO);
ErrorExposureCO1year.push_back(etaErrorCOPlusEMCmax182/yearsCO);
ErrorExposureCO1year.push_back(etaErrorCOPlusEMCmax183/yearsCO);
ErrorExposureCO1year.push_back(etaErrorCOPlusEMCmax184/yearsCO);
ErrorExposureCO1year.push_back(etaErrorCOPlusEMCmax185/yearsCO);
ErrorExposureCO1year.push_back(etaErrorCOPlusEMCeq185/yearsCO);

cout<<" etaErrorCOPlusEMCeq185/yearsCO "<<etaErrorCOPlusEMCeq185/yearsCO<<endl;

vector<double> ExposureHEAT1year;
ExposureHEAT1year.push_back( apertureHEATThetamin115EMCmax171 );
ExposureHEAT1year.push_back(apertureHEATThetamin115EMCmax172 );
ExposureHEAT1year.push_back(apertureHEATThetamin115EMCmax173 );
ExposureHEAT1year.push_back(apertureHEATThetamin115EMCmax174 );
ExposureHEAT1year.push_back(apertureHEATThetamin115EMCmax175 );
ExposureHEAT1year.push_back(apertureHEATThetamin115EMCmax176 );
ExposureHEAT1year.push_back(apertureHEATThetamin115EMCmax177 );
ExposureHEAT1year.push_back(apertureHEATThetamin115EMCmax178 );
ExposureHEAT1year.push_back(apertureHEATThetamin115EMCmax179 );
ExposureHEAT1year.push_back(apertureHEATThetamin115EMCmax18 );
ExposureHEAT1year.push_back(apertureHEATThetamin115EMCmax181 );
ExposureHEAT1year.push_back(apertureHEATThetamin115EMCmax182 );
ExposureHEAT1year.push_back(apertureHEATThetamin115EMCmax183);
ExposureHEAT1year.push_back(apertureHEATThetamin115EMCmax184 );
ExposureHEAT1year.push_back(apertureHEATThetamin115EMCmax185 );
ExposureHEAT1year.push_back(apertureHEATThetamin115EMCeq185);
cout<<"apertureHEATThetamin115EMCeq185  "<< apertureHEATThetamin115EMCeq185<<   endl;

vector<double> ErrorExposureHEAT1year;

ErrorExposureHEAT1year.push_back(etaErrorHEATPlusEMCmax171/yearsHEAT);
ErrorExposureHEAT1year.push_back(etaErrorHEATPlusEMCmax172/yearsHEAT);
ErrorExposureHEAT1year.push_back(etaErrorHEATPlusEMCmax173/yearsHEAT);
ErrorExposureHEAT1year.push_back(etaErrorHEATPlusEMCmax174/yearsHEAT);
ErrorExposureHEAT1year.push_back(etaErrorHEATPlusEMCmax175/yearsHEAT);
ErrorExposureHEAT1year.push_back(etaErrorHEATPlusEMCmax176/yearsHEAT);
ErrorExposureHEAT1year.push_back(etaErrorHEATPlusEMCmax177/yearsHEAT);
ErrorExposureHEAT1year.push_back(etaErrorHEATPlusEMCmax178/yearsHEAT);
ErrorExposureHEAT1year.push_back(etaErrorHEATPlusEMCmax179/yearsHEAT);
ErrorExposureHEAT1year.push_back(etaErrorHEATPlusEMCmax18/yearsHEAT);
ErrorExposureHEAT1year.push_back(etaErrorHEATPlusEMCmax181/yearsHEAT);
ErrorExposureHEAT1year.push_back(etaErrorHEATPlusEMCmax182/yearsHEAT);
ErrorExposureHEAT1year.push_back(etaErrorHEATPlusEMCmax183/yearsHEAT);
ErrorExposureHEAT1year.push_back(etaErrorHEATPlusEMCmax184/yearsHEAT);
ErrorExposureHEAT1year.push_back(etaErrorHEATPlusEMCmax185/yearsHEAT);
ErrorExposureHEAT1year.push_back(etaErrorHEATPlusEMCeq185/yearsHEAT);







TH1F* Axis1 = new TH1F("Axis1","",100,0,520);

  TCanvas *Canvas1 = new TCanvas("Canvas1","Canvas name",200,10,700,400);  //sizes here so change the last 2 to make your plot whatever size you want

  TCanvas *Canvas2 = new TCanvas("Canvas2","Canvas name2",200,10,700,400);
  TCanvas *CanvasCOandHEATThetaMin115 = new TCanvas("CanvasCOandHEATThetaMin115","CanvasCOandHEATThetaMin115", 700,400);
  TCanvas *Canvas3 = new TCanvas("Canvas3","Canvas name3",200,10,700,400);
  TCanvas *Canvas4 = new TCanvas("Canvas4","Canvas name4",200,10,700,400);
  TCanvas *CanvasEnergydiff = new TCanvas("CanvasEnergydiff","Canvas Energydiff",200,10,700,400);
  TCanvas *CanvasSigmaEnergydiff = new TCanvas("CanvasSigmaEnergydiff","Canvas Sigma Energydiff",200,10,700,400);
  TCanvas *CanvasTEST = new TCanvas("CanvasTEST","CanvasTEST",200,10,700,400);

  CanvasSigmaEnergydiff->cd();



Canvas1->cd();
  Canvas1->SetRightMargin(0.02);//This changes the margins
  Canvas1->SetLeftMargin(0.175);
  Canvas1->SetTopMargin(0.02);
  Canvas1->SetBottomMargin(0.18);
  Canvas1->SetTicks(1,1);
  Axis1->GetYaxis()->SetRangeUser(0,30); //sets the Y axis range
  //Axis1->GetXaxis()->SetRangeUser(0,30); //sets the X axis range
  Axis1->GetYaxis()->SetLabelFont(132); //Nice font
  Axis1->GetYaxis()->SetTitleSize(.05); //changes the axis title size
  Axis1->GetYaxis()->CenterTitle(); //centers the axis title
  Axis1->GetYaxis()->SetTitle("#font[132]{Triggered Events}"); // This is the axis title uses latex code basically change '\alpha' for '#alpha' otherwist it is the same
  Axis1->GetYaxis()->SetTitleOffset(1.2); //distance between axis title and axis
  Axis1->GetXaxis()->SetTitleSize(.05);//changes the axis title size
  Axis1->GetXaxis()->CenterTitle();//centers the axis title
  Axis1->GetXaxis()->SetLabelFont(132); //Nice font
  Axis1->GetXaxis()->SetTitle("#font[132]{R_{FD} [km]}");// This is the axis title uses latex code basically change '\alpha' for '#alpha' otherwist it is the same
  Axis1->SetTitle(""); //Histogram title here
  // MeanAll->SetMarkerStyle(8); //changes style of plot points. dont need for a histogram
  // MeanAll->SetMarkerSize(1);
  //Mean1->SetLineWidth(2); //slightly thicker lines
  //Axis1->Draw(""); //draws histogram
//TriggeringEfficiencyEmin17Thetamin115H0->Draw("APC");

HistoLgEMCTEST->Draw("");

//delete Canvas1;
//Now another plot. You can do this as many times as you want. makesure the canvases are named differently.

CanvasTEST->cd();
TGraphErrors * graphExposureCO1year = new TGraphErrors( EnergyRangeVector.size(), &EnergyRangeVector[0], &ExposureCO1year[0],
																				&ErorrEnergy[0], &ErrorExposureCO1year[0]);
graphExposureCO1year->SetTitle("Exposure Coihueco for 1 year, #theta #in [115 - 130#circ]");
graphExposureCO1year->GetXaxis()->SetTitleOffset(1.2);
graphExposureCO1year->GetXaxis()->SetTitle("lg E_{MC} / eV");
graphExposureCO1year->GetXaxis()->CenterTitle();
graphExposureCO1year->GetYaxis()->SetTitleOffset(1.2);
graphExposureCO1year->GetYaxis()->SetTitle("Exposure [km^{2} sr yr]");
graphExposureCO1year->GetYaxis()->CenterTitle();
graphExposureCO1year->SetMarkerStyle(20);
graphExposureCO1year->SetMarkerSize(0.7);
graphExposureCO1year->SetMarkerColor(kBlack);

graphExposureCO1year->Draw("AP");

CanvasCOandHEATThetaMin115->cd();

TGraphErrors * graphExposureHEAT1year = new TGraphErrors( EnergyRangeVector.size(), &EnergyRangeVector[0], &ExposureHEAT1year[0],
																				&ErorrEnergy[0], &ErrorExposureHEAT1year[0]);
graphExposureHEAT1year->SetTitle("Exposure HEAT for 1 year, #theta #in [115 - 130#circ]");
graphExposureHEAT1year->GetXaxis()->SetTitleOffset(1.2);
graphExposureHEAT1year->GetXaxis()->SetTitle("lg E_{MC} / eV");
graphExposureHEAT1year->GetXaxis()->CenterTitle();
graphExposureHEAT1year->GetYaxis()->SetTitleOffset(1.2);
graphExposureHEAT1year->GetYaxis()->SetTitle("Exposure [km^{2} sr yr]");
graphExposureHEAT1year->GetYaxis()->CenterTitle();
graphExposureHEAT1year->SetMarkerStyle(20);
graphExposureHEAT1year->SetMarkerSize(0.7);
graphExposureHEAT1year->SetMarkerColor(kBlue);
graphExposureHEAT1year->SetLineColor(kBlue);

graphExposureHEAT1year->Draw("AP");


Canvas2->cd();


TGraphErrors *graphExposureVsEnergyThetamin115 = new TGraphErrors(EnergyRangeVector.size(), &EnergyRangeVector[0], &Exposure4EyesAllEnergiesThetamin115H0[0],
                                                                    &ErorrEnergy[0], &ErrorExposurePlus[0]);
graphExposureVsEnergyThetamin115->SetTitle("#theta #in [115 - 130#circ]");
graphExposureVsEnergyThetamin115->GetXaxis()->SetTitleOffset(1.2);
graphExposureVsEnergyThetamin115->GetXaxis()->SetTitle("lg E_{MC} / eV");
graphExposureVsEnergyThetamin115->GetXaxis()->CenterTitle();
graphExposureVsEnergyThetamin115->GetYaxis()->SetTitleOffset(1.2);
graphExposureVsEnergyThetamin115->GetYaxis()->SetTitle("Exposure [km^{2} sr yr]");
graphExposureVsEnergyThetamin115->GetYaxis()->CenterTitle();
graphExposureVsEnergyThetamin115->SetMarkerStyle(20);
graphExposureVsEnergyThetamin115->SetMarkerSize(0.7);
graphExposureVsEnergyThetamin115->SetMarkerColor(kBlack);
graphExposureVsEnergyThetamin115->SetLineColor(kBlack);
graphExposureVsEnergyThetamin115->SetFillColorAlpha(kGray+2, .5);
//graphExposureVsEnergyThetamin115->SetLineWidth(2);
graphExposureVsEnergyThetamin115->Draw("AP");

Canvas3->cd();
TGraphErrors *graphTrigEfficiencyEMC17to175 = new TGraphErrors( AverageFdDistance.size(), &AverageFdDistance[0], &TriggEvOverGenEvEMC17to175[0],  &ErrorDistance[0],
																							&ErrorTriggEvOverGenEvEMC17to175[0]);
graphTrigEfficiencyEMC17to175->SetMarkerStyle(20);
graphTrigEfficiencyEMC17to175->SetMarkerSize(0.7);
graphTrigEfficiencyEMC17to175->SetFillColorAlpha(kGray+2, .5);
//graphTrigEfficiencyEMC17to175->Draw("aple3");

TGraphErrors *graphTrigEfficiencyEMC175to18 = new TGraphErrors( AverageFdDistance.size(), &AverageFdDistance[0], &TriggEvOverGenEvEMC175to18[0],  &ErrorDistance[0],
																							&ErrorTriggEvOverGenEvEMC175to18[0]);

graphTrigEfficiencyEMC175to18->SetMarkerStyle(21);
graphTrigEfficiencyEMC175to18->SetMarkerSize(0.7);
graphTrigEfficiencyEMC175to18->SetMarkerColor(kBlue);
graphTrigEfficiencyEMC175to18->SetLineColor(kBlue);
graphTrigEfficiencyEMC175to18->SetFillColorAlpha(kAzure+2, .5);
//graphTrigEfficiencyEMC175to18->Draw("aple3");
//
TGraphErrors *graphTrigEfficiencyEMC18to185 = new TGraphErrors( AverageFdDistance.size(), &AverageFdDistance[0], &TriggEvOverGenEvEMC18to185[0],  &ErrorDistance[0],
																							&ErrorTriggEvOverGenEvEMC18to185[0]);

graphTrigEfficiencyEMC18to185->SetMarkerStyle(22);
graphTrigEfficiencyEMC18to185->SetMarkerSize(0.7);
graphTrigEfficiencyEMC18to185->SetMarkerColor(kRed);
graphTrigEfficiencyEMC18to185->SetLineColor(kRed);
graphTrigEfficiencyEMC18to185->SetFillColorAlpha(kRed-6, .5);
//graphTrigEfficiencyEMC18to185->Draw("aple3");


TMultiGraph *mggraphTrigEfficiency = new TMultiGraph();
mggraphTrigEfficiency ->Add(graphTrigEfficiencyEMC17to175);
mggraphTrigEfficiency->Add(graphTrigEfficiencyEMC175to18);
mggraphTrigEfficiency->Add(graphTrigEfficiencyEMC18to185);

mggraphTrigEfficiency->SetTitle("Triggering Efficiency  ;Distance_{FD} [km]; Triggered Ev/Generated Ev");
mggraphTrigEfficiency->Draw("aple3");
mggraphTrigEfficiency->SetMinimum(-0.1); //for setting y axis limits
mggraphTrigEfficiency->SetMaximum(1);

TPaveText *pt2 = new TPaveText(25,0.4,35,0.7);
 pt2->AddText("lgE #in [17 - 17.5 ]  eV ");
 pt2->SetTextColor(1); ((TText*)pt2->GetListOfLines()->Last())->SetTextColor(1);
 pt2->AddText("lgE #in (17.5 - 18]  eV ");
 pt2->SetTextColor(4); ((TText*)pt2->GetListOfLines()->Last())->SetTextColor(4);
 pt2->AddText("lgE #in (18 - 18.5]  eV");
 pt2->SetTextColor(2); ((TText*)pt2->GetListOfLines()->Last())->SetTextColor(2);
 pt2->Draw();


 Canvas4->cd();

 TGraphErrors *graphExposureVsEnergyThetamin115Rgt1 = new TGraphErrors(EnergyRangeVector.size(), &EnergyRangeVector[0], &Exposure4EyesAllEnergiesThetamin115H0Rgt1[0],
                                                                     &ErorrEnergy[0], &ErrorExposureRgt1[0]);
 graphExposureVsEnergyThetamin115Rgt1->SetMarkerStyle(22);
 graphExposureVsEnergyThetamin115Rgt1->SetMarkerSize(0.7);
 graphExposureVsEnergyThetamin115Rgt1->SetMarkerColor(kGreen+3);
 graphExposureVsEnergyThetamin115Rgt1->SetLineColor(kGreen);
 graphExposureVsEnergyThetamin115Rgt1->SetFillColorAlpha(kGreen-4, .5);

 TGraphErrors *graphExposureVsEnergyThetamin115Rgt2 = new TGraphErrors(EnergyRangeVector.size(), &EnergyRangeVector[0], &Exposure4EyesAllEnergiesThetamin115H0Rgt2[0],
                                                                     &ErorrEnergy[0], &ErrorExposureRgt2[0]);
 graphExposureVsEnergyThetamin115Rgt2->SetMarkerStyle(21);
 graphExposureVsEnergyThetamin115Rgt2->SetMarkerSize(0.7);
 graphExposureVsEnergyThetamin115Rgt2->SetMarkerColor(kBlue);
 graphExposureVsEnergyThetamin115Rgt2->SetLineColor(kBlue);
 graphExposureVsEnergyThetamin115Rgt2->SetFillColorAlpha(kAzure+2, .5);

 TGraphErrors *graphExposureVsEnergyThetamin115Rgt3 = new TGraphErrors(EnergyRangeVector.size(), &EnergyRangeVector[0], &Exposure4EyesAllEnergiesThetamin115H0Rgt3[0],
                                                                     &ErorrEnergy[0], &ErrorExposureRgt3[0]);
 graphExposureVsEnergyThetamin115Rgt3->SetMarkerStyle(23);
 graphExposureVsEnergyThetamin115Rgt3->SetMarkerSize(0.7);
 graphExposureVsEnergyThetamin115Rgt3->SetMarkerColor(kRed);
 graphExposureVsEnergyThetamin115Rgt3->SetLineColor(kRed);
 graphExposureVsEnergyThetamin115Rgt3->SetFillColorAlpha(kRed-6, .5);

 TMultiGraph *mgExposure = new TMultiGraph();
 mgExposure->Add(graphExposureVsEnergyThetamin115);
 mgExposure->Add(graphExposureVsEnergyThetamin115Rgt1);
 mgExposure->Add(graphExposureVsEnergyThetamin115Rgt2);
 mgExposure->Add(graphExposureVsEnergyThetamin115Rgt3);
 mgExposure->SetTitle("Exposure for different distances away from FD, #theta #in [115 - 130 #circ]");
 mgExposure->Draw("aple3");


 TPaveText *pt3 = new TPaveText(17.5,500,17.9,600);
  pt3->AddText("R_{FD} #in [0 - 35 ]  km ");
  pt2->SetTextColor(1); ((TText*)pt3->GetListOfLines()->Last())->SetTextColor(1); //black
  pt3->AddText("R_{fd} > 1 km ");
  pt3->SetTextColor(4); ((TText*)pt3->GetListOfLines()->Last())->SetTextColor(3); //green
  pt3->AddText("R_{fd} > 2 km ");
  pt3->SetTextColor(2); ((TText*)pt3->GetListOfLines()->Last())->SetTextColor(4); //blue
  pt3->AddText("R_{fd} > 3 km ");
  pt3->SetTextColor(2); ((TText*)pt3->GetListOfLines()->Last())->SetTextColor(2); //red
  pt3->Draw();


  CanvasEnergydiff->cd();

  vector<double> RatioExposureRgt1OverExposureTotal;
  vector<double> RatioExposureRgt2OverExposureTotal;
  vector<double> RatioExposureRgt3OverExposureTotal;
  vector<double> RatioExposureRgt4OverExposureTotal;
  vector<double> RatioExposureRgt5OverExposureTotal;

  vector <double> ErrorRatioExposureRgt1OverExposureTotal;
  vector <double> ErrorRatioExposureRgt2OverExposureTotal;
  vector <double> ErrorRatioExposureRgt3OverExposureTotal;
  vector <double> ErrorRatioExposureRgt4OverExposureTotal;
  vector <double> ErrorRatioExposureRgt5OverExposureTotal;

  vector<double> EnergyVectorRatioExposure;
  vector<double> ErrorEnergyVectorRatioExposure;

  for( int i = 0; i< EnergyRangeVector.size(); i++)
  {    if(Exposure4EyesAllEnergiesThetamin115H0[i]!=0)
  {
	  EnergyVectorRatioExposure.push_back(EnergyRangeVector[i]);
	  ErrorEnergyVectorRatioExposure.push_back(0);

	  RatioExposureRgt1OverExposureTotal.push_back( (Exposure4EyesAllEnergiesThetamin115H0Rgt1[i] / Exposure4EyesAllEnergiesThetamin115H0[i]  )* 100 );
  RatioExposureRgt2OverExposureTotal.push_back(  (Exposure4EyesAllEnergiesThetamin115H0Rgt2[i] / Exposure4EyesAllEnergiesThetamin115H0[i]  )* 100 );
  RatioExposureRgt3OverExposureTotal.push_back  (  (Exposure4EyesAllEnergiesThetamin115H0Rgt3[i] / Exposure4EyesAllEnergiesThetamin115H0[i]  )* 100 );
  RatioExposureRgt4OverExposureTotal.push_back  (  (Exposure4EyesAllEnergiesThetamin115H0Rgt4[i] / Exposure4EyesAllEnergiesThetamin115H0[i]  )* 100 );
  RatioExposureRgt5OverExposureTotal.push_back  (  (Exposure4EyesAllEnergiesThetamin115H0Rgt5[i] / Exposure4EyesAllEnergiesThetamin115H0[i]  )* 100 );


  ErrorRatioExposureRgt1OverExposureTotal.push_back(  10 * sqrt(  pow(  (1/Exposure4EyesAllEnergiesThetamin115H0[i] )* ErrorExposureRgt1[i], 2) +
		  pow(  (Exposure4EyesAllEnergiesThetamin115H0Rgt1[i] / (Exposure4EyesAllEnergiesThetamin115H0[i] *Exposure4EyesAllEnergiesThetamin115H0[i] ) ) *
				  ErrorExposurePlus[i],2   )     )    );

  ErrorRatioExposureRgt2OverExposureTotal.push_back(  10 * sqrt(  pow(  (1/Exposure4EyesAllEnergiesThetamin115H0[i] )* ErrorExposureRgt2[i], 2) +
		  pow(  (Exposure4EyesAllEnergiesThetamin115H0Rgt2[i] / (Exposure4EyesAllEnergiesThetamin115H0[i] *Exposure4EyesAllEnergiesThetamin115H0[i] ) ) *
				  ErrorExposurePlus[i],2   )     )    );

  ErrorRatioExposureRgt3OverExposureTotal.push_back(  10 * sqrt(  pow(  (1/Exposure4EyesAllEnergiesThetamin115H0[i] )* ErrorExposureRgt3[i], 2) +
		  pow(  (Exposure4EyesAllEnergiesThetamin115H0Rgt3[i] / (Exposure4EyesAllEnergiesThetamin115H0[i] *Exposure4EyesAllEnergiesThetamin115H0[i] ) ) *
				  ErrorExposurePlus[i],2   )     )    );

  ErrorRatioExposureRgt4OverExposureTotal.push_back(  10 * sqrt(  pow(  (1/Exposure4EyesAllEnergiesThetamin115H0[i] )* ErrorExposureRgt4[i], 2) +
		  pow(  (Exposure4EyesAllEnergiesThetamin115H0Rgt4[i] / (Exposure4EyesAllEnergiesThetamin115H0[i] *Exposure4EyesAllEnergiesThetamin115H0[i] ) ) *
				  ErrorExposurePlus[i],2   )     )    );

  ErrorRatioExposureRgt5OverExposureTotal.push_back(  10 * sqrt(  pow(  (1/Exposure4EyesAllEnergiesThetamin115H0[i] )* ErrorExposureRgt5[i], 2) +
		  pow(  (Exposure4EyesAllEnergiesThetamin115H0Rgt5[i] / (Exposure4EyesAllEnergiesThetamin115H0[i] *Exposure4EyesAllEnergiesThetamin115H0[i] ) ) *
				  ErrorExposurePlus[i],2   )     )    );
  }
  }


  for( int i=0; i<EnergyVectorRatioExposure.size(); i++)
	  {cout<<"Energy: "<<EnergyVectorRatioExposure[i]<< " atioExposureRgt1OverExposureTotal" <<RatioExposureRgt1OverExposureTotal[i]<< "Error RatioExposureRgt1OverExposureTotal"
	  <<ErrorRatioExposureRgt1OverExposureTotal[i]<<  " RatioExposureRgt5OverExposureTotal"<<	 RatioExposureRgt5OverExposureTotal[i] <<" ErrorRatioExposureRgt5OverExposureTotal"
	  <<ErrorRatioExposureRgt5OverExposureTotal[i]<<" ErrorExposureRgt5[i]"<<ErrorExposureRgt5[i]<<endl;


	  }



//  for( int i=0; i<EnergyRangeVector.size(); i++)
//	  cout<<"energy: "<<EnergyRangeVector[i]<<" total exposure: "<< Exposure4EyesAllEnergiesThetamin115H0[i]  << " exposure r > 3 "<< Exposure4EyesAllEnergiesThetamin115H0Rgt3[i]<<
//	  " calculated ratio: "<< RatioExposureRgt3OverExposureTotal[i]<<endl;

  TGraphErrors *graphRatioR1 = new TGraphErrors(EnergyVectorRatioExposure.size(), &EnergyVectorRatioExposure[0], &RatioExposureRgt1OverExposureTotal[0] ,
		  	  	  	  	  	  	  	  &ErrorEnergyVectorRatioExposure[0], &ErrorRatioExposureRgt1OverExposureTotal[0]);
  graphRatioR1->SetMarkerStyle(20);
  graphRatioR1->SetMarkerColor(kBlack);
  graphRatioR1->SetLineColor(kBlack);
  graphRatioR1->SetMarkerSize(0.8);
  graphRatioR1->SetFillColorAlpha(kGray+2, .5);

  TGraphErrors *graphRatioR2 = new TGraphErrors(EnergyVectorRatioExposure.size(), &EnergyVectorRatioExposure[0], &RatioExposureRgt2OverExposureTotal[0] ,
	  	  	  	  &ErrorEnergyVectorRatioExposure[0], &ErrorRatioExposureRgt2OverExposureTotal[0]);
  graphRatioR2->SetMarkerStyle(21);
  graphRatioR2->SetMarkerColor(kBlue);
  graphRatioR2->SetMarkerSize(0.8);
  graphRatioR2->SetLineColor(kBlue);
  graphRatioR2->SetFillColorAlpha(kAzure+2, .5);

  TGraphErrors *graphRatioR3 = new TGraphErrors(EnergyVectorRatioExposure.size(), &EnergyVectorRatioExposure[0], &RatioExposureRgt3OverExposureTotal[0] ,
	  	  	  	  &ErrorEnergyVectorRatioExposure[0], &ErrorRatioExposureRgt3OverExposureTotal[0]);
  graphRatioR3->SetMarkerStyle(22);
  graphRatioR3->SetMarkerColor(kRed);
  graphRatioR3->SetMarkerSize(0.8);
  graphRatioR3->SetLineColor(kRed);
  graphRatioR3->SetFillColorAlpha(kRed-6, .5);

  TGraphErrors *graphRatioR4 =new TGraphErrors(EnergyVectorRatioExposure.size(), &EnergyVectorRatioExposure[0], &RatioExposureRgt4OverExposureTotal[0] ,
	  	  	  	  &ErrorEnergyVectorRatioExposure[0], &ErrorRatioExposureRgt4OverExposureTotal[0]);
  graphRatioR4->SetMarkerStyle(20);
  graphRatioR4->SetMarkerColor(kOrange+4);
  graphRatioR4->SetMarkerSize(0.8);
  graphRatioR4->SetLineColor(kOrange+4);
  graphRatioR4->SetFillColorAlpha(kOrange-7, .5);

  TGraphErrors *graphRatioR5 = new TGraphErrors(EnergyVectorRatioExposure.size(), &EnergyVectorRatioExposure[0], &RatioExposureRgt5OverExposureTotal[0] ,
	  	  	  	  &ErrorEnergyVectorRatioExposure[0], &ErrorRatioExposureRgt5OverExposureTotal[0]);
  graphRatioR5->SetMarkerStyle(20);
  graphRatioR5->SetMarkerColor(kMagenta+1);
  graphRatioR5->SetMarkerSize(0.8);
  graphRatioR5->SetLineColor(kMagenta);
  graphRatioR5->SetFillColorAlpha(kMagenta-9, .5);

  TMultiGraph *mgRatioExposure = new TMultiGraph();
  mgRatioExposure->Add(graphRatioR1);
  mgRatioExposure->Add(graphRatioR2);
  mgRatioExposure->Add(graphRatioR3);
  mgRatioExposure->Add(graphRatioR4);
  mgRatioExposure->Add(graphRatioR5);
  mgRatioExposure  ->SetTitle( "Percentage of Exposures with respect to the exposure in the whole radius range: R_{FD} #in [0, 35 km] ; lg E (eV) ; Percentage of the total exposure [%]");
  mgRatioExposure ->Draw("aple3");

  TPaveText *ptRatio = new TPaveText(18.05,55,18.35,72);
  ptRatio->AddText("R_{FD} > 1km ");
  ptRatio->SetTextColor(1); ((TText*)ptRatio->GetListOfLines()->Last())->SetTextColor(1);
  ptRatio->AddText("R_{FD} > 2 km");
  ptRatio->SetTextColor(4); ((TText*)ptRatio->GetListOfLines()->Last())->SetTextColor(4);
   ptRatio->AddText("R_{FD} > 3 km");
   ptRatio->SetTextColor(2); ((TText*)ptRatio->GetListOfLines()->Last())->SetTextColor(2);
   ptRatio->AddText("R_{FD} > 4 km");
    ptRatio->SetTextColor(kOrange+9); ((TText*)ptRatio->GetListOfLines()->Last())->SetTextColor(kOrange+9);
    ptRatio->AddText("R_{FD} > 5 km");
     ptRatio->SetTextColor(2); ((TText*)ptRatio->GetListOfLines()->Last())->SetTextColor(6);
   ptRatio->Draw();

//  for( int i = 0; i< EnergyRangeVector.size(); i++)
//  cout<<"TEST::"<<RatioExposureRgt1OverExposureTotal[i]<< " err: "<< ErrorRatioExposureRgt1OverExposureTotal[i]<<endl;


  TFile* outFile = new TFile("ExposureInfoTauE17_18.5_Theta115-130_H0.root", "RECREATE");
  graphExposureVsEnergyThetamin115->Write("GraphExposureAllEH0");
  graphExposureCO1year->Write("graphExposureCO1year");
  graphExposureHEAT1year->Write("graphExposureHEAT1year");
  graphTrigEfficiencyEMC17to175->Write("graphTrigEfficiencyEMC17to175");
  graphTrigEfficiencyEMC175to18->Write("graphTrigEfficiencyEMC175to18");
  graphTrigEfficiencyEMC18to185->Write("graphTrigEfficiencyEMC18to185");

  mgRatioExposure->Write("mgRatioExposure");
  mggraphTrigEfficiency->Write("mggraphTrigEfficiency");

  graphRatioR5->Write("GraphRatioR5H0");
  graphRatioR4->Write("GraphRatioR4H0");
  graphRatioR3->Write("GraphRatioR3H0");
  graphRatioR2->Write("GraphRatioR2H0");
  graphRatioR1->Write("GraphRatioR1H0");

  outFile->Write();
  outFile->Close();
  //graphExposureVsEnergyThetamin115Rgt2->Draw("AP");


//  for(int i=0; i<EnergyRangeVector.size();i++)
//  {cout<<"E range: "<<EnergyRangeVector[i]<<" Exposure r 0 - 35: "<<Exposure4EyesAllEnergiesThetamin115H0[i]<<" Exposure r > 1 km: "<<Exposure4EyesAllEnergiesThetamin115H0Rgt1[i]
//	  <<" Exposure r> 2: "<<Exposure4EyesAllEnergiesThetamin115H0Rgt2[i]<<" Exposure r> 3 km: "<<Exposure4EyesAllEnergiesThetamin115H0Rgt3[i]<<endl;
//
//	 // cout<<" exposure: r > 2 "<<Exposure4EyesAllEnergiesThetamin115H0Rgt2[i]<<"   error: "<<ErrorExposureRgt2[i]<<endl;
//
//
//  }

  gStyle->SetStatX(.97);
  gStyle->SetStatW(0.45);
  gStyle->SetStatH(0.25);


  //Counts->Print("Counts.pdf");

}
