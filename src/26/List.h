#pragma once
#include "Employee.h"
class List
{
private:
	std::vector<Employee> list;

public:
	void addEmployee(Employee& employee);
	void addObjects();
	void removeEmployee(const int index);
	void showAll();

	int getSize();
	Employee& getEmployee(const int index);
	Employee& getEmployeeByWorkExp(const int workExp);
	string check(regex reg);
	void getGoogleWithoutInsurance();
	int chooseInt(int start, int end);

	Employee& operator[](const int index);
	friend std::ostream& operator << (std::ostream& out, const List& obj) {
		for (int i = 0; i < obj.list.size(); i++)
			out << obj.list[i];

		return out;
	}

	void readFromFile();
	void writeToFile();
};

class ListOfTranslator {
private:
	std::vector<Translator> list;

public:
	void addEmployee(Translator& employee);
	void addObjects();
	void removeEmployee(const int index);
	void showAll();

	int getSize();
	Translator& getEmployee(const int index);
	Translator& getEmployeeByWorkExp(const int workExp);
	string check(regex reg);
	void getSimultaneousFivePlus();
	int chooseInt(int start, int end);

	

};

class ListOfProgrammer {
private:
	std::vector<Programmer> list;

public:
	void addEmployee(Programmer& employee);
	void addObjects();
	void removeEmployee(const int index);
	void showAll();

	int getSize();
	Programmer& getEmployee(const int index);
	Programmer& getEmployeeByWorkExp(const int workExp);
	string check(regex reg);
	void getMiddleOnePlus();
	int chooseInt(int start, int end);

};
