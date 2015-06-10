#include <iostream>
#include "NormalHuman.h"

using namespace std;


Normal::Normal(const char* name, size_t strength, size_t loyalty, const char* skill)
	:Human(name, strength, loyalty)
{

	this->friends = new Normal[this->getLoyalty()];
	this->setSkill(skill);
}

Normal::Normal(const Normal& other)
	:Human(other)
{
	this->setSkill(other.skill);
	this->copyFriends(other);
}

Normal& Normal::operator=(const Normal& other)
{
	if (this != &other)
	{
		Human::operator=(other);
		this->setSkill(other.skill);
		this->copyFriends(other);

	}

	return *this;
}

Normal::~Normal()
{
	delete[] this->friends;
}



void Normal::setSkill(const char* skill)
{
	delete[] this->skill;
	this->skill = new char[strlen(skill) + 1];
	strcpy(this->skill, skill);

}
const char* Normal::getSkill() const
{
	return this->skill;
}

size_t Normal::revenge() const
{
	size_t sum = 0;
	for (size_t i = 0; i < this->size; i++)
	{
		sum += this->friends->getStrength();
	}

	return sum;
}

size_t Normal::findFriend(const char* name) const
{
	for (size_t i = 0; i < this->size; i++)
	{
		if (!strcmp(this->friends->getName(), name))
			return i;
	}

	return 0; // sorry
}

// ?? - 0.2
void Normal::addFriend(const Normal& other)
{
	if (this->getLoyalty() < this->size)
		return;

}

void Normal::removeFriend(const char* name)
{
	size_t index = this->findFriend(name);
	for (size_t i = 0; i < this->size; i++)
	{
		if (i == index)
		{
			this->friends[index] = this->friends[this->size - 1];
		}
	}

	this->size--;

}

Human* Normal::clone() const
{
	return new Normal(*this);
}

const char* Normal::getSpecialSkill() const
{
	return "none";
}