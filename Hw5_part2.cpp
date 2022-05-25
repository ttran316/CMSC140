#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int Hw5_part2() {
	string name, phone, address, addLine1, addLine2;

	//Ask for data
	cout << "What is your name? ";
	getline(cin, name);
	cout << "What is your phone number? ";
	getline(cin, phone);
	cout << "What is your address? ";
	getline(cin, address);

	//Put data into file
	ofstream file;
	file.open("list.txt");
	file << "Name: " << name << "\nPhone Number: " << phone << "\nAddress: " << address;
	file.close();
	cout << endl;
	
	//Output to console, a full line from txt doc
	std::ifstream inf{"list.txt"};
	std::string outputCons;
	std::getline(inf, outputCons);
	std::cout << outputCons << endl;
	std::getline(inf, outputCons);
	std::cout << outputCons << endl;

	//Output to console, word by word, allows free movement of where to place words.
	for (int i = 0; i < 7;i++) {
		for (int x = 0; x < 7; x++) {
			inf >> outputCons;
			break;
		}
		if (i == 4) {
			cout << endl << "         ";
		}
		std::cout << outputCons;
		cout << " ";
	}
	
	cout << endl << endl;
	system("pause");
	return 0;
}