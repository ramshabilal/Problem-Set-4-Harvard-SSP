/*Ramsha Bilal
bilal_week4_ps
Problem set 4
class.h file
PC
*/

#ifndef CLASS_H 
#define CLASS_H

/*steps:
class called money with dollars and cents members
methods: addMoney() - creating as a method within class Money with two parameters
showMoney()
*/

const int MAX_CENTS = 100, DEFAULT_DOLLARS = 0;

class Money
{
public: 
	int m_cents, m_dollars;
	void addMoney(int cents, int dollars = DEFAULT_DOLLARS);
	void showMoney();
};




#endif
