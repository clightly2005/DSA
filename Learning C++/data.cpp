#include <iostream>
#include <iomanip>
#include <ios>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::string;
using std::streamsize;

string studentGrades() {
	cout << "Please enter your first name";
	string name;
	cin >> name;
	cout << "Hello, " << name << "!" << endl;

	cout << "Please enter your mock and real grade: ";
	double mock, real;
	cin >> mock >> real;

	cout << "Enter your homework grades: ";
	int count = 0;//how many grades i have seen
	double sum = 0; //running total of grades
	double homework;
	while (cin >> homework) {
		++count;
		sum += homework;
	}


}