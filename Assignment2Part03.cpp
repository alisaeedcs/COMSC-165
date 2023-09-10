//Description: This program calculates grades
//Author: Ali Saeed
//COMSC-165 Section 5065
//Date: 9/10/23
//Status: Complete

#include <iostream>
using namespace std;

//function prototype
void calcGrade(double, double, double&);

int main() {
	//variables
	int count;
	double avg, sum = 0;
	//set to f to get rid of extra if statement
	char grade = 'F';

	cout << "Enter the number of grades" << endl;
	cin >> count;

	//for loop to find sum of grades
	for (int i = count; i > 0; i--) {
		double temp;
		cout << "Enter a numeric grade between 0-100" << endl;
		cin >> temp;
		sum += temp;
	}

	//function
	calcGrade(sum, count, avg);

	//used to calculate letter grade
	if (avg >= 90) {
		grade = 'A';
	}
	else if (avg >= 80) {
		grade = 'B';
	}
	else if (avg >= 70) {
		grade = 'C';
	}
	else if (avg >= 60) {
		grade = 'D';
	}
	
	cout << "The grade is " << grade;
}	

//function definition
void calcGrade(double total, double numGrades, double& grade) {
	grade = total / numGrades;
}