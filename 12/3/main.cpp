#include <iostream>
#include "pair.h"
#include "list.h"
#include <map>
using namespace std;

int main(){
    int n;
    cin >> n;
    List<Pair> data(n);
    data.Print();
    data.del_sr();
    cout << "After delete: " << endl;
    data.Print();
    data.add_min();
    cout << "After add: " << endl;
    data.Print();
    data.delenie();
    cout << "After delenie: " << endl;
    data.Print();
}
