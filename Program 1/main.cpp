#include "data.h"
#include <vector>
// main.cpp
// Andrey Toderyan
/* 06/23/21
	
  This is the main cpp  file for the hierchay for Program 1.
  This file will hold the base class , Lake class    ( for visiting lake)
                                       Concert class ( for visiting concerts)
                                       Hike class    ( for hiking outdoors)
*/

int main()
{
	
	
	lake_list list_lake; // Array of LLL for lake events
	concert_list list_concert; // CLL for concert events
	hike_list list_hike; // Vector for Hike events

	//vector <node_hike*> hikeVector; // Vector for Hike events

	do
	{
		system("clear");
	
		cout << "Welcome to Event Scheduler" << endl
		     << "1 : Plan Event " << endl
		     << "2 : Show All Events " << endl
		     << "3 : Remove Event " << endl
		     << "4 : Remove All " << endl;
		int  opt; cin >> opt; cin.ignore(100,'\n');
	
		switch(opt)
		{
			case 1:
			{
			
				cout << "What kind of event do you want to plan?" << endl;					   
				int  kind = select_event();

				string name;
				char date[25];
				
				cout << "Your Name:        	                        ";
				cin >> name;  cin.ignore(100, '\n');
				cout << "Date     :		                        ";
				cin >> date; cin.ignore(100, '\n');
				
				if(kind == 1)
				{
					// Node and all heirachy classes are filled with info
					node_lake one(name, date);
					// added to the data structure	
					list_lake.add(one); 
				}
				else if(kind == 2)
				{
					node_concert one(name, date);	
					list_concert.add(one);
				}
				else if(kind == 3)
				{
					list_hike.add(name, date);
				}
				else
					cout << "Not an option " << endl;
			}
				break;
			case 2:
			{
				cout << "Displaying all events " << endl;
				list_lake.display_all();	cout << endl;
				list_concert.display_all();	cout << endl;
				list_hike.display_all();	cout << endl;
			}
				break;
			case 3:
			{
				cout << "What event  do you want to remove from" << endl;					   
				int kind = select_event();
				
				if(kind == 1)
				{
					string name;

					cout << "Enter Lake Name: ";
					cin >> name; cin.ignore(100, '\n');

					list_lake.remove(name);
				}
				else if(kind == 2)
				{
					string name;

					cout << "Enter venue Name: ";
					cin >> name; cin.ignore(100, '\n');
					list_concert.remove(name);

				
				}
				else if(kind == 3)
				{
					string name;

					cout << "Enter trail Name: ";
					cin >> name; cin.ignore(100, '\n');
					list_hike.remove(name);
				}
				else
					cout << "Not an option " << endl;
			}
				break;
			case 4:
			{
				cout << "Removing all planned events " << endl;
				list_lake.~lake_list();
				list_concert.remove_all();
				list_hike.remove_all();
			}
				break;
			default:
				cout << "Not an option";
				break;
		}	
		
	}while(again());
	
	
}
char select_event()
{
	cout << "1 : Lake " << endl
	     << "2 : Concert " << endl
	     << "3 : Hike " << endl;
				
	int  x; cin >> x; cin.ignore(100,'\n');

	return x;
}
bool again()
{
	cout << "Another Function (Y/N) " << endl;

	char ans; cin >> ans; cin.ignore(100, '\n');
	
	if(toupper(ans) == 'Y')
		return true;
	return false;
}	

