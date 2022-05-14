#include "header.h"

// Colonial Game
// data.h
// Andrey Toderyan
/* 07/20/21
	
  This is the main header file for the data structures which will include
  dynamic binding for the Colonial Game

*/
class node
{
        public:
                node();
                ~node();

		// wrappers to call heirachy functions w/ dynamic binding	
		// by accessing the base pointer found in protected
		int trade();
		int attack();
		int farm();
		int conversion();
		int display();


                void set_base_ptr(int type);
                //this function uses the base pointers to call
                //on derived class functions
                void activate();
                int retrieval(int node);
                int collect_points();

                void set_next(node * source);
		void set_prev(node * source);

                node * & go_next();
        protected:	
                node * prev;
                civil * a_culture;
                node * next;
};

///////////////
class list
{
        public:
                list();
                ~list();

                //Play button, display game
		int choose();
		int current();
		int menu();
                int play();
		int attack();
		int trade();
		int manual_input();
		int add(int country);
		int check();
		int review();
		int display_all();

		
		//random input when user does not manually input
		int power();
		int currency();

		int changes(int civil, int health, int money, int power);
		int removal(int x);
                int removal();

                int retrieval(int , int );
        protected:
                int retrieval_v2(node * head, int node);
		int remove_all(node * & head);
		int remove_select(node * & head, int & x);
		int display_all(node * head);

                int french_money;
                int usa_money;
		int brit_money;

		int french_health;
		int usa_health;
		int brit_health;

		int usa_power;
		int french_power;
		int brit_power;

                void insert(node * & head, int x);
                int menu(node * head, int x);
                int play_re(node * head, int x);

                node * head;
		node * tail;

};

