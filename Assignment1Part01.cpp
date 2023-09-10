//Description: This program counts beverage choice
//Author: Ali Saeed
//COMSC-165 Section 5065
//Date: 8/26/23
//Status: Complete

#include <iostream>
using namespace std;


int main() 
{
	//initializes variables
	int coffee = 0;
	int tea = 0;
	int coke = 0;
	int orange_juice = 0;
	int total = 0;
	int choice = 0;


	cout << "1. Coffee 2. Tea 3. Coke 4. Orange Juice" << endl;
	
	//while loop waits for exist case to quit
	while (choice != -1)
	{
		cout << "Please input the favorite beverage of person " << total++ << ": Choose 1, 2, 3, or 4 from the above menu or -1 to exit the program" << endl;
		cin >> choice;

		//switch allows for less code
		switch (choice)
		{
		case -1:
			//takes away one to let data remain accurate
			total--;
			break;

		case 1:
			coffee++;
			break;
		case 2:
			tea++;
			break;
		case 3:
			coke++;
			break;
		case 4:
			orange_juice++;
			break;
		default:
			//if invalid input is entered, non numerical or not within range
			total--;
			cout << "Please try again, invalid input" << endl;
			break;
		}
	}
	//Displays totals as well as individual choices
	cout << "The total number of people surveyed is " << total << ". The results are as follows: " << endl;
	cout << "Beverage Number of Votes" << endl;
	cout << "********************************" << endl;
	cout << "Coffee " << coffee << endl;
	cout << "Tea " << tea << endl;
	cout << "Coke " << coke << endl;
	cout << "Orange Juice " << orange_juice << endl;
}