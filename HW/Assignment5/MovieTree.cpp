#include <iostream>
#include "MovieTree.hpp"
using namespace std;

MovieNode* newNode(int ranking, string title, int year, float rating){
	MovieNode* temp = new MovieNode;
	temp->ranking = ranking;
	temp->title = title;
	temp->year = year;
	temp->rating = rating;
	temp->rightChild = temp->leftChild = NULL;
	return temp;
}

MovieNode* movieSearch(MovieNode* root, string title){
	if(root == NULL){
		return nullptr;
	}
	else if(title.string::compare(root->title)==0){
		return root;
	}
	else if(title.string::compare(root->title)<=0){
		return movieSearch(root->leftChild,title);
	}
	else{
		return movieSearch(root->rightChild,title);
	}
}

void print(MovieNode *x){
	if(x == NULL)
		return;

	print(x->leftChild);
	cout<<"Movie: "<<x->title<<" "<<x->rating<<endl;
	print(x->rightChild);
}

void query(MovieNode* x, float rating, int year){
	if(x == NULL)
		return;

	if(x->year>year && x->rating>=rating){
		cout<<x->title<<"("<<x->year<<") "<<x->rating<<endl;
	}
	query(x->leftChild, rating, year);
	query(x->rightChild, rating, year);
}

float average(MovieNode* x, float &u, float &c){
	if(x==NULL){
	    return 0.0;
	}
	c++;
	u = x->rating;
	if(x->leftChild != NULL){
	    u = u + average(x->leftChild, u, c);
	}
	if(x->rightChild != NULL){
	    u = u + average(x->rightChild, u, c);
	} 
	return u;
}

MovieNode* insert(int ranking, string title, int year, float rating, MovieNode* root){
	if(root==NULL){
		root = newNode(ranking, title, year, rating);
	}

	else if(title.compare(root->title) < 0){
		root->leftChild = insert(ranking, title, year, rating, root->leftChild);
	}

	else{
		root->rightChild = insert(ranking, title, year, rating, root->rightChild);
	}

	return root;
}

MovieTree::MovieTree(){
	root = NULL;
}

MovieTree::~MovieTree(){

}

void MovieTree::printMovieInventory(){
	MovieNode *x = new MovieNode();
	x = root;
	print(x);
	return;
}

void MovieTree::addMovieNode(int ranking, string title, int year, float rating){
	root=insert(ranking, title, year, rating, root);
	return;
}

void MovieTree::findMovie(string title){
	MovieNode *node = movieSearch(root, title);
	if(node==NULL){
	    cout<<"Movie not found."<<endl;
	    return;
	}
	cout<<"Movie Info:"<<endl;
	cout<<"=================="<<endl;
	cout<<"Ranking:"<<node->ranking<<endl;
	cout<<"Title  :"<<node->title<<endl;
	cout<<"Year   :"<<node->year<<endl;
	cout<<"rating :"<<node->rating<<endl;
}

void MovieTree::queryMovies(float rating, int year){
	cout<<"Movies that came out after "<<year<<" with rating at least "<<rating<<":"<<endl;
	query(root, rating, year);
}

void MovieTree::averageRating(){
    float u = 0;
    float c = 0;
    float out = average(root, u, c);
    if(out==0.0){
        cout<<"Average rating:0"<<endl;
        return;
    }
	cout<<"Average rating:"<<out/c<<endl;;
}