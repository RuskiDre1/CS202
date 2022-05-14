#include "data.h"
//data.cpp
// andrey toderyan 
/* 07/20/21
	
  this is the implementation for the data class and includes operations for 
  
        protected:
                node * prev;
                base * a_culture;
                node * next;
};
*/

node::node(): prev(NULL) , next(NULL) , a_culture(NULL)
{

}
node::~node()
{
	delete a_culture;
}
void node::set_base_ptr(int x)
{
	if(x==1)
        {
        	a_culture = new usa;
                return;
        }
        else if(x==2)
        {
                a_culture = new french;
                return;
        }
        else if(x==3)
        {
                a_culture = new brit;
                return;
	}
}
//this function uses the base pointers to call
//on derived class functions
void node::activate()
{
}
int node::retrieval(int node)
{
	return 1;
}
int collect_points()
{
	return 1;
}
void node::set_next(node * to_add)
{
	next = to_add;
}
void node:: set_prev(node * to_add)
{
	prev = to_add;
}
node * & node::go_next()
{
	return next;
}
//this function uses the base pointers to call
/*----------------------------------------------------------------------*/
/*
	node * head;
*/
list::list()
{
	head  = NULL;
}
list::~list()
{
	remove_all(head);
	head = NULL;
}
int list::review()
{
	bool go = true;
	do
	{
	
	system("clear");

	cout << "----Menu----" << endl
             << "1 : Display Timeline" << endl
             << "2 : Remove all" << endl
             << "3 : Remove Specifc event" << endl;
	int opt; cin >> opt; cin.ignore(100, '\n');

	switch(opt)
	{
		case 1:
		{
			system("clear");
			cout << "Display all events " << endl;
			cout << "Anything 0 means it was not affected during that period" << endl;
			display_all();	
		}
			break;
		case 2:	
		{
			cout << "Removing all " << endl;
			remove_all(head);
		}
			break;
		case 3:
		{
			cout << "Events are numbered, chose which to delete " << endl;
			cout << " ex. delete first type 1 " << endl;
			display_all();
			cout << "Delete: ";
			int del; cin >> del; cin.ignore(100, '\n');
			removal(del);
		}
			break;
		default:
			cout << "NOT an option " << endl;
			break;

	}

	cout << "More timeline actions ? " << endl;
	char ans; cin >> ans; cin.ignore(100,'\n');

        if(toupper(ans) == 'N')
                go = false;

	}while( go == true);

	return 1;
}
int node::display()
{
	return a_culture->display();
}
int list::display_all()
{
	return display_all(head);
}
int list::display_all(node * head)
{
	if(!head)
		return 0;
	
	head->display();
	
	display_all(head->go_next());

	return 1;
}
int list::removal(int x)
{
	return remove_select(head ,x);
}
int list::remove_select(node * & head, int & x)
{
	if(!head)
		return 0;

	if( x == 0)
	{
		if(!head->go_next())
		{
			delete head;
			head = NULL;
			return 1;
		}
		else
		{
			node * temp = head->go_next();
			delete head;
			head = temp;
		}
	}
	remove_select(head->go_next(), --x);
	return 1;

}
int list::remove_all(node * & head)
{
	if(!head)
		return 0;
	remove_all(head->go_next());
	
	delete head;
	head = NULL;
	
	return 1;
}


