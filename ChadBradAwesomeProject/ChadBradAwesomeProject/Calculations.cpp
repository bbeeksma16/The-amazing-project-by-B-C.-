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
	cout << "\t 3) W12 X 14" << endl; //displays options for the bridge
	cout << "\t 4) W6 X 9" << endl;
	cout << "Size of I-beams: ";
	cin >> choice;
	switch (choice)
	{
	case 1: //gets the cooresponding beam area with their choice
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
	default: //by default most bridges have W15 X 26 I-beams
		{
			A = 7.68;
			cout << "Invalid choice. Your bridge will have a default I-beam size of W15 X 26 " << endl; //cout their default I-beam size
		}
	}
	return A; // returns area
}

double stress(double P, double A) //calculates the stress of the bridge beams
{
	double sigma = P / A; //
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
	case 1: //gives the cooresponding yield of the material depending on what their choice was
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
	if (yield <= sigma) //if the yield is less than the stress, the bridge breaks
	{
		return true;
	}
	else //otherwise, it stays standing
	{
		return false;
	}
}	

double score(double sigma, int m) //apply a score based on cost effectiveness of their design
{
	double pointsoff, score;
	switch (m)
	{
	case 1:
		pointsoff = sigma / 4000; //gives score based on how close to breaking point they were
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
	score = 100000 * pointsoff; //everyone likes really large high scores!
	return score;
}