#include <iostream>
#include <cstring>
#include "Rockstar.h"

using namespace std;


Rockstar::Rockstar()
	:name(NULL), awesomeness(0), numberOfFans(0)
{}

Rockstar::Rockstar(char* name, int awesomeness, size_t numberOfFans)
	: name(nullptr)
{
	setName(name);
	this->awesomeness = awesomeness;
	this->numberOfFans = numberOfFans;
}

Rockstar::Rockstar(const Rockstar& other)
{
	setName(other.name);
	this->awesomeness = other.awesomeness;
	this->numberOfFans = other.numberOfFans;
}

Rockstar& Rockstar::operator=(const Rockstar& right)
{
	if (this != &right)
	{
		setName(right.name);
		this->awesomeness = right.awesomeness;
		this->numberOfFans = right.numberOfFans;
	}

	return *this;
}

void Rockstar::setName(char* name)
{
	delete[] this->name;
	int length = strlen(this->name) + 1;
	this->name = new char[length];
	strcpy_s(this->name, length, name);
}

void Rockstar::setAwesomeness(int awesomeness)
{
	this->awesomeness = awesomeness;
}

void Rockstar::setNumberOfFans(size_t numberOfFans)
{
	this->numberOfFans = numberOfFans;
}

char* Rockstar::getName() const
{
	return this->name;
}

int Rockstar::getAwesomeness() const
{
	return this->awesomeness;
}

size_t Rockstar::getNumberOfFans() const
{
	return this->numberOfFans;
}

bool Rockstar::operator==(const Rockstar& otherOne)
{
	return (this->awesomeness == otherOne.awesomeness);
}

bool Rockstar::operator<(const Rockstar& otherOne)
{
	return (this->awesomeness < otherOne.awesomeness);
}

bool Rockstar::operator>(const Rockstar& otherOne)
{
	return (this->awesomeness > otherOne.awesomeness);
}

void Rockstar::print()
{
	cout << "Name of Rockstar: " << this->name << endl
		 << "Awesomeness level of the Rockstar" << this->awesomeness << endl
		 << "Number of fans of the Rockstar" << this->numberOfFans << endl;

}

Rockstar::~Rockstar()
{
	delete[] this->name;
}