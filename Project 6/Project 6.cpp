#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

string fixWord(string word);

int main()
{
	int verseNumber = 0;
	string word = "";
	fstream file;
	file.open("files/john3.txt");
	while (!file.eof()) {
		file >> word;
		try {
			verseNumber = stoi(word);
			continue;
		} catch(exception) {}

		cout << verseNumber << " " << fixWord(word) << "\n";
	}


}


string fixWord(string word) {
	const size_t TO_REMOVE_LENGTH = 8;
	const char TO_REMOVE[TO_REMOVE_LENGTH] = { '!', '.', ',', ';', ':', '"', '(', ')' };
	for (auto i = 0; i < TO_REMOVE_LENGTH; i++) {
		word.erase(remove(word.begin(), word.end(), TO_REMOVE[i]), word.end());
	}
	if (word[0] == '\'') { word.erase(0, 1); }
	if (word[word.size() - 1] == '\'') { word.erase(word.size() - 1);}
	transform(word.begin(), word.end(), word.begin(), tolower);
	return word;
}