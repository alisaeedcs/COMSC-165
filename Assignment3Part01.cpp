//Description: This program creates an array of temperatures and uses some functions to sort it and also find the average
//Author: Ali Saeed
//COMSC-165 Section 5065
//Date: 9/17/23
//Status: Complete

#include <iostream>
#include <iomanip>;
using namespace std;

void sortArray(int[], int);
float findAvg(int[], int, float);

int main() {
    //creates a constant for array size
    const int ARRAY_SIZE = 10;
    //initializes array
    int arr[ARRAY_SIZE];
    //gets all inputs for array
    for (int i = 0; i < ARRAY_SIZE; i++) {
        cout << "Please input temperatures for day " << i+1 << ": " << endl;
        cin >> arr[i];
    }
    //uses function to sort array
    sortArray(arr, ARRAY_SIZE);
    //uses function to display average
    cout << "The average temperature is " << fixed << setprecision(2) << findAvg(arr, ARRAY_SIZE, 0) << " degrees." << endl;;
}

void sortArray(int a[], int size) {
    //uses selection sort, one of the more simple sorting algorithms
    //i is less than size -1 because the last index we look at is the second to last and not the ultimate last index
    for (int i = 0; i < (size - 1); i++) {
        //find smallest element and swap it at index i, if it needs to happen
        //assume minimum is already at i
        int min_index = i;
        //j is the counter variable, checks the rest of the elements in the array, and if finds a smaller element, swaps the index
        for (int j = i + 1; j < size; j++) {
            if (a[j] < a[min_index]) {
                //now minimum stores the index of j, since the value was less than i
                min_index = j;

            }
        }
        //With a final check to see if they were not equal, the values within are swapped
        if (min_index != i) {
            int temp = a[i];
            a[i] = a[min_index];
            a[min_index] = temp;
        }
    }
}

float findAvg(int a[], int size, float avg) {
    //intializes sum
    float sum = 0;
    for (int i = 0; i < size; i++) {
        //adds all values of array
        sum += a[i];
        //final calculation of avg will be the final average
        avg = sum / size;
    }
    //returned
    return avg;
}
