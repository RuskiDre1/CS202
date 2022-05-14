#include "data.h"
//lake.cpp
// andrey toderyan
/* 06/23/21
	
	this is implementation for the lake class and lake node


	protected:
		string kind;
		string lifeguard;
		int depth;
*/

person::person(): name(NULL)
{}
person::~person()
{}
person::person(const person & source): base(source)
{
	name = source.name;
}
person::person(string & name_, char * date): base(date), name(name_)
{} 
bool person::input(string &)
{
	return true;
}
bool person::display()
{
	cout << "Name:						" << name << endl;
	base::display();
	return true;
}
bool person::remove()
{
	return false;
}
/*--------------------------------------------------------------------------------*/
lake::lake() : kind(0) , lifeguard (0), depth(0) //default contructor
{
	//cout << "Lake D Contructor called " << endl;
}
lake::~lake()//destructor
{
	//cout << "Lake Destructor called " << endl;
}
lake::lake(const lake & source): person(source)// CC
{
	//cout << "Lake C.C  called " << endl;
	kind = source.kind;
	lifeguard = source.lifeguard;
	depth = source.depth;
} 
lake::lake(string & name, char * date): person(name, date)
{
	// Adding the rest of the details	
	add();
}
bool lake::add()
{
	//cout << "Lake add()  called " << endl;
	cout << "Name of Lake?		                        ";
	cin >> kind; cin.ignore(100,'\n');

	cout << "Lifeguard present ? y/n           		";
	cin >> lifeguard; cin.ignore(100, '\n');

	cout << "What's the depth of the lake (#)                ";
	cin >> depth; cin.ignore(100, '\n');

	return true;
}
bool lake::display()
{
	person::display();

	cout << "Lake kind    : 					" << kind << endl 
	     << "Lifeguard    : 					" << lifeguard << endl
	     << "Lake Depth(#): 					" << depth << endl;

	return true;
}

// DATA STRUCTURE TIME ! 

node_lake::node_lake()  //default contructor
{
}
node_lake::~node_lake() //destructor
{

}
node_lake::node_lake(const node_lake & source): lake(source)
{} // CC
node_lake::node_lake(string & name, char * date): lake(name, date){}

void node_lake::set_next ( node_lake * to_add)
{
	next = to_add;
}
node_lake * & node_lake::go_next ()
{
	return next;
}
void node_lake::remove_all(node_lake * & head)
{
	if(!head) return;

	remove_all(head->go_next());
	head->~node_lake();
	head = NULL;
}
/*--------------------------------------------------------------------*/
//       lake_list ** lake_event;	
lake_list::lake_list()
{
	lake_event = new node_lake* [7];
	for(int i = 0; i < 7; ++i)
	{
		lake_event[i] = NULL;
	}
}
lake_list::~lake_list()
{
	// call remove all func to clear the Array of LLL
	for(int i = 0; i < 7; ++i)
	{
		if(lake_event[i])
		{
		
		node_lake *  & head = lake_event[i];
	
			//one left in that array element
			if(head && !head->go_next())
			{
				head->~node_lake();
				head = NULL;	
			}
			else
			{
				//remove_re(head)
				head->remove_all(head);
				lake_event[i] = NULL;
			}
		}
	}
}
int lake_list::display_all()
{
	//cout << "Display all called " << endl;
	for(int i = 0; i < 7; ++i)
		if(lake_event[i])
			display_all(lake_event[i]);	
	return 1;
}
int lake_list::display_all(node_lake * head)
{
	//cout << "Display all re called " << endl;
	if(!head)
		return 1;

	head->display();
	display_all(head->go_next());
	
	return 1;
}
int lake_list::choice()
{
	char x; cin >> x; cin.ignore(100, '\n');	

	if(tolower(x) == 'm')
		return 0;
	else if(tolower(x) == 't')
		return 1;
	else if(tolower(x) == 'w')
		return 2;
	else if(tolower(x) == 'r')
		return 3;
	else if(tolower(x) == 'f')
		return 4;
	else if(tolower(x) == 's')
		return 5;
	else
		return 6;
	return 0;
}
int lake_list::add (const node_lake & source)
{
	//cout << "Lake list add called " << endl;
	cout << "What day of the week is it taking place" << endl;
	cout << " m - monday, t - tuesday, w = wednesday " << endl
	     << " r - thursday, f - friday, s - saturday, u - sunday " << endl;
	
	int i = choice();

	node_lake * & head = lake_event[i];

	if(!head)
	{
		head = new node_lake(source);
		head->set_next(NULL);
		return 1;
	}
	else
	{
		node_lake * temp = head;
		head = new node_lake(source);
		head->set_next(temp);
		return 1;
	}
	return 0;
}
int lake_list::remove_all()
{
	//cout << "Remove all called " << endl;	
	return 0;
}
int lake_list::remove(string & key)
{
	for(int i = 0; i < 7; ++i)
		remove(lake_event[i], key);		

	return 1;
}
int lake::compare(string & key)
{
	if( key == kind)
		return 1;
	return 0;
}
int lake_list::remove(node_lake * & head, string & key)
{
	if(!head)
		return 0;	
	
	if(head->lake::compare(key))
	{
		if(!head->go_next())
		{
			head->~node_lake();
			head = NULL;
			return 1;
		}
		else
		{
			node_lake * temp = head->go_next();
			head->~node_lake();
			head = temp;
			return 1;
		}
	}
	remove(head->go_next(), key);

	
	return 0;
}













