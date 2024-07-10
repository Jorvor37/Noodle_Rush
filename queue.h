
#ifndef queue_h
#define queue_h
#include "node.h"
#include "order.h"
#include "game.h"
typedef node* nodePtr;


class queue {
	nodePtr headPtr,tailPtr;
	int size;
public:
    void enqueue(order);
    void dequeue();
    void print_order();
    void do_order();
    int get_size();
    queue();
    ~queue();
};


void queue::enqueue(order x){
    nodePtr new_node= new node(x);
    if(new_node){ 
        if(headPtr!=NULL) tailPtr->set_next(new_node); //if(size==0)
        else headPtr=new_node;
        
        tailPtr=new_node;
        size++;
    }
}

void queue::dequeue(){
  if(headPtr!=NULL){
     nodePtr t=headPtr;
     if(size==1)
     {
        headPtr=NULL;
        tailPtr=NULL;
     }
     else headPtr=headPtr->get_next();

     size--;

     cout<<"You've served ";
     t->print();
          
     delete t;
  } 
  else cout<<"Empty queue"<<endl;
}

int queue::get_size(){
  return size;
}

void queue::do_order(){
  nodePtr t;
  int n=size;
  for (int i=0; i<n; i++)
  {
    t=headPtr;
    t->make_bowl();
    dequeue();
  }
  cout<<"\nIt's the end of the day"<<endl;
  pressEnterToContinue();
}

void queue::print_order(){
   nodePtr t;
  for(t=headPtr; t; t=t->next)
  {
    t->print();
  }
}

queue::queue(){
    size=0;
    headPtr=NULL;
    tailPtr=NULL;
    
}
queue::~queue(){
    cout<<"You've completed all 7 days"<<endl;
    while(size>0)
    {
      dequeue();
    }
    
}


#endif