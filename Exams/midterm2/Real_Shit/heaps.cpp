#include <iostream>
#include "heaps.hpp"
using namespace std;

Heap::Heap(int maxSize){
	heapSize = maxSize;
	currentSize = 0;
	heap = new float [maxSize];
	for(int i=0; i<maxSize; i++) heap[i]=-1;
}

Heap::~Heap(){
	for(int i=0; i<currentSize; i++) heap[i] = -1;
}

void Heap::printHeap(){

	return;
}

void Heap::addToHeap(float value){
	if(currentSize>=heapSize) return;
	currentSize++;
	int index = currentSize-1;
	heap[index] = value;
	if(index>0) repairUpward(index);
}

float Heap::removeFromHeap(){
	if(isEmpty()) return -1;

}

float Heap::peekValue(){
	if(isEmpty()) return -1;
	else return heap[0];
}

bool Heap::isFull(){
	if(currentSize>=heapSize) return true;
	else return false;
}

bool Heap::isEmpty(){
	if(heap==NULL || currentSize==0) return true;
	else return false;
}

int Heap::parent(int i) { return (i-1)/2; }

int Heap::rightChild(int i) { return 2*i+2; }

int Heap::leftChild(int i) { return 2*i+1; }

void swap(int& x, int& y){
	int temp = x;
	x=y;
	y=temp;
}

void Heap::repairUpward(int index){
	int parentIndex=parent(index);

	if(heap[index]<=heap[parentIndex]){
		swap(heap[index], heap[parentIndex]);
		repairUpward(parentIndex);
	}
}

void Heap::repairDownward(int index){
	int smallest=index;
	int l=leftChild(index);
	int r=rightChild(index);

	if(heap[l]<heap[index]) smallest=l;
	if(heap[r]<heap[index]) smallest=r;
	if(smallest!=index){
		swap(heap[smallest], heap[index]);
		repairDownward(smallest);
	}
}