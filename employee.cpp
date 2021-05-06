#include <cstring>
#include <iostream>
#include "employee.h"

int Employee::numCreated = 0;

Employee::Employee(char *name, char *surname) {
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->surname = new char[strlen(surname) + 1];
	strcpy(this->surname, surname);
	this->employer = nullptr;
	this->id = Employee::numCreated + 1;
	Employee::numCreated += 1;
}

Employee::~Employee() {
	this->leave();
	delete[] this->name;
	delete[] this->surname;
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
	this->employer = bank;
}

bool Employee::join(Bank &bank) {
	return bank.employ(*this);
}

void Employee::leave() {
	if (this->employer) {
	this->employer->fire(*this);
	}
}
