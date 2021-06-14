#pragma once
#include "Employee.h"
class List
{
private:
	std::vector<Employee*> list;

public:
	void addEmployee();
	void removeEmployee(const int index);
	void setEmployee(const int index);
	void clear();
	void showAll();


	int getSize();
	Employee& getEmployee(const int index);
	Employee& getEmployeeByWorkExp(const int workExp);

	void sortByWorkExp();

	string check(regex reg);
	int chooseInt(const int start,const int end);

	Employee& operator[](const int index);
	friend std::ostream& operator << (std::ostream& out, const List& obj) {
		for (int i = 0; i < obj.list.size(); i++)
			out << obj.list[i];

		return out;
	}

	void readFromFile();
	void writeToFile();
};
