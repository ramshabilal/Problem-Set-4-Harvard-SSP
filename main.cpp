/*Ramsha Bilal
bilal_week4_ps
Problem set 4
main.cpp file
PC
*/

#include "class.h"
#include "main.h"
#include <iostream>
#include <iomanip>

using namespace std; 

int main()
{
	cout << "Running problem 1" << endl;
	problem1();  //problem 1
	cin.ignore();

	cout << "Running problem 2" << endl; 
	problem2(); //problem 2
	cin.ignore();

	cout << "Running extra credit substring" << endl;
	extraCreditSubstring();
	cin.ignore();

	cout << "Running problem 3" << endl;
	problem3(); //problem 3
	cin.ignore();

	cout << endl << "Running extra credit problem" << endl;
	extraCredit();
	return 0;   
}