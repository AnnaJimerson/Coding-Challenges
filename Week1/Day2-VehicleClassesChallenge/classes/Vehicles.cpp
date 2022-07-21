#include "Vehicles.h"

// Base class functions
Vehicles::Vehicles(int miles)
{
	SetMiles(miles);
}

void Vehicles::SetMiles(int miles)
{
	this->m_miles = miles;
}

// Subclass Car Functions
void Car::Drive()
{
	std::cout << "Hello! I am a car and I drove " << GetMiles() << " miles on the freeway!" << std::endl;
}

// Subclass Boat Functions
void Boat::Drive()
{
	std::cout << "Hello! I am a boat and I sailed " << GetMiles() << " miles on the ocean!" << std::endl;
}

// Subclass Plane Functions
void Plane::Drive()
{
	std::cout << "Hello! I am a plane and I flew " << GetMiles() << " miles in the sky!" << std::endl;
}