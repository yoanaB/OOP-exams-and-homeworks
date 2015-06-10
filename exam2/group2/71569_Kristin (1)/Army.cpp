#include <iostream>
#include "Army.h"

using namespace std;


Army::Army()
	:leader(nullptr), soldiers(nullptr), numSoldiers(0)
{}

Army::Army(const Human& leader, size_t num)
	:leader(nullptr), soldiers(nullptr), numSoldiers(0)
{
	this->leader = leader.clone();
	if (num < this->MAX_CAPACITY)
	{
		this->numSoldiers = num;
		this->soldiers = new Human*[this->numSoldiers];
	}
}


Army::Army(const Army& other)
	:leader(nullptr), soldiers(nullptr), numSoldiers(0)
{
	this->leader = other.leader->clone();
	this->copySoldiers(other);
}

Army& Army::operator=(const Army& other)
{

	if (this!= &other)
	{
		this->leader = other.leader->clone();
		this->copySoldiers(other);
	}

}

Army::~Army()
{
	this->clearSoldiers();
	delete[] this->leader;

}

void Army::setLeader(Human* other)
{
	this->leader = other->clone();
}

void Army::addSoldier(const Human& newlid)
{
	if (this->numSoldiers < this->MAX_CAPACITY)
	{
		this->soldiers[this->numSoldiers++] = newlid.clone();
	}
}

void Army::clearSoldiers()
{
	for (size_t i = 0; i < this->numSoldiers; i++)
	{
		delete this->soldiers[i];
	}

	delete[] this->soldiers;
}