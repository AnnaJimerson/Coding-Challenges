// LargestNumberInArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

void GenerateRandomArray(int[], int);
int GetLargestValue(int[], int);

int main()
{
    const int arrSize = 100;
    int arr[arrSize] = {0};

    // Set random seed
    srand(time(0));

    GenerateRandomArray(arr, arrSize);

    // Print array
    cout << "The Array (100 elements, random 1-1000):" << endl;
    for (int i : arr) {
        cout << i << " ";
    }

    // Print answer
    int largestVal = GetLargestValue(arr, arrSize);
    cout << endl << endl << "The largest number in the array is: " << largestVal << endl;
}

void GenerateRandomArray(int arr[], int size) {
    // fill array with random int's
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000 + 1;
    }
}

int GetLargestValue(int arr[], int size) {
    int largest = 0;

    // Could also use a Set, but this takes up less space...
    for (int i = 0; i < size; i++) {
        if (largest < arr[i]) {
            largest = arr[i];
        }
    }

    return largest;
}