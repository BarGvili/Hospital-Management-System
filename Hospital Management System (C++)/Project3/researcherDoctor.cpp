#pragma warning (disable: 4996)
#include <cstring>
#include <iostream>
using namespace std;
#include "researcherDoctor.h"

researcherDoctor:: researcherDoctor(): doctor(), researcher() {}
researcherDoctor:: ~researcherDoctor(){}
researcherDoctor::researcherDoctor(const doctor& d, const researcher& r) : doctor(d), researcher(r) {}
researcherDoctor:: researcherDoctor(const researcherDoctor& other) : doctor(other), researcher(other) {}

void researcherDoctor::print() const
{
	doctor::print();
	researcher::print();
}