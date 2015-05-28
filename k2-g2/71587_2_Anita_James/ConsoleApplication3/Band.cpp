#include <iostream>
#include <cstring>
#include <iomanip>
#include "Band.h"

using namespace std;

Band::Band() : size(0) : cap(1)
{
	this->stars = new Rock[cap];
}
Band::Band(const Band& other)
{
	this->cap = other.cap;
	this->size = other.size;

	delete[] stars;


	this->stars = new Rock[cap];
	for (unsigned i = 0; i < size; i++)
	{
		this->stars[i]= other.stars[i];
	}
}
Band& Band:: operator= (const Band& other)
{
	if (this == &other) return *this;


	this->cap = other.cap;
	this->size = other.size;

	delete[] stars;

	this->stars = new Rock[cap];
	for (unsigned i = 0; i < size; i++)
	{
		this->stars[i] = other.stars[i];
	}
	return *this;
}
Band:: ~Band ()
{
	delete[] stars;
}

void Band:: addStar(const Rock& other)
{
	if (size == cap)
	{
		expand();
	}
	this->stars[size] = other;
	size++;
}
void Band::removeStar(const Rock& other)
{
	for (unsigned i = 0; i < size; i++)
	{
		if (this->stars[i] == other)
			stars[i + 1] = stars[i];
		--size;
	}	
}
Rock& Band::getStar(const Rock* other)
{
	for (unsigned i = 0; i < size; i++)
	{
		if (this->stars[i] == other)
			return-> *this;
	}
}

// nope
// -0.2
void Band::expand()
{
	Rock* temp = stars;
	delete[] stars;
	
	this->stars = new Rock[cap * 2];
	for (unsigned i = 0; i < size; i++)
	{
		this->stars[i] = temp[i];
	}
	delete[] temp;
	cap *= 2;
}

void Band::print() const
{
	cout << "Band:" << stars << endl;
}

Rock& Band::sort()
{
	for (unsigned i = 0; i < size - 1; i++)
	{
		unsigned max = i;
		for (unsigned j = i + 1; j < size; j++)
		{
			if (stars[j].getAwesomeness > max)
				max = j;
		}
		return stars[max];
	}	
}