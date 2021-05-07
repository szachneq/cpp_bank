#include <cstring>
#include <iostream>
#include "customer.h"

int Customer::numCreated = 0;

Customer::Customer(char* name, char *surname, double cash) {
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->surname = new char[strlen(surname) + 1];
	strcpy(this->surname, surname);
	this->cash = cash;
	this->id = Customer::numCreated + 1;this->accounts = nullptr;
	Customer::numCreated += 1;
}

Customer::~Customer() {
  // TODO - deal with accounts
  delete[] this->name;
  delete[] this->surname;
}

const char* Customer::getName() const {
  return this->name;
}

const char* Customer::getSurname() const {
  return this->surname;
}

const double Customer::getCash() const {
  return this->cash;
}

bool Customer::openAccount(Bank &bank) {
  Account *res = bank.openAccount(*this);
	if (res) {
		Customer::AccountNode *newNode = new Customer::AccountNode;
		newNode->account = res;
		newNode->next = Customer::accounts;
		Customer::accounts = newNode;
		return true;
	}
	return false;
}

bool closeAccount(Bank *bank) {
	// if (this->employer) {
	// this->employer->fire(*this);
	// }
	return true;
}

void Customer::printAccountList() const {
	Customer::AccountNode *current = this->accounts;
	std::cout << this->getName() << this->getSurname() << " - Open Accounts:" << std::endl;

	if (current == nullptr) {
		std::cout << "-- there are no accounts --" << std::endl;
	}

	while(current) {
		std::cout << " - " << current->account->getBank()->getName()
      << ", balance: " << current->account->getBalance() 
      << std::endl;
		current = current->next;
	}

	std::cout << std::endl;
}
