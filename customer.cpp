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
	this->id = Customer::numCreated + 1;
	this->accounts = nullptr;
	Customer::numCreated += 1;
}

Customer::~Customer() {
	// close all accounts
	Customer::AccountNode *m = Customer::accounts;
	while (m) {
		m = m->next;
		this->closeAccount(*(Customer::accounts->account->getBank()));
		delete Customer::accounts;
		Customer::accounts = m;
	}
  delete[] this->name;
  delete[] this->surname;
}

const char* Customer::getName() const {
  return this->name;
}

const char* Customer::getSurname() const {
  return this->surname;
}

const int Customer::getId() const {
	return this->id;
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

bool Customer::closeAccount(Bank &bank) {
	if (!this->accounts) return false;
	bool bankRes = bank.closeAccount(*this);
	if (bankRes) {
		Customer::AccountNode *current = this->accounts;
		Customer::AccountNode *prev = nullptr;
		while(current != nullptr) {
			if (current->account->getCustomer()->getId() == this->getId()) {
				if (prev != nullptr) {
					prev->next = current->next;
				} else {
					this->accounts = current->next;
				}
				double balance = current->account->getBalance();
				this->cash += balance;
				delete current->account;
				delete current;
				break;
			}
			prev = current;
			current = current->next;
		}
		return true;
	}
	return false;
}

void Customer::printAccountList() const {
	Customer::AccountNode *current = this->accounts;
	std::cout << this->getName() << " " << this->getSurname() << " - Open Accounts:" << std::endl;

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

bool Customer::deposit(Bank &bank, double amount) {
	if (amount > this->cash) return false;

	Customer::AccountNode *current = this->accounts;
	while(current != nullptr) {
		if (current->account->getBank() == &bank) {
			if (current->account->deposit(amount)) {
				this->cash -= amount;
				return true;
			} else { return false; }
		}
	}
	return false;
}

bool Customer::withdraw(Bank &bank, double amount) {
	Customer::AccountNode *current = this->accounts;
	while(current != nullptr) {
		if (current->account->getBank() == &bank) {
			if (current->account->withdraw(amount)) {
				this->cash += amount;
				return true;
			} else { return false; }
		}
	}
	return false;
}
