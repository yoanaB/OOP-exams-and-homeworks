// Домашна ООП зад 2.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <string>
#include <cstring>

using namespace std;
char str[100];
class Date
{
private:
	unsigned short int day, month, year; 
public:
	const int Get_day()
	{
		return day;
	}
	const int Get_month()
	{
		return month;
	}
	const int Get_year()
	{
		return year;
	}
	void Set_day(unsigned short int &d)
	{
		day = d;
	}
	void Set_month(unsigned short int &m)
	{
		month = m;
	}
	void Set_year(unsigned short int &y)
	{
		year = y;
	}
	Date()
	{
		day = 1;
		month = 1;
		year = 1900;
	}
	Date(unsigned short int &d ,unsigned short int &m,unsigned short  int &y)
	{
		Set_day(d);
		Set_month(m);
		Set_year(y);
	}
	int Un_normal_Date_num(unsigned short int &d, unsigned short int &m, unsigned short int &y)
	{
		int faultnum=0;
		bool good_day;
		bool good_month = m > 0 && m <= 12;
		bool good_year = y > 1900 && y < 2015;
		if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
		{
			good_day = d>0 && d <= 31;
		}
		else {
			if (m == 4 || m == 6 || m == 9 || m == 11)
			{
				good_day = d > 0 && d <= 30;
			}
			else {
				if (m == 2) good_day = d > 0 && d < 29;
				else
				{
					good_day = d>0 && d < 30;
				}
			}
		}
		if (good_day	&&	good_month	&&	good_year) return 9111;
		if (good_day	&&	good_month	&&	! good_year) return 9110;
		if (good_day	&&	! good_month	&&	good_year) return 9101;
		if (good_day	&&	! good_month	&&	! good_year) return 9100;
		if (! good_day	&&	good_month	&&	! good_year) return 9010;
		if (! good_day	&&	good_month	&&	good_year) return 9011;
		if (! good_day	&&	! good_month	&&	! good_year) return 9000;
		if (! good_day	&&	! good_month	&&	good_year) return 9001;


	}
	void Read()
	{
		unsigned short int d, m, y;
		cout << "Enter date(dd/mm/yy): ";
		do
		{
			cin >> d >> m >> y;
			cout << endl;
			if (Un_normal_Date_num(d, m, y) == 9000) cout << "Error: \n1. Invalid day!\n2. Invalid month!\n3. Invalid year!\nTry again:	";
			if (Un_normal_Date_num(d, m, y) == 9001) cout << "Error:\n1. Invalid month! \n2. Invalid year!\nTry again: ";
			if (Un_normal_Date_num(d, m, y) == 9010) cout << "Error:\n1. Invalid day!\n2. Invalid year\nTry again: ";
			if (Un_normal_Date_num(d, m, y) == 9011) cout << "Error:\n1. Invalid day!\n	Try again: ";
			if (Un_normal_Date_num(d, m, y) == 9100) cout << "Error:\n1. Invalid month!\n2. Invalid year\nTry again: ";
			if (Un_normal_Date_num(d, m, y) == 9101) cout << "Error:\n1. Invalid month!\nTry again: ";
			if (Un_normal_Date_num(d, m, y) == 9110) cout << "Error:\n1. Invalid year!\nTry again: ";
		} while (Un_normal_Date_num(d, m, y) != 9111);
		Set_day(d);
		Set_month(m);
		Set_year(y);
	}
	void zodia()
	{
		int d = Get_day();
		int m = Get_month()+1;
		if ((d >= 22 && m == 12) || (d <= 19 || m == 1)) cout << "Capricorn";	//Козирог
		else if ((d >= 20 && m == 1) || (d <= 18 || m == 2)) cout << "Aquarius";		//Водолей
		else if ((d >= 19 && m == 2) || (d <= 20 || m == 3)) cout << "Pisces";			//Риби
		else if ((d >= 21 && m == 3) || (d <= 20 || m == 4)) cout << "Aries";			//Овен
		else if ((d >= 21 && m == 4) || (d <= 20 || m == 5)) cout << "Taurus";			//Телец 
		else if ((d >= 21 && m == 5) || (d <= 20 || m == 6)) cout << "Gemini";			//Близнаци
		else if ((d >= 21 && m == 6) || (d <= 22 || m == 7)) cout << "Cancer";			//Рак
		else if ((d >= 23 && m == 7) || (d <= 22 || m == 8)) cout << "Leo";				//Лъв
		else if ((d >= 23 && m == 8) || (d <= 22 || m == 9)) cout << "Virgo";			//Дева
		else if ((d >= 23 && m == 9) || (d <= 22 || m == 10)) cout << "Libra";			//Везни
		else if ((d >= 23 && m == 10) || (d <= 21 || m == 11)) cout << "Scorpius";		//Скорпион
		else if ((d >= 22 && m == 11) || (d <= 21 || m == 12)) cout << "Sagittarius";	//Стрелец

	}
	void Print()
	{
		cout << "Date: " << Get_day() << ", " << Get_month() << ", " << Get_year() << endl;
		cout << "Zodiac: ";
		zodia();
		cout << endl;
	}
	
};

