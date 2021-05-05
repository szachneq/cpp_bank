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
	std::cout << e1.getEmployerName() << std::endl;
	std::cout << std::endl;

	Bank b1((char*)"Bank 1");
	std::cout << b1.getName() << std::endl;
	b1.printEmployeeList();
	e1.join(b1);
	b1.printEmployeeList();
	std::cout << e1.getEmployer()->getName() << std::endl;

	Employee e2((char*)"Janusz", (char*)"Kowal");
	e2.join(b1);
	std::cout << e2.getEmployerName() << std::endl;
	b1.printEmployeeList();
	e2.leave();
	std::cout << e2.getEmployerName() << std::endl;
	b1.printEmployeeList();
	b1.fire(e1);
	b1.printEmployeeList();
	b1.fire(e1);
	b1.printEmployeeList();
	e2.join(b1);
	b1.printEmployeeList();
	b1.fire(e1);
	b1.printEmployeeList();
}
