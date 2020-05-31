/****************************************************************/
/*                CountryNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CountryNetwork */
/*     This class uses a linked-list of Country structs to      */
/*     represet communication paths between nations             */
/****************************************************************/

#include <iostream>
#include "CountryNetwork.hpp"

using namespace std;

/*
 * Purpose: Constructer for empty linked list
 * @param none
 * @return none
 */
CountryNetwork::CountryNetwork()
{
     head = NULL;
}


/*
 * Purpose: Check if list is empty
 * @return true if empty; else false
 */
bool CountryNetwork::isEmpty()
{
     if(head == NULL){
          return true;
     }
     else{
          return false;
     }
}


/*
 * Purpose: Add a new Country to the network
 *   between the Country *previous and the Country that follows it in the network.
 * @param previous name of the Country that comes before the new Country
 * @param countryName name of the new Country
 * @return none
 */
void CountryNetwork::insertCountry(Country* previous, string countryName){
     Country *x = new Country;
     if(previous == NULL){
          Country *y = new Country;
          y = head;
          x->next = y;
          x->name = countryName;
          head = x;
          cout<<"adding: "<<countryName<<" (HEAD)"<<endl;
     }

     else{
          x->next = previous->next;
          previous->next = x;
          x->name = countryName;
          cout<<"adding: "<<countryName<<" (prev: "<<previous->name<<")"<<endl;
     }
}


/*
 * Purpose: delete the country in the network with the specified name.
 * @param countryName name of the country to delete in the network
 * @return none
 */
void CountryNetwork::deleteCountry(string countryName){
     Country *x = new Country;
     x = head;
     Country *p = new Country;
     while(x->next != NULL){
          if(x->name == countryName){
              p = x;
              x = x->next;
              head = x;
              delete p;
              return;
          }
          if((x->next)->name == countryName){
               p = x->next;
               x->next = (x->next)->next;
               delete p;
               return;
          }
          x = x->next;
     }
     if(x!=head){
        cout<<"Country does not exist."<<endl;
     }
}


/*
 * Purpose: populates the network with the predetermined countries
 * @param none
 * @return none
 */
void CountryNetwork::loadDefaultSetup(){

     Country *h = new Country;
     head = h;
     Country *p = head;
     head->name = "United States";
     cout<<"adding: United States (HEAD)"<<endl;

     for(int i=0;i<5;i++){
          Country *n = new Country;
          p->next = n;
          switch(i){
               case 0:
                    n->name = "Canada";
                    break;
               case 1:
                    n->name = "Brazil";
                    break;
               case 2:
                    n->name = "India";
                    break;
               case 3:
                    n->name = "China";
                    break;
               case 4:
                    n->name = "Australia";
                    break;
          }
          cout<<"adding: "<<n->name<<" (prev: "<<p->name<<")"<<endl;
          p = n;
     }
}


/*
 * Purpose: Search the network for the specified country and return a pointer to that node
 * @param countryName name of the country to look for in network
 * @return pointer to node of countryName, or NULL if not found
 * @see insertCountry, deletecountry
 */
Country* CountryNetwork::searchNetwork(string countryName){
     Country *x = new Country;
     x = head;
     while(x != NULL){
          if(x->name == countryName){
               return x;
          }
          x = x->next;
     }
     return NULL;
}


/*
 * Purpose: deletes all countries in the network starting at the head country.
 * @param none
 * @return none
 */
void CountryNetwork::deleteEntireNetwork(){
     Country *x = new Country;
     x = head;
     while(x != NULL){
          cout<<"deleting: "<<x->name<<endl;
          deleteCountry(x->name);
          x = x->next;
     }
     cout<<"Deleted network"<<endl;
     head = NULL;
}


/*
 * Purpose: Transmit a message across the network to the
 *   receiver. Msg should be stored in each country it arrives
 *   at, and should increment that country's count.
 * @param receiver name of the country to receive the message
 * @param message the message to send to the receiver
 * @return none
 */
void CountryNetwork::transmitMsg(string receiver, string message){
     Country *x = new Country;
     x = head;
     bool passed = false;
     while(x != NULL){
          x->numberMessages++;
          cout<<x->name<<" [# messages received: "<<x->numberMessages<<"] received: "<<message<<endl;
          if(x->name == receiver){
               x->message = message;
               return;
          }
     x = x->next;
     }
}


/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void CountryNetwork::printPath()
{
     Country *x = new Country;
     x = head;
     cout<<"== Current Path =="<<endl;
     while(x != NULL){
          cout<<x->name<<" -> ";
          x = x->next;
     }
     cout<<"\n===\n"<<endl;

}


/*
 * Purpose: reverse the entire network t
 * @param ptr head of list
 */
void CountryNetwork::reverseEntireNetwork(){
     Country *current = new Country;
     current = head;
     Country *next = new Country;
     Country *prev = new Country;
     next = NULL, prev = NULL;
     while(current != NULL){
          next = current->next;
          current->next = prev;
          prev = current;
          current = next;
     }
     head = prev;
}
