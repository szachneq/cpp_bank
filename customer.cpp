#include <cstring>
#include "customer.h"

int Customer::numCreated = 0;

Customer::Customer(char* name, char *surname, double cash) {
  this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->surname = new char[strlen(surname) + 1];
	strcpy(this->surname, surname);
  this->cash = cash;
	this->id = Customer::numCreated + 1;
	Customer::numCreated += 1;
}

Customer::~Customer() {
  // TODO - deal with accounts
  delete[] this->name;
  delete[] this->surname;
}

const char* Customer::getName() const {
  return this->name;
}

const char* Customer::getSurname() const {
  return this->surname;
}

const double Customer::getCash() const {
  return this->cash;
}
