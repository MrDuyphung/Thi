#pragma once

#include "Employee.h"

class Cashier : public Employee
{
private:
	string m_programmingLanguage;

public:

	Cashier() {}

	Cashier(int id, string name, string age)
		: Employee{ id, name, age }
	{}

	virtual void show();
	virtual void input();
};

