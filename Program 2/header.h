#include <iostream>
#include <cctype>
#include <cstring>
#include <string>

using namespace std;
// Colonial Game
// header.h
// Andrey Toderyan
/* 07/20/21
	
  This is the main header file for the hierchay which will include
  dynamic binding for the Colonial Game

*/
class civil
{
	public:
		civil();
		
		civil(const civil & source);
		virtual~civil();
			
		virtual int  attack(); //  attacking and return said damage
		virtual int  trade(); // trading and how much you profit/lost
		virtual int  farm(); // farming soldiers and money
		virtual int display();

		int currency_func();
		int charge_func(int x);
		int power_func(int x);
		int health_func(int x);
		
	protected:
		string moto;
		int currency;
		int health;
		string name;
		int power; // soldiers
};
class usa: public civil
{
	public:
		usa();
		//usa(const usa & );
		~usa();
		
		int  attack(); 
		int trade();
		int farm();
		int display();
		//dynamic cast func
		int song();

	protected:
		int colonies;
		int timber;
};

class brit: public civil
{
	public:
		brit();
		brit(const brit & souce);	
		~brit();
		
		//dynamic cast func
		int song();

		int  attack(); 
		int display();
		int trade();
		int farm();
	protected:
		int tea;
};
class french: public civil
{
	public:
		french();
		french(const french & source);
		~french();

		int trade();	
		int farm();
		int display();
		int  attack(); 
		bool activate();


	protected:
		int clothe;
};
bool again();
bool another();










