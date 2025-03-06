#ifndef __NURSE_H
#define __NURSE_H
#include <iostream>
#include "employee.h"

class nurse : public employee
{
private:
	int experience;

public:

	nurse();
	nurse(const employee& i, int e);
	nurse(const nurse& other);
	~nurse();

	void print() const ;

	bool setExperience(int e);

	int getExperience() const;

	nurse& operator=(const nurse& other);

	friend std::ostream& operator<<(std::ostream& os, const nurse& n);

	

};
#endif