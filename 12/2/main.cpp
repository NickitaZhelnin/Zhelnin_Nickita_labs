#include <iostream>
#include "pair.h"
#include <map>
using namespace std;

int main(){
    multimap<int, Pair> data;
    multimap<int, Pair>::iterator itr;
    int key;
    int value1;
    double value2;
    //enter elements
    int n;
    cout << "Enter count: ";
    cin >> n;
    for(int i = 0; i < n; i++){
        cout << "Key: "; cin >> key;
        cout << "Value1: "; cin >> value1;
        cout << "Value2: "; cin >> value2;
        Pair a(value1, value2);
        data.insert({key, a});
    }
    //print elements
    for (itr = data.begin(); itr != data.end(); ++itr) {
        cout << itr->first << " :: ";
        cout << itr->second.first << " : " << itr->second.second;
        cout << endl;
    }
    //find min
    Pair min1(10000, 10000.0);
    for (itr = data.begin(); itr != data.end(); ++itr) {
        if(itr->second < min1) min1 = itr->second;
    }
    //insert min
    int key1;
    cout << "Enter key: "; cin >> key1;
    data.insert({key1, min1});
    //print elements
    for (itr = data.begin(); itr != data.end(); ++itr) {
        cout << itr->first << " :: ";
        cout << itr->second.first << " : " << itr->second.second;
        cout << endl;
    }
    //udalit' < srednego
    int sr1; double sr2;
    int k = 0;
    int sum1 = 0; double sum2 = 0;
    for (itr = data.begin(); itr != data.end(); ++itr) {
        k++;
        sum1 = sum1 + itr->second.first;
        sum2 = sum2 + itr->second.second;
    }
    sr1 = sum1 / k; sr2 = sum2 / k;
    Pair sr(sr1, sr2);
    for (itr = data.begin(); itr != data.end();) {
        if(itr->second < sr){
            itr = data.erase(itr);
        }
        else ++itr;
    }
    //print elements
    cout << "After delete: " << endl;
    for (itr = data.begin(); itr != data.end(); ++itr) {
        cout << itr->first << " :: ";
        cout << itr->second.first << " : " << itr->second.second;
        cout << endl;
    }
    //find max and delenie
    Pair max1(-10000, -10000.0);
    for (itr = data.begin(); itr != data.end(); ++itr) {
        if(itr->second > max1) max1 = itr->second;
    }
    for (itr = data.begin(); itr != data.end(); ++itr) {
        itr->second.first = itr->second.first / max1.first;
        itr->second.second = itr->second.second / max1.second;
    }
    cout << "Posle deleniya na max:" << endl;
    //print elements
    for (itr = data.begin(); itr != data.end(); ++itr) {
        cout << itr->first << " :: ";
        cout << itr->second.first << " : " << itr->second.second;
        cout << endl;
    }
}
