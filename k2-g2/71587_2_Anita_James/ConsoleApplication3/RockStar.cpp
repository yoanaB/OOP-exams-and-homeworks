#include <iostream>
#include <cstring>
#include <iomanip>
#include "RockStar.h"

using namespace std;

const char* Rock:: getName() const
{
	return this->name;
}
int Rock:: getAwesomeness() const
{
	return this->awesomeness;
}
int Rock:: getNumber() const
{
	return this->numberOfFens;
}

void Rock:: setName(const char* name)
{
	delete[] name; 

	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}
void Rock::setAwesomeness(int awesomeness)
{
	this->awesomeness = awesomeness;
}
void Rock::setNumber(int numberOfFens)
{
	this->numberOfFens = numberOfFens;
}

void Rock::copy(const Rock& other)
{
	this->awesomeness = other.awesomeness;
	this->numberOfFens = other.numberOfFens;

	this->name = new char[strlen(other.name) + 1];
	strcpy_s(this->name, strlen(other.name) + 1, other.name);
}
void Rock::del()
{
	delete[] name;
}

void Rock:: print() const
{
	cout << "Name:" << name << setw(10)
		<< "Awesomeness:" << awesomeness << setw(10)
		<< "NumberOfFans:" << numberOfFens << endl;
}

Rock::Rock() :awesomeness(0) : numberOfFens(0)
{
	this->name = new char[1];
	this->name = "\0";
}
Rock::Rock(const char* name, int awesomeness, int numberOfFens)
{
	this->awesomeness = awesomeness;
	this->numberOfFens = numberOfFens;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}
Rock::Rock(const Rock& other)
{
	del();
	copy(other);
}
Rock& Rock:: operator=(const Rock& other)
{
	if (this == &other) return *this;

	del();
	copy(other);
	return *this;
}
Rock:: ~Rock()
{
	del();
}

bool Rock:: operator > (const Rock& other)
{
	return (this->awesomeness > other.awesomeness)
}
bool Rock:: operator < (const Rock& other)
{
	return (this->awesomeness < other.awesomeness)
}
bool Rock:: operator == (const Rock& other)
{
	return (this->awesomeness == other.awesomeness)
}
