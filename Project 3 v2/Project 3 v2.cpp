#pragma once
#include "Node.h"
#include "List.h"
#include "Flight.h"
#include <string>
#include <iostream>

using namespace std;

int tester();
void driver();
void driver2();
void reservations(List<Flight*>& Flights);
void printAll(List<Flight*>& Flights);


int main() {
	List<Flight*> Flights;
	bool repeat = true;
	while (repeat) {
		string response = "";
		cout << endl;
		cout << "-----------------MAIN-MENU-----------------\n"
			<< "1 - Press to make or change a reservation.\n"
			<< "2 - Press to print all manifests.\n"
			<< "3 - Press to run driver.\n"
			<< "0 - Exit program." << endl;
		getline(cin, response);
		try {
			switch (stoi(response)) {
			case 1:
				reservations(Flights);
				break;
			case 2:
				printAll(Flights);
				break;
			case 3:
				driver();
				break;
			case 0:
				repeat = false;
				return 0;
				break;
			default:
				cout << "invalid entry!" << endl;
			}
		}
		catch (exception) {
			cout << "invalid entry!" << endl;
		}
	}
}

void driver() {
	List<Flight*> Flights;
	Flight* flight1 = new Flight(2430);
	Flights.append(flight1);
	const int LENGTH = 5;
	string pass[LENGTH] = { "Hamilton Dale", "Hamilton Leslie", "Hamilton Jonathan", "Hamilton Nicholas", "Hamilton Annalisa" };
	for (int i = 0; i < LENGTH; ++i) {
		Flights.returnValueAtIndex(0)->addPassenger(pass[i]);
	}
	Flights.returnValueAtIndex(0)->printFlight(false);
	cout << endl;


	Flight* flight2 = new Flight(2515);
	Flights.append(flight2);
	const int LENGTH2 = 3;
	string pass2[LENGTH2] = { "Absorka Thor", "Loki the Mutt", "Snowwispe Nora" };
	for (int i = 0; i < LENGTH2; ++i) {
		Flights.returnValueAtIndex(1)->addPassenger(pass2[i]);
	}
	Flights.returnValueAtIndex(1)->printFlight(false);
	cout << endl;

	Flights.returnValueAtIndex(1)->removePassenger("Loki the Mutt");

	Flight* flight3 = new Flight(2750);
	Flights.append(flight3);
	const int LENGTH3 = 1;
	string pass3[LENGTH3] = { "Loki the Mutt" };
	for (int i = 0; i < LENGTH3; ++i) {
		Flights.returnValueAtIndex(2)->addPassenger(pass3[i]);
	}
	cout << endl;


	Flights.returnValueAtIndex(1)->printFlight(false);
	Flights.returnValueAtIndex(2)->printFlight(false);

	//std::cout << "hello world" << std::endl;
}


