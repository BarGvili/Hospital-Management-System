#pragma warning (disable: 4996)
#include <cstring>
#include <iostream>
using namespace std;
#include "hospital.h"

hospital::hospital() : r("RC shiba")
{
    allEmployees = new employee * [2];
    allPatients = new patient * [2];
    allDepartments = new department * [2];
    

    numOfEmployees = 0;
    maxEmployees = 2;
    numOfPatients = 0;
    maxPatients = 2;
    numOfDepartments = 0;
    maxDepartments = 2;
    
}

hospital :: ~hospital()
{
    delete[] allEmployees;
    delete[] allPatients;
    delete[] allDepartments;
}


void hospital::resizeEmployeeArray()
{
    int newmax = maxEmployees * 2;
    employee** newArray = new employee * [newmax];
    for (int i = 0; i < maxEmployees; i++)
    {
        newArray[i] = allEmployees[i];
    }
    delete[] allEmployees;
    allEmployees = newArray;
    maxEmployees = newmax;
}


bool hospital::addDoctor(const char* n, const char* s, const char* d)
{
    if (numOfEmployees == maxEmployees)
    {
        resizeEmployeeArray();
    }

    person tempPerson(n);
    employee tempEmployee= employee(tempPerson);
    allEmployees[numOfEmployees] = new doctor(tempEmployee, s);
    numOfEmployees++;

    for (int i = 0; i < numOfDepartments; i++)
    {
        if (strcmp(allDepartments[i]->getName(), d) == 0)
        {
            allDepartments[i]->addEmployee(allEmployees[numOfEmployees - 1]);
            return true;
        }
    }
    cout << "couldnt find department" << endl;
    return false;
}


bool hospital::addNurse(const char* n, int e, const char* d)
{
    if (numOfEmployees == maxEmployees)
    {
        resizeEmployeeArray();
    }

    person tempPerson(n);
    employee tempEmployee = employee(tempPerson);
    allEmployees[numOfEmployees] = new nurse(tempEmployee, e);
    numOfEmployees++;

    for (int i = 0; i < numOfDepartments; i++)
    {
        if (strcmp(allDepartments[i]->getName(), d) == 0)
        {
            allDepartments[i]->addEmployee(allEmployees[numOfEmployees - 1]);
            return true;
        }
    }
    cout << "couldnt find department" << endl;
    return false;
}

void hospital::resizePatientArray()
{
    int newmax = maxPatients * 2;
    patient** newArray = new patient * [newmax];
    for (int i = 0; i < maxPatients; i++)
    {
        newArray[i] = allPatients[i];
    }
    delete[] allPatients;
    allPatients = newArray;
    maxPatients = newmax;
}

patient* hospital::addPatient(const char* n, int i, int y, patient::eSex s, const char* d, const char* r)
{
    if (numOfPatients == maxPatients)
    {
        resizePatientArray();
    }

    person p(n);
    allPatients[numOfPatients] = new patient(p, i, y, s, d, r);
    return allPatients[numOfPatients++]; 
}


bool hospital::addPatientToDepartment(const char* depName, patient* b)
{
    for (int i = 0; i < numOfDepartments; i++)
    {
        if (strcmp(allDepartments[i]->getName(), depName) == 0) {
            allDepartments[i]->addPatient(b);
            return true;
        }
    }
    cout << "couldnt find department" << endl;
    return false;
}

patient* hospital::findPatient(int i)
{
    for (int j = 0; j < numOfPatients; j++)
    {
        if (i == allPatients[j]->getId())
        {
            allPatients[j]->print();
            return allPatients[j];
        }
    }
    cout << "patient not found " << endl;
    return nullptr;
}


void hospital::printAllStuffMembers() const
{
    for (int i = 0; i < numOfEmployees; i++)
    {
        allEmployees[i]->print();
    }
}

void hospital::resizeDepartmentArray()
{
    int newmax = maxDepartments * 2;
    department** newArray = new department * [newmax];
    for (int i = 0; i < maxDepartments; i++)
    {
        newArray[i] = allDepartments[i];
    }
    delete[] allDepartments;
    allDepartments = newArray;
    maxDepartments = newmax;
}

bool hospital::addDepartment(const char* d)
{
    if (numOfDepartments == maxDepartments)
    {
        resizeDepartmentArray();
    }
    allDepartments[numOfDepartments] = new department(d);
    numOfDepartments++;
    return true;
}



void hospital::printPatientsFromCertainDepartment(const char* d)
{
    for (int i = 0; i < numOfDepartments; i++)
    {
        if (strcmp(d, allDepartments[i]->getName()) == 0)
        {
            cout << "patient in department: " << d << endl;
            allDepartments[i]->printPatient();
            return;
        }
    }
    cout << "department" << d << " not found " << endl;

}

