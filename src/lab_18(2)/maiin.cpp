#pragma once
#include "Employee.h"
#include "Test.h"

int main() {

	testAdd();
	testRemove();

	int size = 2;
	Employee* mass = (Employee*)malloc(size * sizeof(Employee));
	for (int i = 0; i < size; i++)
	{
		mass[i] = create();
	}
	size = addEmployee(mass,size);
	write(mass, size);

	size = removeEmployee(mass,size,1);
	write(mass, size);

	return 0;
}