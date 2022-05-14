

#include "data.h"
// main.cpp
// Andrey Toderyan 
/* 07/20/21
	
  This is the main cpp  file for the hierchay which will include
  dynamic binding for the Colonial Game

*/
int main()
{
	do
	{
	system("clear");

	cout << "Welcome Player " << endl << endl 
	     << "Setting  :   1700s " << endl
	     << "Objective:   Control countries" << endl << endl
	     << "      Y = yes | N = NO          " << endl;


	//DLL Created	
	list game;	
	
	cout << "World is in motion!" << endl
	     << "With every step the 3 nations will " << endl
	     << "experience the passage of time with properity " << endl
	     << "You Hold the keys to the future! " << endl << endl;
	
	game.play(); // plays time for all the civils
		
	do{
		
		game.menu(); // calls constuctor and dynamic memory 
		
		//check whether 2 countries have lost yet
		//if(game.check() == 0)

		//transfer over to final tally


	}while( game.check() == 1 && another() );

	cout << "Since war is over you can review what each country did on our " 
	     << "timeline and removed all or specific events or display" << endl;
	
	game.review();	

	}while(again());

}
bool another()
{
	cout << endl << "Another action in this World?" << endl;
        char ans; cin >> ans; cin.ignore(100,'\n');

        if(toupper(ans) == 'Y')
                return true;
        return false;
}
bool again()
{
	cout << endl << "Create and run a New world (Y/N)" << endl;
        char ans; cin >> ans; cin.ignore(100,'\n');

        if(toupper(ans) == 'Y')
                return true;
        return false;
}


















