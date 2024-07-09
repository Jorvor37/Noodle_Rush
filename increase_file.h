#ifndef INCREASE_FILE_H
#define INCREASE_FILE_H

#include "linkedlist_person.h"
#include "file.h"

using namespace std;

void increaseday(LinkedList& list, const string& current_name) {
    list.increment_day(current_name);
    write_list_to_file(list, "filename.txt");
}

void increasemoney(LinkedList& list, const string& current_name, double amount) {
    list.increment_money(current_name, amount);
    write_list_to_file(list, "filename.txt");
}


#endif // INCREASE_FILE_H
