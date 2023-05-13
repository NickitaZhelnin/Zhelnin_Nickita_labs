#include "pair.h"
#include "list.h"
#include <iostream>
using namespace std;

int main() {
	List<Pair> l(3);
	l.Print();
	int n;
	Pair range_min, range_max, min_el, max_el;
	Pair el = l.srednee();
	int pos;
	cin >> pos;
	l.add_list(el, pos);
	l.Print();
	cout << "Remove elements:\n";
	l.remove_elements(l.srednee());
	l.Print();
	cout << "Increase elements:\n";
	l.increase_elements(l.max());
	l.Print();
	return 0;
}