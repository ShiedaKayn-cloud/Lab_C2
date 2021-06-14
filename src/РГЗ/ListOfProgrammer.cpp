#include "List.h"

void ListOfProgrammer::addEmployee(Programmer& employee) {
	list.push_back(employee);
}
void ListOfProgrammer::removeEmployee(const int index) {
	if (!list.empty())
		list.erase(list.begin() + index);
}
void ListOfProgrammer::showAll() {
	for (Programmer& emp : list)
		cout << emp.printEmployee() << endl;
}
Programmer& ListOfProgrammer::getEmployee(const int index) { return list[index]; }
Programmer& ListOfProgrammer::getEmployeeByWorkExp(const int workExp) {
	for (Programmer& emp : list) {
		if (emp.getWorkExp() == workExp)
			return emp;
	}
}


int ListOfProgrammer::getSize() { return list.size(); }
Programmer& ListOfProgrammer::operator[](const int index) {
	return list[index];
}
void ListOfProgrammer::addObjects() {
	bool choice = true;
	Programmer tmp;
	int digit;

	while (choice) {
		getchar();
		cout << "\n\nCreate a new employee now.\n	Enter full name : ";
		tmp.setFullName(check(regName));
		cout << "	Enter mail : ";
		tmp.setMail(check(regMail));
		cout << "	Enter company name : ";
		tmp.setCompany(check(regName));
		cout << "	Describe the positive qualities in 3 words : ";
		tmp.setCharac(check(regName));
		cout << "	Enter work experience in months : ";
		tmp.setWorkExp(chooseInt(0, 480));
		cout << "	Availability of insurance \n1.Yes\n2.No\n\nYour choose : ";
		tmp.setInsurance(chooseInt(0, 1));
		cout << "	Programming level\n1.Junior\n2.Middle\n3.Senior\nYour choose : ";
		tmp.setLvl(chooseInt(1, 3));
		cout << "	Programming language\n1.C++\n2.Java\n3.Python\nYour choose :";
		tmp.setProgLanguage(chooseInt(1, 3));

		list.push_back(tmp);
		cout << "A new employee has been added to the list. Would you like to add another one? \n Your choice (1 - yes, 0 - no):";
		cin >> choice;
	}
}

void ListOfProgrammer::getMiddleOnePlus() {
	for (Programmer& emp : list) {
		if (emp.getLvl() == 2 && emp.getWorkExp() >= 12)
			cout << emp.printEmployee() << endl;
	}
}

string ListOfProgrammer::check(regex reg) {
	string word;
	do {
		getline(cin, word);
		if (!std::regex_match(word, reg))
			cout << "\nTry again :";
	} while (!std::regex_match(word, reg));
	return word;
}

int chooseInt(int start, int end) {
	int digit = 0;
	do {
		cin >> digit;
		if (digit >= start && digit <= end) {
			return digit;
		}
		else
			cout << "\nTry again : ";
	} while (true);
}