//Abstraction
//Encapsulation
//Inheritance
//Polimorphism

#include<iostream>
#include "Header.h"	
using namespace std;

RockStar::RockStar(){
	awesomeness = 0;
	numberOfFans = 0;
	name = new char[1];
	name[0] = '\0';
}
RockStar::RockStar(char* _name = "", int _awesomeness = 0, int _numberOfFans = 0){
	this->awesomeness = _awesomeness;
	this->numberOfFans = _numberOfFans;
	size_t length = strlen(_name) + 1;
	this->name = new char[length];
	strcpy_s(this->name, length, _name);
}
RockStar::~RockStar(){
	delete[] name;
}
RockStar::RockStar(const RockStar& other){
	numberOfFans = other.numberOfFans;
	awesomeness = other.awesomeness;
	size_t length = strlen(other.name) + 1;
	name = new char[length];
	strcpy_s(name, length, other.name);
}
RockStar& RockStar::operator=(const RockStar& other){
	if (this != &other){
		delete[] name;
		numberOfFans = other.numberOfFans;
		awesomeness = other.awesomeness;
		size_t length = strlen(other.name) + 1;
		name = new char[length];
		strcpy_s(name, length, other.name);
	}
	return *this;
}
bool RockStar::operator<(const RockStar& other){
	return (this->awesomeness < other.awesomeness);
}
bool RockStar::operator>(const RockStar& other){
	return (this->awesomeness > other.awesomeness);
}
bool RockStar::operator==(const RockStar& other){
	return (this->awesomeness == other.awesomeness);
}
void RockStar::setName(char* _name){
	delete[] name;
	size_t length = strlen(_name) + 1;
	this->name = new char[length];
	strcpy_s(this->name, length, _name);
}
void RockStar::setAwesomeness(int _awesomeness){
	this->awesomeness = _awesomeness;
}
void RockStar::setNumberOfFans(int _numberOfFans){
	this->numberOfFans = _numberOfFans;
}
char* RockStar::getName()const{
	return name;
}
int RockStar::getAwesomeness()const{
	return awesomeness;
}
int RockStar::getNumberOfFans()const{
	return numberOfFans;
}
void RockStar::print()const{
	cout << "Name: " << this->name << endl;
	cout << "Awesomeness: " << this->awesomeness << endl;
	cout << "Number of fans: " << this->numberOfFans << endl;
}
int main(){
	RockStar a("Valentin", 100, 50000);
	a.print();
	return 0;
}
