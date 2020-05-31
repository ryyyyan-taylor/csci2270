/*
Starter HPP File for Hash Tables.
DISCLAIMER: We recommend everyone to at least have these functions implemented properly.

For the exams the variable type might change form int to char / any other custom type.
You will also have extra functions which will be the main exam problems. These will just be added to this hpp file and it will be given to you during your exam
*/



#ifndef HASH_HPP
#define HASH_HPP

#include <string>

using namespace std;

// Struct for a linked list node
struct node
{
    int data; // data to be stored in the node
    struct node* next; // pointer to the next node
};

class HashTable
{
    // No. of buckets (Size of the Hash Table)
    int tableSize;

    // Pointer to an array containing buckets (the Hash Table)
    node **hashTable;

  	/*
  	Method Name: createNode
  	Purpose: Create a node with data as 'key'
    return: pointer to the new node
  	*/
    node* createNode(int key);

    public:

    /*
    constructor
    Purpose: perform all operations necessary to instantiate a class object
    Param: Size of the Hash Table
    return: none
    */
    HashTable(int bsize);

  	/*
  	Method Name: insertItem
  	Purpose: inserts a node with data as 'key' into the Hash Table
    return: false if 'key' already exists in the table, otherwise true
  	*/
    bool insertItem(int key);

    /*
  	Method Name: hashFunction
  	Purpose: function to hash "key" into an index
    return: index in the Hash Table
  	*/
    unsigned int hashFunction(int key);

    /*
  	Method Name: printTable
  	Purpose: function to display the Hash Table
    return: none
  	*/
    void printTable();

    /*
  	Method Name: searchItem
  	Purpose: function to search for "key" in the Hash Table
    return: node with "key" as it's data if found, otherwise NULL
  	*/
    node* searchItem(int key);
};

#endif
