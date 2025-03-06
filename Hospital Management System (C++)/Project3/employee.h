#ifndef __EMPLOYEE_H
#define __EMPLOYEE_H
#include "person.h"

class employee : public person
{
protected:
	int workerId;
	static int nextWorkerId;

public:
	employee(const person& p);
	employee(const employee& other);
	~employee();

	virtual void print() const;

	int getWorkerId() const;
};
#endif