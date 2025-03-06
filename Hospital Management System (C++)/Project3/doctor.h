#ifndef __DOCTOR_H
#define __DOCTOR_H
#include <iostream>
#include "employee.h"

class doctor : public employee 
{
private:
	char* specialization;

public:

	doctor();
	doctor(const employee& i, const char* s);
	doctor(const doctor& other);
	~doctor();

	void print() const ;

	bool setSpecialization(const char* s);

	const char* getSpecialization() const;

	void cleanUp();

	const doctor& operator= (const doctor& other)
	{
		if (this != &other)
		{
			employee :: operator=(other);
			delete[] specialization;
			specialization = strdup(other.specialization);
			workerId = other.workerId;
		}
		return *this;
	}


	friend std::ostream& operator<< (std::ostream& os, const doctor& d)
	{
		os << "Name: " << d.getName() << "\n"
			<< "Specialization: " << d.specialization << "\n"
			<< "Employee ID: " << d.workerId << std::endl;
		return os;
	}


};
#endif