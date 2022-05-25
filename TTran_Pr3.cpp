/*
 * Class: CMSC140 CRN
 * Instructor: Ahmed Tarek
 * Project<3>
 * Description: You are required to write a program that calculates the 
				 occupancy rate and the total hotel income for one night 
				 and displays this information as well as some other information 
				 described below. 

 * Due Date: 11/1/2020
 * I pledge that I have completed the programming assignment independently.
   I have not copied the code from a student or any source.
   I have not given my code to any student.
   Print your Name here: Thomas Tran

 * Pseudocode or Algorithm for the program:
	(be sure to indent items with control structure)
	(need to match flow chart submitted in documentation)
  1. Display start of program, BlueMont
  2. Ask for location
  3. Ask for floors
		3a. If floors is more than 5 or less than 1 ask again
  4. Ask for total amount of rooms on that floor
  5. Ask for occupied rooms for single, double, king, and suite rooms
  6. Repeat 4 and 5 until all floors that the user inputed is done
  7. Calculate total single, double, king, and suite rooms
  8. Display room rates for single, double, king, and suite
  9. Calculate and display hotel income, total rooms, total occupied, total unoccupied, and occupancy rate
  10. Display the floor with the lowest amount of rooms
  11. If occupancy rate is below 60% state and display it
  12. Display credit
 (more as needed)
*/
#include <iomanip>
#include <iostream>
using namespace std;

int Pr3(){
	//Declaring my variables
	string location;
	float occupancyRate;
	int floors, leastFloor = 1, leastRooms = 31, floorRooms, roomsTotal = 0, prevRoomTotal = 31, roomsSingle = 0, roomsDouble = 0, roomsKing = 0, roomsSuite = 0, singles, doubles, kings, suites, occupiedRooms = 0;
	const int singleRate = 60, doubleRate = 75, kingRate = 100, suiteRate = 150;
	const int floorsMax = 5, floorsMin = 1, roomsMax = 30, roomsMin = 1;

	//First part - Asking for # of floors and location, only if within 1 to 5
	cout << "======================================================" << endl << "                    BlueMont Hotel" << endl << "======================================================";
	cout << endl << "Enter the location of this hotel chain: ";
	cin >> location;
	do{
		cout << "Enter the total number of floors of the hotel: ";
		cin >> floors;
		if (floors < floorsMin || floors > floorsMax) {
			cout << "Number of floors should be between 1 and 5 !! Please try again." << endl << endl;
		}
	} while (floors < floorsMin || floors > floorsMax);
	
	//2nd part - Asking for room totals for each floor and specifications
	cout << endl << endl;
	for (int i = 1; i <= floors; i++) {
		do{
			do {
				cout << "Enter the total number of rooms on floor " << i << ": ";
				cin >> floorRooms;
				if (floorRooms < roomsMin || floorRooms > roomsMax) {
					cout << "Number of rooms should be between 1 and 30 !! Please try again." << endl << endl;
				}
			} while (floorRooms < roomsMin || floorRooms > roomsMax);
			cout << "How many SINGLE rooms are occupied in the " << i << "th floor? ";
			cin >> singles;
			cout << "How many DOUBLE rooms are occupied in the " << i << "th floor? ";
			cin >> doubles;
			cout << "How many KING rooms are occupied in the " << i << "th floor? ";
			cin >> kings;
			cout << "How many SUITE rooms are occupied in the " << i << "th floor? ";
			cin >> suites;
			if (floorRooms < singles + doubles + kings + suites) {
				cout << "Total number of occupied rooms exceeds the total number of rooms on this floor. Please try again!!" << endl << endl;
			}
			else {
				//Used to find rates of each room
				roomsSingle += singles;
				roomsDouble += doubles;
				roomsKing += kings;
				roomsSuite += suites;
				occupiedRooms += singles + doubles + kings + suites;
				roomsTotal += floorRooms;
				//Way to find least amount of rooms and which floor
				if (prevRoomTotal > floorRooms && leastRooms > floorRooms) {
					leastFloor = i;
					leastRooms = floorRooms;
				}
				prevRoomTotal = floorRooms;
				cout << endl << endl;
			}
		} while (floorRooms < singles + doubles + kings + suites);
	}

	//last part - caluclations for rates, incomes, totals. Then says which had least rooms and if needs to improve rate.
	occupancyRate = ((float)occupiedRooms / (float)roomsTotal) * 100;
	cout << "===================================================================================" << endl << "                      BlueMont Hotel located in " << location << endl << endl << "                        TODAYS'S ROOM RATES(US$/Night)" << endl << endl << "        Single Room        Double Room        King Room        Suite Room" << endl << endl << "                 60                 75              100               150" << endl << "===================================================================================" << endl;
	//Set percision and fixed is to make only two units show after decimal
	cout << "               Hotel Income:     $" << ((roomsSingle * singleRate) + (roomsDouble * doubleRate) + (roomsKing * kingRate) + (roomsSuite * suiteRate)) << ".00" << endl << "           Total # of rooms:     " << roomsTotal << endl << "     Total # Occupied Rooms:     " << occupiedRooms << endl << "   Total # Unoccupied Rooms:     " << roomsTotal-occupiedRooms << endl << "              Occupancy rate     " << setprecision (2) << fixed << occupancyRate << "%" << endl << endl;
	cout << leastFloor << "th floor with " << leastRooms << " rooms, has the least number of rooms." << endl;
	if (occupancyRate < 60.00) {
		cout << "Need to improve hotel occupancy rate!!"<< endl;
	}
	cout << endl << "Thank you for testing my program!!" << endl << "PROGRAMMER: Thomas Tran" << endl << "CMSC140 Common Project 3" << endl << "Due Date: 11/1/2020" << endl << endl;
	system("pause");
	return 0;
}