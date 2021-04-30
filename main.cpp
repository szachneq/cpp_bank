#include <iostream>

#include "account.h"
#include "bank.h"

int main() {
    std::cout << "Hello, world!" << std::endl;
    Account *a = new Account;
    a->setBalance(100.50);
    std::cout << a->getBalance() << std::endl;

    // Bank *b = new Bank;
    // b->account = a;
    // a->bank = b;
    // std::cout << b->account << std::endl;
    // std::cout << a->bank << std::endl;
}
