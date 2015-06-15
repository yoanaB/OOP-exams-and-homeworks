//Абстракция, наследяване, полиморфизъм, капсулация
#include <iostream>
#include <cassert>
#include <math.h>
using namespace std;
struct Musical_skill
{
	char* name;
	int skill;
	Musical_skill()
	
	{
		this->name = new char[1];
		assert(this -> name != NULL);
		strcpy_s(this-> name, 1, "");
		this->skill = 1;
	}
	Musical_skill(const Musical_skill& other)
	{
		this->name = new char[strlen(other.name) + 1];
		assert(this->name != NULL);
		strcpy_s(this->name, strlen(other.name), other.name);
		this->skill = other.skill;
	}
	~Musical_skill()
	{
		delete[] name;
	}
	Musical_skill operator=(const Musical_skill& other)
	{
		if (this != &other)
		{
			delete[] name;
			this->name = new char[strlen(other.name) + 1];
			assert(this->name != NULL);
			strcpy_s(this->name, strlen(other.name), other.name);
			this->skill = other.skill;
		}
		return*this;
	}
	int getSkill()
	{
		return this->skill;
	}

};

class Musicant
{
public:
	Musicant()
	{
		this->name = new char(1);
		assert(this->name != NULL);
		strcpy_s(this->name, 1, "");
		this->size = 0;
		this->beauty = 1;
		this->badAss = 1;
	}
	Musicant(const Musicant& other)
	{
		this->setName(other.getName());
		this-> beauty = other.beauty;
		for (int i = 0; i < size; i++)
		{
			this->skills[i] = other.skills[i];
		}
	}

	virtual ~Musicant()
	{
		delete[] name;
	}

	Musicant& operator = (const Musicant& other)
	{
		if (this != &other)
		{
			delete[] name;
			setName(other.getName());
			for (int i = 0; i < size; i++)
			{
				this->skills[i] = other.skills[i];
			}
		}
		return *this;
	}
	void setName(char* name)
	{
		delete[] name;
		this->name = new char[strlen(name)+1];
		assert(this->name != NULL);
		strcpy_s(this->name, strlen(name) + 1, name );

	}
	char* getName() const
	{
		return this -> name;
	}
	virtual int getBeauty()
	{
		return beauty;
	}
	virtual int getBadAss() 
	{
		return badAss;
	}
	virtual Musical_skill* mostPowerfull(int) = 0;
	virtual char getType() = 0;
	int sumSkills()
	{
		int sum = 0;
		for (int i = 0; i < size; i++)
		{
			sum = sum + skills[i]->getSkill();
		}
		return sum;
	}
	bool SkillMoreThan100()
	{
		for (int i = 0; i < size; i++)
		{
			if (skills[i]->getSkill() > 100)
				return true;
			else
				return false;

		}
	}
	/*int sortSkills()
	{
		int max;
		max = skills[0]->getSkill();
		for (int i = 0; i < size; i++)
		{
			if (max < skills[i + 1]->getSkill())
				max = skills[i + 1]->getSkill();
		}
	}*/

protected:
	int beauty;
	int badAss;
	int size;
	Musical_skill* skills[5];
private:

	char* name;
	
	
};

class Rock : virtual public Musicant
{
public:

	virtual int getBeauty()
	{
		return this->beauty * 2 + sumSkills() - badAss * 3 * 3.14;
	}

	virtual int getBadAss()
	{
		return badAss;
	}
	virtual	char getType()
	{
		return 'r';
	}

private:
};

class Chalga : virtual public Musicant
{
public:
	bool isRom(int rom)
	{
		if (rom > 10)
		return true;
		else return false;
	}

	virtual int getBeauty()
	{
		//return this->beauty * 5 + badAss + rom * cos();
	}

	virtual int getBadAss()
	{
		return badAss;
	}
	virtual	char getType()
	{
		return '4';
	}

private:
};

