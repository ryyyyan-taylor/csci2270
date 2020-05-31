#include <iostream>
#include "hash.hpp"
#include <string>
using namespace std;

node* HashTable::createNode(int key){
	node* temp = new node;
	temp->data = key;
	temp->next=NULL;
	return temp;
}

HashTable::HashTable(int size){
	hashTable = new node*[size];
	for(int=0;i<size;i++) hashTable[i]=NULL;
	tableSize=size;
}

bool HashTable::insertItem(int key){
	int hashVal = hashFunction(key);
	node* prev = new node;
	prev = NULL;
	node* entry = new node;
	entry = hashTable[hashVal];
	while(entry!=NULL){
		if(entry->data == key) return false;
		prev=entry;
		entry=entry->next;
	}
	entry = createNode(key);
	if(prev==NULL) hashTable[hashVal] = entry;
	else prev->next = entry;
	return true;
}

unsigned int HashTable::hashFunction(int key){

}

void HashTable::printTable(){
	node *x = new node;
	for(int i=0; i<tableSize; i++){
		cout<< i <<"||";
		x = hashTable[i];
		while(x){
			cout<<" "<<x->data;
			x = x->next;
		}
		cout<<endl;
	}
}

node* HashTable::searchItem(int key){
	int hashVal = hashFunction(key);
	node* entry = hashTable[hashVal];
	while(entry!=NULL){
		if(entry->data==key) return entry;
		entry = entry->next;
	}
	return NULL;
}