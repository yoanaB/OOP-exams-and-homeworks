#include "Hex.h"
#include<iostream>

Hex::Hex(char* number, int size)
{	
	this->setNumber(number);
}

void Hex::setNumber(const char* number)
{
	delete[] this->number;
	this->size = strlen(number);
	this->number = new unsigned char[this->size + 1];
	strcpy_s((char*)this->number, this->size + 1, number);
}

Hex::Hex(const Hex& number)
{
	this->setNumber((char*)number.number);
}

Hex& Hex::operator=(const Hex& number)
{
	if (this == &number)
	{
		return *this;
	}
	else
	{
		this->setNumber((char*)number.number);
		return *this;
	}
}

int Hex::HexToDec() const
{
	if (!strcmp((char*)this->number, ""))
	{
		return 0;
	}
	int result = 0;
	int j = 0;
	for (int i = this->size - 1; i >= 0; i--)
	{
		if (this->number[i] >= '0' && this->number[i] <= '9')
		{
			result = result + (this->number[i] - '0') * pow(16, j);
			j++;
		}
		if (this->number[i] >= 'A' && this->number[i] <= 'F')
		{
			switch (this->number[i])
			{
			case 'A':
				result = result + 10 * pow(16, j); j++;
				break;
			case 'B':
				result = result + 11 * pow(16, j); j++;
				break;
			case 'C':
				result = result + 12 * pow(16, j); j++;
				break;
			case 'D':
				result = result + 13 * pow(16, j); j++;
				break;
			case 'E':
				result = result + 14 * pow(16, j); j++;
				break;
			case 'F':
				result = result + 15 * pow(16, j); j++;
				break;
			}
		}
	}
	return result;
}
bool Hex::operator<(const Hex& other)
{
	return this->HexToDec() < other.HexToDec();
}

bool Hex:: operator>(const Hex& other)
{
	return this->HexToDec() > other.HexToDec();
}

bool Hex::operator==(const Hex& other)
{
	return this->HexToDec() == other.HexToDec();
}

bool Hex::operator!=(const Hex& other)
{
	return !(*this == other);
}

bool Hex:: operator<=(const Hex& other)
{
	return (*this == other) || (*this < other);
}

bool Hex:: operator>=(const Hex& other)
{
	return (*this == other) || (*this > other);
}

void Hex::print() const
{
	std::cout << "Hex:" << this->number << "  " << "Dec:" << this->HexToDec() << std::endl;
}
Hex::~Hex()
{
	delete[] this->number;
}
