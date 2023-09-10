//Description: This program swaps inputs
//Author: Ali Saeed
//COMSC-165 Section 5065
//Date: 9/10/23
//Status: Complete

#include <iostream>
using namespace std;

//function prototype
void exchange(float &, float &);

int main()
{
	float first, second;

	//inputs
	cout << "Enter the first number" << endl << "Then hit enter" << endl;
	cin >> first;
	cout << "Enter the second number" << endl << "Then hit enter" << endl;
	cin >> second;
	cout << "You input the numbers as " << first << " and " << second << "." << endl;
	//function
	exchange(first, second);

	//states changes
	cout << "After swapping, the first number has the value of " << first << " which was the value of the second number" << endl;
	cout << "The second number has the value of " << second << " which was the value of the first number" << endl;
}
//function definition
void exchange(float & number1, float & number2)
{
	float placeholder;
	placeholder = number2;
	number2 = number1;
	number1 = placeholder;
}