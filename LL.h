#include "node.h"
#include "order.h"
typedef node* nodePtr;

class LL{
      nodePtr hol;// node * hol;
         //head of linked list
      int size;
  public:
      LL();
      void insert(order);
      void printList();
     ~LL();
};

LL::LL(){
  hol=NULL;
  size=0;
}



void LL::insert(order x){
   
   	nodePtr t=hol;
    	//search for location
   	while(t->next) t=t->next;
   	t->next=new node(x);
  
     size++;
}


void LL::printList (){
   nodePtr t;
  for(t=hol; t; t=t->next)

  {
       t->print();
       cout<<" ";
  }
  
  cout<<"NULL" <<endl;
}


LL::~LL(){
  cout<<"It's the end of the day";
  nodePtr t;   
  t=hol;
  while(t){

  } 
} 
