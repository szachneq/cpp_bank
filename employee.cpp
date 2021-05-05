#include <cstring>
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

const char *Employee::getName() {
	return this->name;
}

const char *Employee::getSurname() {
	return this->surname;
}

const int Employee::getId() {
	return this->id;
}

const Bank *Employee::getEmployer() {
	return this->employer;
}

const char *Employee::getEmployerName() {
	return (this->getEmployer() != nullptr) ? this->getEmployer()->getName() : "unemployed";
}

void Employee::setEmployer(Bank *bank) {
	if (bank != nullptr) {
		this->employer = bank;
	}
}

bool Employee::join(Bank &bank) {
	return bank.employ(*this);
}

void Employee::leave() {
	this->employer->fire(*this);
	this->employer = nullptr;
}
