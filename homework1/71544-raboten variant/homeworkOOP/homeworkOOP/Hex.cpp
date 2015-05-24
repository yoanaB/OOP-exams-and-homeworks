#include <iostream>
#include <assert.h>
#include "Header.h"
#include <string.h>
#include <iomanip>
#include <cmath>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

void Hex::print()const
{
	cout << "Hex:" << this->hex << endl;
}
Hex::Hex()
{
	size = 1;
	hex = new char[1];
	hex[0] = '\0';
}
Hex::Hex(const Hex& other)
{
	this->hex = new char[other.size+1];
	assert(hex != NULL);
	for (int i = 0; i < other.size + 1; i++)
	{
		this->hex[i] = other.hex[i];
	}
}
Hex::Hex(char* hex)
{
	this->size = strlen(hex);
	this->hex = new char[size + 1];
	assert(hex != NULL);
	for (int i = 0,j=size-1; i < size + 1; i++,j--)
	{
		this->hex[i] = hex[j];
	}
}
Hex& Hex::operator=(const Hex& other)
{
	if (this != &other)
	{
		delete[]hex;
		this->hex = new char[other.size + 1];
		assert(hex != NULL);
		for (int i = 0; i < other.size + 1; i++)
		{
			this->hex[i] = other.hex[i];
		}
	}
	return *this;
}
Hex::~Hex()
{
	delete[]hex;
}

Hex& Hex::operator+(const Hex& other)
{
	int value = fromHextoDec(*this) + fromHextoDec(other);
	char*result=_itoa(value,hex, 16);
	this->size = strlen(result);
	this->hex = new char[strlen(result) + 1];
	assert(this != NULL);
	for (int i = 0,j=size-1; i < size; j--,i++)
	{
		hex[i] = result[j];
	}
	hex[size] = '\0';
	delete[] result;
	return *this;
}
Hex& Hex::operator-(const Hex& other)
{
	int value = fromHextoDec(*this) - fromHextoDec(other);
	char*result = _itoa(value, hex, 16);
	this->size = strlen(result);
	this->hex = new char[strlen(result) + 1];
	assert(this != NULL);
	for (int i = 0, j = size-1; i < size; j--, i++)
	{
		hex[i] = result[j];
	}
	hex[size] = '\0';
	delete[] result;
	return *this;
}
Hex& Hex::operator*(const Hex& other)
{
	int value =( fromHextoDec(*this) ) * ( fromHextoDec(other));
	char*result = _itoa(value, hex, 16);
	this->size = strlen(result);
	this->hex = new char[strlen(result) + 1];
	assert(this != NULL);
	for (int i = 0, j = size-1; i < size; j--, i++)
	{
		hex[i] = result[j];
	}
	hex[size] = '\0';
	delete[] result;
	return *this;
}
Hex& Hex::operator/(const Hex& other)
{
	int value = fromHextoDec(*this) / fromHextoDec(other);
	char*result = _itoa(value, hex, 16);
	this->size = strlen(result);
	this->hex = new char[strlen(result) + 1];
	assert(this != NULL);
	for (int i = 0, j = size; i < size; j--, i++)
	{
		hex[i] = result[j];
	}
	hex[size] = '\0';
	delete[] result;
	return *this;
}

bool Hex::operator>(const Hex& other)
{
	return fromHextoDec(*this) > fromHextoDec(other);
}
bool Hex::operator==(const Hex& other)
{
	return fromHextoDec(*this) == fromHextoDec(other);
}
bool Hex::operator<(const Hex& other)
{
	return !(*this >= other);
}
bool Hex::operator<=(const Hex& other)
{
	return !(*this>other);
}
bool Hex::operator>=(const Hex& other)
{
	return (*this > other && *this == other);
}
bool Hex::operator!=(const Hex& other)
{
	return !(*this == other);
}
int Hex::fromHextoDec(const Hex& h)
{
	int result = 0;
	for (int i = 0; i<h.size; i++) {
		if (h.hex[i] >= 48 && h.hex[i] <= 57)
		{
			result += (h.hex[i] - 48)*pow(16, h.size - i - 1);
		}
		else if (h.hex[i] >= 65 && h.hex[i] <= 70) {
			result += (h.hex[i] - 55)*pow(16, h.size - i - 1);
		}
		else if (h.hex[i] >= 97 && h.hex[i] <= 102) {
			result += (h.hex[i] - 87)*pow(16, h.size - i - 1);
		}
	}
	return result;
}
