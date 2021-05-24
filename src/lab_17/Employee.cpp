#define _CRT_SECURE_NO_WARNINGS
#include "Employee.h"

int fread(struct Employee* employee, int size) {
	FILE* file;
	file = fopen(filename, "r");
	int i = 0;
	int fileSize;
	fscanf(file, "%d\n", &fileSize);
	if (fileSize >= size) {
		while (i < size) {
			fgets(employee[i].company, SIZE, file);
			fgets(employee[i].mail, SIZE, file);
			fgets(employee[i].fullName, SIZE, file);
			fgets(employee[i].characteristic, SIZE, file);
			fscanf(file, "%d\n", &employee[i].workExperience);
			fscanf(file, "%d\n", &employee[i].insurance);
			i++;
		}
		fclose(file);
		return size;
	}
	else {
		printf("The number of objects in the file does not match the request. %d objects will be read.\n", fileSize);
		while (i < fileSize) {
			fgets(employee[i].company, SIZE, file);
			fgets(employee[i].mail, SIZE, file);
			fgets(employee[i].fullName, SIZE, file);
			fgets(employee[i].characteristic, SIZE, file);
			fscanf(file, "%d\n", &employee[i].workExperience);
			fscanf(file, "%d\n", &employee[i].insurance);
			i++;
		}
		fclose(file);
		return fileSize;
	}
}
void fwrite(struct Employee* employee, int size) {
	FILE* file;
	file = fopen(filename, "w");

	fprintf(file, "%d\n", size);
	for (int i = 0; i < size; i++) {
		fprintf(file, employee[i].company);
		fprintf(file, employee[i].mail);
		fprintf(file, employee[i].fullName);
		fprintf(file, employee[i].characteristic);
		fprintf(file, "%d\n", employee[i].workExperience);
		fprintf(file, "%d\n", employee[i].insurance);
	}

	fclose(file);
}
void write(struct Employee* employee, int size) {
	for (int i = 0; i < size; i++) {
		printf("Company:%s", employee[i].company);
		printf("Mail:%s", employee[i].mail);
		printf("Fullname:%s", employee[i].fullName);
		printf("Characteristic:%s", employee[i].characteristic);
		printf("Work experience in years:%d\n", employee[i].workExperience);
		printf("insurance:%s\n\n", employee[i].insurance ? "Yes" : "No");
	}
}
void sort(struct Employee* employee, int size) {
	struct Employee tmp;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1; j++) {
			if (employee[j].workExperience > employee[j + 1].workExperience) {
				tmp = employee[j];
				employee[j] = employee[j + 1];
				employee[j + 1] = tmp;
			}
		}
	}
}
Employee create() {
	Employee employee;
	strcpy(employee.company, "example\n");
	strcpy(employee.mail, createMail());
	strcpy(employee.fullName, "example\n");
	strcpy(employee.characteristic, "example\n");
	employee.workExperience = rand() % 18 + 10;
	employee.insurance = rand() % 2;

	return employee;
}

void fwriteB(struct Employee* employee, int size) {
	FILE* file;
	file = fopen(filenameB, "wb");
	for (int i = 0; i < size; i++)
		fwrite(&employee, sizeof(Employee), 1, file);

	fclose(file);
}

//void fwriteB(struct Employee* employee, int size) {
//    int n;
//    for (int i = 0; i < size; i++) {
//        writeB(employee[i].name, n = sizeof(employee[i].name) / sizeof(' '));
//        writeB(employee[i].patronymic, n = sizeof(employee[i].patronymic) / sizeof(' '));
//        writeB(employee[i].surname, n = sizeof(employee[i].surname) / sizeof(' '));
//        writeB(employee[i].data, n = sizeof(employee[i].data) / sizeof(' '));
//        char tmp[SIZE];
//        sprintf(tmp, "%d", employee[i].workExperienceInMonth);
//        writeB(tmp, n = sizeof(employee[i].workExperienceInMonth) / sizeof(' '));        
//        char tmp1[SIZE];
//        sprintf(tmp1, "%d", employee[i].salary);
//        writeB(tmp1, n = sizeof(employee[i].salary) / sizeof(' '));
//        writeB(employee[i].post, n = sizeof(employee[i].post) / sizeof(' '));       
//        char tmp2[SIZE];
//        sprintf(tmp2, "%d", employee[i].lecturer);
//        writeB(tmp2, n = sizeof(employee[i].lecturer) / sizeof(' '));
//    }
//}
//int writeB(char message[], int size)
//{
//    FILE* fp;
//    if ((fp = fopen(filenameB, "w")) == NULL)
//    {
//        perror("Error occured while opening file");
//        return 1;
//    }
//    for (int i = 0; i < size; i++)
//    {
//X           putc(message[i], fp);
//    }
//
//    fclose(fp);
//    return 0;
//}
//
Employee freadB()
{
	struct Employee employee;
	FILE* file;
	file = fopen(filenameB, "rb");
	fread(&employee, sizeof(Employee), 1, file);

	fclose(file);
	return employee;
}

char* createMail() {
	char start[9] = "rabotnik";
	char domen[11] = "gmail.com\n";
	char mail[22] = "";
	strcat(mail, start);
	char number[4] = "";
	sprintf(number, "%d", rand() % 900 + 100);
	strcat(mail, number);
	strcat(mail, domen);

	return mail;
}