#ifndef __ARTICLE_H
#define __ARTICLE_H
#include <iostream>

class article
{
private:
	char* articleName;
	char* dateOfpublish;
	char* magazine;

public:
	article(const char* a, const char* d, const char* m);
	article(const article& other);
	~article();

	void print() const;

	bool setArticleName(const char* n);
	const char* getArticleName() const;

	bool setDateOfpublish(const char* d);
	const char* getDateOfpublish() const; 

	bool setMagazine(const char* m);
	const char* getMagazine() const;

};
#endif