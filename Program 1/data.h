#include "header.h"
// data.h
// Andrey Toderyan
/* 06/23/21
	
  This is the main header file for the data structures  for Program 1.
  This file will hold prototypes of
                                    Lake class node   
                                    Concert class node
                                    Hike class node
  Part 2:
  This portion includes all the classes for holding start of each data structure
	lake_list ------- Array of LLL
	concert_list ---- Circular linked list
	hike_list ------- STL ( vector? )
*/

class node_lake: public lake
{
	public:
		node_lake(); //default contructor
		~node_lake();//destructor
		node_lake(const node_lake & source); // CC

		node_lake(string & name, char * date);

		void remove_all(node_lake * & head);

		void set_next ( node_lake * source);
		node_lake * & go_next ();	

	protected:
		node_lake * next;

};

class lake_list
{
	public:
		 lake_list();
		~lake_list();

		 int add (const node_lake & source);
		 int display_all();
		 int remove_all();
		 int remove(string & );
		int choice();

	protected:
		 node_lake ** lake_event;	

		 int remove(node_lake * & head, string & );
		 int display_all(node_lake * head);
};

/*-----------------------------------------------------------------*/
class node_concert: public concert
{
	public:
		node_concert(); //default constructor
		~node_concert(); //destructor
		node_concert(const node_concert & ); // CC

		
		node_concert(string & name, char * date); 

		void set_next(node_concert * source);
		node_concert * & go_next();

	protected:
			node_concert * next;
};
class concert_list
{
	public:
		concert_list();
		~concert_list();

		int add (const node_concert & source);
		 int display_all();
		 int remove(string & );
		int remove_all();


	protected:
		 node_concert * rear;  // rear pointer
		 

		 int remove_all(node_concert * & head);
		 int remove(node_concert * & head, string & );
		 int display_all(node_concert * head);
};
/*-------------------------------------------------------------*/
class node_hike: public hike
{
	public:
		node_hike(); // default constructor
		~node_hike(); // destructor
		node_hike(const node_hike & ); // CC


		node_hike( string & name, char * );

	protected:

};
class hike_list
{
	public:
		hike_list();
		~hike_list();
	
 		 int add (string &, char * );
		 int display_all();
		 int remove(string &  );
		 int remove_all();
	
	protected:
		vector <node_hike*> hikeVector; // Vector for Hike events

};





