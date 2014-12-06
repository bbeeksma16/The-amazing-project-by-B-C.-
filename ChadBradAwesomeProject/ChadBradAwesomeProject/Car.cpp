#include "Car.h"

string Car::getName() {return name;}
void Car::setName(string Name) {name = Name;}
double Car::getWeight() {return weight;}
void Car::setWeight(double Weight) {weight = Weight;}
string Car::getColor() {return color;}
void Car::setColor(string Color) {color = Color;}

ostream& operator<<(ostream& os, Car& c)
{
os << "A " << c.getName() << ", with a total weight of " <<
c.getWeight() << " lbs, is about to drive across your bridge. Design a bridge that will support this vehicle." << endl << endl;
return os;
}