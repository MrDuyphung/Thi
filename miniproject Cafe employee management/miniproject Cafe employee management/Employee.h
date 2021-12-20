#pragma once

#include <iostream>
#include <string>

using namespace std;

class Employee
{
protected:
	int m_id{ 0 };
	string m_name;
	string m_email;
	string m_age;

public:
	//constructors
	Employee() {};

	Employee(int id, string name, string age)
		: m_id{ id }, m_name{ name }, m_age{ age }
	{}

	
	virtual void show();

	virtual void input();

	
	string getName();

};


