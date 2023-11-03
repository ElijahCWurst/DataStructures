#include <iostream>
#include <fstream>
#include <string>
#include "Stack.h"

using namespace std;

void delimiterMatching(fstream &file);

int main(int argc, char* argv[])
{
	/*for (int i = 0; i < argc; i++) {
		cout << i << ": " << argv[i] << endl;
	}*/
	if (argc == 1) {
		string input = "";
		do {
			fstream file;
			while (!file.is_open()) {
				cout << "Enter a filepath: " << endl;
				getline(cin, input);
				file.open(input);
				if (!file.is_open()) {
					cout << "Try again, with an actual file. >:( \n";
				}
			}

			delimiterMatching(file);

			cout << "Again? (y/n): ";
			getline(cin, input);
		} while (input == "y" || input == "Y");
	}
	else if (argc >= 2) {
		for (int i = 1; i < argc; ++i) {
			fstream file;
			file.open(argv[i]);
			if (!file.is_open()) {
				cout << "Could not open file: '" << argv[i] << "'" << endl
					<< "Try again, with an actual file. >:( \n";
			}
			else {
				cout << "Checking file: '" << argv[i] << "'\n";
				delimiterMatching(file);
			}
		}
	}
}


void delimiterMatching(fstream &file) {
	Stack stack;
	char value;
	unsigned int LineNumber = 1;
	bool startingComment = false;
	bool failed = false;
	bool inComment = false;

	while (file.get(value)) {
		if (value == '\n') {
			++LineNumber;
		}
		else if (value == '(' || value == '[' || value == '{') {
			stack.push_back(value);
		}
		else if (value == ')' || value == ']' || value == '}') {
			if (!stack.isEmpty()) {
				char top = stack.getTop();
				bool goodJob = false;
				string message;
				switch (top)
				{
				case '(':
					if (!(goodJob = value == ')')) {
						message = ")";
					}
					break;
				case '[':
					if (!(goodJob = value == ']')) {
						message = "]";
					}
					break;
				case '{':
					if (!(goodJob = value == '}')) {
						message = "}";
					}
					break;
				default:
					break;
				}
				if (!goodJob) {
					cout << "FAIL" << endl << "Line Number: " << LineNumber << endl;
					cout << "Expected '" << message << "' Got '" << value << "'" << endl;
					failed = true;
					break;
				}
				else {
					stack.pop_back();
				}
			}
			else {
				cout << "FAIL" << endl << "Line Number: " << LineNumber << endl;
				cout << "Did not expect a '" << value << "'" << endl;
				failed = true;
				break;
			}
		}
		else if (value == '/' && !startingComment) {
			startingComment = true;
		}
		else if (startingComment) {
			startingComment = false;
			if (value == '*') {
				inComment = true;
				while (file.get(value)) {
					if (value == '\n') {
						LineNumber++;
					}
					else if (value == '*') {
						file.get(value);
						if (value == '/') {
							inComment = false;
							break;
						}
					}
				}
			}
			else if (value == '/') {
				while (file.get(value)) {
					if (value == '\n') {
						break;
					}
				}
				LineNumber++;
			}
		}
	}
	
	cout << endl;
	if (inComment) {
		cout << "There was an unclosed comment.\n";
	}
	if (stack.isEmpty() && !failed) {
		cout << "Congratulations!!!\nNo errors found!\n" << endl;
	}
	else {
		cout << "you suck.\n" << endl;
	}

}
