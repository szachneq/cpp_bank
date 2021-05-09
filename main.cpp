#include <iostream>
#include <cstring>

// g++ -Wall bank.cpp account.cpp employee.cpp customer.cpp main.cpp && ./a.out

#include "account.h"
#include "bank.h"
#include "employee.h"
#include "customer.h"

int main() {
	std::cout << "--- Start of tests ---" << std::endl << std::endl;

	// Employee tests

	{
		// Test basic employee accessors
		Employee e1((char*)"Adam", (char*)"Nowak");
		std::cout << "Name:" << e1.getName() << std::endl;
		std::cout << "Surname: " << e1.getSurname() << std::endl;
		std::cout << "Id: " << e1.getId() << std::endl;
		std::cout << "Employer memory address: " << e1.getEmployer() << std::endl;
		std::cout << "Employer name: " << e1.getEmployerName() << std::endl;
		// Test joining the company
		Bank b1((char*)"Bank 1");
		std::cout << "Before employment: " << std::endl;
		std::cout << "Employer name: " << e1.getEmployerName() << std::endl;
		b1.printEmployeeList();
		e1.join(b1);
		std::cout << "After employment: " << std::endl;
		std::cout << "Employer name: " << e1.getEmployerName() << std::endl;
		b1.printEmployeeList();
		// Test leaving the company
		e1.leave();
		std::cout << "After leaving: " << std::endl;
		std::cout << "Employer name: " << e1.getEmployerName() << std::endl;
		b1.printEmployeeList();
		// Test employer firing employee
		e1.join(b1);
		std::cout << "Before Firing: " << std::endl;
		std::cout << "Employer name: " << e1.getEmployerName() << std::endl;
		b1.printEmployeeList();
		b1.fire(e1);
		std::cout << "After firing: " << std::endl;
		std::cout << "Employer name: " << e1.getEmployerName() << std::endl;
		b1.printEmployeeList();
		// Test if limit of employees is working
		Employee e2((char*)"John", (char*)"Snow");
		Employee e3((char*)"Aleksander", (char*)"Tester");
		Employee e4((char*)"Janusz", (char*)"Kowal");
		bool e1_result = e1.join(b1); // should be true
		bool e2_result = e2.join(b1); // should be true
		bool e3_result = e3.join(b1); // should be true
		bool e4_result = e4.join(b1); // should be false, employee limit reached
		std::cout << "e1: " << e1_result << " ";
		std::cout << "e2: " << e2_result << " ";
		std::cout << "e3: " << e3_result << " ";
		std::cout << "e4: " << e4_result << std::endl;
		std::cout << "e1 employer: " << e1.getEmployerName() << std::endl;
		std::cout << "e2 employer: " << e2.getEmployerName() << std::endl;
		std::cout << "e3 employer: " << e3.getEmployerName() << std::endl;
		std::cout << "e4 employer: " << e4.getEmployerName() << std::endl;
		b1.printEmployeeList(); // e4 (Janusz Kowal) should not be there
		// Unemployed employee leaving work should not break the program
		std::cout << "e4 employer: " << e4.getEmployerName() << std::endl;
		e4.leave();
		std::cout << "e4 employer: " << e4.getEmployerName() << std::endl;
		// Unemployed employee being fired should not break the program
		b1.fire(e4);
		// Cannot employ employee if hes working in another company
		Bank b2((char*)"Bank 2");
		e1.join(b2);
		std::cout << "e1 employer: " << e1.getEmployerName() << std::endl;
		b2.printEmployeeList();
		// Check if after one of the employees leaves the company another can join
		b1.printEmployeeList();
		e1.leave();
		b1.printEmployeeList();
		e4.join(b1);
		b1.printEmployeeList();
		std::cout << "e4 employer: " << e4.getEmployerName() << std::endl;
	}

	{
		// Test if the employee destructor informs bank
		Bank b1((char*)"Bank 1");
		Employee *e1 = new Employee((char*)"Jan", (char*)"Znikajacy");
		e1->join(b1);
		std::cout << "Before deletion" << std::endl;
		std::cout << "e1 employer: " << e1->getEmployerName() << std::endl;
		b1.printEmployeeList();
		delete e1;
		std::cout << "After deletion" << std::endl;
		b1.printEmployeeList();
	}

	{
		// Test if the bank destructor informs employee
		Bank *b1 = new Bank((char*)"Bank 1");
		Employee e1((char*)"Jan", (char*)"Znikajacy");
		e1.join(*b1);
		std::cout << "Before deletion" << std::endl;
		std::cout << "e1 employer: " << e1.getEmployerName() << std::endl;
		b1->printEmployeeList();
		delete b1;
		std::cout << "After deletion" << std::endl;
		std::cout << "e1 employer: " << e1.getEmployerName() << std::endl;
	}
	std::cout << std::endl;

	// Customer tests
	{
		// Test basic customer accessors
		Customer c1((char*)"Witold", (char*)"Bogaty", 10000);
		std::cout << "Name:" << c1.getName() << std::endl;
		std::cout << "Surname: " << c1.getSurname() << std::endl;
		std::cout << "Id: " << c1.getId() << std::endl;
		std::cout << "Cash: " << c1.getCash() << std::endl;
		c1.printAccountList();
		// Opening accounts should not be possible without employees
		Bank b1((char*)"Bank 1");
		c1.openAccount(b1);
		b1.printAccountList();
		c1.printAccountList();
		// Test opening account when necessary conditions are met (employees present)
		Employee e1((char*)"Wladek", (char*)"Pracowniczy");
		e1.join(b1);
		c1.openAccount(b1);
		b1.printAccountList();
		c1.printAccountList();
		std::cout << std::endl;

		// TODO Customer can have only one account in certain bank



		// Test money deposit
		std::cout << "Before deposit: " << std::endl;
		b1.printAccountList();
		c1.printAccountList();
		std::cout << "C1 cash: " << c1.getCash() << std::endl;
		std::cout << "After deposit: " << std::endl;
		bool r1 = c1.deposit(b1, 5000); // should be true
		std::cout << "result: " << r1 << std::endl;
		b1.printAccountList();
		c1.printAccountList();
		std::cout << "C1 cash: " << c1.getCash() << std::endl;
		std::cout << std::endl;
		// Try to deposit more money than the customer has
		std::cout << "Before deposit: " << std::endl;
		b1.printAccountList();
		c1.printAccountList();
		std::cout << "C1 cash: " << c1.getCash() << std::endl;
		std::cout << "After deposit: " << std::endl;
		bool r2 = c1.deposit(b1, 9999999); // should be false
		std::cout << "result: " << r2 << std::endl;
		b1.printAccountList();
		c1.printAccountList();
		std::cout << "C1 cash: " << c1.getCash() << std::endl;
		// TODO cannot deposit money if no employees

		// Test money withdrawal (test bool value)

		// Try to withdraw more money than the account balance is (test bool value)

		// Customer cant withdraw or deposit negative (or 0) amount of money

		// Customer cannot deposit/withdraw if he has no account in this bank

		// Test closing account (by customer)
		// Test closing account (by bank)
		// Bank cannot close account if customer is not there
		// Customer cannot close account if he has no account in this bank
		// Deleting customer should inform banks and close all its accounts
		// Deleting bank should inform all customers, refund all money and close accounts
	}
		std::cout << std::endl;

	// Employee e1((char*)"John", (char*)"Snow");
	// Customer c1((char*)"Adam", (char*)"Nowak", 500.0);
	// Bank *b1 = new Bank((char*)"Bank 1");
	// e1.join(*b1);
	// c1.openAccount(*b1);
	// c1.deposit(*b1, 100);
	// c1.printAccountList();
	// std::cout << "C1: " << c1.getCash() << std::endl;
	// delete b1;
	// c1.printAccountList();
	// std::cout << "C1: " << c1.getCash() << std::endl;

	// Employee e1((char*)"John", (char*)"Snow");
	// Employee e2((char*)"Aleksander", (char*)"Ziomal");

	// Customer c1((char*)"Adam", (char*)"Nowak", 500.0);
	// Customer c2((char*)"Jan", (char*)"Kowalski", 300.0);
	// Bank b1((char*)"Bank 1");
	// e1.join(b1);
	// Bank b2((char*)"Bank 2");
	// e2.join(b2);

	// c1.openAccount(b1);
	// c1.deposit(b1, 10);
	// c2.openAccount(b1);
	// c2.deposit(b1, 20);
	// c2.openAccount(b2);
	// c2.deposit(b2, 5);

	// std::cout << "C1: " << c1.getCash() << std::endl;
	// std::cout << "C2: " << c2.getCash() << std::endl;

	// b1.printAccountList();
	// b2.printAccountList();
	// c1.printAccountList();
	// c2.printAccountList();

	// c1.closeAccount(b1);
	// c1.closeAccount(b2);
	// c1.printAccountList();

	// c2.closeAccount(b2);
	// c2.printAccountList();

	// c2.withdraw(b1, 10);
	// c2.printAccountList();
	// b1.printAccountList();

	// std::cout << "Name:" << c1.getName() << std::endl;
	// std::cout << "Surname:" << c1.getSurname() << std::endl;
	// std::cout << "Cash:" << c1.getCash() << std::endl;
	// Account a1(b1, c1);
	// std::cout << a1.getBank()->getName() << std::endl;
	// std::cout << a1.getCustomer()->getName() << std::endl;
	// std::cout << a1.getBalance() << std::endl;

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
