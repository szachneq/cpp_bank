#include "account.h"

Account::Account(Bank &bank, Customer &customer) {
	this->bank = &bank;
	this->customer = &customer;
	this->balance = 0.0;
}

const Bank *Account::getBank() const {
	return this->bank;
}

const Customer *Account::getCustomer() const {
	return this->customer;
}

double Account::getBalance() const{
	return this->balance;
}

bool Account::deposit(double amount) {
	this->balance += amount;
	return true;
}

bool Account::withdraw(double amount) {
	if (amount > this->balance) return false;
	this->balance -= amount;
	return true;
}
