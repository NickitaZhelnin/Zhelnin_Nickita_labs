#pragma once
#include "person.h"

class Teacher:
    public Person
{
public:
    Teacher(void);
public:
    ~Teacher(void);
    Teacher(string, int, string, int);
    Teacher(const Teacher&);
    string get_object() {return object;}
    void set_object(string);
    int get_hours() {return hours;}
    void set_hours(int);
    void Show();
    int hours;
    void change_hours(char, int);
    Teacher& operator=(const Teacher&);
    friend istream& operator>>(istream&in, Teacher&t);
    friend ostream& operator<<(ostream&out, const Teacher&t);
protected:
    string object;
};
    