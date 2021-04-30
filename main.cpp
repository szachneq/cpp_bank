#include <iostream>

// g++ -Wall bank.cpp account.cpp employee.cpp customer.cpp main.cpp && ./a.out

#include "account.h"
#include "bank.h"
#include "employee.h"
#include "account.h"

int main() {
	std::cout << "Hello, world!" << std::endl;
	Account *a = new Account;
	a->setBalance(100.50);
	std::cout << a->getBalance() << std::endl;
}
