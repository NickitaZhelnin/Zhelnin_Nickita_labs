#include "book.h"

Book::~Book(void) {}

Book::Book(void){
	pages = 0;
	izdat = "";
}

Book::Book(string N, string A, int P, string I) : Print(N, A) {
	pages = P;
	izdat = I;
}

Book::Book(const Book& P) {
	name = P.name;
	author = P.author;
	pages = P.pages;
	izdat = P.izdat;
}


void Book::Show() {
	cout << "\nName: " << name;
	cout << "\nAuthor: " << author;
	cout << "\nPages: " << pages;
	cout << "\nIzdat: " << izdat << endl;
}

void Book::Input() {
	getline(cin, name);
	cout << "Enter name: "; getline(cin, name);
	cout << "Enter author: "; getline(cin, author);
	cout << "Enter izdat: "; getline(cin, izdat);
	cout << "Enter pages: "; cin >> pages;
}

Book& Book::operator=(const Book& p) {
	if (&p == this) return *this;
	name = p.name;
	author = p.author;
	pages = p.pages;
	izdat = p.izdat;
	return *this;
}