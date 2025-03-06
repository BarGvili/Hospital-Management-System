#pragma warning (disable: 4996)
#include <cstring>
#include <iostream>
using namespace std;
# include "nurse.h"

nurse::nurse() : employee(person("someone")),experience(0) {}
nurse::nurse(const employee& i, int e) : employee(i)
{
	experience = e;
}
nurse::nurse(const nurse& other) : employee(other)
{
	experience = other.experience;
}

nurse :: ~nurse(){}

void nurse::print() const 
{
	employee::print();
	cout << "years of experience: " << experience << endl;
}


bool nurse::setExperience(int e)
{
	if (e < 0)
	{
		return false;
	}
	experience = e;
	return true;
}


int nurse::getExperience() const
{
	return experience;
}

nurse& nurse::operator=(const nurse& other) {
	if (this != &other) {
		employee::operator=(other); 
		experience = other.experience;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const nurse& n) {
	os << "Name: " << n.getName() << std::endl
		<< "Experience: " << n.experience << " years" << std::endl
		<< "Employee ID: " << n.getWorkerId() << std::endl;
	return os;
}