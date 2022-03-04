#ifndef REWEIGHT_H_
#define REWEIGHT_H_


std::string gOutputFile = "RootFiles/WeightsOut.root";

int getOptions(int argc, char** argv) {

  int c;
  while ((c = getopt(argc, argv, "c:bshmio::")) != -1) {
   switch (c) {
    case 'o':
      printf("Output file: \"%s\"\n", optarg);
      gOutputFile = std::string(optarg);
      break;
    default:
      return -1;
   }
  }

  return optind;
}

void Usage(const char* exe) {
  std::cout
    << "\n"
    "  Usage:  "
    << exe
    << " FdCompADST.root\n"
    "        "
    << exe
    << " \"FdCompADST*.root\"\n\n"
    "  Options: -c: config file for event selection (default: analysis.config)\n"
    << std::endl;
}

int ReadData(std::string);
void FillHistograms();
void PlotThrown();
void CalculateWeightingParameters(TFile*);

Double_t TotalFitFunc(Double_t*, Double_t*);
Double_t ParFunc(Double_t*, Double_t*);


#endif /* REWEIGHT_H_ */
