//1.Abstraction
//2.Encapsulation
//3.Enheritance
//4.Polymorphism

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

//zad0
class Human
{
public:
	Human(char* nme = "N", int power = 20, int loyalty = 4)
	{
		init(nme, power, loyalty);
	}
	virtual ~Human()
	{
		del();
	}
	Human(const Human& other)
	{
		init(other.name, other.power, other.loyalty);
	}
	Human& operator=(const Human& other)
	{
		if (this != &other)
		{
			del();
			init(other.name, other.power, other.loyalty);
		}
		return *this;
	}
	void setName(char* name)
	{
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
	}
	const char* getName() const
	{
		return name;
	}
	void setLoyalty(int l)
	{
		loyalty = l;
	}
	int getPower() const
	{
		return power;
	}
	void dePow(int n)
	{
		if (n < power) return;
		else power - n;
	}
	bool delFr(char* n)
	{
		int index = -1;
		bool forDel = false;
		for (int i = 0; i < count; i++)
		{
			if (strcmp(this->name, n) == 0)
			{
				index = i;
				forDel = true;
				break;
			}
		}
		if (forDel)
		{
			delete friends[index];
			Human **temp = new Human*[count - 1];
			for (int i = index; i < count - 1; i++)
			{
				friends[i] = friends[i + 1];
			}
			for (int i = 0; i < count - 1; i++)
			{
				temp[i] = friends[i];
			}
			del();
			for (int i = 0; i < count - 1; i++)
			{
				friends[i] = temp[i];
			}
			delete[] temp;
		}
		return forDel;
	}
	virtual int getLoy() const = 0;
	virtual const char* getSkill() = 0;
	virtual int revenge() = 0;
	virtual const char* getType() = 0;
	virtual void addFr(Human &h) = 0;
	
private:
	void init(char* name, int p, int l)
	{
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
		this->power = p;
		this->loyalty = l;
	}
	void del()
	{
		for (int i = 0; i < loyalty; i++)
		{
			delete friends[i];
		}
		delete[] friends;
	}
protected:
	char* name;
	int power;
	int loyalty;
	int count;
	Human **friends;
	
};

class Normal_human : public Human
{
public:
	Normal_human(char* nme = "N", int power = 20, int loyalty = 4) :Human(nme, power, loyalty){}
	Normal_human(const Normal_human& other) : Human(other){}
	Normal_human& operator=(const Normal_human& other)
	{
		if (this != &other)
		{
			Human :: operator=(other);
		}
		return *this;
	}
	virtual const char*getSkill()
	{
		return "none";
	}
	virtual int revenege()
	{
		int sum = 0;
		for (int i = 0; i < count; i++)
		{
			sum += friends[i]->getPower();
		}
		return sum;
	}
	const char* getType() const
	{
		return "normal";
	}
	virtual void addFr(Human& h)
	{
		if ((count == loyalty) || (strcmp(h->getType(), "normal") != 0)) return;
		else 
		{
			friends[count++] = &h;
		}
	}
};

//zad1
class Army
{
public:
	Army(int countW = 0)
	{
		this->countW = 0;
	}
	virtual ~Army()
	{
		delete leader;
		for (int i = 0; i < countW; i++)
		{
			delete warior[i];
		}
	}
	Army(const Army& other)
	{
		leader = other.leader;
		for (int i = 0; i < other.countW; i++)
		{
			this->warior[i] = other.warior[i];
		}
		this->countW = other.countW;
	}
	Army& operator=(const Army& other)
	{
		if (this != &other)
		{
			delete leader;
			for (int i = 0; i < countW; i++)
			{
				delete warior[i];
			}
			leader = other.leader;
			for (int i = 0; i < other.countW; i++)
			{
				this->warior[i] = other.warior[i];
			}
			this->countW = other.countW;
		}
		return *this;
	}
	void addW(Human &h)
	{
		if (countW == 100)
		{
			return;
		}
		*warior[countW++] = h;
	}
	bool delW(char* name)
	{
		int index = -1;
		bool forDel = false;
		for (int i = 0; i < countW; i++)
		{
			if (strcmp(warior[i]->getName(), name) == 0)
			{
				index = i;
				forDel = true;
				break;
			}
		}
		if (forDel)
		{
			delete warior[index];
			Human **temp = new Human*[countW - 1];
			for (int i = index; i < countW - 1; i++)
			{
				warior[i] = warior[i + 1];
			}
			for (int i = 0; i < countW - 1; i++)
			{
				temp[i] = warior[i];
			}
			delete leader;
			for (int i = 0; i < countW; i++)
			{
				delete warior[i];
			}
			for (int i = 0; i < countW - 1; i++)
			{
				warior[i] = temp[i];
			}
			delete[] temp;
		}
		return forDel;
	}
	virtual void addL(Human &h) = 0;
	virtual double getMark() const = 0;
	virtual double getSalary() const = 0;
protected:
	Human *warior[100];
	int countW;
	Human *leader;
};

