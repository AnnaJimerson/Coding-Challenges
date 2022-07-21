// Day2-VehicleClassesChallenge.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "classes/Vehicles.h"

using namespace std;

int main()
{
    // Create our class objects, each having their own miles
    Car* myCar = new Car(100);
    Boat* myBoat = new Boat(1400);
    Plane* myPlane = new Plane(240000);

    // Blank constructor test
    Car* myCarNone = new Car();
    
    // Do drive functions for each
    myCar->Drive();
    myPlane->Drive();
    myBoat->Drive();
    myCarNone->Drive();

    // Delete dynamic data
    delete myCar;
    delete myPlane;
    delete myBoat;
    delete myCarNone;
}
