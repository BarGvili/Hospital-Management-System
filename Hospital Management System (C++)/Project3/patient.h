#ifndef __PATIENT_H
#define __PATIENT_H
#include "person.h"

class patient : public person
{
public:
	enum eSex { male, female, other };

	patient();
	patient(const person& n, int i, int y, eSex s, const char* d, const char* r);
	patient(const patient& other);
	~patient();

	void print() const;
	
	bool setId(int i);
	bool setYearOfBirth(int y);
	bool setSex(eSex s);
	bool setDate(const char* d);
	bool setReason(const char* d);

	int getId() const;
	int getYearOfBirth() const;
	eSex getSex() const;


private:
	int id;
	int yearOfBirth;
	eSex sex;
	char* date;
	char* reason;

};

#endif