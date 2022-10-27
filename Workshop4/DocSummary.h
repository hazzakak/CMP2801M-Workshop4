#ifndef DOCHEADER
#define DOCHEADER

#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <fstream>
#include "WordFreqPair.h"

using namespace std;

class DocSummary {
	private:
		int numberOfWords;
		int numberOfSentences;
		string filename;
		vector<WordFreqPair> wordList;

		void increaseSentenceCount();
		void addWord(string word);

	public:
		DocSummary(string);
		void printSummary();
		void analyseDocument();
};

#endif // !1
