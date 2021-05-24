#include "Test.h"

void testSort() {
	printf("Here the sort test works.\n");
	int size = 3;
	struct Employee* employee = (struct Employee*)malloc(size * sizeof(struct Employee));

	for (int i = 0; i < size; i++)
	{
		employee[i] = create();
	}
	sort(employee, size);
	if (employee[0].workExperience <= employee[1].workExperience &&
		employee[1].workExperience <= employee[2].workExperience)
	{
		printf("Sort was succesful.\n");
	}
	else
	{
		printf("Sort was not succesful.\n");
	}
}

void testAdd() {

	printf("Here the add test works.\n");

	int size = 2;
	Employee* mass = (Employee*)malloc(size * sizeof(Employee));
	for (int i = 0; i < size; i++)
	{
		mass[i] = create();
	}
	size = addEmployee(mass, size);

	if (mass[size - 1].workExperience > 0 && size == 3)
	{
		printf("Add was succesful.\n");
	}
	else
	{
		printf("Add was not succesful.\n");
	}

}

void testRemove() {

	printf("Here the remove test works.\n");

	int size = 3;
	Employee* mass = (Employee*)malloc(size * sizeof(Employee));
	for (int i = 0; i < size; i++)
	{
		mass[i] = create();
	}

	int tmpWorkExp0 = mass[0].workExperience;
	int tmpWorkExp2 = mass[2].workExperience;

	size = removeEmployee(mass, size, 1);

	if (tmpWorkExp0 == mass[0].workExperience && tmpWorkExp2 == mass[1].workExperience && size == 2)
	{
		printf("Remove was succesful.\n");
	}
	else
	{
		printf("Remove was not succesful.\n");
	}

}