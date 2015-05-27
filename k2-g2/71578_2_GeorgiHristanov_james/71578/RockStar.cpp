#include<iostream>
#include<cstring>
#include "RockStar.h"
#include "Band.h"

using namespace std;

//TASK 1 - Ima gi i v header file-a za vseki sluchai
// 1. Polimorfizum
// 2. Kapsulaciq
// 3. Abstrakciq
// 4. Nasledqvane

//------------------
RockStar::RockStar() : awesomeness(0), numberOfFans(0) 
{
	delete[] name;
	name = new char[2];
	name[0] = '\0';
}

RockStar::RockStar(char* _name, int _awesomeness, int _numberOfFans)
{
	delete[] name;
	this->name = new char[strlen(_name) + 1];
	strcpy(name, _name);

	this->awesomeness = _awesomeness;
	this->numberOfFans = _numberOfFans;
}

RockStar::~RockStar()
{
	delete[] name;
}

const char* RockStar::getName()
{
	return this->name;
}

int RockStar::getAwesomeness()
{
	return this->awesomeness;
}

int RockStar::getNumberOfFans()
{
	return this->numberOfFans;
}

void RockStar::setName(const char* _name)
{
	delete[] name;
	this->name = new char[strlen(_name) + 1];
	strcpy(name, _name);
}

void RockStar::setAwesomeness(int _awesomeness)
{
	this->awesomeness = _awesomeness;
}

RockStar& RockStar :: operator>(RockStar _other)
{
	if (this->awesomeness > _other.awesomeness)
	{
		return *this;
	}
	else
	{
		return _other;
	}
}

RockStar& RockStar :: operator<(RockStar _other)
{
	if (this->awesomeness < _other.awesomeness)
	{
		return *this;
	}
	else
	{
		return _other;
	}
}

void RockStar::setNumberOfFans(int _numberOfFans)
{
	this->numberOfFans = _numberOfFans;
}

void RockStar::print() const
{
	cout << "Name of rockstar: "	<< this->name			<< endl
		 << "Awesomenss: "			<< this->awesomeness	<< endl
		 << "Number of fans:"		<< this->numberOfFans	<< endl;
}
//------------------
Band::Band()
{
	delete[] name;
	name = new char[1];
	name[0] = '\0';

	this->currSize = 0;
	this->size = 1;
}
Band::Band(char* _name, int _memberCount)
{
	delete[] name;
	name = new char[strlen(_name) + 1];
	strcpy(name, _name);
	this->currSize = _memberCount;
	this->size = this->currSize + 1;
}
/*
void Band::addStar(char* _starName, int _awesomeness, int _numberOfFans)
{
	if (this->currSize == this->size)
	{
		Band old = *this;
		*this = new Band(this->name, this->size * 2);


	}
}
*/
void Band::removeStar(char* _starName)
{
	for (int i = 0; i < this->currSize; i++)
	{
		if (strcmp(this->stars[i].getName, _starName) == 0)
		{
			for (int j = i + 1; j < currSize; j++)
			{
				this[j - 1] = this[j];
			}
			currSize--;
			break;
		}
	}
}

void Band::getStar(char* _starName)
{
	for (int i = 0; i < this->currSize; i++)
	{
		if (strcmp(this->stars[i].getName, _starName) == 0)
		{
			cout << "Name of rockstar: " << this-stars[i].getName << endl
				<< "Awesomeness: " << this->stars[i].getAwesomeness << endl
				<< "Number of fans: " << this->stars[i].getNumberOfFans << endl;
			break;
		}
	}
}
void Band::print() const
{
	for (int i = 0; i < this->currSize; i++)
	{
		cout << "Name of rockstar: "<< this->stars[i].getName << endl
			 << "Awesomeness: "		<< this->stars[i].getAwesomeness << endl
			 << "Number of fans: "	<< this->stars[i].getNumberOfFans << endl;
	}
}
int main()
{
	RockStar pesho("LQLQLQ", 8, 6);
	
	pesho.setName("mnogo zdrav");
	pesho.setAwesomeness(666);
	pesho.setNumberOfFans(69);
	pesho.print();

	system("pause");
	return 0;
}
