#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "account.fwd.h"
#include "bank.fwd.h"

class Account {
    public:
    Bank *bank;
};

#endif // ACCOUNT_H