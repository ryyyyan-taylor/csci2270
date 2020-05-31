#include <iostream>
#include <string>
#include <cstring>
#include "PriorityQueue.hpp"
using namespace std;

int parent(int i) { return (i-1)/2; }

int right(int i) { return 2*i+2; }

int left(int i) { return 2*i+1; }

void swap(GroupNode& x, GroupNode& y){
	GroupNode temp = x;
	x=y;
	y=temp;
}

PriorityQueue::PriorityQueue(int queueSize){
	maxQueueSize = queueSize;
	currentQueueSize = 0;
	priorityQueue = new GroupNode[queueSize];
	// for(int i=0;i<queueSize;i++){
	// 	priorityQueue[i] = nullptr;
	// }
}

PriorityQueue::~PriorityQueue(){
	// for(int i=0;i<currentQueueSize;i++){
	// 	delete priorityQueue[i];
	// }
}

void PriorityQueue::enqueue(string _groupName, int _groupSize, int _cookingTime){
	if(currentQueueSize>=maxQueueSize){
		cout<<"Heap full, cannot enqueue"<<endl;
		return;
	}
	currentQueueSize++;
	int index=currentQueueSize-1;
	GroupNode addedGroup;
	addedGroup.groupSize=_groupSize;
	addedGroup.groupName=_groupName;
	addedGroup.cookingTime=_cookingTime;
	priorityQueue[index]=addedGroup;
	if(index>0) repairUpward(index);
}

void PriorityQueue::dequeue(){
    if(isEmpty()){
        cout<<"Heap empty, cannot dequeue"<<endl;
        return;
    }
	GroupNode temp = priorityQueue[0];
	priorityQueue[0] = priorityQueue[currentQueueSize-1];
	currentQueueSize--;
	repairDownward(0);
}

GroupNode PriorityQueue::peek(){
	if(isEmpty()) cout<<"Heap empty, nothing to peek"<<endl;
	else return priorityQueue[0];
}

bool PriorityQueue::isFull(){
	if(currentQueueSize>=maxQueueSize) return true;
	else return false;
}

bool PriorityQueue::isEmpty(){
	if(priorityQueue==NULL) return true;
	else if(currentQueueSize==0) return true;
	else return false;
}

void PriorityQueue::repairUpward(int nodeIndex){
	int parentIndex = parent(nodeIndex);
	int smallest = nodeIndex;

	if(priorityQueue[nodeIndex].groupSize<priorityQueue[parentIndex].groupSize) smallest=parentIndex;
	else if(priorityQueue[nodeIndex].groupSize==priorityQueue[parentIndex].groupSize){
		if(priorityQueue[nodeIndex].cookingTime<priorityQueue[parentIndex].cookingTime){
			smallest=parentIndex;
		}
	}
	if(smallest!=nodeIndex){
		swap(priorityQueue[nodeIndex], priorityQueue[smallest]);
		repairUpward(smallest);
	}
}

void PriorityQueue::repairDownward(int nodeIndex){
	int smallest=nodeIndex;
	int l=left(nodeIndex);
	int r=right(nodeIndex);

	if(l<currentQueueSize){
		if(priorityQueue[l].groupSize<priorityQueue[nodeIndex].groupSize) smallest=l;
		else if(priorityQueue[l].groupSize==priorityQueue[nodeIndex].groupSize){
			if(priorityQueue[l].cookingTime<priorityQueue[nodeIndex].cookingTime){
				smallest=l;
			}
		}
	}
	
	if(r<currentQueueSize){
		if(priorityQueue[r].groupSize<priorityQueue[smallest].groupSize) smallest=r;
		else if(priorityQueue[r].groupSize==priorityQueue[smallest].groupSize){
			if(priorityQueue[r].cookingTime<priorityQueue[smallest].cookingTime){
			smallest=r;
			}
		}
	}

	if(smallest!=nodeIndex){
		swap(priorityQueue[smallest], priorityQueue[nodeIndex]);
		repairDownward(smallest);
	}
	return;
}