#pragma warning (disable: 4996)
#include <cstring>
#include <iostream>
using namespace std;
# include "doctor.h"

doctor::doctor() : employee(person("someone")), specialization(nullptr) {}
doctor :: doctor(const employee& i, const char* s) : employee(i)
{
	specialization = new char[strlen(s) + 1];
	strcpy(specialization, s);

}
doctor :: doctor(const doctor& other) : employee(other)
{
	specialization = new char[strlen(other.specialization) + 1];
	strcpy(specialization, other.specialization);
}

doctor :: ~doctor() 
{
	cleanUp();
}


void doctor::print() const 
{
	employee::print();
	cout << "worker specialization:" << specialization  << endl;
}


bool doctor::setSpecialization(const char* s)
{
	if (s == nullptr || strlen(s) == 0)
	{
		return false;
	}
	specialization = new char[strlen(s)+ 1];
	strcpy(specialization, s);
	return true;
}


const char* doctor :: getSpecialization() const
{
	return specialization;
}

void doctor :: cleanUp()
{
	delete[] specialization;
	specialization = nullptr;
}