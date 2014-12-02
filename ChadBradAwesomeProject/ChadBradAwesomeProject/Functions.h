#include <vector>
#include "Car.h"
#include <fstream>
using namespace std;

vector<Car> CarsIntoVector()
{
	vector<Car> Cars(10);

	Car a, b, c, d, e, f, g, h, i, j;

	a.setName("Nissan Pickup Truck");
	a.setWeight(5038);
	b.setName("Volkswagon Beetle");
	b.setWeight(1764);
	c.setName("Subaru Forester");
	c.setWeight(3153);
	d.setName("Toyota Prius");
	d.setWeight(3042);
	e.setName("Ferrari Italia");
	e.setWeight(3274);
	f.setName("Bugatti Veyron");
	f.setWeight(4044);
	g.setName("Tesla Model S");
	g.setWeight(4647);
	h.setName("Leopard 2 Tank");
	h.setWeight(90000);
	i.setName("KNTV Smart Car");
	i.setWeight(1800);
	j.setName("Toyota Camry");
	j.setWeight(3190);

	Cars[0] = a;
	Cars[1] = b;
	Cars[2] = c;
	Cars[3] = d;
	Cars[4] = e;
	Cars[5] = f;
	Cars[6] = g;
	Cars[7] = h;
	Cars[8] = i;
	Cars[9] = j;

	return Cars;
}

double getHeight()
{
	int i = -1;
	double height;

	while (i == -1)
	{
		cout << "Please enter what you want the height of the suspension pole to be (between 0 and 1000 feet):";
		cin >> height;

		if (height < 0 || height > 1000)
			cout << "Height out of range." << endl;
		else
			i = 1;
	}

	return height;
}

double getThickness()
{
	int i = -1;
	double thickness;

	while (i == -1)
	{
		cout << "Please enter what you want the thickness of the bridge to be (between 0 and 100 feet):";
		cin >> thickness;

		if (thickness < 0 || thickness > 100)
			cout << "Thickness out of range." << endl;
		else
			i = 1;
	}

	return thickness;
}

double getMaterial()
{
	double modulus;
	string material;
	cout << "The following are all available materials for the bridge: "; //finish this section with your modulus information
	cout << "Which material would you like the bridge to be made out of: ";
	cin >> material;

	// write code here that will convert the material choice into their cooresponding modulus.
	return modulus;
}

vector<string> InputUsername ()
{
	vector<string> usernames;

	ifstream input;
	input.open( "usernameList.txt", ios::in ); 

	if ( !input ) {
		cout << "The file does not exist..." << endl; //make sure it opened properly
	}

	int lineCount, NumberUsernames;
	string line;
	while (getline(input, line)) { //getting the amount of candies being added
	lineCount++;
	}

	input.clear(); //resetting the input to the beginning
	input.seekg(0);

	NumberUsernames = lineCount / 2;

	for (int i = 0; i < NumberUsernames; i++)
	{
		getline(input, line); //gets username
		usernames[i] = line; //adds it to the vector

		getline(input, line); //skips over the password line
	}

	input.close();

	return usernames;
}

vector<string> InputPasswords ()
{
	vector<string> passwords;

	ifstream input;
	input.open( "usernameList.txt", ios::in ); 

	if ( !input ) {
		cout << "The file does not exist..." << endl; //make sure it opened properly
	}

	int lineCount, NumberPasswords;
	string line;
	while (getline(input, line)) { //getting the amount of candies being added
	lineCount++;
	}

	input.clear(); //resetting the input to the beginning
	input.seekg(0);

	NumberPasswords = lineCount / 2;

	for (int i = 0; i < NumberPasswords; i++)
	{
		getline(input, line); //skips over the username line

		getline(input, line); //gets the password
		passwords[i] = line; //adds it to the vector
	}

	input.close();

	return passwords;
}

void addUsername(string Username, string Password)
{
	ofstream output;
	output.open( "usernameList.txt", ios::app );

	if ( !output ) {
		cout << "The file does not exist..." << endl; //make sure it opened properly
	}

	output << endl << Username;
	output << endl << Password;

	output.close();
}