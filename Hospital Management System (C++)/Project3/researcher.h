#ifndef __RESEARCHER_H
#define __RESEARCHER_H
#include "employee.h"
#include "article.h"

class researcher : public employee
{
private:
	article** allArticles;
	int numOfArticles;
	int maxArticles;
public:
	researcher();
	researcher(const employee& i);
	researcher(const researcher& other);
	~researcher();


	void addArticle(const article& newArticle);
	void resizeArticleArray();

	article** getArticles() const;
	void print() const;
	int getWorkerId() const;
	void cleanUp();


};

#endif