/*
 * Class: CMSC140 CRN
 * Instructor: Ahmed Tarek
 * Project<5>
 * Description: Write a program that simulates a magic square using 3 one dimensional parallel arrays 
				 of integer type. Each one the arrays corresponds to a row of the magic square. The 
				 program asks the user to enter the values of the magic square row by row and informs 
				 the user if the grid is a magic square or not.
 * Due Date: 12/6/2020
 * I pledge that I have completed the programming assignment independently.
   I have not copied the code from a student or any source.
   I have not given my code to any student.
   Print your Name here: Thomas Tran

 * Pseudocode or Algorithm for the program:
	(be sure to indent items with control structure)
	(need to match flow chart submitted in documentation)
 1. Ask function fillArray
	a. Keeps asking user for input until a 3x3 square is filled
 2. Ask function showArray
	a. Display the numbers the user inputed
 3. Calls isMagicSquare function in if statement.
	a. Calls function checkRange
		- Checks every slot in a 3x3 grid if between min of 1 and max of 9
	b. Calls function checkUnique
		- Checks every slot in a 3x3 grid if all slots are different from each other
	c. Calls function checkRowSum
		- Adds up 3 individual rows to see if equal to 15, magic number
	d. Calls function checkColSum
		- Adds up 3 individual columns to see if equal to 15, magic number
	e. Calls function checkDiagSum
		- Adds up 2 individual lines, one from top-left to bottom-right, one from top-right to bottom-left
 4. If isMagicSquare 0, or false, then display that it's not a magic square.
	otherwise it will display that it is.
 5. Ask user if they want to play again
	a. If yes the code repeats from the do while loop
	b. If no, do while loop ends
 6. Display credits
 (more as needed)
*/
#include<iostream>
#include <string>
using namespace std;

//Global constants 
const int ROWS = 3;  // The number of rows in the array
const int COLS = 3;  // The number of columns in the array
const int MIN = 1;  // The value of the smallest number
const int MAX = 9;  // The value of the largest number

