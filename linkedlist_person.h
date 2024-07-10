#ifndef LINKEDLIST_PERSON_H
#define LINKEDLIST_PERSON_H

#include "node_person.h"
#include "Cal.h"

using namespace std;

typedef nodeP* NodePtr;

class LinkedList {
private:
    NodePtr head;
    NodePtr tail;

public:
    LinkedList();
    ~LinkedList();
    void append(person p);
    bool exists(const string& name) const;
    void print_list() const;
    bool increment_day(const string& name);
    bool increment_money(const string& name, double amount);
    void load_from_file(const string& filename);
    NodePtr get_head() const;
    void sort_by_money();
};
LinkedList::LinkedList(){
    head = nullptr;
    tail = nullptr;
}
LinkedList::~LinkedList() {
    NodePtr current = head;
    while (current != nullptr) {
        NodePtr next = current->next;
        delete current;
        current = next;
    }
}

void LinkedList::append(person p) {
    NodePtr newNode = new nodeP(p);
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

bool LinkedList::exists(const string& name) const {
    NodePtr current = head;
    while (current != nullptr) {
        if (current->data.get_name() == name) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void LinkedList::print_list() const {
    NodePtr current = head;
    while (current != nullptr) {
        cout << current->data.get_name() << " ";
        current = current->next;
    }
    cout << endl;
}

bool LinkedList::increment_day(const string& name) {
    NodePtr current = head;
    while (current != nullptr) {
        if (current->data.get_name() == name) {
            current->data.set_day(current->data.get_day() + 1);
            return true;
        }
        current = current->next;
    }
    return false;
}


bool LinkedList::increment_money(const string& name, double amount) {
    NodePtr current = head;
    while (current != nullptr) {
        if (current->data.get_name() == name) {
            current->data.set_money(amount);
            return true;
        }
        current = current->next;
    }
    return false;
}

void LinkedList::load_from_file(const string& filename) {
    ifstream checkFile(filename);
    string file_name;
    int file_day;
    double file_money;
    
    if (!checkFile.is_open()) return;

    checkFile.ignore(numeric_limits<streamsize>::max(), '\n');

    while (checkFile >> file_name >> file_day >> file_money) {
        person temp(file_name, file_day, file_money);
        append(temp);
    }
    checkFile.close();
}

NodePtr LinkedList::get_head() const {
    return head;
}

void LinkedList::sort_by_money() {
    if (!head || !head->next) return;

    NodePtr current = head;
    while (current != nullptr) {
        NodePtr maxNode = current;
        NodePtr next = current->next;

        while (next != nullptr) {
            if (next->data.get_money() > maxNode->data.get_money()) {
                maxNode = next;
            }
            next = next->next;
        }

        if (maxNode != current) {
            person temp = current->data;
            current->data = maxNode->data;
            maxNode->data = temp;
        }

        current = current->next;
    }
}

#endif // LINKEDLIST_PERSON_H
