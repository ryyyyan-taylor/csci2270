#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "PriorityQueue.hpp"
using namespace std;

void displayMenu(){
	cout<<"============Main Menu============"<<endl;
	cout<<"1. Get group information from file"<<endl;
	cout<<"2. Add a group to Priority Queue"<<endl;
	cout<<"3. Show next group in the queue"<<endl;
	cout<<"4. Serve Next group"<<endl;
	cout<<"5. Serve Entire Queue"<<endl;
	cout<<"6. Quit"<<endl;
}

int main(int argc, char *argv[]){
	string choice, input, line, line2, name, size, cTime;
	int totalCookTime=0;
	PriorityQueue pQueue(stoi(argv[1]));
	while(true){
		displayMenu();
		getline(cin,choice);
		switch(stoi(choice)){
			case 1:{
				cout<<"Enter filename:"<<endl;
				getline(cin,input);
				ifstream file(input);
				while(getline(file,line)){
					stringstream ss;
					ss<<line;
					getline(ss,line2,' ');
					name=line2;
					getline(ss,line2,' ');
					size=line2;
					getline(ss,line2,' ');
					cTime=line2;
					if(pQueue.isFull()){
						cout<<"Heap full, cannot enqueue"<<endl;
						break;
					}
					else pQueue.enqueue(name, stoi(size), stoi(cTime));
				}
				file.close();
				break;
			}

			case 2:
				cout<<"Enter Group Name:"<<endl;
				getline(cin,name);
				cout<<"Enter Group Size:"<<endl;
				getline(cin,size);
				cout<<"Enter Estimated Cooking Time:"<<endl;
				getline(cin,cTime);
				if(pQueue.isFull()){
					cout<<"Heap full, cannot enqueue"<<endl;
					break;
				}
				else pQueue.enqueue(name, stoi(size), stoi(cTime));
				break;

			case 3:
				if(pQueue.isEmpty()){
					cout<<"Heap empty, nothing to peek"<<endl;
					break;
				}
				cout<<"Group Name: "<<pQueue.peek().groupName<<endl;
				cout<<"Group Size: "<<pQueue.peek().groupSize<<endl;
				cout<<"Group Time: "<<pQueue.peek().cookingTime<<endl;
				break;

			case 4:
				if(pQueue.isEmpty()){
					cout<<"Heap empty, cannot dequeue"<<endl;
					break;
				}
				totalCookTime+=pQueue.peek().cookingTime;
				cout<<"Group Name: "<<pQueue.peek().groupName<<" - Total Cook Time for the Group: "<<totalCookTime<<endl;
				pQueue.dequeue();
				break;

			case 5:
				if(pQueue.isEmpty()){
					cout<<"Heap empty, cannot dequeue"<<endl;
					break;
				}
				while(!pQueue.isEmpty()){
					totalCookTime+=pQueue.peek().cookingTime;
					cout<<"Group Name: "<<pQueue.peek().groupName<<" - Total Cook Time for the Group: "<<totalCookTime<<endl;
					pQueue.dequeue();
				}
				break;
				
			case 6:
				cout<<"Goodbye!"<<endl;
				return 0;
		}
	}
}