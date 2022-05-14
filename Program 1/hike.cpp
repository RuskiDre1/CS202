#include "data.h"
//hike.cpp
// andrey toderyan
/* 06/23/21
	
	this is implementation for the hike class and hike node


	protected:
		string trail;
		int altitude;
		int lenght;
*/
hike::hike(): trail(NULL) , altitude(0) , lenght(0)  // default constructor
{}
hike::~hike() // destructor
{}
hike::hike(const hike & source): person(source) // CC
{
	trail = source.trail;
	altitude = source.altitude;
	lenght = source.altitude;
}
hike::hike(string & name, char * date): person(name,date)
{
	add();
}
int hike::compare(string & trail_name)
{
	if( trail.compare(trail_name) == 0)
		return 1;
	

	cout << "No match found" << endl;
	return 0;
}
bool hike::add()
{
	
	cout << "Hike Trail:					";
	cin >> trail; cin.ignore(100, '\n');
	cout << "Hike Altitude (feet):				";
	cin >> altitude; cin.ignore(100, '\n');
	cout << "Hike Lenght (miles):				";
	cin >> lenght; cin.ignore(100, '\n');

	return true;
}
bool hike::display()
{
	person::display();
	cout << "Hike Trail:					" << trail << endl;
	cout << "Hike Altitude (feet):				" << altitude << endl;
	cout << "Hike Lenght (miles):				" << lenght << endl;
	
	return true;
}

/*--------------------------------------------------------------------*/
// VECTOR
node_hike::node_hike() // default constructor
{
}
node_hike::~node_hike() // destructor
{

}
node_hike::node_hike(const node_hike & source): hike ( source)
{}

node_hike::node_hike( string & name, char * date): hike ( name, date)
{}

/*----------------*/


hike_list::hike_list()
{

}
hike_list::~hike_list()
{

}
int hike_list::add( string & name, char * date)
{
	node_hike * ptr = new node_hike(name, date);
	hikeVector.push_back(ptr);

	return 1;
}
int hike_list::display_all()
{
	for ( node_hike* & item: hikeVector)
	{
		cout << item->display() << endl;
	}
	/*
	for ( int i = 0; i < hikeVector.size(); ++i)
	{
		cout << hikeVector[i]->display()  << endl;
	}
	*/

	return 1;
}
int hike_list::remove(string & trail_name)
{
		
	
	for ( int i = 0; i < hikeVector.size(); ++i)
	{
		if(hikeVector[i]->compare(trail_name) == 1)
		{
			//hikeVector[i].erase();	
			return 1;
		}
	}

	remove_all();	
	return 0;
}
int hike_list::remove_all()
{
	hikeVector.clear();
	return 0;
}











