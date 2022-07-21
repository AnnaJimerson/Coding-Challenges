// Day1-SumAverageNumbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

float Sum(float, float, float);

float Average(float, float, float);

int main()
{
    char choice = 'y';

    while (choice == 'y')
    {
        float val1, val2, val3, sum, average;
        cout << "Please input 3 numbers to return Sum and Average." << endl;
        cin >> val1 >> val2 >> val3;

        sum = Sum(val1, val2, val3);
        average = Average(val1, val2, val3);

        cout << "Sum:     " << sum << endl;
        cout << "Average: " << average << endl;

        choice = 'n';

        cout << "Would you like to input more numbers? (y/n)" << endl;
        cin >> choice;
    }
}


float Sum(float val1, float val2, float val3 = 0)
{
    float sum = 0;
    sum = val1 + val2 + val3;

    return sum;
}


float Average(float val1, float val2, float val3)
{
    float avg = 0;
    avg = val1 + val2 + val3;
    avg /= 3;

    return avg;
}
