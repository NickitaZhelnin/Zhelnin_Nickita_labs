#include "pair.h"
#include <iostream>
#include <vector> 
#include <cstdlib> 
using namespace std;

typedef vector<Pair>Vec;
Vec make_vector(int n) {
	Vec v;
	for (int i = 0;i < n;i++) {
		Pair a;
		cin >> a;
		v.push_back(a);
	}
	return v;
}

void print_vector(Vec v) {
	for (int i = 0;i < v.size();i++)
		cout << v[i];
	cout << endl;
}

Pair srednee(Vec v){
	Pair s;
	for (int i=0;i<v.size();i++) s += v[i];
	int n = v.size();
	s = s / n;
	return s;
}
void add_vector(Vec &v, Pair el, int pos) { 
	v.insert(v.begin()+pos-1, el);
}

void remove_elements(Vec &v, Pair srednee) {
	for (int i = 0; i<v.size();i++) {
		if (v[i]<srednee)
			v.erase(v.begin()+i);
	}
}

Pair max(Vec v) {
	Pair max(0,0);
	int n=0;
	for (int i = 0;i<v.size();i++)
		if (max<v[i]){
			max = v[i];
			n=i;//pos max
		}
	return max;
}

Pair min(Vec v) {
	Pair min(1110,1110);
	int n=0;
	for (int i =0;i<v.size();i++)
		if (v[i]<min){
			min = v[i];
			n=i;//pos min
		}
	return min;
}

void delenie(Vec &v, Pair max) {
	for (int i = 0; i<v.size();i++)
		v[i] /= max;
}

int main() {
	try {
		vector<Pair> v;
		int n, pos;
		cout << "Size: "; cin >> n;
		v = make_vector(n);
		print_vector(v);
		Pair el = srednee(v);
		cout << "Pos: " ; cin >> pos;
		add_vector(v, el, pos);
		print_vector(v);
		remove_elements(v, el);
		cout << "Delete numbers < sr_znach:" << endl;
		print_vector(v);
		cout << "Delenie na max:" << endl;
		delenie(v, max(v));
		print_vector(v);
		
	}
	catch (float) {
		cout << "error!";
	}
}
