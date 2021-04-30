#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "employee.fwd.h"
#include "bank.fwd.h"

class Employee {
	private:
	char *name;
	char *surname;
	int id;
	Bank *employer;

	// number of created Employee objects
	// is used to generate unique id for each employee
	static int numCreated;

	public:
	Employee(char *name, char *surname);
	~Employee();

	bool join(const Bank &bank);

	// employee is always able to leave his job
	// therefore boolean return is not needed - always successful
	void leave();
};

#endif // EMPLOYEE_H