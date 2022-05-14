#include "data.h"
// Olympic Tracker
//main.cpp
// Andrey Toderyan
/* 08/05/21
	
  This is the main .cpp file for the Olympic Tracker

*/
int main()
{
	do{

	bst tree; // balanced tree;

	tree.menu(); // adding athletes to tree


	}while(again());

}
bool again()
{
        cout << endl << "Create and run a New Olympic tracker?  (Y/N)" << endl;
        char ans; cin >> ans; cin.ignore(100,'\n');

        if(toupper(ans) == 'Y')
                return true;
        return false;
}