//Function prototypes
bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max) {
	bool checker = true;
	//3 loops for 3 rows, check if between 9 and 1
	for (int c = 0; c < size; c++) {
		if (arrayRow1[c] > max || arrayRow1[c] < min) {
			checker = false;
		}
	}
	for (int c = 0; c < size; c++) {
		if (arrayRow2[c] > max || arrayRow2[c] < min) {
			checker = false;
		}
	}
	for (int c = 0; c < size; c++) {
		if (arrayRow3[c] > max || arrayRow3[c] < min) {
			checker = false;
		}
	}
	return checker;
}
bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) {
	//Local variables
	int num = 0;
	int repeat = 0;
	//Three main for loops for each array, 1, 2, 3
	for (int c = 0; c < size; c++) {
		num = arrayRow1[c]; //Num gets a designated number in the array. Ex R1C1.
		for (int i = 0; i < size; i++) {
			if (num == arrayRow1[i] || num == arrayRow2[i] || num == arrayRow3[i]) {
				repeat++; //Num is checked throughout all Rows and Cols. If there is a repeat then add to variable.
			}
		}
	}
	for (int c = 0; c < size; c++) {
		num = arrayRow2[c];
		for (int i = 0; i < size; i++) {
			if (num == arrayRow1[i] || num == arrayRow2[i] || num == arrayRow3[i]) {
				repeat++;
			}
		}
	}
	for (int c = 0; c < size; c++) {
		num = arrayRow3[c];
		for (int i = 0; i < size; i++) {
			if (num == arrayRow1[i] || num == arrayRow2[i] || num == arrayRow3[i]) {
				repeat++;
			}
		}
	}
	//Checks if there are repeats. Compared with 9 b/c in the prev loops there will always be one repeat and 3x3 is 9.
	//Example: When checking R2C1, the for loops will always check, startng with R1C1, eventually seeing a repeat of itself with R2C1.
	if (repeat == 9) {
		return true;
	}
	else {
		return false;
	}
}
bool checkRowSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size) {
	bool checker = true;
	int sum = 0;
	//Calculate total for each row, starting with R1
	//If doesn't meet magic num, 15, then false.
	for (int c = 0; c < size; c++) {
		sum += arrayrow1[c];
	}
	if (sum != 15) {
		checker = false;
	}
	sum = 0;

	for (int c = 0; c < size; c++) {
		sum += arrayrow2[c];
	}
	if (sum != 15) {
		checker = false;
	}
	sum = 0;

	for (int c = 0; c < size; c++) {
		sum += arrayrow3[c];
	}
	if (sum != 15) {
		checker = false;
	}
	sum = 0;
	return checker;
}
bool checkColSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size) {
	bool checker = true;
	int sum = 0;
	//Calculate total for a column, see if meet num 15
	for (int c = 0; c < size; c++) {
		sum += arrayrow1[c];
		sum += arrayrow2[c];
		sum += arrayrow3[c];
		if (sum != 15) {
			checker = false;
		}
		else {
			sum = 0;
		}
	}
	sum = 0;
	return checker;
}
bool checkDiagSum(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size) {
	bool checker = true;
	int sum = 0;
	//Calculate sum starting from top-left to bottom-right then again for top-right to bottom-left
	sum += arrayrow1[0];
	sum += arrayrow2[1];
	sum += arrayrow3[2];
	if (sum != 15) {
		checker = false;
	}
	else {
		sum = 0;
	}

	sum += arrayrow1[2];
	sum += arrayrow2[1];
	sum += arrayrow3[0];
	if (sum != 15) {
		checker = false;
	}
	else {
		sum = 0;
	}
	sum = 0;
	return checker;
}
bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) {
	bool checker = true;
	//If all these meet then it is a magic square
	if (checkRange(arrayRow1, arrayRow2, arrayRow3, size, MIN, MAX) == 0) {
		checker = false;
	}
	if (checkUnique(arrayRow1, arrayRow2, arrayRow3, size) == 0) {
		checker = false;
	}
	if (checkRowSum(arrayRow1, arrayRow2, arrayRow3, size) == 0) {
		checker = false;
	}
	if (checkColSum(arrayRow1, arrayRow2, arrayRow3, size) == 0) {
		checker = false;
	}
	if (checkDiagSum(arrayRow1, arrayRow2, arrayRow3, size) == 0) {
		checker = false;
	}
	return checker;
}
void fillArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) {
	int num;
	for (int c = 0; c < size; c++) {
		cout << "Enter the number for row 0 and and column " << c << ": ";
		cin >> num;
		arrayRow1[c] = num;
	}
	for (int c = 0; c < size; c++) {
		cout << "Enter the number for row 1 and and column " << c << ": ";
		cin >> num;
		arrayRow2[c] = num;
	}
	for (int c = 0; c < size; c++) {
		cout << "Enter the number for row 2 and and column " << c << ": ";
		cin >> num;
		arrayRow3[c] = num;
	}
}
void showArray(int arrayrow1[], int arrayrow2[], int arrayrow3[], int size) {
	for (int c = 0; c < size; c++) {
		cout << arrayrow1[c] << " ";
	}
	cout << endl;
	for (int c = 0; c < size; c++) {
		cout << arrayrow2[c] << " ";
	}
	cout << endl;
	for (int c = 0; c < size; c++) {
		cout << arrayrow3[c] << " ";
	}
	cout << endl;
}

int main()
{
	/* Define a Lo Shu Magic Square using 3 parallel arrays corresponding to each row of the grid */
	int magicArrayRow1[COLS], magicArrayRow2[COLS], magicArrayRow3[COLS];
	string retry;
	//Do while so a person can play again
	do {
		fillArray(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLS);
		showArray(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLS);
		if (isMagicSquare(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLS) == 0) {
			cout << endl << "This is not a Lo Shu magic square." << endl << endl;
		}
		else {
			cout << endl << "This is a Lo Shu magic square, well done!" << endl << endl;
		}
		cout << "Would you like to play again? (y/n) ";
		cin >> retry;
		cout << endl;
	} while (retry == "y");
	cout << endl << "Thank you for testing my program!!" << endl << "PROGRAMMER: Thomas Tran" << endl << "CMSC140 Common Project 5" << endl << "Due Date: 12/6/2020" << endl << endl;
	system("pause");
	return 0;
}
// Function definitions go here
