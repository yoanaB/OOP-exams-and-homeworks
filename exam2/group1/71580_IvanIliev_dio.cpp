//Енкапсулация,Абстракция,Наследяване,Полиморфизъм
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
struct Musical_skill
{
private:
	char*name;
	int skill;
public:
	Musical_skill()
	{
		skill = 0;
		name = new char[1];
		name[0] = '\0';
	}
	Musical_skill(char* name, int skill)
	{
		this->skill = skill;
		this->name = new char[strlen(this->name) + 1];
		strcpy(this->name, name);
	}
	Musical_skill(const Musical_skill& other)
	{
		skill = other.skill;
		name = new char[strlen(other.name) + 1];
		strcpy(name, other.name);
	}
	~Musical_skill()
	{
		delete[] this->name;
	}
	void setName(char*name)
	{
		delete[] this->name;
		this->name = new char[strlen(this->name) + 1];
		strcpy(this->name, name);
	}
	char* getName() const
	{
		return this->name;
	}
	void setSkill(int skill)
	{
		this->skill = skill;
	}
	int getSkill()
	{
		return this->skill;
	}
	Musical_skill& operator =(const Musical_skill & other)
	{
		if (this != &other)
		{
			delete[] this->name;
			setName(other.getName());
			this->skill = other.skill;
		}
		return *this;
	}
};
class Muzikant
{
private:
	char*name;
	int count = 0;
protected:
	Musical_skill* skills[5];
	int beauty;
	int badHabits;
	int sum;
public:
	Muzikant()
	{
		beauty = 0;
		badHabits = 0;
		name = new char[1];
		name[0] = '\0';
	}
	Muzikant(char*name, int beauty, int badHabits)
	{
		this->beauty = beauty;
		this->badHabits = badHabits;
		this->name = new char[strlen(this->name) + 1];
		strcpy(this->name, name);
	}
	Muzikant(const Muzikant& other)
	{
		beauty = other.beauty;
		badHabits = other.badHabits;
		name = new char[strlen(other.name) + 1];
		strcpy(name, other.name);
		for (unsigned i = 0; i < 5; ++i)
		{
			skills[i] = other.skills[i];
		}
	}
	~Muzikant()
	{
		delete[]this->name;
		// what about skills 
		// - 0.1
	}
	void setName(char*name)
	{
		delete[] this->name;
		this->name = new char[strlen(this->name) + 1];
		strcpy(this->name, name);
	}
	char* getName() const
	{
		return this->name;
	}
	Muzikant& operator =(const Muzikant & other)
	{
		if (this != &other)
		{
			delete[] this->name;
			setName(other.getName());
			this->beauty = other.beauty;
			this->badHabits = other.badHabits;
			// del skills?
			// - 0.1
			for (unsigned i = 0; i < 5; ++i)
			{
				skills[i] = other.skills[i];
			}
		}
		return *this;
	}
	void addMusical_skill(Musical_skill& skill){
		this->skills[this->count] = &skill;
		this->count++;
	}
	virtual void setName() = 0;
	virtual char* getName() = 0;
	virtual int getBeauty() = 0;
	virtual int getBadHabits() = 0;
	virtual int getTheBest() = 0;
	virtual string getType() = 0;
};
class RockMuzikant :public Muzikant
{
	//bad name
	virtual int getTheBest()
	{
		int sum = 0;
		for (int i = 0; i < 5; i++)
		{
			sum = sum + skills[i];
			skills[i] = skills[i + 1];
		}
		return sum;
	}
	virtual int getBeauty()
	{
		return beauty*beauty + getTheBest() - badHabits * 3 * 3.14;
	}
	virtual int getBadHabits()
	{
		return this->badHabits;
	}
	virtual string getType()
	{
		return "rock";
	}
};
class ChalgaMuzikant :public Muzikant
{
private:
	bool race;
public:
	int getBestSkill()
	{
	
	}
	virtual int getBeauty()
	{
		// pow?
		// - 0.1
		return beauty*beauty*beauty*beauty*beauty + badHabits + race*cos(getBestSkill());
	}
	virtual int getBadHabits()
	{
		return this->badHabits;
	}
	virtual string getType()
	{
		return "rock_tack";
	}
};
class Band
{
private:
	char*bandName;
	Muzikant*group[10];
public:
	virtual void addMuzikant(Muzikant& group) = 0;
	virtual void removeMuzikant(char*name) = 0;
	Band()
	{
		bandName = new char[1];
		bandName[0] = '\0';
	}
	Band(char*name)
	{
		this->bandName = new char[strlen(this->bandName) + 1];
		strcpy(this->bandName, name);
	}
	Band(const Band& other)
	{
		bandName = new char[strlen(other.bandName) + 1];
		strcpy(bandName, other.bandName);
		for (unsigned i = 0; i < 5; ++i)
		{
			group[i] = other.group[i];
		}
	}
	~Band()
	{
		delete[]this->bandName;
		// the musicians?
		// - 0.2
	}
	void setName(char*name)
	{
		delete[] this->bandName;
		this->bandName = new char[strlen(this->bandName) + 1];
		strcpy(this->bandName, name);
	}
	char* getName() const
	{
		return this->bandName;
	}
	Band& operator =(const Band & other)
	{
		if (this != &other)
		{
			delete[] this->bandName;
			setName(other.getName());
			//...
			for (unsigned i = 0; i < 5; ++i)
			{
				group[i] = other.group[i];
			}
		}
		return *this;
	};	
};
void main()
{

	system("pause");
}
// - 2
// 3.4