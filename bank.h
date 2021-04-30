#ifndef BANK_H
#define BANK_H

#include "bank.fwd.h"
#include "account.fwd.h"
#include "customer.fwd.h"
#include "employee.fwd.h"

const int MAX_EMPLOYEES = 3;

class Bank {
	private:
	char *name;

	struct EmployeeNode {
		Employee *employee;
		EmployeeNode *next;
	}
	// linked list of employees
	EmployeeNode *employees;
	int numEmployees;

	public:
	Bank(char *name);
	~Bank();

	bool employ(const Employee &employee);
	void fire(const Employee &employee);
};

#endif // BANK_H
