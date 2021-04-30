#include <iostream>

#include "account.h"
#include "bank.h"

int main() {
    std::cout << "Hello, world!" << std::endl;
    Bank *b = new Bank;
    Account *a = new Account;
    b->account = a;
    a->bank = b;
    std::cout << b->account << std::endl;
    std::cout << a->bank << std::endl;
}
