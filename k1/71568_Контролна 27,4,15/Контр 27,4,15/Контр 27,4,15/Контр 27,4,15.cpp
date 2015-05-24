// Контролна.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
//Четирите принципа на ООП:
//1. Абстракция
//2. Наследяване
//3. Капсулация
//4. Контруктури

/*1) Да се дефинира клас Programmer, който представлява даден програмист. Нека негови член-данни са:
•	name - име на програмиста (с променлива дължина)
•	iq – коефициент на интелигентност (цяло число)
•	salary – заплата (реално число)
Да се реализира канонично представяне на класа, set и get функции и функция print за извеждане на информацията за програмиста на екрана.
Да се предефинират операторите за сравнение (>, <, ==) на програмисти по iq.

*/
class Programmer
{
private:
	char *name;
	int iq;
	double salary;
public:
	void Set_name(char* str)
	{
		strcpy_s(name, strlen(str) + 1, str);
	}
	void Set_iq(int a)
	{
		iq = a;
	}
	void Set_salary(double sal)
	{
		salary = sal;
	}
	const char* Get_name()
	{
		return name;
	}
	const int Get_iq()
	{
		return iq;
	}
	const double Get_salary()
	{
		return salary;
	}
	void Print()
	{
		cout << "Name: " << Get_name() << endl <<
			"IQ: " << Get_iq() << endl <<
			"Salary: " << Get_salary() << endl;
	}
	Programmer(char* str = "default", int a = 0, double s = 0)
	{
		if (name)
		{
			delete [] name;
		}
		name = new char[strlen(str) + 1];
		Set_name(str);
		Set_iq(a);
		Set_salary(s);

	}
	~Programmer()
	{
		delete[] name;
	}
	 

};
/*
2) Да се дефинира клас Team с дадено име, който съхранява динамичен масив от програмисти, като има следната функционалност:
•	addProgrammer - добавяне на програмист
•	removeProgrammer - премахване на програмист по зададенo име
•	getProgrammer – връща програмист  по зададенo име
•	print - извежда на екрана информация за всички програмисти
•	да се предефинира оператор  -=, който премахва от подразбиращия се Теаm тези програмисти, които се намират и във втория Team
Бонус: sort – сортира  програмистите по iq във възходящ ред
Да се реализира канонично представяне на класа.
*/
class Team
{
private:
	Programmer *list;
	int count = 0;
public:
	Programmer Get_member(int &i)
	{
		return list[i];
	}
	void Set_count(int a = 1)
	{
		count = a;
	}
	const int Get_count()
	{
		return count;
	}
	Programmer getProgrammer(char * name)
	{
		for (int i = 0; i < count; i++)
		{
			if (list[i].Get_name() == name)
			{
				return list[i];
				break;
			}
		}
	}
	Team()
	{
		list = new Programmer[1];
		Set_count(1);
	}
	void swap(Programmer &a, Programmer &b)
	{
		Programmer c = a;
		a = b;
		b = c;
	}
	void Sort()
	{
	for (int i = 0; i < Get_count()-1; i++)
		{
          for (int j = 0; j < Get_count(); j++)
			{
			  if (Get_member(i).Get_iq() > Get_member(j).Get_iq())
				  swap(Get_member(j), Get_member(i));
			}
		}
	}
	void addProgrammer(Programmer &a)
	{
		if (!list)
		{
			list = new Programmer[1];
			Set_count(Get_count() + 1);
		}
		Programmer* tmp = new Programmer[count];
		for (int i = 0; i < Get_count(); i++)
		{

			tmp[i] = list[i];
		}
		count++;
		delete[] list;
		list = new Programmer[count];
		for (int i = 0; i < count-1; i++)
		{
			list[i] = tmp[i];
		}
		list[count - 1] = a;
		Sort();
	}
	void removeProgrammer(char* name)
	{
		if (count == 0)
		{
			cout << "The list is empty!\n";
		}
		else
		{
			for (int i = 0; i < count; i++)
			{
				if (list[i].Get_name() == name)
				{
					swap(list[i], list[count - 1]);
					break;
				}
			}
			count--;
		}
		Sort();
	}
	void Print()
	{
		if (count == 0) cout << "The list is empty!";
		else
		{

			for (int i = 0; i < count; i++)
			{
				list[i].Print();
				cout << endl;
			}
		}
	}
	~Team()
	{
		delete[] list;
	}
};

/*3) Да се дефинира клас Company, който съхранява масив от екипи(Теаm), като има следната функционалност :
•	averageIq – намира средния коефициент на интелигентност на всички програмисти в компанията
•	print - извежда на екрана информация за всички екипи
Да се реализира канонично представяне на класа.
*/
class Company
{
private:
	Team teams[10];
	int count;
public:
	Company()
	{
		count = 0;
	}
	void Print()
	{
		for (int i = 0; i < 10; i++)
		{
			teams[i].Print();
		}
	}
	int averageIq()
	{
		int sum = 0, a = 0;
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < teams[i].Get_count(); j++)
			{
				if (teams[i].Get_member(j).Get_iq() != 0)
				{
					sum += teams[i].Get_member(j).Get_iq();
					a++;
				}
			}
		}
		return (sum / a);
	}
};
int main()
{
	//Company FMI;
	Programmer ivan = Programmer("Ivan", 120, 5400);
	Programmer b = Programmer("Pesho", 156, 3000);
	Team a;
	a.addProgrammer(ivan);
	a.addProgrammer(b);
	a.Print();
	return 0;
}