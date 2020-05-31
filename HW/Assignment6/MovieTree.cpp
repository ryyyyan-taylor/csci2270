#include <iostream>
#include "MovieTree.hpp"
using namespace std;

MovieTree::MovieTree(){
	root = NULL;
}

MovieTree::~MovieTree(){
	
}

void print(TreeNode *x){
	if(x==NULL) {
		return;
	}
	print(x->leftChild);
	cout<<"Movies starting with letter:"<< x->titleChar<<endl;
	LLMovieNode *n = new LLMovieNode;
	n = x->head;
	while(n!=NULL){
		cout<<">>"<<n->title<<" "<<n->rating<<endl;
		n = n->next;
	}  
	print(x->rightChild);
}

void MovieTree::printMovieInventory(){
	TreeNode *x = new TreeNode();
	x = root;
	print(x);
	return;
}

LLMovieNode* newLLNode(int ranking, string title, int year, float rating, LLMovieNode *next){
	LLMovieNode *temp = new LLMovieNode;
	temp->ranking = ranking;
	temp->title = title;
	temp->year = year;
	temp->rating = rating;
	temp->next = next;
	return temp;
}

TreeNode* newTreeNode(char titleChar){
	TreeNode *temp = new TreeNode;
	temp->titleChar = titleChar;
	temp->parent = temp->leftChild = temp->rightChild = NULL;
	temp->head = NULL;
	return temp;
}

TreeNode* insertNewBranch(TreeNode* root, char titleChar){
	if(root==NULL) return newTreeNode(titleChar);
	if(titleChar<root->titleChar) root->leftChild = insertNewBranch(root->leftChild, titleChar);
	else if(titleChar>root->titleChar) root->rightChild = insertNewBranch(root->rightChild, titleChar);
	return root;
}

TreeNode* insert(int ranking, string title, int year, float rating, TreeNode* x, TreeNode* root){
	if(x==NULL){
		x = newTreeNode(title[0]);
		LLMovieNode *u = new LLMovieNode;
		u = newLLNode(ranking, title, year, rating, NULL);
		x->head = u;
		if(root==NULL) root=x;
		else insertNewBranch(root, title[0]);
	}	
	
	else if(x->titleChar == title[0]){
		LLMovieNode *p = new LLMovieNode;
		p = x->head;
		LLMovieNode *n = new LLMovieNode;
		here:
		if(title.compare(p->title) < 0){
			n = newLLNode(ranking, title, year, rating, p);
			x->head = n;
			return x;
		}
		if(p->next == NULL){
			p->next = newLLNode(ranking, title, year, rating, NULL);
			return x;
		}
		if(title.compare(p->next->title) < 0){
			n = newLLNode(ranking, title, year, rating, p->next);
			p->next = n;
			return x;
		}
		else{
			p = p->next;
			goto here;
		}
	}
	else if(title[0]<x->titleChar){
		x->leftChild = insert(ranking, title, year, rating, x->leftChild, root);
	}
	else if(title[0]>x->titleChar){
		x->rightChild = insert(ranking, title, year, rating, x->rightChild, root);
	}
	return x;
}

void MovieTree::addMovie(int ranking, string title, int year, float rating){
	root=insert(ranking, title, year, rating, root, root);
	return;
}

TreeNode* minValueNode(TreeNode *node){
	TreeNode *current = node;
	while(current->leftChild != NULL){
		current = current->leftChild;
	}
	return current;
}

TreeNode* deleteM(string title, TreeNode *x, TreeNode *root){
	if(root==NULL){
		cout<<"Movie: "<<title<<" not found, cannot delete."<<endl;
		return root;
    }
    if(x->titleChar==title[0]){
    	cout<<"MADE IT IN"<<endl;
    	if(x->head->next==NULL){
    		cout<<"OH SHIT"<<endl;
    		if(x->leftChild==NULL){
    			TreeNode* temp = x->rightChild;
    			delete(x);
    			return temp;
    		}
    		else if(x->rightChild==NULL){
    			TreeNode* temp = x->leftChild;
    			delete(x);
    			return temp;
    		}
    		TreeNode* temp = minValueNode(root->rightChild);
    		root->titleChar = temp->titleChar;
    		root->head = temp->head;
    		root->rightChild = deleteM(title, x->rightChild, root);
    	}

    	LLMovieNode *entry = new LLMovieNode;
    	LLMovieNode *prev = new LLMovieNode;
    	LLMovieNode *nextOne = new LLMovieNode;
    	entry = x->head;

    	while(entry!=NULL){
    		cout<<"WHILE"<<endl;
    		if(entry->title==title) break;
    		prev = entry;
    		entry = nextOne;
    		nextOne = entry->next;
    	}

    	cout<<"HERE"<<endl;
    	if(entry->title==title){
    		if(entry==x->head) x->head=entry->next;
    		else prev->next = nextOne;
    		delete entry;
    		cout<<"DID IT"<<endl;
    		return root;
    	}
    	else{
    		cout<<"Movie: "<<title<<" not found, cannot delete."<<endl;
    		return root;
    	}
    }
    deleteM(title, x->leftChild, root);
	deleteM(title, x->rightChild, root);
	return root;
}

void MovieTree::deleteMovie(string title){
	TreeNode *x = new TreeNode();
	x = root;
	TreeNode* temp = deleteM(title, root, x);
	root=temp;
	cout<<"ALMOST THERE"<<endl;
	return;
}