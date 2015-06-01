#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cassert>
#include <cstring>

using namespace std;

class Date
{
private:
	int day;
	int month;
	int year;
public:
	Date(int day = 1, int month = 1, int year = 2000)
	{
		this->day = day;
		this->month = month;
		this->year = year;
	}
	Date(const Date &other)
	{
		this->day = other.day;
		this->month = other.month;
		this->year = other.year;
	}
	Date operator = (const Date & other)
	{
		this->day = other.day;
		this->month = other.month;
		this->year = other.year;
		return *this;
	}
	void setDay(int day)
	{
		this->day = day;
	}
	void setMonth(int monnth)
	{
		this->month = month;
	}
	void setYear(int year)
	{
		this->year = year;
	}
	int getDay()const
	{
		return day;
	}
	int getMonth()const
	{
		return month;
	}
	int getYear()const
	{
		return year;
	}
};

class BusinessCard
{
private:
	char* name;
	Date birthday;
public:
	BusinessCard(int day = 1, int month = 1, int year = 1990, char* name = " ")
	{
		this->name = new char[strlen(name) + 1];
		assert(this->name != NULL);
		strcpy(this->name, name);
		birthday = Date(day, month, year);
	}
	~BusinessCard()
	{
		delete[]name;
	}
	BusinessCard(const BusinessCard & other)
	{
		this->name = new char[strlen(other.name) + 1];
		assert(this->name != NULL);
		strcpy(this->name, other.name);
		birthday = other.birthday;
	}
	BusinessCard operator = (const BusinessCard & other)
	{
		if (this != &other)
		{
			delete[]name;
			this->name = new char[strlen(other.name) + 1];
			assert(this->name != NULL);
			strcpy(this->name, other.name);
			birthday = other.birthday;
		}
		return *this;
	}
	void printBusinessCard()
	{
		cout << this->birthday.getDay() << " " << this->birthday.getMonth() << " " << this->birthday.getYear() << this->getName() << endl;
	}
	void setName(char* name)
	{
		delete[]name;
		this->name = new char[strlen(name) + 1];
		assert(name);
		strcpy(this->name, name);
	}
	char* getName()const
	{
		return this->name;
	}
	void setBirthday(Date birthday)
	{
		this->birthday = birthday;
	}
	Date getBirthday() const
	{
		return this->birthday;
	}
};

