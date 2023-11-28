#include <iostream>
#include "Word.h"

using namespace std;

//Constructors:
Word::Word() {}
Word::Word(string name) {
	this->name = name;
}


// Prints out the word and all it's use locations, supposedly without a comma on the last one.
void Word::print() {
	cout << name << ": ";
	for (int i = 0; i < location.size(); ++i) {
		if (i == location.size() - 1) {
			cout << location[i] << "\n";
		}
		else {
			cout << location[i] << ", ";
		}
	}
}

void Word::printToFile(ofstream& file) {
	file << name << ": ";
	for (int i = 0; i < location.size(); ++i) {
		if (i == location.size() - 1) {
			file << location[i] << "\n";
		}
		else {
			file << location[i] << ", ";
		}
	}
}