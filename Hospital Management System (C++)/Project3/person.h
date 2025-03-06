#ifndef __PERSON_H
#define __PERSON_H

class person
{
protected:
	char* name;

public:

	person();
	person(const char* n);
	person(const person& other);
	~person();

	virtual void print() const ;

	bool setName(const char* n);
	const char* getName() const;
	void cleanUp();

	person& operator=(const person& other);


};
#endif