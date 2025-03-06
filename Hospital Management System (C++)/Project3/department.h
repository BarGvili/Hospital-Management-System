#ifndef __DEPARTMENT_H
#define __DEPARTMENT_H
#include <ostream>
#include "doctor.h"
#include "nurse.h"
#include "patient.h"
#include <cstring>

class department
{
private:
    char* name;
    patient** patientsInDepartment;
    employee** EmployessInDepartment;

    int numOfPatientsInDepartment;
    int maxPatientsInDepartment;

    int maxEmployessInDepartment;
    int numOfEmployessInDepartment;
  
public:

    department();
    department(const char* depName);
    department(const department& other);
    ~department();

    void cleanUp();

    bool addEmployee(employee* d);
    bool addPatient(patient* p);

    void printPatients() const;

    const char* getName() const;
    void printPatient() const;

    patient* findPatientById(int id) const;

    const department& operator=(const department& other)
    {
        if (this != &other)
        {
            delete[] name;
            name = strdup(other.name);

        }
        return *this;
    }

    friend std::ostream& operator<< (std::ostream& os, const department& dep)
    {
        os << "Name: " << dep.name << "\n";
        return os;
    }

};

#endif
