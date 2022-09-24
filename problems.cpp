/*Ramsha Bilal
Problem Set 4
bilal_week4_ps
problems.cpp
PC.*/ 

#include "main.h"
#include "class.h"
#include<iostream>
#include <string>
using namespace std; 

bool debug;
string* allocName(string FName, string LName); 

/*creates a money object, saves an initial value in it. then calls 
method Addmoney to add more money and showMoney to display it.*/
void problem1()
{
	Money object1 = { 65, 2 };
	object1.addMoney(120, 0);
	object1.showMoney();
}

/*calls subString and passes parameters (2 or 3) to the function getting 
pointer in return.*/
void problem2()
{
	int answer;

	//debug version:
	cout << "Would you like the debug version? (Press 1 for yes and 0 for no.)\n";
	cin >> answer;
	if (answer == 1)
		debug = true;
	else
		debug = false; //debug ends here. 

	//assigning string to array and defining variables:
        const int ARRAY_SIZE = 100;
	char word[ARRAY_SIZE] = "Hello There";
	int length = strlen(word);
	char *returnPointer;
	const int INDEX = 3; 
	const int HOW_MANY = 99;
	//adding termination character at the end:
	word[length] = '\0';                    

	returnPointer = subString(word, INDEX, HOW_MANY);
	//debug version:
	/*  if (debug == true)
	{
		cout << endl << "Testing returned pointer:  ";
		for (int i = 0; i < HOW_MANY; i++)
		{
			cout << *returnPointer;
			returnPointer++;
		}
	}
		cout << endl;
       //debug ends here.*/
}

/*calls the second substring function. gets pointer to the 
substring in return/*/
void extraCreditSubstring()
{
	char word[100] = "Hello There";
	const int INDEX = 3, HOW_MANY = 99;
	char *secondPointer;
		secondPointer = subStringTwo(word, INDEX, HOW_MANY);
}

/*takes array location as parameter along with the index from where substring starts and number of 
characters to be taken. it then uses array to only keep the required substring and return pointer 
to its first character.*/
char* subString(char* px, int index, int howMany)
{
	static char* pointer;
	char substring[100];
	int i = 0, count = index;
	px += index;
	
	do
	{
		substring[i] = *px;

		//DEBUG VERSION
		if (debug == true)
		{
			cout << "*px is: " << *px << "   ";       
			cout << "substring[i] is: " << substring[i] << endl;    
		} //DEBUG ENDS HERE.      //THIS IS COMMENDED OUT TO ENSURE THE POINTER, 
		                         //WHEN RETURNED, IS AT BEGINNING OF ARRAY

		//Incrementing counters and pointer:
		i++;
		px++;
		count++;

	} while ((count < (index + howMany)) && (*px != '\0'));

	//adding termination character at end:
	substring[i] = '\0';

	//assigning address of substring to pointer to be returned:
	pointer = &substring[0];
	
	return pointer;
}
/*asks user for how many numbers they want displayed. Calls makeFibSeries and passes the number 
  as a parameter. Finally, deletes the allocated memory.*/
void problem3()
{
	int noOfNumbers; 
	cout << "How many numbers in the Fibonacci series do you want displayed?\n";
	cin >> noOfNumbers;
	int* pointerArray, *startPoint;
		pointerArray = makeFibSeries(noOfNumbers); 
		startPoint = pointerArray;

		cout << endl; 
		while (*pointerArray != 11)
		{
			cout <<  *pointerArray++ << "  ";
		}

		//delete dynamically allocated memory
		delete startPoint; 
}


/*takes number of numbers to be displayed as argument and saves those numbers on 
consecutive locations, returning the pointer to the first location.*/
int* makeFibSeries(int howManyNumbers)
{
	//debug version:
	int ans;
	bool debugIt;
	cout << "Would you like the debug version? (Press 1 for yes and 0 for no.)\n";
	cin >> ans;
	if (ans == 1)
		debugIt = true;
	else
		debugIt = false; //debug ends 

	int *dynArray, *startArray;

	dynArray = new int[howManyNumbers];
	startArray = dynArray;
	dynArray[0] = 0;
	dynArray[1] = 1;
	if (!dynArray) 
		exit(-1);

	for (int i = 2; i < howManyNumbers; i++)
	{
		dynArray[i] = dynArray[i - 1] + dynArray[i - 2];
	}
	dynArray[howManyNumbers] = 11;

	//debug version:
	if (debugIt == true)
	{
		cout << "Testing that the array has the Fibonacci series saved correctly.\n";
		for (int i = 0; i < howManyNumbers; i++)
		{
			cout << *dynArray << "  ";
			dynArray++;
		}
		cout << endl;   //debug ends.
	}
	return startArray;
}

/*substring for extra credits
takes array, index, and number of characters to be displayed as arguments. 
then creates a dynamic array, copies those values in the array and returns pointer to that array*/
char* subStringTwo(char* px, int index, int howMany)
{
	static char* pointer;
	char* dynArray, *startArray;
	dynArray = new char[howMany];
	int count = index;
	px += index;
	do
	{
		*dynArray = *px;

		//DEBUG VERSION
		if (debug == true)
		{
			cout << "*px is: " << *px << "   ";
			cout << "*dynArray is: " << *dynArray << endl;
		} //DEBUG ENDS HERE.

		//Incrementing counters and pointer:
		px++;
		dynArray++;
		count++;

	} while ((count < (index + howMany)) && (*px != '\0'));

	//adding termination character at end:
	*dynArray = '\0';


	/*//debug version:
	if (debug == true)
		cout << endl << "testing new pointer:  ";
	{
		int z = 0;
		while (*pointer != '\0')   //testing the pointer;
		{
			cout << *pointer;
			z++;
			pointer++;
		}
		cout << endl;
	} //debug ends here. */

	return dynArray;
}

/*extra credit assignment
takes first and last name as parameter and concatenates them with a space in between. 
returns pointer to the dynamic memory location where the name is saved.*/
string* allocName(string FName, string LName)
{
	string* fullName; 
	fullName = new string; 
	if (!fullName)
		cout << "Error\n";

	*fullName = (FName + " " + LName);

	return fullName;
}

/*calls allocName passing strings as parameters. 
gets pointer to the name and displays it. then deletes the dynamic memory allocated to the name.*/
void extraCredit()
{
	string* pointer;
	pointer = allocName("Ramsha", "Bilal");
	cout << "Full Name: " << *pointer;
	delete pointer; 
}