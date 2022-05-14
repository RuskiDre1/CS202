#include "data.h"
// Olympic Tracker
// data.cpp
// Andrey Toderyan
/* 08/05/21
	)
  This is the data .cpp file for the Olympic Tracker
	while includes implementations for  2-3 tree and it's nodes and implementations

*/
/*
protected:
		protected:
		athlete * an_athlete;
		node_lll * next;
*/
/*----------------------------------------*/
node_lll::node_lll()
{
}
node_lll::node_lll(const node_lll &)
{

}
node_lll::~node_lll()
{

}
int node_lll::display()
{
	return 1;
}

int node_lll::input()
{
	return 1;
}
		
/*----------------------------------------*/
/*
	protected:
		//2 athletes, 
		athlete * data[2];
		//children	
		bst_node * child[3];
*/
bst_node::bst_node()
{
	//2 athletes, 
	for(int i = 0; i < 3; ++i)
	{
		data[i] = NULL;
	}

	for(int i = 0; i < 3; ++i)
	{
		child[i] = NULL;
	}

}
bst_node::bst_node(const bst_node & )
{

}
bst_node::~bst_node()
{
}

int bst_node::display_lll() // calls Overloaded " << " operator while going through bst
{
	return 1;
}

		
int bst_node::input()
{
	return 1;
}
		
		// = 
bst_node & bst_node::operator = (const bst_node & source)
{
	return *this;
}
		
		//display
ostream & operator << (ostream & out, const bst_node & a_athlete)
{

}
		// input 
istream & operator >> (istream & in, bst_node & new_node)
{
}
	
		//if another bst_node name is < > to balance correctly				
bool operator < (const bst_node, const bst_node)
{

}
bool operator > (const bst_node, const bst_node)
{

}

	
/*	
friend bool operator <= (const node, const node);
friend bool operator >= (const node, const node);
friend bool operator != (const node, const node);
*/

/*-----------------------------------------------------*/
/*
	protected:
		bst_node * root;
*/
bst::bst()
{
	root = NULL;
}
bst::~bst()
{
	//remove all
}
int bst::menu()
{

	do
	{
		cout << "-------- Menu --------" << endl
             	     << "1 : Add Athlete" << endl
             	     << "2 : Display All" << endl
             	     << "3 : Remove All" << endl
	      	     << "4 : Remove Specific" << endl;
		int opt; cin >> opt; cin.ignore(100, '\n');

		switch(opt)
		{
			case 1:
			{
				int opt = athlete_type();

			//try "Add exception handling here to check for successful input
			
				athlete * temp = NULL;
		
				cout << "Upcasting about to happen " << endl;
				cin.get();
			
				if(opt == 1)
					temp = new dash;
				if(opt == 2)
					temp = new relay;
				else	
					temp = new long_m;

				temp->input();
				add(temp);
			}
				break;
			case 2:
			{
				cout << "displaying all" << endl;
				display_all(root);

			}
				break;
			case 3:
			{


			}
				break;
			case 4:
			{


			}
				break;
			default:
				cout << "Not an option" << endl;
				break;
		}
	} while(another());



	return 1;
}
int bst::add(athlete * add)
{
	if(!root)
	{
		cout << "No root" << endl;
		//root = new bst;
	}
	//recursive call

	add_re(root, add);

	return 1; 	
}
/*
	//2 athletes, 
		athlete * data[2];
		//children	
		bst_node * child[3];
*/



int bst::check_room(bst_node * root)
{
	if(!root->data[1] || !root->data[0] || !root->data[2]) // <--- temp pointer
		return 1;
	return 0;
}
bool bst::isLeaf( bst_node * root)
{
	return (!root->child[0] && !root->child[1] && !root->child[2]);
}

