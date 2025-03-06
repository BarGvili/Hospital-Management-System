#pragma warning (disable: 4996)
#include "department.h"
#include <iostream>

using namespace std;

department::department() : name(nullptr) {}

department::department(const char* depName)
{
    name = new char[strlen(depName) + 1];
    strcpy(name, depName);

    maxEmployessInDepartment = 2;
    numOfEmployessInDepartment = 0;
    EmployessInDepartment = new employee * [maxEmployessInDepartment];

    maxPatientsInDepartment = 2;
    numOfPatientsInDepartment = 0;
    patientsInDepartment = new patient * [maxPatientsInDepartment];
}
department::department(const department& other) 
{
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
}
department :: ~department()
{
    cleanUp();
}

void department::cleanUp()
{
    delete[] name;

    for (int i = 0; i < numOfEmployessInDepartment; i++)
    {
        delete EmployessInDepartment[i];
    }
    delete[] EmployessInDepartment;

    for (int i = 0; i < numOfEmployessInDepartment; i++)
    {
        delete EmployessInDepartment[i];
    }
    delete[] EmployessInDepartment;

    for (int i = 0; i < numOfPatientsInDepartment; i++)
    {
        delete patientsInDepartment[i];
    }
    delete[] patientsInDepartment;
}

bool department::addEmployee(employee* d)
{
    if (numOfEmployessInDepartment == maxEmployessInDepartment)
    {
        int newmax = maxEmployessInDepartment * 2;
        employee** newEmployess = new employee * [newmax];

        for (int i = 0; i < numOfEmployessInDepartment; i++)
        {
            newEmployess[i] = EmployessInDepartment[i];
        }

        for (int i = numOfEmployessInDepartment; i < newmax; i++)
        {
            newEmployess[i] = nullptr;
        }

        delete[] EmployessInDepartment;

        EmployessInDepartment = newEmployess;
        maxEmployessInDepartment = newmax;
    }

    EmployessInDepartment[numOfEmployessInDepartment] = d;
    numOfEmployessInDepartment++;

    return true;
}


bool department::addPatient(patient* b)
{
    if (numOfPatientsInDepartment == maxPatientsInDepartment)
    {
        int newmax = maxPatientsInDepartment * 2;
        patient** newPatients = new  patient * [newmax];
        for (int i = 0; i < numOfPatientsInDepartment; i++)
        {
            newPatients[i] = patientsInDepartment[i];
        }
        for (int i = numOfPatientsInDepartment; i < newmax; i++)
        {
            newPatients[i] = nullptr;
        }
        delete[] patientsInDepartment;
        patientsInDepartment = newPatients;
        maxPatientsInDepartment = newmax;
    }

    patientsInDepartment[numOfPatientsInDepartment] = b;
    numOfPatientsInDepartment++;
    return true;
}

void department::printPatients() const
{
    cout << "Patients in department " << name << ":" << endl;
    for (int i = 0; i < numOfPatientsInDepartment; i++)
    {
        patientsInDepartment[i]->print();
    }
}

const char* department::getName() const
{
    return name;
}

patient* department::findPatientById(int id) const
{
    for (int i = 0; i < numOfPatientsInDepartment; i++)
    {
        if (patientsInDepartment[i]->getId() == id)
        {
            return patientsInDepartment[i];
        }
    }
    return nullptr;
}

void department::printPatient() const
{
    if (numOfPatientsInDepartment == 0)
    {
        cout << "No patients in this department." << endl;
        return;
    }

    for (int i = 0; i < numOfPatientsInDepartment; i++)
    {
        patientsInDepartment[i]->print();
    }

}