#include <iostream>

//Abstrakciq s danni
//Enkapsulaciq
//Nasledqvane
//Polimorfizum

using namespace std;


class Human
{
	char* name;
	int power;
	int loyalty;

protected:
	int size;
	Human* friends[10];
	
public:
	virtual void setName(char*);
	char* getName()const;
	void setPower(int);
	int getPower()const;
	virtual void setLoyalty(int);
	virtual int getLoyalty()const;
	void reducePower(int);
	virtual char* specialSkill()const = 0;

	Human();
	Human(const Human&);
	Human& operator=(const Human&);
	virtual ~Human();
	virtual void addFriend(Human&) = 0;
	virtual void removeFriend(char*) = 0;
	virtual int getRevange()const = 0;

};


void Human::setName(char* newName)
{
	delete[] name;
	int length = strlen(newName) + 1;
	name = new char[length];
	strcpy_s(name, length, newName);
}

char* Human::getName()const
{
	return name;
}

void Human::setPower(int newPower)
{
	power = newPower;
}

int Human::getPower()const
{
	return power;
}

void Human::setLoyalty(int newLoyalty)
{
	loyalty = newLoyalty;
}

int Human::getLoyalty()const
{
	return loyalty;
}

void Human::reducePower(int number)
{

	// > 0?
	// - 0.1
	power -= number;
}

Human::Human() :name(NULL)
{
	setName(" ");
	setPower(0);
	setLoyalty(0);
	size = loyalty;
	
}

Human::Human(const Human& other)
{
	setName(other.name);
	setPower(other.power);
	setLoyalty(other.loyalty);
	size = other.loyalty;

	for (int i = 0; i < size; i++)
	{
		friends[i] = other.friends[i];
	}
}

Human& Human::operator=(const Human& other)
{
	if (this != &other)
	{
		setName(other.name);
		setPower(other.power);
		setLoyalty(other.loyalty);
		size = other.loyalty;
		// not deep
		for (int i = 0; i < size; i++)
		{
			friends[i] = other.friends[i];
		}
	}

	return*this;
}

Human::~Human()
{
	delete[]name;
}

class normalHuman :public Human
{
public:
	char* specialSkill()const;
	int getRevange()const;
	int sumOfPower()const;
	void addFriend(Human&);
	void removeFriend(char*);
	normalHuman();
	normalHuman(const normalHuman&);
	normalHuman& operator=(const normalHuman&);
};

void normalHuman::removeFriend(char* name)
{
	size -= 1;
	// why 100? 
	// leaking memory
	// - 0.2
	Human* newFriends[100];

	for (int i = 0; i < size; i++)
	{
		if (!strcmp(friends[i]->getName(), name))
		{
			newFriends[i] = friends[i];
		}
	}
}

normalHuman::normalHuman() :Human()
{

}

normalHuman::normalHuman(const normalHuman& other) : Human(other)
{

}

normalHuman& normalHuman::operator=(const normalHuman& other)
{
	// if?
	Human::operator=(other);
	return *this;
}

void normalHuman::addFriend(Human& other)
{
	if (strcmp(other.specialSkill(), "none"))
	{
		friends[size] = &other;
		size++;
	}
	
	else
	{
		cout << "ERRO" << endl;
	}
}


char* normalHuman::specialSkill()const
{
	return "none";
}

int normalHuman::getRevange()const
{
	int sum = 0;

	for (int i = 0; i < size; i++)
	{
		sum += friends[i]->getPower();
	}

	return sum;
}

class Targaryen : virtual public Human
{
	int age;
public:
	int getLoyalty()const;
	char* specialSkill()const;
	int getRevange()const;
	void addFriend(Human&);
	int getAge()const;
};

int Targaryen::getAge()const
{
	return age;
}

void Targaryen::addFriend(Human& other)
{
	if (strcmp(other.specialSkill(), "fire"))
	{
		friends[size] = &other;
		size++;
	}
	
	else
	{
		cout << "ERROR" << endl;
	}
}

int Targaryen::getLoyalty()const
{
	return  getLoyalty() + age;
}

char* Targaryen::specialSkill()const
{
	return "fire";
}

int Targaryen::getRevange()const
{
	int sum = 0;

	for (int i = 0; i < size; i++)
	{
		sum += friends[i]->getPower();
	}

	return 2*sum;
}

class Stark:virtual public Human
{
public:
	int getLoyalty()const;
	void setLoyalty(int);
	char* specialSkill()const;
	void addFriend(Human&);
	int getRevange()const;
};

char* Stark::specialSkill()const
{
	return "ice";
}


int Stark::getLoyalty()const
{
	return Human::getLoyalty() + size;
}

void Stark::setLoyalty(int number)
{
	number = size;
	Human::setLoyalty(number);
}

void Stark::addFriend(Human& other)
{
	if (strcmp(other.specialSkill(), "ice") || strcmp(other.specialSkill(), "none"))
	{
		friends[size] = &other;
		size++;
	}

	else
	{
		cout << "ERROR" << endl;
	}
}

int Stark::getRevange()const
{
	int sum = 0;
	int sum1 = 0;
	int sum2 = 0;
	int sum3 = 0;

	for (int i = 0; i < size; i++)
	{
		if (strcmp(friends[i]->specialSkill(), "ice"))
		{
			sum1 += friends[i]->getPower() * 3;
		}

		else if (strcmp(friends[i]->specialSkill(), "fire"))
		{
			sum2 += friends[i]->getPower() * 2;
		}

		else if (strcmp(friends[i]->specialSkill(), "none"))
		{
			sum3 += friends[i]->getPower() * 1;
		}
	}

	sum = sum1 + sum2 + sum3;

	return sum;
}

class TargaryenStark:public Targaryen,public Stark
{
public:
	int getLoyalty()const;
	void setLoyalty(int);
	char* specialSkill()const;
	void addFriend(Human&);
	int getRevange()const;
	void setName(char*);
};

void TargaryenStark::addFriend(Human& other)
{
	friends[size] = &other;
	size++;
}

int TargaryenStark::getLoyalty()const
{
	return Human::getLoyalty() + size + getAge();
}

void TargaryenStark::setLoyalty(int number)
{
	number = size - getAge();
	Human::setLoyalty(number);
}

void TargaryenStark::setName(char* newName)
{
	Human::setName(newName);
	strcat_s(Human::getName(),6," Snow");
}

int TargaryenStark::getRevange()const
{
	int sum = 0;
	int sum1 = 0;
	int sum2 = 0;
	int sum3 = 0;

	for (int i = 0; i < size; i++)
	{
		if (strcmp(friends[i]->specialSkill(), "ice"))
		{
			sum1 += friends[i]->getPower() * 3;
		}

		else if (strcmp(friends[i]->specialSkill(), "fire"))
		{
			sum2 += friends[i]->getPower() * 2;
		}

		else if (strcmp(friends[i]->specialSkill(), "none"))
		{
			sum3 += friends[i]->getPower() * 1;
		}
	}

	sum = sum1 + sum2 + sum3;

	return sum;
}
// some thing no ok 
// - 0.3
class Army
{
protected:
	Human* soldiers[100];
	int size;
	Human* leader;
public:
	virtual void addSoldier(Human&) = 0;
	virtual void removeSoldier(char*) = 0;
	virtual void addLeader(Human&) = 0;
};
// missing stuffs
// - 0.9
int main()
{




	system("pause");
	return 0;
}