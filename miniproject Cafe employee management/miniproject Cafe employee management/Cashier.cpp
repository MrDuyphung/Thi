#include "Cashier.h"

void Cashier::show()
{
	Employee::show();
	cout << "I'm Cashier, i'm in charge of the collection counter." << '\n';
}

void Cashier::input()
{
	cout << "I am Cashier" << '\n';
	Employee::input();
}
