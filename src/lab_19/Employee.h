#define _CRT_SECURE_NO_WARNINGS
#define SIZE 30
#define filename "D:\\text.txt"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Employee {
	char company[SIZE];
	char mail[SIZE];
	char fullName[SIZE];
	char characteristic[SIZE];
	int workExperience;
	bool insurance;
};

void fwrite(struct Employee employee);
Employee create(char* company, char* mail, char* fullName, char* characteristic, int workExperience, bool insurance);
void print(struct Employee);
Employee create();
char* createMail();