#include <iostream>
#include <cstring>
#include "RockStar.h"

using namespace std;

RockStar::RockStar()
	:name(nullptr), awesomeness(0), numberOfFans(0)
{}

void RockStar::setName(const char* name)
{
	delete[] this->name;
	int length = strlen(name) + 1;
	this->name = new char[length];
	strcpy_s(this->name, length, name);

}

RockStar::RockStar(const char* name, int awesomeness, int numberOfFans)
	: name(nullptr), awesomeness(awesomeness), numberOfFans(numberOfFans)
{
	this->setName(name);
}


RockStar::RockStar(const RockStar& other)
	: name(nullptr), awesomeness(other.awesomeness), numberOfFans(other.numberOfFans)
{
	this->setName(other.name);
}

RockStar& RockStar::operator=(const RockStar& other)
{
	if (this == &other)
		return *this;
	this->setName(other.name);
	this->awesomeness = other.awesomeness;
	this->numberOfFans = other.numberOfFans;
	return *this;
}

RockStar::~RockStar()
{
	delete[] name;
}

void RockStar::setAwesomeness(int awesomeness)
{
	this->awesomeness = awesomeness;
}

void RockStar::setNumberOfFans(int numberOfFans)
{
	this->numberOfFans = numberOfFans;
}

int RockStar::getAwesomeness() const
{
	return this->awesomeness;
}


int RockStar::getNumberOfFans() const
{
	return this->numberOfFans;
}

const char* RockStar::getName() const
{
	return this->name;
}

void RockStar::print() const
{
	cout << "Rockstar is " << this->name << endl;
	cout << "Rockstar awesomeness:" << this->awesomeness << endl;
	cout << "Rockstar has " << this->numberOfFans<<" fans" << endl;
	
}

bool RockStar::operator==(const RockStar& other) const
{
	return  this->awesomeness == other.awesomeness;

}

bool RockStar::operator<(const RockStar& other) const
{
	return this->awesomeness < other.awesomeness;
}

bool RockStar::operator>(const RockStar& other) const
{
	return (!(*this < other || *this == other));
}