class Group
{

private:
	char* name;
protected:
	Musicant* people[10];
	int size;
public:
	void setName(char* name)
	{
		delete[] name;
		this->name = new char[strlen(name) + 1];
		assert(this->name != NULL);
		strcpy_s(this->name, strlen(name) + 1, name);

	}
	virtual void addMusicant(Musicant*) = 0;
	virtual void removeMusicant(char*) = 0;
	virtual int averageBeauty() = 0;
	virtual int mark() = 0;
	Group()
	{
		this->name = new char(1);
		assert(this->name != NULL);
		strcpy_s(this->name, 1, "");
		this->size = 0;
	}
	Group(const Group& other)
	{
		this->setName(other.getName());
		this->size = other.size;
		for (int i = 0; i < size; i++)
		{
			this->people[i] = other.people[i];
		}
	}

	virtual ~Group()
	{
		delete[] name;
	}

	Group& operator = (const Group& other)
	{
		if (this != &other)
		{
			delete[] name;
			setName(other.getName());
			for (int i = 0; i < size; i++)
			{
				this->people[i] = other.people[i];
			}
		}
		return *this;
	}

	
	char* getName() const
	{
		return this->name;
	}
};

	class RockGroup : public virtual Group
	{
	public:
		RockGroup() :Group()
		{

		}
		
		virtual void addMusicant(Musicant* a)
		{
			if (a->getType() == 'r')  //if (a->getType() == 'r' && SkillMoreThan100())
			{
				if (size > 9)
					cout << "nqma mqsto";
				else
				{
					people[size] = a;
					size++;
				}
			}
			else
				cout << "ne e dostoen!";
		}
		virtual void removeMusicant(char* name)
		{
			if (size == 0)
				cout << "nqma kakvo da mahash";
			else
			{
				for (int i = 0; i < size; i++)
				{
					if (strcmp(people[i]->getName(), name))
					{

						for (i; i < size - 1; i++)
						{
							people[i] = people[i + 1];

						}
						delete people[size];
						size--;
					}
				}
			}
		}
		virtual int averageBeauty()
		{
			int count;
			int averageBeauty;
			for (int i = 0; i < size; i++)
			{

				count++;
				averageBeauty = people[i]->getBeauty() / count;
			}
			return averageBeauty;
		}
		virtual int mark()
		{
			
			int mark;
			
				for (int i = 0; i < size; i++)
				{
					
					mark = people[i]->sumSkills() - people[i]->getBadAss;
				}
				return mark;
		}
	private:

	};

	class ChalgaGroup : public virtual Group
	{
	public:
		ChalgaGroup() :Group()
		{

		}
		virtual void addMusicant(Musicant* a)
		{
			if (a->getType() == '4' )
			{
				if (size > 9)
					cout << "nqma mqsto";
				else
				{
					people[size] = a;
					size++;
				}
			}
			else
				cout << "ne e dostoen!";
		}
		virtual void removeMusicant(char* name)
		{
			if (size == 0)
				cout << "nqma kakvo da mahash";
			else
			{
				for (int i = 0; i < size; i++)
				{
					if (strcmp(people[i]->getName(), name))
					{

						for (i; i < size - 1; i++)
						{
							people[i] = people[i + 1];

						}
						delete people[size];
						size--;
					}
				}
			}
		}
		virtual int averageBeauty()
		{
			int count;
			int averageBeauty;
			for (int i = 0; i < size; i++)
			{

				count++;
				averageBeauty = people[i]->getBeauty() / count;
			}
			return averageBeauty;
		}
		virtual int mark()
		{

			int mark;

			for (int i = 0; i < size; i++)
			{

				mark = people[i]->sumSkills() + people[i] -> getBeauty();
			}
			return mark;
		}
	private:

	};

	class FolkRockGroup : public ChalgaGroup, public RockGroup
	{
		FolkRockGroup() : Group(), ChalgaGroup(), RockGroup()
		{

		}
		virtual void addMusicant(Musicant* a)
		{

		}
	};


int main()
{

}











