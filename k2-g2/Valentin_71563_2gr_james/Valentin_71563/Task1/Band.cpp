#include<iostream>
using namespace std;
#include "Header.h"
Band::Band(){
	size = 0;
	capacity = 1;
	stars = new RockStar[capacity];
}
Band::~Band(){
	delete[] stars;
}
Band::Band(const Band& other){
	size = other.size;
	capacity = other.capacity;
	stars = new RockStar[capacity];
	for (int i = 0; i < size; i++)
	{
		stars[i] = other.stars[i];
	}
}
Band& Band::operator=(const Band& other){
	if (this != &other){
		delete[] stars;
		size = other.size;
		capacity = other.capacity;
		stars = new RockStar[capacity];
		for (int i = 0; i < size; i++)
		{
			stars[i] = other.stars[i];
		}
	}
	return *this;
}
void Band::print()const{
	for (int i = 0; i < size; i++)
	{
		stars[i].print();
		cout << endl;
	}
}
void Band::removeStar(char* _name){
	for (int i = 0; i < size; i++)
	{
		if (!strcmp(stars[i].getName(), _name)){
			for (int j = i + 1; j < size; j++)
			{
				stars[j - 1] = stars[j];
			}
			--size;
			return;
		}
	}
}
void Band::addStar(const RockStar& other){
	if (size == capacity){
		RockStar* oldStars = stars;
		oldStars = new RockStar[2 * capacity];
		for (int i = 0; i < size; i++)
		{
			stars[i] = oldStars[i];
		}
		delete[] oldStars;
		capacity *= 2;
	}
	stars[size++] = other;
}
RockStar& Band::getStar(char* _name){
	for (int i = 0; i < size; i++)
	{
		if (!strcmp(stars[i].getName(), _name)){
			return stars[i];
		}
	}
}
int Band::numberOfStars()const{
	return size;
}
void Band::sort(){
	bool isSort = true;
	while (isSort){
		isSort = false;
		for (int i = 0; i < size - 1; i++)
		{
			if(stars[i].getAwesomeness() > stars[i + 1].getAwesomeness()){
				RockStar tmp = stars[i];
				stars[i] = stars[i + 1];
				stars[i + 1] = tmp;
				isSort = true;
			}
		}
	}
}
RockStar& Band::pickAFrontman()const{
	return stars[size - 1];
}
int Band::getAwesomenessKoef()const{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += stars[i].getAwesomeness();
	}
	return sum / size;
}