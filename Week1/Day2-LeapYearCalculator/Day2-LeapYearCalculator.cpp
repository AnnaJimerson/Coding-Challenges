// Day2-LeapYearCalculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

bool leapYear(int);

int main()
{
    int year = 0;
    bool isLeap = false;
    char choice = 'y';
    int minYear = 1582;

    // Check choice to try again or not
    while (choice == 'y') 
    {
        cout << "Input a year to see if it's a leap year or not. (From " << minYear << " onwards.)" << endl;
        cin >> year;

        // (Based on MathIsFun, check if year is after 1582 (minYear)
        if (year >= minYear) {
            isLeap = leapYear(year);

            isLeap ? cout << "YES " << year << " is a leap year." << endl :
                cout << "NO " << year << " is NOT a leap year." << endl;
        }
        else
            cout << "Year is invalid!" << endl;

        // Get choice to continue
        choice = 'n';
        cout << "Would you like to continue? (y/n)" << endl;
        cin >> choice;
    }

    return 0;

}

bool leapYear(int year) {
    if (year % 4 == 0) {            // Check if year can be divided by 4 for leap year
        if (year % 100 == 0) {      // Then check if we can divide by 100 for exceptions
            if (year % 400 == 0)    // Finally if we get this far, check if we can divide by 400
                return true;
            else
                return false;
        }
        else {                      // If we can't divide by 100, then the year isn't an exception, so return true
            return true;
        }
    }
    else {
        return false;               // If NOT divisible by 4, then return not a leap year
    }
}