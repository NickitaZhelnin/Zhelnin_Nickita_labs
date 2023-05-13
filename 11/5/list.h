#pragma once
#include <list>
#include <queue>
#include <iostream>
using namespace std;

template <class T>
class List {
	queue<T> q;
	int size;
public:
	List(void);
	List(int n);
	void Print();
	~List(void);
	T srednee();
	void add_list(T el);
	void remove_elements(T srednee);
	T max();
	T min();
	void delenie_elements(T max);
};

template <class T>
list<T> copy_q_to_list(queue<T> q) {
	list<T> l;
	while (!q.empty()) {
		l.push_back(q.front());
		q.pop();
	}
	return l;
}

template <class T>
queue<T> copy_list_to_q(list<T> l) {
	queue<T> q;
	for (auto it = l.cbegin();it != l.cend();++it)
		q.push(*it);
	return q;
}

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
		cin >> a;
		q.push(a);
	}
	size = q.size();
}

template <class T>
void List<T>::Print() {
    list<T> l = copy_q_to_list(q);
	for (auto it = l.begin();it != l.end();++it)
		cout << *it;
	cout << endl;
}

template <class T>
T List<T>::srednee() {
	T s;
	list<T> l = copy_q_to_list(q);
	for (auto it = l.begin();it != l.end();++it) s += *it;
	int n = l.size();
	s = s / n;
	return s;
}

template <class T>
void List<T>::add_list(T el) {
	q.push(el);
}

template <class T>
void List<T>::remove_elements(T srednee) {
    list<T> l = copy_q_to_list(q);
	for (auto it = l.begin();it != l.end();) {
		if (*it < srednee)
			it = l.erase(it);
		else
			++it;
	}
	q = copy_list_to_q(l);
}

template <class T>
T List<T>::max() {
    list<T> l = copy_q_to_list(q);
	T max = *(l.begin());
	for (auto it = l.begin();it != l.end();++it)
		if (*it > max)
			max = *it;
	return max;
}
template <class T>
T List<T>::min() {
    list<T> l = copy_q_to_list(q);
	T min = *(l.begin());
	for (auto it = l.begin();it != l.end();++it)
		if (*it < min)
			min = *it;
	return min;
}

template <class T>
void List<T>::delenie_elements(T max) {
    list<T> l = copy_q_to_list(q);
	for (auto it = l.begin();it != l.end();++it)
		*it /= max;
	q = copy_list_to_q(l);
}