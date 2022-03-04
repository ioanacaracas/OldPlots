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

void CheckZenithValues(){

	const double PI = 3.141592653589;

	const double NZenithBins = 30;
	double ZenithValues[NZenithBins];

	double CosSqZenithValues[NZenithBins] = {0.1317166667, 0.16115, 0.1905833333, 0.2200166667, 0.24945, 0.2788833333, 0.3083166667, 
	                                        0.33775, 0.3671833333, 0.3966166667, 0.42605, 0.4554833333, 0.4849166667, 0.51435, 0.5437833333, 0.5732166667, 
	                                        0.60265, 0.6320833333, 0.6615166667, 0.69095, 0.7203833333, 0.7498166667, 0.77925, 0.8086833333, 0.8381166667, 
	                                        0.86755, 0.8969833333, 0.9264166667, 0.95585, 0.9852833333};


	for(int i=0; i<NZenithBins; i++){
	  ZenithValues[i] = 180 - acos( sqrt(CosSqZenithValues[i]) ) * 180/PI;
	  cout<<"zenith = "<<ZenithValues[i]<<endl;

	}

}
