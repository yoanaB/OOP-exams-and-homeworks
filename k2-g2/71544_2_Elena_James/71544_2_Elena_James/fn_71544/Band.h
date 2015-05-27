/*
2) Да се дефинира клас  Band с дадено име, който съхранява динамичен масив 
от звезди , като има следната функционалност:
addStar- добавяне на звезда
removeStar- премахване на звезда по зададенo име
getStar- връща звезда  по зададенo име
print - извежда на екрана информация за всички рок звезди
да се предефинира оператор  += , който да обединява 2 банди като избира 
най-добрите  5 звезди и ги оставя в резултата.
Да се реализира канонично представяне на класа.
Бонус: pickAFrontman- избира най-яката звезда в групата и я връща като фронтмен.
Бонус:  Тестове в кода  с имена на истински рок звезди вероятно ще повлияе добре на оценките ви.*/

#ifndef BAND_H
#define BAND_H
#include "Rockstar.h"

class Band
{
public:
	void setName(char*);
	char* getName()const;
	void setSize(int);
	int getSize()const;
	void setCap(int);
	int getCap()const;

	Band();
	Band(char*, Rockstar*,int ,int);
	Band(const Band&);
	Band& operator=(const Band&);
	~Band();

	void print();

	void addStar(const Rockstar&);
	bool removeStar(const Rockstar&);
	Rockstar& getStar(char*);

	Band operator+=(const Band&);
	Band bestFive();
	void sort();
	double avAw();

	Rockstar& pickAFrontman()const;

private:
	char*name;
	Rockstar* stars;
	int size;
	int capacity;
};

#endif