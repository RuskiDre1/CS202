#include <iostream>
#include <cctype>
#include <cstring>
#include <string>
#include <vector>


using namespace std;
//header.h
// Andrey Toderyan
/* 06/23/21
	
  This is the main header file for the hierchay for Program 1.
  This file will hold prototypes of base class 
                                    Lake class    ( for visiting lake)
                                    Concert class ( for visiting concerts)
                                    Hike class    ( for hiking outdoors)

  Along with additional prototypes for functions used
	bool again() - repeated do loop in main 
*/

class base
{
	public:
		base(); // default constructor
		~base();      // destructor 
		base( const base & ); // copy constructor
		
		base(char * date);

		bool input();
		bool remove();
		bool display();	

	protected:
		char * title;
		char * date;
		char * time;
};

class person: public base
{
	public:
		person();
		~person();

		person( const person & );
		person(string & name, char * date);

		bool input(string &);
		bool display();
		bool remove();

	protected:
		string name;

};

class lake: public person 
{
	public:
		lake(); //default contructor
		~lake();//destructor
		lake(const lake & source); // CC

		lake(string & name, char * date);
		
		int compare(string & key);
		bool add();
		bool display();
	
	protected:
		string kind;
		string lifeguard;
		string depth;
};

class concert: public person
{
	public:
		concert(); //default constructor
		~concert(); //destructor
		concert(const concert & ); // CC

		concert(string & name, char * date);
		
		bool add();
		bool display();
		bool compare( string & key);
		

	protected:
		string venue;
		string preformer;

};

class hike: public person
{
	public:
		hike(); // default constructor
		~hike(); // destructor
		hike(const hike & ); // CC

		hike(string & name, char * date);
		
		int compare(string & trail_name);

		bool add();
		bool display();

	protected:
		string trail;
		int altitude;
		int lenght;
			
};

// Additional Prototypes for main.cpp
bool again();
char select_event();

