#ifndef ___CAR_H___
#define ___CAR_H___

#include <iostream>
#include <string>

using namespace std;

class Car
{
private:
	string name;
	double weight;
	string color;
public:
	string getName();
	void setName(string Name);
	double getWeight();
	void setWeight(double Weight);
	string getColor();
	void setColor(string Color);
};

#endif

ostream& operator<<(ostream& os, Car& c);
