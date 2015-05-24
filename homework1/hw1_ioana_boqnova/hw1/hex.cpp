#include <iostream>
#include <cstring>
#include <cassert>
#include "Hex.h"

using namespace std;

HNumber::HNumber()
{
	number = new char[2];
	strcpy_s(number, 2, "0");
}

HNumber :: ~HNumber()
{
	delete[] number;
}

HNumber::HNumber(const HNumber& other)
{
	number = new char[strlen(other.number) + 1];
	assert(number);
	strcpy_s(number, strlen(other.number) + 1, other.number);
}

HNumber& HNumber :: operator= (const HNumber& other)
{
	if (this != &other)
	{
		delete[] number;
		number = new char[strlen(other.number) + 1];
		assert(number);
		strcpy_s(number, strlen(other.number) + 1, other.number);
	}
	return *this;
}

void HNumber::setNumber(char* n)
{
	delete[] number;
	number = new char[strlen(n) + 1];
	assert(number);
	strcpy_s(number, strlen(n) + 1, n);
}

char* HNumber::getNumber() const
{
	return number;
}

//void HNumber::read()
//{
//	cout << "Enter number in hexadecimal numeral system(the number of units is the first one!): ";
//	do{
//		cin.getline(number, 10);
//	} while (*number < '0' || *number > '9' || *number < 'A' || *number > 'F');
//}

void HNumber::print() const
{
	cout << getNumber();
}

Hex::Hex()
{
	size = 100;
	count = 0;
}

Hex :: ~Hex()
{
	delete[] hex;
}

Hex::Hex(const Hex& other)
{
	this->size = other.size;
	this->count = other.count;
	for (int i = 0; i < other.size; i++)
	{
		this->hex[i] = other.hex[i];
	}
}

Hex& Hex :: operator= (const Hex& other)
{
	if (this != &other)
	{
		delete[] hex;
		this->size = other.size;
		this->count = other.count;
		for (int i = 0; i < other.size; i++)
		{
			this->hex[i] = other.hex[i];
		}
	}
	return *this;
}

int Hex::getCount() const
{
	return count;
}

void Hex::addNumber(const HNumber& a)
{
	if (size == count)
	{
		size *= 2;
		HNumber* temp = new HNumber[count];
		for (int i = 0; i < count; i++)
		{
			temp[i] = this->hex[i];
		}
		delete[] hex;
		hex = new HNumber[size];
		for (int i = 0; i < count + 1; i++)
		{
			hex[i] = temp[i];
		}
		delete[] temp;
	}
	hex[size] = a;
}

void Hex::deleteNumber(char* n)
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(hex[i].getNumber(), n) == 0)
		{
			for (int j = i; j < size; j++)
			{
				hex[i] = hex[i + 1];
			}
		}
	}
}