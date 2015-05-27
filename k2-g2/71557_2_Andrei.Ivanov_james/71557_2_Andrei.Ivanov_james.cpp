#include <iostream>
using namespace std;
class RockStar
{
	char *name;
	double awesomeness;
	int numbersOfFans;
public:
	friend class Band;
	RockStar();
	RockStar(char *, double, int);
	RockStar(const RockStar&);
	RockStar& operator=(const RockStar&);
	~RockStar();
	void setName(const char *);
	void setAwesomeness(double);
	void setNumberofFans(int);
	char *getName() const;
	double getAwesomeness() const;
	int getFans() const;
	void print() const;
	bool operator==(const RockStar&);
	bool operator<(const RockStar&);
	bool operator>(const RockStar&);

};
void RockStar::setName(const char *name)
{
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}
RockStar::RockStar() : name(nullptr)
{
	this->setName("Ivan");
	this->awesomeness = 9;
	this->numbersOfFans = 100;
}
RockStar::RockStar(char *name,double awesome,int numberofans) : name(nullptr)
{
	this->setName(name);
	this->awesomeness = awesome;
	this->numbersOfFans = numberofans;
}
RockStar::RockStar(const RockStar& other) : name(nullptr)
{
	this->setName(other.name);
	this->awesomeness = other.awesomeness;
	this->numbersOfFans = other.numbersOfFans;
}
RockStar& RockStar::operator=(const RockStar& other)
{
	if (this == &other)
	{
		return *this;
	}
	else
	{
		this->setName(other.name);
		this->awesomeness = other.awesomeness;
		this->numbersOfFans = other.numbersOfFans;
		return *this;
	}
}
void RockStar::setAwesomeness(double aweSome)
{
	this->awesomeness = aweSome;
}
void RockStar::setNumberofFans(int fans)
{
	this->numbersOfFans = fans;
}
char * RockStar::getName() const
{
	return (char *)this->name;
}
double RockStar::getAwesomeness() const
{
	return this->awesomeness;
}
int RockStar::getFans() const
{
	return this->numbersOfFans;
}
void RockStar::print() const
{
	cout << "Name:" << this->name << "  " << "Awesomeness:" << this->awesomeness << "   " << "NumberOfFans:" << this->numbersOfFans << endl;
}
bool RockStar::operator==(const RockStar& other)
{
	return this->awesomeness == other.awesomeness;
}
bool RockStar::operator<(const RockStar& other)
{
	return this->awesomeness<other.awesomeness;
}
bool RockStar::operator>(const RockStar& other)
{
	return this->awesomeness > other.awesomeness;
}
RockStar::~RockStar()
{
	delete[] this->name;
}

