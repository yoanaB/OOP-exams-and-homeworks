#include "RockStar.h"
#include<iostream>

RockStar::RockStar()
{
	this->setName("");
	this->awesomeness = 0;
	this->numberOfFens = 0;
}


RockStar::RockStar(char* name, int awesomeness, int numberOfFens)
{
	this->setName(name);
	this->awesomeness = awesomeness;
	this->numberOfFens = numberOfFens;
}

void RockStar::setName(const char* name)
{	
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	size_t len = strlen(name) + 1;
	strcpy_s(this->name, len, name);
}

RockStar::RockStar(const RockStar& other)
{
	this->setName(other.name);
	this->awesomeness = other.awesomeness;
	this->numberOfFens = other.numberOfFens;
}

RockStar& RockStar::operator=(const RockStar& other)
{
	if (this != &other)
	{
		this->setName(other.name);
		this->awesomeness = other.awesomeness;
		this->numberOfFens = other.numberOfFens;
		
		return *this;
	}
	else
	{
		return *this;
	}
}

RockStar::~RockStar()
{
	delete[] this->name;
}

bool RockStar::operator<(const RockStar& other) const
{
	return  this->awesomeness < other.awesomeness;
}

bool RockStar::operator>(const RockStar& other) const
{
	return  this->awesomeness > other.awesomeness;
}

bool RockStar::operator==(const RockStar& other) const
{
	return  this->awesomeness == other.awesomeness;
}

void RockStar::print() const
{
	std::cout << this->name<<std::endl;
	std::cout << this->awesomeness << std::endl;
	std::cout << this->numberOfFens << std::endl;
}

char* RockStar::getName() const
{
	return this->name;
}

int RockStar::getAwesomeness()const
{
	return this->awesomeness;
}

int RockStar::getNumberOfFens() const
{
	return this->numberOfFens;
}
