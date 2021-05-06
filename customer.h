#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "customer.fwd.h"
#include "account.fwd.h"
#include "bank.fwd.h"

class Customer {
    private:
	char *name;
	char *surname;
    int id;
    double cash;

    // number of created Customer objects
	// is used to generate unique id for each customer
	static int numCreated;

    public:
    Customer(char* name, char *surname, double cash);
    ~Customer();

    const char* getName() const;
    const char* getSurname() const;
    const double getCash() const;
    // inline const double getAccountBalance(Bank bank) const;
};

// class Customer {

//     struct AccountElement {
//         Account *account;
//         AccountElement *next;
//     }
//     // linked list of accounts
//     AccountElement* aHead;

//     public:
//     Customer(char* name, char *surname, double cash);

//     ~Customer();

//     // print all accounts of the given customer
//     void print();

//     // Initiative of opening account is on the customers side
//     bool openAccount(Bank *bank);
//     // Both bank and customer cant start procedure of closing account
//     bool closeAccount(Bank *bank);

//     inline double getBalance(Bank *bank);

//     void print();

//     bool deposit(Bank *bank, double amount);
//     bool withdraw(Bank *bank, double amount);
// }

#endif // CUSTOMER_H