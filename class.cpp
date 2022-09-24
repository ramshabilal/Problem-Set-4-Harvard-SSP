/*Ramsha Bilal
bilal_week4_ps
Problem set 4
class.cpp file
PC
*/

#include <iostream>
#include "class.h"

using namespace std; 

/*adds the cents and dollars passed to the existing money. if new total cents exceed 99, 
 converts the excess to dollars and saves in dollars*/
void Money::addMoney(int cents, int dollars)
{
	m_dollars += dollars;
	m_cents += cents;

	if (m_cents >= MAX_CENTS)
	{
		int noOfDollars;
		noOfDollars = (m_cents/100);     //to check how many dollars to be added:
		m_cents -= (noOfDollars * MAX_CENTS);     //for example, in case that number of cents is greater than 200,
		m_dollars += noOfDollars;                // 2 dollars should be added.

		cout << "no of dollars " << noOfDollars << endl;  //DEBUG VERSION
	}
	cout << "dollars: " << m_dollars << endl;   //DEBUG VERSION
	cout << "cents: " << m_cents << endl;       //DEBUG VERSION
}

/*shows the total money in a money object. 
converts cents to dollars if cents exceeds 99*/
void Money::showMoney()
{
	double centToDollars, totalDollars; 
	centToDollars = (static_cast<double>(m_cents) / MAX_CENTS); 
	cout << "centToDollars are: " << centToDollars << endl; //debug version
	totalDollars = static_cast<double>(m_dollars) + centToDollars;
	cout << "Total money: $" << totalDollars << endl;
}
