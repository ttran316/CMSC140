/*
 * Class: CMSC140 CRN
 * Instructor: Ahmed Tarek
 * Project<2>
 * Description: There are two main systems for measuring distance, weight and temperature, 
				the Imperial System of Measurement and the Metric System of Measurement. 
				Most countries use the Metric System, which uses the measuring units such 
				as meters and grams and adds prefixes like kilo, milli and centi to count 
				orders of magnitude. In the United States, we use the older Imperial system, 
				where things are measured in feet, inches and pounds.

 * Due Date: 10/11/2020
 * I pledge that I have completed the programming assignment independently.
   I have not copied the code from a student or any source.
   I have not given my code to any student.
   Print your Name here: Thomas Tran

 * Pseudocode or Algorithm for the program:
	(be sure to indent items with control structure)
	(need to match flow chart submitted in documentation)
  1. Ask for a country.
  2. Display the converter toolkit menu.
  3. Ask for a choice from 1-4.
  4. Input of choice determines future outputs.
	4a. If input is outside of 1-4, display error.
	4b. If input is 1, ask for number in celsius.
		- Calculate fahrenheit with decimals
		- Display fahrenheit as a whole number, rounded
	4c. If input is 2, ask for number in kilometers.
		- If input is negative num, display error and skip to 5.
		- Calculate miles with deciamls
		- Display miles with decimals
	4d. If input is 3, ask for number in kilgrams.
		- If input is negative num, display error and skip to 5.
		-Calculate kilograms with decimals
		-Display kilograms with decimals
	4e. If input is 4, skip to step 5.
  5. Display the inputted country.
  6. Display program credits.
 (more as needed)
*/
#include <iostream>
#include <string>
using namespace std;

int Pr2() {
	int choice;
	int celsius;
	int fahrenheit;
	double kilometers;
	double miles;
	double kilograms;
	double pounds;
	string country;
	//Declare variables

	cout << "Enter a country name: ";
	getline(cin, country);
	cout << endl << endl;
	//Ask and get country name

	cout << "Converter Toolkit" << endl << "-----------------" << endl << "1. Temperature Converter" << endl << "2. Distance converter" << endl << "3. Weight Converter" << endl << "4. Quit" << endl << endl;

	cout << "Enter your choice (1-4): ";
	cin >> choice;
	//Start of menu
	if (choice == 1) {
		cout << "Please enter temperature in Celsius (such as 24): ";
		cin >> celsius;
		fahrenheit = (round((double)((9.0 / 5.0) * celsius))) + 32 ; //Calculate using decimals and then round to whole number
		cout << "It is " << fahrenheit << " in Fahrenheit.";
	} //Choice 1 is related to temperature
	else if (choice == 2) {
		cout << "Please enter distance in Kilometers (such as 18.54): ";
		cin >> kilometers;
		if (kilometers < 0) {
			cout << " !!! Program does not convert negative kilometers !!!";
		}else {
			miles = kilometers * (0.6);
			cout << "It is " << miles << " in Miles.";
		}
	} //Choice 2 is related to distance
	else if (choice == 3) {
		cout << "Please enter weight in Kilograms (such as 67.8): ";
		cin >> kilograms;
		if (kilograms < 0) {
			cout << " !!! Program does not convert negative kilograms !!!";
		}else {
			pounds = kilograms * (2.2);
			cout << "It is " << pounds << " in Pounds.";
		}
	} //Choice 3 is related to weight
	//Choice 4 doesn't need if-statement because it quits, so skip to end part of program
	else if ((choice > 4) || (choice < 1)) {
		cout << " !!! Program does not accept numbers outside the range of (1-4) !!!";
	} //If choice does fall between 1-4 then error

	cout << endl << endl << country << " sounds fun!" << endl;
	
	cout << endl << "Thank you for testing my program!!" << endl << "PROGRAMMER: Thomas Tran" << endl << "CMSC140 Common Project 2" << endl << "Due Date: 10/11/2020" << endl << endl;
	system("pause");
	return 0;
}