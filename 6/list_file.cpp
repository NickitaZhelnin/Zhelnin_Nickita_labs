#include "list_head.h"
#include <iostream>
using namespace std;

List::List(int s, int k) {
	size = s;
	Node* node = new Node;
	node->data = k;
	head = node;
	tail = node;
	for (int i = 0; i < size - 1; i++) {
		Node* node = new Node;
		node->data = rand() % 10;
		tail->next = node;
		node->prev = tail;
		tail = node;
	}
	tail->next = nullptr;
	start.n = head;
	end.n = tail->next;
}

List::List() {
	size = 0;
	head = nullptr;
	tail = nullptr;
}

List::List(const List& a) {
	Node* node = a.head;
	while (node != nullptr) {
		pushback(node->data);
		node = node->next;
	}
	start = a.start;
	end = a.end;
}

List::~List() {
	Node* th = head;
	while (th != nullptr) {
		head = th->next;
		delete th;
		th = head;
	}
}

void List::pushback(int data) {
	Node* newNode = new Node;
	newNode->data = data;
	if (head == nullptr) {
		head = newNode;
		tail = newNode;
		size++;
		end.n = tail->next;
	}
	else {
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
		size++;
		end.n = tail->next;
	}
}

void List::pushfront(int data) {
	Node* newNode = new Node;
	newNode->data = data;
	if (head == nullptr) {
		head = newNode;
		tail = newNode;
		size++;
		start.n = head;
	}
	else {
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
		size++;
		start.n = head;
	}
}

int List::front() { return head->data; }

int List::back() { return tail->data; }

void List::popback() {
	if (head != nullptr) {
		Node* th = tail;
		tail = th->prev;
		delete th;
		tail->next = nullptr;
		size--;
		end.n = tail->next;
	}
}

void List::popfront() {
	if (head != nullptr) {
		Node* th = head;
		head = th->next;
		delete th;
		head->prev = nullptr;
		size--;
		start.n = head;
	}
}

bool List::empty() { return size == 0; }

List& List::operator=(const List& a) {
	if (this == &a) return *this;
	Node* node = head;
	while (node != nullptr) {
		head = node->next;
		delete node;
		node = head;
		size--;
	}
	Node* th = a.head;
	while (th != nullptr) {
		pushback(th->data);
		th = th->next;
	}
	start = a.start;
	end = a.end;
	return *this;
}

int& List::operator[](int index) {
	if (index < size && index >= 0) {
		Node* th = head;
		for (int i = 0; i < index; i++) th = th->next;
		return th->data;
	}
	else {
		cout << "Bad index, man!" << endl;
		exit(222);
	}
}

int& List::operator ()() {
	return size;
}
List List::operator*(List& a) {
	int tempsize = size;
	int b = 5;
	List templist(tempsize);
	for (int i = 0; i < tempsize; i++) templist[i] = (*this)[i] * b;
	return templist;

}

ostream& operator<<(ostream& out, const List& a) {
	Node* th = a.head;
	while (th != nullptr) {
		cout << th->data << " ";
		th = th->next;
	}
	cout << endl;
	return out;
}
istream& operator>>(istream& in, const List& a) {
	Node* th = a.head;
	while (th != nullptr) {
		in >> th->data;
		th = th->next;
	}
	return in;
}