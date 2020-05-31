#include "ProducerConsumer.hpp"
#include <iostream>
#include <string>
using namespace std;

ProducerConsumer::ProducerConsumer(){
     queueFront = -1;
     queueEnd =  -1;
}

bool ProducerConsumer::isEmpty(){
     if(queueFront==-1 || queueEnd==-1){
          return true;
     }
     return false;
}

bool ProducerConsumer::isFull(){
     if(queueEnd == 19){
          return true;
     }
     return false;
}

void ProducerConsumer::enqueue(string item){
     if(isFull()==false){
          if(isEmpty()==true){
               queue[0] = item;
               queueEnd++;
               queueFront++;
          }
          else{
               queue[queueEnd+1] = item;
               queueEnd++;
          }
     }
     else if(isFull()==true){
          cout<<"Queue full, cannot add new item"<<endl;
     }
}

void ProducerConsumer::dequeue(){
     if(isEmpty()==true){
          cout<<"Queue empty, cannot dequeue an item"<<endl;
          return;
     }
     for(int x=0;x<queueEnd;x++){
          queue[x] = queue[x+1];
     }
     queueEnd--;
     queueFront++;
     if(queueEnd==-1){
          queueFront=-1;
     }
}

int ProducerConsumer::queueSize(){
     return queueEnd+1;
}

string ProducerConsumer::peek(){
     if(isEmpty() == true){
          cout<<"Queue empty, cannot peek"<<endl;
          return "";
     }
     return queue[0];
}
