/*
 * Class: CMSC140 CRN
 * Instructor: Ahmed Tarek
 * Project<4>
 * Description: Write a program that calculates the average number of days a 
				 company's employees are absent during the year and outputs a 
				 report on a file named "employeeAbsences.txt".  

 * Due Date: 11/15/2020
 * I pledge that I have completed the programming assignment independently.
   I have not copied the code from a student or any source.
   I have not given my code to any student.
   Print your Name here: Thomas Tran

 * Pseudocode or Algorithm for the program:
	(be sure to indent items with control structure)
	(need to match flow chart submitted in documentation)
  1. Create, open, and write starting words for file
  2. Call the function numOfEmployees
	2a. Ask for amount of employees
		a. If employees is not more than 0 then display error and keep asking
	2b. return employees
  3. Call the function totDaysAbsent with input of employees
	3a. Ask for userID and absentdays
		a. If absentdays is negative display error and keep asking
	3b. Write the userID and absences in file
	3c. Calculate total absences and return it
  4. Call function averageAbsent with two inputs of employees and total absences
	4a. Calculate average absences and return it
  5. Write in file the average and total absences
  6. Display program credits
 (more as needed)
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

double averageAbsences;
int employees, totalAbsences;
ofstream employeeAbsences;
stringstream writer;

int numOfEmployees() {
	
	//Find amount of employees and ask again if no within wanted nums
	cout << "Calculate the average number of days a company's employees are absent." << endl << endl << "Please enter the number of employees in the company: ";
	cin >> employees;
	while (employees < 1) {
		cout << "Number of employees needs to be more than 0." << endl << "Please re-enter the number of employees: ";
		cin >> employees;
	}
	return employees;
}

int totDaysAbsent(int employees) {
	for (int i = 0; i < employees; i++) {

		//Declare local variables
		int userID, absentDays, counter;
		string converter;

		//Repeats for amount of employees, ask for ID and absences.
		cout << "Please enter an employee ID: ";
		cin >> userID;
		cout << "Please enter the number of days this employee was absent: ";
		cin >> absentDays;
		while (absentDays < 0) {
			cout << "The number of days must not be negative." << endl << "Please re-enter the number of days absent: ";
			cin >> absentDays;
		}

		//If statements and converter/counter used to format in note.txt
		//Makes a stringstream to input into note.txt then clears for next line
		converter = to_string(userID);
		counter = converter.size();
		if (counter == 4) {
			writer << "   " << userID << "           " << absentDays << endl;
		}
		else if (counter == 3) {
			writer << "   " << userID << "            " << absentDays << endl;
		}
		else if (counter == 2) {
			writer << "   " << userID << "             " << absentDays << endl;
		}
		else{
			writer << "   " << userID << "              " << absentDays << endl;
		}
		employeeAbsences << writer.str();
		writer.str("");
		totalAbsences += absentDays;
	}
	return totalAbsences;
}

double averageAbsent(int employees, int totalAbsences){
	averageAbsences = (double)totalAbsences / (double)employees;
	return averageAbsences;
}

int Pr4() {
	//Open file and write the start inside it
	employeeAbsences.open("employeeAbsences.txt");
	employeeAbsences << "EMPLOYEE ABSENCE REPORT" << endl << "Employee ID    Days Absent" << endl;

	employees = numOfEmployees();
	totalAbsences = totDaysAbsent(employees);
	averageAbsences = averageAbsent(employees, totalAbsences);

	employeeAbsences << endl << "The " << employees << " employees were absent a total of " << totalAbsences << " days." << endl << "The average number of days absent is " << setprecision(1) << fixed << averageAbsences << " days.";
	employeeAbsences << endl << endl << "Programmer: Thomas Tran";
	employeeAbsences.close();

	cout << endl << "Thank you for testing my program!!" << endl << "PROGRAMMER: Thomas Tran" << endl << "CMSC140 Common Project 4" << endl << "Due Date: 11/15/2020" << endl << endl;
	system("pause");
	return 0;
}