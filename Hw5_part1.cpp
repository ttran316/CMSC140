#include <iostream>
using namespace std;

int Hw5_part1() {
	char star = '*';

	cout << "(i)" << endl;
	for (int i = 0;i < 10;i++) {
		cout << star;
	}

	cout << endl << endl << "(ii)" << endl;
	for (int i = 0;i < 20;i++) {
		cout << star;
	}

	cout << endl << endl << "(iii)" << endl;
	for (int i = 0;i < 10;i++) {
		for (int x = 0; x <= i;x++) {
			cout << star;
		}
		cout << endl;
	}

	cout << endl << "(iv)" << endl;
	for (int i = 0;i < 20;i++) {
		for (int x = 0; x <= i;x++) {
			cout << star;
		}
		cout << endl;
	}

	cout << endl << "(v)" << endl;
	for (int i = 10;i > 0;i--) {
		for (int x = 0; x < i;x++) {
			cout << star;
		}
		cout << endl;
	}

	cout << endl << "(vi)" << endl;
	for (int i = 20;i > 0;i--) {
		for (int x = 0; x < i;x++) {
			cout << star;
		}
		cout << endl;
	}
	cout << endl;

	system("pause");
	return 0;
}