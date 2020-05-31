
#include <iostream>
#include "BST.hpp"
using namespace std;

Node* BST::createNode(int data){
	Node* temp = new Node;
	temp->key = data;
	temp->right = temp->left = NULL;
	return temp;
}

Node* BST::addNodeHelper(Node* currNode, int data){
	if(currNode==NULL) currNode=createNode(data);
	else if(data<currNode->key) currNode->left = addNodeHelper(currNode->left, data);
	else currNode->right = addNodeHelper(currNode->right, data);
	return currNode;
}

// Node* BST::deleteNodeHelper(Node* currNode, int data){
// 	if(currNode==NULL) return NULL;
// 	else if(data<currNode->key) currNode->left=deleteNodeHelper(currNode->left, data);
// 	else if(value>currNode->key) currNode->right=deleteNodeHelper(currNode->right, data);
// }

Node* BST::searchKeyHelper(Node* currNode, int data){
	if(currNode==NULL) return nullptr;
	if(data==currNode->key) return currNode;
	if(data<currNode->key) return searchKeyHelper(currNode->left, data);
	if(data>currNode->key) return searchKeyHelper(currNode->right, data);
}

void BST::printTreeHelper(Node* currNode){
	if(currNode==NULL) return;
	printTreeHelper(currNode->left);
	cout<<" "<<currNode->key;
	printTreeHelper(currNode->right);
}

void BST::destroyNode(Node *currNode){
	if(currNode){
		destroyNode(currNode->left);
		destroyNode(currNode->right);
		delete currNode;
		currNode=NULL;
	}
}

// void print2DUtilHelper(Node* currNode, int space){
// 	if(currNode==NULL) return;
// 	space += COUNT;
// 	print2DUtilHelper(currNode->right, space);
// 	cout<<endl;
// 	for(int i=COUNT; i<space; i++)
// 		cout<<" "<<endl;
// 	printf("%d\n", currNode->key);
// }

void BST::addNode(int data){
	root=addNodeHelper(root, data);
	return;
}

// void BST::deleteNode(int data){
// 	root=deleteNodeHelper(root, data);
// 	return;
// }

bool BST::searchKey(int data){
	Node *x = searchKeyHelper(root, data);
	if(x==NULL) return false;
	else return true;
}

void BST::printTree(){
	if(root==NULL){
		cout<<"Empty Tree"<<endl;
		return;
	}
	printTreeHelper(root);
	return;
}

BST::BST(){
	root=NULL;
}

BST::BST(int data){
	root=createNode(data);
}

BST::~BST(){
	destroyNode(root);
}

// void BST::print2DUtil(int space){
// 	print2DUtilHelper(root, space);
// 	return;
// }

int sumRangeHelper(Node* x, int min, int max, int& sum){
	if(x==NULL) return sum;
	sumRangeHelper(x->left, min, max, sum);
	if(x->key>=min && x->key<=max) sum += x->key;
	sumRangeHelper(x->right, min, max, sum);
}

int BST::sumRange(int min, int max){
	if(root==NULL) return 0;
	int sum=0;
	int x = 0;
	x = sumRangeHelper(root, min, max, sum);
	return x;
}