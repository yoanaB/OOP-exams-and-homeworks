#include <iostream>
#include "Concert.h"
#include "Band.h"
#include "Rockstar.h"

using namespace std;

Concert::Concert()
	:bands(NULL), size(0)
{}
Concert::Concert(Band* bands, size_t size)
	: bands(nullptr), size(size)
{
	for (size_t i = 0; i < size; ++i)
	{
		delete (bands + i);
	}
	delete[] bands;
	this->bands = new Band[size];
	this->size = size;
}
Concert::Concert(const Concert& other)
{
	for (size_t i = 0; i < this->size; ++i)
	{
		this->bands[i] = other.bands[i];
	}
	this->size = other.size;
}
Concert& Concert::operator= (const Concert& right)
{
	if (this != &right)
	{
		for (size_t i = 0; i < this->size; ++i)
		{
			this->bands[i] = right.bands[i];
		}
		this->size = right.size;
	}
	return *this;
}

size_t Concert::AverageAwesomeness(Rockstar** awesomeBands)
{
	size_t sum = 0;
	for (size_t i = 0; i < size; ++i)
	{
		sum += awesomeBands[i]->getAwesomeness();
	}
	return sum / size;
}

Band Concert::headliners(Band* headOfBands)
{}



Concert::~Concert()
{
	for (size_t i = 0; i < size; ++i)
	{
		delete (bands + i);
	}
	delete[] bands;
}