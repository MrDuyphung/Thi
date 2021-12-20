#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

#include "Employee.h"
#include "Cashier.h"
#include "Guard.h"
#include "Waiter.h"
#include "Manager.h"
#include "Labor.h"
#include "Supportme.h"

void showMenu() {
	cout << "-----------------------Config settings Cafe----------------------" << '\n';
	cout << "1. Add employee." << '\n';
	cout << "2. Edit employee." << '\n';
	cout << "3. Remove employee." << '\n';
	cout << "4. Sort employee by name." << '\n';
	cout << "5. Show all employees." << '\n';
	cout << "6. Salary." << '\n';
	cout << "7. Guide for new manager." << '\n';
	cout << "0. Exit" << '\n';
	cout << "--------------------------------------------------" << '\n';
	cout << "Please choose: ";
}
void guide() {
	cout << "Enter 1 2 3 ... to choose what u need, that's all..." << '\n';
	cout << "Remember, dont break any rules and dont make any mistake. " << '\n';
	cout << "And last one, this guide and config system is still beta, help me complete this." << '\n';
}
	


void incomemon() {
	cout << "--------------- Type of Employee ---------------" << '\n';
	cout << "1.Cashier" << '\n';
	cout << "2.Waiter" << '\n';
	cout << "3.Guard" << '\n';
	cout << "4.Manager" << '\n';
	cout << "5.Labor" << '\n';
	cout << "0.exit" << '\n';
	cout << "--------------------------------------------------" << '\n';

	int a, b, c, d, e, x;
	a = 30000;
	b = 20000;
	c = 25000;
	d = 50000;
	e = 15000;
	x = 200;



	int chose;

	bool exit{ false };


	while (true) {
		cin >> chose;
		switch (chose) {

		case 1:
			int y;
			cout << "Number of days off in the month:";
			cin >> y;

			if (y < 30) {
				cout << "Cashier gained: " << a - (x * y) << "usd." << '\n'; 
				incomemon();
				break;
			}
			else {
				cout << "Error cant calculate." << '\n';
				exit = true;
				break;
				
				
			}
		case 2:

			cout << "Number of days off in the month:";
			cin >> y;

			if (y < 30) {
				cout << "Waiter gained: " << b - (x * y) << "usd." << '\n';
				incomemon();
				break;

			}
			else {
				cout << "Error cant calculate." << '\n';
				exit = true;
				break;

			}
		case 3:

			cout << "Number of days off in the month:";
			cin >> y;

			if (y < 30) {
				cout << "Guard gained: " << c - (x * y) << "usd." << '\n';
				incomemon();
				break;
			}
			else {
				cout << "Error cant calculate." << '\n';
				exit = true;
				break;

			}
		case 4:

			cout << "Number of days off in the month:";
			cin >> y;

			if (y < 30) {
				cout << "Manager gained: " << d - (x * y) << "usd." << '\n';
				incomemon();
				break;
			}
			else {
				cout << "Error cant calculate." << '\n';
				exit = true;
				break;

			}
		case 5:

			cout << "Number of days off in the month:";
			cin >> y;

			if (y < 30) {
				cout << "Labor gained: " << e - (x * y) << "usd." << '\n';
				incomemon();
				break;
			}
			else {
				cout << "Error cant calculate." << '\n';
				exit = true;
				break;

			}
		case 0:
			exit = true;
			break;

		}

		if (exit) {
			break;
			showMenu();
		}
	}
}


void showAll(vector<Employee*> list) {
	for (auto e : list) {
		e->show();
	}
}

void menuadd() {
	cout << "--------------- Add a new employee ---------------" << '\n';
	cout << "1.Cashier" << '\n';
	cout << "2.Guard" << '\n';
	cout << "3.Waiter" << '\n';
	cout << "4.Manager" << '\n';
	cout << "5.Labor" << '\n';
	cout << "0.exit" << '\n';
	cout << "--------------------------------------------------" << '\n';

}


int main()
{
	

	vector<Employee*> list{};

	ifstream fileIn{ "input.txt" };

	// doc du lieu tu file
	string line;
	while (getline(fileIn, line)) {

		auto vec = Supportme::split(line, ",");

		if (vec.at(0) == "1") {
			list.push_back(new Cashier{ stoi(vec.at(1)), vec.at(2), vec.at(3) });
		}
		else if (vec.at(0) == "2") {
			list.push_back(new Guard{ stoi(vec.at(1)), vec.at(2), vec.at(3) });
		}
		else if (vec.at(0) == "3") {
			list.push_back(new Waiter{ stoi(vec.at(1)), vec.at(2), vec.at(3) });
		}
		else if (vec.at(0) == "4") {
			list.push_back(new Manager{ stoi(vec.at(1)), vec.at(2), vec.at(3) });
		}
		else if (vec.at(0) == "5") {
			list.push_back(new Labor{ stoi(vec.at(1)), vec.at(2), vec.at(3) });

		}
	}

	

	int choose;
	bool exit{ false };

	string name;

	showMenu();
	while (true) {

		cin >> choose;
		cin.ignore(100, '\n');

		switch (choose)
		{
		case 1:
		{
			cout << "Add employee" << '\n';

			int chooseType;
			menuadd();
			cin >> chooseType;
			cin.ignore(100, '\n');

			switch (chooseType) {
			case 1:
			{
				Employee* e{ new Cashier{} };
				e->input();
				list.push_back(e);
			}
			break;
			case 2:
			{
				Employee* e{ new Guard{} };
				e->input();
				list.push_back(e);
			}
			break;
			case 3:
			{
				Employee* e{ new Waiter{} };
				e->input();
				list.push_back(e);

			}
			break;
			case 4:
			{
				Employee* e{ new Manager{} };
				e->input();
				list.push_back(e);

			}
			break;
			case 5:
			{
				Employee* e{ new Labor{} };
				e->input();
				list.push_back(e);

			}
			break;
			}

		}
		break;
		case 2:
		{
			cout << "Edit employee" << '\n';
			cout << "Enter name: ";
			getline(cin, name);
			for (auto e : list) {
				if (e->getName().compare(name) == 0) {
					e->input();
					break;
				}
			}
		}
		break;
		case 3:
		{
			cout << "Remove employee" << '\n';
			cout << "Enter name: ";
			getline(cin, name);
			

			for (auto e : list) {
				if (e->getName().compare(name) == 0) {
					auto index = std::find(list.begin(), list.end(), e);
					list.erase(index);
					break;
				}
			}
		}
		break;
		case 4:
			cout << "Sort by name" << '\n';
			std::sort(
				list.begin(),
				list.end(),
				[](const auto& e1, const auto& e2) {return e1->getName() < e2->getName(); }
			);
			showAll(list);
			break;
		case 5:
			cout << "Show all employees" << '\n';
			showAll(list);
			break;
		case 6:
			cout << "Salary" << '\n';
			incomemon();
			break;
		case 7:
			cout << "Guide for new manager" << '\n';
			guide();
			break;
		case 0:
			cout << "Exit" << '\n';
			exit = true;
			break;
		}
		if (exit) {
			break;
		}
		showMenu();
	}

}



