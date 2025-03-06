#pragma warning (disable: 4996)
#include <cstring>
#include <iostream>
using namespace std;
# include "person.h"

person::person() : name(nullptr) {}
person:: person(const char* n)
{
	name = new char[strlen(n) + 1];
	strcpy(name, n);
}

person::person(const person& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
}

person :: ~person()
{
	cleanUp();
}

void person :: print() const 
{
cout << "name : " << name << endl;
}

bool person::setName(const char* n)
{
	if (n == nullptr || strlen(n) == 0)
	{
		return false;
	}
	name = new char[strlen(n) + 1];
	strcpy(name, n);
	return true;

}
const char* person::getName() const
{
	return name;
}

void person::cleanUp() 
{
		delete[] name;
		name = nullptr;
}

person& person::operator=(const person& other)
{
	if (this != &other) 
	{
			name = new char[strlen(other.name) + 1]; 
			strcpy(name, other.name);               
	}
	return *this;
}
