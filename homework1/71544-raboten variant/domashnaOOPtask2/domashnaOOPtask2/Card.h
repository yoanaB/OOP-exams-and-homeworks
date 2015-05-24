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
#ifndef CARD_H
#define CARD_H

struct Card
{
public:
	void setName(char*);
	void setDay(int);
	void setYear(int);
	void setMonth(int);
	char* getName()const;
	void print()const;
	int getDay();
	int getMonth();
	int getYear();
	void getDate();
	~Card();
	Card();
	Card(int, int, int, char*);
	Card& operator=(const Card&);
	Card(const Card&);
	bool operator==(const Card&)const;
	
private:
	char*name;
	int day;
	int month;
	int year;
};
#endif