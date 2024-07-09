#ifndef NODE_PERSON_H
#define NODE_PERSON_H

#include "person.h"

using namespace std;

class nodeP {
public:
    person data;
    nodeP* next;

    nodeP(const person& p) : data(p), next(nullptr) {}
};

#endif // NODE_PERSON_H
