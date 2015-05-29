//Abstrcton,Inharitance,Encapsulation,Polymorphism
#include<iostream>
#include<cstring>
#include<cassert>

using namespace std;

class RockStar
{
public:
	RockStar();
	RockStar(char*, int, int);
	~RockStar();
	RockStar(const RockStar&);
	RockStar& operator=(const RockStar&);
	void setName(char*);
	void setAwesomeness(int);
	void setNumberOfFens(int);
	char* getName() const;
	int getAwesomeness() const;
	int getNumberOfFens() const;
	void print() const;
	bool operator> (const RockStar&);
	bool operator< (const RockStar&);
	bool operator== (const RockStar&);


private:
	char* name;
	int awesomeness;
	int numberOfFens;
};
RockStar::RockStar()
{
	this->name = new char[1];
	name[0] = '\0';
	this->awesomeness = 0;
	this->numberOfFens = 0;

}
RockStar::RockStar(char* name, int awesomeness, int numberOfFen) :
name(NULL)
{
	this->setName(name);
	this->awesomeness = awesomeness;
	this->numberOfFens = numberOfFens;
}
RockStar::~RockStar()
{
	delete[] this->name;
}
RockStar::RockStar(const RockStar& other) :
name(NULL)
{
	this->setName(other.name);
	this->awesomeness = other.awesomeness;
	this->numberOfFens = other.numberOfFens;
}
RockStar& RockStar:: operator=(const RockStar& other)
{
	if (this != &other)
	{
		this->setName(other.name);
		this->awesomeness = other.awesomeness;
		this->numberOfFens = other.numberOfFens;
	}
	return *this;
}

void RockStar::setName(char* name)
{
	delete[] this->name;
	size_t length = strlen(name) + 1;
	this->name = new char[length];
	assert(this->name != NULL);
	strcpy_s(this->name, length, name);
}

void RockStar::setAwesomeness(int aswesomeness)
{
	this->awesomeness = awesomeness;
}
void  RockStar::setNumberOfFens(int numberOfFens)
{
	this->numberOfFens = numberOfFens;
}
char*  RockStar::getName() const
{
	return this->name;
}
int RockStar::getAwesomeness() const
{
	return this->awesomeness;
}
int RockStar::getNumberOfFens() const
{
	return this->numberOfFens;
}
void RockStar::print() const
{
	cout << "Name:" << name << endl;
	cout << "Awesomeness" << awesomeness << endl;
	cout << "Number of fans:" << numberOfFens << endl;
}
bool RockStar:: operator> (const RockStar& other)
{
	return (this->getAwesomeness() > other.getAwesomeness());
}
bool RockStar:: operator< (const RockStar& other)
{
	return (this->getAwesomeness() < other.getAwesomeness());
}
bool RockStar:: operator== (const RockStar& other)
{
	return (this->getAwesomeness() == other.getAwesomeness());
}

class Band
{
public:
	void setName(char*);
	char* getName() const;
	Band();
	~Band();
	Band(const Band&);
	Band& operator= (const  Band&);
	bool removeStar(char*);
	void addStar(RockStar&);
	void print() const;
	RockStar getStar(char*);
	bool sort();
	RockStar pickAFrontman();

private:
	char* name;
	RockStar* bands;
	int count;
	int capacity;
	void del();
	void cpy(const Band&);
};
void Band::del()
{
	delete[] this->bands;
}
void Band::cpy(const Band& other)
{
	this->count = other.count;
	this->capacity = other.capacity;
	this->bands = new RockStar[capacity];
	for (int i = 0; i < count; i++)
	{
		bands[i] = other.bands[i];
	}

}
void Band::setName(char* name)
{
	delete[] this->name;
	size_t length = strlen(name) + 1;
	this->name = new char[length];
	assert(this->name != NULL);
	strcpy_s(this->name, length, name);
}
char* Band::getName() const
{
	return this->name;
}
Band::Band()
{
	this->name = new char[1];
	name[0] = '\0';
	this->count = 0;
	this->capacity = 1;
	this->bands = new RockStar[capacity];


}
Band :: ~Band()
{
	delete[] this->name;
	delete[] this->bands;
}
Band::Band(const Band& other) :
name(NULL)
{
	this->setName(other.name);
	del();
	cpy(other);
}
Band& Band:: operator= (const  Band& other)
{
	this->setName(other.name);
	del();
	cpy(other);
}

// what about decreasing the size 
// - 0.2
bool Band::removeStar(char* name)
{
	for (int i = 0; i < count; i++)
	{
		if (strcmp(bands[i].getName(), name) == 0)
		{
			bands[i] = bands[i + 1];
			return true;
		}
		return false;
	}

}

void Band::addStar(RockStar& other)
{
	if (count == capacity)
	{
		capacity *= 2;
		RockStar* tmp = bands;
		bands = new RockStar[capacity];
		for (int i = 0; i < count; i++)
		{
			bands[i] = tmp[i];
		}
		delete[] tmp;

	}
	bands[count++] = other;
}
void Band::print() const
{
	cout << "Name:" << name << endl;
	for (int i = 0; i < count; i++)
	{
		bands[i].print();
	}
	cout << endl;

}
RockStar Band::getStar(char* name)
{
	for (int i = 0; i < count; i++)
	{
		if (strcmp(bands[i].getName(), name) == 0)

		{
			// return would be wonderfull
			// - 0.1
			bands[i].print();
		}
	}
}
bool Band::sort()
{
	bool isNotSorted = true;
	while (isNotSorted)
	{
		isNotSorted = false;
		for (int i = 0; i < count - 1; i++)
		{
			if (bands[i].getAwesomeness() > bands[i + 1].getAwesomeness())
				isNotSorted = true;
		}
	} return false;
}

// they are not stored sorted??
// - 0.1
RockStar Band::pickAFrontman()
{
	return this->bands[count - 1];
}

class Concert
{
public:
	Concert();
	~Concert();
	Concert(const Concert&);
	Concert& operator= (const Concert&);


private:
	Band* grupi;
	int count;
	int capacity;

};

Concert::~Concert()
{
	delete[] this->grupi;
}

// oh... i expected more :(
// - 1.4
// + 0.2 as promised
