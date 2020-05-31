#include <iostream>
#include "RPNCalculator.hpp"
using namespace std;

RPNCalculator::RPNCalculator(){
     stackHead = NULL;
}

RPNCalculator::~RPNCalculator(){
     while(stackHead!=NULL){
          pop();
     }
     stackHead = NULL;
}

bool RPNCalculator::isEmpty(){
     if(stackHead == NULL){
          return true;
     }
     return false;
}

void RPNCalculator::push(float n){
     Operand *x = new Operand;
     x->number = n;
     x->next = stackHead;
     stackHead = x;
}

void RPNCalculator::pop(){
     if(stackHead == NULL){
          cout<<"Stack empty, cannot pop an item."<<endl;
          return;
     }
     Operand *x = new Operand;
     x = stackHead;
     stackHead = x->next;
     delete x;
}

Operand* RPNCalculator::peek(){
     if(stackHead == NULL){
          cout<<"Stack empty, cannot peek."<<endl;
          return NULL;
     }
     return stackHead;
}

bool RPNCalculator::compute(string symbol){
     if(stackHead == NULL || stackHead->next == NULL){
          cout<<"err: not enough operands"<<endl;
          return false;
     }
     float x = stackHead->number;
     float y = stackHead->next->number;
     float z = 0;

     if(symbol == "*"){
          z = x*y;
     }
     else if(symbol == "+"){
          z = x+y;
     }
     else{
          cout<<"err: invalid operation"<<endl;
          return false;
     }
     pop();
     pop();
     push(z);
}
