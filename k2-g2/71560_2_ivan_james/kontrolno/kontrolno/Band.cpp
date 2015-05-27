#include "Band.h"
#include<iostream>

Band::Band()
{
	this->setBandName("");
	this->size = 0;
	this->capacity = 0;
}

Band::Band(char* name, int size, int capacity)
{
	this->setBandName(name);
	this->size = size;
	this->capacity = capacity;
	this->rockstars = new RockStar[this->capacity];
}

void Band::setBandName(const char* name)
{
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	size_t len = strlen(name) + 1;
	strcpy_s(this->name, len, name);
}

Band::Band(const Band& other)
{
	this->setBandName(other.name);
	this->size = other.size;
	this->capacity = other.capacity;
	this->rockstars = new RockStar[this->capacity];
	for (int i = 0; i < this->size; i++)
	{
		this->rockstars[i] = other.rockstars[i];
	}
}

Band& Band::addStar(const RockStar& star)
{
	if (this->size == this->capacity)
	{	

		this->capacity *= 2;
		RockStar* temp = this->rockstars;
		delete[]this->rockstars;
		this->rockstars = new RockStar[this->capacity];
		for (int i = 0; i < this->size; i++)
		{
			this->rockstars[i] = temp[i];
		}
		delete[] temp;
	}
	this->rockstars[this->size] = star;
	this->size++;
	return *this;
}

Band& Band::removeStat(const char* name)
{
	for (int i = 0; i < this->size; i++)
	{
		if (!strcmp(this->rockstars[i].getName(), name))
		{
			this->rockstars[i] = this->rockstars[this->size - 1];
			this->size--;
			i--;
		}
	}
	return *this;
}
RockStar Band::getStar(const char* name)
{

	for (int i = 0; i < this->size; i++)
	{
		if (!strcmp(this->rockstars[i].getName(), name))
		{
			return this->rockstars[i];
		}
	}
}

Band& Band::operator=(const Band& other)
{

	if (this != &other)
	{
		this->setBandName(other.name);
		this->size = other.size;
		this->capacity = other.capacity;
		delete[] this->rockstars;
		this->rockstars = new RockStar[this->capacity];
		for (int i = 0; i < this->size; i++)
		{
			this->rockstars[i] = other.rockstars[i];
		}
	}
	return *this;
}

Band& Band::operator+=(const Band& other)
{

}

RockStar& Band::pickAFrontman(const Band& band)
{	
	int maxAwesomenessIndex = 0;
	int maxAwesomeness = this->rockstars[0].getAwesomeness();
	for (int i = 0; i < this->size -1 ; i++)
	{
		if (maxAwesomeness < this->rockstars[i + 1].getAwesomeness())
		{
			maxAwesomeness = this->rockstars[i].getAwesomeness();
			maxAwesomenessIndex = i;
		}
	}
	return rockstars[maxAwesomenessIndex];
}

double Band::avarageAwesomeness(const Band&)
{
	double sum = 0;
	for (int i = 0; i < this->size; i++)
	{
		sum = sum + rockstars[i].getAwesomeness();
	}

	return (sum / this->size);
}

void Band::print()const
{
	for (int i = 0; i < this->size; i++)
	{
		std::cout << this->rockstars[i].getName()<<std::endl;
		std::cout << this->rockstars[i].getAwesomeness() << std::endl;
		std::cout << this->rockstars[i].getNumberOfFens() << std::endl;
	}
}

Band::~Band()
{
	delete[] this->rockstars;
}