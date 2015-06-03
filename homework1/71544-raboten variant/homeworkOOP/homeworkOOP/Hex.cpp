#include <iostream>
#include <assert.h>
#include "Header.h"
#include <string.h>
#include <iomanip>
#include <cmath>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

char Hex::values[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };


void Hex::print()const
{
	cout << "Hex:";
	for (int i = size-2; i>=0; i--)
	{
		cout << hex[i];
	}
	cout << endl;
}
Hex::Hex()
{
	size = 1;
	hex = new char[1];
	hex[0] = '\0';
}
Hex::Hex(const Hex& other)
{
	this->hex = new char[other.size];
	this->size = other.size;
	assert(hex != NULL);
	for (int i = 0; i < other.size -1; i++)
	{
		this->hex[i] = other.hex[i];
	}
	hex[size - 1] = '\0';
}
Hex::Hex(char* hex)
{
	this->size = strlen(hex)+1;
	this->hex = new char[size + 1];
	assert(hex != NULL);
	for (int i = 0; i < size - 1; i++)
	{
		this->hex[i] = hex[size - 2 - i];
	}
	this->hex[size - 1] = '\0';
}
Hex& Hex::operator=(const Hex& other)
{
	if (this != &other)
	{
		delete[]hex;
		this->hex = new char[other.size];
		assert(hex != NULL);
		for (int i = 0; i < other.size -1; i++)
		{
			this->hex[i] = other.hex[i];
		}
		hex[size - 1] = '\0';
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
	char * result = new char[strlen(fromDectoHex(value))+1];
	assert(result != NULL);
	strcpy(result, fromDectoHex(value));
	this->size = strlen(result) + 1;
	this->hex = new char[size];
	for (int i = 0; i < size-1; i++)
	{
		this->hex[i] = result[i];
	}
	hex[size-1] = '\0';
	delete[] result;
	return *this;
}
Hex& Hex::operator-(const Hex& other)
{
	int value = fromHextoDec(*this) - fromHextoDec(other);
	char * result = new char[strlen(fromDectoHex(value)) + 1];
	assert(result != NULL);
	strcpy(result, fromDectoHex(value));
	this->size = strlen(result) + 1;
	this->hex = new char[size];
	for (int i = 0; i < size - 1; i++)
	{
		this->hex[i] = result[i];
	}
	hex[size - 1] = '\0';
	delete[] result;
	return *this;
}
Hex& Hex::operator*(const Hex& other)
{
	int value = fromHextoDec(*this) * fromHextoDec(other);
	char * result = new char[strlen(fromDectoHex(value)) + 1];
	assert(result != NULL);
	strcpy(result, fromDectoHex(value));
	this->size = strlen(result) + 1;
	this->hex = new char[size];
	for (int i = 0; i < size - 1; i++)
	{
		this->hex[i] = result[i];
	}
	hex[size - 1] = '\0';
	delete[] result;
	return *this;
}
Hex& Hex::operator/(const Hex& other)
{
	int value = fromHextoDec(*this) / fromHextoDec(other);
	char * result = new char[strlen(fromDectoHex(value)) + 1];
	assert(result != NULL);
	strcpy(result, fromDectoHex(value));
	this->size = strlen(result) + 1;
	this->hex = new char[size];
	for (int i = 0; i < size - 1; i++)
	{
		this->hex[i] = result[i];
	}
	hex[size - 1] = '\0';
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
	double dec = 0;
	for (int i = 0; i < h.size-1; i++)
	{
		if ((h.hex[i] >= 'A' && h.hex[i] <= 'F') || (h.hex[i] >= '1' && h.hex[i] <= '9') || (h.hex[i] >= 'a' && h.hex[i] <= 'f'))
		{
			int value = 0;
			switch (h.hex[i])
			{
			case 'A': case 'a': value = 10; break;
			case 'B': case 'b': value = 11; break;
			case 'C': case 'c': value = 12; break;
			case 'D': case 'd': value = 13; break;
			case 'E': case 'e': value = 14; break;
			case 'F': case 'f': value = 15; break;
			case '1': value = 1; break;
			case '2': value = 2; break;
			case '3': value = 3; break;
			case '4': value = 4; break;
			case '5': value = 5; break;
			case '6': value = 6; break;
			case '7': value = 7; break;
			case '8': value = 8; break;
			case '9': value = 9; break;
			}
			dec += value * (pow(16, double(i)));
		}
	}
	return (int)dec;
}
char* Hex::fromDectoHex(int integer)
{
	char value[100];
	int i = 0;
	do
	{
		value[i] = values[integer % 16];
		integer /= 16;
		i++;
	} while (integer > 0);

	value[i] = '\0';
	return value;
}
