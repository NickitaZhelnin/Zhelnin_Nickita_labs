#include <iostream>
#include <vector> 
#include <cstdlib> 
using namespace std;

typedef vector<float>Vec;
Vec make_vector(int n) {
	Vec v;
	for (int i = 0;i < n;++i) {
		float a = (rand() % 100 + 100);
		a /= 100;
		v.push_back(a);
	}
	return v;
}

void print_vector(Vec v) {
	for (int i = 0;i < v.size();i++)
		cout << v[i] << " ";
	cout << endl;
}

float srednee(Vec v){
	float s = 0;
	for (int i=0;i<v.size();i++) s += v[i];
	int n = v.size();
	return s/n;
}
void add_vector(Vec &v, float el, int pos) { 
	v.insert(v.begin()+pos-1, el);
}

void remove_elements(Vec &v, float srednee) {
	for (int i = 0; i<v.size();i++) {
		if (v[i]<srednee)
			v.erase(v.begin()+i);
	}
}

float max(Vec v) {
	float max = v[0];
	int n=0;
	for (int i = 0;i<v.size();i++)
		if (max<v[i]){
			max = v[i];
			n=i;//pos max
		}
	return max;
}

float min(Vec v) {
	float min = v[0];
	int n=0;
	for (int i =0;i<v.size();i++)
		if (v[i]<min){
			min = v[i];
			n=i;//pos min
		}
	return min;
}

void delenie(Vec &v, float max) {
	for (int i = 0; i<v.size();i++)
		v[i] = v[i] / max;
}

int main() {
	try {
		vector<float> v;
		int n, pos;
		//float d_min;
		cout << "Size: "; cin >> n;
		v = make_vector(n);
		print_vector(v);
		float el = srednee(v);
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
	//return 0;
}
