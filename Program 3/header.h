#include <iostream>
#include <cctype>
#include <cstring>
#include <string>

using namespace std;
// Olympic Tracker
// header.h
// Andrey Toderyan
/* 08/05/21
	
  This is the main header file for the hierchay which will include
  dynamic binding and Exception Handling in Olympic Tracker

*/
class athlete
{
	public:
		athlete();
		athlete(const athlete &);
		~athlete();
		
		virtual int display();//  
		virtual int input(); // 
		virtual int title(); // Display other sports they play (LLL)
			int compare( const athlete * check); // compares the name for 2-3 tree balance


	protected:
		int time;
		string name;
		//for the other sports an athlete my play
		class node_lll * head;
		
};

class dash: public athlete
{
	public:
		dash();
		dash(const dash &);
		~dash();

		// when just showing what multiple events the do
		// only title to be called;
		int title();	
		int display();//  
		int input(); // 

	protected:
		string time;
		
};
class relay: public athlete
{
	public:
		relay();
		~relay();
		relay(const relay & source);
		
		int title();	
		int display();//
		int input(); //

	protected:
		string time;
};
class long_m: public athlete
{
	public:
		long_m();
		long_m(const long_m & source);
		~long_m();
		
		int title();	
		int display();//  
		int input(); // 

	protected:
		string time;

};
bool again();
bool another();
int athlete_type();









