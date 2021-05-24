#include "List.h"

void print_list(node_t* head) {

	node_t* current = head;

	while (current != NULL) {
		print(current->employer);
		current = current->next;
	}
}

void push(node_t* head, Employee employer) {

	node_t* current = head;

	while (current->next != NULL) {
		current = current->next;
	}

	current->next = (node_t*)malloc(sizeof(node_t));
	current->next->employer = employer;
	current->next->next = NULL;
}

void push_start(node_t** head, Employee employer) {

	node_t* new_node;
	new_node = (node_t*)malloc(sizeof(node_t));

	new_node->employer = employer;
	new_node->next = *head;
	*head = new_node;
}

void pop(node_t** head) {

	node_t* next_node = NULL;

	if (*head == NULL) {
		return;
	}

	next_node = (*head)->next;
	free(*head);
	*head = next_node;

	return;
}

void remove_last(node_t* head) {

	/* if there is only one item in the list, remove it */
	if (head->next == NULL) {
		free(head);
		return;
	}

	/* get to the last node in the list */
	node_t* current = head;
	while (current->next->next != NULL) {
		current = current->next;
	}

	/* now current points to the last item of the list, so let's remove current->next */
	free(current->next);
	current->next = NULL;
	return;
}

void remove_by_index(node_t** head, int n) {

	int i = 0;

	node_t* current = *head;
	node_t* temp_node = NULL;

	if (n == 0) {
		pop(head);
		return;
	}

	for (int i = 0; i < n - 1; i++) {
		if (current->next == NULL) {
			return;
		}
		current = current->next;
	}

	temp_node = current->next;
	current->next = temp_node->next;
	free(temp_node);

	return;
}

node_t* read_from_file() {
	FILE* f = fopen(filename, "r");

	//фокус называется по гнидски XD
	struct Employee employee;
	node_t* head = NULL;
	head = (node_t*)malloc(sizeof(node_t));
	head->employer = create();
	head->next = NULL;

	while (fscanf(f, "%s\n%s\n%s\n%s\n%d\n%d\n", employee.company, employee.mail, employee.fullName, employee.characteristic, &employee.workExperience, &employee.insurance) != EOF) {
		
		print(employee);
		push(head, employee);
	}
	pop(&head);
	fclose(f);
	return head;
}

void write_to_file(node_t* head) {

	node_t* current = head;
	FILE* file;
	file = fopen(filename, "w");
	fprintf(file, "");
	fclose(file);
	while (current != NULL) {
		fwrite(current->employer);		
		current = current->next;
	}
}

int size(node_t* head) {
	node_t* current = head;
	int count = 0;

	while (current->next != NULL) {
		current = current->next;
		count++;
	}

	return count;
}

void search_by_insurance(node_t* head) {
	node_t* current = head;

	while (current->next != NULL) {
		if (current->employer.insurance == true)
			print(current->employer);
		current = current->next;
	}
}

void search_by_characteristic(node_t* head) {
	node_t* current = head;

	while (current->next != NULL) {
		if (regex_search(current->employer.characteristic, regex("(_)+")))
			print(current->employer);
		current = current->next;
	}
}

node_t* sort_by_work_exp(node_t* head) {
	node_t* tmp = NULL;

	while (head != NULL) {
		node_t* node = head;
		head = head->next;

		if (tmp == NULL || node->employer.workExperience < tmp->employer.workExperience)
		{
			node->next = tmp;
			tmp = node;
		}
		else
		{
			node_t* current = tmp;
			while (current->next != NULL && !(node->employer.workExperience < current->next->employer.workExperience))
			{
				current = current->next;
			}

			node->next = current->next;
			current->next = node;
		}
	}
	return tmp;
}

node_t* free_list(node_t* dlist)
{
	node_t* current = dlist->next;

	while (current != NULL)
	{
		node_t* tmp = current;
		current = current->next;

		free(tmp);
	}

	dlist->next = nullptr;

	return dlist;
}