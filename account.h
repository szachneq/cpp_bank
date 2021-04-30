#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "account.fwd.h"
#include "bank.fwd.h"
#include "customer.fwd.h"

class Account {
    private:
    Bank *bank;
    Customer *customer;
    double balance;

    public:
    void setBank(Bank *bank);
    Bank *getBank();
    void setBalance(double balance);
    double getBalance();
};

#endif // ACCOUNT_H