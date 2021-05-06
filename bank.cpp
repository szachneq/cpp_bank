#include <cstring>
#include <iostream>
#include "bank.h"

Bank::Bank(char *name) {
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
  this->employees = nullptr;
  this->numEmployees = 0;
}

Bank::~Bank() {
	// fire all employees
  Bank::EmployeeNode *m = Bank::employees;
	while (m) {
		m = m->next;
		Bank::employees->employee->setEmployer(nullptr);
		delete Bank::employees;
		Bank::employees = m;
	}
	Bank::employees = nullptr;

  // TODO all accounts closed and money returned to customers !!!

	// deallocate memory
	delete[] this->name;
}

const char *Bank::getName() const {
  return this->name;
}

void Bank::printEmployeeList() {
  Bank::EmployeeNode *current = Bank::employees;

	std::cout << this->getName() << " - Employees:" << std::endl;

	if (current == nullptr) {
		std::cout << "-- there are no employees --" << std::endl;
	}

	while(current != nullptr) {
		std::cout << " - " << current->employee->getId() 
      << ", "<< current->employee->getName() 
      << " " << current->employee->getSurname() 
      << std::endl;
		current = current->next;
	}

	std::cout << std::endl;
}

bool Bank::employ(Employee &employee) {
  if (this->numEmployees >= MAX_EMPLOYEES) return false;
  if (employee.getEmployer() != nullptr) return false;

  employee.setEmployer(this);

  Bank::EmployeeNode *newEmployee = new Bank::EmployeeNode;
  newEmployee->employee = &employee;
  newEmployee->next = Bank::employees;
  Bank::employees = newEmployee;

  this->numEmployees++;
  return true;
}

void Bank::fire(Employee &employee) {
	if (!Bank::employees) return;
  Bank::EmployeeNode *current = Bank::employees;
  Bank::EmployeeNode *prev = nullptr;

  while(current != nullptr) {
		if (current->employee->getId() == employee.getId()) {
			if (prev != nullptr) {
				prev->next = current->next;
			} else {
				Bank::employees = current->next;
			}
			delete current;
      employee.setEmployer(nullptr);
      if (this->numEmployees > 0) this->numEmployees--;
			break;
		}
		prev = current;
		current = current->next;
	}
}
