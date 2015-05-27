#include <iostream>
#include "Band.h"

using namespace std;

Band::Band()
	:band(nullptr), size(0), capacity(0)
{}

Band::Band(int size, int capacity)
	: band(nullptr), size(size), capacity(capacity)
{
	this->band = new RockStar[this->capacity];
}

void Band::copyStars(const Band& other)
{
	delete[] band;
	
	this->size = other.size;
	this->capacity = other.capacity;
	this->band = new RockStar[this->capacity];

	for (int i = 0; i < this->size; i++)
	{
		this->band[i] = other.band[i];
	}

}

Band::Band(const Band& other)
	: band(nullptr), size(other.size), capacity(other.capacity)
{
	this->copyStars(other);
}

Band& Band::operator=(const Band& other)
{
	if (this == &other)
		return *this;
	this->copyStars(other);
	return *this;
}

Band::~Band()
{
	delete[] this->band;
}


int Band::getSize() const
{
	return this->size;
}

int Band::findStar(const char* name) const
{
	for (int i = 0; i < this->size; i++)
	{
		if (!strcmp(this->band[i].getName(), name))
			return i;
	}
	return -1;
}

RockStar& Band::getStar(const char* name) const // da rechem che vinagi gi ima :D
{

	return this->band[this->findStar(name)];
}


void Band::addRockStar(RockStar& newstar)
{
	if (this->size == this->capacity)
	{
		this->capacity *= 2;
		RockStar* temp = new RockStar[this->capacity];
		for (int i = 0; i < this->size; i++)
		{
			temp[i] = this->band[i];
		}
		delete[] band;
		this->band = temp;
	}

	this->band[this->size++] = newstar;

}

void Band::removeRockStar(const char* name)
{

	int index = this->findStar(name);
	RockStar* temp = new RockStar[this->capacity];
	for (int i = 0; i < this->size - 1; i++)
	{
		if (index < i)
		{
			temp[i] = this->band[i];
		}
		else
		{
			temp[i] = this->band[i + 1];
		}

	}
	delete[] band;
	this->band = temp;
	this->size--;
	
}

void Band::sort()
{
	for (int i = 0; i < this->size; i++)
	{
		for (int j = i + 1; j < this->size - 1; i++)
		{
			if (this->band[i].getAwesomeness() < this->band[j].getAwesomeness())
			{
				RockStar temp = this->band[i];
				this->band[i] = this->band[j];
				this->band[j] = temp;
			}
		}
	}

	return;
}

Band& Band::operator+=(const Band& other)
{
	Band result(*this);
	for (int i = 0; i < other.size; i++)
	{
		result.addRockStar(other.band[i]);
	}

	result.sort();

	delete[] this->band;
	this->band = new RockStar[10];
	for (int i = 0; i < 5; i++)
	{
		this->addRockStar(result.band[i]);
	}

	return *this;
}

RockStar& Band::pickFrontMan()
{
	this->sort();

	return this->band[0];
}


double Band::getAverageAwesomeness() const
{
	int awesome = 0;
	for (int i = 0; i < this->size; i++)
	{
		awesome += this->band[i].getAwesomeness();
	}

	return ((double)awesome) / this->size;
}

