#include <iostream>
#include <cstring>
#include "RockStar.h"

using namespace std;

RockStar :: RockStar()

	
{
	char* name = "";
	awesomeness = 0;
	numberOfFans = 0;

}

RockStar::RockStar(char* name, int awesomeness, int numberOfFans){

	this->setName(name);
	this->setAwesomeness(awesomeness);
	this->setNumberOfFans(numberOfFans);
}

RockStar::RockStar(const RockStar& other){

	copy(other);

}

RockStar::~RockStar(const RockStar& other){

	delete(other);
}



RockStar &RockStar :: operator=(const RockStar& other)
{
	if (this != &other) {
		this->awesomeness = other.awesomeness;
		this->name, strlen(name), other.name;
		this->numberOfFans = other.numberOfFans;
	}

	return *this;
}

void RockStar::setAwesomeness(int awesomeness){

	this->awesomeness = awesomeness;
}

void RockStar::setName(const char* name) 
{

	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	delete[] this->name;

}

char* RockStar::getName()const{
	return this->name;
}

int RockStar::getAwesomeness()const {
	return this->awesomeness;
}

int RockStar::getNumberOfFans()const {
	return this->numberOfFans;
}

bool RockStar :: operator<(const RockStar& other) const {

	return this-> awesomeness < other.awesomeness;
}

bool RockStar :: operator>(const RockStar& other) const {

	return this->awesomeness > other.awesomeness;
}

bool RockStar :: operator==(const RockStar& other) const {

	return this->awesomeness == other.awesomeness;
}


void RockStar::print(){

	cout << "Name:" << getName() << endl;
	cout << "Awesomeness:" << getAwesomeness () << endl;
	cout << "NumberOfFans:" << getNumberOfFans() << endl;
}