void reservations(List<Flight*>& Flights) {
	int flightIndex = 0;
	bool repeat = true;
	
	string input = "";
	cout << "Please enter a flight number:" << endl;
	int flightNum = -1;
	while (flightNum == -1) { // this is just to make sure flightNum gets correctly set.
		getline(cin, input);
		flightNum = -1;
		try {
			flightNum = stoi(input);
		}
		catch (exception) {
			cout << "invalid entry!" << endl;
		}
	}
	bool found = false;
	int iterator = 0;
	for (; iterator < Flights.getLength(); ++iterator) {
		if (Flights.returnValueAtIndex(iterator)->getFlightNumber() == flightNum) {
			found = true;
			flightIndex = iterator;
		}
	}
	if (!found) {
		flightIndex = iterator;
		Flight* flight = new Flight(flightNum);
		Flights.append(flight);
	}
	while (repeat) {
		string response = "";
		cout << "\n--------List-of-Passengers--------\n"
			<< "1 - Insert passenger onto flight " << flightNum << ".\n"
			<< "2 - Remove passenger from flight " << flightNum << ".\n"
			<< "3 - List passengers on flight " << flightNum << ".\n"
			<< "4 - List passengers by reverse order.\n"
			<< "0 - Exit Flight " << flightNum << "." << endl;
		getline(cin, response);

		string pass = "";
		switch (stoi(response)) {
		case 1:
			cout << "Name: ";
			getline(cin, pass);
			Flights.returnValueAtIndex(flightIndex)->addPassenger(pass);
			break;
		case 2:
			cout << "Name: ";
			getline(cin, pass);
			Flights.returnValueAtIndex(flightIndex)->removePassenger(pass);
			break;
		case 3:
			Flights.returnValueAtIndex(flightIndex)->printFlight(false);
			break;
		case 4:
			Flights.returnValueAtIndex(flightIndex)->printFlight(true);
			break;
		case 0:
			repeat = false;
			return;
			break;
		default:
			cout << "invalid entry!" << endl;
		}
	}
}
void printAll(List<Flight*>& Flights) {
	for (int i = 0; i < Flights.getLength(); ++i) {
		Flights.returnValueAtIndex(i)->printFlight(false);
	}
}
int tester() {
	string t = "6";

	string names[3] = { "Timothy", "Ian", "Elijah" };
	Node<string> test(names[0]);
	cout << "Value: " << test.value << endl;

	//-----------------------------------------------------------//   ^ Working ^

	List<string> testList;
	testList.append(names[2]);
	testList.append(names[1]);
	testList.append(names[0]);
	cout << "head: " << testList.getHead() << "\n";
	cout << "tail: " << testList.getTail() << "\n";
	testList.printList();
	cout << "length: " << testList.getLength() << "\n";
	cout << "Node[1]: " << testList.getNode(1) << endl;
	cout << "Node[10]: " << testList.getNode(10) << endl;
	cout << "Value at Node[1]: " << testList.returnValueAtIndex(1) << endl;
	testList.removeIndex(1);
	testList.printList();
	testList.append(names[1]);
	testList.removeIndex(0);
	testList.printList();
	testList.append(names[2]);
	testList.removeLast();
	testList.printList();
	testList.append(names[2]);
	testList.append(names[0]);
	testList.printList();
	cout << "length: " << testList.getLength() << "\n";
	testList.sort(false);
	testList.printList();
	testList.sort(true);
	testList.printList();

	cout << endl;

	Flight flight1(1234);
	const int LENGTH = 7;
	string pass[LENGTH] = { "Eli", "Elijah", "Timothy", "Aaron", "Ian", "Ethan", "Isaiah" };
	for (int i = 0; i < LENGTH; ++i) {
		flight1.passengers.append(pass[i]);
	}
	flight1.printFlight(false);

	cout << endl;


	return 0;
}
void driver2() {
	int index = 0;
	List<Flight*> Flights;

	Flight* flight = new Flight(1234);
	Flights.append(flight);
	const int LENGTH = 5;
	string pass[LENGTH] = { "Hamilton Dale", "Hamilton Leslie", "Hamilton Jonathan", "Hamilton Nicholas", "Hamilton Annalisa" };
	for (int i = 0; i < LENGTH; ++i) {
		Flights.returnValueAtIndex(index)->addPassenger(pass[i]);
	}
	Flights.returnValueAtIndex(index)->printFlight(false);
	cout << endl;


	string response = "1";
	string pas = "";
	switch (stoi(response)) {
	case 1:
		getline(cin, pas);
		Flights.returnValueAtIndex(index)->addPassenger(pas);
		break;
	case 2:
		Flights.returnValueAtIndex(index)->removePassenger(pas);
		break;
	case 3:
		Flights.returnValueAtIndex(index)->printFlight(false);
		break;
	case 4:
		Flights.returnValueAtIndex(index)->printFlight(true);
		break;
	case 0:
		return;
		break;
	default:
		cout << "invalid entry! idk" << endl;
	}



	Flights.returnValueAtIndex(index)->printFlight(false);

	//std::cout << "hello world" << std::endl;
}