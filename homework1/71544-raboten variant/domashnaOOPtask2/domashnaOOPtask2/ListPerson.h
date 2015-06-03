#ifndef LIST_H
#define LIST_H
#include "Card.h"

struct Zodiac {
public:
	void setName(char*);
	void setStartDay(int);
	void setStartMonth(int);
	void setFinalDay(int);
	void setFinalMonth(int);
	Zodiac(char*, int, int, int, int);
	char* getName()const;
	void print()const;
	int getStartDay();
	int getStartMonth();
	int getFinalDay();
	int getFinalMonth();

	Zodiac() {
		name = new char[1];
		name[0] = '\0';
		startDay=0, startMonth=0, finalDay=0, finalMonth = 0;
	}
private:
	char*name;
	int startDay;
	int startMonth;
	int finalDay;
	int finalMonth;
};

class ListPerson
{
public:
	~ListPerson();
	ListPerson();
	ListPerson(int);
	ListPerson(int,int,Card*);
	ListPerson& operator=(const ListPerson&);
	ListPerson(const ListPerson&);
	bool addCard(const Card&);
	bool removeCard(char*);
	Card& getCard(char*)const;
	ListPerson unionList(const ListPerson&);
	ListPerson sameCards(const ListPerson&);
	ListPerson& removeSame(const ListPerson&);
	void print()const;
	bool Unique(char*);
	void readZodiac();
	void printZodiacs();
	void getZodiac(char*);
private:
	Card* cards;
	int size;
	int capacity;
	Zodiac* zod;
	int zodiacSize;
};
#endif
