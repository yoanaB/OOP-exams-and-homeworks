//Encapsulation, Data Abstraction,Polymorphism and Inheritence
//демек Енкапсулация,Абстракция,Полиморфизъм и Наследяване
#include<iostream>
#include <cstring>
#include "Header.h"
using namespace std;
unsigned Team::lastIQ = 0;
Programmer::Programmer()
{
	name = new char[1];
	name[0] = '\0';
	iq = 0;
	salary = 0;
}
Programmer::Programmer(char* name, int iq, double salary)
{
	this->iq = iq;
	this->salary = salary;
	name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
Programmer::Programmer(const Programmer& other)
{
	copy(other);
}
void Programmer::setName(char* name)
{
	this->name = name;
}
void Programmer::setIQ(int iq)
{
	this->iq = iq;
}
void Programmer::setSalary(double salary)
{
	this->salary = salary;
}
char* Programmer::getName() 
{
	return name;
}
int Programmer::getIQ() 
{
	return iq;
}
double Programmer::getSalary() 
{
	return salary;
}
void Programmer::print()
{
	cout << "Name:" << name<<endl;
	cout << "IQ:" << iq<<endl;
	cout << "Salary:" << salary<<endl;
}
void Programmer::copy(const Programmer& other)
{
	salary = other.salary;
	iq = other.iq;
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
}
Programmer::~Programmer()
{
	del();
}
void Programmer::del()
{
	delete[] name;
}
// noooo 
// - 0.2
int Programmer::operator==(int iq)
{
	if (this->iq == iq )
		return iq;
}
// oh god 
// - 0.2 
int Programmer::operator<(int iq)
{
	if (this->iq < iq)
	{
		return this->iq;
	}
		return iq;
}
// ....
int Programmer::operator>(int iq)
{
	if (this->iq > iq)
	{
		return this->iq;
	}
	return iq;
}
Team::Team() 
{
	size = 0;
	capacity = 1;
	programmers = new Programmer[capacity];
}
Team::Team(const Team& other)
{
	copy(other);
}
void Team::copy(const Team& other)
{
	size = other.size;
	capacity = other.capacity;
	programmers = new Programmer[capacity];

	for (unsigned i = 0; i < size; i++)
	{
		programmers[i] = other.programmers[i];
	}
}
Team::~Team()
{
	del();
}
Programmer Team::getProgrammer(unsigned iq) const
{
	for (unsigned i = 0; i < size; i++)
	{
		//name should be uniq
		if (programmers[i].getIQ() == iq)
		{
			return programmers[i];
		}
	}
}
unsigned Team::getNumberOfProgrammers() const
{
	return size;
}
void Team::del()
{
	delete[] programmers;
}
void Team::extend()
{
	Programmer* oldProgrammers = programmers;
	programmers = new Programmer[2 * capacity];
	for (unsigned i = 0; i < size; i++)
	{
		programmers[i] = oldProgrammers[i];
	}
	delete[] oldProgrammers;
	capacity *= 2;
}
void Team::addProgrammer(const Programmer& programmer)
{
	if (size == capacity)
	{
		extend();
	}
	programmers[size++] = programmer;
	programmers[size - 1].setIQ(lastIQ++);
}
void Team::removeProgrammer(unsigned iq)
{
	// not very good but whateveer..
	for (unsigned i = 0; i < size; i++)
	{
		if (programmers[i].getIQ() == iq)
		{
			for (unsigned j = i + 1; j < size; j++)
			{
				programmers[j - 1] = programmers[j];
			}
			--size;
			return;
		}
	}
}
void Team::print()
{
	for (unsigned i = 0; i < size; i++)
	{
		programmers[i].print();
		cout << endl;
	}
}
void Team::sort()
{
	for (unsigned i = 0; i < size - 1; i++)
	{
		unsigned max = i;

		for (unsigned j = i + 1; j < size; j++)
		{
			if (programmers[max].getIQ() < programmers[j].getIQ())
			{
				max = j;
			}
		}
		if (max != i)
		{
			swap(programmers[max], programmers[i]);
		}
	}
}
Company::Company()
{
	size = 0;
	capacity = 1;
	teams = new Team[capacity];
}
Company::Company(const Company& other)
{
	copy(other);
}
void Company::copy(const Company& other)
{
	size = other.size;
	capacity = other.capacity;
	teams = new Team[capacity];
	for (unsigned i = 0; i < size; i++)
	{
		teams[i] = other.teams[i];
	}
}
void Company::del()
{
	delete[] teams;
}
Company::~Company()
{
	del();
}
void Company::print()
{
	for (unsigned i = 0; i < size; i++)
	{
		teams[i].print();
		cout << endl;
	}
}

// operator = missing
// - 0.5
// no average iq 
// - 0.3
void main()
{
	Programmer c;
	c.setName("Pesho");
	c.setIQ(69);
	c.setSalary(69);
	c.print();
	system("pause");
}

//4.8