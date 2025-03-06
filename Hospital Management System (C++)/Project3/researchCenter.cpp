#pragma warning (disable: 4996)
#include <cstring>
#include <iostream>
using namespace std;
#include "researchCenter.h"

researchCenter::researchCenter(const char* n)
{
	allResearchers = new researcher * [2];
	numOfResearchers = 0;
	maxResearchers = 2;

	name = new char[strlen(n) + 1];
	strcpy(name, n);
}

researchCenter :: ~researchCenter()
{
	delete[] name;
    delete[] allResearchers;
}

void researchCenter::resizeResearcherArray()
{
    int newmax = maxResearchers * 2;
    researcher** newArray = new researcher * [newmax];
    for (int i = 0; i < maxResearchers; i++)
    {
        newArray[i] = allResearchers[i];
    }
    delete[] allResearchers;
    allResearchers = newArray;
    maxResearchers = newmax;
}

researcher* researchCenter::addResearcher(const char* n)
{
    if (numOfResearchers == maxResearchers)
    {
        resizeResearcherArray();
    }
    person tempPerson(n);
    employee tempEmployee = employee(tempPerson);

    allResearchers[numOfResearchers] = new researcher(tempEmployee);
    return  allResearchers[numOfResearchers++];
}

researcher* researchCenter::findResearcher(const char* n)
{
    for (int i = 0; i < numOfResearchers; i++)
    {
        if (strcmp(allResearchers[i]->getName(), n) == 0)
        {
            return allResearchers[i];
        }
    }
    cout << "couldnt find researcher" << endl;
    return nullptr;
}

bool researchCenter::addArticleToReasearcher(const char* a, const char* d, const char* m, researcher* r)
{
    article newArticle(a, d, m);
    r->addArticle(newArticle);
    cout << "Article added successfully!" << endl;
    return true;
}

void researchCenter::printAllResearchers() const
{
    for (int i = 0; i < numOfResearchers; i++)
    {
        allResearchers[i]->print();
    }
}