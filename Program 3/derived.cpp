#include "data.h"
// Olympic Tracker
// derived.cpp
// Andrey Toderyan
/* 08/05/21
	
  This is the derived .cpp file for the Olympic Tracker
	while includes implementations for  base class atheltethe dervied classes from athlete

*/
athlete::athlete()
{
	name = "boob";
	time = 0;
}
athlete::athlete(const athlete & source)
{
	name = source.name;
	time = source.time;
}
athlete::~athlete()
{
}
int athlete::display()
{
	cout << " Athlete display called" << endl;
	return 1;
}
int athlete::input()
{
	cout << "Enter your name " << endl;
	cin >> name;

	return 1;
}
int athlete::title()
{
	return 1;
}
int athlete::compare( const athlete * check)
{
	if(check->name > name)
		return 1;
	if(check->name < name)
		return -1;
	else
		return 0;
}
/*---------------------------------*/
dash::dash()
{
	cout << "Dash con activated" << endl;
}
dash::dash(const dash & source): athlete(source)
{

}
dash::~dash()
{
	cout << "Dash destructor called" << endl;
}
int dash::display()
{
	cout << " Dash display called" << endl;
	return 1;
}
int dash::input()
{
	athlete::input();	
	return 1;
}
int dash::title()
{
	return 1;
}
/*---------------------------------*/
relay::relay ()
{

}
relay::relay(const relay & source): athlete(source)
{

}
relay::~relay()
{
}
int relay::display()
{
	cout << " Relay  display called" << endl;
	return 1;
}
int relay::input()
{
	athlete::input();	
	return 1;
}
int relay::title()
{
	return 1;
}
/*---------------------------------*/
long_m::long_m()
{

}
long_m::long_m(const long_m & source):athlete(source)
{
}
long_m::~long_m()
{
}
int long_m::display()
{
	cout << " Long m display called" << endl;
	return 1;
}
int long_m::input()
{
	athlete::input();	
	return 1;
}
int long_m::title()
{
	return 1;
}





