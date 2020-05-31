#include <iostream>
#include "heaps.hpp"
using namespace std;

float heapSort(float arr[], int size){
	Heap arrIn(size);
	for(int i=0; i<size; i++){
		arrIn.addToHeap(arr[i]);
	}
}


int main(){
	float g[10];
	for(int i=0; i<10; i++){
		g[i] = i;
	}
	float out = heapSort(g, 10);
}