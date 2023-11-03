#pragma once
#include "Flight.h"


using namespace std;

Flight::Flight() {
	bool retry = true;
	cout << "Flight Number: ";
	string input = "";
	while (retry) {
		try {
			getline(cin, input);
			flightNumber = stoi(input);
			retry = false;
		}
		catch (exception) {
			cout << "That was not a valid entry! Try again." << endl;
		}
	}
}
Flight::Flight(int number) {
	flightNumber = number;
	List<string>* passengers = new List<string>();
}




int Flight::getFlightNumber() {
	return flightNumber;
}

void Flight::setFlightNumber(int num) {
	flightNumber = num;
}

void Flight::printFlight(bool reverse) {
	passengers.sort(reverse);
	cout << endl;
	cout << "Flight Number: " << flightNumber << endl;
	for (int i = 0; i < passengers.getLength(); ++i) {
		cout << "Name: " << passengers.returnValueAtIndex(i) << endl;
	}
}

void Flight::addPassenger(string pass) {
	passengers.append(pass);
	cout << pass << " was added onto flight " << flightNumber << endl;
}

void Flight::removePassenger(string passenger) {
	int index = -1;
	index = returnIndexFromValue(passenger);
	if (index == -1) {
		cout << passenger << " not found." << endl;
		return;
	}
	passengers.removeIndex(index + 1);
	cout << passenger << " was removed from flight " << flightNumber << endl << endl;
	return;
}

void Flight::removePassenger(int index) {
	string passenger = passengers.returnValueAtIndex(index);
	passengers.removeIndex(index);
	cout << passenger << " was removed from flight " << flightNumber << endl;
	return;
}

int Flight::returnIndexFromValue(string value) {
	Node<string>* temp = passengers.getNode(0);
	for (int i = 0; &(temp->value) != 0; temp = temp->next, ++i) {
		if (temp->value == value) {
			return i;
		}
	}
	return -1;
}