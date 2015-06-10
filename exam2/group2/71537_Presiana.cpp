#include<iostream>
#include<cassert>
#include<cstring>
#include<cmath>
using namespace std;

//Inheritance, Polymorphism, Encapsulation, Abstraction 

class Human
{
public:
	Human(char* name = "", int strenght = 0, int loyalty = 0)
	{
		init(name, strenght, loyalty);
	}
	virtual ~Human()
	{
		delHuman();
	}
	Human(const Human& a)
	{
		init(a.name, a.strenght, a.loyalty);
	}
	

	virtual void setName(char* name)
	{
		this->name = new char[strlen(name) + 1];
		assert(this->name);
		strcpy_s(this->name, strlen(name) + 1, name);
	}
	virtual char* getName() const
	{
		return name;
	}
	virtual void setStrenght(int strenght)
	{
		this->strenght = strenght;
	}
	virtual void setLoyalty(int loyalty)
	{
		this->loyalty = loyalty;
	}
	virtual int getStrenght() const
	{
		return strenght;
	}
	virtual int getLoyalty() const
	{
		return loyalty;
	}
	// decrease?
	bool increaseStrenght(int n)
	{
		if ((strenght - n) > 0)
		{
			strenght -= n;
			return true;
		}
			
		else return false;
	}
	virtual char* getSpecialSkill() const = 0;
	virtual bool addFriend(Human*) = 0;
	virtual bool removeFriend(char* name)
	{
		for (int i = 0; i < countFriends; i++)
		{
			if (!strcmp(friends[i]->getName(), name))
			{
				for (int j = i + 1; j < countFriends; j++)
				{
					this->friends[j - 1] = friends[j];
					countFriends--;
				}
				return true;
				break;
			}
			else return false;
		}
	}
	virtual double getRevenge() const = 0;
	virtual double getSalaryW() const = 0;
	virtual double getSalaryL() const = 0;

 protected:
	char* name;
	int strenght;
	int loyalty;
	Human** friends;
	int countFriends;
private:
	void init(char* name, int strenght, int loyalty)
	{
		this->name = new char[strlen(name) + 1];
		assert(this->name);
		strcpy_s(this->name, strlen(name) + 1, name);
		// size for friends ??
		// - 0.2
		this->strenght = strenght;
		this->loyalty = loyalty;
	}
	void delHuman()
	{
		delete[] name;
		// nice
		for (int i = 0; i < loyalty; i++)
		{
			delete friends[i];
		}
		delete[] friends;
	}
};

class NormalHuman : public Human
{
public:
	NormalHuman(char* name, int strenght, int loyalty) : Human(name, strenght, loyalty){}
	virtual ~NormalHuman() {}
	NormalHuman(const NormalHuman &a): Human(a){}

	virtual char* getSpecialSkill() const
	{
		return "none";
	}
	virtual bool addFriends(Human* a)
	{
		if (countFriends < loyalty)
		{
			if (!strcmp(a->getSpecialSkill(), "none"))
			{
				// ++?
				// - 0.1
				this->friends[countFriends] = a;
				return true;
			}
			return false;
		}
		return false;
	}

	virtual double getRevenge() const
	{
		int sum = 0;
		for (int i = 0; i < countFriends; i++)
		{
			sum += friends[i]->getStrenght();
		}
		return sum;
	}
};

class Army
{
public:
	Army(Human* leader = NULL, int countWar = 0)
	{
		init(leader, countWar);
	}
	virtual ~Army(){}
	Army(const Army&a)
	{
		init(a.leader, a.countWar);
	}
	Army& operator= (const Army &a)
	{
		if (this != &a)
		{
			// delete?
			// - 0.1
			init(a.leader, a.countWar);
		}
		return *this;
	}

	virtual bool addWarrior(Human*) = 0;
	virtual bool removeWarrior() = 0;
	virtual bool changeLeader(Human*) = 0;
	virtual double getValue() const = 0;

protected:
	Human* warriors[100];
	int countWar;
	Human* leader;
private:
	void init(Human* leader, int countWar)
	{
		this->leader = leader;
		this->countWar = countWar;
	}

};

