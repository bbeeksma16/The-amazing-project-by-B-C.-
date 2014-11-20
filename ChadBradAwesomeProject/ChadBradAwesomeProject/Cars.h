#include <iostream>
#include <string>

using namespace std;

class Cars
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