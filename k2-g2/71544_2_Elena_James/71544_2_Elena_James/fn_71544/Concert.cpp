#include <iostream>
#include <string.h>
#include <assert.h>
#include "Concert.h"
#include "Band.h"
#include "Rockstar.h"

Concert::Concert()
{
	this->bands = new Band[1];
	this->size = 0;
	this->capacity = 1;
}
Concert::~Concert()
{
	for (int i = 0; i < size; i++)
	{
		delete[](this->bands + i);
	}
	delete[]this->bands;
}
Concert::Concert(const Concert& other) :bands(NULL)
{
	this->bands = new Band[other.capacity];
	assert(this->bands != NULL);
	for (int i = 0; i < other.size; i++)
	{
		this->bands[i] = other.bands[i];
	}
	this->size = other.size;
	this->capacity = other.capacity;
}
Concert::Concert(Band* bands, int size, int capacity) : bands(NULL)
{
	this->bands = new Band[capacity];
	assert(this->bands != NULL);
	for (int i = 0; i <size; i++)
	{
		this->bands[i] = bands[i];
	}
	this->size = size;
	this->capacity = capacity;
}
Concert& Concert::operator=(const Concert& other)
{
	if (this != &other)
	{

		for (int i = 0; i < size; i++)
		{
			delete[](this->bands + i);
		}
		delete[]this->bands;
		this->bands = new Band[other.capacity];
		assert(this->bands != NULL);
		for (int i = 0; i < other.size; i++)
		{
			this->bands[i] = other.bands[i];
		}
		this->size = other.size;
		this->capacity = other.capacity;
	}
	return *this;
}

double Concert::averageAwesomeness()
{
	double result = 0;
	for (int i = 0; i < size; i++)
	{
		result += bands[i].avAw();
	}
	return result;
}
Band& Concert::headliners()
{
	Band result = bands[0];
	for (int i = 0; i < size; i++)
	{
		if (result.avAw() < bands[i].avAw())
		{
			result = bands[i];
		}
	}
	return result;
}