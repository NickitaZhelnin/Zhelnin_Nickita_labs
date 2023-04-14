#include "person.h"
Person::Person(void){
    name = "";
    age = 0;
}
Person::~Person(void){}
Person::Person(string n, int a){
    name = n;
    age = a;
}
Person::Person(const Person& tmp){
    name = tmp.name;
    age = tmp.age;
}
void Person::set_name(string n){
    name = n;
}
void Person::set_age(int a){
    age = a;
}
void Person::show(){
    cout << name << " " << age << endl;
}

