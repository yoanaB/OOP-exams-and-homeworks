#include "ListPerson.h"
#include <iostream>
#include <assert.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

void Zodiac::print()const
{
	cout << "Name:" << name << endl
		<< "Start Date:" << startDay << '/' << startMonth << endl;
	cout << "Final Date:" << finalDay << '/' << finalMonth <<endl;

}
void Zodiac::setName(char*name)
{
	this->name = new char[strlen(name) + 1];
	assert(this->name != NULL);
	strcpy_s(this->name, strlen(name) + 1, name);
}
void Zodiac::setStartDay(int startDay)
{
	this->startDay = startDay;
}
void Zodiac::setFinalDay(int finalDay)
{
	this->finalDay = finalDay;
}

char* Zodiac::getName()const
{
	return name;
}
int Zodiac::getStartDay()
{
	return this->startDay;
}
int Zodiac::getStartMonth()
{
	return this->startMonth;
}
int Zodiac::getFinalDay()
{
	return this->finalDay;
}
int Zodiac::getFinalMonth()
{
	return this->finalMonth;
}
Zodiac::Zodiac(char*name, int startDay, int startMonth, int finalDay, int finalMonth) :name(NULL)
{
	this->name = new char[strlen(name) + 1];
	assert(this->name != NULL);
	strcpy_s(this->name, strlen(name) + 1, name);
	this->startDay = startDay;
	this->startMonth = startMonth;
	this->finalDay = finalDay;
	this->finalMonth = finalMonth;

}

void ListPerson::print()const
{
	for (int i = 0; i < size; i++)
	{
		cards[i].print();
	}
	cout << "size:" << size;
}
ListPerson::~ListPerson()
{
	delete[]cards;
	delete[]zod;
}
ListPerson::ListPerson()
{
	cards = new Card[1];
	size = 0;
	capacity = 1;
}
ListPerson::ListPerson(int size)
{
	cards = new Card[1];
	this->size = size;
	capacity = 1;
}
ListPerson::ListPerson(int size,int capacity,Card* cards)
{
	cards = new Card[size];
	assert(this != NULL);
	for (int i = 0; i < size; i++)
	{
		this->cards[i] = cards[i];
	}
	this->size = size;
	this->capacity = capacity;
}
ListPerson& ListPerson::operator=(const ListPerson& other)
{
	if (this != &other)
	{
		delete[]cards;
		cards = new Card[other.capacity];
		assert(this != NULL);
		for (int i = 0; i < other.size; i++)
		{
			this->cards[i] = other.cards[i];
		}
		this->size = other.size;
		this->capacity = other.capacity;
	}
	return *this;
}
ListPerson::ListPerson(const ListPerson& other) :cards(NULL)
{
	cards = new Card[other.capacity];
	assert(this != NULL);
	for (int i = 0; i < other.size; i++)
	{
		this->cards[i] = other.cards[i];
	}
	this->size = other.size;
	this->capacity = other.capacity;
}
bool ListPerson::addCard(const Card& newOne)
{
	if (newOne == getCard(newOne.getName()))
		return false;

	else
	{
		if (size == capacity)
		{
			capacity *= 2;
			Card* old = cards;
			cards = new Card[capacity];

			for (int i = 0; i < size; ++i)
			{
				cards[i] = old[i];
			}
			delete[] old;
		}
		cards[size++] = newOne;
		return true;
	}
}
bool ListPerson::removeCard(char*name)
{
	bool isFound = false;
	for (int i = 0; i < size - 1; i++)
	{
		if (cards[i] == getCard(name))
		{
			isFound = true;
			for (int j = i + 1; j < size; j++)
			{
				cards[j - 1] = cards[j];
			}
		}
	}
	if (!isFound)
	{
		if (cards[size - 1] == getCard(name))
		{
			--size;
			isFound = true;
		}
	}
	else
	{
		size--;
	}
	return isFound;
}
Card& ListPerson::getCard(char*name)const
{
	for (int i = 0; i < size; i++)
	{
		if (!strcmp(cards[i].getName(), name))
		{
			return cards[i];
		}

	}
}
ListPerson ListPerson::unionList(const ListPerson&other)
{
		removeSame(other);
		Card* result = new Card[(this->size + other.size)*2];
		for (int i = 0; i < this->size; i++)
		{
			result[i]=this->cards[i];
		}
		for (int i = this->size, j = 0; i < this->size + other.size; i++, j++)
		{
			result[i] = other.cards[j];
		}
		this->size += other.size;
		this->capacity = size * 2;
		delete[]this->cards;
		this->cards = result;
		
		return *this;
}

