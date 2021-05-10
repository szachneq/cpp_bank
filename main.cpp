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

		// Customer can have only one account in certain bank
		b1.printAccountList();
		c1.printAccountList();
		c1.openAccount(b1);
		b1.printAccountList();
		c1.printAccountList();
		std::cout << std::endl;

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
		// cannot deposit money if no employees
		e1.leave();
		std::cout << "Before deposit: " << std::endl;
		b1.printAccountList();
		c1.printAccountList();
		std::cout << "C1 cash: " << c1.getCash() << std::endl;
		std::cout << "After deposit: " << std::endl;
		bool r3 = c1.deposit(b1, 10); // should be false
		std::cout << "result: " << r3 << std::endl;
		b1.printAccountList();
		c1.printAccountList();
		std::cout << "C1 cash: " << c1.getCash() << std::endl;
		std::cout << std::endl;

		// Test money withdrawal (test bool value)
		std::cout << std::endl;

		// Try to withdraw more money than the account balance is (test bool value)
		std::cout << std::endl;

		// Customer cant withdraw or deposit negative (or 0) amount of money
		std::cout << std::endl;

		// Customer cannot deposit/withdraw if he has no account in this bank
		std::cout << std::endl;

		// Test closing account (by customer)
		std::cout << std::endl;

		// Test closing account (by bank)
		std::cout << std::endl;

		// Bank cannot close account if customer is not there
		std::cout << std::endl;

		// Customer cannot close account if he has no account in this bank
		std::cout << std::endl;

		// Deleting customer should inform banks and close all its accounts
		std::cout << std::endl;

		// Deleting bank should inform all customers, refund all money and close accounts
		std::cout << std::endl;
	}
		std::cout << std::endl;

	return 0;
}
