#include "data.h"
// civil.cpp
// Andrey Toderyan 
/* 07/20/21
	
  This is the implementation for class civil

	protected:
		int currency;
		int health;
		string name;
		int power; // soldiers
*/
civil::civil(): health(0), currency(0), power(0)
{
}
civil::civil(const civil & source)
{

}
civil::~civil()
{

}
int civil::display()
{
	cout << "Currency changes:  " << currency << endl
	     << "Health changes  :  " <<health << endl 
	     << "Military changes:  " <<power << endl << endl;
	return 1;
}
int civil::attack() //  attacking and return said damage
{
	cout << "Civil" << endl;
	return false;
}
int civil::trade() // trading and how much you profit/lost
{
	cout << "trade" << endl;	
	return false;
}
int civil::farm()
{
	cout << "Civil Farm called" << endl;
	return 1;
}
int civil::currency_func()
{
	currency = 5;
	return true;
}
int civil::charge_func(int x)
{
	currency = x;	
	return 1;
}
int civil::power_func(int x)
{
	power = x;	
	return 1;
}
int civil::health_func(int x)
{
	health = x;
	return 1;
}
















