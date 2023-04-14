#pragma once
#include "person.h"

class Teacher:
    public Person
{
public:
    Teacher(void);
    ~Teacher(void);
    Teacher(string, int, string, int);
    Teacher(const Teacher&);
    string get_object() {return object;}
    void set_object(string);
    int get_hours() {return hours;}
    void set_hours(int);
    void show();
	void change_hours(char, int);
    string object;
    int hours;
};
    