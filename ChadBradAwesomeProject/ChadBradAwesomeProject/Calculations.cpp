#include"Calculations.h"

// Materials: Concrete, A36 Steel, Titanium, Aluminum 6061


// T = (V * Q)/(I * t)

double maxShear(double th, double w)
{
	double width = 24 * 12;
	double T = (w * (width  * (th / 2))* (th / 4)) / ((1 / 12)*width*th*th*th*width);
	return T;
}

// Function for the utilization of the height's effect on the shear force. 
double heightCalc(double h, double V)
{

}

// Yield strengthes of each materials: 
// C - 4000 psi 
// S - 36 000 psi
// T - 32 633 psi
// A - 40 000 psi

bool failure(int material, double shear)
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
	if (yield <= shear)
	{
		return true;
	}
	else
	{
		return false;
	}
}	