#include <iostream>
#include <string>
using namespace std;

int Hw3() {
	double participationScore = 0;
	double testScore = 0;
	double assignmentScore = 0;
	double examScore = 0;
	double practiceScore = 0;
	double averageScore = 0;
	double finalScore = 0;
	const int MY_VAL = 77;
	//Declare my int variables, all five scores and average
	string name = "";
	//Declare string variables, name of student
	cout << "Enter the Student's name: ";
	getline (cin,name);
	cout << "Enter Class Participation Score ranging from 0 to 100: ";
	cin >> participationScore;
	cout << "Enter Test Score ranging from 0 to 100: ";
	cin >> testScore;
	cout << "Enter Assignment Score ranging from 0 to 100: ";
	cin >> assignmentScore;
	cout << "Enter Exam Score ranging from 0 to 100: ";
	cin >> examScore;
	cout << "Enter Practice Score ranging from 0 to 100: ";
	cin >> practiceScore;
	cout << name+":   Final Score: ";
	finalScore = testScore + participationScore + assignmentScore + examScore + practiceScore;
	cout << finalScore;
	cout << "   Average Score: ";
	averageScore = finalScore / 5;
	cout << averageScore << endl;
	system("pause");
	return 0;
}