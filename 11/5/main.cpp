#include "pair.h"
#include "list.h"
#include <iostream>
#include <queue>
#include <list>
using namespace std;

int main() {
	List<Pair> l(3);
	l.Print();
	Pair el = l.srednee();
	l.add_list(el);
	l.Print();
	cout << "Remove elements:\n";
	l.remove_elements(el);
	l.Print();
	cout << "Delenie elements:\n";
	l.delenie_elements(l.max());
	l.Print();
	return 0;
}