#include "Employee.h"

Employee::Employee() :company("exampleCompany"), mail("exampleMail"),
fullName("exampleName"), characteristic("exampleCharac"), workExperience(0), insurance(1)
{
	/*cout << "\n\t\tThere was a DEFAULT constructor here\n";*/
}

Employee::Employee(const string company, const string mail, const string fullName, const string characteristic, const int workExperience, const bool insurance) :
	company(company), mail(mail), fullName(fullName), characteristic(characteristic), workExperience(workExperience), insurance(insurance)
{
	/*cout << "\n\t\tHere was a constructor with PARAMETRS\n";*/
}

Employee::Employee(const Employee& obj) :company(obj.company), mail(obj.mail), fullName(obj.fullName),
characteristic(obj.characteristic), workExperience(obj.workExperience), insurance(obj.insurance)
{
	//cout << "\n\t\tThere was a COPY constructor here\n";
}

Employee& Employee::operator= (const Employee& obj) {
	characteristic = obj.characteristic;
	workExperience = obj.workExperience;
	insurance = obj.insurance;
	fullName = obj.fullName;
	company = obj.company;
	mail = obj.mail;

	return *this;
}

string Translator::print() {
	std::stringstream ss;
	ss << "\nCompany:" << company;
	ss << "\nMail:" << mail;
	ss << "\nFullname:" << fullName;
	ss << "\nCharacteristic:" << characteristic;
	ss << "\nWork experience in years:" << workExperience;
	ss << "\nInsurance:" << insurance ? "Yes" : "No";
	ss << "\nThe language used by the translator:";
	switch (language)
	{
	case 1:
		ss << "English";
		break;
	case 2:
		ss << "Ukrainian";
		break;
	case 3:
		ss << "German";
		break;
	}
	ss << "\nSimultaneous : "<<(simultaneous ? "Yes" : "No");

	return ss.str();
}
string Programmer::print() {
	std::stringstream ss;
	ss << "\nCompany:" << company;
	ss << "\nMail:" << mail;
	ss << "\nFullname:" << fullName;
	ss << "\nCharacteristic:" << characteristic;
	ss << "\nWork experience in years:" << workExperience;
	ss << "\nInsurance:" << insurance ? "Yes" : "No";
	ss << "\nLvl:";
	switch (lvl)
	{
	case 1:ss << "Junior"; break;
	case 2:ss << "Middle"; break;
	case 3:ss << "Senior"; break;
	}
	ss << "\nProgramming language :";
	switch (progLanguage)
	{
	case 1:ss << "C++"; break;
	case 2:ss << "Java"; break;
	case 3:ss << "Python"; break;
	}

	return ss.str();
}

int Translator::whoIAm() { return 2; };
int Programmer::whoIAm() { return 1; };

Translator::Translator(string company, string mail, string fullName, string characteristic, int workExperience, bool insurance, int language, bool sim) {
	setCompany(company);
	setMail(mail);
	setFullName(fullName);
	setCharac(characteristic);
	setWorkExp(workExperience);
	setInsurance(insurance);
	setLanguage(language);
	setSimultaneous(sim);
}

Programmer::Programmer(string company, string mail, string fullName, string characteristic, int workExperience, bool insurance, int lvl, int progLanguage) {
	setCompany(company);
	setMail(mail);
	setFullName(fullName);
	setCharac(characteristic);
	setWorkExp(workExperience);
	setInsurance(insurance);
	setLvl(lvl);
	setProgLanguage(progLanguage);
}


void Employee::setCompany(string company) { this->company = company; }
void Employee::setMail(string mail) { this->mail = mail; }
void Employee::setFullName(string fullName) { this->fullName = fullName; }
void Employee::setCharac(string charac) { this->characteristic = charac; }
void Employee::setWorkExp(int workExp) { this->workExperience = workExp; }
void Employee::setInsurance(bool insurance) { this->insurance = insurance; }
 
string Employee::getCompany() { return company; }
string Employee::getMail() { return mail; }
string Employee::getFullName() { return fullName; }
string Employee::getCharac() { return characteristic; }
int Employee::getWorkExp() { return workExperience; }
bool Employee::getInsurance() { return insurance; }