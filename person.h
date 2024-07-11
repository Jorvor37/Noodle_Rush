#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using namespace std;

class person {
private:
    string name;
    int day;
    double money;

public:
    person(string, int, double);
    person(const person& other);
    string get_name() const;
    int get_day() const;
    double get_money() const;
    void set_day(int new_day);
    void set_money(double new_money);
};

person::person(string x, int y, double z) {
    name = x;
    day = y;
    money = z;
} 

person::person(const person& other) {
    name = other.name;
    day = other.day;
    money = other.money;
}

string person::get_name() const {
    return name;
}

int person::get_day() const {
    return day;
}

double person::get_money() const {
    return money;
}

void person::set_day(int new_day) {
    day = new_day;
}

void person::set_money(double new_money) {
    money = new_money;
}

#endif // PERSON_H