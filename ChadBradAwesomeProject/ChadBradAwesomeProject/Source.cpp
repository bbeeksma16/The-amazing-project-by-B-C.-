//B-
// Trying to work out the account system 
// This text file will hold the password on the first line
// 

#include <iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	char answer;
	string username;
	string line, password;
	fstream account;
	cout << "Welcome to the Bridge-Builder!!" << endl;
	cout << "In this game you must get poor sheep-car across a bridge that you designed." << endl;
	cout << endl;
	cout << "Do you have an account?" << endl;
	cout << "(Y/N):";
	cin >> answer;
	if (answer == 'Y' || answer == 'y')
	{
	cout << "Username: " ;
	cin >> username; 
	account.open(username, ios::in, ios::out);
	cout << "Password: "; 
	cin >> password; 
	account >> line;
	if (line != password) 
	{
		cout << "password incorrect. Please try again" << endl;

	}
	else if (answer == 'N' || answer == 'n')
	{
		cout << "Let's create an account then!" << endl;
		cout << "What do you want your username to be? " ;
		cin >> username;
		account.open(username, ios::out);
		cout << endl;
		cout << "What is your password? ";
		cin >> password;
		account << password; 

	}
	


	return 0;
}