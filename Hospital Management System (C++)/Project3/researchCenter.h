#ifndef __RESEARCHCENTER_H
#define __RESEARCHCENTER_H
#include "Researcher.h"

class researchCenter 
{

private:
	researcher** allResearchers;
	int numOfResearchers;
	int maxResearchers;
	char* name;
	researchCenter(const researchCenter& other);

public:

	researchCenter(const char* n);
	~researchCenter();
	researcher* addResearcher(const char* n);
	researcher* findResearcher(const char* n);
	void resizeResearcherArray();
	bool addArticleToReasearcher(const char* a, const char* d, const char* m, researcher* r);
	void printAllResearchers() const;

	friend std::ostream& operator<<(std::ostream& os, const researchCenter& r)
	{
		os << "Name: " << r.name << "\n";
		return os;
	}
};
#endif