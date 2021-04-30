#ifndef BANK_H
#define BANK_H

#include "bank.fwd.h"
#include "account.fwd.h"
#include "customer.fwd.h"
#include "employee.fwd.h"

const int MAX_EMPLOYEES = 3;

class Bank {
    private:
	char *name;

    struct AccountElement {
        Account *account;
        AccountElement *next;
	};
	// linked list of accounts
	AccountElement* aHead;

    public:
    Bank(char *name);
    ~Bank();
    void addAccount(Account *account);
    void removeAccount(Account *account);
};

#endif // BANK_H
