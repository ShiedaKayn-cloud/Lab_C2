#pragma once
#include "Employee.h"
typedef struct node {
    struct Employee employer;
    struct node* next;
} node_t;

void print_list(node_t* head);

void push(node_t* head, Employee employer);

void push_start(node_t** head, Employee employer);

void pop(node_t** head);

void remove_last(node_t* head);

void remove_by_index(node_t** head, int n);

int size(node_t* head);

void search_by_insurance(node_t* head);

node_t* sort_by_work_exp(node_t* head);

node_t* read_from_file();

void write_to_file(node_t* head);

node_t* free_list(node_t* dlist);