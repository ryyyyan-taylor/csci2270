#include <iostream>
#include "HashTable.hpp"
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, char *argv[]){
	
	HashTable stopWordsTable(50);
	getStopWords(argv[3], stopWordsTable);

	int size = stoi(argv[4]);
	HashTable wordsTable(size);
	string line, word;

	ifstream file(argv[2]);
	if(file.is_open()){
		while(getline(file,line)){
			stringstream ss;
			ss<<line;
			while(getline(ss,word,' ')){
				if(isStopWord(word,stopWordsTable)==true || word=="") continue;
				else if(wordsTable.isInTable(word)) wordsTable.incrementCount(word);
				else wordsTable.addWord(word);
			}
		}
	}
	wordsTable.printTopN(stoi(argv[1]));
	cout<<"#\nNumber of collisions: "<<wordsTable.getNumCollisions()<<endl;
	cout<<"#\nUnique non-stop words: "<<wordsTable.getNumItems()<<endl;
	cout<<"#\nTotal non-stop words: "<<wordsTable.getTotalNumWords()<<endl;

	file.close();

	return 0;
}