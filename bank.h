#ifndef BANK_H
#define BANK_H

#include "bank.fwd.h"
#include "account.fwd.h"
#include "customer.fwd.h"
#include "employee.fwd.h"
#include "employee.h"

const int MAX_EMPLOYEES = 3;

class Bank {
	private:
	char *name;

	struct EmployeeNode {
		Employee *employee;
		EmployeeNode *next;
	};
	// linked list of employees
	EmployeeNode *employees;
	int numEmployees;

	public:
	Bank(char *name);
	~Bank();

	const char *getName() const;

	void printEmployeeList();

	bool employ(Employee &employee);
	void fire(Employee &employee);
};

#endif // BANK_H
