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
      void print_order();
     ~LL();
};

LL::LL(){
  hol=NULL;
  size=0;
}

void LL::insert(order x){
   nodePtr newNode = new node(x);

    if (hol == nullptr) {
        hol = newNode;
    } else {
        nodePtr t = hol;
        while (t->next) {
            t = t->next;
        }
        t->next = newNode;
    }
    size++;
   	
    /*nodePtr t=hol;
    //search for location
   	while(t->next) t=t->next;
   	t->next=new node(x);
    size++;*/
}

void LL::print_order(){
   nodePtr t;
  for(t=hol; t; t=t->next)
  {
    t->print();
  }
}

LL::~LL(){
  cout<<"It's the end of the day"<<endl;
  nodePtr t;
  t = hol;
  int i;
  for (i = 0; i < size; i++) {
    t = hol->get_next();
    delete hol;
    hol = t;
  }
} 
