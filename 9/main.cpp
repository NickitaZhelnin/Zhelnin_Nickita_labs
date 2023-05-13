#include "list.h"
#include "error.h"
#include <iostream>
#include <exception>
using namespace std;

int main() {
    try {
        List a(5);
        cout << "a: " << a;
        cout << a[3] << endl;
        List b = a*3;
        cout << b;
        cout << a-2 << endl;
    }
    catch (Error &e) {
        e.what();
    }
    catch (...) {
        cout << "Unknown exception occurred" << endl;
    }
    return 0;
}
