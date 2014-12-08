#include"Calculations.h"
#include<cmath>

// Materials: Concrete, A36 Steel, Titanium, Aluminum 6061



double beamSize() // Asks user what size beams for bridge
{
	int choice;
	double A;
	cout << "What size I-beams would you like to construct your bridge with? "  << endl;
	cout << "\t 1) W24 X 55" << endl;
	cout << "\t 2) W15 X 26" << endl;
	cout << "\t 3) W12 X 14" << endl;
	cout << "\t 4) W6 X 9" << endl;
	cout << "Size of I-beams: ";
	cin >> choice;
	switch (choice)
	{
	case 1:
		A = 16.2;
		break;
	case 2:
		A = 7.68;
		break;
	case 3:
		A = 4.16;
		break;
	case 4:
		A = 2.68;
		break;
	default:
		A = 7.68;
	}
	return A; // returns area
}

double stress(double P, double A)
{
	double sigma = P / A;
	return sigma;
}

// Function for the utilization of the height's effect on the shear force. 
double maxTension(double h, double V)
{
	double adj = 150;
	double rad = atan(h/adj);
	double P = V*(cos(rad)/sin(rad));
	// P is the max tension force in the bridge;
	return P;
}

// Yield strengthes of each materials: 
// C - 4000 psi 
// S - 36 000 psi
// T - 32 633 psi
// A - 40 000 psi

bool failure(int material, double sigma) // returns if material will break
{
	double yield;
	switch (material)
	{
	case 1:
		yield = 4000;
		break;
	case 2:
		yield = 36000;
		break;
	case 3:
		yield = 32633;
		break;
	case 4:
		yield = 40000;
		break;
	default:
		yield = 4000;
	}
	if (yield <= sigma)
	{
		return true;
	}
	else
	{
		return false;
	}
}	

double score(double sigma, int m)
{
	double pointsoff, score;
	switch (m)
	{
	case 1:
		pointsoff = sigma / 4000;
		break;
	case 2:
		pointsoff = sigma / 36000;
		break;
	case 3:
		pointsoff = sigma / 32633;
		break;
	case 4:
		pointsoff = sigma / 40000;
		break;
	default:
		pointsoff = sigma;
	}
	score = 100000 * pointsoff;
	return score;
}