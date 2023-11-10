#pragma once
#include <string>
#include <vector>

using namespace std;

//The "Word" class contains the word that it represents, as well as a vector containing all the verses that it is used in.
class Word
{
public: 
	string name = "";
	vector<int> location;
	Word();
	Word(string name);
	void print();
};

