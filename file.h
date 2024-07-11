#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cctype>
#include <algorithm>
#include <sys/stat.h>
#include "person.h"
#include "linkedlist_person.h"

using namespace std;

void check_and_write_person(LinkedList& list, string& current_name);
bool uniquename(const LinkedList& list, const string& name);
bool contains_letter(const string& name);
string to_uppercase(const string& str);
void write_list_to_file(const LinkedList& list, const string& filename);
void print_current_player(const LinkedList& list, const string& current_name);
void print_scoreboard(const LinkedList& list, const string& filename);

void check_and_write_person(LinkedList& list, string& current_name) {
    string name;
    int date = 0;
    double money = 0;

    struct stat buffer;
    bool fileExists = (stat("filename.txt", &buffer) == 0);

    if (!fileExists) {
        ofstream MyFile("filename.txt");
        MyFile << left << setw(10) << "Name" << setw(10) << "Day" << right << setw(4) << "Money" << endl;
        MyFile.close();
    }

    ifstream checkFile("filename.txt");
    if (!checkFile.is_open()) {
        cerr << "Error opening file!" << endl;
        return;
    }

    bool isEmpty = checkFile.peek() == ifstream::traits_type::eof();
    string file_name;
    int file_day;
    double file_money;

    if (!isEmpty) {
        checkFile.ignore(numeric_limits<streamsize>::max(), '\n'); // Skip header
        while (checkFile >> file_name >> file_day >> file_money) {
            person temp(to_uppercase(file_name), file_day, file_money);
            list.append(temp);
        }
    }
    checkFile.close();

    while (true) {
        cout << "Enter your name: ";
        cin >> name;
        string upper_name = to_uppercase(name);

        if (!contains_letter(name)) {
            cout << "Name must contain at least one letter. Please enter a valid name." << endl;
        } else if (list.exists(upper_name)) {
            cout << "Name '" << upper_name << "' already exists. Please enter a different name." << endl;
            cout << "Existing Names: ";
            list.print_list();
        } else {
            current_name = upper_name;
            break;
        }
    }

    person p(current_name, date, money);
    list.append(p);

    ofstream MyFile("filename.txt", ios::app);
    if (!MyFile.is_open()) {
        cerr << "Error opening file!" << endl;
        return;
    }

    MyFile << left << setw(10) << p.get_name() << " " << setw(9) << p.get_day() << right << setw(5) << p.get_money() << endl;
    MyFile.close();
}

bool uniquename(const LinkedList& list, const string& name) {
    string upper_name = to_uppercase(name);
    return !list.exists(upper_name);
}

bool contains_letter(const string& name) {
    return any_of(name.begin(), name.end(), ::isalpha);
}

string to_uppercase(const string& str) {
    string upper_str = str;
    transform(upper_str.begin(), upper_str.end(), upper_str.begin(), ::toupper);
    return upper_str;
}

void write_list_to_file(const LinkedList& list, const string& filename) {
    ofstream MyFile(filename);
    if (!MyFile.is_open()) {
        cerr << "Error opening file!" << endl;
        return;
    }

    MyFile << left << setw(10) << "Name" << setw(10) << "Day" << right << setw(4) << "Money" << endl; 
    NodePtr current = list.get_head();
    while (current != nullptr) {
        MyFile << left << setw(10) << current->data.get_name() << " " << setw(9) << current->data.get_day() << right << setw(5) << current->data.get_money() << endl;
        current = current->next;
    }
    MyFile.close();
}

void print_current_player(const LinkedList& list, const string& current_name) {
    NodePtr current = list.get_head();
    string upper_current_name = to_uppercase(current_name);
    
    while (current != nullptr) {
        if (current->data.get_name() == upper_current_name) {
            cout << current->data.get_name() << "'s total money: " << current->data.get_money() << endl;
            return;
        }
        current = current->next;
    }
    cout << "Current player not found." << endl;
}

void print_scoreboard(const LinkedList& list, const string& filename) {
    cout << endl << "--------Scoreboard--------" << endl << endl;
    NodePtr current = list.get_head();
    cout << left << setw(10) << "Name" << setw(10) << "Day" << right << setw(4) << "Money" << endl;
    while (current != nullptr) {
        cout << left << setw(10) << current->data.get_name() << " " << setw(9) << current->data.get_day() << right << setw(5) << current->data.get_money() << endl;
        current = current->next;
    }
    cout << endl << "--------------------------" << endl;
}

void increaseday(LinkedList& list, const string& current_name) {
    list.increment_day(current_name);
    write_list_to_file(list, "filename.txt");
}

void increasemoney(LinkedList& list, const string& current_name, double amount) {
    list.increment_money(current_name, amount);
    write_list_to_file(list, "filename.txt");
}

#endif // FILE_H