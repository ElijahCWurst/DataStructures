#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "BST.h"

using namespace std;

string fixWord(string word);
void addWord(string word, BST& tree, int verseNum);

//This function was made by Tim Zink
void printNode(Word* word, int depth, int position, vector<int>* also) {
	for (int i = 0; i < depth; i++) {
		if (find(also->begin(), also->end(), i) != also->end()) {
			cout << "|   ";
		}
		else {
			cout << "    ";
		}
	}
	if (position == 1) { cout << "/ "; }
	else if (position == -1) { cout << "\\ "; }
	cout << word->name << endl;
}


int main(int argc, char* argv[])
{

	BST Tree;
	int verseNumber = 0;
	string word = "";
	string fileName = "";
	fstream file;
	ofstream outFile;
	bool fileOutput = false;


	if (argc >= 3) {
		cout << argv[1] << "\n";
		cout << argv[2] << endl;
		file.open(argv[1]);
		if (!file) {
			cout << "Fail!" << endl;
			return -1;
		}
		fileOutput = true;
		outFile.open(argv[2]);
		if (!outFile) {
			cout << "Fail!" << endl;
		}
	}
	if (argc == 2) {
		file.open(argv[1]);
		if (!file) {
			cout << "Fail!" << endl;
			return -1;
		}
	}
	if (argc == 1) {
		do {
			cout << "Enter filepath" << endl;
			getline(cin, fileName);
			file.open(fileName);
			if (!file) cout << "Try again!" << endl;
		} while (!file);
	}

	while (!file.eof()) {
		file >> word;
		try {
			verseNumber = stoi(word);
			continue;
		}
		catch (exception) {}

		addWord(word, Tree, verseNumber);

	}

	if (fileOutput) {
		Tree.inOrder(outFile);
	}
	else if(!fileOutput) {
		Tree.inOrder();
	}
	//Tree.PrintStructure(&printNode);  //This line prints out the entire tree visually. This function was made by Timothy Zink
}



// This function takes out all special symbols including punctuation. It also converts possessives 
string fixWord(string word) {
	const int TO_REMOVE_LENGTH = 9;
	const char TO_REMOVE[TO_REMOVE_LENGTH] = { '!', '.', ',', ';', ':', '"', '(', ')', '?'};
	for (int i = 0; i < TO_REMOVE_LENGTH; ++i) {
		word.erase(remove(word.begin(), word.end(), TO_REMOVE[i]), word.end());
	}
	const size_t MAX_INDEX = word.size() - 1;
	if (word[0] == '\'') { word.erase(0, 1); }
	if (word[MAX_INDEX] == '\'') { word.erase(MAX_INDEX);}
	transform(word.begin(), word.end(), word.begin(), tolower);
	transform(word.begin(), ++word.begin(), word.begin(), toupper);  //Add this if you want the words to be capitalized

	if (word[MAX_INDEX] == 's' && word[MAX_INDEX - 1] == '\'') {
		word.erase(MAX_INDEX - 1, MAX_INDEX);
	}
	return word;
}

void addWord(string word, BST& tree, int verseNum) {
	if (word == "") {
		return;
	}
	size_t dashAt = word.find('-');
	if (dashAt == string::npos) {
		Word* wordNode = new Word(fixWord(word));
		tree.insert(wordNode, verseNum);
	}
	else {
		addWord(word.substr(0, dashAt), tree, verseNum);
		addWord(word.substr(dashAt + 1), tree, verseNum);
	}
	
}

