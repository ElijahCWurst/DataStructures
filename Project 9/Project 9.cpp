#include <iostream>
#include "Heap.h"
#include <fstream>
#include <string>
#include <list>

using namespace std;

int main(int argc, char* argv[])
{
	fstream inFile;
	ofstream outFile;
	Heap heap;
	string inFilePath = "";
	string outFilePath = "";
	string flag = "";
	string fromFile = "";
	bool isAscending = false;
	bool isOutFile = false;
	list<int> sizedList;

	if (argc == 1 || argc == 2 || argc > 4) {
		isOutFile = false;
		while (!inFile.is_open()) {
			cout << "Please enter a filepath for an input file.\n";
			getline(cin, inFilePath);
			inFile.open(inFilePath);
			if (!inFile) cout << "Cout not open file. Try again!\n";
		}
		cout << "Would you like to sort the data in ascending(-a) or descending(-d) order?\nType either \"-a\" or \"-d\"\n";
		getline(cin, flag);
	} else {
		inFile.open(argv[1]);
		if (!inFile) {
			cout << "Failed! Could not open file.\n";
			return -1;
		}
		if (argc == 3) {
			flag = argv[2];
			isOutFile = false;
		}
		else if (sizeof(*argv[2]) / sizeof(char) <= 2) {
			flag = argv[2];
			outFilePath = argv[3];
			isOutFile = true;
		}
		else {
			flag = argv[3];
			outFilePath = argv[2];
			isOutFile = true;
		}
	}

	if (flag == "a" || flag == "-a") isAscending = true;
	if (flag == "d" || flag == "-d") isAscending = false;

	while (!inFile.eof()) {
		getline(inFile, fromFile);
		if (fromFile == "") continue;
		sizedList.push_back(stoi(fromFile));
	}

	int arraySize = sizedList.size();
	int* data = new int[arraySize];
	list<int>::iterator it = sizedList.begin();

	for (int i = 0; i < arraySize; ++i, ++it) {
		data[i] = *it;
	}

	heap.HeapSort(data, arraySize, isAscending);

	if (isOutFile) {
		outFile.open(outFilePath);
		heap.printHeap(data, arraySize, outFile);
	}
	else {
		heap.printHeap(data, arraySize);
	}
}