/*
#ifndef node_h
#define node_h
#include "Game.h"

class NODE{
    order bowl;
    NODE *nextPtr;
public:
    NODE(order);
    ~NODE();
    void set_next(NODE*);
    NODE* get_next();
    char get_value();
};
typedef NODE* NodePtr;


NODE::NODE(order x){
    bowl=x;
    nextPtr=NULL;
    //pPtr =NULL; not using doubly
}

NODE* NODE::get_next(){
    return nextPtr;
}

char NODE::get_value(){
    return data;
}


void NODE::set_next(NODE *t){
     nextPtr=t;

}
NODE::~NODE(){
     //cout<<"deleting "<<data<<endl;

}

#endif
*/