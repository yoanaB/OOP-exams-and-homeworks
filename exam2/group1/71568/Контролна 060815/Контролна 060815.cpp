// Контролна 060815.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cassert>
#include <math.h>
using namespace std;
//Четирите принципа на ООП:
//1.Наследяване
//2.Полиморфизъм
//3.капсулация
//4.Абстракция
//задача 1
struct Musical_skill
{
public:
	const char* getInstrument() const
	{
		return instrument;
	}
	const unsigned short int getSkill()
	{
		return skill;
	}

	void setInstrument(char* _instrument)
	{
		strcpy_s(instrument, strlen(_instrument) + 1, _instrument);
	}
	void setSkill(unsigned short int _skill)
	{
		skill = _skill;
	}

	Musical_skill()
	{
		setInstrument("Piano");
		setSkill(3);
	}
	Musical_skill(Musical_skill& other)
	{
		if (this != &other)
		{
			strcpy_s(instrument, strlen(other.instrument) + 1, other.instrument);
			skill = other.skill;
		}
	}
	Musical_skill& operator = (const Musical_skill& other)
	{
		if (this != &other)
		{
			strcpy_s(instrument, strlen(other.instrument) + 1, other.instrument);
			skill = other.skill;
		}
		return *this;
	}
	void print()
	{
		cout << getInstrument() << endl << getSkill();
	}
	virtual ~Musical_skill()
	{
		//
	}
private:
	char instrument[10];
	unsigned short int skill;
};
// dynamic instrument needed
// - 0.2
class Musician:public Musical_skill
{
public:
	const char* getName()
	{
		return name;
	}
	const unsigned int  getBeauty()
	{
		return beauty;
	}
	const unsigned int getVice()
	{
		return vice;
	}
	virtual double  getfinalBeauty() = 0;
	virtual int getabsVice() = 0;
	const int getNumofSkills()
	{
		return num_of_skills;
	}
	int getBestSkills(int n)
	{
		for (int i = 0; i < getNumofSkills()-1; i++)
		{
			for (int j = i + 1; j < getNumofSkills(); j++)
			{
				if (skills[i].getSkill() < skills[j].getSkill())
					swap(skills[i], skills[j]);
			}
		}
		for (int i = 0; i < n; i++)
		{
			skills[i].print();
			cout << endl;
		}
		// return?? // why print 
		// - 0.2
	}
	
	const int sumofskills()
	{
		int sum = 0;
		for (int i = 0; i < getNumofSkills(); i++)
		{
			sum += skills[i].getSkill();
		}
		return sum;
	}
	virtual void spec()=0;


	void setName(const char* _name)
	{
		delete[] this->name;
		name = new char[strlen(_name + 1)];
		assert(name);
		strcpy_s(name, strlen(_name) + 1, _name);
		
	}
	void setVice(unsigned int _vice)
	{
		vice = _vice;
	}
	void setBeauty(unsigned int _beauty)
	{
		beauty = _beauty;
	}
	
	void swap(Musical_skill &a, Musical_skill &b)
	{
		Musical_skill c = b;
		b = a;
		a = c;
	}
	
	Musician(const Musician& other)
	{
		if (this != &other)
		{
			delete[] name;
			name = new char[strlen(other.name + 1)];
			assert(name);
			strcpy_s(name, strlen(other.name) + 1, other.name);

			beauty = other.beauty;
			vice = other.vice;
			for (int i = 0; i < other.num_of_skills; i++)
			{
				skills[i] = other.skills[i];
			}
		}
	}
	Musician& operator=(const Musician& other)
	{
		if (this != &other)
		{
			delete this;
			delete[] name;
			name = new char[strlen(other.name + 1)];
			assert(name);
			strcpy_s(name, strlen(other.name) + 1, other.name);

			beauty = other.beauty;
			vice = other.vice;
			for (int i = 0; i < other.num_of_skills; i++)
			{
				skills[i] = other.skills[i];
			}
		}
		return *this;
	}
	Musician()
	{
		setName("John");
		beauty = 0;
		vice = 0;
		num_of_skills = 0;
	}
	virtual ~Musician()
	{
		delete[] name;
	}
	
