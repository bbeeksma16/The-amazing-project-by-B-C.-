#include "Car.h"

string Car::getName() {return name;} //return the name of a car
void Car::setName(string Name) {name = Name;} //set the name of a car
double Car::getWeight() {return weight;} //return the weight of a car
void Car::setWeight(double Weight) {weight = Weight;} //set the weight of a car

ostream& operator<<(ostream& os, Car& c) //overwrite the << operator for the car class
{
os << "A " << c.getName() << ", with a total weight of " <<
c.getWeight() << " lbs, is about to drive across your bridge. Design a bridge that will support this vehicle." << endl << endl; 
return os; //make it cout the name and the weight of the car in a sentence structure
}