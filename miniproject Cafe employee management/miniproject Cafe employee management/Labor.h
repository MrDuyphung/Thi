#pragma once

#include "Employee.h"

class Labor : public Employee
{
private:
	string m_category;

public:
	Labor();

	Labor(int id, string name, string age);

	void input() override;

	void show() override;
};
