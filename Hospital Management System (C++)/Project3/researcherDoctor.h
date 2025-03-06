
#ifndef __RESEARCHERDOCTOR_H
#define __RESEARCHERDOCTOR_H
#include "doctor.h"
#include "researcher.h"
class researcherDoctor : public doctor, public researcher
{
private:


public:

	researcherDoctor();
	~researcherDoctor();
	researcherDoctor(const doctor& d, const researcher& r);
	researcherDoctor(const researcherDoctor& other);

	void print() const;
};
#endif;