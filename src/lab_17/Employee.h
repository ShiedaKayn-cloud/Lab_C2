#define _CRT_SECURE_NO_WARNINGS
#define SIZE 30
#define filename "C:\\Users\\User\\source\\repos\\lab_15\\lab_15\\test.txt"
#define filenameB "C:\\Users\\User\\source\\repos\\lab_15\\lab_15\\testB.dat"

using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
	char company[SIZE];
	char mail[SIZE];
	char fullName[SIZE];
	char characteristic[SIZE];
	int workExperience;
	bool insurance;
};

int fread(struct Employee*, int);
void fwrite(struct Employee*, int);
void write(struct Employee*, int);
void sort(struct Employee*, int);
Employee create();
Employee freadB();
void fwriteB(struct Employee*, int);
char* createMail();