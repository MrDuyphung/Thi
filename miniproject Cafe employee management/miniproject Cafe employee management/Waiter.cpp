#include "Waiter.h"

Waiter::Waiter()
	: Employee{}
{
}

Waiter::Waiter(int id, string name, string age)
	: Employee { id, name, age }
{
}

void Waiter::input()
{
	cout << "I am Waiter" << '\n';

	Employee::input();

	cout << "Enter category: " << '\n';
	getline(cin, m_category);
}

void Waiter::show()
{
	Employee::show();
	cout << "I am waiter, i'm here to make request of customer" << '\n';
}