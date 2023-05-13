#include "list.h"
#include "pair_head.h"


int main() {
	Pair p1(2, 2.5);
	List<Pair> a(3, p1);
	cout << a << endl;
	List<Pair> b(a); 
	cout << b << endl;
	List<Pair> c = a * b;
	cout << c << endl;
	Pair num;
	cout << "Write a number:\n"; cin >> num;
	b.pushback(num);
	b.popfront();
	for (Iterator<Pair> iter = b.first(); iter != b.last(); ++iter)
		cout << *iter << '\n';
	return 0;
}