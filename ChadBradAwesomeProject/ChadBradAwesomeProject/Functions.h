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
	d.setName("Semi Truck");
	d.setWeight(35000);
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
	j.setName("Gas Tanker");
	j.setWeight(60000);

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
		cout << "Please enter what you want the height of the truss bridge to be (between 0 " << endl << "and 1000 feet): ";
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
		cout << endl << "Please enter what you want the thickness of the bridge to be (between 0 and 100  feet): ";
		cin >> thickness;

		if (thickness < 0 || thickness > 100)
			cout << "Thickness out of range." << endl;
		else
			i = 1;
	}

	return thickness;
}

int getMaterial()
{
	int material;
	cout << endl << "The following are all available materials for the bridge: " << endl; //finish this section with your modulus information
	cout << "\t 1) Concrete" << endl;
	cout << "\t 2) A36 Steel" << endl;
	cout << "\t 3) Titanium" << endl;
	cout << "\t 4) 6061 Aluminum" << endl;
	cout << "Which material would you like the bridge to be made out of: ";
	cin >> material;

	return material;
}

vector<string> InputUsername ()
{
	ifstream input;
	input.open( "usernameList.txt", ios::in ); 

	if ( !input ) {
		cout << "The file does not exist..." << endl; //make sure it opened properly
	}

	int lineCount = 0;
	int NumberUsernames = 0;
	string line;
	while (getline(input, line)) { //getting the amount of candies being added
	lineCount++;
	}

	input.clear(); //resetting the input to the beginning
	input.seekg(0);

	NumberUsernames = lineCount / 2;

	vector<string> usernames(NumberUsernames);

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
	ifstream input;
	input.open( "usernameList.txt", ios::in ); 

	if ( !input ) {
		cout << "The file does not exist..." << endl; //make sure it opened properly
	}

	int lineCount = 0;
	int NumberPasswords = 0;
	string line;
	while (getline(input, line)) { //getting the amount of usernames being added
	lineCount++;
	}

	input.clear(); //resetting the input to the beginning
	input.seekg(0);

	NumberPasswords = lineCount / 2;

	vector<string> passwords(NumberPasswords);

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

vector<string> InputHighScoreUsernames ()
{
	ifstream input;
	input.open( "HighScores.txt", ios::in ); 

	if ( !input ) {
		cout << "The file does not exist..." << endl; //make sure it opened properly
	}

	int lineCount = 0;
	int NumberUsernames = 0;
	string line;
	while (getline(input, line)) { //getting the amount of usernames being added
	lineCount++;
	}

	input.clear(); //resetting the input to the beginning
	input.seekg(0);

	NumberUsernames = lineCount / 2;

	vector<string> usernames(NumberUsernames);

	for (int i = 0; i < NumberUsernames; i++)
	{
		getline(input, line); //gets username
		usernames[i] = line; //adds it to the vector

		getline(input, line); //skips over the score line
	}

	input.close();

	return usernames;
}

vector<double> InputHighScores ()
{
	ifstream input;
	input.open( "HighScores.txt", ios::in ); 

	if ( !input ) {
		cout << "The file does not exist..." << endl; //make sure it opened properly
	}

	int lineCount = 0;
	int NumberScores = 0;
	double score = 0;
	string line;
	while (getline(input, line)) { //getting the amount of scores being added
	lineCount++;
	}

	input.clear(); //resetting the input to the beginning
	input.seekg(0);

	NumberScores = lineCount / 2;

	vector<double> scores(NumberScores);

	for (int i = 0; i < NumberScores; i++)
	{
		getline(input, line); //skips over the username line

		input >> score; //gets the score
		scores[i] = score; //adds it to the vector

		getline(input, line);
	}

	input.close();

	return scores;
}

void addScore(string Username, double Score)
{
	ofstream output;
	output.open( "HighScores.txt", ios::app );

	if ( !output ) {
		cout << "The file does not exist..." << endl; //make sure it opened properly
	}

	output << endl << Username;
	output << endl << Score;

	output.close();
}

void OutputHighScores()
{
	vector<string> highScoreUsernames = InputHighScoreUsernames();
	vector<double> highScores = InputHighScores();

	for (int g = 0; g < highScores.size(); g++) //sort it as many times as there are candies in the store
	{
		for (int i = 0; i < highScores.size() - 1; i++)
		{
			double b = highScores[i];
			double c = highScores[i+1];
			string d = highScoreUsernames[i];
			string e = highScoreUsernames[i+1];

			if (b < c) //if the candy is more expensive than the candy after it
			{
				highScores[i] = c;
				highScores[i+1] = b;
				highScoreUsernames[i] = e;
				highScoreUsernames[i+1] = d;
			}
		}
	}

	cout << endl << endl;

	cout << "Current High Scores" << endl;
	cout << "_____________________________________" << endl;
	cout << "1. " << highScores[0] << "    " << highScoreUsernames[0] << endl;
	cout << "2. " << highScores[1] << "    " << highScoreUsernames[1] << endl;
	cout << "3. " << highScores[2] << "    " << highScoreUsernames[2] << endl;
}