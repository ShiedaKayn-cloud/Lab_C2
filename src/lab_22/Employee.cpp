#include "Employee.h"

void fwrite(struct Employee employee) {
	FILE* file;
	file = fopen(filename, "a");
		fprintf(file, employee.company);
		fprintf(file, "\n");
		fprintf(file, employee.mail);
		fprintf(file, "\n");
		fprintf(file, employee.fullName);
		fprintf(file, "\n");
		fprintf(file, employee.characteristic);
		fprintf(file, "\n");
		fprintf(file, "%d\n", employee.workExperience);
		fprintf(file, "%d\n", employee.insurance);
	fclose(file);
}
void print(struct Employee employee) {
		printf("Company:%s\n", employee.company);
		printf("Mail:%s\n", employee.mail);
		printf("Fullname:%s\n", employee.fullName);
		printf("Characteristic:%s\n", employee.characteristic);
		printf("Work experience in years:%d\n", employee.workExperience);
		printf("insurance:%s\n\n", employee.insurance ? "Yes" : "No");
}
Employee create() {
	Employee employee;
	strcpy(employee.company, "example");
	strcpy(employee.mail, createMail());
	strcpy(employee.fullName, "example");
	strcpy(employee.characteristic, "example");
	employee.workExperience = rand() % 18 + 10;
	employee.insurance = rand() % 2;

	return employee;
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

char* createMail() {
	char start[9] = "rabotnik";
	char domen[11] = "gmail.com";
	char mail[22] = "";
	strcat(mail, start);
	char number[4] = "";
	sprintf(number, "%d", rand() % 900 + 100);
	strcat(mail, number);
	strcat(mail, domen);

	return mail;
}
Employee create(char* company, char* mail, char* fullName, char* characteristic, int workExperience, bool insurance) {
	Employee employee;
	strcpy(employee.company, company);
	strcpy(employee.mail, mail);
	strcpy(employee.fullName, fullName);
	strcpy(employee.characteristic, characteristic);
	employee.workExperience = workExperience;
	employee.insurance = insurance;

	return employee;
}