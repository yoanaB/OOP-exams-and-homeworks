#include <iostream>
#include "Concert.h"

using namespace std;

Concert::Concert()
	:concert(nullptr), numberBands(0), capacity(0)
{}

Concert::Concert(int numberBands, int capacity)
	: concert(nullptr), numberBands(numberBands), capacity(capacity)
{
	this->concert = new Band*[this->capacity];
}

void Concert::clearBands()
{
	for (int i = 0; i < this->numberBands; i++)
	{
		delete this->concert[i];
	}
	delete[] concert;
}

void Concert::copyStuff(const Concert& other)
{
	this->clearBands();

	this->concert = new Band*[other.capacity];
	for (int i = 0; i < other.numberBands; i++)
	{
		this->concert[i] = new Band(*(other.concert[i]));
	}
	this->numberBands = other.numberBands;
}

Concert::Concert(const Concert& other)
	:concert(nullptr), numberBands(0), capacity(0)
{
	this->clearBands();
	this->copyStuff(other);
}

Concert& Concert::operator=(const Concert& other)
{
	if (this == &other)
		return *this;
	this->clearBands();
	this->copyStuff(other);
	return *this;
}

Concert::~Concert()
{
	this->clearBands();

}

double Concert::getAveAwesomeness()
{
	double awesomeness = 0;
	for (int i = 0; i < this->numberBands; i++)
	{
		awesomeness += (*this->concert[i]).getAverageAwesomeness();
	}
	return awesomeness / this->numberBands;
}

Band Concert::getHeadliners()
{
	int index = 0;
	for (int i = 0; i < this->numberBands; i++)
	{
		if ((*this->concert[i]).getAverageAwesomeness() > (*this->concert[index]).getAverageAwesomeness())
		{
			index = i;
		}
	}

	return (*this->concert[index]);
}


int main()
{
	RockStar first("Hetfield", 100, 5);

	first.print();


	system("pause");
	return 0;
}