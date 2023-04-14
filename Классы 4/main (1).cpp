#include <iostream>
#include "person.h"
#include "teacher.h"
using namespace std;

int main()
{
    Person a("Jack", 52);
    a.show();
    Person c;
    c=a;
    c.show();
    Person d;
    Person b;
    d.set_name("Victor");
    d.set_age(11);
    b.name = d.get_name();
    b.age = d.get_age();
    d.show();
    b.show();
    Teacher e;
    e.set_name("Olga_Andreevna");
    e.set_age(18);
    e.set_object("Algebra");
    e.set_hours(23);
    e.show();
    cout << "Введите знак (+ или -): ";  
	cin >> znak;   
	cout << "Введите число: ";    
	cin >> value;    
	cout << endl;    
	e.change_hours(znak, value);
	e.show();
}
