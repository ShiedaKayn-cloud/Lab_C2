#include "List.h"

void List::addEmployee(Employee& employee) {
	list.push_back(employee);
}
void List::removeEmployee(const int index) {
	if (!list.empty())
		list.erase(list.begin() + index);
}
void List::showAll() {
	for (Employee& emp : list) 		 //пример foreach
		cout << emp.printEmployee() << endl;
}
Employee& List::getEmployee(const int index) { return list[index]; }
Employee& List::getEmployeeByWorkExp(const int workExp) {
	for (Employee& emp : list) {
		if (emp.getWorkExp() == workExp)
			return emp;
	}
}

void List::readFromFile() {
	string company;
	string mail;
	string fullName;
	string characteristic;
	int workExperience;
	bool insurance;

	std::ifstream in(filename);
	if (in.is_open())
	{
		list.clear();
		while (in >> company >> mail >> fullName >> characteristic >> workExperience >> insurance)
			list.push_back(Employee(company, mail, fullName, characteristic, workExperience, insurance));
	}
	in.close();
}
void List::writeToFile() {
	std::ofstream out(filename);
	if (out.is_open()) {
		for (int i = 0; i < list.size(); i++)
			out << list[i].getCompany() << " " << list[i].getMail() << " " << list[i].getFullName() << " " << list[i].getCharac() << " " << list[i].getWorkExp() << " " << list[i].getInsurance() << endl;
	}
	out.close();
}

int List::getSize() { return list.size(); }
Employee& List::operator[](const int index) {
	return list[index];
}
void List::addObjects() {
	bool choice = true;
	Employee tmp;
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
		list.push_back(tmp);
		cout << "A new employee has been added to the list. Would you like to add another one? \n Your choice (1 - yes, 0 - no):";
		cin >> choice;
	}
}

string List::check(regex reg) {
	string word;
	do {
		getline(cin, word);
		if (!std::regex_match(word, reg))
			cout << "\nTry again :";
	} while (!std::regex_match(word, reg));
	return word;
}
int List::chooseInt(int start, int end) {
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