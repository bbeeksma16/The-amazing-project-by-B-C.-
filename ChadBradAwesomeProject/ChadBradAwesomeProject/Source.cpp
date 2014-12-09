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
	cout << "In this game you must get a car across a 600 ft bridge that you designed." << endl; //introduce the game
	cout << endl;
	account.open("usernameList.txt");
	vector<string> usernameslist = InputUsername(); //get vector for usernames
	vector<string> passwordslist = InputPasswords(); //get vector for passwords
	int index = -1;

	do
	{
		cout << "Do you have an account?" << endl; //ask if they have an existing account
		cout << "(Y/N): ";
		cin >> answer;
		cin.ignore();
		if (answer == 'Y' || answer == 'y') // User has account
		{
			cout << endl << "Username: ";
			getline(cin, username);
			for (int i = 0; i < usernameslist.size(); i++) //check all usernames and see if provided name is there
			{
				if (usernameslist[i] == username)
				{
					index = i; //if it is, store the position in the vector of the username
				}
			}
			if (index == -1) //if the username didn't match any usernames in the vector
			{
				cout << "Username not found. Please try again." << endl; //go back to the beginning
				dowhile = 0;
			}
			else //if the username was found
			{
				cout << "Password: ";
				getline(cin, password);
				if (passwordslist[index] == password) //check if password is the right password
				{
					dowhile = 1;
				}
				else
				{
					cout << "Password not correct, please try again." << endl; //if wrong go back to the beginning
					dowhile = 0;
				}
			}	
		}
		else if (answer == 'N' || answer == 'n') // User is making an account
		{
			cout << endl << "Let's create an account then!" << endl << endl;
			cout << "Please enter a username: "; //get username
			getline(cin, username);
			cout << "Please enter a password: "; //get password
			getline(cin, password);
			addUsername(username, password); //add username and password to txt file
			dowhile = 1;
		}
		else
		{
			cout << "That is not a valid answer. Please try again" << endl; //repeat beginning until user says y or n
			dowhile = 0;
			cin.ignore();

		}
	} while (dowhile == 0);
		

	vector<Car> cars = CarsIntoVector(); //put cars into a vector

	srand (time(NULL));
	int random = rand() % 10;

	cout << endl << cars[random]; //cout a random car about to drive across your bridge

	cout << "     ________________    " << endl;
	cout << "    / \\  / \\  / \\  / \\    " << endl;
	cout << "   /___\\/___\\/___\\/___\\   " << endl << endl; //cool picture of a truss bridge

	double h = getHeight(); //get the height of the bridge
	cout << endl;
	int m = getMaterial(); //get the material for the bridge
	cout << endl;
	double A = beamSize(); //get the beam size for the bridge
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
	double points = score(sigma, m); //assign a score for the user
	cout << "You earned " << floor(points) << " points!" << endl; //cout  what their score was

	addScore(username, floor(points)); //add the score and username to the txt file

	vector<string> highScoreUsernames = InputHighScoreUsernames(); //make the vector for the usernames
	vector<double> highScores = InputHighScores(); //make a vector for the scores

	OutputHighScores(); //output the three highest scores and their usernames

	cout << endl << endl;

	return 0;
}