ListPerson ListPerson::sameCards(const ListPerson& other)
{
	Card* result = new Card[this->size];
	for (int i = 0; i < this->size; i++)
	{
		for (int j = 0; j < other.size; j++)
		{
			if (cards[i] == other.cards[j])
			{
				result[i] = cards[i];
			}
		}
	}
	delete[]this->cards;
	this->cards = result;

	return *this;
}
ListPerson& ListPerson::removeSame(const ListPerson& other)
{
	if (this == &other)
	{
		delete[]cards;
		ListPerson();
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < other.size; j++)
			{
				if (!strcmp(cards[i].getName(), other.cards[j].getName()))
				{
					removeCard(cards[i].getName());
				}
			}
		}
	}
	return *this;
}
void ListPerson::readZodiac()
{
	int size;
	char name[21];
	int startDay, startMonth, finalDay, finalMonth;
	cout << "Enter number of zodiacs:";
	cin >> size;
	this->zodiacSize = size;
	for (int i = 0; i < size; i++)
	{
		cout << "Enter zodiac name:";
		cin >> name;
		cout << endl << "Enter zodiac start day and month:";
		cin >> startDay >> startMonth;
		cout << endl << "Enter zodiac final day and month:";
		cin >> finalDay >> finalMonth;
		cout << endl;
		zod[i]=Zodiac(name, startDay, startMonth, finalDay, finalMonth);
	}

}
void ListPerson::printZodiacs()
{
	for (int i = 0; i < zodiacSize; i++)
	{
		zod[i].print();
	}
}
void ListPerson::getZodiac(char* name)
{
	Zodiac z[12];
	z[0]=Zodiac("Aries", 21, 3, 20, 4);
	z[1]=Zodiac("Taurus", 21, 4, 21, 5);
	z[2]=Zodiac("Gemini", 22, 5, 21, 6);
	z[3]=Zodiac("Cancer", 22, 6, 22, 7);
	z[4]=Zodiac("Leo", 23, 7, 22, 8);
	z[5]=Zodiac("Virgo", 23, 8, 23, 9);
	z[6]=Zodiac("Libra", 24, 9, 23, 10);
	z[7]=Zodiac("Scorpio", 24, 10, 23, 11);
	z[8]=Zodiac("Sagittarius", 23, 11, 21, 12);
	z[9]=Zodiac("Capricorn", 22, 12, 20, 1);
	z[10]=Zodiac("Aquarius", 21, 1, 19, 2);
	z[11]=Zodiac("Pisces", 20, 2, 20, 3);

	int i;
	bool person = false;
	for (i = 0; i < size; i++)
	{
		if (!strcmp(name, cards[i].getName()))
		{
			person = true;
			break;
		}
	}
	if (person)
	{
		for (int j = 0; j < 12; j++)
		{
			bool isBeforeDay = z[j].getStartDay() <= cards[i].getDay();
			bool isSameStartMonth = z[j].getStartMonth() == cards[i].getMonth();
			bool isAfterDay = z[j].getFinalDay() >= cards[i].getDay();
			bool isSameEndMonth = z[j].getFinalMonth() == cards[i].getMonth();
			bool condition = (isBeforeDay && isSameStartMonth) || (isAfterDay && isSameEndMonth);
			if (condition)
			{
				cout << cards[i].getName() << " zodiac is: " << z[j].getName();
			}
		}
	}
}
