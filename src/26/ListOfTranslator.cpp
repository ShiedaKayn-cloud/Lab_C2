#include "List.h"

void ListOfTranslator::addEmployee(Translator& employee) {
	list.push_back(employee);
}
void ListOfTranslator::removeEmployee(const int index) {
	if (!list.empty())
		list.erase(list.begin() + index);
}
void ListOfTranslator::showAll() {
	for (Translator& emp : list) 		 //пример foreach
		cout << emp.printEmployee() << endl;
}
Translator& ListOfTranslator::getEmployee(const int index) { return list[index]; }
Translator& ListOfTranslator::getEmployeeByWorkExp(const int workExp) {
	for (Translator& emp : list) {
		if (emp.getWorkExp() == workExp)
			return emp;
	}
}


int ListOfTranslator::getSize() { return list.size(); }


void ListOfTranslator::addObjects() {
	bool choice = true;
	Translator tmp;
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
		cout << "	The language used by the translator \n1.English\n2.Ukrainian\n3.German\n\nYour choose :";
		tmp.setLanguage(chooseInt(1, 3));
		cout << "	Does the translator have simultaneous translation \n1.Yes\n2.No\n\nYour choose :";
		tmp.setSimultaneous(chooseInt(0, 1));

		list.push_back(tmp);
		cout << "A new employee has been added to the list. Would you like to add another one? \n Your choice (1 - yes, 0 - no):";
		cin >> choice;
	}
}

void ListOfTranslator::getSimultaneousFivePlus() {
	for (Translator& emp : list) {
		if (emp.getSimultaneous() && emp.getWorkExp() >= 60)
			cout << emp.printEmployee() << endl;
	}
}

string ListOfTranslator::check(regex reg) {
	string word;
	do {
		getline(cin, word);
		if (!std::regex_match(word, reg))
			cout << "\nTry again :";
	} while (!std::regex_match(word, reg));
	return word;
}

int ListOfTranslator::chooseInt(int start, int end) {
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