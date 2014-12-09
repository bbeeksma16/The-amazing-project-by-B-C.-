#ifndef ___CALCULATIONS_H___
#define ___CALCULATIONS_H___

#include <iostream>


using namespace std; //comments in cpp file

double beamSize();

double maxTension(double h, double V);

double stress(double P, double A);

bool failure(int m, double sigma);

double score(double sigma, int m);
#endif