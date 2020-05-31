#include <iostream>
using namespace std;

struct Node{
	int num;
	Node *next;
};

bool lengthIsEven(Node *head){
	int i=1;
	Node *x = new Node;
	x = head;
	while(x!=NULL){
		x = x->next;
		i++;
	}
	if(i/2 == 0)
		return true;
	else
		return false;
}

int main(){
	Node *x = new Node;
}