#include "Guard.h"

Guard::Guard()
	: Employee{}
{
}

Guard::Guard(int id, string name, string age)
	: Employee{ id, name, age }
{
}

void Guard::input()
{
	cout << "I am Guard" << '\n';

	Employee::input();

	cout << "Enter category: " << '\n';
	getline(cin, m_category);
}

void Guard::show()
{
	Employee::show();
	cout << "I am guard, i'm in charge of security and parking lot in Cafe." << '\n';
}
