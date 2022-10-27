#ifndef DOCFILE
#define DOCFILE

#include "DocSummary.h"

using namespace std;

int numberOfSentences;
int numberOfWords;
string filename;
vector<WordFreqPair> wordList;

DocSummary::DocSummary(string fn) {
	filename = fn;
}

void DocSummary::increaseSentenceCount() {
	numberOfSentences = numberOfSentences + 1;
}

void DocSummary::addWord(string word) {
	bool exists = false;

	numberOfWords = numberOfWords + 1;

	if (word.find('!') != string::npos || word.find('.') != string::npos) {
		increaseSentenceCount();
	}

	auto tempWordX = remove_if(word.begin(), word.end(), ispunct);
	word.erase(tempWordX, word.end());

	for (int i = 1; i < wordList.size(); i++) {
		if (wordList.at(i).word == word) {
			wordList.at(i).freq++;
			exists = true;
			break;
		}
		else {
			exists = false;
		}
	}
	if (!exists) {
		WordFreqPair tempWordVec(word);
		wordList.push_back(tempWordVec);
	}
}

void DocSummary::printSummary() {
	numberOfWords--;
	cout << filename << endl;
	cout << "Number of words \t" << numberOfWords << endl;
	cout << "Number of sentences \t" << numberOfSentences << endl;

	for (WordFreqPair y : wordList) {
		cout << y.word << "\t" << y.freq << endl;
	}
}

void DocSummary::analyseDocument() {
	ifstream myfile(filename);
	string contents((std::istreambuf_iterator<char>(myfile)),
		(std::istreambuf_iterator<char>()));
	myfile.close();

	istringstream iss(contents);
	do {
		string word;

		// Get the word from the istringstream
		iss >> word;

		addWord(word);

	} while (iss);		
}

#endif // !1