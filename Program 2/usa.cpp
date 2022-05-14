#include "data.h"
// usa.cpp
// Andrey Toderyan 
/* 07/20/21
	
  This is the implementation for class usa


	protected:
		int colonies;
		int timber;
*/

usa::usa()
{

}

usa::~usa()
{

}
int usa::display()
{
	cout << "USA Moved" << endl;
	civil::display();
	return 1;
}
int  usa::attack()
{
	cout << "USA  Attack " << endl;
	cout << "Choose an attack method! " << endl;

        //this crop doesn't grow into money or soldiers
        int r = rand()%4 + 1;

        cout << "Land 1\t\t\tLand_2  2\t\t\tSHIP 3 \t\t\tAIR 4 \t\t\tNUKE 5" << endl;
        int choice; cin >> choice; cin.ignore(100,'\n');

        if(choice == r)
        {
                cout <<"Attack broke even, you dealth 5 and lost 5"<< endl;
		civil::power_func(-5);
                return -5;
        }
	if(choice %2 == 0)
	{
		//even
		cout << "Attack succesful! You dealth 10 damage! Lost 5" << endl;
		civil::power_func(-5);
		return -10;
	}
	if(choice == 5)
	{
		cout << "Ultimate attack!, you dealth 100 damage! Lost nothing" << endl;
		civil::power_func(0);
		return -100;
	}
        else
        {
                cout <<"Attack Failed, You lost 5 troops... enemy intact" << endl;
		civil::power_func(-5);
                return 0;
        }

	return 1;

}
int usa::trade()
{
	cout << "French Trade " << endl;
	
	cout << "Let's see your luck with trading! " << endl;
	cout << "Do you want to purchase money or soldiers ? " << endl
	     << "1 = soldiers , 2 = health " << endl;

	int opt; cin >> opt; cin.ignore(100, '\n');
	if(opt == 1)
	{
		cout << "How many soldiers to buy? $1 = 1 soldier " << endl;
		int x; cin >> x; cin.ignore(100, '\n');
		civil::power_func(x);
		civil::charge_func(-x);		
		return x;
	}
	else
	{
		cout << "How much health do you want to buy? $1 = 1 health " << endl;
		int x; cin >> x; cin.ignore(100, '\n');
		civil::health_func(x);
		civil::charge_func(-x);		
		return -x;
	}
	return 0;
}
int usa::farm()
{
	cout << "USA farm " << endl;
	cout << "Choose the a crop you want to grow! " << endl;

        //this crop doesn't grow into money or soldiers
        int r = rand()%4 + 1;

        cout << "CROP 1\t\t\tCROP 2\t\t\tCrop 3 \t\t\tCrop 4" << endl;
        int choice; cin >> choice; cin.ignore(100,'\n');

        if(choice == r)
        {
                cout <<"You failed to farm anything"<< endl;
                return 0;
        }
	if(choice %2 == 0)
	{
		//even
		cout << "You farmed +5 soldiers to attack with" << endl;
		civil::power_func(5);
		return 1;
	}
        else
        {
                cout <<"You farmed +5 money to buy stuff and survive" <<endl;
                civil::currency_func();
                return 2;
        }
	return 0;

	return 0;
}
