#include <iostream>
#include <map>
using namespace std;

int main(){
    multimap<int, float> data;
    multimap<int, float>::iterator itr;
    int key;
    float value;
    //enter elements
    int n;
    cout << "Enter count: ";
    cin >> n;
    for(int i = 0; i < n; i++){
        cout << "Key: "; cin >> key;
        cout << "Value: "; cin >> value;
        data.insert({key, value});
    }
    //print elements
    for (itr = data.begin(); itr != data.end(); ++itr) {
        cout << itr->first << " : " << itr->second << endl;
    }
    //find min
    float min1 = 10000.0;
    for (itr = data.begin(); itr != data.end(); ++itr) {
        if(itr->second < min1) min1 = itr->second;
    }
    //insert min
    int key1;
    cout << "Enter key: "; cin >> key1;
    data.insert({key1, min1});
    //print elements
    for (itr = data.begin(); itr != data.end(); ++itr) {
        cout << itr->first << " : " << itr->second << endl;
    }
    //udalit' < srednego
    float sr;
    int k = 0;
    float sum = 0;
    for (itr = data.begin(); itr != data.end(); ++itr) {
        k++;
        sum += itr->second;
    }
    sr = sum / k;
    cout << "Srednee: " << sr;
    cout << endl;
    for (itr = data.begin(); itr != data.end();) {
        if(itr->second < sr){
            itr = data.erase(itr);
        }
        else ++itr;
    }
    //print elements
    for (itr = data.begin(); itr != data.end(); ++itr) {
        cout << itr->first << " : " << itr->second << endl;
    }
    //find max and delenie
    float max1 = -10000.0;
    for (itr = data.begin(); itr != data.end(); ++itr) {
        if(itr->second > max1) max1 = itr->second;
    }
    for (itr = data.begin(); itr != data.end(); ++itr) {
        itr->second = itr->second / max1;
    }
    cout << "Posle deleniya na max:" << endl;
    //print elements
    for (itr = data.begin(); itr != data.end(); ++itr) {
        cout << itr->first << " : " << itr->second << endl;
    }
}
