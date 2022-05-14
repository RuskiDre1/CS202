#include "header.h"
//base.cpp
// andrey toderyan
/* 06/23/21
	
	this is implementation for the base class

	protected:
		char * title;
		char * date;
		char * time;

*/
base::base(): title(NULL) , date(NULL) , time(NULL) // default constructor
{}
base::base(char * date_): date(date_)
{
	input();
}
base::~base()     // destructor 
{
	delete [] title;
	delete [] date;
	delete [] time;

	title = NULL;
	date = NULL;
	time = NULL;
}
base::base( const base & source) // copy constructor
{
	title = new char[strlen(source.title) + 1];
	strcpy(title, source.title);
	time = new char[strlen(source.time) + 1];
	strcpy(time, source.time);
	date = new char[strlen(source.date) + 1];
	strcpy(date, source.date);
}
bool base::input()
{
	char t[100];
	char d[100];
	char temp_time[100];

	cout << "Trip Title:        	                        ";
	cin >> t; cin.ignore(100, '\n');

	cout << "Trip Date: 					";
	cin >> d; cin.ignore(100, '\n');

	cout << "Trip Time: 					";
	cin >> temp_time; cin.ignore(100, '\n');

	title = new char[strlen(t) + 1];
	strcpy(title, t);
	time = new char[strlen(d) + 1];
	strcpy(time, d);
	date = new char[strlen(temp_time) + 1];
	strcpy(date, temp_time);

	return false;
}
bool base::remove()
{
	return false;
}
bool base::display()
{
	cout << "Event Title: 					" << title << endl
	     << "Date:        					" << date  << endl
	     << "time:        					" << time  << endl;
	return true;
}

