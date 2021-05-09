#include "account.h"

Account::Account(Bank &bank, Customer &customer) {
	this->bank = &bank;
	this->customer = &customer;
	this->balance = 0.0;
}

Account::~Account() {
	this->customer->closeAccount(*(this->bank));
}

Bank *Account::getBank() const {
	return this->bank;
}

Customer *Account::getCustomer() const {
	return this->customer;
}

double Account::getBalance() const{
	return this->balance;
}

bool Account::deposit(double amount) {
	if (!this->getBank()->isWorking()) return false;
	this->balance += amount;
	return true;
}

bool Account::withdraw(double amount) {
	if (amount > this->balance) return false;
	this->balance -= amount;
	return true;
}
