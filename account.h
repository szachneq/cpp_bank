#ifndef ACCOUNT_H_DEFINED
#define ACCOUNT_H_DEFINED

#include "bank.h"

class Bank;

class Account {
    public:
    Bank *bank;
};

#endif // ACCOUNT_H_DEFINED