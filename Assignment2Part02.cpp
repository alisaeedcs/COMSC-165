//Description: This program calculates miles per hour
//Author: Ali Saeed
//COMSC-165 Section 5065
//Date: 9/10/23
//Status: Complete

#include <iostream>
#include <iomanip>
using namespace std;

//function prototype
void calculate(float, float, float &);

int main()
{
	float mi, hr, spd;

	//inputs
	cout << "Please input the miles traveled" << endl;
	cin >> mi;
	cout << "Please input the hours traveled" << endl;
	cin >> hr;

	//function
	calculate(mi, hr, spd);

	cout << "Your speed is " << fixed << setprecision(2) << spd << " miles per hour" << endl;
	return 0;

}

//function definition
void calculate(float miles, float hours, float & milesPerHour)
{
	milesPerHour = miles/hours;
}