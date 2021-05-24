#include "List.h"

void menu(node_t* head);

int main() {
	time_t start = time(NULL);

	node_t* head = NULL;
	head = (node_t*)malloc(sizeof(node_t));
	head->employer = create();
	head->next = NULL;

	menu(head);
	head = free_list(head);

#ifdef DEBUG
	time_t end = time(NULL);
	TIME_CHECK(start, end);
	TASK();
#endif
	return 0;
}

void menu(node_t* head) {
	printf("\n\n        A list of employees.Select an action from the following.\n\n");
	printf("1.Write list to screen.\n");
	printf("2.Generate and add employee.\n");
	printf("3.Delete employee by index.\n");
	printf("4.Search for employees with insurance.\n");
	printf("5.Sorted by employee experience.\n");
	printf("6.Reading employees from a file.\n");
	printf("7.Writing employees in file.\n");
	printf("0.Exit.\n\n");
	printf("Your choice: ");

	int choice = -1;
	int size_list;


	while (choice < 0 || choice>7) {
		scanf("%d", &choice);
		if (choice < 0 || choice>7)
			printf("You entered an invalid value, please retry\n\nYour choice: ");
	}
	printf("\n\n");


	switch (choice) {
	case 0: return;
	case 1: print_list(head);
		break;
	case 2: push(head, create());
		break;
	case 3:
		size_list = size(head);
		choice = -1;
		printf("Choose index(0-%d):", size_list);
		while (choice < 0 || choice > size_list) {
			scanf("%d", &choice);
			if (choice < 0 || choice > size_list)
				printf("You entered an index that is larger than the size of the list, please retry\n\nYour choice: ");
		}
		remove_by_index(&head, choice);
		break;
	case 4:	search_by_characteristic(head);
		break;
	case 5: head = sort_by_work_exp(head);
		break;
	case 6: head = read_from_file();
		break;
	case 7: write_to_file(head);
		break;
	}
	printf("Successful.");
	menu(head);
}