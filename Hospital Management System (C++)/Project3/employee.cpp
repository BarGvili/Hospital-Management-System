#pragma warning (disable: 4996)
#include <cstring>
#include <iostream>
using namespace std;
# include "employee.h"
int employee:: nextWorkerId = 1;

employee:: employee(const person& p) : person(p), workerId(nextWorkerId++) {}
employee::employee(const employee& other) :person(other), workerId(other.workerId) {}
employee:: ~employee() {}

void employee:: print() const
{
	person::print();
	cout << "worker ID: " << workerId << endl;
}


int employee:: getWorkerId() const
{
	return workerId;
}

