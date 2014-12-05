#include"Calculations.h"

// Materials: Concrete, A36 Steel, Titanium, Aluminum 6061


// T = (V * Q)/(I * t)

double maxShear(double height, double thickness, double weight)
{
	double width = 24 * 12;
	T = (weight * (width  * (thickness / 2))* (thickness / 4)) / ((1 / 12)*width*thickness*thickness*thickness*width);
	return T;
}

// Yield strengthes of each materials: 
// C - 4000 psi 
// S - 36 000 psi
// T - 32 633 psi
// A - 40 000 psi

bool failure(char material, float T)
{
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
	if (yield <= T)
	{
		return true;
	}
	else
	{
		return false;
	}
}	