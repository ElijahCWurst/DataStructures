#include <iostream>
#include <string>
#include <fstream>

using namespace std;
int* getSize(string&);
void treeFinder(int, int**&, char**&, int, int, int, int);

int main(int argc, char* argv[])
{

	ofstream outFile;
	string userInput = "";
	fstream file;
	bool fileOutput = false;


	if (argc >= 3) {
		file.open(argv[1]);
		if (!file) {
			cout << "Fail!" << endl;
			return -1;
		}
		fileOutput = true;
		outFile.open(argv[2]);
	}
	if (argc == 2) {
		file.open(argv[1]);
		if (!file) {
			cout << "Fail!" << endl;
			return -1;
		}
	}
	if(argc == 1) {
		do {
			cout << "Enter filepath" << endl;
			getline(cin, userInput);
			file.open(userInput);
			if (!file) cout << "Try again!" << endl;
		} while (!file);
	}
	
	string input = "";
	getline(file, input);
	
	auto size = getSize(input);
	const int HEIGHT = size[0];
	const int WIDTH = size[1];

	//Dynamically allocate 2d array
	int** standsMap = new int*[HEIGHT];
	char** baseMap = new char*[HEIGHT];


	//Initialize the arrays
	for (int i = 0; i < HEIGHT; ++i) {
		baseMap[i] = new char[WIDTH];
		standsMap[i] = new int[WIDTH];
	}
	for (int i = 0; i < HEIGHT; ++i) {
		for (int j = 0; j < WIDTH; ++j) {
			baseMap[i][j] = '0';
			standsMap[i][j] = 0;
		}
	}

	getline(file, input);
	for (int i = 0; i < HEIGHT; ++i) {
		if (input == "") {
			break;
		}
		for (int j = 0; j < WIDTH; ++j) {
			baseMap[i][j] = input[j * 2];
		}
		getline(file, input);

	}

	int standsCount = 0;
	for (int i = 0; i < HEIGHT; ++i) {
		for (int j = 0; j < WIDTH; ++j) {
			if (baseMap[i][j] == 't' && standsMap[i][j] == 0) {
				standsCount++;
				treeFinder(standsCount, standsMap, baseMap, i, j, HEIGHT, WIDTH);
			}
			else if (baseMap[i][j] == 'g') {
				baseMap[i][j] = ' ';
			}
		}
	}

	if (fileOutput) {

		outFile << "Total Stands: " << standsCount << endl << endl;

		for (int i = 0; i < HEIGHT; ++i) {
			for (int j = 0; j < WIDTH; ++j) {
				outFile << standsMap[i][j] << ' ';
			}
			outFile << endl;
		}
		outFile << endl;
		outFile << endl;
		for (int i = 0; i < HEIGHT; ++i) {
			for (int j = 0; j < WIDTH; ++j) {
				outFile << baseMap[i][j] << ' ';
			}
			outFile << endl;
		}

	}
	else if (!fileOutput) {
		cout << "Total Stands: " << standsCount << endl << endl;

		cout << "Output tables?(y/n) NOTE: It is not recommended if you are testing a large file)" << endl;
		getline(cin, userInput);

		if (userInput == "y") {

			for (int i = 0; i < HEIGHT; ++i) {
				for (int j = 0; j < WIDTH; ++j) {
					cout << standsMap[i][j] << ' ';
				}
				cout << endl;
			}
			cout << endl;
			cout << endl;
			for (int i = 0; i < HEIGHT; ++i) {
				for (int j = 0; j < WIDTH; ++j) {
					cout << baseMap[i][j] << ' ';
				}
				cout << endl;
			}
		}
	}
}

//Extracting the length and width from the file
int* getSize(string &input) {
	string value = "";

	string row = input.substr(0, input.find(','));
	string column = input.substr(input.find(',') + 1);
	
	int* toReturn = new int[2];

	toReturn[0] = stoi(row.substr(row.find('=') + 1));
	toReturn[1] = stoi(column.substr(column.find('=') + 1));

	return toReturn;
}


//Recursive function
void treeFinder(int standCount, int**& standsMap, char**& baseMap, int row, int col, int Height, int Width) {

	if (row >= Height || col >= Width || row < 0 || col < 0) {
		return;
	}
	if (standsMap[row][col] != 0) {
		return;
	}
	else if(baseMap[row][col] == 't'){
		standsMap[row][col] = standCount;
		treeFinder(standCount, standsMap, baseMap, row, col + 1, Height, Width);
		treeFinder(standCount, standsMap, baseMap, row + 1, col, Height, Width);
		treeFinder(standCount, standsMap, baseMap, row, col - 1, Height, Width);
		treeFinder(standCount, standsMap, baseMap, row - 1, col, Height, Width);
	}
	else {
		return;
	}
}