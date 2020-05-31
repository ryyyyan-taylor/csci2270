#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include "Graph.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
	Graph g;
	string filename = argv[1];
	string line="", pLine="", cityName;
	vector<string> cities;
	int count=0, count2=0, position=0;
	ifstream file(filename);

	if(file.is_open()){
		while(getline(file,line)){
			stringstream ss;
			ss<<line;
			count2=position=0;
			if(count==0){
				count++;
				while(getline(ss, pLine, ',')){
					if(pLine=="cities") continue;
					cities.push_back(pLine);
					g.addVertex(pLine);
				}
			}
			while(getline(ss, pLine, ',')){
				if(count2==0){
					count2++;
					cityName = pLine;
					continue;
				}
				if(stoi(pLine)>0){
					cout<<" ... Reading in "<<cityName<<" -- "<<cities[position]<<" -- "<<stoi(pLine)<<endl;
					g.addEdge(cityName, cities[position], stoi(pLine));
				}
				position++;
			}

		}
	}

	cout<<"------------------------------"<<endl;
	cout<<"Breadth First Traversal"<<endl;
	cout<<"------------------------------"<<endl;
	g.printBFT();

	cout<<"------------------------------"<<endl;
	cout<<"Depth First Traversal"<<endl;
	cout<<"------------------------------"<<endl;
	g.printDFT();

	cout<<"------------------------------"<<endl;
	cout<<"Display Edges"<<endl;
	cout<<"------------------------------"<<endl;
	g.displayEdges();

	return 0;
}