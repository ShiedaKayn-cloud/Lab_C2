#include "Helper.h"


void Helper::menu(List& list) {
	cout << "\n\n        A list of employees.Select an action from the following.\n\n";
	cout << "1.Write list to screen.\n";
	cout << "2.Generate and add employee.\n";
	cout << "3.Delete employee by index.\n";
	cout << "4.Search for employees with insurance.\n";
	cout << "5.Change info about employee\n";
	cout << "6.Sort by work exp\n";
	cout << "7.Reading employees from a file.\n";
	cout << "8.Writing employees in file.\n";
	cout << "0.Exit.\n\n";
	cout << "Your choice: ";

	int choice = -1;

	while (choice < 0 || choice > 9) {
		cin >> choice;
		if (choice < 0 || choice > 9)
			cout << "You entered an invalid value, please retry\n\nYour choice: ";
	}
	cout << endl << endl;

	switch (choice) {
	case 0:
		list.clear();
		return;
	case 1:
		list.showAll();
		break;
	case 2:
		list.addEmployee();
		break;
	case 3:
		choice = 0;
		cout << "Choose index(1-" << list.getSize() << "):";
		while (choice <= 0 || choice > list.getSize()) {
			cin >> choice;
			if (choice < 0 || choice > list.getSize())
				cout << "You entered an index that is larger than the size of the list, please retry\n\nYour choice: ";
		}
		list.removeEmployee(choice - 1);
		break;
	case 4:
		cout << list.getEmployeeByWorkExp(31).print();
		break;
	case 5:
		choice = 0;
		cout << "Choose index(1-" << list.getSize() << "):";
		while (choice <= 0 || choice > list.getSize()) {
			cin >> choice;
			if (choice < 0 || choice > list.getSize())
				cout << "You entered an index that is larger than the size of the list, please retry\n\nYour choice: ";
		}
		list.setEmployee(choice - 1);
		break;
	case 6:
		list.sortByWorkExp();
		break;
	case 7:
		list.readFromFile();
		break;
	case 8:
		list.writeToFile();
		break;
	}
	cout << "\n\nSuccessful.";
	menu(list);
}

