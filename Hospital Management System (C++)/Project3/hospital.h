#ifndef __hospital_H
#define __hospital_H

#include "department.h"
#include "researchCenter.h"
class hospital
{
private:
	researchCenter r;
	char* Departments;
	patient** allPatients;
	int numOfPatients;
	int maxPatients;
	employee** allEmployees;
	int numOfEmployees;
	int maxEmployees;
	department** allDepartments;
	int numOfDepartments;
	int maxDepartments;
	
	

public:
	hospital();
	~hospital();


	bool addDoctor(const char* n, const char* s, const char* d);
	bool addNurse(const char* n, int e, const char* d);
	patient* addPatient(const char* n, int i, int y, patient::eSex s, const char* d, const char* r);
	bool addDepartment(const char* d);
	patient* findPatient(int i);
	void printAllStuffMembers() const;
	void printPatientsFromCertainDepartment(const char* d);
	void resizeEmployeeArray();
	void resizePatientArray();
	void resizeDepartmentArray();
	bool addPatientToDepartment(const char* depName, patient* b);

};
#endif