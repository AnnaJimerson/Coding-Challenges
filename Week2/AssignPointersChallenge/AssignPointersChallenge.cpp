// AssignPointersChallenge.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    int a = 10;
    int b = 42;

    std::cout << "Enter 2 numbers to display their values and memory addresses: ";
    std::cin >> a >> b;

    // Store addresses
    int* ptrA = &a;
    int* ptrB = &b;

    // Print value of their pointers
    std::cout << "Values: " << std::endl;
    std::cout << *ptrA << std::endl;
    std::cout << *ptrB << std::endl;
    std::cout << std::endl;

    // Print memory addresses of pointers
    std::cout << "Addresses" << std::endl;
    std::cout << ptrA << std::endl;
    std::cout << ptrB << std::endl;
}
