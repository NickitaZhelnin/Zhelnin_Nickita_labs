#include<iostream>
using namespace std;

struct para{
    double first;
    double second;
    void Init(double, double);
    void Read();
    void Show();
    void Multiply(int);
};

void para::Init(double f, double s){
    if(f == round(f) and s != round(s)){
        first = f;
        second = s;
    }
    else{
        cout << "\nError";
        first = 0;
        second = 0;
    }
}

void para::Read(){
    cout << "\nFirst: "; cin >> first;
    cout << "\nSecond: "; cin >> second;
}

void para:: Show(){
    cout << "\nFirst: " << first;
    cout << "\nSecond: " << second;
    cout << "\n";
}

void para::Multiply(int k){
    first*=k;
    second*=k;
}

para make_para(double f, double s){
    para tmp;
    tmp.Init(f,s);
    return tmp;
}

int main(){
    para a;
    
    para mas[3];
    for(int i = 0; i < 3; i++) mas[i].Read();
    for(int i = 0; i < 3; i++) mas[i].Show();
    for(int i = 0; i < 3; i++) mas[i].Multiply(6);
    
    para* mas2 = new para[3];
    for(int i = 0; i < 3; i++) mas2[i].Read();
    for(int i = 0; i < 3; i++) mas2[i].Show();
    for(int i = 0; i < 3; i++) mas2[i].Multiply(3);
    
    a.Init(2, 3.4);
    a.Show();
    para tmp = make_para(4.3, 3.6);
    tmp.Show();
    return 0;
}