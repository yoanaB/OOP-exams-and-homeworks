#include "Band.h"
#include "Rockstar.h"
#include <iostream>
#include <string.h>
#include <assert.h>
using namespace std;

void Band::setName(char* name)
{
	if (this->name)
	{
		delete[] this->name;
	}
	this->name = new char[strlen(name) + 1];
	assert(this->name != NULL);
	strcpy(this->name, name);
}
char* Band::getName()const
{
	return name;
}
void Band::setSize(int size)
{
	this->size = size;
}
void Band::setCap(int capacity)
{
	this->capacity = capacity;
}
int Band::getSize()const
{
	return size;
}
int Band::getCap()const
{
	return capacity;
}


Band::Band()
{
	this->name = new char[1];
	name[0] = '\0';
	this->stars = new Rockstar[1];
	this->size = 0;
	this->capacity = 1;
}
Band::Band(char* name, Rockstar* stars,int size, int capacity) :name(NULL), stars(NULL)
{
	this->name = new char[strlen(name) + 1];
	assert(this->name != NULL);
	strcpy(this->name, name);
	this->stars = new Rockstar[capacity];
	assert(this->stars != NULL);
	for (int i = 0; i < size; i++)
	{
		this->stars[i] = stars[i];
	}
	this->size = size;
	this->capacity = capacity;
}
Band::Band(const Band& other) :name(NULL), stars(NULL)
{
	this->name = new char[strlen(other.name) + 1];
	assert(this->name != NULL);
	strcpy(this->name, other.name);
	this->stars = new Rockstar[other.capacity];
	assert(this->stars != NULL);
	for (int i = 0; i < size; i++)
	{
		this->stars[i] = other.stars[i];
	}
	this->size = other.size;
	this->capacity = other.capacity;
}
Band& Band:: operator= (const Band& other)
{
	if (this != &other)
	{
		delete[]name;
		delete[]stars;
		this->name = new char[strlen(other.name) + 1];
		assert(this->name != NULL);
		strcpy(this->name, other.name);
		this->stars = new Rockstar[other.capacity];
		assert(this->stars != NULL);
		for (int i = 0; i < size; i++)
		{
			this->stars[i] = other.stars[i];
		}
		this->size = other.size;
		this->capacity = other.capacity;
	}
	return *this;
}
Band::~Band()
{
	delete[] name;
	delete[] stars;
}

void Band::print()
{
	if (size > 0)
	{
		for (int i = 0; i < size; i++)
		{
			stars[i].print();
		}
	}
	else
		cout << "This band has no stars!" << endl;
}

void Band::addStar(const Rockstar& newOne)
{
	if (size == capacity)
	{
		capacity = size * 2;
		Rockstar* old = stars;
		stars = new Rockstar[capacity];
		for (int i = 0; i < size; i++)
		{
			stars[i] = old[i];
		}
		delete[] old;
	}
	stars[size++] = newOne;
}
bool Band::removeStar(const Rockstar& other)
{
	bool isFound = false;
	for (int i = 0; i < size - 1; i++)
	{
		if (stars[i] == other)
		{
			isFound = true;
			for (int j = i + 1; j < size; i++)
			{
				stars[j - 1] = stars[j];
			}
		}
	}
	if (!isFound)
	{
		if (stars[size - 1] == other)
		{
			isFound = true;
			size--;
		}
	}
	else
		size--;

	return isFound;
}
Rockstar& Band::getStar(char*name)
{
	for (int i = 0; i < size; i++)
	{
		if (!strcmp(name, stars[i].getName()))
		{
			return stars[i];
		}
	}
}

Band Band::operator+=(const Band& other)
{
	Rockstar* old = stars;
	stars = new Rockstar[capacity+other.capacity];
	for (int i = 0; i < size; i++)
	{
		stars[i] = old[i];
	}
	delete[] old;
	for (int j = size; j < other.size; j++)
	{
		stars[j] = other.stars[j];
	}
	this->capacity = capacity + other.capacity;
	this->size = size + other.size;
	bestFive();
	return *this;
}
Band Band::bestFive()
{
	sort();
	Rockstar* old = stars;
	stars = new Rockstar[10];
	for (int i = 0; i < 5; i++)
	{
		stars[i] = old[i];
	}
	delete[] old;
	this->size = 5;
	this->capacity = size * 2;
	return *this;
}
void Band::sort()
{
	Rockstar temp;
	bool flag = 1;
	for (int i = 0; (i < size) && flag; i++)
	{
		if (stars[i].getAwesomeness()<stars[i + 1].getAwesomeness())
		{
			for (int j = i; i < size; j++)
			{
				temp = stars[i];
				stars[i] = stars[i + 1];
				stars[i + 1] = temp;
				flag = 0;
			}
		}
	}
}
double Band::avAw()
{
	double result = 0;
	for (int i = 0; i < size; i++)
	{
		result += stars[i].getAwesomeness();
	}
	return result;
}
Rockstar& Band::pickAFrontman()const
{
	Rockstar result = stars[0];
	for (int i = 0; i < size; i++)
	{
		if (result.getAwesomeness() < stars[i].getAwesomeness())
		{
			result = stars[i];
		}
	}
	return result;
}
