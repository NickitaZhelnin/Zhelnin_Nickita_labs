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
void Teacher::show(){
    cout << name << " " << age << " " << object << " " << hours << endl;
}
void Teacher::change_hours(char z, int v){
	if(z == '+') hours += v;
	if(z == '-') hours -= v;
}