class Band
{
	char *name;
	RockStar *stars;
	int size, capacity;
public:
	Band();
	Band(const Band &);
	Band& operator=(const Band&);
	~Band();
	void setName(const char *);
	void print() const;
	Band& addStar(const RockStar&);
	Band& removeStar(const char *);
	RockStar& getStar(const char *);
	Band operator+=(const Band&);
	RockStar pickAFrontman() const;
	void sort();
	double getAvAwesomenes() const;

};
void Band::setName(const char *name)
{
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}
Band::Band() :name(nullptr)
{
	this->setName("Band1");
	this->size = 3;
	this->capacity = 5;
	this->stars = new RockStar[this->capacity];

	this->stars[0].setName("Petur"); 
	this->stars[0].setAwesomeness(30);
	this->stars[0].setNumberofFans(100);

	this->stars[1].setName("Georgi");
	this->stars[1].setAwesomeness(78);
	this->stars[1].setNumberofFans(200);

	this->stars[2].setName("Nikolai");
	this->stars[2].setAwesomeness(80);
	this->stars[2].setNumberofFans(400);
	

}
Band::Band(const Band& otherBand) : name(nullptr)
{
	this->setName(otherBand.name);
	this->size = otherBand.size;
	this->capacity = otherBand.capacity;
	this->stars = new RockStar[this->capacity];
	for (int i = 0; i < this->size; i++)
	{
		this->stars[i] = otherBand.stars[i];
	}
}
Band& Band::operator=(const Band& other)
{
	if (this == &other)
	{
		return *this;
	}
	else
	{
		this->setName(other.name);
		this->size = other.size;
		this->capacity = other.capacity;
		delete[] this->stars;
		this->stars = new RockStar[this->capacity];
		for (int i = 0; i < this->size; i++)
		{
			this->stars[i] = other.stars[i];
		}
		return *this;
	}
}
Band& Band::addStar(const RockStar& other)
{
	if (this->size == this->capacity)
	{
		this->capacity *= 2;
		RockStar *old = this->stars;
		this->stars = new RockStar[this->capacity];
		for (int i = 0; i < this->size; i++)
		{
			this->stars[i] = old[i];
		}
		delete[] old;
	}
	this->stars[this->size] = other;
	this->size++;
	return *this;
}
Band& Band::removeStar(const char *name)
{
	for (int i = 0; i < this->size; i++)
	{
		if (!strcmp(this->stars[i].getName(), name))
		{
			this->stars[i] = this->stars[this->size - 1];
			this->size--;
			i--;
		}
	}
	return *this;
}
RockStar& Band::getStar(const char *name)
{
	for (int i = 0; i < this->size; i++)
	{
		if (!strcmp(this->stars[i].getName(), name))
		{
			return this->stars[i];
		}
	}	
}
void Band::sort()
{
	bool flag;
	do
	{
		flag = false;
		for (int i = 0; i< this->size - 1; i++)
		{
			if (this->stars[i].awesomeness < this->stars[i + 1].awesomeness)
			{
				RockStar temp = this->stars[i];
				this->stars[i] = this->stars[i + 1];
				this->stars[i + 1] = temp;
				flag = true;
			}
		}
	} while (flag);
}
Band Band::operator+=(const Band& other)
{
	Band result1;	
	delete[] result1.stars;
	result1.stars = new RockStar[this->capacity+other.capacity];

	for (int i = 0; i< this->size; i++)
	{
		result1.stars[i] = this->stars[i];
	}
	int j = this->size;
	for (int i = 0; i<other.size; i++)
	{
		result1.stars[j] = other.stars[i];
		j++;
	}
	result1.size = this->size + other.size;
	result1.sort();

	Band result;
	result.setName("BandRes");
	delete[] result.stars;
	result.stars = new RockStar[5];
	for (int i = 0; i < 5; i++)
	{
		result.stars[i] = result1.stars[i];
	}
	result.size = 5;
	return result;	

}
RockStar Band::pickAFrontman() const
{
	Band res = *this;
	res.sort();
	return this->stars[0];
}
double Band::getAvAwesomenes() const
{
	double res = 0;
	for (int i = 0; i<this->size; i++)
	{
		res = res+ this->stars[i].awesomeness;
	}
	res = res / this->size;
	return res;

}
Band::~Band()
{
	delete[] this->name;
	delete[] this->stars;
}
void Band::print() const
{
	cout << "NameBand:" << this->name << endl;
	if (this->size > 0)
	{
		for (int i = 0; i < this->size; i++)
		{
			this->stars[i].print();
		}
	}
	else
	{
		return;
	}
}

class Concert
{
	Band *bands;
	int size, capacity;
public:
	Concert();
	Concert(const Concert&);
	Concert& operator=(const Concert&);
	~Concert();
	void print() const;
	double getAllBandsAverageAwesomeness() const;
	void sortConcert();
	Band headliners() const;


};
Concert::Concert()
{
	this->size = 2;
	this->capacity = 4;
	this->bands= new Band[this->capacity];
}
Concert::Concert(const Concert& other)
{
	this->size = other.size;
	this->capacity = other.capacity;
	this->bands = new Band[this->capacity];
	for (int i = 0; i < this->size; i++)
	{
		this->bands[i] = other.bands[i];
	}
}
Concert& Concert::operator=(const Concert& other)
{
	if (this == &other)
	{
		return *this;
	}
	else
	{
		this->size = other.size;
		this->capacity = other.capacity;
		delete[] this->bands;
		this->bands = new Band[this->capacity];
		for (int i = 0; i < this->size; i++)
		{
			this->bands[i] = other.bands[i];
		}
		return *this;

	}
}
double Concert::getAllBandsAverageAwesomeness() const
{
	double res = 0;
	for (int i = 0; i < this->size; i++)
	{
		res = res + this->bands[i].getAvAwesomenes();
	}
	res = res / this->size;
	return res;
}
void Concert::sortConcert()
{
	bool flag;
	do
	{
		flag = false;
		for (int i = 0; i< this->size - 1; i++)
		{
			if (this->bands[i].getAvAwesomenes() < this->bands[i + 1].getAvAwesomenes())
			{
				Band temp = this->bands[i];
				this->bands[i] = this->bands[i + 1];
				this->bands[i + 1] = temp;
				flag = true;
			}
		}
	} while (flag);
}
Band Concert::headliners() const
{
	Concert res = *this;
	res.sortConcert();
	return res.bands[0];
}

void Concert::print() const
{
	if (this->size > 0)
	{
		for (int i = 0; i < this->size; i++)
		{
			this->bands[i].print();
		}
	}
	else
	{
		return;
	}
}
Concert::~Concert()
{ 
	delete[] this->bands;
}

int main()
{
	
	Concert a;
	(a.headliners()).print();
	

	system("pause");
	return 0;
}
