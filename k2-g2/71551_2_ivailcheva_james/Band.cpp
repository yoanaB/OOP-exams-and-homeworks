#include <iostream>
#include "Band.h"
#include "Rockstar.h"

using namespace std;

Band::Band()
	:stars(NULL), size(0), capacity(0)
{}

Band::Band(Rockstar* stars, size_t size, size_t capacity)
	: stars(nullptr), size(size), capacity(capacity)
{
	this->stars = new Rockstar[this->capacity];
	this->size = size;
	this->capacity = capacity;
}

Band::Band(const Band& other)
{
	for (size_t i = 0; i < this->size; ++i)
	{
		this->stars[i] = other.stars[i];
	}
	this->size = other.size;
	this->capacity = other.capacity;
}

Band& Band::operator=(const Band& right)
{
	if (this != &right)
	{
		for (size_t i = 0; i < this->size; ++i)
		{
			this->stars[i] = right.stars[i];
		}
		this->size = right.size;
		this->capacity = right.capacity;
	}

	return *this;
}

Rockstar Band::getStar(char* nameSearch) const
{
	for (size_t i = 0; i < this->size; ++i)
	{
		if (strcmp(this->stars[i].getName(), nameSearch) == 0)
		{
			return stars[i];
		}
	}
}

Band& Band::addStar(Rockstar& newOne)
{
	if (size == capacity)
	{
		Rockstar* oldBand = stars;
		stars = new Rockstar[2 * capacity];
		for (size_t i = 0; i < size; ++i)
		{
			stars[i] = oldBand[i];
		}
		delete[] oldBand;
		capacity *= 2;
	}
	stars[size++] = newOne;
}

Band& Band::removeStar(Rockstar& deletedOne)
{
	for (size_t i = 0; i < size - 1; ++i)
	{
		if (strcmp(this->stars[i].getName(), deletedOne.getName()) == 0)
		{
			for (int j = i + 1; j < size; ++j)
			{
				stars[j - 1] = stars[j];
			}
		}
		--size;
	}
}

void Band::printBand()
{
	for (size_t i = 0; i < size; ++i)
	{
		stars[i].print();
	}
}


Rockstar Band::pickAFrontman(const Band& band)
{
	for (size_t i; i < size; ++i)
	{
		unsigned best = i;
		for (size_t j = i + 1; j < size; ++j)
		{
			if (band.stars[best].getAwesomeness() < band.stars[j].getAwesomeness())
			{
				best = j; 
			}
		}
		if (best != i)
		{
			return stars[best];
		}
	}
}

Rockstar Band::operator+=(Rockstar* secondBand)
{
	Rockstar* temp = new Rockstar[5];
	for (size_t i = 0; i < size-1; ++i)
	{
		size_t best = i;
		for (size_t j = i + 1; j < size; ++j)
		{
			if (this->stars[i].getAwesomeness() < secondBand[j].getAwesomeness())
			{
				best = j;
			}
		}
		if (best != i)
		{
			temp[i] = stars[best];
		}
	}
	for (size_t i = 0; i < size; ++i)
	{
		return temp[i];
	}
}

Band::Band()
{
	delete[] stars;
}