#include"concert.h"
#include<iostream>

Concert::Concert()
{
	this->capacity = 0;
	this->size = 0;
}
Concert::Concert(int size, int capacity)
{
	this->size = size;
	this->capacity = capacity;
	this->concert = new Band[this->capacity];
}

double Concert::averageAwesomeness(const Concert& other)
{
	double sum = 0;
	for (int i = 0; i < this->size; i++)
	{
		sum = sum + concert[i].
	}

	return (sum / this->size);
}

Concert::~Concert()
{
	delete[]concert;
}