#pragma once
#include <iostream>
using namespace std;

struct Node{
    Node* prev = nullptr;
    Node* next = nullptr;
    int data = 0;
};

class Iterator{
    friend class List;
    Node* n;
public:
    Iterator(){
        n = nullptr;
    }
    Iterator(const Iterator& it){
        n = it.n;
    }
    Iterator& operator=(const Iterator& a) {
		n = a.n;
		return *this;
	}
	bool operator==(const Iterator& it) { return n == it.n; }
	bool operator!=(const Iterator& it) { return n != it.n; };
	Iterator& operator++() {
		n = n->next;
		return *this;
	};
	Iterator& operator--() {
		n = n->prev;
		return *this;
	}
	Iterator& operator+(const int& a) {
		for (int i = 0; i < a; i++) n = n->next;
		return *this;
	}
	Iterator& operator-(const int& a) {
		for (int i = 0; i < a; i++) n = n->prev;
		return *this;
	}
	int& operator *() const { return n->data; }
};

class List {
private:
	int size;
	Node* head = nullptr;
	Node* tail = nullptr;
	Iterator start, end;
public:
	List();
	List(int s, int k = 0);
	List(const List&);
	~List();
	int front();
	int back();
	void pushback(int data);
	void pushfront(int data);
	void popback();
	void popfront();
	bool empty();
	List& operator=(const List&);
	int& operator[](int index);
	int& operator()();
	List operator*(List&);
	friend ostream& operator <<(ostream&, const List&);
	friend istream& operator >>(istream&, const List&);
	Iterator first() { return start; }
	Iterator last() { return end; }
};
