#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
#include "pair.h"
using namespace std;
typedef queue<Pair> Q;
typedef vector<Pair> V;

struct Comp_less{
    public:
    bool operator() (Pair p1, Pair p2){
        if (p1>p2) return true;
        else return false;
    }
};

Q make_q(int n) {
	Q s; 
	Pair t;
	for (int i = 0;i < n;i++) {
		cin >> t; 
		s.push(t);
	}
	return s;
}
V copy_q_to_v(Q q) {
	V v;
	while (!q.empty()) {
		v.push_back(q.front());
		q.pop();
	}
	return v;
}
Q copy_v_to_q(V v) {
	Q q;
	for (auto it = v.cbegin();it != v.cend();++it)
		q.push(*it);
	return q;
}

ostream& operator<<(ostream& out, Q q) {
    V v = copy_q_to_v(q);
	for_each(v.begin(), v.end(), [](Pair& p) {cout << p; });
	return out;
}

bool EQUAL(Pair a, Pair t) {
	if (a == t) return true;
	return false;
}

void menu(const int c, Q q) {
	switch (c) {
		//sort
	case 1: {
		cout << q << endl;
		cout << "< - po vozr\n> - po ubiv\n";
		char op;
		cin >> op;
		V v = copy_q_to_v(q);
		if (op == '<') sort(v.begin(), v.end());
		else if (op == '>') sort(v.begin(), v.end(), Comp_less());
		else cout << "wrong character\n";
		cout << q << endl;
		break;
	}
		  //find element 
	case 2: {
		cout << q << "\n\n";
		cout << "Input value:\n";
		Pair value;
		cin >> value;
		V v = copy_q_to_v(q);
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
		cout << q << endl << endl;
		Pair sum;
		V v = copy_q_to_v(q);
		for_each(v.begin(), v.end(), [&sum](Pair& p) {sum += p; });
		sum.set_first(sum.get_first() / v.size());
		sum.set_second(sum.get_second() / v.size());
		for (vector<Pair>::iterator i = v.begin(); i != v.end(); ++i) {
			i = v.erase(i);
		}
		break;
		cout << q << endl;
		break;
	}
		  //dobavit min
	case 4: {
		cout << q << endl;
		V v = copy_q_to_v(q);
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
		cout << q << endl << endl;
		V v = copy_q_to_v(q);
		auto maxi = max_element(v.begin(), v.end());
		cout << "max: " << *maxi;
		int tmp;
		for_each(v.begin(), v.end(), [&maxi](Pair& p) {p /= *maxi;});
		cout << endl << q << endl;
		break;
	}
		  //print
	case 6: {
		cout << q << endl;
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
	q = make_q(n);
	V v = copy_q_to_v(q);
	generate(v.begin(), v.end(), []() {Pair p; p.set_random(); return p; });
	cout << q << endl;

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
