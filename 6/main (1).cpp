#include "list_head.h"
#include <iostream>
using namespace std;

int main() {
	srand(time(NULL));
	List a(10);
	cout << a << endl;
	for (int i = 0; i < a(); i++) a[i] = rand() % 100 - 40;
	cout << a << endl;
	List b(a);
	cout << "List have been copied\n";
	cout << b << endl;
	cout << a*b << endl;
	int num;
	cout << "Enter int number: "; cin >> num;
	b.pushback(num);
	b.popfront();
	for (Iterator iter = b.first(); iter != b.last(); ++iter) 
		cout << *iter << " ";
	return 0;
}