int node::trade()
{
	return a_culture->trade();
}
int node::attack()
{
	return a_culture->attack();
}
int node::farm()
{
	return a_culture->farm();
}
int list::trade()
{
	cout << "Who do you wanna trade with?" << endl;
	int trade_no = choose();

	//int recived= tail->a_culture->trade();
	int recived = tail->trade();

	int money = abs(recived);

	// if - health
	// if + soldiers

	if(trade_no == 1)
	{
		usa_money += money;
	}
	else if(trade_no == 2)
	{		
		french_money += money;
	}
	else if(trade_no == 3)
	{
		brit_money += money;
	}

	return recived;
}
int list::attack()
{
	//attacking subtracts power but does more damage to enemy

	cout << "Who do you wanna attack?" << endl;
	int attack_no = choose();
	
	//will collect how much damage is done to enemy choosen
	// by choose function	

	//send this value to base info of attacked nation
	int damage_done = tail->attack();

	int money_steal = (damage_done/-2);

	//failed attack 
	if(damage_done == 0)
	{
		return 0;
	}

	if( attack_no == 1)
	{
		usa_power += damage_done;
		usa_health += damage_done;
		usa_money += money_steal;
		return 1;
	}
	else if(attack_no== 2)
	{		
		french_power += damage_done;
		french_health += damage_done;
		french_money += money_steal;
		return 1;
	}
	else if(attack_no == 3)
	{
		brit_power += damage_done;
		brit_health += damage_done;
		brit_money += money_steal;
		return 1;
	}


	return 1;
}
int list::menu()
{
	system("clear");
	cout << "---------------Current Economic Standings---------------" << endl;

	// system goes and tallies all the current assests and troops 
	current();

	cout << endl << "Which Country do you want to steer? " << endl;
	int country = choose();
	//adding node to DLL and upcasting the base ptr
	//to point to specific derived class
	add(country);
	     
	     cout << "----Menu----" << endl
             	  << "1 : Trade" << endl
             	  << "2 : Attack" << endl
             	  << "3 : Farm" << endl
		  << "4 : Red COATs only (dynamic cast ) Converstion" << endl;
	int opt; cin >> opt; cin.ignore(100, '\n');

	switch(opt)
	{
		case 1:
		{
			int result = trade();					
			// + solidersj
			if(result > 0)
			{
				if(country == 1)
				{
					usa_power += result;
					usa_money += -result;
				}
				if(country == 2)
				{
					french_power += result;
					french_money += -result;
				}
				if(country == 3)
				{
					brit_power += result;
					brit_money += -result;
				}
			}
			else
			{
				if(country == 1)
				{
					usa_health += -result;
					usa_money += result;
				}
				if(country == 2)
				{
					french_money += result;
					french_health += -result;
				}
				if(country == 3)
				{
					brit_health +=  -result;
					brit_money += result;
				}
			}
		}
			break;
		case 2:
		{
			attack();
				
			if(country == 1)
				usa_power += -5;
			if(country == 2)
				french_power += -5;
			if(country == 3)
				brit_power += -5;
		}
			break;
		case 3:
		{
			int result = tail->farm();
			if(result == 1)
			{
				if(country == 1)
					usa_power += 5;
				if(country == 2)
					french_power += 5;
				if(country == 3)
					brit_power += 5;
			}
			if(result == 2)
			{
				if(country == 1)
					usa_money += 5;
				if(country == 2)
					french_money += 5;
				if(country == 3)
					brit_money += 5;
			}
		}
			break;
		case 4:
		{
			cout << "This MAGIC ONLY WORKS IF YOU CHOSE THE BRITS TO CONTROL!";
			cout << "Press Enter to try " << endl;	
			cin.get();
			if(country != 3)
			{
				cout << "BOOTED !!! " << endl;
				break;
			}
			//cout << "******magic_happens!******" << endl;
			
			tail->conversion();

			cout << endl << "BRITISH HEALTH back to  100!" << endl;	
			brit_health = 100;
		}
			break;
		default:
			cout << "Not an Option " << endl;
                        	break;
	}
	
	return 1;
	//changes functions to update list's scoreboard
	// and if one value is below 0 that country is dead
}
int node::conversion()
{
	//access the hidden function containing athem, cast the base ptr

	brit * brit_ptr = dynamic_cast< brit* >( a_culture );
	
	if(brit_ptr)
		brit_ptr->song();
	
	return 1;
}
int list::add(int country)
{
	if(!head)
	{
		//cout << "NEW head add " << endl;
		head = new node;
		head->set_base_ptr(country);
		head->set_next(NULL);
		tail = head;
		//fix this later
		//head->set_prev(head);
		return 1;
	}
	else
	{
		//cout << "Adding at tail" << endl;
		node * hold = tail;
		tail = new node;
		tail->set_base_ptr(country);
		hold->set_next(tail);
		
		tail->set_prev(hold);
		return 1;
	}
	//cout << "FAil add " << endl;
	return 0;	
}
int list::choose()
{
             	 cout << "1 : USA" << endl
             	      << "2 : French" << endl
             	      << "3 : British" << endl;
		int attack; cin >> attack; cin.ignore(100, '\n');
		return attack;
}
int list::current()
{
	// Run Through the list and count the assets and display
	
	cout << "       -----French----- | -----USA----- | -----Brit----- " << endl
	     << "Money:  " << french_money << "\t\t\t" << usa_money << "\t\t\t" << brit_money << endl;
	cout << "Health: "<< french_health << "\t\t\t" << usa_health << "\t\t\t" << brit_health << endl;
	cout << "Power:  " << french_power << "\t\t\t" << usa_power << "\t\t\t" << brit_power << endl;
	
	return 1;
	
}
int list::play()
{
	cout << "Would you like to input starting values? " << endl;
	char  opt; cin >> opt; cin.ignore(100, '\n');
	if( tolower(opt) == 'y')
	{
		manual_input();
		return 1;
	}
	french_money = currency();
        usa_money = currency();
	brit_money= currency();
	french_health = usa_health = brit_health = 100;
	usa_power = power();
	french_power= power();
	brit_power= power();
	
	return 1;
}
int list::power()
{
	return rand()% 25 + 25;
}
int list::currency()
{
	return rand()% 50 + 25;
}

