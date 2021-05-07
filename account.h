#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "account.fwd.h"
#include "bank.fwd.h"
#include "bank.h"
#include "customer.fwd.h"
#include "customer.h"

class Account {
    private:
    Bank *bank;
    Customer *customer;
    double balance;

    public:
    Account(Bank &bank, Customer &customer);
    const Bank *getBank() const;
    const Customer *getCustomer() const;
    double getBalance() const;

    // subtracts given amount from customers cash and adds it to the account balance
    // returns true if this is possible
    // false otherwise
    bool deposit(double amount);

    // subtracts given amount from account balance and adds it to the customers cash
    // returns true if this is possible
    // false otherwise
    bool withdraw(double amount);
};

// class Account {
//     private:

//     Bank *bank;
//     Customer *customer;
//     double balance;

//     public:
//     // Account doesnt need methods for changing its internal data
//     // Once they are set in the beginning they dont change
//     Account(Bank *bank, Customer *customer);

//     // When account is closed it is being deleted
//     ~Account();

//     // get amount of money on a given account
//     double getBalance();
//     // store money on the account
//     bool deposit(double amount);
//     // get money from account
//     bool withdraw(double amount);
// }

#endif // ACCOUNT_H