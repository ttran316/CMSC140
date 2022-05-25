/*
#include <iostream>
using namespace std;

int choice, numberOne, numberTwo, result = 0;

void getChoice() {
	do {
		cout << "Enter your choice, 1 for addition, 2 for subtaction: ";
		cin >> choice;
		if (choice > 2 || choice < 1) {
			cout << "Please input 1 or 2" << endl << endl;
		}
	} while (choice > 2 || choice < 1);
}

void getNumbers() {
	cout << "Enter the first number: ";
	cin >> numberOne;
	cout << "Enter the second number: ";
	cin >> numberTwo;
}

int main() {
	getChoice();
	getNumbers();

	if(choice == 1){
		result = numberOne + numberTwo;
	}
	else if (choice == 2) {
		result = numberOne - numberTwo;
	}
	cout << "The result of the operation is: " << result << endl;

	system("pause");
	return 0;
}
*/