int list::play_re(node * head, int x)
{
	return 0;
}
int list::manual_input()
{
	cout << "Enter Values from 1 - 100" << endl;
	cout << "---Power---" << endl
	     << "USA	 " << endl; cin >> usa_power; cin.ignore(100, '\n');
	cout << "French  " << endl; cin >> french_power; cin.ignore(100, '\n');
	cout << "Brit    " << endl; cin >> brit_power; cin.ignore(100, '\n');

	cout << "---Money---" << endl 
	     << "USA	 " << endl; cin >> usa_money; cin.ignore(100, '\n');
	cout << "French  " << endl; cin >> french_money; cin.ignore(100, '\n');
	cout << "Brit    " << endl; cin >> brit_money; cin.ignore(100, '\n');

	cout << "--Health---" << endl
	     << "USA	 " << endl; cin >> usa_health; cin.ignore(100, '\n');
	cout << "French  " << endl; cin >> french_health; cin.ignore(100, '\n');
	cout << "Brit    " << endl; cin >> brit_health; cin.ignore(100, '\n');

	return 1;
}
int list::check()
{
	//cout << "IN THE CHECK PHASE " << endl;
	//checking whether 2 have lost completly
	bool check_1 = 0;
	bool check_2 = 0;
	bool check_3 = 0;

	if(usa_money < 0|| usa_health < 1)	
	{
		cout << "USA is LOSING... " << endl;
		check_1 = 1;
	}
	if(french_money < 0|| french_health < 1)	
	{
		cout << "France is LOSING... " << endl;
		check_2 = 1;
	}	
	if(brit_money < 0|| brit_health < 1)	
	{
		cout << "British is LOSING... " << endl;
		check_3 = 1;
	}



	if(check_1 == 1&& check_2 == 1)
	{
		cout << "GAME OVER! , BRITS HAVE WON" << endl;
		return 0;
	}
	else if(check_2 == 1&& check_3 == 1 )
	{
		cout << "GAME OVER! , USA HAS WON" << endl;
		return 0;
	}
	else if(check_1 == 1&& check_3 == 1)
	{
		cout << "GAME OVER! , France HAS WON" << endl;
		return 0;
	}
	return 1;

}














