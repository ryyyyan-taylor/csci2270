#include <iostream>
#include <math.h>

using namespace std;

struct Node{
	int num;
	Node *next;
};

int sumEvens(Node *head){
	if(head==NULL){
		cout<<"LIST INITIALIZED AS NULL"<<endl;
		return 0;
	}
	Node *x = new Node;
	x = head;
	int sum = 0;
	while(x!=NULL){
		if(x->num % 2 == 0){
			sum = sum + x->num;
		}
		x = x->next;
	}
	return sum;
}

int main(){
	Node *head = new Node;
    Node *p = head;

    p->num = 6;

     for(int i=0;i<5;i++){
          Node *n = new Node;
          p->next = n;
          switch(i){
               case 0:
                    n->num = 8;
                    break;
               case 1:
                    n->num = 12;
                    break;
               case 2:
                    n->num = 33;
                    break;
               case 3:
                    n->num = 6;
                    break;
               case 4:
                    n->num = 80;
                    break;
          }
          p = n;
     }

    cout<<"Initialized list as: ";
    Node *g = new Node;
    g = head;
   	while(g!=NULL){
   		cout<<g->num<<" ";
   		g = g->next;
   	}
   	cout<<"\nSum of even values: "<<sumEvens(head)<<endl;
   	return 0;
}