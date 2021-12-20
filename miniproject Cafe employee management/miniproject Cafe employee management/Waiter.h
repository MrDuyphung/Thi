#pragma once

#include "Employee.h"

class Waiter : public Employee
{
private:
	string m_category;

public:
	Waiter();

	Waiter(int id, string name, string age);

	void input() override;

	void show() override;
};
