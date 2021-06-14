#include "List.h"

void List::addEmployee() {
	cout << "Do you want to create a translator or programmer? \n1.Programmer\n2.Translator\nYour choose:";
	int choose = chooseInt(1, 2);
	Employee* p = NULL;
	int digit;
	getchar();

	if (choose == 1) {
		Programmer tmp;
		cout << "\n\nCreate a new Programmer now.\n	Enter full name : ";
		
		tmp.setFullName(check(regName));
		cout << "	Enter mail : ";
		tmp.setMail(check(regMail));
		cout << "	Enter company name : ";
		tmp.setCompany(check(regName));
		cout << "	Describe the positive qualities in 3 words : ";
		tmp.setCharac(check(regName));
		cout << "	Enter work experience in months : ";
		tmp.setWorkExp(chooseInt(0, 480));
		cout << "	Availability of insurance \n1.Yes\n0.No\n\nYour choose : ";
		tmp.setInsurance(chooseInt(0, 1));
		cout << "	Programming level\n1.Junior\n2.Middle\n3.Senior\nYour choose : ";
		tmp.setLvl(chooseInt(1, 3));
		cout << "	Programming language\n1.C++\n2.Java\n3.Python\nYour choose :";
		tmp.setProgLanguage(chooseInt(1, 3));
		p = &tmp;

	}
	else if (choose == 2) {
		Translator tmp;
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
		cout << "	Availability of insurance \n1.Yes\n0.No\n\nYour choose : ";
		tmp.setInsurance(chooseInt(0, 1));
		cout << "	The language used by the translator \n1.English\n2.Ukrainian\n3.German\n\nYour choose :";
		tmp.setLanguage(chooseInt(1, 3));
		cout << "	Does the translator have simultaneous translation \n1.Yes\n0.No\n\nYour choose :";
		tmp.setSimultaneous(chooseInt(0, 1));
		p = &tmp;
	}
	list.push_back(p);
}
void List::removeEmployee(const int index) {
	if (!list.empty()) {
		delete* (list.begin() + index);
		list.erase(list.begin() + index);
	}
}
void List::showAll() {
	for (int i = 0; i < list.size(); i++) {
		
			cout << list[i]->print() << endl;
	}
}
Employee& List::getEmployee(const int index) { return *(list[index]); }
Employee& List::getEmployeeByWorkExp(const int workExp) {
	for (int i = 0; i < list.size(); i++) {
		if (list[i]->getWorkExp() == workExp)
			return *(list[i]);
	}
}

void List::readFromFile() {
	string company;
	string mail;
	string fullName;
	string characteristic;
	int workExperience;
	bool insurance;
	int lvl;
	int progLanguage;
	int language;
	bool sim;

	std::ifstream in(filename);
	if (in.is_open())
	{
		int size = 0;
		int type = 0;
		list.clear();

		in >> size;
		list.reserve(size);
		for (int i = 0; i < size; i++) {
			Employee* p = NULL;
			in >> type;
			if (type == 1) {
				in >> company >> mail >> fullName >> characteristic >> workExperience >> insurance >> lvl >> progLanguage;
				Programmer* tmp=new Programmer(company, mail, fullName, characteristic, workExperience, insurance, lvl, progLanguage);
				p = *(&tmp);
				list.push_back(p);
			}
			else if (type == 2) {
				in >> company >> mail >> fullName >> characteristic >> workExperience >> insurance >> language >> sim;
				Translator* tmp = new Translator(company, mail, fullName, characteristic, workExperience, insurance, language, sim);
				p = *(&tmp);
				list.push_back(p);
			}

		}
		in.close();
	}
}
void List::writeToFile() {
	std::ofstream out(filename);
	if (out.is_open()) {
		out << list.size() << endl;
		for (int i = 0; i < list.size(); i++)
			out << list[i]->whoIAm() << " " << list[i]->getCompany() << " " << list[i]->getMail() << " " << list[i]->getFullName() << " " << list[i]->getCharac() << " " << list[i]->getWorkExp() << " " << list[i]->getInsurance() << endl;
	}
	out.close();
}

int List::getSize() { return list.size(); }
Employee& List::operator[](const int index) {
	return *list[index];
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