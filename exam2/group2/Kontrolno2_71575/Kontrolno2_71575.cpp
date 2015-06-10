#include <iostream>
#include <cstring>
#include "Kontrolno2_71575.h"

using namespace std;

Human::Human(const char* name, int strenght, int loyalty, Human* friends){
	this->setName(name);
}

Human::Human(const Human& other){
	this->setName(other.name);

}

// Ouch
Human& Human::operator=(const Human& other){
	if (this != &other){
		this->setName = other.name;

	}
	return *this;

	}


Human::~Human(){
	delete[]this->name;
}

void Human::setName(const char* name){
	delete[]this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);

}

char* Human::getName()const{
	return this->name;
}

int Human::getLoyalty()const{
	return this->loyalty;
}

int Human::getStrenght()const{
	return this->strenght;
}

//bool addFriend(Human* friends, int x, )
 //{
//	if ((!strcmp(x->getName()) || ((x->getName(1)->getName() >= 100))
//		{
//		Human*[friends] = x;
//		Human*++;
//		return true;
//		}
//	return false;
//	}

char* Normal_human::getSpecialSkill()const{
	return "none";
}

Normal_human::Normal_human(char* name, int strenght, int loyalty) : Human(name, strenght, loyalty)
{};

Normal_human::Normal_human(const Normal_human& other) : Human(other)
{};

Normal_human& Normal_human :: operator=(const Normal_human& other) {
	if (this != &other){
		Human::operator=(other);
	}
	return *this;
}

int Normal_human::removeFriends(char* name){

}

int Paid_Army::getNoteArmy()const{
	return loyalty*sumSalary + sumStrenght;
}

Army::Army(Human* soldiers, int numberSold, Human* leader) : Human(soldiers, numberSold, leader)
{};

Army::Army(const Army& other) : Human(other)
{};

Army& Army::operator=(const Army& other) {
	if (this != &other){
	Human:operator=(other);
	}
	return *this;
}

int Targaryen::getLoyalty()const{
	return loyalty + age;
}

char* Targaryen::getSpecialSkill()const{
	return "fire";
}

int Stark::getLoyalty()const{
	return loyalty + friends;
}

char* Stark::getSpecialSkill()const{
	return "ice";
}

// - 3
//....