class ListPerson
{
private:
	BusinessCard * businesscards;
	int size;
	int count;
public:
	ListPerson(int size)
	{
		this->businesscards = new BusinessCard[size];
		assert(businesscards);
		this->size = size;
		this->count = 0;
	}
	~ListPerson()
	{
		delete[]businesscards;
		this->size = 0;
		this->count = 0;
	}
	ListPerson(const ListPerson &other)
	{
		this->businesscards = new BusinessCard[other.size];
		assert(businesscards);
		this->size = other.size;
		this->count = other.count;
		for (int i = 0; i < size; i++)
		{
			this->businesscards[i] = other.businesscards[i];
		}
	}
	ListPerson operator = (const ListPerson &other)
	{
		if (this != &other)
		{
			delete[]businesscards;
			this->businesscards = new BusinessCard[other.size];
			assert(other.businesscards);
			this->size = other.size;
			this->count = other.count;
			for (int i = 0; i < size; i++)
			{
				this->businesscards[i] = other.businesscards[i];
			}
		}
		return *this;
	}
	int getSize()const
	{
		return this->size;
	}
void addBusinessCard(BusinessCard businesscard)
	{
		if (size == count)
		{
			size = size * 2;
			BusinessCard * businesscardsR = new BusinessCard[count];
			assert(businesscards);
			for (int i = 0; i < count; i++)
			{
				businesscardsR[i] = businesscards[i];
			}
			delete[]businesscards;
			BusinessCard * businesscards = new BusinessCard[size];
			assert(businesscards);
			for (int i = 0; i < count; i++)
			{
				businesscards[i] = businesscardsR[i];
			}
			delete[]businesscardsR;
		}
		businesscards[count] = businesscard;
		this->count++;
	}
void removeBusinessCard(char* name)
{
	int indexToRemove = 0;
	for (int i = 0; i < this->count; i++)
	{
		if (strcmp(businesscards[i].getName(), name) == 0)
		{
			indexToRemove = i;
			break;
		}
	}
	for (int i = indexToRemove; i < this->count - 1; i++)
	{
		businesscards[i] = businesscards[i + 1];
	}
	this->count--;
}
BusinessCard getSO(char* name)
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(businesscards[i].getName(), name) == 0)
		{
			return businesscards[i];
		}
	}
	return NULL;
}
ListPerson operator +(const ListPerson & lp1)
{
	int newSize= this->size + lp1.getSize();
	ListPerson newList(newSize);
	int i;
	for (i = 0; i < this->count; i++)
	{
		newList.businesscards[i] = this->businesscards[i];
	}
	for (int j = 0; j < lp1.count; j++)
	{
		newList.businesscards[i + j] = lp1.businesscards[j];
	}
	newList.size = newSize;
	newList.count = this->count + lp1.count;
	return newList;
}
ListPerson obBS(const ListPerson& lp1)
{
	int newSize = this->size + lp1.getSize();
	ListPerson newList(newSize);
	int i;
	for (i = 0; i < this->count; i++)
	{
		newList.businesscards[i] = this->businesscards[i];
	}
	for (int j = 0; j < lp1.count; j++)
	{
		newList.businesscards[i + j] = lp1.businesscards[j];
	}
	newList.size = newSize;
	newList.count = this->count + lp1.count;
	return newList;
}
ListPerson razBS(const ListPerson& lp1)
{
	bool contains = false;
	int thisCount = this->count;
	int lp1Count = lp1.count;
	int removesCount = 0;
	for (int i = 0; i < thisCount; i++)
	{
		contains = false;
		for (int j = 0; j < lp1Count; j++)
		{
			if (strcmp(this->businesscards[i - removesCount].getName(), lp1.businesscards[j].getName()) == 0)
			{
				contains = true;
				break;
			}
		}
		if (contains)
		{
			this->removeBusinessCard(this->businesscards[i - removesCount].getName());
			removesCount++;
		}
	}
	return *this;
}
ListPerson secBS(const ListPerson& lp1)
{
	bool contains = false;
	int thisCount = this->count;
	int lp1Count = lp1.count;
	int removesCount = 0;
	for (int i = 0; i < thisCount; i++)
	{
		contains = false;
		for (int j = 0; j < lp1Count; j++)
		{
			if (strcmp(this->businesscards[i - removesCount].getName(), lp1.businesscards[j].getName()) == 0)
			{
				contains = true;
				break;
			}
		}
		if (!contains)
		{
			this->removeBusinessCard(this->businesscards[i - removesCount].getName());
			removesCount++;
		}
	}
	return *this;
}
void printZodiac(char* name)
{
	for (int i = 0; i <count; i++)
	{
		if (strcmp(this->businesscards[i].getName(), name) == 0)
		{
			if ((businesscards[i].getBirthday().getDay() >= 21 && businesscards[i].getBirthday().getMonth() == 3) || (businesscards[i].getBirthday().getDay() <= 21 && businesscards[i].getBirthday().getMonth() == 4))
			{
				cout << "Aries" << endl;
			}
			else if ((businesscards[i].getBirthday().getDay() >= 22 && businesscards[i].getBirthday().getMonth() == 4) || (businesscards[i].getBirthday().getDay() <= 20 && businesscards[i].getBirthday().getMonth() == 5))
			{
				cout << "Taurus" << endl;
			}
			else if ((businesscards[i].getBirthday().getDay() >= 21 && businesscards[i].getBirthday().getMonth() == 5) || (businesscards[i].getBirthday().getDay() <= 20 && businesscards[i].getBirthday().getMonth() == 6))
			{
				cout << "Gemini" << endl;
			}
			else if ((businesscards[i].getBirthday().getDay() >= 21 && businesscards[i].getBirthday().getMonth() == 6) || (businesscards[i].getBirthday().getDay() <= 21 && businesscards[i].getBirthday().getMonth() == 7))
			{
				cout << "Cancer" << endl;
			}
			else if ((businesscards[i].getBirthday().getDay() >= 22 && businesscards[i].getBirthday().getMonth() == 7) || (businesscards[i].getBirthday().getDay() < 23 && businesscards[i].getBirthday().getMonth() == 8))
			{
				cout << "Leo" << endl;
			}
			else if ((businesscards[i].getBirthday().getDay() >= 23 && businesscards[i].getBirthday().getMonth() == 8) || (businesscards[i].getBirthday().getDay() <= 22 && businesscards[i].getBirthday().getMonth() == 9))
			{
				cout << "Virgo" << endl;
			}
			else if ((businesscards[i].getBirthday().getDay() >= 23 && businesscards[i].getBirthday().getMonth() == 9) || (businesscards[i].getBirthday().getDay() <= 22 && businesscards[i].getBirthday().getMonth() == 10))
			{
				cout << "Libra" << endl;
			}
			else if ((businesscards[i].getBirthday().getDay() >= 23 && businesscards[i].getBirthday().getMonth() == 10) || (businesscards[i].getBirthday().getDay() <= 21 && businesscards[i].getBirthday().getMonth() == 11))
			{
				cout << "Scorpius" << endl;
			}
			else if ((businesscards[i].getBirthday().getDay() >= 22 && businesscards[i].getBirthday().getMonth() == 11) || (businesscards[i].getBirthday().getDay() <= 21 && businesscards[i].getBirthday().getMonth() == 12))
			{
				cout << "Sagittarius" << endl;
			}
			else if ((businesscards[i].getBirthday().getDay() >= 22 && businesscards[i].getBirthday().getMonth() == 12) || (businesscards[i].getBirthday().getDay() <= 20 && businesscards[i].getBirthday().getMonth() == 1))
			{
				cout << "Capricorn" << endl;
			}
			else if ((businesscards[i].getBirthday().getDay() >= 21 && businesscards[i].getBirthday().getMonth() == 1) || (businesscards[i].getBirthday().getDay() <= 19 && businesscards[i].getBirthday().getMonth() == 2))
			{
				cout << "Aquaruis" << endl;
			}
			else if ((businesscards[i].getBirthday().getDay() >= 20 && businesscards[i].getBirthday().getMonth() == 2) || (businesscards[i].getBirthday().getDay() <= 20 && businesscards[i].getBirthday().getMonth() == 3))
			{
				cout << "Pisces" << endl;
			}
			return;
		}
	}
	cout << "No person with this name." << endl;
}
void printListPerson()
{
	for (int i = 0; i < this->count; i++)
	{
		this->businesscards[i].printBusinessCard();
	}
}
};
int main()
{
	BusinessCard businessCardOne(1, 1, 2001, "Ivanov");
	BusinessCard businessCardTwo(2, 2, 2002, "Petrov");
	BusinessCard businessCardThree(3, 3, 2003, "Angelov");
	BusinessCard businessCardFour(4, 4, 2004, "Peshev");

	ListPerson listPersonOne(7);

	BusinessCard businessCardFive(5, 5, 2005, "Asenov");
	BusinessCard businessCardSix(6, 6, 2006, "Ignatov");

	ListPerson listPersonTwo(7);

	listPersonOne.addBusinessCard(businessCardOne);
	listPersonOne.addBusinessCard(businessCardTwo);
	listPersonOne.addBusinessCard(businessCardThree);
	listPersonOne.addBusinessCard(businessCardFour);

	listPersonTwo.addBusinessCard(businessCardFour);
	listPersonTwo.addBusinessCard(businessCardFive);
	listPersonTwo.addBusinessCard(businessCardSix);

	/*listPersonOne.removeBusinessCard(businessCardTwo.getName());
	
	listPersonOne.printListPerson();
	cout << endl;

	BusinessCard taken = listPersonOne.getSO(businessCardThree.getName());
	taken.printBusinessCard();*/

	/*ListPerson listPersonThree(0);
	listPersonThree = (listPersonOne + listPersonTwo);
	listPersonThree.printListPerson();*/

	/*ListPerson section = listPersonOne.secBS(listPersonTwo);
	section.printListPerson();*/

	/*ListPerson difference = listPersonOne.razBS(listPersonTwo);
	difference.printListPerson();*/

	listPersonTwo.printZodiac("Ignatov");

	system("pause");
	return 0;
}