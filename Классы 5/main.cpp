#include <iostream>
#include "object.h"
#include "person.h"
#include "teacher.h"
#include "vector.h"
using namespace std;

int main()
{
    Person a;
    cin>>a;
    //cout<<a<<endl;
    Object *p=&a;
    //p->Show();
    Teacher b;
    cin>>b;
    Vector v(5);
    v.Add(p);
    p=&b;
    v.Add(p);
    cout<<v;
}
