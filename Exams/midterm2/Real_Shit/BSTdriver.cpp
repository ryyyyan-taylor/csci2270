#include <iostream>
#include "BST.hpp"
using namespace std;

int main(){
	BST searchTree;
	searchTree.addNode(100);
	searchTree.addNode(20);
	searchTree.addNode(33);
	searchTree.addNode(18);
	searchTree.addNode(45);
	searchTree.addNode(3);
	searchTree.addNode(12);

	searchTree.printTree();
	cout<<endl;

	cout<<"Gathering sum from 20 -> 50"<<endl;
	cout<<"SUM = "<<searchTree.sumRange(20, 50)<<endl; 
	cout<<"\n\n";

	BST searchTree2;

	searchTree2.addNode(0);
	searchTree2.addNode(0);
	searchTree2.addNode(1);
	searchTree2.addNode(12);
	searchTree2.addNode(6);
	searchTree2.addNode(9);
	searchTree2.addNode(8);

	searchTree2.printTree();
	cout<<endl;

	cout<<"Gathering sum from 5 -> 10"<<endl;
	cout<<"SUM = "<<searchTree2.sumRange(5, 10)<<endl; 
	cout<<"\n\n";

	BST searchTree3;

	searchTree3.printTree();

	cout<<"Gathering sum from 1 -> 1000"<<endl;
	cout<<"SUM = "<<searchTree3.sumRange(1, 1000)<<endl; 

	return 0;
}