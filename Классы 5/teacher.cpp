#include "teacher.h"

Teacher::Teacher(void):Person() {object = ""; hours = 0;}
Teacher::~Teacher(void){}
Teacher::Teacher(string n, int a, string o, int h):Person(n, a){
    object = o;
    hours = h;
}
Teacher::Teacher(const Teacher& tmp){
    name = tmp.name;
    age = tmp.age;
    object = tmp.object;
    hours = tmp.hours;
}
void Teacher::set_object(string o){
    object = o;
}
void Teacher::set_hours(int h){
    hours = h;
}
void Teacher::Show(){
    cout << "\nName: " << name;
    cout << "\nAge: " << age;
    cout << "\nObject: " << object;
    cout << "\nHours: " << hours;
}
void Teacher::change_hours(char z, int v){
    if(z == '+') hours += v;
    if(z == '-') hours -= v;
}
Teacher& Teacher::operator=(const Teacher&t){
    if(&t==this) return *this;
    name=t.name;
    age=t.age;
    return *this;
}
istream& operator>>(istream&in, Teacher&t){
    cout << "\nName:"; in>>t.name;
    cout << "\nAge:"; in>>t.age;
    cout << "\nObject:"; in>>t.object;
    cout << "\nHours:"; in>>t.hours;
    return in;
}
ostream& operator<<(ostream&out, const Teacher&t){
    out << "\nName:" <<t.name;
    out << "\nAge:" <<t.age;
    out << "\nObject:" <<t.object;
    out << "\nHours:" <<t.hours;
    return out;
}