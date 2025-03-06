#pragma warning (disable: 4996)
#include <cstring>
#include <iostream>
using namespace std;
# include "researcher.h"

researcher :: researcher() :  employee(person("Default Researcher")), numOfArticles(0), maxArticles(2), allArticles(nullptr) {}

researcher ::researcher(const employee& i) : employee(i), numOfArticles(0), maxArticles(2) ,allArticles(nullptr){}

researcher::researcher(const researcher& other) : employee(other), numOfArticles(other.numOfArticles), maxArticles(other.maxArticles)
{
	allArticles = new article*[maxArticles];
	if (other.allArticles != nullptr && other.numOfArticles > 0)
	{
		for (int i = 0; i < numOfArticles; i++)
		{
			allArticles[i] = new article(*other.allArticles[i]);
		}
	}
}

researcher :: ~researcher()
{
	cleanUp();
}

void researcher::addArticle(const article& newArticle)
{
	if (allArticles == nullptr)
	{
		maxArticles = 2;
		allArticles = new article*[maxArticles];
		numOfArticles = 0;
	}

	if (numOfArticles == maxArticles)
	{
		resizeArticleArray();
	}
	allArticles[numOfArticles] = new article(newArticle);
	numOfArticles++;
}

void researcher::resizeArticleArray()
{
	maxArticles *= 2;
	article** newArticles = new article*[maxArticles];

	for (int i = 0; i < numOfArticles; i++)
	{
		newArticles[i] = allArticles[i];
	}

	delete[] allArticles;
	allArticles = newArticles;
}

article** researcher:: getArticles() const
{
	return allArticles;
}
void researcher::print() const
{
	employee::print();
	cout << "Number of articles: " << numOfArticles << endl;
	for (int i = 0; i < numOfArticles; i++)
	{
		allArticles[i]->print();
	}
}

int researcher::getWorkerId() const
{
	return workerId;
}

void researcher::cleanUp()
{
	if (allArticles != nullptr)
	{
		delete[] allArticles;
		allArticles = nullptr;
	}
}

