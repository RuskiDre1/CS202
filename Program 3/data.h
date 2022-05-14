#include "header.h"
// Olympic Tracker
// data.h
// Andrey Toderyan
/* 08/05/21
	
  This is the main header file for the hierchaywhich will include
  BST of LLL Exception Handling in Olympic Tracker

*/
class node_lll
{
	public:
		node_lll();
		node_lll(const node_lll &);
		~node_lll();

		int display();
		int input();
		


	protected:
		athlete * an_athlete;
		node_lll * next;
	

};
class bst_node
{
	public: 
		bst_node();
		bst_node(const bst_node & );
		~bst_node();

		int display_lll(); // calls Overloaded " << " operator while going through bst
		int input();
		
		bool full_data_small(bst_node * root);
		int full_data();

		
		// = 
		bst_node & operator = (const bst_node & source);
		
		//display
		friend ostream & operator << (ostream & out, const bst_node & a_athlete);
		// input 
		friend istream & operator >> (istream & in, bst_node & new_node);	
	
		//if another bst_node name is < > to balance correctly				
		friend bool operator < (const bst_node, const bst_node);
		friend bool operator > (const bst_node, const bst_node);

	
		/*	
		friend bool operator <= (const node, const node);
		friend bool operator >= (const node, const node);
		friend bool operator != (const node, const node);
		*/

	


		// 3 children + 1 temp
		bst_node  * child[4];
		
		//holds 2 data + 1 temp
		athlete * data[3];

		friend class bst;
};
class bst
{
	public:
		bst();
		~bst();

		int menu();
		int add(athlete * temp);
		int add_re(bst_node * &  root, athlete * temp);
		int balance();

		int full_data(bst_node * root);

	protected:
		bst_node * root;

		int display_all(bst_node * root);
		int display_root(bst_node * root);
		int check_room(bst_node * root);
		bool isLeaf( bst_node * root);
		//bool full_data_small(bst_node * root);
		//int full_data(bst_node * root);
};

