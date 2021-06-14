#include "Employee.h"

Employee::Employee() :company("exampleCompany"), mail("exampleMail"),
fullName("exampleName"), characteristic("exampleCharac"), workExperience(0), insurance(1)
{
	cout << "\n\t\tThere was a DEFAULT constructor here\n";
}

Employee::Employee(const string company, const string mail, const string fullName, const string characteristic, const int workExperience, const bool insurance) :
	company(company), mail(mail), fullName(fullName), characteristic(characteristic), workExperience(workExperience), insurance(insurance)
{
	cout << "\n\t\tHere was a constructor with PARAMETRS\n";
}

Employee::Employee(const Employee& obj) :company(obj.company), mail(obj.mail), fullName(obj.fullName),
characteristic(obj.characteristic), workExperience(obj.workExperience), insurance(obj.insurance)
{
	cout << "\n\t\tThere was a COPY constructor here\n";
}

Employee::~Employee() {
	cout << "\n\t\tThere was DESTRUCTOR here\n";
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

string Employee::printEmployee() {
	std::stringstream ss;
	ss << "\nCompany:" << company;
	ss << "\nMail:" << mail;
	ss << "\nFullname:" << fullName;
	ss << "\nCharacteristic:" << characteristic;
	ss << "\nWork experience in years:" << workExperience;
	ss << "\nInsurance:" << insurance ? "Yes" : "No";
	
	return ss.str();
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