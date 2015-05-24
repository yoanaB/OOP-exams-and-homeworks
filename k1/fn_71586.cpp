#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;

//. 1) Да се дефинира клас Programmer, който представлява даден програмист.Нека негови член - данни са :
//•	name - име на програмиста(с променлива дължина)
//•	iq – коефициент на интелигентност(цяло число)
//•	salary – заплата(реално число)
//Да се реализира канонично представяне на класа, set и get функции и функция print за извеждане на информацията за програмиста на екрана.
//Да се предефинират операторите за сравнение(>, <, == ) на програмисти по iq.
//

class Programmer
{
public:
	/*
	Programmer()
	{
		name = new char[1];
		name = "\0";
		this->iq = 120;
		this->salary = 100;

	}
	*/
	//DA PREDIFINIRAM OPERATORI!!!
	/*
	bool operator >(const Programmer& other)
	{
		if (this->iq > other.getIq())
			return true;
		else
			return false;
		
	}
	*/
	bool operator > (const Programmer& other)
	{

		this->iq > other.iq;
		return this;
	}
	bool operator < (const Programmer& other)
	{
		this->iq < other.iq;
		return this;
	}
	bool operator == (const Programmer& other)
	{
		this->iq = other.iq;
		return this;
	}
	
	Programmer(const char* name, int iq, double salary)
			
	{
		this->salary = salary;
		this->iq = iq;
		name = new char[strlen(name) + 1];
		strcpy_s(this -> name,strlen(name) + 1, name);
	
	}
	void printProgrammer() const
	{
		cout << this->name << endl << this->iq << endl << this->salary;
	}
	
	Programmer(char* name = "Misho", int iq = 150, double salary = 5000)
	{
		this->name = new char[strlen(name) + 1];
		assert(this->name != NULL);
		strcpy_s(this->name, strlen(name) + 1, name);
		this->iq = iq;
		this->salary = salary;
		
	}
	Programmer(const Programmer& other)
	{
		copy(other);
	}
	Programmer& operator = (const Programmer& other)
	{
		if (this != &other)
		{
			del();
			copy(other);
		}
		return *this;
	}
	~Programmer()
	{
		del();
	}
	void setName(char* name)
	{
		this->name = new char[strlen(name) + 1];
		assert(this->name != NULL);
		strcpy_s(this->name, strlen(name) + 1, name);
	}
	char* getName() const
	{
		return this->name;
	}
	void setIq(int iq)
	{
		this->iq = iq;
	}
	int getIq() const
	{
		return this->iq;
	}
	void setSalary(double salary)
	{
		this->salary = salary;
	}
	double getSalary()
	{
		return this->salary;
	}
private:
	
	void copy(const Programmer& other)
	{
		this->name = new char[strlen(other.name) + 1];
		assert(this -> name != NULL);
		strcpy_s(this->name, strlen(name) + 1, name);
		this->iq = other.iq;
		this->salary = other.salary;
	}
	void del()
	{
		delete[] name;
	}
	
	char* name;
	int iq;
	double salary;
	
};



class Team
{
public:
	Team()
	{
		

		this->size = 0;
		this -> capacity = 1;
		listOfProgrammers = new Programmer[capacity];

	}
	Team(const Team& other)
	{
		copy(other);
	}
	Team& operator = (const Team& other)
	{
		if (this != &other)
		{
			del();
			copy(other);
		}
		return *this;
	}
	~Team()
	{
		del();
	}
	void addProgrammer(Programmer& other)
	{
		if (this->size == capacity)
		{
			Programmer* temp = listOfProgrammers;
			listOfProgrammers = new Programmer[capacity*2];

			for (int i = 0; i < size; i++)
			{
				listOfProgrammers[i] = temp[i];
			}
			delete[] temp;
			capacity = capacity * 2;
		}
		listOfProgrammers[size++] = other;
	}
	void removeProgrammer(char name)
	{
		for (int i = 0; i < size; i++)
		{
			if (listOfProgrammers[i].getName == name)
			{
				for (int j = i + 1; j < size - 1; j++)
				{
					listOfProgrammers[j] = listOfProgrammers[j + 1];
				}
			}
			size--;
		}
	}
	Programmer& getProgrammer(char name)
	{
		for (int i = 0; i < size; i++)
		{
			if (listOfProgrammers[i].getName == name)
				return listOfProgrammers[i];
		}
	}
	void printProgammerOfList()
	{
		for (int i = 0; i < size; i++)
		{
			listOfProgrammers[i].printProgrammer();
		}
	}
	void sort()
	{
		for (int i = 0; i < size; i++)
		{
			int max = i;
			for (int j = i + 1; j < size - 1, j++)
			{
				if (listOfProgrammers[i].getIq < listOfProgrammers[j].getIq)
					max = j;
			}
			if (max != i)
			{
				swap(listOfProgrammers[max], listOfProgrammers[i]);
			}
		}
	}

	//трябва да вкарам име като база данна
	void operator -=(const Team& team2)
	{
		for (int i = 0; i < size; i++)
		{
			if (listOfProgrammers[i].getName = team2.getName)
			{
				for (int j = i + 1; j < size - 1; j++)
				{
					listOfProgrammers[j] = listOfProgrammers[j + 1];
				}
			}
			size--;
			
		}
	}
private:
	void copy(const Team& other)
	{
		this->size = other.size;
		this -> capacity = other.capacity;
		this->listOfProgrammers = new Programmer[other.capacity];
		for (int i = 0; i < size; i++)
		{
			listOfProgrammers[i] = other.listOfProgrammers[i];
		}
	}
	void del()
	{
		delete[] listOfProgrammers;
	}
	char name[30];
	int size;
	int capacity;
	Programmer* listOfProgrammers;
};



/*
class Company
{
public:
	Company()
	{
		this->size = 0;
		this->capacity = 1;
		listOfProgrammers = new Programmer[capacity];

	}
	Company(const Team& other)
	{
		copy(other);
	}
	Company& operator = (const Company& other)
	{
		if (this != &other)
		{
			del();
			copy(other);
		}
		return *this;
	}
	~Company()
	{
		del();
	}
private:
	void copy(const Company& other)
	{
		this->size = other.size;
		this->capacity = other.capacity;
		this->list = new Company[other.capacity];
		for (int i = 0; i < size; i++)
		{
			listOfProgrammers[i] = other.listOfProgrammers[i];
		}
	}
	int size;
	int capacity;
	Team* list;
};
*/

int main()
{
	Programmer C("gsdfsd", 200, 2222);
	Programmer M, P;
	C > P;
	M.printProgrammer();
	system("pause");
	return 0;
}



//2) Да се дефинира клас Team с дадено име, който съхранява динамичен масив от програмисти, като има следната функционалност :
//•	addProgrammer - добавяне на програмист
//•	removeProgrammer - премахване на програмист по зададенo име
//•	getProgrammer – връща програмист  по зададенo име
//•	print - извежда на екрана информация за всички програмисти
//•	да се предефинира оператор -= , който премахва от подразбиращия се Теаm тези програмисти, които се намират и във втория Team
//Бонус : sort – сортира  програмистите по iq във възходящ ред
//



//3) Да се дефинира клас Company, който съхранява масив от екипи(Теаm), като има следната функционалност :
//•	averageIq – намира средния коефициент на интелигентност на всички програмисти в компанията
//•	print - извежда на екрана информация за всички екипи
//


























