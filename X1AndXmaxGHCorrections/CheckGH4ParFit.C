#include <TFile.h>
#include <TH1.h>
#include <TH2.h>
#include <TProfile.h>
#include <THistPainter.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TColor.h>
#include <TF1.h>
#include <TFormula.h>
#include <TGraph.h>
#include <TGraphErrors.h>
#include <TPaveStats.h>
#include <TPaveText.h>

#include "TROOT.h"

#include <vector>
#include <math.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>


using namespace std;

  double GaisserHillas4ParametersFunction ( double* x, double* par)
    {return par[0] * pow((x[0]-par[1])/(par[2]-par[1]), (par[2]-par[1])/par[3]) * exp((par[2]-x[0])/par[4]);       }


void CheckGH4ParFit()
{


string holder;

double dedx;
double x;

vector<double> dEdX;
vector<double> X;
cout<<"smth"<<endl;
ifstream dEdXFile;
//dEdXFile.open("outputSlantDepthEnergyDepositH0_sh001003.txt"); //H0
dEdXFile.open("outputSlantDepthEnergyDepositH4_sh013060.txt"); //H4
if(!dEdXFile.is_open()){ return 1; }

for (int i=0; i<44; i++)
	{dEdXFile>>x>>dedx;
	getline(dEdXFile,holder);
	dEdX.push_back(dedx);
	X.push_back(x);}



 TCanvas *Canvas1 = new TCanvas("Canvas1","Proton, E = 1.2156 #times 10^{18} eV, #theta = 116.438#circ, H = 0 km",200,10,700,400);
Canvas1->cd();
  Canvas1->SetRightMargin(0.02);//This changes the margins
  Canvas1->SetLeftMargin(0.155);
  Canvas1->SetTopMargin(0.02);
  Canvas1->SetBottomMargin(0.18);
  Canvas1->SetTicks(1,1);



TGraph *g = new TGraph(dEdX.size(), &X[0], &dEdX[0]);
g->SetTitle("");
g->GetXaxis()->SetTitleOffset(2.2);
g->GetXaxis()->SetTitle("X [g/cm^{2}]");
g->GetXaxis()->CenterTitle();
g->GetYaxis()->SetTitleOffset(1.2);
g->GetYaxis()->SetTitle("dE/dx [PeV / (g/cm^{2})]");
g->GetYaxis()->CenterTitle();
g->SetMarkerStyle(20);
g->Draw("AP");

	TF1 *ft = new TF1("f1","[0] * pow((x-[1])/([2]-[1]), ([2]-[1])/[3]) * exp(([2]-x)/[3])",22.46,2500);
	//ft->SetParameters( 1.78129, -24.4158, 728.005, 81.4485 ); //H0
	ft->SetParameters( 3.70046, 20.08535, 1468.35, 36.1792 ); //H4
	ft->Draw("same");

	

	 leg2 = new TLegend(.75,0.75,.95,0.95); //size of legend
	 leg2->AddEntry(g,"#font[132]{CORSIKA data}","lf"); //top right)
	 leg2->AddEntry(ft,"#font[132]{GH Fit}","lf"); //bottom right
	 leg2->Draw();

	 //lfunction = new TPaveLabel(1600,0.9,2000,1,"dE/dX_{max} = 1.78129 PeV / (g/cm^{2})"); 
	 //lfunction->Draw();

pt = new TPaveText(1600,0.65,2000,1);
//h4
/*pt->AddText("dE/dX_{max} = 3.70046 PeV / (g/cm^{2})");
pt->AddText("X_{max} = 1468.35 (g/cm^{2})");
pt->AddText("N_{max} = 1.51831 #times 10^{9}");*/

pt->AddText("dE/dX_{max} = 1.78129 PeV / (g/cm^{2})");
pt->AddText("X_{max} = 728.005 (g/cm^{2})");
pt->AddText("N_{max} = 7.30866 #times 10^{8}");

pt->Draw();

Canvas1->Print("CheckGHFit_H0.pdf");


//for (int j=0;j<dEdX.size();j++)
//	cout<<X[j]<<"  "<<dEdX[j]<<endl;

}

