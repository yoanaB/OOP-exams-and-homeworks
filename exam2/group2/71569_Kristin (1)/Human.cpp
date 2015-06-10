#include <iostream>
#include "Human.h"

using namespace std;

Human::Human(const char* name, size_t strength, size_t loyalty)
	:name(NULL), strength(0), loyalty(0)
{
	this->setName(name);
	this->setStrength(strength);
	this->setLoyalty(loyalty);
	this->size = this->loyalty;
}

Human::Human(const Human& other)
	:name(NULL), strength(0), loyalty(0)
{
	this->setName(other.name);
	this->setStrength(other.strength);
	this->setLoyalty(other.loyalty);
	this->size = this->loyalty;
}

Human& Human::operator=(const Human& other)
{
	if (this != &other)
	{
		this->setName(other.name);
		this->setStrength(other.strength);
		this->setLoyalty(other.loyalty);
		this->size = this->loyalty;

	}

	return *this;
}


Human::~Human()
{

	delete[] this->name;

}


void Human::setName(const char* name)
{
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
	

void Human::setLoyalty(size_t loyalty)
{
	if (loyalty > 0)
	{
		this->loyalty = loyalty;
	}
}

void Human::setStrength(size_t str)
{
	this->strength = str;
}

void Human::reduceStrength(size_t low)
{
	if ((this->strength - low) > 0)
	{
		this->strength -= low;
	}
}


size_t Human::getLoyalty() const
{
	return this->loyalty;
}

size_t Human::getStrength() const
{
	return this->strength;
}


const char* Human::getName() const
{
	return this->name;
}

