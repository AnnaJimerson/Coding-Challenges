// Day2-NumberFactors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

void DisplayFactors(int);

int main()
{
    int number = 0;
    cout << "Enter a number to display all of its factors:" << endl;
    cin >> number;

    // Just incase, convert number to positive
    number = abs(number);

    DisplayFactors(number);
}

void DisplayFactors(int value) {
    cout << "Factors: " << endl;

    for (int i = 1; i <= value; i++) {
        if (value % i == 0) {
            cout << i << endl;
        }
    }
}