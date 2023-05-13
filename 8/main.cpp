#include "vector.h"
#include "dialog.h"
#include "event.h"
#include "book.h"
#include "object.h"
#include "print.h"

int main() {

	cout << "m: Make\n";
	cout << "+: Add\n";
	cout << "-: Del\n";
	cout << "s: Show\n";
	cout << "z: Get\n";
	cout << "q: Quit\n";
	Dialog D;
	D.Execute();
	return 0;
}