class PaidArmy : public Army
{
public:
	PaidArmy(Human* leader = NULL, int countWar = 0, int salaryL = 0, int budget = 0) : Army(leader, countWar)
	{
		this->salaryL = salaryL;
		this->budget = budget;
	}
	virtual ~PaidArmy() {}
	PaidArmy(const PaidArmy &a) :Army(a)
	{
		this->salaryL = a.salaryL;
		this->budget = a.budget;
	}
	PaidArmy& operator= (const PaidArmy &a)
	{
		if (this != &a)
		{
			Army:: operator= (a);
			this->salaryL = a.salaryL;
			this->budget = a.budget;
		}
	}

	void  setSalaryW()
	{
		this-> salaryW = ((budget - 0.2*salaryL) / countWar);
	}
	double getSalaryW() const
	{
		return salaryW;
	}
	double getSalaryL() const
	{
		return salaryL;
	}

	virtual bool changeLeader(Human* l)
	{
		// leaking memory
		// - 0.1
		if (!strcmp(l->getSpecialSkill(), "none"))
		{
			this->leader = l;
			return true;
		}
		else return false;
	}

	virtual double getValue() const
	{
		double sumSal = 0;
		double sumStr = 0;
		for (int i = 0; i < countWar; i++)
		{
			sumSal =sumSal + warriors[i]->getSalaryW() + leader->getSalaryL();
			sumStr =sumStr + warriors[i]->getStrenght() + leader->getStrenght();
		}
		return leader->getLoyalty() * sumSal + sumStr;
	}
	
	bool operator>(const Army *a)
	{
		if (this->getValue() > a->getValue())
		{
			return true;
		}
		else return false;
	}

protected:
	int budget;
	int salaryL;
	double salaryW;

};

class ConscriptArmy : public Army
{
public:
	ConscriptArmy(Human* leader = NULL, int countWar = 0) : Army(leader, countWar){}
	virtual ~ConscriptArmy() {}
	ConscriptArmy(const ConscriptArmy &a) : Army(a){}
	ConscriptArmy& operator= (const ConscriptArmy &a)
	{
		if (this != &a)
		{
			// leeak...
			Army:: operator = (a);
		}
		return *this;
	}

	virtual bool changeLeader(Human* l)
	{
		// leak...
		this->leader = l;
		return true;
	}
	virtual double getValue() const
	{
		double sumL = 0;
		double sumStr = 0;
		for (int i = 0; i < countWar; i++)
		{
			sumL = sumL + warriors[i]->getLoyalty() + leader->getLoyalty();
			sumStr = sumStr + warriors[i]->getStrenght() + leader->getStrenght();
		}
		return leader->getLoyalty() * sumL + sumStr;
	}
	bool operator>(const Army *a)
	{
		if (this->getValue() > a->getValue())
		{
			return true;
		}
		else return false;
	}

};

class Targaryen : virtual public Human
{
public:
	Targaryen(char* name = "", int strenght = 0, int loyalty = 0, int age = 0) : Human(name, strenght, loyalty)
	{
		this->age = age;
	}
	virtual ~Targaryen() {}
	Targaryen(const Targaryen&a) :Human(a)
	{
		this->age = a.age;
	}
	Targaryen& operator= (const Targaryen &a)
	{
		if (this != &a)
		{
			Human :: operator= (a);
			this->age = a.age;
		}
	}

	 int getCountFriendsT() 
	{
		return countFriends;
	}
	//??
	virtual void setName(char* name)
	{
	}
	virtual char* getName() const
	{
		return name;
	}
	virtual void setStrenght(int strenght)
	{
		this->strenght = strenght;
	}
	//hmm
	virtual void setLoyalty(int loyalty) = 0;

	virtual int getStrenght() const
	{
		return 2*strenght;
	}
	virtual int getLoyalty() const
	{
		return loyalty + age;
	}

	virtual char* getSpecialSkill() const
	{
		return "fire";
	}

	virtual bool addFriend(Human* a)
	{
		if (countFriends < loyalty)
		{
			if (!strcmp(a->getSpecialSkill(), "fire"))
			{
				// ++?
				this->friends[countFriends] = a;
				return true;
			}
			return false;
		}
		return false;
	
	}
	virtual bool removeFriend(char* name)
	{	
		for (int i = 0; i < countFriends; i++)
		{
			if (!strcmp(friends[i]->getName(), name))
			{
				for (int j = i + 1; j < countFriends; j++)
				{
					this->friends[j - 1] = friends[j];
					countFriends--;
				}
				return true;
				break;
			}
			else return false;
		}
	}
	virtual double getRevenge() const
	{
		double sumStr = 0;
		for (int i = 0; i < countFriends; i++)
		{
			sumStr = sumStr + friends[i]->getStrenght();
		}
		return 2 * sumStr;
	}

protected:
	int age;

};

