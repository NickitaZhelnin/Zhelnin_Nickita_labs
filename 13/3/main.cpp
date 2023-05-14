#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <functional>
#include "pair.h"
using namespace std;
typedef multiset<Pair> Q;
typedef vector<Pair> V;

struct Comp_less{
    public:
    bool operator() (Pair p1, Pair p2){
        if (p1>p2) return true;
        else return false;
    }
};
void Print(Q v){
    multiset<Pair>::iterator i;
    for(i = v.begin(); i!=v.end(); ++i) {
        cout << i->first << " : " << i->second << endl;
    }
    
}
bool EQUAL(Pair a, Pair t) {
	if (a == t) return true;
	return false;
}

void menu(const int c, Q v) {
	switch (c) {
		//sort
	case 1: {
		Print(v);
		cout << "< - po vozr\n> - po ubiv\n";
		char op;
		cin >> op;
		if (op == '<') sort(v.begin(), v.end());
		else if (op == '>') sort(v.begin(), v.end(), Comp_less());
		else cout << "wrong character\n";
		Print(v);
		break;
	}
		  //find element 
	case 2: {
		Print(v);
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
		Print(v);
		Pair sum;
		for_each(v.begin(), v.end(), [&sum](Pair& p) {sum += p; });
		sum.set_first(sum.get_first() / v.size());
		sum.set_second(sum.get_second() / v.size());
		for (multiset<Pair>::iterator i = v.begin(); i != v.end(); ++i) {
			i = v.erase(i);
		}
		break;
		Print(v);
		break;
	}
		  //dobavit min
	case 4: {
		Print(v);
		auto mini = min_element(v.begin(), v.end());
       		int pos;
		cout << "\nPosition: "; cin >> pos;
        	v.insert(*mini);
		cout << "Elements: " << endl;
		for_each(v.begin(), v.end(), [](Pair& p) {cout << p; });
		break;
	}
		  //delenie na max
	case 5: {
		Print(v);
		auto maxi = max_element(v.begin(), v.end());
		cout << "max: " << *maxi;
		int tmp;
		for_each(v.begin(), v.end(), [&maxi](Pair& p) {p /= *maxi;});
		Print(v);
		break;
	}
		  //print
	case 6: {
		Print(v);
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
	Q q;
	Pair a;
	for(int i = 0; i<n; i++){
	    cin >> a;
	    q.insert(a);
	}
	Print(q);

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
		menu(c, q);
	}
	return 0;
}
