#pragma once
#include <map>
#include <iostream>
using namespace std;

template <class T>
class List {
	multimap <int, T> data;
	multimap<int, Pair>::iterator itr;
	int size;
public:
	List(void);
	List(int n);
	void Print();
	~List(void);
	void del_sr();
	void add_min();
	void delenie();
};

template <class T>
List<T>::List() {
	size = 0;
}

template <class T>
List<T>::~List() {}

template <class T>
List<T>::List(int n) {
	T a;
	for (int i = 0;i < n;++i) {
		cin >> a.first;
		cin >> a.second;
		data.insert({i, a});
	}
	size = data.size();
}

template <class T>
void List<T>::Print() {
    int k = 1;
    for (itr = data.begin(); itr != data.end(); ++itr) {
	    cout << k++ << " :: ";
	    cout << itr->second.first;
	    cout << " : ";
	    cout << itr->second.second;
	    cout << endl;
    }
}

template <class T>
void List<T>::del_sr() {
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
}

template <class T>
void List<T>::add_min() {
	//find min
	int k = 1;
    Pair min1(10000, 10000.0);
    for (itr = data.begin(); itr != data.end(); ++itr) {
        if(itr->second < min1) min1 = itr->second;
        k++;
    }
    //insert min
    data.insert({k+1, min1});
}

template <class T>
void List<T>::delenie() {
	//find max and delenie
    Pair max1(-10000, -10000.0);
    for (itr = data.begin(); itr != data.end(); ++itr) {
        if(itr->second > max1) max1 = itr->second;
    }
    for (itr = data.begin(); itr != data.end(); ++itr) {
        itr->second.first = itr->second.first / max1.first;
        itr->second.second = itr->second.second / max1.second;
    }
}
