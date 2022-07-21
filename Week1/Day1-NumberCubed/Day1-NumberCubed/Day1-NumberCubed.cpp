// Day1-NumberCubed.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

float Pow(float, int);

int main()
{
    // Project name is misleading...I ended up just making an int power calculator instead...
    char choice = 'y';

    while (choice == 'y')
    {
        float number, result;
        int power;
        cout << "Input a number and a power to return its value." << endl;
        cin >> number >> power;

        result = Pow(number, power);

        cout << number << "^" << power << " == " << result << endl;

        choice = 'n';

        cout << "Want to continue inputting numbers? (y/n)" << endl;
        cin >> choice;
    }


}

float Pow(float val, int power) {
    float poweredVal = 1;

    if(power > 0)
        poweredVal = val * Pow(val, power - 1);

    return poweredVal;
}