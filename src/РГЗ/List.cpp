#include "List.h"

void List::addEmployee() {
	cout << "Do you want to create a translator or programmer? \n1.Programmer\n2.Translator\nYour choose:";
	int choose = chooseInt(1, 2);
	Employee* p = NULL;
	int digit;
	getchar();

	if (choose == 1) {
		Programmer* tmp=new Programmer();
		cout << "\n\nCreate a new Programmer now.\n	Enter full name : ";

		tmp->setFullName(check(regName));
		cout << "	Enter mail : ";
		tmp->setMail(check(regMail));
		cout << "	Enter company name : ";
		tmp->setCompany(check(regName));
		cout << "	Describe the positive qualities in 3 words : ";
		tmp->setCharac(check(regName));
		cout << "	Enter work experience in months : ";
		tmp->setWorkExp(chooseInt(0, 480));
		cout << "	Availability of insurance \n1.Yes\n0.No\n\nYour choose : ";
		tmp->setInsurance(chooseInt(0, 1));
		cout << "	Programming level\n1.Junior\n2.Middle\n3.Senior\nYour choose : ";
		tmp->setLvl(chooseInt(1, 3));
		cout << "	Programming language\n1.C++\n2.Java\n3.Python\nYour choose :";
		tmp->setProgLanguage(chooseInt(1, 3));
		p = tmp;

	}
	else if (choose == 2) {
		Translator* tmp= new Translator();
		cout << "\n\nCreate a new employee now.\n	Enter full name : ";
		tmp->setFullName(check(regName));
		cout << "	Enter mail : ";
		tmp->setMail(check(regMail));
		cout << "	Enter company name : ";
		tmp->setCompany(check(regName));
		cout << "	Describe the positive qualities in 3 words : ";
		tmp->setCharac(check(regName));
		cout << "	Enter work experience in months : ";
		tmp->setWorkExp(chooseInt(0, 480));
		cout << "	Availability of insurance \n1.Yes\n0.No\n\nYour choose : ";
		tmp->setInsurance(chooseInt(0, 1));
		cout << "	The language used by the translator \n1.English\n2.Ukrainian\n3.German\n\nYour choose :";
		tmp->setLanguage(chooseInt(1, 3));
		cout << "	Does the translator have simultaneous translation \n1.Yes\n0.No\n\nYour choose :";
		tmp->setSimultaneous(chooseInt(0, 1));
		p = tmp;
	}
	list.push_back(p);
}
void List::removeEmployee(const int index) {
	if (!list.empty()) {
		delete* (list.begin() + index);
		list.erase(list.begin() + index);
	}
}
void List::setEmployee(const int index) {
	int choice = 0, type = 0;
	type = list[index]->whoIAm();

	cout << "Your Employee:\n\n";
	cout << list[index]->print() << endl;
	cout << "What do u want to change?\n1.Name\n2.Mail\n3.Company\n4.Characteristic\n5.Work exp\n6.Insurance\n";
	//if (type == 1)
	//	cout << "7.Lvl of Programming\n8.Programming language\n";
	//else
	//	cout << "7.Language\n8.Simultaneous\n";

	cout << "Your choise(1-8): ";
	choice = chooseInt(1, 8);

	switch (choice)
	{
	case 1:
		list[index]->setFullName(check(regName));
		break;
	case 2:
		list[index]->setMail(check(regMail));
		break;
	case 3:
		list[index]->setCompany(check(regName));
		break;
	case 4:
		list[index]->setCharac(check(regName));
		break;
	case 5:
		list[index]->setWorkExp(chooseInt(0, 480));
		break;
	case 6:
		list[index]->setInsurance(!list[index]->getInsurance());
		break;
		/*case 7:
			if(type==1)
				list[index].set
			break;
		case 8:
			break;*/
	}
}
void List::clear() {
	if (!list.empty()) {
		for (int i = list.size(); i > 0; i--) {
			removeEmployee(i - 1);
		}
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

void List::sortByWorkExp() {
	cout << "\nSelect sorting type: \n1. Ascending \n2. Descending \n	Your choose:";
	int type = chooseInt(1, 2);

	if (type == 1) {
		std::sort(list.begin(), list.end());
	}
	else {
		std::sort(list.begin(), list.end());
		std::reverse(list.begin(), list.end());
	}
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
int List::chooseInt(const int start, const int end) {
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
				Programmer* tmp = new Programmer(company, mail, fullName, characteristic, workExperience, insurance, lvl, progLanguage);
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