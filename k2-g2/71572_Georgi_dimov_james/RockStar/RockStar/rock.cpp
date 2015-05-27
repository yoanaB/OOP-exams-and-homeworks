#include "rock.h"
#include <iostream>
using namespace std;
RockStar::RockStar(char* hereName, int hereAw, int hereNumOfFans)
{
	this->setName(hereName);
	this->setAw(hereAw);
	this->setFans(hereNumOfFans);
}


RockStar::RockStar(RockStar& other)
{
	int length = strlen(other.name) + 1;
	name = new char[length];
	strcpy_s(this->name, length, other.name);
	this->awesomeness = other.awesomeness;
	this->numberOfFans = other.numberOfFans;
}
RockStar& RockStar ::  operator=(RockStar& other)
{
	int length = strlen(other.name) + 1;
	name = new char[length];
	strcpy_s(this->name, length, other.name);
	this->awesomeness = other.awesomeness;
	this->numberOfFans = other.numberOfFans;
	return *this;
}
RockStar :: ~RockStar()
{
	delete[] name;
}




void RockStar::setName(char* hereName)
{
	int length = strlen(hereName) + 1;
	name = new char[length];
	strcpy_s(name, length, hereName);
	
}
void RockStar ::  setAw(int aw)
{
	this->awesomeness = aw;

}

void RockStar ::  setFans(int fans)
{
	this->numberOfFans = fans;

}
char* RockStar::getName()
{
	return name; 
}
int RockStar::getAw()
{
	return awesomeness;
}
int RockStar::getFans()
{
	return numberOfFans;
}

void RockStar::printRockStar()
{
	cout << "Name : " << getName() << endl << "awwsomen : " << getAw() << endl << "Fans : " << getFans() << endl;
}

bool RockStar :: operator>(RockStar& other)
{
	if (this->awesomeness > other.awesomeness)
	{
		return true;
	}
	else
	{
		return false; 
	}
}
bool RockStar ::  operator<(RockStar& other)
{
	return !(*this>other);
}
bool RockStar :: operator==(RockStar& other)
{
	if (strcmp(this->name, other.name) == 0 && (this->awesomeness = other.awesomeness
		&& this->numberOfFans == other.numberOfFans))
	{
		return true; 
	}
	else
	{
		return false; 
	}
}