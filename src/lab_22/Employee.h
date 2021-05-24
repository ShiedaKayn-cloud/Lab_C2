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
^( - параметр что маска начинается с начала текста
    (
        (  - этот блок отвечает за логин латиницей
            [A-Z]{1} - 1й символ только заглавная буква
            [0-9A-z\.]{1,} - в середине минимум один символ (буква, цифра, .) (не менее 1 символа)
            [-]{0,1} - в середине может либо вообще не быть, либо быть 1 символ -
            [0-9A-Za-z]{1} - последний символ только цифра или буква
        )
        | - параметр "или/или" выбирает блок "латиница" или "кирилица"
        (  - этот блок отвечает за логин кирилицей
            [А-Я]{1} - 1й символ только заглавная буква
            [0-9А-я\.]{1,} - в середине минимум один символ (буква, цифра, .) (не менее 1 символа)
            [-]{0,1} - в середине может либо вообще не быть, либо быть 1 символ -
            [0-9А-Яа-я]{1} - последний символ только цифра или буква
        )
    )
    @ - обазятельное наличие значка разделяющего логин от домена
    (
        [A-Za-z]{1,} - блок может состоять из букв (не менее 1 символа)
        \. - наличие точки в конце блока
    ){1,2} - допускается от 1 до 2 блоков по вышеукащанной маске (mail. , ru.mail.)
    [-A-Za-z]{2,} - блок описывайющий домен вехнего уровня (ru, com, net, aero etc) (не менее 2 символов)
)
*/
static regex pattern("^((([A-Z]{1}[0-9A-z\.]{1,}[-]{0,1}[0-9A-Za-z]{1})|([А-Я]{1}[-0-9А-я\.]{1,}[-]{0,1}[0-9А-Яа-я]{1}))@([A-Za-z]{1,}\.){1,2}[-A-Za-z]{2,})");

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