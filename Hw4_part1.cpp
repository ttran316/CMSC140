#include <iostream>
using namespace std;

int Hw4_part1() {
	double units = 0;
	double discount = 0;
	double total = 0;

	cout << "How many units were sold? ";
	cin >> units;

	if(units <= 0){
		cout << "Units sold must be greater than zero." << endl;
	}else{
		if (0 < units && units < 10) {
			total = units * 99;
		}else if (10 <= units && units <= 19) {
			units *= 99;
			discount = units * 0.20;
			total = units - discount;
		}else if (20 <= units && units <= 49) {
			units *= 99;
			discount = units * 0.30;
			total = units - discount;
		}else if (50 <= units && units <= 99) {
			units *= 99;
			discount = units * 0.40;
			total = units - discount;
		}else {
			units *= 99;
			discount = units * 0.50;
			total = units - discount;
		}
		cout << "The total cost of the purchase is $" << total << endl;
	}
	system("pause");
	return 0;
}