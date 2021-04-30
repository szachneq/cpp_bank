#include <iostream>

// g++ -Wall bank.cpp account.cpp employee.cpp customer.cpp main.cpp && ./a.out

#include "account.h"
#include "bank.h"
#include "employee.h"
#include "account.h"

int main() {
	std::cout << "--- Start of tests ---" << std::endl;
	Employee e1((char*)"Adam", (char*)"Nowak");
	std::cout << e1.getName() << std::endl;
	std::cout << e1.getSurname() << std::endl;
	std::cout << e1.getId() << std::endl;
	std::cout << e1.getEmployer() << std::endl;
}
