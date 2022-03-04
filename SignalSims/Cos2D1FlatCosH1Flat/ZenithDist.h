/*
 * SysErrPenalization.h
 *
 *  Created on: Nov 28, 2017
 *      Author: mayotte
 */

#include <string>

#ifndef DEV_FINAL_SYSERRPENALIZATION_H_
#define DEV_FINAL_SYSERRPENALIZATION_H_

//Data Structure to hold analysis variables

std::string gOutputFile = "ZenithDists.root";

void Usage(const char* const exe) {
  std::cout << " usage: " << exe << " <Outname>"<< std::endl;
}


void GetConfiguration();
void ReadData(std::string);
void ElongationCorrection();
void TSMC();

#endif /* DEV_FINAL_SYSERRPENALIZATION_H_ */