struct Card
{
private:
	char* name=NULL;
	Date birthdate;
public:
	void Set_name(char* s)
	{
		strcpy_s(name, strlen(s)+1, s);
	}
	const char *Get_name()
	{
		return name;
	}
	Date Get_birthdate()
	{
		return birthdate;
	}
	Card(char* n = "default", Date bdate=Date())
	{
		if (name) delete [] name;
		name = new char[strlen(n)+1];
		Set_name(n);
	}
	void Read()
	{
		cout << "Enter name: "; 
		cin.getline(str, 100);
		if (name) delete[] name;
		name = new char[strlen(str) + 1];
		strcpy_s(name, strlen(str) + 1, str);
		this->birthdate.Read();
	}
	
	void Print()
	{
		cout << "Info: \nName: " << Get_name() << endl;
		this->birthdate.Print();
	
	}

	~Card()
	{
		cout << "Deleting " << Get_name();
		delete[] name;
	}
};
struct Zodiac
{
private:
	char name[10];
	Date begin, end;
public:
	Zodiac()
	{

	}
};
//
/*
Задача 2. Визитка на човек съдържа фамилията и датата на раждането му. Реализирана е чрез структура. 
Да се дефинира клас ListPerson за работа с картотека от визитки. Класът да съдържа масив от визитки на хора. 
Да се реализират методи за добавяне и изтриване на визитка, а също за достъп до визитка по указана фамилия. 
Фамилиите в масива трябва да са уникални. Да се реализират операции за обединяване на две картотеки, за намиране 
на сечението и на разликата на две картотеки. Да се дефинира метод, който по зададена фамилия намира зодията на човека. 
За целта в класа да се дефинира и масив от структури Zodiac с полета: название на знака на зодиака, дата на началото и 
дата на края му. Да се реализират два варианта на класа: с обикновен масив и със статичен масив.
*/

class ListPerson
{
private:
	Card *list=new Card [50];
	int cardsnum = 0;

public:
	ListPerson()
	{
		list;// = new Card[50];
		cardsnum = 0;
	}
	
	void Print()
	{
		for (int i = 0; i < cardsnum; i++)
		{
			list[i].Print();
		}
	}
	Card *More()
	{
		Card *tmp = new Card[cardsnum];
		for (int i = 0; i < cardsnum; i++)
		{
			tmp[i] = list[i];
		}
		
		delete[] list;
		list = new Card[cardsnum * 2];
		for (int i = 0; i < cardsnum; i++)
		{
			list[i]=tmp[i];
		}
		return list;
	}
	
	void Add_card()
	{
		if (cardsnum == 50) More();
		else
		{
			this -> list[cardsnum].Read();
			cardsnum++;
		}
	
	}
	~ListPerson()
	{
		for (int i = 0; i < cardsnum; i++)
		{
			cout << "deleting " << list[i].Get_name();
			delete[] list[i].Get_name();
		}
	}

};


int main()
{
	system("color A");
	ListPerson reg;
	reg.Add_card();
	reg.Add_card();
	reg.Print();
	system("pause");
	return 0;
} 