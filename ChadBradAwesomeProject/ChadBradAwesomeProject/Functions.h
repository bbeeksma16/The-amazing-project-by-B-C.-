#include <vector>
#include "Car.h"
#include <fstream>
using namespace std;

vector<Car> CarsIntoVector() //putting all possible cars into a vector
{
	vector<Car> Cars(10);

	Car a, b, c, d, e, f, g, h, i, j;

	a.setName("Nissan Pickup Truck"); //naming and adding the weight to the cars
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

	Cars[0] = a; //adding the cars to the vector
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

double getHeight() //get the height of the truss bridge from the user
{
	int i = -1;
	double height;

	while (i == -1)
	{
		cout << "Please enter what you want the height of the truss bridge to be (between 0 " << endl << "and 1000 feet): "; //get height of bridge
		cin >> height;

		if (height < 0 || height > 1000) //check if response is out of range
			cout << "Height out of range." << endl << endl;
		else
			i = 1;
	}

	return height;
}

int getMaterial() //get material of bridge
{
	int material;
	int a = -1;
	do
	{
		cout << endl << "The following are all available materials for the bridge: " << endl; //display material options
		cout << "\t 1) Concrete" << endl;
		cout << "\t 2) A36 Steel" << endl;
		cout << "\t 3) Titanium" << endl;
		cout << "\t 4) 6061 Aluminum" << endl;
		cout << "Which material would you like the bridge to be made out of: ";
		cin >> material; //get material they want
		if (material < 5 && material > 0) //make sure choice is one of the choices
			a = 1;
		else
			cout << endl << "Please enter a valid choice. " << endl << endl; //if not, re-enter choice
	} while (a == -1);
	

	return material;
}

vector<string> InputUsername () //making a vector of all the usernames in the username txt file
{
	ifstream input;
	input.open( "usernameList.txt", ios::in ); //open the file

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

	NumberUsernames = lineCount / 2; //txt file only half usernames (half passwords)

	vector<string> usernames(NumberUsernames);

	for (int i = 0; i < NumberUsernames; i++)
	{
		getline(input, line); //gets username
		usernames[i] = line; //adds it to the vector

		getline(input, line); //skips over the password line
	}

	input.close(); //close the file

	return usernames;
}

vector<string> InputPasswords () //making a vector of all the passwords from the username txt file
{
	ifstream input;
	input.open( "usernameList.txt", ios::in ); //open the file

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

	NumberPasswords = lineCount / 2; //only half lines are passwords

	vector<string> passwords(NumberPasswords);

	for (int i = 0; i < NumberPasswords; i++)
	{
		getline(input, line); //skips over the username line

		getline(input, line); //gets the password
		passwords[i] = line; //adds it to the vector
	}

	input.close(); //close the file

	return passwords;
}

void addUsername(string Username, string Password) //add a username and password to the username txt file
{
	ofstream output;
	output.open( "usernameList.txt", ios::app ); //open the txt file for appending

	if ( !output ) {
		cout << "The file does not exist..." << endl; //make sure it opened properly
	}

	output << endl << Username; //add username and password
	output << endl << Password;

	output.close(); //close the file
}

vector<string> InputHighScoreUsernames () //put usernames for the high scores into a vector
{
	ifstream input;
	input.open( "HighScores.txt", ios::in ); //open the txt file

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

	NumberUsernames = lineCount / 2; //only half of the lines are usernames

	vector<string> usernames(NumberUsernames);

	for (int i = 0; i < NumberUsernames; i++)
	{
		getline(input, line); //gets username
		usernames[i] = line; //adds it to the vector

		getline(input, line); //skips over the score line
	}

	input.close(); //close the file

	return usernames;
}

vector<double> InputHighScores () //put the high scores into a vector
{
	ifstream input;
	input.open( "HighScores.txt", ios::in ); //open the txt file

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

	NumberScores = lineCount / 2; //only half the lines are high scores

	vector<double> scores(NumberScores);

	for (int i = 0; i < NumberScores; i++)
	{
		getline(input, line); //skips over the username line

		input >> score; //gets the score
		scores[i] = score; //adds it to the vector

		getline(input, line); //skips over "rest" of high score line
	}

	input.close(); //close the file

	return scores;
}

void addScore(string Username, double Score) //add a username and score to the txt file
{
	ofstream output;
	output.open( "HighScores.txt", ios::app ); //open the file

	if ( !output ) {
		cout << "The file does not exist..." << endl; //make sure it opened properly
	}

	output << endl << Username; //add the username and score
	output << endl << Score;

	output.close(); //close the txt file
}

void OutputHighScores() //output the table for the three highest scores and their usernames
{
	vector<string> highScoreUsernames = InputHighScoreUsernames();
	vector<double> highScores = InputHighScores();

	for (int g = 0; g < highScores.size(); g++) //sort it as many times as there are candies in the store
	{
		for (int i = 0; i < highScores.size() - 1; i++) //sorting the high score and the cooresponding username vectors from highest score to least
		{
			double b = highScores[i];
			double c = highScores[i+1];
			string d = highScoreUsernames[i];
			string e = highScoreUsernames[i+1];

			if (b < c) //if the candy is more expensive than the candy after it
			{
				highScores[i] = c; //swap the high scores
				highScores[i+1] = b;
				highScoreUsernames[i] = e; //swap their usernames
				highScoreUsernames[i+1] = d;
			}
		}
	}

	cout << endl << endl;

	cout << "Current High Scores" << endl; //cout a fancy table with the first three usernames and passwords thus far
	cout << "_____________________________________" << endl;
	cout << "1. " << highScores[0] << "    " << highScoreUsernames[0] << endl;
	cout << "2. " << highScores[1] << "    " << highScoreUsernames[1] << endl;
	cout << "3. " << highScores[2] << "    " << highScoreUsernames[2] << endl;
}