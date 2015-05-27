#include "RockStar.h"
#include <iostream>
#include <iomanip>
using namespace std;

void RockStar::setName(char* name){
	delete[] this->name;
	int length = strlen(name) + 1;
	this->name = new char[length];
	strcpy_s(this->name, length, name);
}

void RockStar::setAwesomeness(int awesomeness){
	this->awesomeness = awesomeness;
}

void RockStar::setNumberOfFans(int num){
	this->numberOfFens = num;
}

void RockStar::setRockStar(char* name, int awesomeness, int fans){
	setName(name);
	setAwesomeness(awesomeness);
	setNumberOfFans(fans);
}

RockStar::RockStar(char* name, int awesomeness, int fans):name(nullptr){
	setRockStar(name, awesomeness, fans);
}

RockStar::~RockStar(){
	delete[] this->name;
}

RockStar::RockStar(const RockStar& other):name(nullptr){
	setRockStar(other.name,other.awesomeness, other.numberOfFens);
}

RockStar& RockStar::operator=(const RockStar& right){
	if (this != &right)
		setRockStar(right.name, right.awesomeness, right.numberOfFens);
	return *this;
}

void RockStar::print() const{
	cout << setw(10) << this->name <<" Awesomeness: "<< this->awesomeness << " Fans: " << this->numberOfFens << endl;
}

bool RockStar::operator>(const RockStar& right){
	return this->awesomeness > right.awesomeness;
}

bool RockStar::operator<(const RockStar& right){
	return this->awesomeness < right.awesomeness;
}

bool RockStar::operator==(const RockStar& right){
	return this->awesomeness == right.awesomeness;
}
