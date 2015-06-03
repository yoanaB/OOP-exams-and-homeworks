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

const char* HNumber::getNumber() const
{
	return number;
}

void HNumber::read()
{
	cout << "Enter number in hexadecimal numeral system(the number of units is the first one!): ";
	do{
		cin.getline(number, 10);
		cin.ignore();
	} while ((*number < '0' || *number > '9') || (*number < 'A' || *number > 'F'));
}

void HNumber::print() const
{
	cout << getNumber();
}

Hex::Hex()
{
	count = 0;
}

Hex :: ~Hex()
{
	delete[] hex;
}

Hex::Hex(const Hex& other)
{
	this->count = other.count;
	for (int i = 0; i < 100; i++)
	{
		this->hex[i] = other.hex[i];
	}
}

Hex& Hex :: operator= (const Hex& other)
{
	if (this != &other)
	{
		delete[] hex;
		this->count = other.count;
		for (int i = 0; i < 100; i++)
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
	if (maxSize == count)
	{
		/*count *= 2;
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
		delete[] temp;*/
		cout << "The array is full!" << endl;
	}
	else hex[count] = a;
}

void Hex::deleteNumber(char* n)
{
	bool number = false;
	for (int i = 0; i < 100; i++)
	{
		if (strcmp(hex[i].getNumber(), n) == 0)
		{
			number = true;
			for (int j = i; j < 100; j++)
			{
				hex[i + 1] = hex[i];
			}
		}
	}
	if (number)
	{
		HNumber* temp = new HNumber[count - 1];
		for (int i = 0; i < count - 1; i++)
		{
			temp[i] = hex[i];
		}
		delete[] hex;
		hex = temp;
	}
	else cout << "Cannot find the number!" << endl;
}

bool HNumber :: operator == (const HNumber &other)
{
	return (strcmp(this->number, other.number) == 0);
}

int HNumber::convertInInt(char* n)
{
	int dec = 0;
	char current;
	for (int i = 0; i < strlen(n); i++)
	{
		current = n[i];
		if (n[i] >= 'A' && n[i] <= 'F')
		{
			dec += (current - 55) * pow(16, i);
		}
		else
		{
			dec += (current - 48) * pow(16, i);
		}
	}
	return dec;
}

char* HNumber::convertInChar(int n)
{
	char* hex = new char[100];

	int index = 0;
	int remainder = 0;
	while (n != 0)
	{
		remainder = n % 16;
		if (remainder < 10)
		{
			hex[index] = char(remainder + 48);
		}
		else
		{
			hex[index] = char(remainder + 55);
		}

		index++;
		n /= 16;
	}

	char* toReturn = new char[index + 1];
	for (int i = 0; i < index; i++)
	{
		toReturn[i] = hex[i];
	}
	toReturn[index] = '\0';

	delete[] hex;
	return toReturn;
}

bool HNumber :: operator > ( HNumber &other)
{
		int sum1 = this->convertInInt(this->number);
		int sum2 = other.convertInInt(other.number);
		
		return (sum1 > sum2);
}

bool HNumber :: operator < (HNumber &other)
{
		int sum1 = this->convertInInt(this->number);
		int sum2 = other.convertInInt(other.number);

		return (sum1 < sum2);
}

bool HNumber :: operator >= (HNumber &other)
{
	return !(this < &other);
}

bool HNumber :: operator <= (HNumber &other)
{
	return !(this > &other);
}

HNumber& HNumber :: operator + ( HNumber &other)
{
	int sum = this->convertInInt(this->number) + other.convertInInt(other.number);
	HNumber* hexNumber = new HNumber(convertInChar(sum));
	return *hexNumber;
}

HNumber& HNumber :: operator - ( HNumber &other)
{
	int sub = this->convertInInt(this->number) - other.convertInInt(other.number);
	HNumber* hexNumber = new HNumber(convertInChar(sub));
	return *hexNumber;
}

HNumber& HNumber :: operator *(HNumber & other)
{
	int pr = this->convertInInt(this->number) * other.convertInInt(other.number);
	HNumber* hexNumber = new HNumber(convertInChar(pr));
	return *hexNumber;
}

HNumber& HNumber :: operator /(HNumber & other)
{
	int del = this->convertInInt(this->number) / other.convertInInt(other.number);
	HNumber* hexNumber = new HNumber(convertInChar(del));
	return *hexNumber;
}

HNumber& HNumber :: operator %(HNumber & other)
{
	int delp = this->convertInInt(this->number) % other.convertInInt(other.number);
	HNumber* hexNumber = new HNumber(convertInChar(delp));
	return *hexNumber;
}

HNumber::HNumber(char* n)
{
	number = new char[strlen(n) + 1];
	strcpy_s(number, strlen(n) + 1, n);
}
