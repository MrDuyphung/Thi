#pragma once

#include "Employee.h"

class Guard : public Employee
{
private:
	string m_category;

public:
	Guard();

	Guard(int id, string name, string age);

	void input() override;

	void show() override;
};
