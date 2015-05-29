#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;


class RockStar
{
	char*name;
	int awesomeness;
	int numberOfFans;
public:
	RockStar();
	~RockStar();
	RockStar(const RockStar&);
	void setRockStar(char*, int, int);
	RockStar& operator=(const RockStar&);
	bool operator<(const RockStar&);
	bool operator>(const RockStar&);
	bool operator==(const RockStar&);
	void print() const;
	int getAwesomeness();
	void setAwesomeness(int);
	char* getName() const;
};

RockStar::~RockStar()
{
	delete[] this->name;
}

void RockStar::setRockStar(char*name, int awesomeness,int number)
{
	delete[] this->name;

	int length = strlen(name) + 1;
	this->name = new char[length];
	strcpy_s(this->name, length, name);

	this->awesomeness = awesomeness;
	this->numberOfFans = number;
}

RockStar::RockStar():
name(NULL)
{
	// nicee :)
	this->setRockStar("John Lennon", 10, 200000);
}

RockStar::RockStar(const RockStar& other):
name(NULL)
{
	this->setRockStar(other.name, other.awesomeness, other.numberOfFans);
}

RockStar& RockStar::operator=(const RockStar& other)
{
	if (this == &other)
	{
		return *this;
	}

	else
	{
		this->setRockStar(other.name, other.awesomeness, other.numberOfFans);
		return *this;

	}
}


bool RockStar::operator<(const RockStar& other)
{
	return this->awesomeness < other.awesomeness;
}

bool RockStar::operator>(const RockStar& other)
{
	return this->awesomeness > other.awesomeness;
}

bool RockStar::operator==(const RockStar& other)
{
	return this->awesomeness == other.awesomeness;
}

void RockStar::print() const
{
	cout << this->name << " " << this->awesomeness << " " << this->numberOfFans << endl;
}

int RockStar::getAwesomeness()
{
	return this->awesomeness;
}

void RockStar::setAwesomeness(int newAwesomeness)
{
	this->awesomeness = newAwesomeness;
}

char* RockStar::getName() const
{
	return this->name;
}

class Band
{
	RockStar* stars;
	int size;
	int capacity;
public:
	Band();
	~Band();
	Band(const Band&);
	int getAverageAwesomeness();
	Band& addStar(const RockStar&);
	Band& removeStar(char*);
	Band& operator=(const Band&);
	RockStar* getStar(char*);
	void print() const;
	Band& operator+=(const Band&);
	RockStar& pickAFrontMan();
	
};

Band::Band()
{
	this->size = 5;
	this->capacity = 10;
	this->stars = new RockStar[capacity];
}

Band& Band::operator=(const Band& other)
{
	if (this == &other)
	{
		return *this;
	}

	else
	{
		this->size = other.size;
		this->capacity = other.capacity;

		delete[] this->stars;
		this->stars = new RockStar[capacity];

		for (int i = 0; i < this->size; i++)
		{
			this->stars[i] = other.stars[i];
		}

		return *this;
	}
}

Band::Band(const Band& other)
{
	this->size = other.size;
	this->capacity = other.capacity;

	delete[] this->stars;
	this->stars = new RockStar[capacity];

	for (int i = 0; i < this->size; i++)
	{
		this->stars[i] = other.stars[i];
	}
}

Band::~Band()
{
	delete[]this->stars;
}

Band& Band::addStar(const RockStar& other)
{
	if (this->size == this->capacity)
	{
		this->capacity *= 2;
		RockStar* old = this->stars;
		this->stars = new RockStar[capacity];

		for (int i = 0; i < this->size; i++)
		{
			this->stars[i] = old[i];
		}

		delete[] old;
	}

	this->stars[this->size] = other;
	size++;
	return *this;

}

Band& Band::removeStar(char* name)
{
	// what about decreasing size
	// - 0.2
	for (int i = 0; i < this->size; i++)
	{
		if (strcmp(this->stars[i].getName(), name) == 0)
		{
			this->stars[i] = this->stars[this->size - 1];
			size--;
			i--;
		}
	}

	return *this;
}

int Band::getAverageAwesomeness()
{
	int sum = 0;

	for (int i = 0; i < this->size; i++)
	{
		sum += this->stars[i].getAwesomeness();
	}

	sum /= this->size;

	return sum;
}

RockStar* Band::getStar(char*name)
{
	for (int i = 0; i < this->size; i++)
	{
		if (strcmp(this->stars[i].getName(), name) == 0)
		{
			return &this->stars[i];
		}

	}

	return NULL;	
}

void Band::print() const
{

	for (int i = 0; i < this->size; i++)
	{
		this->stars[i].print();
	}

}

RockStar& Band::pickAFrontMan()
{
	RockStar max = this->stars[0];

	for (int i = 0; i < this->size; i++)
	{
		if (max.getAwesomeness() < this->stars[i].getAwesomeness())
		{
			max = this->stars[i];
		}

	}

	return max;
}

class Concert
{
	Band* bands;
	int size;
	int capacity;
public:
	Concert();
	Concert(const Concert&);
	~Concert();
	Concert& operator=(const Concert&);
	int averageAwesomeness();
	Band& headliners();
	void print() const;
};

Concert::Concert()
{
	this->size = 2;
	this->capacity = 5;

	this->bands = new Band[capacity];
}

Concert::~Concert()
{
	delete[] this->bands;
}

Concert::Concert(const Concert& other)
{
	this->size = other.size;
	this->capacity = other.capacity;

	delete[]this->bands;
	this->bands = new Band[capacity];

	for (int i = 0; i < this->size; i++)
	{
		this->bands[i] = other.bands[i];
	}

}

Concert& Concert::operator=(const Concert &other)
{
	if (this == &other)
	{
		return *this;
	}

	else
	{
		this->size = other.size;
		this->capacity = other.capacity;

		delete[]this->bands;
		this->bands = new Band[capacity];

		for (int i = 0; i < this->size; i++)
		{
			this->bands[i] = other.bands[i];
		}

		return *this;
	}
}

int Concert::averageAwesomeness()
{
	int sum = 0;

	for (int i = 0; i < this->size; i++)
	{
		sum += this->bands[i].getAverageAwesomeness();
	}

	sum /= this->size;

	return sum;
}

Band& Concert::headliners()
{
	Band max = this->bands[0];

	for (int i = 0; i < this->size; i++)
	{
		if (max.getAverageAwesomeness() < this->bands[i].getAverageAwesomeness())
		{
			max = this->bands[i];
		}
	}

	return max;
}

void Concert::print() const
{
	for (int i = 0; i < this->size; i++)
	{
		this->bands[i].print();
	}
}

int main()
{
	

	system("pause");
	return 0;
}

// 5.80