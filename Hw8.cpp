#include <iostream>
#include <algorithm>
using namespace std;

void displayArray(int array[], int size) {
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
}

void selectionSort(int array[], int size) {
	sort(array, array + size, greater<int>());
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
}

int findMax(int array[], int size) {
	int max = array[0];
	for (int i = 0; i < size; i++) {
		if (array[i] > max) {
			max = array[i];
		}
	}
	return max;
}

int findMin(int array[], int size) {
	int min = array[0];
	for (int i = 0; i < size; i++) {
		if (array[i] < min) {
			min = array[i];
		}
	}
	return min;
}

double findAvg(int array[], int size) {
	double total = 0;
	for (int i = 0; i < size; i++) {
		total+=array[i];
	}
	return (double)(total / size);
}

int Hw8() {
	int loop;
	int scoreArray[50];

	cout << "How many scores do you want to enter? ";
	cin >> loop;
	for (int i = 0; i < loop; i++) {
		cout << "Enter score #" << i+1 << ": ";
		cin >> scoreArray[i];
	}

	cout << "Original order scores are: ";
	displayArray(scoreArray, loop);
	cout << endl << endl << "Scores ordered high to low: ";
	selectionSort(scoreArray, loop);
	cout << endl << endl << "Highest score: ";
	cout << findMax(scoreArray, loop);
	cout << endl << endl << "Lowest score: ";
	cout << findMin(scoreArray, loop);
	cout << endl << endl << "Average of scores: ";
	cout << findAvg(scoreArray, loop);

	cout << endl << endl;
	system("pause");
	return 0;
}