class Paid_army :public Army
{
public:
	virtual void addL(Human &h)
	{
		if ((strcmp(h->getType(), "normal") == 0) || (strcmp(h->getType(), "fire") == 0))
		{
			leader = &h;
		}
	}
	virtual double getMark() const
	{
		int sumSal = salary*countW;
		int sumL = leader->getLoyalty();
		int sumPow = 0;
		for (int i = 0; i < countW; i++)
		{
			sumPow += warior[i]->getPower();
		}
		return sumL*sumSal + sumPow;
	}
	bool operator>(Paid_army* a)
	{
		return this->getMark() > a->getMark();
	}
private:
	int buget;
	int salary = (buget - 0.2*buget) / countW;
};

class Conscript_army : public Army
{
public:
	virtual void addL(Human* h)
	{
		leader = h;
	}
	virtual double getMark() const
	{
		int sumL = leader->getLoyalty();
		int sumW = 0;
		int sumPow = 0;
		for (int i = 0; i < countW; i++)
		{
			sumW = warior[i]->getLoyalty();
		}
		for (int i = 0; i < countW; i++)
		{
			sumPow += warior[i]->getPower();
		}
		return sumL*sumW + sumPow;
	}
};

//zad2
class Targaryen : virtual public Human
{
public:
	Targaryen(char* nme = "N", int power = 20, int loyalty = 4, int y = 20) : Human(nme, power, loyalty){}
	Targaryen(const Targaryen& other) : Human(other)
	{
		this->years = other.years;
	}
	Targaryen& operator=(const Targaryen& other)
	{
		if (this != &other)
		{
			Human :: operator=(other);
			this->years = other.years;
		}
		return *this;
	}
	virtual int getLoy() const
	{
		return loyalty + years;
	}
	virtual const char* getSkill()
	{
		// wut?? :D
		// fire??
		// :(
		// - 0.1
		return "life";
	}
	virtual void addFr(Targaryen& t)
	{
		if (count == loyalty)
		{
			loyalty *= 2;
			Human **temp = new Human*[loyalty];
			for (int i = 0; i < count; i++)
			{
				temp[i] = friends[i];
			}
			delete[] friends;
			friends = temp;
		}
		*friends[count] = t;
		count++;
	}
	virtual int revenge() const
	{
		int sumP = 0;
		for (int i = 0; i < count; i++)
		{
			sumP += friends[i]->getPower();
		}
		return sumP * 2;
	}
	int getYears() const
	{
		return years;
	}
private:
	void setLoyalty(int l)
	{
		loyalty = l;
	}
	int years;
};

class Stark :virtual public Human
{
public:
	Stark(char* nme = "N", int power = 20, int loyalty = 4) : Human(nme, power, loyalty){}
	Stark(const Stark& other) : Human(other)
	{
		this->years = other.years;
	}
	Stark& operator=(const Stark& other)
	{
		if (this != &other)
		{
			Human :: operator=(other);
			this->years = other.years;
		}
		return *this;
	}
	virtual int getLoy() const
	{
		return loyalty + count;
	}
	void setLoyalty(int l)
	{
		loyalty = l;
	}
	const char* getSkill() const
	{
		return "ice";
	}
	virtual void addFr(Human* h)
	{
		if ((strcmp(h->getType(), "fire") == 0) && countT = 0 && count < loyalty)
		{
			friends[count++] = h;
		}
		else if (((strcmp(h->getType(), "normal") == 0) || (strcmp(h->getType(), "ice") == 0)) && count < loyalty)
		{
			friends[count++] = h;
		}
		else return;
	}
	virtual int revenge() const
	{
		int sum = 0;
		for (int i = 0; i < count; i++)
		{
			if (strcmp(friends[i]->getType(), "fire"))
			{
				sum += 2*friends[i]->getPower();
			}
			else if (strcmp(friends[i]->getType(), "ice"))
			{
				sum += 3*friends[i]->getPower();
			}
			else sum += friends[i]->getPower();
		}
		return sum;
	}
private:
	int countT;
};

class Targaryen_Stark : public Targaryen, public Stark
{
	Targaryen_Stark(char* nme = "N", int power = 20, int loyalty = 4, int y = 20) :Human(nme, power, loyalty), Targaryen(nme, power, loyalty, y), Stark(nme, power, loyalty, y){}
	int getLoy() const
	{
		return loyalty + count + getYears();
	}
	void setLoyalty(int l)
	{
		if ((l - count - getYears()) < 0) return;
		else
			loyalty = l - count - getYears();
	}
	void setName(const char* name)
	{
		strcat("Show", name);
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);

	}
	const char* getSkill() const
	{
		// well :D it cloud be done better  :)
		return "i am the son of fire and ice!";
	}
	void addFriend(Human& h)
	{
		if (count == loyalty)
		{
			loyalty *= 2;
			Human **temp = new Human*[loyalty];
			for (int i = 0; i < count; i++)
			{
				temp[i] = friends[i];
			}
			delete[] friends;
			friends = temp;
		}
		*friends[count] = h;
		count++;
	}
	int getRev() const
	{
		int sum = 0;
		for (int i = 0; i < count; i++)
		{
			if (strcmp(friends[i]->getType(), "fire"))
			{
				sum += 2 * friends[i]->getPower();
			}
			else if (strcmp(friends[i]->getType(), "ice"))
			{
				sum += 3 * friends[i]->getPower();
			}
			else sum += friends[i]->getPower();
		}
		return sum;
	}
};

int main()
{

	return 0;
}
// 6.00