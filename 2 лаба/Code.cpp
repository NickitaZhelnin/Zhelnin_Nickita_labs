#include<iostream>
using namespace std;

class bankomat{
    int number;
    double ostatoc;
    double max_snyatie;
public:
    bankomat(){
        number = 0;
        ostatoc = 0;
        max_snyatie = 0;
        cout << "Bez parametrov dlya " << this << endl;
    }
    bankomat(int n, double o, double m){
        number = n;
        ostatoc = o;
        max_snyatie = m;
        cout << "s parametrami dlya " << this << endl;
    }
    bankomat(const bankomat &c){
        number = c.number;
        ostatoc = c.ostatoc;
        max_snyatie = c.max_snyatie;
        cout << "Copy dlya " << this << endl;
    }
    ~bankomat(){
        cout << "Deconstructor dlya " << this << endl;
    }
    int get_number(){
        return number;
    }
    void set_number(int n){
        number = n;
    }
    double get_ost(){
        return ostatoc;
    }
    void set_ost(double o){
        ostatoc = o;
    }
    double get_max(){
        return max_snyatie;
    }
    void set_max(double m){
        max_snyatie = m;
    }
    void show(){
        cout << "Number: " << number << endl;
        cout << "Ostatoc: " << ostatoc << endl;
        cout << "Max summa snyatia: " << max_snyatie << endl;
    }
};

bankomat make(){
    int n;
    double o;
    double m;
    cout << "Vvedite number: ";
    cin >> n;
    cout << "Vvedite ostatoc: ";
    cin >> o;
    cout << "Vvedite max summu snyatia: ";
    cin >> m;
    bankomat b(n, o, m);
    return b;
}

void print(bankomat b){
    b.show();
}

int main(){
    bankomat b1;
    b1.show();
    bankomat b2(4351, 12.4, 12.2);
    b2.show();
    bankomat b3 = b2;
    b3.set_number(5612);
    b3.set_ost(54.23);
    b3.set_max(52.20);
    print(b3);
    b1 = make();
    b1.show();
    return 0;
}