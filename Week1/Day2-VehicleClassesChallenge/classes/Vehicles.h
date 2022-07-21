#pragma once
#include <iostream>

// Vehicles Base Class
class Vehicles
{
private:
	int m_miles = 0;

public:
	Vehicles() {};
	Vehicles(int miles);

	virtual void Drive() {};				// The Drive overridable function that subclasses replace
	int GetMiles() { return m_miles; }
	void SetMiles(int miles);
};

// Car subclass
class Car : public Vehicles
{
public:
	Car() {};
	Car(int miles) : Vehicles(miles) {};	// This simply calls the constructor of the base class whenever we provide
											// the amount of miles the vehicle was active for
	virtual void Drive() override;
};


// Boat subclass
class Boat : public Vehicles
{
public:
	Boat() {};
	Boat(int miles) : Vehicles(miles) {};
	virtual void Drive() override;
};


// Plane subclass
class Plane : public Vehicles
{
public:
	Plane() {};
	Plane(int miles) : Vehicles(miles) {};
	virtual void Drive() override;
};