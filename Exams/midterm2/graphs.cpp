#include <iostream>
#include <vector>
#include "graphs.hpp"
using namespace std;

Graph::Graph(){

}

Graph::~Graph(){

}

void Graph::addEdge(int v1, int v2){

}

void Graph::addVertex(int id){
	vertex *temp = new vertex;
	temp->id = id;
	temp->Edges.clear();
	vertices.push_back(temp);
	if(vertices.size>1) vertices.sort(vertices. begin(), v.end());
}

void Graph::displayEdges(){

}

void Graph::printDFT(){

}

void Graph::printBFT(){

}

void Graph::setAllVerticesUnvisited(){

}

vertex* Graph::findVertex(int id){

}

void Graph::BFTraversal(vertex *v){

}

void DFTraversal(vertex *v){
	
}