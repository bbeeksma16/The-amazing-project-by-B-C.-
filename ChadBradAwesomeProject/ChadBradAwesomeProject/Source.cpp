//B-
// Trying to work out the account system 
// This text file will hold the password on the first line
// 

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
#include "Car.h"
#include "Functions.h"
//#include "Calculations.h"


using namespace std;

int main()
{

	int dowhile = 0;
	char answer;
	string username;
	string password, line;
	ifstream account;
	cout << "Welcome to the Bridge-Builder!!" << endl;
	cout << "In this game you must get poor sheep-car across a bridge that you designed." << endl;
	cout << endl;
	account.open("usernameList.txt");
	vector<string> usernameslist = InputUsername();
	vector<string> passwordslist = InputPasswords();
	int index = -1;

	//do
	//{
	//	cout << "Do you have an account?" << endl;
	//	cout << "(Y/N):";
	//	cin >> answer;
	//	if (answer == 'Y' || answer == 'y') // User has account
	//	{
	//		cout << "Username: ";
	//		cin >> username;
	//		for (int i = 0; i < usernameslist.size(); i++)
	//		{
	//			if (usernameslist[i] == username)
	//			{
	//				index = i;
	//			}
	//		}
	//		if (index == -1)
	//		{
	//			cout << "Username not found. Please try again." << endl;
	//			dowhile = 0;
	//		}
	//		else
	//		{
	//			cout << "Password: ";
	//			cin >> password;
	//			if (passwordslist[index] == password)
	//			{
	//				dowhile = 1;
	//			}
	//			else
	//			{
	//				cout << "Password not correct, please try again." << endl;
	//				dowhile = 0;
	//			}
	//		}

	//		
	//	}
	//	else if (answer == 'N' || answer == 'n') // User is making an account
	//	{
	//		cout << "Let's create an account then!" << endl;
	//		cout << "What do you want your username to be? ";
	//		cin >> username;
	//		cout << endl;
	//		cout << "What is your password? ";
	//		cin >> password;
	//		addUsername(username, password);
	//		dowhile = 1;
	//	}
	//	else
	//	{
	//		cout << "That is not a valid answer. Please try again" << endl;
	//		dowhile = 0;

	//	}
	//} while (dowhile == 0);
		

	/*vector<Car> cars = CarsIntoVector();

	srand (time(NULL));
	int random = rand() % 10;

	cout << cars[random];

	getHeight();
	getThickness();
	getMaterial();*/

	/*vector<string> highScoreUsernames = InputHighScoreUsernames();
	vector<double> highScores = InputHighScores();*/

	OutputHighScores();

	return 0;
}
