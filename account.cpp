#include "account.h"

void Account::setBank(Bank *bank) {
    this->bank = bank;
}

Bank *Account::getBank() {
    return this->bank;
}

void Account::setBalance(double balance) {
    this->balance = balance;
}

double Account::getBalance() {
    return this->balance;
}
