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
/*

ostream& operator<<(ostream& out, Q v) {
    //V v = copy_q_to_v(q);
	for_each(v.begin(), v.end(), [](Pair& p) {cout << p; });
	return out;
}
*/
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
		//V v = copy_q_to_v(q);
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
		//V v = copy_q_to_v(q);
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
		//V v = copy_q_to_v(q);
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
		//V v = copy_q_to_v(q);
		auto mini = min_element(v.begin(), v.end());
		//cout << "Summary of each elment: " << endl;
		//for_each(v.begin(), v.end(), [](Pair& p) {cout << p.sum() << ' '; });
        int pos;
		cout << "\nPosition: "; cin >> pos;
		//auto iter = v.cbegin();
        v.insert(*mini);
		//auto s = remove_if(v.begin(), v.end(), [one, two](Pair& p) {return p >= one && p <= two; });
		//v.erase(s, v.end());

		cout << "Elements: " << endl;
		for_each(v.begin(), v.end(), [](Pair& p) {cout << p; });
		break;
	}
		  //delenie na max
	case 5: {
		Print(v);
		//V v = copy_q_to_v(q);
		//auto mini = min_element(v.begin(), v.end());
		auto maxi = max_element(v.begin(), v.end());
		//cout << "min: " << *mini;
		cout << "max: " << *maxi;
		int tmp;
		//sum = *mini + *maxi;
		//cout << "summary = " << sum << endl;
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
	//q = make_q(n);
	//V v = copy_q_to_v(q);
	//generate(v.begin(), v.end(), []() {Pair p; p.set_random(); return p; });
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