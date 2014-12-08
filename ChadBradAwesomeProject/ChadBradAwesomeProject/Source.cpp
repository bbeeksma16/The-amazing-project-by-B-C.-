//B-
// Trying to work out the account system 
// This text file will hold the password on the first line
// 

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
#include <math.h>
#include "Car.h"
#include "Functions.h"
#include "Calculations.h"


using namespace std;

int main()
{
	int dowhile = 0;
	char answer;
	string username;
	string password, line;
	ifstream account;
	cout << "Welcome to the Bridge-Builder!!" << endl;
	cout << "In this game you must get a car across a 600 ft bridge that you designed." << endl;
	cout << endl;
	account.open("usernameList.txt");
	vector<string> usernameslist = InputUsername();
	vector<string> passwordslist = InputPasswords();
	int index = -1;

	do
	{
		cout << "Do you have an account?" << endl;
		cout << "(Y/N): ";
		cin >> answer;
		cin.ignore();
		if (answer == 'Y' || answer == 'y') // User has account
		{
			cout << "Username: ";
			getline(cin, username);
			for (int i = 0; i < usernameslist.size(); i++)
			{
				if (usernameslist[i] == username)
				{
					index = i;
				}
			}
			if (index == -1)
			{
				cout << "Username not found. Please try again." << endl;
				dowhile = 0;
			}
			else
			{
				cout << "Password: ";
				getline(cin, password);
				if (passwordslist[index] == password)
				{
					dowhile = 1;
				}
				else
				{
					cout << "Password not correct, please try again." << endl;
					dowhile = 0;
				}
			}	
		}
		else if (answer == 'N' || answer == 'n') // User is making an account
		{
			cout << "Let's create an account then!" << endl << endl;
			cout << "Please enter a username: ";
			getline(cin, username);
			cout << "Please enter a password: ";
			getline(cin, password);
			addUsername(username, password);
			dowhile = 1;
		}
		else
		{
			cout << "That is not a valid answer. Please try again" << endl;
			dowhile = 0;
			cin.ignore();

		}
	} while (dowhile == 0);
		

	vector<Car> cars = CarsIntoVector();

	srand (time(NULL));
	int random = rand() % 10;

	cout << endl << cars[random];

	cout << "     ________________    " << endl;
	cout << "    / \\  / \\  / \\  / \\    " << endl;
	cout << "   /___\\/___\\/___\\/___\\   " << endl << endl;

	double h = getHeight();
	cout << endl;
	//getThickness();
	int m = getMaterial(); 
	cout << endl;
	double A = beamSize(); 
	cout << endl;
	double P = maxTension(h, cars[random].getWeight()); // finds amount of force on bridge
	double sigma = stress(P,A); // evaluates stress
	bool breaks = failure(m, sigma); // if true, the bridge breaks
	if ( breaks == 0)
	{cout << "Good job! Your bridge stands. " << endl;}
	else if (breaks == 1)
	{ cout << "Your bridge broke under the weight. Better luck next time!" << endl;
		return 0;}
	else
	{return 0;}
	double points = score(sigma, m);
	cout << "You earned " << floor(points) << " points!" << endl;

	addScore(username, floor(points));

	vector<string> highScoreUsernames = InputHighScoreUsernames();
	vector<double> highScores = InputHighScores();

	OutputHighScores();

	cout << endl << endl;

	return 0;
}
