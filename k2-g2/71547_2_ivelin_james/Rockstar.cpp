//абстракция
//енкапсулация
//полиморфизъм
//абстракция

#include "rock.h"
#include <iostream>
using namespace std;

RockStar::RockStar(char* hereName, int hereAwesomness, int hereNumOfFans)
{
	this->setName(hereName);
	this->setAwesomness(hereAwesomness);
	this->setFans(hereNumOfFans);
}


RockStar::RockStar(RockStar& other)
{
	int length = strlen(other.name) + 1;
	// why not?
	//	delete[] name; 
	name = new char[length];
	strcpy_s(this->name, length, other.name);
	this->awesomeness = other.awesomeness;
	this->numberOfFans = other.numberOfFans;
}

RockStar& RockStar ::  operator=(RockStar& other)
{
	// if?
	int length = strlen(other.name) + 1;
	delete this->name;
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
void RockStar::setAwesomness(int aw)
{
	this->awesomeness = aw;
}

void RockStar::setFans(int fans)
{
	this->numberOfFans = fans;
}
char* RockStar::getName()
{
	return name;
}
int RockStar::getAwesomness()
{
	return awesomeness;
}
int RockStar::getFans()
{
	return numberOfFans;
}

void RockStar::printRS()
{
	cout << "Name : " << getName() << endl << "awwsomness : " << getAwesomness() << endl << "Fans : " << getFans() << endl;
}

// no operators 
// 2.5