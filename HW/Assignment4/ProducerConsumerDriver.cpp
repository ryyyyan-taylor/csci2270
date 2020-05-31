/****************************************************************/
/*                Producer Consumer Driver File                 */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "ProducerConsumer.hpp"
#include <iostream>
#include <string>
// you may include more libraries as needed

using namespace std;

/*
 * Purpose: displays a menu with options
 * @param none
 * @return none
 */
void menu()
{
	cout << "*----------------------------------------*" << endl;
	cout << "Choose an option:" << endl;
    cout << "1. Producer (Produce items into the queue)" << endl;
	cout << "2. Consumer (Consume items from the queue)" << endl;
	cout << "3. Return the queue size and exit" << endl;
	cout << "*----------------------------------------*" << endl;
}

int main(int argc, char const *argv[]){
     ProducerConsumer x;
     string input = "", num = "", choice = "";
     int n;
     while(true){
          menu();
          getline(cin,input);
          switch(stoi(input)){
               case 1:
                    cout<<"Enter the number of items to be produced:"<<endl;
                    getline(cin,num);
                    n = stoi(num);
                    for(int i=0;i<n;i++){
                         cout<<"Item"<<i+1<<":"<<endl;
                         getline(cin,choice);
                         x.enqueue(choice);
                    }
                    break;

               case 2:
                    cout<<"Enter the number of items to be consumed:"<<endl;;
                    getline(cin, num);
                    n=stoi(num);
                    for(int i=0;i<n;i++){
                         if(x.isEmpty() != true){
                              cout<<"Consumed: "<<x.peek()<<endl;
                              x.dequeue();
                         }
                         else{
                              cout<<"No more items to consume from queue"<<endl;
                         }
                    }
                    break;

               case 3:
                    cout<<"Number of items in the queue:"<<x.queueSize()<<endl;
                    return 0;
          }
     }
}