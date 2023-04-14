#include <iostream>
using namespace std;

class Pair{
    int first;
    double second;
public:
    Pair(){
        first = 10;
        second = 2.4;
        cout << "Конструктор без параметров для " << this << endl;
    }
    Pair(int f, double s){
        first = f;
        second = s;
        cout << "Конструктор с параметрами для " << this << endl;
    }
    Pair(const Pair&p){
        this->first = p.first;
        this->second = p.second;
        cout << "Конструктор копирования для " << this << endl;
    }
    ~Pair(){
        cout << "Деструктор для " << this << endl;
    }
    void set_first(int tmp){
        first = tmp;
    }
    void set_second(double tmp){
        second = tmp;
    }
    int get_first(){
        return first;
    }
    double get_second(){
        return second;
    }
    void show(){
        cout << first << ":" << second << endl;
    }
    Pair& operator=(const Pair&tmp){
        if(&tmp == this) return *this;
        first = tmp.first;
        second = tmp.second;
        return *this;
    }
    bool operator==(const Pair&tmp){
        return (this->first == tmp.first && this->second == tmp.second);
    }
    bool operator!=(const Pair&tmp){
        return !(this->first == tmp.first && this->second == tmp.second);
    }
    Pair &operator-(const double tmp){
        if(tmp == (int)tmp) first -= tmp;
        else second -= tmp;
        return *this;
    }
};


int main()
{
    setlocale(LC_ALL, "Rus");
    Pair a;
    cout << "Введите первое число: ";
    cin >> a.first;
    cout << "Введите второе число: ";
    cin >> a.second;
    a.show();
    Pair b(123, 65.43);
    b.show();
    Pair c(b);
    Pair d;
    d.set_first(5671);
    d.set_second(79.1);
    d.get_first();
    d.get_second();
    a+10;
    a+4.2;
    a.show();
    return 0;
}
