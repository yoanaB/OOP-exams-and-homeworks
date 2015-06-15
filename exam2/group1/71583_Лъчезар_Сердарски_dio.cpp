//abstrakciq, kapsulirane, nasledqvane, polimorfizam
#include <iostream>
#include <cstring>
#include <cassert>
#include <cmath>
using namespace std;
class Musical_skill
{
public:
	Musical_skill(char* name = "", int skill = 0) : skill(skill)
	{
		this->name = new char[strlen(name) + 1];
		assert(this->name != 0);
		strcpy(this->name, name);
	}
	~Musical_skill()
	{
		delete name;
	}
	Musical_skill(const Musical_skill& other)
	{
		name = new char[strlen(other.name) + 1];
		assert(name != 0);
		strcpy(name, other.name);
		skill = other.skill;
	}
	Musical_skill& operator=(const Musical_skill& other)
	{
		if (this != &other)
		{
			delete name;
			name = new char[strlen(other.name) + 1];
			assert(name != 0);
			strcpy(name, other.name);
			skill = other.skill;
		}
		return *this;
	}
	void setName(char* name)
	{
		// delete the old one?
		// - 0.1
		this->name = new char[strlen(name) + 1];
		assert(this->name != 0);
		strcpy(this->name, name);
	}
	void setSkill(int skill)
	{
		this->skill = skill;
	}
	int getSkill()const
	{
		return skill;
	}
private:
	char* name;
	int skill;
};
class Musican
{
public:
	Musican()
	{
		name = "";
		beauty = 0;
		porok = 0;
		skillNum = 0;
		// wut
		// - 0.2
		skills[skillNum].setName("");
		skills[skillNum].setSkill(0);
	}
	~Musican()
	{
		delete[] name;
	}
	Musican(const Musican& other)
	{
		name = new char[strlen(other.name) + 1];
		assert(name != 0);
		strcpy(name, other.name);
		beauty = other.beauty;
		porok = other.porok;
		skillNum = other.skillNum;
		for (int i = 0; i < other.skillNum; i++)
		{
			skills[i] = other.skills[i];
		}
	}
	Musican& operator=(const Musican& other)
	{
		if (this != &other)
		{

			// delete skills? 
			// - 0.1
			delete name;
			name = new char[strlen(other.name) + 1];
			assert(name != 0);
			strcpy(name, other.name);
			beauty = other.beauty;
			porok = other.porok;
			skillNum = other.skillNum;
			for (int i = 0; i < other.skillNum; i++)
			{
				skills[i] = other.skills[i];
			}
		}
		return *this;
	}
	void addSkill(const Musical_skill newSkill)
	{
		if (skillNum < 5)
		{

			skills[skillNum] = newSkill;
			skillNum++;
			sortSkills();
		}
		else cout << "Not enough space" << endl;
	}
	void sortSkills()
	{
		for (int i = 0; i < skillNum-1; i++)
		{
			for (int j = i; j < skillNum; j++)
			{
				if (skills[i].getSkill() < skills[j].getSkill())
					swap(skills[i], skills[j]);
			}
		}
	}
	int sumSkills()const
	{
		int sum = 0;
		for (int i = 0; i < skillNum; i++)
		{
			sum += skills[i].getSkill();
		}
		return sum;
	}
	virtual void set_name(char*) = 0;
	virtual char* get_name()const = 0;
	virtual int get_beauty()const = 0;
	virtual int get_porok()const = 0;
	virtual void type()const = 0;
	virtual Musical_skill* take_n_skills(int) = 0;
protected:
	char* name;
	int beauty;
	int porok;
	int skillNum;
	Musical_skill skills[5];
};
class Rock : public Musican
{
public:
	virtual void set_name(char* name)
	{
		//..
		this-> name = new char[strlen(name) + 1];
		assert(name != 0);
		strcpy(this->name, name);
	}
	virtual char* get_name()const
	{
		return name;
	}
	virtual int get_beauty()const
	{
		// oh .. 3,14??
		// - 0.2
		return beauty*beauty + sumSkills() - get_porok()*3*3,14;
	}
	virtual int get_porok()const
	{
		return porok;
	}
	virtual void type()const
	{
		// - 0.1
		cout << "Rock" << endl;
	}
	virtual Musical_skill* take_n_skills(int n)
	{
		Musical_skill best[5];
		for (int i = 0; i < n; i++)
		{
			best[i] = skills[i];
		}
		// not ok
		return best;
	}
};

// - 2.3