/*
#ifndef stack_h
#define stack_h
#include "node.h"

class Stack {
 NodePtr top;
 int size;
public:
    void push(int);
    int pop();
    Stack();
    ~Stack();
    bool isEmpty();
};


void Stack::push(int x){
  NodePtr new_node=new NODE(x);
  if(new_node){
        new_node->set_next(top);
        top=new_node;
        ++size;
            // Left missing for exercises…
   }
   else {
    cout<<"No more memory left"<<endl;
   }
         // Left missing for exercises…
    
}

int Stack::pop(){
    if (isEmpty()) {
        cout << "Stack Underflow" << endl;
        return '\0'; // Return a null character if stack is empty
    }
        NodePtr t=top;
        int value;
        value=t->get_value();
        top = t->get_next();
    // Left missing part for exercises
        size--;
        delete t;
        return value;
 //be careful of the empty stack!!!
    }

Stack::Stack(){
    top=NULL;
    size=0;
    
}
Stack::~Stack(){
    //cout<<"Strat clearing the stack"<<endl;
    /*int i;
    while(top!=NULL)
    {
        for(i=size;i>0;i--) {
            pop();
        }
    }*/
    /*
    while(size>0) pop();
}
bool Stack::isEmpty() {
    return top == nullptr;
}


#endif
*/