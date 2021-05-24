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