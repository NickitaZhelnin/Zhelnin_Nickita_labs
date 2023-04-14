#pragma once
#include "object.h"
#include <iostream>
#include <string>
using namespace std;
class Person:
    public Object
{
public:
    Person(void);
public:
    virtual ~Person(void);
    void Show();
    Person(string, int);
    Person(const Person&);
    string get_name() {return name;}
    int get_age() {return age;}
    void set_name(string);
    void set_age(int);
    Person& operator=(const Person&);
    friend istream& operator>>(istream&in, Person&p);
    friend ostream& operator<<(ostream&out, const Person&p);
protected:
    string name;
    int age;
};