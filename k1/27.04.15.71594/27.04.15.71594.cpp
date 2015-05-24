//abstraction
//inheritance
//encapsulation
//polymorphism

#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;

class Programmer
{
private:
	char* name;
	int iq;
	double salary;
public:
	Programmer(char* name = " ", int iq = 80, double salary = 500)
	{
		this->name = new char[strlen(name) + 1];
		assert(name);
		strcpy(this->name, name);
		this->iq = iq;
		this->salary = salary;
	}
	~Programmer()
	{
		delete[]name;
	}
	Programmer(const Programmer & other)
	{
		this->name = new char[strlen(other.name) + 1];
		assert(name);
		strcpy(this->name, other.name);
		this->iq = other.iq;
		this->salary = other.salary;
	}
	Programmer operator = (const Programmer & other)
	{
		if (this != &other)
		{
			delete[]name;
			this->name = new char[strlen(other.name) + 1];
			assert(name);
			strcpy(this->name, other.name);
			this->iq = other.iq;
			this->salary = other.salary;
		}
		return *this;
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
		return name;
	}
	void setIq(int iq)
	{
		this->iq = iq;
	}
	int getIq()const
	{
		return iq;
	}
	void setSalary(double salary)
	{
		this->salary = salary;
	}
	double getSalary()const
	{
		return salary;
	}
	void printProgrammer()
	{
		cout << this->getName() << " " << this->getIq() << " " << this->getSalary() << endl;
	}
	bool operator ==(const Programmer & other)
	{
		return this->getIq() == other.getIq();
	}
	bool operator >(const Programmer & other)
	{
		return this->getIq() > other.getIq();
	}
	bool operator <(const Programmer & other)
	{
		return this->getIq() < other.getIq();
	}
};
class Team
{
private:
	Programmer * programmers;
	int size;
	int count;
public:
	Team(int size)
	{
		this->programmers = new Programmer[size];
		assert(programmers);
		this->size = size;
		this->count = 0;
	}
	Team(Programmer * programmers = NULL, int count = 0, int size = 0)
	{
		this->programmers = new Programmer[size];
		assert(programmers);
		this->size = size;
		this->count = 0;
	}
	~Team()
	{
		delete[]programmers;
		this->size = 0;
		this->count = 0;
	}
	Team(const Team & other)
	{
		this->programmers = new Programmer[other.size];
		assert(programmers);
		this->size = other.size;
		this->count = other.count;
		for (int i = 0; i < size; i++)
		{
			this->programmers[i] = other.programmers[i];
		}
	}
	Team operator = (const Team & other)
	{
		if (this != &other)
		{
			delete [] programmers;
			this->programmers = new Programmer[other.size];
			assert(programmers);
			this->size = other.size;
			this->count = other.count;
			for (int i = 0; i < size; i++)
			{
				this->programmers[i] = other.programmers[i];
			}
		}
		return *this;
	}
	int getSize()const
	{
		return this->size;
	}
	int getCount()const
	{
		return this->count;
	}
	void addProgrammer(Programmer p1)
	{
		this->programmers[this->count] = *programmers;
		this->count++;
	}
	void removeProgrammer(char*name)
	{
		int removeIndex = 0;
		for (int i = 0; i < count; i++)
		{
			if (strcmp(this->programmers[i].getName(), name) == 0)
			{
				removeIndex = i;
			}
			else return;
		}
		for (int i = removeIndex; i < count-1 ; i++)
		{
			programmers[i] = programmers[i + 1];
		}
		count--;
	}
	void getProgrammer(char* name)
	{
		for (int i = 0; i <count; i++)
		{
			if (strcmp(this->programmers[i].getName(), name) == 0)
			{
				return programmers[i].printProgrammer();
			}
		}
	}
	void printProgrammers()
	{
		for (int i = 0; i < count; i++)
		{
			programmers[i].printProgrammer();
		}
	}
	void sortProgrammers()
	{
		int maxIq = 0;
		for (int i = 0; i < count; i++)
		{
			if (this->programmers[i].getIq() > maxIq)
			{
				Programmer tmp = programmers[i];
				programmers[i] = programmers[i + 1];
				programmers[i + 1] = tmp;
				maxIq = programmers[i].getIq();
			}
		}
	}
	Team operator -= (const Team & other)
	{
		bool isThere = false;
		for (int i = 0; i < this-> count; i++)
		{
			for ( int j = 0; j <other.count; j++)
			{
				isThere = false;
				if (strcmp(this->programmers[i].getName(), other.programmers[j].getName()) == 0)
				{
					isThere = true;
					break;
				}
				if (isThere)
				{
					removeProgrammer(programmers[i].getName());
				}
			}
			
		}
	}
};
class Company
{
private:
	Team * teams;
	int sizeC;
	int countC;
public:
	Company(int size)
	{
		this->teams = new Team[size];
		assert(teams);
		this->sizeC = sizeC;
		this->countC = 0;
	}
	~Company()
	{
		for (int i = 0; i < countC; i++)
		{
			delete[](teams+1);
			this->sizeC = 0;
			this->countC = 0;
		}
		delete[]teams;
	}
	Company(const Team& other)
	{
		this->teams = new Team[other.getSize()];
		assert(teams);
		this->sizeC = other.getSize();
		this->countC = other.getCount();
	}
	void printCompany()
	{
		for (int i = 0; i < countC; i++)
		{
			for (int j = 0; j < countC; j++)
			{
				teams[i].printProgrammers();
			}
			
		}
	}
	/*int averageIq(const Company company)
	{
		int* avIQ;
		avIQ = new int[countC];
		assert(anIQ);
		for (int i = 0; i < this->countC; i++)
		{
			teams[i].sortProgrammers();
			int avIqTeamI = teams[i].programmers[1].getIq() + teams[i].programmers[countC];
			avIQ[i] = avIqTeamI;
		}
		int maxIq = 0;
		int minIq = 200;
		for (int i = 0; i < countC; i++)
		{
			if (avIQ[i] > maxIq)
			{
				maxIq = avIQ[i];
			}
			if (avIQ[i] < minIq)
			{
				minIq = avIQ[i];
			}
		}
		return (minIq + maxIq) / 2;
	}*/
};
int main()
{

	system("pause");
	return 0;
}