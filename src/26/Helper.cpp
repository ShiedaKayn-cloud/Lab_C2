#include "Helper.h"


void Helper::menu(List& list) {
	cout << "\n\n        A list of employees.Select an action from the following.\n\n";
	cout << "1.Write list to screen.\n";
	cout << "2.Generate and add employee.\n";
	cout << "3.Delete employee by index.\n";
	cout << "4.Search for employees with insurance.\n";
	cout << "5.Reading employees from a file.\n";
	cout << "6.Writing employees in file.\n";
	cout << "0.Exit.\n\n";
	cout << "Your choice: ";

	int choice = -1;

	while (choice < 0 || choice>7) {
		cin >> choice;
		if (choice < 0 || choice>7)
			cout << "You entered an invalid value, please retry\n\nYour choice: ";
	}
	cout << endl << endl;

	switch (choice) {
	case 0: return;
	case 1:
		list.showAll();
		break;
	case 2:
		list.addObjects();
		break;
	case 3:
		choice = -1;
		cout<<"Choose index(0-"<< list.getSize()<<"):";
		while (choice < 0 || choice > list.getSize()) {
			cin >> choice;
			if (choice < 0 || choice > list.getSize())
				cout << "You entered an index that is larger than the size of the list, please retry\n\nYour choice: ";
		}
		list.removeEmployee(choice-1);
		break;
	case 4:
		cout << list.getEmployeeByWorkExp(10).printEmployee();
		break;
	case 5:
		list.readFromFile();
		break;
	case 6:
		list.writeToFile();
		break;
	}
	cout<<"\n\nSuccessful.";
	menu(list);
}

