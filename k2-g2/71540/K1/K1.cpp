#include <iostream>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include "K1.h"

using namespace std;

RockStar::RockStar()
{
	name = new char[2];
	strcpy_s(name, 2, " ");

	awesomeness = 50;
	numberofFens = 0;
}

RockStar :: ~RockStar()
{
	delete[] name;
}

RockStar::RockStar(const RockStar& other)
{
	this->awesomeness = other.awesomeness;
	this->numberofFens = other.numberofFens;

	name = new char[strlen(other.name) + 1];
	strcpy_s(name, strlen(other.name) + 1, other.name);
}

RockStar& RockStar :: operator= (const RockStar& other)
{
	if (this != &other)
	{
		delete[] name;

		this->awesomeness = other.awesomeness;
		this->numberofFens = other.numberofFens;

		name = new char[strlen(other.name) + 1];
		strcpy_s(name, strlen(other.name) + 1, other.name);
	}
	return*this;
}

void RockStar::setName(char* n)
{
	delete[] name;
	name = new char[strlen(n) + 1];
	strcpy_s(name, strlen(n) + 1, n);
}

char* RockStar::getName() const
{
	return name;
}

void RockStar::setN(int n)
{
	this->numberofFens = n;
}

int RockStar::getN() const
{
	return numberofFens;
}

void RockStar::setAw(int n)
{
	this->awesomeness = n;
}

int RockStar::getAw() const
{
	return awesomeness;
}

void RockStar::print()
{
	cout << "Name: " << getName() << endl;
	cout << "Awesomeness: " << getAw() << endl;
	cout << "Number of fens: " << getN() << endl;
}

bool RockStar :: operator == (const RockStar& r) const
{
	return this->awesomeness == r.getAw();
}

bool RockStar :: operator> (const RockStar& r) const
{
	return this->awesomeness > r.getAw();
}

bool RockStar :: operator< (const RockStar& r) const
{
	return this->awesomeness < r.getAw();
}

Band::Band()
{
	size = 1; 
	count = 0;
}

Band :: ~Band()
{
	delete[] r;
}

Band::Band(const Band& other)
{
	this->count = other.count;
	this->size = other.size;

	for (int i = 0; i < other.count; i++)
	{
		r[i] = other.r[i];
	}
}

Band& Band :: operator= (const Band& other)
{
	if (this != &other)
	{
		delete[] r;
		this->count = other.count;
		this->size = other.size;

		for (int i = 0; i < other.count; i++)
		{
			r[i] = other.r[i];
		}
	}
	return *this;
}

void Band::addStar(const RockStar& r1)
{
	if (count == size)
	{
		size *= 2;
		RockStar* temp = new RockStar[count];
		for (int i = 0; i < count; i++)
		{
			temp[i] = this->r[i];
		}
		////delete[] this->r;
		//this->r = new RockStar[size];
		//for (int i = 0; i < count; i++)
		//{
		//	this->r[i] = temp[i];
		//}
		//delete[] temp;
		delete[] r;
		// no need of this:
		r = new RockStar[size];
		// ----
		r = temp;
		
	}
	r[count++] = r1;
}

// what about decreasing the size 
// - 0.2
void Band::removeStar(char* n)
{
	int index = -1;
	for (int i = 0; i < count; i++)
	{
		if (strcmp(r[i].getName(), n) == 0)
		{
			index = i;
		}
	}
	if (index != -1)
	{ 
		for (int i = index ; i < count - 1; i++)
		{
			r[i + 1] = r[i];
		}
		count--;
	}
	
}

RockStar Band::getStar(char* n)
{
	int index = 0;
	for (int i = 0; (i < count) && (index == 0); i++)
	{
		if (strcmp(r[i].getName(), n) == 0)
		{
			index = i;
		}
	}
	//if (index == 0) cout << "Not found!";
	return r[index];
}

void Band::print()
{
	for (int i = 0; i < count; i++)
	{
		r[i].print();
	}
}

int Band::getCount() const
{
	return count;
}

// first five?
// - 0.1
Band Band :: operator+=(const Band& r)
{
	int newSize = this->count + r.getCount();
	for (int i = this->count; i < newSize; i++)
	{
		for (int j = 0; j < r.count; j++)
		{ 
			this->r[i] = r.r[i];
		}
	}
	return *this;

}

void Band::sort()
{/*
	RockStar min = r[0]; int k = 0, Min;
	for (int i = 0; i < count; i++)
	{
		for (int j = 1; j < count; j++)
		{
			if (min.getAw() > r[i].getAw())
			{
				k = Min;
			}
		}
	}
	min = r[k]; r[k] = r[Min]; r[] = min;*/
}

double Band::average()
{
	int sum = 0;
	for (int i = 0; i < count; i++)
	{
		sum += r[i].getAw();
	}
	return sum / count;
}

Concert::Concert()
{
	size = 1;
	count = 0;
}

Concert :: ~Concert()
{
	for (int i = 0; i < count; i++)
	{
		// delete not ~...
		// - 0.1
		b[i].~Band();
	}
	delete[] b;
}

Concert::Concert(const Concert& other)
{
	this->count = other.count;
	this->size = other.size;
	for (int i = 0; i < other.count; i++)
	{
		b[i] = other.b[i];
	}
}

Concert& Concert :: operator= (const Concert& other)
{
	if (this != &other)
	{
		// no no no ...
		this->~Concert();
		this->count = other.count;
		this->size = other.size;
		for (int i = 0; i < other.count; i++)
		{
			b[i] = other.b[i];
		}
	}
	return *this;
}

double Concert::averageAwesomeness()
{
	double sum = 0;
	for (int i = 0; i < count; i++)
	{
		sum += b[i].average();
	}
	return sum / count;
}

Band Concert::headliners()
{
	int max = b[0].average();
	for (int i = 0; i < count; i++)
	{
		if (max < b[i].average())
		{
			max = i;
		}
	}
	return b[max];
}

//5.6