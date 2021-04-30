#include "bank.h"

Bank::Bank(char *name) {
	this->name = new char[strlen(name)];
	strcpy(this->name, name);
  this->employees = nullptr;
  this->numEmployees = 0;
}

Bank::~Bank() {
	delete[] this->name;
  // TODO - method that informs all other objects associated
  // about the deletion
  // employees are getting fired
  // all accounts closed and money returned to customers
}

bool Bank::employ(const Employee &employee) {
  if (this->numEmployees >= MAX_EMPLOYEES) return false;
  if (employee.getEmployer != nullptr) return false;

  
}

void Bank::fire(const Employee &employee) {

}
