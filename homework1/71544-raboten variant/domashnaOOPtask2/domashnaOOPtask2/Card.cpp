#include <iostream>
#include <assert.h>
#include <string.h>
#include "Card.h"
#include "ListPerson.h"
using namespace std;


void Card::print()const
{
	cout << "Date:" << day << '/' << month << '/' << year << endl
		<< "Name:" << name << endl;
}
void Card::setName(char*name)
{
	this->name = new char[strlen(name) + 1];
	assert(this->name != NULL);
	strcpy(this->name, name);
}
void Card::setDay(int day)
{
	this->day = day;
}
void Card::setYear(int year)
{
	this->year = year;
}

char* Card::getName()const
{
	return name;
}
int Card::getDay()
{
	return day;
}
int Card::getMonth()
{
	return month;
}
int Card::getYear()
{
	return year;
}
void Card::getDate()
{
	cout << day << '/' << month << '/' << year << endl;
}
Card::~Card()
{
	delete[]name;
}
Card::Card()
{
	this->day = 1;
	this->month = 1;
	this->year = 1900;
	this->name = new char[1];
	name[0] = '\0';
}
Card::Card(int day, int month, int year, char* name)
{
	this->day = day;
	this->month = month;
	this->year = year;
	this->name = new char[strlen(name) + 1];
	assert(name != NULL);
	strcpy(this->name, name);
}
Card& Card::operator=(const Card& other)
{
	if (this != &other)
	{
		delete[]name;
		this->day = other.day;
		this->month = other.month;
		this->year = other.year;
		this->name = new char[strlen(other.name) + 1];
		assert(name != NULL);
		strcpy(this->name, other.name);
	}
	return *this;
}
bool Card::operator==(const Card& other)const
{
	return !(strcmp(this->name, other.name));
}
Card::Card(const Card&other) :name(NULL), day(NULL), month(NULL), year(NULL)
{
	this->day = other.day;
	this->month = other.month;
	this->year = other.year;
	this->name = new char[strlen(other.name) + 1];
	assert(name != NULL);
	strcpy(this->name, other.name);
}
