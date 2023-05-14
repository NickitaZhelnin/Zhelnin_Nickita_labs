#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include "pair.h"
using namespace std;

struct Comp_less{
    public:
    bool operator() (Pair p1, Pair p2){
        if (p1>p2) return true;
        else return false;
    }
};

ostream& operator<<(ostream& out, vector<Pair>& v) {
	for_each(v.begin(), v.end(), [](Pair& p) {cout << p; });
	return out;
}

bool EQUAL(Pair a, Pair t) {
	if (a == t) return true;
	return false;
}

void menu(const int c, vector<Pair>& v) {
	switch (c) {
		//sort
	case 1: {
		cout << v << endl;
		cout << "< - po vozr\n> - po ubiv\n";
		char op;
		cin >> op;
		if (op == '<') sort(v.begin(), v.end());
		else if (op == '>') sort(v.begin(), v.end(), Comp_less());
		else cout << "wrong character\n";
		cout << v << endl;
		break;
	}
		  //find element 
	case 2: {
		cout << v << "\n\n";
		cout << "Input value:\n";
		Pair value;
		cin >> value;
		auto it = find_if(v.begin(), v.end(), bind2nd(ptr_fun(EQUAL), value));
		if (it == v.end()) {
			cout << "no such element!" << endl;
			break;
		}
		for (auto i = v.begin(); i != v.end(); ++i) {
			if (i == it) {
				cout << "the element is " << *i << endl;
			}
		}
		break;
	}
    //delete < sred
	case 3: {
		cout << v << endl << endl;
		Pair sum;
		for_each(v.begin(), v.end(), [&sum](Pair& p) {sum += p; });
		sum.set_first(sum.get_first() / v.size());
		sum.set_second(sum.get_second() / v.size());
		for (vector<Pair>::iterator i = v.begin(); i != v.end(); ++i) {
			i = v.erase(i);
		}
		break;
		cout << v << endl;
		break;
	}
		  //dobavit min
	case 4: {
		cout << v << endl;
		auto mini = min_element(v.begin(), v.end());
        	int pos;
		cout << "\nPosition: "; cin >> pos;
		auto iter = v.cbegin();
        	v.emplace(iter+pos-1, mini);
		cout << "Elements: " << endl;
		for_each(v.begin(), v.end(), [](Pair& p) {cout << p; });
		break;
	}
		  //delenie na max
	case 5: {
		cout << v << endl << endl;
		auto maxi = max_element(v.begin(), v.end());
		cout << "max: " << *maxi;
		int tmp;
		for_each(v.begin(), v.end(), [&maxi](Pair& p) {p /= *maxi;});
		cout << endl << v << endl;
		break;
	}
		  //print
	case 6: {
		cout << v << endl;
		break;
	}
		  //exit
	default: {
		cout << "\nExiting from menu" << endl;
		exit(777);
	}
	}
}


int main() {
	int n;
	cout << "Size: ";
	cin >> n;
	vector<Pair> v(n);
	generate(v.begin(), v.end(), []() {Pair p; p.set_random(); return p; });
	cout << v << endl;

	while (true) {
		system("pause");
		system("cls");
		cout << "1. Sort container\n";
		cout << "2. Find a pair\n";
		cout << "3. Delete < sred\n";
		cout << "4. Dobavit min\n";
		cout << "5. Delenie na max\n";
		cout << "6. Print container\n";
		int c;
		cin >> c;
		system("cls");
		menu(c, v);
	}
	return 0;
}