bool bst_node::full_data_small(bst_node * root)
{
	// check if kinds have full data, like 3 nodes along with temp
	return (root->data[1] && root->data[0] && root->data[2]);
}
int bst_node::full_data()
{
	for(int i = 0; i < 3; ++i)
		if(full_data_small(child[i]))
			return i;
	return -1;
}
int bst::add_re(bst_node * & root, athlete * add)
{
	cout << "in recursive out" << endl;

	if(!this->root)
	{
		root = new bst_node;
	}

	if(this->root->full_data_small(this->root))
	{
		cout << "checking ineer loop" << endl;
	}
	
	//check if room in node	, if it's a leaf
	if( isLeaf(root) == true && check_room(root) == 1)
	{
		if(!root->data[0])
		{
			cout << "added to very first!" << endl;
			if(root->data[0] == NULL)
				root->data[0] = add;
				return 1;
		} 

		//swap needed?
		if( root->data[0]->compare(add) == 1)
		{
			athlete * hold = root->data[0];
			root->data[0] = add;
			root->data[1] = hold;
			return 1;
		}
		//no swap needed , 1 is open add is larger than data[0]
		if(root->data[0]->compare(add) == -1)
		{	
			root->data[1] = add;
			return 1;
		}
		
		// FULL!!! place in temporary holder
		if(root->data[0] && root->data[1])
		{
			if(root->data[1]->compare(add) == 1) //bigger than data[1]
			{
				root->data[2] = add;
				return 1;
			}
			// less than data[1] and larger than data[0] --> goes in middle
			if(root->data[0]->compare(add) == 1)  //larger than data[0]
			{
				athlete * hold = root->data[1];
				root->data[1] = add;
				root->data[2] = hold;
				return 1;
if(!root) return 0;

        int counter = 0;

        counter = display_re(root->go_left());


        counter += display_re(root->go_right());

        // OVERLOADED OPERATOR! YAY
        cout << (*root);
			}
			// less than data[0] , move data[1] -->data[2] , data[0] --> data[1]
			root->data[2] = root->data[1];
			root->data[1] = root->data[0];
			root->data[0] = add;
			return 1;
		}
		cout << " None of the conditions met" << endl;
		return 1;
	}
	else 
	{
		//transverse the tree to find leaf where to insert
	
		//left subtree	
		if( root->data[0]->compare(add) == -1)
		{
			add_re(root->child[0], add);
			
			//going back up
	
			int i = root->child[0]->full_data();
			if( i != -1)
			{
				//i is the child where we will go and pull up ptr;
				athlete * hold = root->child[i]->data[1];
								
				//insert into current root 
				root->data[2] = root->data[1];
				root->data[1] = root->data[0];
				root->data[0] = hold;
				
				root->child[i]->data[1] = NULL;
				return 1;
			}
			return 1;

		}
		//greater go down to the right subtree
		else if( root->data[1]->compare(add) == 1)
		{
			add_re(root->child[2], add);

			int i = root->child[2]->full_data();
			if( i != -1)
			{
				//i is the child where we will go and pull up ptr;
				athlete * hold = root->child[i]->data[1];
								
				//insert into current root 
				root->data[2] = hold;
				
				root->child[i]->data[1] = NULL;
				return 1;
			}
			return 1;
		}
		// middle
		else
		{
			add_re(root->child[1], add);
			
			int i = root->child[1]->full_data();
			if( i != -1)
			{
				//i is the child where we will go and pull up ptr;
				athlete * hold = root->child[i]->data[1];
								
				//insert into current root 
				root->data[2] = root->data[1];
				root->data[1] = hold;
				
				root->child[i]->data[1] = NULL;
				return 1;
			}
			return 1;
		}

	}

		
		
	
}
/*
		
		bst_node  * child[4];
		
		//holds 2 data + 1 temp
		athlete * data[3];
*/

int bst::display_all(bst_node * root)
{
	if(!root) return 0;

        int counter = 0;

	for(int i = 0; i < 4; ++i)
	{
		if(root->child[i])
        		display_all(root->child[i]);

		for(int j = 0; j < 3; ++j)	
		{
			
        		if(root->data[j])
			{
				cout << "sdf" << endl;
				root->data[j]->display();
			}
		}
	}
	return 1;
}

int bst::display_root()
{
	for(int i = 0; i < 4; ++i)	
        	counter = display_root(root->child[0])
			for(int i = j; j < 2; ++j)	
        			if(root->data[j])
					root->data[j]->display();
	return 1;
}

int bst::balance()
{
	return 1;
}
bool another()
{
	cout << endl << "Another Action?  (Y/N)" << endl;
        char ans; cin >> ans; cin.ignore(100,'\n');

        if(toupper(ans) == 'Y')
                return true;
        return false;
}
int athlete_type()
{
	cout << "What kind of athlete do you want to add?" << endl 
	     << "1: Short Distance 100m " << endl
	     << "2: Relay 5000m " << endl
	     << "3: Long Distance " << endl;
	int opt; cin >> opt; cin.ignore(100, '\n');
	return opt;
}










