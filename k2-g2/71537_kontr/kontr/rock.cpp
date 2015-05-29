#include <iostream>
#include <cassert>
#include <cstring>
#include "rock.h"
using namespace std;

RockStar::RockStar(char* n , int a, int f )
{
	this->name = new char[strlen(n) + 1];
	assert(this->name);
	strcpy_s(this->name, strlen(n) + 1, n);

	this->awesomness = a;
	this->numberOfFens = f;
}
RockStar::RockStar(const RockStar& a)
{
	cpy(a);
}
RockStar:: ~RockStar()
{
	del();
}
RockStar& RockStar :: operator= (const RockStar& a)
{
	if (this != &a)
	{
		del();
		cpy(a);
	}
	return *this;
}
void RockStar::setName(char* n)
{
	this->name = new char[strlen(n) + 1];
	assert(this->name);
	strcpy_s(this->name, strlen(n) + 1, n);
}
void RockStar::setAwesomness(int a)
{
	this->awesomness = a;
}
void RockStar::setNumberOfFens(int f)
{
	this->numberOfFens = f;
}
char* RockStar::getName() const
{
	return name;
}
int RockStar::getAwesomness() const
{
	return awesomness;
}
int RockStar::getNumberOfFens() const
{
	return numberOfFens;
}
void RockStar::print() const
{
	cout << "Name: " << name << endl;
	cout << "Awesomness: " << awesomness << endl;
	cout << "Number of fens: " << numberOfFens << endl;
}
bool RockStar::operator> (const RockStar& a)
{
	return this->awesomness > a.awesomness;
}
bool RockStar::operator== (const RockStar& a)
{
	return this->awesomness == a.awesomness;
}
bool RockStar::operator< (const RockStar& a)
{
	return this->awesomness < a.awesomness;
}


Band::Band(char* name , int size)
{
	this->name = new char[strlen(name) + 1];
	assert(this->name);
	strcpy_s(this->name, strlen(name) + 1, name);

	this->size = size;
}
Band::Band(const Band& a)
{
	cpy(a);
}
Band :: ~Band()
{
	del();
}
Band& Band:: operator= (const Band& a)
{
	if (this != &a)
	{
		del();
		cpy(a);
	}
	return *this;
}
void Band::print() const
{
	cout << "Name of band: " << name << endl;
	cout << "Rockstars: ";
	for (int i = 0; i<size; i++)
	{
		stars[i].print();
		cout << endl;
	}
	
}
void Band::addStar(const RockStar& a)
{
	// ==?
	// - 0.1
	if (size > capacity)
		extend();
	stars[size++] = a;
}
void Band::removeStar(char* n)
{
	// decreasing size
	// - 0.2
	for (int i = 0; i < size; i++)
	{
		if (strcmp(stars[i].getName(), n))
		{
			stars[i - 1] = stars[i];
		}
		size--;
	}
}
// return is better...
void Band::getStar(char* n) 
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(stars[i].getName(), n))
			stars[i].print();
	}
}
// += must be of type Band&
// - 0.2
void Band:: operator+= (const Band& a)
{
	int i = this->size;
	for (int j = 0; j < a.size; j++)
	{
		stars[i++] = stars[j];
	}
	sort(a);
	for (int k = 0; k < 5; k++)
	{
		stars[k].print();
	}
}
double Band::getAv(const Band& a)
{
	int result = 0;
	for (int i = 0; i < size; i++)
	{
		result += stars[i].getAwesomness();
	}
	return result / size;
}
void Band::pickFrontMan(const Band& a)
{
	sort(a);
	cout << "The frontman is: ";
	stars[0], print();
}
int Band::getAwesomness(const Band& a)
{
	int result2 = 0;
	for (int i = 0; i < size; i++)
	{
		result2 += stars[i].getAwesomness();
	}
	return result2;
}

double Concert::averageAwesomness(const Concert& a)
{
	double result1=0;
	for (int i = 0; i < sizeBands; i++)
	{
		result1 += bands[i].getAv;
	}
	return result1 / sizeBands;
}
// miising a lot of things 
// - 1.2
// 4.3


