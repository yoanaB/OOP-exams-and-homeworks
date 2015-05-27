/*
1.Abstraction
2.Inheritance
3.Encapsulation
4.Polymophysm
*/

/*1) Да се дефинира RockStar, който представлява дадена рок звезда. Нека негови член-данни са:
name - име на звездата (с променлива дължина)
awesomeness- коефициент на якост (цяло число)
numberOfFens- брой фенове ( цяло число)
Да се реализира канонично представяне на класа, set и get функции и функция
print за извеждане на информацията за звездата  на екрана.
Да се предефинират операторите за сравнение (>, <, ==) на рок звезди  по iq.*/
#include "Rockstar.h"
#include <iostream>
#include <assert.h>
#include <string.h>
using namespace std;


void Rockstar::setName(char* name)
{
	if (this->name)
	{
		delete[] this->name;
	}
	this->name = new char[strlen(name) + 1];
	assert(this->name != NULL);
	strcpy(this->name, name);
}
void Rockstar::setAwesomeness(int awesomeness)
{
	this->awesomeness = awesomeness;
}
void Rockstar::setNumber(int numberOfFans)
{
	this->numberOfFans = numberOfFans;
}
char* Rockstar::getName()const
{
	return name;
}
int Rockstar::getAwesomeness()const
{
	return awesomeness;
}
int Rockstar::getNumber()const
{

	return numberOfFans;
}

Rockstar::Rockstar()
{
	this->awesomeness = 0;
	this->numberOfFans = 0;
	this->name = new char[1];
	name[0] = '\0';
}
Rockstar::Rockstar(char* name, int awesomeness, int numberOfFans) :name(NULL)
{
	this->name = new char[strlen(name) + 1];
	assert(this->name != NULL);
	strcpy(this->name, name);
	this->awesomeness = awesomeness;
	this->numberOfFans = numberOfFans;
}
Rockstar::Rockstar(const Rockstar& other)
{
	this->name = new char[strlen(other.name) + 1];
	assert(this->name != NULL);
	strcpy(this->name, other.name);
	this->awesomeness = other.awesomeness;
	this->numberOfFans = other.numberOfFans;
}
Rockstar& Rockstar::operator=(const Rockstar& other)
{
	if (this != &other)
	{
		delete[]this->name;
		this->name = new char[strlen(other.name) + 1];
		assert(this->name != NULL);
		strcpy(this->name, other.name);
		this->awesomeness = other.awesomeness;
		this->numberOfFans = other.numberOfFans;
	}
	return *this;
}
Rockstar::~Rockstar()
{
	delete[]name;
}

void Rockstar::print()
{
	cout << "Name:" << name << endl
		<< "Awesomeness:" << awesomeness << endl
		<< "Fans:" << numberOfFans << endl;
}

bool Rockstar::operator>(const Rockstar& other)
{
	return awesomeness > other.awesomeness;
}
bool Rockstar::operator<(const Rockstar& other)
{
	return awesomeness < other.awesomeness;
}
bool Rockstar:: operator== (const Rockstar& other)
{
	return awesomeness == other.awesomeness;
}
