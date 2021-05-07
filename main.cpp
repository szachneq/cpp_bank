#include <iostream>
#include <cstring>

// g++ -Wall bank.cpp account.cpp employee.cpp customer.cpp main.cpp && ./a.out

#include "account.h"
#include "bank.h"
#include "employee.h"
#include "customer.h"

int main() {
	std::cout << "--- Start of tests ---" << std::endl << std::endl;

	Customer c1((char*)"Adam", (char*)"Nowak", 500.0);
	Customer c2((char*)"Jan", (char*)"Kowalski", 300.0);
	std::cout << "Name:" << c1.getName() << std::endl;
	std::cout << "Surname:" << c1.getSurname() << std::endl;
	std::cout << "Cash:" << c1.getCash() << std::endl;

	Bank b1((char*)"Bank 1");

	// Account a1(b1, c1);
	// std::cout << a1.getBank()->getName() << std::endl;
	// std::cout << a1.getCustomer()->getName() << std::endl;
	// std::cout << a1.getBalance() << std::endl;

	c1.openAccount(b1);
	c2.openAccount(b1);
	b1.printAccountList();
	c1.printAccountList();
	c2.printAccountList();

	// nice tests for later
	// {
	// 	// Test basic employee accessors
	// 	std::cout << "### Test 01 ###" << std::endl;
	// 	Employee e1((char*)"Adam", (char*)"Nowak");
	// 	std::cout << "Name:" << e1.getName() << std::endl;
	// 	std::cout << "Surname: " << e1.getSurname() << std::endl;
	// 	std::cout << "Id: " << e1.getId() << std::endl;
	// 	std::cout << "Employer memory address: " << e1.getEmployer() << std::endl;
	// 	std::cout << "Employer name: " << e1.getEmployerName() << std::endl;
	// 		std::cout << "###############" << std::endl;
	// 	std::cout << std::endl;
	// }

	// {
	// 	// Test joining the company
	// 	std::cout << "### Test 02 ###" << std::endl;
	// 	Employee e1((char*)"Adam", (char*)"Nowak");
	// 	Bank b1((char*)"Bank 1");
	// 	std::cout << "Before employment: " << std::endl;
	// 	std::cout << "Employer name: " << e1.getEmployerName() << std::endl;
	// 	b1.printEmployeeList();
	// 	e1.join(b1);
	// 	std::cout << "After employment: " << std::endl;
	// 	std::cout << "Employer name: " << e1.getEmployerName() << std::endl;
	// 	b1.printEmployeeList();
	// 	std::cout << "###############" << std::endl;
	// 	std::cout << std::endl;
	// }

	// {
	// 	// Test leaving the company
	// 	std::cout << "### Test 03 ###" << std::endl;
	// 	Employee e1((char*)"Adam", (char*)"Nowak");
	// 	Bank b1((char*)"Bank 1");
	// }
	// // Bank b1((char*)"Bank 1");
	// // std::cout << b1.getName() << std::endl;
	// // b1.printEmployeeList();
	// // e1.join(b1);
	// // b1.printEmployeeList();
	// // std::cout << e1.getEmployer()->getName() << std::endl;

	// // Employee e2((char*)"Janusz", (char*)"Kowal");
	// // Employee e8((char*)"Januszex", (char*)"Kowalex");
	// // Employee e9((char*)"Ziomalex", (char*)"Nowax");
	// // e2.join(b1);
	// // e8.join(b1);
	// // e9.join(b1);
	// // std::cout << e2.getEmployerName() << std::endl;
	// // b1.printEmployeeList();
	// // e2.leave();
	// // std::cout << e2.getEmployerName() << std::endl;
	// // b1.printEmployeeList();
	// // b1.fire(e1);
	// // b1.printEmployeeList();
	// // b1.fire(e1);
	// // b1.printEmployeeList();
	// // e2.join(b1);
	// // b1.printEmployeeList();
	// // b1.fire(e1);
	// // b1.printEmployeeList();


	// // Bank *b2 = new Bank((char*)"Bank 2");
	// // Employee e3((char*)"Test", (char*)"Jeden");
	// // Employee e4((char*)"Tester", (char*)"Dwa");
	// // e3.join(*b2);
	// // e4.join(*b2);
	// // std::cout << e3.getEmployerName() << std::endl;
	// // std::cout << e4.getEmployerName() << std::endl;
	// // delete b2;
	// // std::cout << e3.getEmployerName() << std::endl;
	// // std::cout << e4.getEmployerName() << std::endl;

	// // std::cout << std::endl << std::endl;

	// // Bank b3((char*)"Bank 3");
	// // Employee *et = new Employee((char*)"Pracownik", (char*)"Wskaznik");
	// // et->join(b3);
	// // b3.printEmployeeList();
	// // delete et;
	// // b3.printEmployeeList();

	// // Bank b4((char*)"Bank 4");
	// // Employee e420((char*)"zdradziecki", (char*)"zdrajca");
	// // e420.join(b4);
	// // e420.join(b3);
	// // b4.printEmployeeList();
	// // b3.printEmployeeList();

	return 0;
}
