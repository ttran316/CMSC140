#include <iostream>
using namespace std;

int Hw4_part2() {
	int subjects = 0;
	double price = 0;
	double discount = 0;
	char fancyBackground;
	char appointmentDate;

	cout << "Enter the number of subjects in the portrait: ";
	cin >> subjects;
	cout << "Do you want a fancy background (y/n)? ";
	cin >> fancyBackground;
	cout << "Do you want an appointment date (y/n)? ";
	cin >> appointmentDate;

	if (subjects == 1) {
		price = 100;
	}else if (subjects == 2) {
		price = 130;
	}else if (subjects == 3) {
		price = 150;
	}else if (subjects == 4) {
		price = 160;
	}else{
		price = 165;
	}

	discount = price * 0.1;
	if (fancyBackground == 'y') {
		price += discount;
	}
	if (appointmentDate == 'y') {
		price += discount;
	}
	
	cout << "The price is: $" << price << endl;

	system("pause");
	return 0;
}