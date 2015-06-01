#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;

class Sixteen
{
private:
	char* number;
public:
	Sixteen(char* number = " ")
	{
		this->number = new char[strlen(number) + 1];
		assert(this->number);
		strcpy(this->number, number);
	}
	~Sixteen()
	{
		delete[]this->number;
	}
	Sixteen(const Sixteen & other)
	{
		this->number = new char[strlen(other.number) + 1];
		assert(this->number);
		strcpy(this->number, other.number);
	}
	Sixteen operator = (const Sixteen & other)
	{
		if (this != &other)
		{
			delete[]this->number;
			this->number = new char[strlen(other.number) + 1];
			assert(this->number);
			strcpy(this->number, other.number);
		}
		return *this;
	}
	void setNumber(char* number)
	{
		this->number = new char[strlen(number) + 1];
		assert(this->number);
		strcpy_s(this->number, strlen(number), number);
	}
	char* getNumber()const
	{
		return this->number;
	}
	int convHexToDec(char* number)
	{
		int decimal = 0;
		for (int i = 0; i < strlen(number); i++)
		{
			char currentChar = number[i];
			if ((currentChar >= '0') && (currentChar <= '9'))
			{
				decimal += (currentChar - '0') * pow(16, i);
			}
			else if ((currentChar >= 'A') && (currentChar <= 'F'))
			{
				decimal += (currentChar - 'A' + 10) * pow(16, i);
			}
		}
		return decimal;
	}
	char* convDecToHex(int decimal)
	{
		char* number = new char[100];
		int i = 0;
		int reminder = 0;
		while (decimal)
		{
			reminder = decimal % 16;
			if (reminder < 10)
			{
				number[i] = char(reminder + '0');
			}
			else
			{
				number[i] = char(reminder -10 + 'A');
			}
			i++;
			decimal /= 16;
		}
		char* newNumber = new char[i + 1];
		for (int j = 0; j < i; j++)
		{
			newNumber[j] = number[j];
		}
		newNumber[i] = '\0';
		return newNumber;
	}
	void print()
	{
		cout << this->getNumber() << endl;
	}
	Sixteen operator +(Sixteen & other)
	{
		int sum;
		sum = this->convHexToDec(this->getNumber()) + other.convHexToDec(other.getNumber());
		return Sixteen(convDecToHex(sum));
	}
	Sixteen operator-(Sixteen & other)
	{
		int sub = this->convHexToDec(this->getNumber()) - other.convHexToDec(other.getNumber());
		return Sixteen(convDecToHex(sub));
	}
	Sixteen operator *(Sixteen & other)
	{
		int mult = this->convHexToDec(this->getNumber()) * other.convHexToDec(other.getNumber());
		return Sixteen(convDecToHex(mult));
	}
	Sixteen operator /(Sixteen & other)
	{
		int div = this->convHexToDec(this->getNumber()) / other.convHexToDec(other.getNumber());
		return Sixteen(convDecToHex(div));
	}
	bool operator < (Sixteen & other)
	{
		return this->convHexToDec(this->getNumber()) < other.convHexToDec(other.getNumber());
	}
	bool operator > (Sixteen & other)
	{
		return this->convHexToDec(this->getNumber()) > other.convHexToDec(other.getNumber());
	}
	bool operator == (Sixteen & other)
	{
		return this->convHexToDec(this->getNumber()) == other.convHexToDec(other.getNumber());
	}
	bool operator <= (Sixteen & other)
	{
		return this->convHexToDec(this->getNumber()) <= other.convHexToDec(other.getNumber());
	}
	bool operator >= (Sixteen & other)
	{
		return this->convHexToDec(this->getNumber()) >= other.convHexToDec(other.getNumber());
	}
};

class Hex
{	
private:
	Sixteen * numbers;
	int size;
	int count;
public:
	Hex(int size)
	{
		this->numbers = new Sixteen[size];
		assert(this->numbers);
		this->size = size;
		this->count = 0;
	}
	~Hex()
	{
		delete[]numbers;
	}
	Hex(const Hex &other)
	{
		this->numbers = new Sixteen[other.size];
		assert(this->numbers);
		for (int i = 0; i < count; i++)
		{
			this->numbers[i] = other.numbers[i];
		}
		this->size = other.size;
		this->count = other.count;
	}
	Hex operator = (const Hex & other)
	{
		if (this != &other)
		{
			delete[]numbers;
			this->numbers = new Sixteen[other.size];
			assert(this->numbers);
			for (int i = 0; i < count; i++)
			{
				this->numbers[i] = other.numbers[i];
			}
			this->size = other.size;
			this->count = other.count;
		}
		return *this;
	}
};
int main()
{
	Sixteen test1 ("A1E");
	test1.print();
	Sixteen test2 ("F");
	test2.print();
	Sixteen sum;
	sum = test1 + test2;
	sum.print();
	Sixteen sub;
	sub = test1 - test2;
	sub.print();
	Sixteen mult;
	mult = test1 * test2;
	mult.print();
	Sixteen div = test1 / test2;
	div.print();
	cout << (test1 == test2) << endl;
	cout << (test1 < test2) << endl;
	cout << (test1 > test2) << endl;
	system("pause");
	return 0;
}