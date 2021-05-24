#define _CRT_SECURE_NO_WARNINGS
#define SIZE 30
#define filename "D:\\text.txt"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <regex>

using namespace std;

#define TASK()  time_t time1 = time(NULL);\
				printf("Function %s. Time %s ", __func__, ctime(&time1)) 

#define TIME_CHECK(start,end) printf("Program worked for %d seconds\n",(end)-(start))
		  
/*
^( - �������� ��� ����� ���������� � ������ ������
    (
        (  - ���� ���� �������� �� ����� ���������
            [A-Z]{1} - 1� ������ ������ ��������� �����
            [0-9A-z\.]{1,} - � �������� ������� ���� ������ (�����, �����, .) (�� ����� 1 �������)
            [-]{0,1} - � �������� ����� ���� ������ �� ����, ���� ���� 1 ������ -
            [0-9A-Za-z]{1} - ��������� ������ ������ ����� ��� �����
        )
        | - �������� "���/���" �������� ���� "��������" ��� "��������"
        (  - ���� ���� �������� �� ����� ���������
            [�-�]{1} - 1� ������ ������ ��������� �����
            [0-9�-�\.]{1,} - � �������� ������� ���� ������ (�����, �����, .) (�� ����� 1 �������)
            [-]{0,1} - � �������� ����� ���� ������ �� ����, ���� ���� 1 ������ -
            [0-9�-��-�]{1} - ��������� ������ ������ ����� ��� �����
        )
    )
    @ - ������������ ������� ������ ������������ ����� �� ������
    (
        [A-Za-z]{1,} - ���� ����� �������� �� ���� (�� ����� 1 �������)
        \. - ������� ����� � ����� �����
    ){1,2} - ����������� �� 1 �� 2 ������ �� ������������� ����� (mail. , ru.mail.)
    [-A-Za-z]{2,} - ���� ������������ ����� ������� ������ (ru, com, net, aero etc) (�� ����� 2 ��������)
)
*/
static regex pattern("^((([A-Z]{1}[0-9A-z\.]{1,}[-]{0,1}[0-9A-Za-z]{1})|([�-�]{1}[-0-9�-�\.]{1,}[-]{0,1}[0-9�-��-�]{1}))@([A-Za-z]{1,}\.){1,2}[-A-Za-z]{2,})");

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