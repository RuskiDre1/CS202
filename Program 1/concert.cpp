#include "data.h"
//concert.cpp
// andrey toderyan
/* 06/23/21
	
	this is implementation for the concert  class and concert node


	protected:
		string venue;
		string preformer;

	
*/
concert::concert():venue(NULL), preformer(NULL) //default constructor
{}
concert::~concert() //destructor
{}
concert::concert(const concert & source):person(source) // CC
{
	venue = source.venue;
	preformer = source.preformer;
}
concert::concert(string & name, char * date): person(name, date)
{
	add();
}
bool concert::add()
{
	cout << "Venue:			?                       ";
	cin >> venue; cin.ignore(100,'\n');

	cout << "Preformer:            		       		 ";
	cin >> preformer; cin.ignore(100, '\n');

	return true;
}

bool concert::display()
{
	person::display();	
	cout << "Venue:			?                       " << venue << endl;
	cout << "Preformer:            		       		 " << preformer << endl;
	return true;
}
bool concert::compare( string & key)
{
	if(key == venue)
		return true;
	return false;
}



/*-------------------------------------------------------------------*/

node_concert::node_concert(): next(NULL)//default constructor
{}
node_concert::~node_concert() //destructor
{
	next = NULL;
}
node_concert::node_concert(string & name, char * date):concert(name, date)
{

}
node_concert::node_concert(const node_concert & source): concert(source)// CC
{}
void node_concert::set_next(node_concert * to_add)
{
	next = to_add;
}
node_concert * & node_concert::go_next()
{
	return next;
}
concert_list::concert_list()
{
	rear = NULL;
}
concert_list::~concert_list()
{
	remove_all();
	rear = NULL;
}
int concert_list::remove_all()
{
	if(!rear)
		return 0;

	remove_all(rear->go_next());

	rear = NULL;
	return 1;
}
int concert_list::remove_all(node_concert * & head)
{
	if(head == this->rear && rear != NULL)
	{
		head->~node_concert();
		head = NULL;
		return 1;
	}

	remove_all(head->go_next());
	head->~node_concert();
	head = NULL;
	return 1;
}
int concert_list::add (const node_concert & source)
{
	if(!rear)
	{
		//cout << "Adding new rear" << endl;
		rear = new node_concert(source);
		rear->set_next(rear);
	
		//cout << "We will check whether rear is pointed itself" << endl;

		if(rear == this->rear)
			cout << "YES it is" << endl;
		else 
			cout << "NO it isn't" << endl;
		
		return 1;
	}
	else
	{
		//cout << "Adding to rear" << endl;
		node_concert * temp = rear->go_next();
		rear->set_next(new node_concert(source));
		rear = rear->go_next();
		rear->set_next(temp);
		return 1;
	}
	return 0;
}
int concert_list::display_all()
{
	//cout << "Display all rear called " << endl;
	if(!rear) 
		return 0;

	display_all(rear->go_next());
	
	return 0;
}
int concert_list::display_all(node_concert * head)
{
	if(head == this->rear)
	{
		head->display();
		return 0;
	}
	
	display_all(head->go_next());
	head->display();

	return 1;
}
int concert_list::remove(string &)
{
	//call remove all recurive

	if (!rear)
		return 0;

	//remove(rear->go_next(), key);
	return 1;
}
int concert_list::remove(node_concert * & head, string & key)
{
	if(!head)
		return 0;

	remove(head->go_next() , key);	
	
	if(head->compare(key))
	{
		//remove

		return 1;
	}

	return 0;
}



















