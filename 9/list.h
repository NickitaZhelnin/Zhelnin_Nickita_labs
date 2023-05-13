#pragma once
#include <iostream>
using namespace std;

struct Node {
	Node* prev = nullptr;
	Node* next = nullptr;
	int data = 0;
};

class List {
private:
	int size;
	Node* head = nullptr; 
	Node* tail = nullptr;
public:
	List();
	List(int s);
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
	int& operator-(int);
	List operator*(int);
	friend ostream& operator <<(ostream&, const List&);
	friend istream& operator >>(istream&, const List&);
};