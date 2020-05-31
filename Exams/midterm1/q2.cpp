#include <iostream>

using namespace std;

struct Node{
	int num;
	Node *next;
};

void print(Node *head){
	if(head == NULL){
		cout<<"NULL ARRAY"<<endl;
		return;
	}
	Node *f = new Node;
	f = head;
	while(f!=NULL){
		cout<<f->num<<" ";
		f = f->next;
	}
	cout<<endl;
	return;
}

int main(){
	Node *x = new Node;
	
	Node *q = new Node;
	
	Node *h = new Node;
    Node *p = h;

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
                    n->num = 23;
                    break;
          }
          p = n;
     }

    cout<<"Initialized list as: ";
    Node *g = new Node;
    g = h;
   	while(g!=NULL){
   		cout<<g->num<<" ";
   		g = g->next;
   	}
	Node *evenH = new Node;
	Node *oddH = new Node;
	Node *j = new Node;
    j = h;


	while(j!=NULL){
		if(j->num % 2 == 0){
			Node *y = new Node;
			x->next = y;
			y->num = j->num;
			x = y;
			if(evenH = NULL){
				evenH = x;
			}
			
		}
		else{
			Node *w = new Node;
			q->next = w;
			w->num = j->num;
			q = w;
			oddH = q;
			if(oddH = NULL){
				oddH = x;
			}
		}
		j = j->next;
	}

	cout<<"\nSorted Even Array: ";
	print(evenH);
	cout<<"Sorted Odd Array: ";
	print(oddH);
	return 0;
}