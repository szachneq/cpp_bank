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
