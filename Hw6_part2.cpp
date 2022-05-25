#include <iostream>
using namespace std;

int choice, amount;
double pay, tax, purchase, change;

void showMenu() {
	cout << "**** Vending Machine ****" << endl << "1. Coke $1.25" << endl << "2. Pepsi $1.00" << endl << "3. Water $2.00" << endl << "4. Coffee $1.50" << endl << "5. Exit menu" << endl << endl << "Enter your choice: ";
	cin >> choice;
	if (choice == 5) {
		exit(0);
	}
}

void takePayment() {
	cout << "How many do you want? ";
	cin >> amount;
	cout << "How much is your payment? ";
	cin >> pay;
}

void displayInfo() {
	if (choice == 4) {
		tax = (1.50 * amount) * 0.06;
		purchase = (1.50 * amount) + tax;
	}
	else if (choice == 3) {
		tax = (2.00 * amount) * 0.06;
		purchase = (2.00 * amount) + tax;
	}
	else if (choice == 2) {
		tax = (1.00 * amount) * 0.06;
		purchase = (1.00 * amount) + tax;
	}
	else if (choice == 1) {
		tax = (1.25 * amount) * 0.06;
		purchase = (1.25 * amount) + tax;
	}
	change = pay - purchase;
	cout << endl << endl << "Tax Amount: $" << tax << endl << endl << "Total Purchase: $" << purchase << endl << endl << "Change: $" << change << endl;
}

int Hw6_part2() {
	showMenu();
	takePayment();
	displayInfo();

	system("pause");
	return 0;
}