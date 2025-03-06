#pragma warning (disable: 4996)
#include <cstring>
# include "article.h"
using namespace std;

article::article (const char* a, const char* d, const char* m)
{
	articleName = new char[strlen(a) + 1];
	strcpy(articleName, a);
	dateOfpublish = new char[strlen(d) + 1];
	strcpy(dateOfpublish, d);
	magazine = new char[strlen(m) + 1];
	strcpy(magazine, m);
}
article::article(const article& other)
{
	articleName = new char[strlen(other.articleName) + 1];
	strcpy(articleName, other.articleName);
	dateOfpublish = new char[strlen(other.dateOfpublish) + 1];
	strcpy(dateOfpublish, other.dateOfpublish);
	magazine = new char[strlen(other.magazine) + 1];
	strcpy(magazine, other.magazine);
}
article :: ~article()
{
	delete[] articleName;
	articleName = nullptr;
	delete[] dateOfpublish;
	dateOfpublish = nullptr;
	delete[] magazine;
	magazine = nullptr;
}

void article::print() const
{
	cout << "the aticle name is: " << articleName << endl << "date Of publish: " << dateOfpublish << endl << "magazine: " << magazine << endl;
}

bool article::setArticleName(const char* n)
{
	if (n == nullptr || strlen(n) == 0)
	{
		return false;
	}
	articleName = new char[strlen(n) + 1];
	strcpy(articleName, n);
	return true;
}

const char* article::getArticleName() const
{
	return articleName;
}

bool article:: setDateOfpublish(const char* d)
{
	if (d == nullptr || strlen(d) == 0)
	{
		return false;
	}
	dateOfpublish = new char[strlen(d) + 1];
	strcpy(dateOfpublish, d);
	return true;
}
const char* article::getDateOfpublish() const
{
	return dateOfpublish;
}

bool article::setMagazine(const char* m)
{
	if (m == nullptr || strlen(m) == 0)
	{
		return false;
	}
	magazine = new char[strlen(m) + 1];
	strcpy(magazine, m);
	return true;
}
const char* article::getMagazine() const
{
	return magazine;
}

