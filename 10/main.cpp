#include "pair.h"
#include "file_work.h" 
#include <iostream> 
#include <fstream>
#include <string> 
using namespace std; 

int main() {

	Pair p, temp; int k, c, num, count; double plus; char file_name[30];
	do{
		//system("pause"); system("cls");
		cout << "1. Make file"; 
		cout << "\n2. Print file";
		cout << "\n3. Del file";
		cout << "\n4. Add file";
		cout << "\n5. Change file";
		cout<<"\n0. Exit\n";
		cin >> c; 
		switch (c) {
		case 1://sozdanie
			cout << "File: "; cin >> file_name;
			k = make_file(file_name);
			if (k < 0) cout << "Error\n";
			break;
		case 2://vivod
			cout << "File: "; cin >> file_name;
			k = print_file(file_name);
			if (k == 0) cout << "Error\n";
			if (k < 0) cout << "Error\n";
			break;
		case 3://udalenie par iz intervala
			cout << "File: "; cin >> file_name;
			int temp1, temp2;
			cin >> temp1;
			cin >> temp2;
			k = del_file(file_name, temp1, temp2);
			if (k < 0)cout << "Error\n";
			break;
		case 4://dobavlenie
			cout << "File: "; cin >> file_name;
			cout << "Count: "; cin >> count;
			k = add_file(file_name, 1, count);
			if (k < 0) cout << "Error\n";
			if (k == 0) k = add_end(file_name, count);
			break;
		case 5://umnozhenie v 2r
			cout << "File: "; cin >> file_name;
			int num;
			cin >> num;
			k = change_file(file_name, num);
			if (k < 0) cout << "Error\n";
			break;
		}
	} while (c != 0);
	return 0;
}