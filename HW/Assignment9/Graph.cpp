#include <iostream>
#include <vector>
#include <queue>
#include "Graph.hpp"
using namespace std;

Graph::Graph(){
	vertices.clear();
}

Graph::~Graph(){
	vertices.clear();
}

void Graph::addVertex(string cityName){
	vertex temp;
	temp.name = cityName;
	temp.visited = false;
	vertices.push_back(temp);
}

void Graph::addEdge(string city1, string city2, int distance){
	Edge temp;
	temp.distance = distance;
	if(findVertex(city2)==NULL) addVertex(city2);
	temp.v = findVertex(city2);
	findVertex(city1)->Edges.push_back(temp);
}

void Graph::displayEdges(){
	for(int i=0; i<vertices.size(); i++){
		cout<<vertices[i].name<<"-->";
		if((vertices[i].Edges).size()==0){
			cout<<endl;
			continue;
		}
		for(int j=0; j<(vertices[i].Edges).size(); j++){
			cout<<vertices[i].Edges[j].v->name<<" ";
			cout<<"("<<vertices[i].Edges[j].distance<<" miles)";
			if(j==vertices[i].Edges.size() - 1) cout<<endl;
			else cout<<"***";
		}
	}
}

void Graph::setAllVerticesUnvisited(){
	for(int i=0; i<vertices.size(); i++) vertices[i].visited = false;
}

void Graph::DFT_traversal(vertex *v){
	v->visited = true;
	cout<<v->name<<endl;
	for(int i=0; i<(v->Edges).size(); i++){
		if(((v->Edges).at(i).v)->visited == false){
			DFT_traversal(((v->Edges).at(i).v));
		}
	}
}

void Graph::printDFT(){
	setAllVerticesUnvisited();
	for(int i=0; i<vertices.size(); i++){
	    if(vertices[i].visited==false) DFT_traversal(&vertices[i]);
	}
}

void Graph::BFT_traversal(vertex *v){
	v->visited = true;
	queue <vertex*> myQueue;
	myQueue.push(v);

	while(!myQueue.empty()){
		v=myQueue.front();
		cout<<v->name<<endl;
		myQueue.pop();
		for(int i=0; i<(v->Edges).size(); i++){
			if((v->Edges).at(i).v->visited==false){
				(v->Edges).at(i).v->visited=true;
				myQueue.push((v->Edges).at(i).v);
			}
		}
	}
}

void Graph::printBFT(){
	setAllVerticesUnvisited();
	for(int i=0; i<vertices.size(); i++){
		if(vertices[i].visited==false) BFT_traversal(&vertices[i]);
	}
}

vertex* Graph::findVertex(string name){
	vertex* found = NULL;
	for(int i=0; i<vertices.size(); i++){
		if(vertices[i].name==name) found = &vertices[i];
	}
	return found;
}