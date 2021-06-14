#pragma once
#include <regex>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>  

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
public:
	string fullName;
	string company;
	string mail;	
	string characteristic;
	int workExperience;
	bool insurance;


	Employee();
	Employee(const string company, const string mail, const string fullName, const string characteristic, const int workExperience, const bool insurance);
	Employee(const Employee& obj);
	virtual ~Employee() = 0 {};

	virtual string print() = 0;
	virtual int whoIAm() = 0;

	Employee& operator=(const Employee& obj);
	friend bool operator==(const Employee& obj1, const Employee& obj2) {
		return (obj1.workExperience == obj2.workExperience);
	}
	friend bool operator>(const Employee& obj1, const Employee& obj2) {
		return (obj1.workExperience > obj2.workExperience);
	}
	friend bool operator<(const Employee& obj1, const Employee& obj2) {
		return (obj1.workExperience < obj2.workExperience);
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
	Programmer(string company, string mail, string fullName, string characteristic, int workExperience, bool insurance, int lvl, int progLanguage);
	~Programmer() {}

	friend std::ostream& operator<< (std::ostream& out, const Programmer& obj) {

		out << "\nCompany:" << obj.company;
		out << "\nMail:" << obj.mail;
		out << "\nFullname:" << obj.fullName;
		out << "\nCharacteristic:" << obj.characteristic;
		out << "\nWork experience in years:" << obj.workExperience;
		out << "\nInsurance:" << obj.insurance ? "Yes" : "No";
		out << "\nLvl:";
		switch (obj.lvl)
		{
		case 1:out << "Junior"; break;
		case 2:out << "Middle"; break;
		case 3:out << "Senior"; break;
		}
		out << "\nProgramming language :";
		switch (obj.progLanguage)
		{
		case 1:out << "C++"; break;
		case 2:out << "Java"; break;
		case 3:out << "Python"; break;
		}

		return out;
	}
	friend std::istream& operator>> (std::istream& in, Programmer& obj) {
		in >> obj.company >> obj.mail >> obj.fullName >> obj.characteristic
			>> obj.workExperience >> obj.insurance >> obj.lvl >> obj.progLanguage;
		return in;	 //to do
	}
	friend bool operator==(const Programmer& obj1, const Programmer& obj2) {
		return (obj1.workExperience == obj2.workExperience && obj1.lvl == obj2.lvl);
	}

	virtual string print()override final;
	virtual int whoIAm()override final;

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
	Translator(string company, string mail, string fullName, string characteristic, int workExperience, bool insurance, int language, bool sim);
	~Translator() {};

	friend std::ostream& operator<< (std::ostream& out, const Translator& obj) {

		out << "\nCompany:" << obj.company;
		out << "\nMail:" << obj.mail;
		out << "\nFullname:" << obj.fullName;
		out << "\nCharacteristic:" << obj.characteristic;
		out << "\nWork experience in years:" << obj.workExperience;
		out << "\nInsurance:" << obj.insurance ? "Yes" : "No";
		out << "\nThe language used by the translator:";
		switch (obj.language)
		{
		case 1:
			out << "English";
			break;
		case 2:
			out << "Ukrainian";
			break;
		case 3:
			out << "German";
			break;
		}
		out << "\nSimultaneous : " << (obj.simultaneous ? "Yes" : "No");

		return out;
	}
	friend std::istream& operator>> (std::istream& in, Translator& obj) {
		in >> obj.company >> obj.mail >> obj.fullName >> obj.characteristic >> obj.workExperience
			>> obj.insurance >> obj.language >> obj.simultaneous;
		return in;	 //to do
	}
	friend bool operator==(const Translator& obj1, const Translator& obj2) {
		return (obj1.workExperience == obj2.workExperience && obj1.language == obj2.language
			&& obj1.simultaneous == obj2.simultaneous);
	}

	virtual string print()override final;
	virtual int whoIAm()override final;

	int getLanguage() { return language; }
	bool getSimultaneous() { return simultaneous; }

	void setLanguage(int l) { language = l; }
	void setSimultaneous(bool s) { simultaneous = s; }
};