#pragma once
#include <regex>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::regex;


#define filename "D:\\text.txt"
static regex regMail("^((([A-Z]{1}[0-9A-z\.]{1,}[-]{0,1}[0-9A-Za-z]{1})|([Р-п]{1}[-0-9Р-џ\.]{1,}[-]{0,1}[0-9Р-пр-џ]{1}))@([A-Za-z]{1,}\.){1,2}[-A-Za-z]{2,})");
static regex regName("^([A-Z]{1}[a-z]{1,}[ -,]{0,1}){1,3}");

class Employee
{
private:
	string company;
	string mail;
	string fullName;
	string characteristic;
	int workExperience;
	bool insurance;
public:
	Employee();
	Employee(const string company, const string mail, const string fullName, const string characteristic, const int workExperience, const bool insurance);
	Employee(const Employee& obj);
	~Employee();

	Employee& operator=(const Employee& obj);
	friend bool operator==(const Employee& obj1, const Employee& obj2) {
		return (obj1.workExperience == obj2.workExperience);
	}
	friend bool operator!=(const Employee& obj1, const Employee& obj2) {
		return !(obj1 == obj2);
	}
	friend std::ostream& operator<< (std::ostream& out, const Employee& obj) {
		out << "\nCompany:" << obj.company;
		out << "\nMail:" << obj.mail;
		out << "\nFullname:" << obj.fullName;
		out << "\nCharacteristic:" << obj.characteristic;
		out << "\nWork experience in years:" << obj.workExperience;
		out << "\nInsurance:" << obj.insurance ? "Yes" : "No";
		return out;
	}
	friend std::istream& operator>> (std::istream& in, Employee& obj) {
		in >> obj.company;
		in >> obj.mail;
		in >> obj.fullName;
		in >> obj.characteristic;
		in >> obj.workExperience;
		in >> obj.insurance;

		return in;	 //to do
	}

	string printEmployee();

	void setCompany(string company);
	void setMail(string mail);
	void setFullName(string fullName);
	void setCharac(string charac);
	void setWorkExp(int workExp);
	void setInsurance(bool insurance);

	string getCompany();
	string getMail();
	string getFullName();
	string getCharac();
	int getWorkExp();
	bool getInsurance();
};

class Programmer : public Employee {
private:
	int progLanguage;
	int lvl;
public:
	Programmer() :progLanguage(0), lvl(0) {};
	~Programmer() {};

	int getProgLanguage() { return progLanguage; }
	int getLvl() { return lvl; }

	void setProgLanguage(int l) { progLanguage = l; }
	void setLvl(int s) { lvl = s; }
};

class Translator : public Employee {
private:
	int language;
	bool simultaneous;
public:
	Translator() :language(0), simultaneous(false) {};
	~Translator() {};

	int getLanguage() { return language; }
	bool getSimultaneous() { return simultaneous; }

	void setLanguage(int l) { language = l; }
	void setSimultaneous(bool s) { simultaneous = s; }
};