class Stark : virtual public Human
{
public:
	Stark(char* name = "", int strenght = 0, int loyalty = 0) : Human(name, strenght, loyalty){}

	virtual int getCountFriends() 
	{
		return countFriends;
	}
	virtual void setName(char* name)
	{}
	virtual char* getName() const
	{
		return name;
	}
	virtual void setStrenght(int strenght)
	{
		this->strenght = strenght;
	}
	virtual void setLoyalty(int par)
	{
		this->loyalty = par - countFriends;
	}

	virtual int getStrenght() const
	{
		return 3*strenght;
	}
	virtual int getLoyalty() const
	{
		return loyalty + countFriends;
	}

	virtual char* getSpecialSkill() const
	{
		return "ice";
	}
	virtual bool addFriend(Human*a)
	{
		if (countFriends < loyalty)
		{
			if ((a.getCountFriendsT() == 0) || (!strcmp(a->getSpecialSkill(), "none")) || (!strcmp(a->getSpecialSkill(), "ice")))
			{
				// niceee :D

					this->friends[countFriends] = a;
					countFriends++;
					return true;
				}
				else return false;
			}

	}
	virtual bool removeFriend(char* name)
	{
		for (int i = 0; i < countFriends; i++)
		{
			if (!strcmp(friends[i]->getName(), name))
			{
				for (int j = i + 1; j < countFriends; j++)
				{
					this->friends[j - 1] = friends[j];
					countFriends--;
				}
				return true;
				break;
			}
			else return false;
		}
	}
	virtual double getRevenge() const
	{
		// nopee 
		// - 0.2
		double sumStr = 0;
		for (int i = 0; i < countFriends; i++)
		{
			sumStr = sumStr + friends[i]->getStrenght();
		}
		return sumStr;
	}
};

class TargaryenStark : public Stark, public Targaryen
{
public:
	TargaryenStark(char* name = "", int strenght = 0, int loyalty = 0, int age = 0) : Human(name, strenght, loyalty), Targaryen(name, strenght, loyalty), Stark(name, strenght, loyalty){}
	virtual ~TargaryenStark() {}
	TargaryenStark(const TargaryenStark &a) :Human(a), Targaryen(a), Stark(a){}
	TargaryenStark& operator= (const TargaryenStark &a)
	{
		if (this != &a)
		{
			// leak
			Human::operator = (a);
			Targaryen:: operator = (a);
			Stark:: operator= (a);
		}
	}

	virtual void setName(char* name)
	{
		cout << "Snow";
		this->name = new char[strlen(name) + 1];
		assert(this->name);
		strcpy_s(this->name, strlen(name) + 1, name);
	}
	virtual char* getName() const
	{
		return name;
	}
	virtual void setStrenght(int strenght)
	{
		this->strenght = strenght;
	}
	virtual void setLoyalty(int par)
	{
		this->loyalty = par - countFriends - age;
	}

	virtual int getStrenght() const
	{
		return 3 * strenght;
	}
	virtual int getLoyalty() const
	{
		return loyalty + countFriends + age;
	}

	virtual char* getSpecialSkill() const
	{
		cout << "I am the son of" << Targaryen::getSpecialSkill() << " and " << Stark::getSpecialSkill() << "!" << endl;;
	}
	virtual bool addFriend(Human* a)
	{
		if (countFriends < loyalty)
		{
			this->friends[countFriends] = a;
			countFriends++;
			return true;
		}
		else return false;
	}
	virtual bool removeFriend(char* name)
	{
		for (int i = 0; i < countFriends; i++)
		{
			if (!strcmp(friends[i]->getName(), name))
			{
				for (int j = i + 1; j < countFriends; j++)
				{
					this->friends[j - 1] = friends[j];
					countFriends--;
				}
				return true;
				break;
			}
			else return false;
		}
	}
	virtual double getRevenge() const
	{
		double sumStr = 0;
		for (int i = 0; i < countFriends; i++)
		{
			sumStr = sumStr + friends[i]->getStrenght();
		}
		return sumStr;
	}

};
// some stuffs missing 
// - 0.4
int main()
{
	return 0;
}

// 4.90