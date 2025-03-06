#pragma warning (disable: 4996)
#include <cstring>
#include <iostream>
using namespace std;
# include "patient.h"

patient :: patient() :person(),id(0),yearOfBirth(0),sex(male),date(nullptr),reason(nullptr) {}

patient::patient(const person& n, int i, int y, eSex s, const char* d, const char* r) :person(n)
{
	id = i;
	yearOfBirth = y;
	sex = s;
	date = new char[strlen(d) + 1];
	strcpy(date, d);
	reason = new char[strlen(r) + 1];
	strcpy(reason, r);
}
patient::patient(const patient& other) : person(other)
{
	id = other.id;
	yearOfBirth = other.yearOfBirth;
	sex = other.sex;
	date = new char[strlen(other.date) + 1];
	strcpy(date, other.date);
	reason = new char[strlen(other.reason) + 1];
	strcpy(reason, other.reason);
}
patient :: ~patient() 
{
		delete[] date;
		delete[] reason;
}


void patient :: print() const
{
	const char* sexStr[] = { "male", "female", "other" };
	person::print();
	cout  << "id:" << id << endl << "year Of Birth:" << yearOfBirth << endl << "sex:" << sexStr[sex] << endl << "date of arrival " << date << endl << "reason of visit " << reason << endl;
}


bool patient::setId(int i)
{
	if (i < 0)
	{
		return false;
	}
	id = i;
	return true;
}

bool patient::setYearOfBirth(int y)
{
	if (y>2024 || y<1900)
	{
		return false;
	}
	yearOfBirth = y;
	return true;
	}

bool patient::setSex(eSex s)
{
	sex = s;
	return true;
}

bool patient::setDate(const char* d)
{
	if (d == nullptr || strlen(d) == 0)
	{
		return false;
	}
	date = new char[strlen(d) + 1];
	strcpy(date, d);
	return true;
}

bool patient:: setReason(const char* r)
{
	if (r == nullptr || strlen(r) == 0)
	{
		return false;
	}
	reason = new char[strlen(r) + 1];
	strcpy(reason, r);
	return true;
}


int patient::getId() const
{
	return id;
}

int patient::getYearOfBirth() const
{
	return yearOfBirth;
}

patient:: eSex patient ::getSex() const
{
	return sex;
}

