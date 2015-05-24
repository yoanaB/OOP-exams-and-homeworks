/*Задача 2. Визитка на човек съдържа фамилията и датата на раждането му. 
Реализирана е чрез структура. Да се дефинира клас ListPerson за работа с 
картотека от визитки. Класът да съдържа масив от визитки на хора.
Да се реализират методи за добавяне и изтриване на визитка, а също 
за достъп до визитка по указана фамилия. Фамилиите в масива трябва 
да са уникални. Да се реализират операции за обединяване на две
картотеки, за намиране на сечението и на разликата на две картотеки.
Да се дефинира метод, който по зададена фамилия намира зодията на човека.
За целта в класа да се дефинира и масив от структури Zodiac с полета:
название на знака на зодиака, дата на началото и дата на края му.
Да се реализират два варианта на класа: с обикновен масив и със статичен масив.
*/
#include "ListPerson.h"
#include <iostream>
#include <assert.h>
#include <string.h>
using namespace std;


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
		cards = new Card[other.size];
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
	cards = new Card[other.size];
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
		Card* result = new Card[this->size + other.size];
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