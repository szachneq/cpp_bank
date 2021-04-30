#include <string.h>
#include "employee.h"

int Employee::numCreated = 0;

Employee::Employee(char *name, char *surname) {
	this->name = new char[strlen(name)];
	strcpy(this->name, name);
	this->surname = new char[strlen(surname)];
	strcpy(this->surname, surname);
	this->employer = nullptr;
	this->id = Employee::numCreated + 1;
	Employee::numCreated += 1;
}

Employee::~Employee() {
	delete[] this->name;
	delete[] this->surname;
	// TODO - add a call to function on the employers side
	// something like employer->removeEmployee(this);
}

bool Employee::join(const Bank &bank) {
	return false;
}

void Employee::leave() {
	// TODO - add a call to function on the employers side
	// something like employer->removeEmployee(this);
	this->employer = nullptr;
}