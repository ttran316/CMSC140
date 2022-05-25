/*
 * Class: CMSC140 CRN
 * Instructor: Ahmed Tarek
 * Project<1>
 * Description: The Department plans to purchase a humanoid robot. 
				  The Chairman would like you to write a program to 
				  show a greeting script the robot can use later. 
 * Due Date: 9/27/2020
 * I pledge that I have completed the programming assignment independently.
   I have not copied the code from a student or any source.
   I have not given my code to any student.
   Print your Name here: Thomas Tran

 * Pseudocode or Algorithm for the program:
	(be sure to indent items with control structure)
	(need to match flow chart submitted in documentation)
  1. Display intro.
  2. Ask their name.
  3. Display greeting.
  4. Ask for a number, important pet or person.
  5. Display number
  6. Calculate by converting the number to months,days,hours,minutes,seconds,dog age, and gold fish age.
  7. Display years, months, days, hours, minutes, seconds, dog age, and fish age
  8. Ask for two more numbers
  9. Calculate the sum, divison, and division when the whole numbers are decimals
  10. Display work of calculations and answer.
  11. Display credits.
 (more as needed)
*/
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int pr1() {

	int age;
	int months = 0;
	int days = 0;
	int hours = 0;
	int minutes = 0;
	int seconds = 0;
	int dogAge = 0;
	int fishAge = 0;
	int wholeNumberOne = 0;
	int wholeNumberTwo = 0;
	int wholeNumberSum = 0;
	int wholeNumberDiv = 0;
	double decimalNumberDiv = 0;
	const int oneDogYear = 7;
	const int oneFishYear = 5;
	const int daysPerMonth = 30;
	const int assignmentNumber = 1;

	string visitorName = "";
	string robotName = "Juni";
	const string programmerName= "Thomas Tran";
	const string dueDate = "9/27/2020";
	stringstream stringStream;
	//Declare my variables

	cout << "**************** Robot Prototype Scripting ********************" << endl << "Hello, welcome to Montgomery College! My name is " + robotName + ". May I have your name?"<< endl;
	getline(cin,visitorName);
	//Get name and put into string name
	cout << "Nice to have you with us today, " + visitorName + "!" << endl << "Let me impress you with a small game." << endl << "Give me the age of an imporant person or a pet to you." << endl << "Please give me only a number:" << endl;
	cin >> age;
	const int humanAge = age;
	//Output name and get age and put into int age

	cout << endl << "You have entered ";
	cout << humanAge;
	//Output humanAge
	months = humanAge * 12;
	days = months * daysPerMonth;
	hours = days * 24;
	minutes = hours * 60;
	seconds = minutes * 60;
	dogAge = humanAge * 7;
	fishAge = humanAge * 5;
	//Calculating different ints after getting base number (humanAge)
	cout << "." << endl << " If this is for a person, the age can be expressed as:" << endl;
	stringStream << " " << humanAge << " years" << endl << " or " << months << " months" << endl <<" or about " << days << " days" << endl << " or about " << hours << " hours" << endl << " or about " << minutes << " minutes" << endl << " or about " << seconds << " seconds." << endl << " If this is for a dog, it is " << dogAge << " years old in human age." << endl << " If this is for a gold fish, it is " << fishAge << " years old in human age." << endl;
	cout << stringStream.str();
	stringStream.str("");
	//stringStream allows combination of int and string. Clear after for future use.
	
	cout << endl << "Let's play another game, " + visitorName << ". Give me a whole number." << endl;
	cin >> wholeNumberOne;
	cout << "Very well. Give me another whole number." << endl;
	cin >> wholeNumberTwo;
	wholeNumberSum = wholeNumberOne + wholeNumberTwo;
	wholeNumberDiv = wholeNumberOne / wholeNumberTwo;
	decimalNumberDiv = (double)wholeNumberOne / (double)wholeNumberTwo;
	//Calculate and get numbers. (double) changes the whole number from 4 to 4.0
	stringStream << "Using the operator '+' in C++, the result of " << wholeNumberOne << " + " << wholeNumberTwo << " is " << wholeNumberSum << "." << endl;
	cout << stringStream.str();
	stringStream.str("");
	stringStream << "Using the operator '/', the result of " << wholeNumberOne << " / " << wholeNumberTwo << " is " << wholeNumberDiv << "." << endl;
	cout << stringStream.str();
	stringStream.str("");
	stringStream << "however, the result of " << (double)wholeNumberOne << " / " << (double)wholeNumberTwo << " is about " << decimalNumberDiv << "." << endl;
	
	cout << stringStream.str() << endl << "Thank you for testing my program!!" << endl << "PROGRAMMER: Thomas Tran" << endl << "CMSC140 Common Project 1" << endl << "Due Date: 9/27/2020" << endl;
	system("pause");
	return 0;
}