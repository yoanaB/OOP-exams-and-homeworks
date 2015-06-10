#include <iostream>
#include "Tar.h"


using namespace std;

Tar::Tar(const char* name, size_t strength, size_t loyalty, size_t age)
	:Human(name, strength, loyalty)

{
	this->friends = new Tar[this->size];
	this->setAge(age);
}

Tar::Tar(const Tar& other)
	:Human(other)
{

	this->setAge(other.age);
	this->copyFriends(other);
}

Tar& Tar::operator=(const Tar& other)
{
	if (this != &other)
	{
		Human::operator=(other);
		this->copyFriends(other);
		this->setAge(other.age);
	}
	return *this;
}

size_t Tar::revenge() const
{
	size_t sum = 0;
	for (size_t i = 0; i < this->size; i++)
	{
		sum += this->friends[i].getStrength();
	}

	return sum * 2;
}

size_t Tar::getLoyalty() const
{
	return this->getLoyalty() + this->age;
}

const char* Tar::getSpecialSkill() const
{
	return "fire";
}

void Tar::setLoyalty(size_t loyalty)
{
	if (loyalty > 0)
	{
		this->setLoyalty = loyalty;
	}
}

Human* Tar::clone() const
{
	return new Tar(*this);
}

// - 1.5 