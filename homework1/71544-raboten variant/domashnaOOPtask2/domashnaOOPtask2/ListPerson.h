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
#ifndef LIST_H
#define LIST_H
#include "Card.h"

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
private:
	Card* cards;
	int size;
	int capacity;

};
#endif