#include <iostream>
#include <cstring>
#include <iomanip>
#include "Concert.h"

using namespace std;

Concert::Concert()
{
	this->bands = new Band[size];
}
Concert::Concert(const Concert& other)
{
	delete[] bands;

	this->bands = new Band[size];
	for (unsigned i = 0; i < size; i++)
	{
		this->bands[i] = other.bands[i];
	}
}
Concert& Concert:: operator= (const Concert& other)
{
	if (this == &other) return *this;

	delete[] bands;
	this->bands = new Band[size];
	for (unsigned i = 0; i < size; i++)
	{
		this->bands[i] = other.bands[i];
	}
	return *this;
}
Concert::~Concert()
{
	delete[] bands;
}

// missing stuffs  - 0.8