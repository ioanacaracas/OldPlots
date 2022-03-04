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

void CheckExpoDistrib(){

	TH1D* X1FromExpDistribHist = new TH1D("X1FromExpDistribHist","X1FromExpDistribHist", 500, 0, 5000);

	double avX1Electron = 37;
	double X1FromExpDistribElectron;
	double xCheck;
	TRandom* random = new TRandom();
	vector<double> TrialsVector;
	vector<double> X1FromExpDistribElectronVector;

	for(int i= 0; i<1000; i++){
		X1FromExpDistribElectron=random->Exp(avX1Electron);
		X1FromExpDistribHist->Fill(X1FromExpDistribElectron);

	}
X1FromExpDistribHist->Draw("");

}