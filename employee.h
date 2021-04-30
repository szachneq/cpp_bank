#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "employee.fwd.h"
#include "bank.fwd.h"

class Employee {
    private:
	char *name;
    Bank *employer;
};

#endif // EMPLOYEE_H