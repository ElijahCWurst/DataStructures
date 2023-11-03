#pragma once
#include "List.h"
#include <string>
#include <iostream>

using namespace std;

class Flight
{
private:
	int flightNumber = 0;

public:
	Flight();
	Flight(int number);
	void setFlightNumber(int num);
	void printFlight(bool reverse);
	void addPassenger(string pass);
	void removePassenger(string passenger);
	void removePassenger(int index);
	int getFlightNumber();
	int returnIndexFromValue(string value);
	List<string> passengers;

};

//#include "Flight.cpp"