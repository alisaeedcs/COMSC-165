//Description: The program counts sick days
//Author: Ali Saeed
//COMSC-165 Section 5065
//Date: 9/1/23
//Status: Complete

#include <iostream>
using namespace std;

int main() {
	//initializes values used
	int total = 0, teller = 0, teller_count = 0, days = 0;

	cout << "How many tellers worked at Nation's Bank during each of the last three years?" << endl;
	cin >> teller_count;

	//loops for each teller working at the bank
	for (int i = 1; i <= teller_count; i++)
	{
		teller = i;
		//loops for three years
		for (int z = 1; z <= 3; z++)
		{
			cout << "How many days was teller " << teller << " out sick during year " << z << "?" << endl;
			cin >> days;
			//finds sum of all days that were missed
			total += days;
		}
	}
	cout << "The " << teller_count << " tellers were out sick for a total of " << total << " days during the last three years" << endl;
}