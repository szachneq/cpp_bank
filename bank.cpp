#include <cstring>
#include <iostream>
#include "bank.h"

// Account *Bank::findAccount(Customer &customer) {
// 	Bank::AccountNode *current = this->accounts;
// 	while(current != nullptr) {
// 		if (current->account->getCustomer()->getId() == customer.getId()) {
// 			return current->account;
// 		}
// 		current = current->next;
// 	}
// 	return nullptr;
// }

Bank::Bank(char *name) {
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
  this->employees = nullptr;
  this->accounts = nullptr;
  this->numEmployees = 0;
}

Bank::~Bank() {
	// return all money and close accounts
	Bank::AccountNode *m = Bank::accounts;
	while (m) {
		m = m->next;
		Bank::accounts->account->getCustomer()->closeAccount(*this);
		delete Bank::accounts;
		Bank::accounts = m;
	}

	// fire all employees
  Bank::EmployeeNode *e = Bank::employees;
	while (e) {
		e = e->next;
		Bank::employees->employee->setEmployer(nullptr);
		delete Bank::employees;
		Bank::employees = e;
	}
	this->employees = nullptr;
	this->accounts = nullptr;

	// deallocate memory
	delete[] this->name;
}

const char *Bank::getName() const {
  return this->name;
}

void Bank::printEmployeeList() {
  Bank::EmployeeNode *current = this->employees;

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
  newEmployee->next = this->employees;
  this->employees = newEmployee;

  this->numEmployees++;
  return true;
}

void Bank::fire(Employee &employee) {
	if (!this->employees) return;
  Bank::EmployeeNode *current = this->employees;
  Bank::EmployeeNode *prev = nullptr;

  while(current != nullptr) {
		if (current->employee->getId() == employee.getId()) {
			if (prev != nullptr) {
				prev->next = current->next;
			} else {
				this->employees = current->next;
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

Account *Bank::openAccount(Customer &customer) {
	// check if bank is working
	if (!this->isWorking()) return nullptr;

	// check if customer already has account
	Bank::AccountNode *current = this->accounts;
	while(current != nullptr) {
		if (current->account->getCustomer()->getId() == customer.getId()) {
			return nullptr;
			break;
		}
		current = current->next;
	}

	// if criteria met, create account
	Account *newAccount = new Account(*this, customer);
	Bank::AccountNode *newNode = new Bank::AccountNode;
	newNode->account = newAccount;
	newNode->next = Bank::accounts;
	Bank::accounts = newNode;

	return newAccount;
}

bool Bank::closeAccount(Customer &customer) {
	if (!this->accounts) return false;
	Bank::AccountNode *current = this->accounts;
	Bank::AccountNode *prev = nullptr;
	while(current != nullptr) {
		if (current->account->getCustomer()->getId() == customer.getId()) {
			if (prev != nullptr) {
				prev->next = current->next;
			} else {
				this->accounts = current->next;
			}
			delete current;
			break;
		}
		prev = current;
		current = current->next;
	}
	return true;
}

void Bank::printAccountList() const {
	Bank::AccountNode *current = this->accounts;

	std::cout << this->getName() << " - Open Accounts:" << std::endl;

	if (current == nullptr) {
		std::cout << "-- there are no accounts --" << std::endl;
	}

	while(current) {
		std::cout << " - " << current->account->getCustomer()->getName()
      << " "<< current->account->getCustomer()->getSurname() 
      << ", balance: " << current->account->getBalance() 
      << std::endl;
		current = current->next;
	}

	std::cout << std::endl;
}

bool Bank::isWorking() const {
	return (this->numEmployees > 0);
}
