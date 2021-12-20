#include "Labor.h"

Labor::Labor()
	: Employee{}
{
}

Labor::Labor(int id, string name, string age)
	: Employee{ id, name, age }
{
}

void Labor::input()
{
	cout << "I am Labor" << '\n';

	Employee::input();

	cout << "Enter category: " << '\n';
	getline(cin, m_category);
}

void Labor::show()
{
	Employee::show();
	cout << "I am Labor, i will clean WC right now." << '\n';
}
