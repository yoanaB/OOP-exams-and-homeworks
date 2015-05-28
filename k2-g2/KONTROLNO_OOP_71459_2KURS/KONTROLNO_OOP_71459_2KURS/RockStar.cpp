#include "RockStar.h"
#include <iostream>
using namespace std;

RockStar::RockStar()
{
	name = NULL;
	awesomeness = 0;
	numberOfFens = 0;
}

RockStar::RockStar(RockStar& r)
{
	this->name = new char [strlen(r.name) + 1];
	if(!this->name)
	{
		cerr << "Error allocating memory!";
	}

	strcpy(this->name, r.name);
	this->awesomeness = r.awesomeness;
	this->numberOfFens = r.numberOfFens;
}

RockStar::~RockStar()
{
	delete[] name;
}

char* RockStar::getName()
{
	return name;
}

int RockStar::getAwesomeness()
{
	return awesomeness;
}

unsigned int RockStar::getNumberOfFens()
{
	return numberOfFens;
}

void RockStar::setRockStar(const char* name, const int awesomeness, const unsigned int numberOfFens)
{
	this->name = new char[strlen(name) + 1];
	if(!this->name)
	{
		cerr << "Error allocating memory";
	}
	strcpy(this->name, name);

	this->awesomeness = awesomeness;
	this->numberOfFens = numberOfFens;
}

void RockStar::print()
{
	cout << "Star name: " << name << endl;
	cout << "Awesomeness: " << awesomeness << endl;
	cout << "Number of fans: " << numberOfFens << endl;
}

bool RockStar::operator<(RockStar& r)
{
	// how about return this->awesomeness < r.awesomeness :)
	if(this->awesomeness < r.awesomeness)
		return true;
	else
		return false;
}

bool RockStar::operator>(RockStar& r)
{
	if(this->awesomeness > r.awesomeness)
		return true;
	else
		return false;
}

bool RockStar::operator==(RockStar& r)
{
	if(this->awesomeness == r.awesomeness)
		return true;
	else
		return false;
}

RockStar& RockStar::operator=(RockStar& r)
{
	// nice :D this != &r would be better
	if(!(r == *this))
	{
		delete[] this->name;
		this->name = new char[strlen(r.name) + 1];
		if(!this->name)
		{
			cerr << "Error allocating memory!";
		}
		strcpy(this->name, r.name);
		
		this->awesomeness = r.awesomeness;
		this->numberOfFens = r.numberOfFens;

		return *this;
	}
}