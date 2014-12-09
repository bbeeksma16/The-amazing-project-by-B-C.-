#ifndef ___CAR_H___
#define ___CAR_H___

#include <iostream>
#include <string>

using namespace std;

class Car //comments in the cpp file
{
private:
	string name;
	double weight;
	
public:
	string getName();
	void setName(string Name);
	double getWeight();
	void setWeight(double Weight);
};

#endif

ostream& operator<<(ostream& os, Car& c); 
