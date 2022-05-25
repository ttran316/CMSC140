#include <iostream>
using namespace std;

void largerThanN(int array[], int size, int n) {
	cout << "The numbers that are larger than " << n << " are ";
	//If no numbers are greater than n
	if (n > 90) {
		cout << "none";
		//exit;
	}
	//Chceks every number, one by one, in array and compare to n
	for (int i = 0; i < size; i++) {
		if (n < array[i]) {
			cout << array[i] << " ";
		}
	}
	cout << endl;
}

int Hw7() {
	int n;
	int number[] = { 30, 20, 50, 2, -1, 44, 3, 12, 90, 32 };
	cout << "Enter a number:" << endl;
	cin >> n;
	largerThanN(number, 10, n);
	system("pause");
	return 0;
}