#include "Band.h"
#include <iostream>

void Band::setBand(char* name, RockStar* members, int size, int capacity){
	delete[] this->name;
	int length = strlen(name) + 1;
	this->name = new char[length];
	strcpy_s(this->name, length, name);

	delete[] this->members;
	this->members = new RockStar[capacity];
	for (int i = 0; i < size; i++){
		this->members[i] = members[i];
	}
	this->capacity = capacity;
	this->size = size;
}

Band::Band(char* name, int capacity):name(nullptr), members(nullptr){
	setBand(name, nullptr, 0, capacity);
}

Band::~Band(){
	delete[] this->name;
	delete[] this->members;
}

Band::Band(const Band& other) :name(nullptr), members(nullptr){
	setBand(other.name, other.members, other.size, other.capacity);
}

Band& Band::operator=(const Band& other){
	if (this != &other)
		setBand(other.name, other.members, other.size, other.capacity);
	return *this;
}

void Band::addStar(const RockStar& newMember){
	if (size == capacity){
		capacity *= 2;
		RockStar* temp = members;
		this->members = new RockStar[capacity];
		for (int i = 0; i < size; i++){
			this->members[i] = temp[i];
		}
		delete[] temp;
	}
	this->members[size] = newMember;

	//сортиране по awesomeness
	for (int i = size; i > 0; i--){
		if (members[i] < members[i - 1]){
			RockStar temp = members[i];
			members[i] = members[i - 1];
			members[i - 1] = temp;
		}
	}
	size++;
}

void Band::removeStar(char* name){
	for (int i = 0; i < size; i++){
		if (!(strcmp(this->members[i].name, name))){
			RockStar temp = members[i];
			members[i] = members[size - 1];
			members[size - 1] = temp;
			break;
		}
		size--;
	}
}
RockStar error;
RockStar& Band::getStar(char* name){
	for (int i = 0; i < size; i++){
		if (!(strcmp(this->members[i].name, name))){
			return members[i];
		}
	}
	return error;
}

void Band::print() const{
	for (int i = 0; i < size; i++){
		members[i].print();
	}
}

Band& Band::operator+=(const Band& right){
	for (int i = 0; i < size; i++){
		bool flag = true;
		for (int j = 0; j < right.size; j++){
			if (!(strcmp(members[i].name,right.members[j].name)))
				flag = false;
		}
		if (flag){
			this->addStar(right.members[i]);
		}
	}
	this->size = 5;
	
	return *this;
}

RockStar& Band::pickAFrontman() const{
	return members[size - 1];
}