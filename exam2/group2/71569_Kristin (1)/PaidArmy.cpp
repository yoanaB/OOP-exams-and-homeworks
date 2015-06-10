#include <iostream>
#include "PaidArmy.h"

using namespace std;


PaidArmy::PaidArmy()
	:Army()
{}

PaidArmy::PaidArmy(const Human& lid, size_t num, size_t budget, size_t sal)
	: Army(lid, num)
{
	this->setSalary(sal);
	this->setBudget(budget);
}


PaidArmy::PaidArmy(const PaidArmy& other)
	:Army(other)
{
	this->setSalary(other.salary);
	this->setBudget(other.budget);
}

PaidArmy& PaidArmy::operator=(const PaidArmy& other)
{

	if (this != &other)
	{
		Army::operator=(other);
		this->setSalary(other.salary);
		this->setBudget(other.budget);
	}
	return *this;

}

Army::~Army()
{
	this->clearSoldiers();
	delete[] this->leader;

}


size_t PaidArmy::getRevenge() const
{
	size_t sum=0;
	for (size_t i = 0; i < this->numSoldiers; i++)
	{
		sum += this->soldiers[i]->getStrength();
	}
	sum += this->leader->getStrength();

	return (this->leader->getLoyalty() * (this->numSoldiers +1) + sum);
}

// wut?
bool PaidArmy::operator>(const PaidArmy& other)
{
	return this->getRevenge() > other.getRevenge();
}


