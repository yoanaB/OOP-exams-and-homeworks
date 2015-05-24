/*Задача 2. Визитка на човек съдържа фамилията и датата на раждането му.
Реализирана е чрез структура. Да се дефинира клас ListPerson за работа с
картотека от визитки. Класът да съдържа масив от визитки на хора. Да се
реализират методи за добавяне и изтриване на визитка, а също за достъп до
визитка по указана фамилия. Фамилиите в масива трябва да са уникални.
Да се реализират операции за обединяване на две картотеки, за намиране
на сечението и на разликата на две картотеки. Да се дефинира метод, който
по зададена фамилия намира зодията на човека. За целта в класа да се дефинира
и масив от структури Zodiac с полета: название на знака на зодиака, дата на
началото и дата на края му. Да се реализират два варианта на класа:
с обикновен масив и със статичен масив.
*/
#include <iostream>
#include <assert.h>
#include <string.h>
#include "Card.h"
using namespace std;


void Card::print()const
{
	cout << "Date:" << day << '/' << month << '/' << year << endl
		<< "Name:" << name << endl;
}
void Card::setName(char*name)
{
	this->name = new char[strlen(name) + 1];
	assert(this->name != NULL);
	strcpy(this->name, name);
}
void Card::setDay(int day)
{
	this->day = day;
}
void Card::setYear(int year)
{
	this->year = year;
}

char* Card::getName()const
{
	return name;
}
int Card::getDay()
{
	return day;
}
int Card::getMonth()
{
	return month;
}
int Card::getYear()
{
	return year;
}
void Card::getDate()
{
	cout << day << '/' << month << '/' << year << endl;
}
Card::~Card()
{
	delete[]name;
}
Card::Card()
{
	this->day = 1;
	this->month = 1;
	this->year = 1900;
	this->name = new char[1];
	name[0] = '\0';
}
Card::Card(int day, int month, int year, char* name)
{
	this->day = day;
	this->month = month;
	this->year = year;
	this->name = new char[strlen(name) + 1];
	assert(name != NULL);
	strcpy(this->name, name);
}
Card& Card::operator=(const Card& other)
{
	if (this != &other)
	{
		delete[]name;
		this->day = other.day;
		this->month = other.month;
		this->year = other.year;
		this->name = new char[strlen(other.name) + 1];
		assert(name != NULL);
		strcpy(this->name, other.name);
	}
	return *this;
}
bool Card::operator==(const Card& other)const
{
	return !(strcmp(this->name, other.name));
}
Card::Card(const Card&other) :name(NULL), day(NULL), month(NULL), year(NULL)
{
	this->day = other.day;
	this->month = other.month;
	this->year = other.year;
	this->name = new char[strlen(other.name) + 1];
	assert(name != NULL);
	strcpy(this->name, other.name);
}