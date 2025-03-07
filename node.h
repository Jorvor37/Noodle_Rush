#ifndef node_h
#define node_h
#include "order.h"

class node
{ 
private:
    order bowl;
    node *next;

public:
   node(order);
   void print();
   void make_bowl();
   ~node();
    void set_next(node* t) {next=t;}
    node * get_next() {return next;}
   
};
node::node(order x)
{
  bowl=x;
  next=NULL; 
}

void node::print(){
    bowl.print();
}

void node::make_bowl(){
    bowl.make();
}

node::~node(){
    //cout<<"Deleting "<<endl;
    //bowl.print();
    //cout<<bowl.get_name()<<" is ready to serve!"<<endl;
}

#endif