	void print()
	{
		cout << "Name: " << getName() << endl
			<< "Beauty level: " << getBeauty() << endl
			<< "Vice: " << getVice() << endl;
		Musical_skill::print();
	}
	Musical_skill skills[5];
private:
	char* name;
	unsigned int beauty;
	unsigned int vice;
	int num_of_skills;
};
class Rock_musician:virtual public Musician
{
public:
	int getabsVice()
	{
		return getVice();
	}
	double  getfinalBeauty()
	{
		// M_PI?
		// - 0.1
		return (pow(getBeauty(),2)+sumofskills()-getVice()*3);
	}
	
	// should be private...
	void setType(char* _type)
	{
		delete[] type;
		type = new char[strlen(_type) + 1];
		assert(type);
		strcpy_s(type, strlen(_type) + 1, _type);
	}
	const char* getType()
	{
		return type;
	}
	Rock_musician() :Musician()
	{
		setType("Rock");
	}
	Rock_musician( Rock_musician& other)
	{
		if (this != &other)
		{
			Musician::operator=(other);
		}
	}
	Rock_musician& operator=(const Rock_musician& other)
	{
		if (this != &other)
		{
			Musician::operator=(other);
		}
		return *this;
	}
	virtual ~Rock_musician()
	{
		delete[] type;
	}
private:
	char*type;

};
class Chalga_musician:virtual public Musician
{
public:
	int getabsVice()
	{
		return getVice();
	}
	// nope
	// - 0.2
	double  getfinalBeauty()
	{
		return (pow(getBeauty(), 2) + sumofskills() - getVice() * 3);
	}

	void setType(char* _type)
	{
		delete[] type;
		type = new char[strlen(_type) + 1];
		assert(type);
		strcpy_s(type, strlen(_type) + 1, _type);
	}
	const char* getType()
	{
		return type;
	}
	Chalga_musician() :Musician()
	{
		setType("rock_tack");
	}
	Chalga_musician(Chalga_musician& other)
	{
		if (this != &other)
		{
			Musician::operator=(other);
		}
	}
	Chalga_musician& operator=(const Chalga_musician& other)
	{
		if (this != &other)
		{
			Musician::operator=(other);
		}
	}
	virtual ~Chalga_musician()
	{
		delete[] type;
	
	}
	
private:
	char* type;
};
//задача 2
// oo no no no 
// oo o 
// - 0.3

class group:virtual public Rock_musician, virtual public Chalga_musician
{
public:
	const char* getName()
	{
		return gname;
	}
	

	void setName(char* name)
	{
		delete[] gname;
		gname = new char[strlen(name) + 1];
		assert(gname);
		strcpy_s(gname, strlen(name) + 1, name);
	}
	virtual void addMusician(Musician& newm) = 0;
	virtual double avbeauty() = 0;
	virtual ~group()
	{
		delete[] gname;
	}
	Musician* list[20];
private:
	char* gname;
};
class RockGroup:virtual public group
{
public:
	RockGroup()
	{
		setName("Rock'N Rolla");
		count = 0;
	}

	// neeein
	// - 0.3
	void addMusician(Musician& newm)
	{
	*list[count] = newm;
	count++;
	}
	double avbeauty()
	{
		double sum=0;
		for (int i = 0; i <= count; i++)
		{
			sum += *list[i].getfinalBeauty();
		}
	}

private:
	int count;
};
class Chalga_group:public group
{
public:
	Chalga_group()
	{
		setName("Planeta");
	}
	void addMusician(Musician& newm)
	{
		*list[count] = newm;
		count++;
	}
	double avbeauty()
	{
		double sum = 0;
		for (int i = 0; i <= count; i++)
		{
			sum += *list[i].getfinalBeauty();
		}
	}

private:
	int count;
};
// C main??
int _tmain(int argc, _TCHAR* argv[])
{
	
	return 0;
}

// oh...
// missing 
// - 1 .2
// 3.4