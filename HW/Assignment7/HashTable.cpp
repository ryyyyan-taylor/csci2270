#include <iostream>
#include "HashTable.hpp"
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

HashTable::HashTable(int size){
	hashTable = new wordItem*[size];
	for(int i=0; i<size;i++)
		hashTable[i] = NULL;
	hashTableSize = size;
}

HashTable::~HashTable(){
	for(int i=0;i<hashTableSize;i++){
		wordItem* entry = hashTable[i];
		while(entry!=NULL){
			wordItem* prev = entry;
			entry = entry->next;
			delete prev;
		}
	}
	delete hashTable;
}

wordItem* newWordItem(string word){
	wordItem* temp = new wordItem;
	temp->word = word;
	temp->count = 0;
	temp->next = NULL;
	return temp;
}

void HashTable::addWord(string word){
	numItems++;
	if(word=="") return;
	int hashVal = getHash(word);
	wordItem* prev = new wordItem;
	prev = NULL;
	wordItem* entry = new wordItem;
	entry = hashTable[hashVal];
	if(entry!=NULL) numCollisions++;
	while(entry!=NULL){
		prev = entry;
		entry = entry->next;
	}
	entry = newWordItem(word);
	if(prev==NULL) hashTable[hashVal] = entry;
	else prev->next = entry;
}

bool HashTable::isInTable(string word){
	wordItem* temp = searchTable(word);
	if(temp==NULL) return false;
	else return true;
}

void HashTable::incrementCount(string word){
	wordItem* temp = searchTable(word);
	temp->count++;
}

void HashTable::printTopN(int n){
	wordItem* uniqueWords[numItems];
	wordItem* temp;
	int ct = 0;
	for(int i=0;i<hashTableSize;i++){
		temp = hashTable[i];
		while(temp!=NULL){
			uniqueWords[ct] = temp;
			temp = temp->next;
			ct++;
		}
	}

	for(int j=0;j<numItems-1;j++){
		for(int i=0;i<numItems-1;i++){
			if(uniqueWords[i]->count < uniqueWords[i+1]->count){
				temp = uniqueWords[i];
				uniqueWords[i] = uniqueWords[i+1];
				uniqueWords[i+1] = temp;
			}
		}
	}
	for(int i=0;i<n;i++){
		float count = uniqueWords[i]->count;
		float total = getTotalNumWords();
		float prob = count / total;
		cout<<fixed<<setprecision(4)<<prob + 0.00002<<" - "<<uniqueWords[i]->word<<endl;
	}
}

int HashTable::getNumCollisions(){
	return numCollisions;
}

int HashTable::getNumItems(){
	return numItems;
}

int HashTable::getTotalNumWords(){
	int totalWords = 0;
	for(int i=0;i<hashTableSize;i++){
		wordItem* temp = hashTable[i];
		while(temp!=NULL){
			totalWords+=temp->count;
			temp = temp->next;
		}
	}
	return totalWords + numItems;
}

unsigned int HashTable::getHash(string word){
	unsigned int hashValue = 5381;
	int length = word.length();
	for(int i=0;i<length;i++)
		hashValue=(hashValue<<5)+ hashValue + word[i];
	hashValue %= hashTableSize;
	return hashValue;
}

wordItem* HashTable::searchTable(string word){
	int hashVal = getHash(word);
	wordItem *entry = hashTable[hashVal];
	while(entry!=NULL){
		if(entry->word == word) return entry;
		entry = entry->next;
	}
	return NULL;
}

void getStopWords(char *ignoreWordFileName, HashTable &stopWordsTable){
	string line = "";
	ifstream file(ignoreWordFileName);
	if(file.is_open()){
		while(getline(file,line)){
			if(!stopWordsTable.isInTable(line)) stopWordsTable.addWord(line);
			else stopWordsTable.incrementCount(line);
		}
	}
	file.close();
}

bool isStopWord(string word, HashTable &stopWordsTable){
	if(stopWordsTable.isInTable(word)) return true;
	else return false;
}