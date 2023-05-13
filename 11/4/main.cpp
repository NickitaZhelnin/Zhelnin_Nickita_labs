#include "pair.h"
#include <iostream>
#include <queue>
#include <list>
using namespace std;

typedef queue<Pair> Q;
typedef list<Pair> List;

Q make_q(int n) {
	Q s; 
	Pair t;
	for (int i = 0;i < n;i++) {
		cin >> t; 
		s.push(t);
	}
	return s;
}

List copy_q_to_list(Q q) {
	List l;
	while (!q.empty()) {
		l.push_back(q.front());
		q.pop();
	}
	return l;
}

Q copy_list_to_q(List l) {
	Q q;
	for (auto it = l.cbegin();it != l.cend();++it)
		q.push(*it);
	return q;
}

void print_q(Q q) {
	List l = copy_q_to_list(q);
	for (auto it = l.cbegin();it != l.cend();++it)
		cout << *it;
	cout << endl;
}

Pair srednee(Q q) {
	Pair s;
	List l = copy_q_to_list(q);
	for (auto it = l.begin();it != l.end();++it) s += *it;
	int n = l.size();
	s = s / n;
	return s;
}

void add_q(Q& q, Pair el) {
	q.push(el);
}

void remove_elements(Q& q, Pair srednee) {
	List l = copy_q_to_list(q);
	for (auto it = l.begin();it != l.end();) {
		if (*it < srednee)
			it = l.erase(it);
		else
			++it;
	}
	q = copy_list_to_q(l);
}

Pair max(Q q) {
	Pair max(0,0);
	List l = copy_q_to_list(q);
	for (auto it = l.begin();it != l.end();++it)
		if (*it > max)
			max = *it;
	return max;
}

Pair min(Q q) {
	Pair min(11111,11111);
	List l = copy_q_to_list(q);
	for (auto it = l.begin();it != l.end();++it)
		if (*it < min)
			min = *it;
	return min;
}

void delenie_elements(Q& q, Pair max) {
	List l = copy_q_to_list(q);
	for (auto it = l.begin();it != l.end();++it)
		*it /= max;
	q = copy_list_to_q(l);
}

int main() {
	Q q;
	int n;
	cout << "Size: "; cin >> n;
	q = make_q(n);
	print_q(q);
	Pair el = srednee(q);
	add_q(q, el);
	print_q(q);
	cout << "Remove elements:\n";
	remove_elements(q, el);
	print_q(q);
	cout << "Delenie elements:\n";
	delenie_elements(q, max(q));
	print_q(q);
	return 0;
}