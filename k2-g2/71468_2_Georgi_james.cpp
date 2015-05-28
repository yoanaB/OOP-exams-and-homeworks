//Абстракция,капсулация,наследяване,полиморфизъм-зад1

#include <iostream>

using namespace std;

class RockStar
{
private:
	char* Name[30];
	size_t Awesomeness;
	size_t numberOfFans;
public:
	RockStar();
	~RockStar();
	void setName(char* newName);
	void setAwesomeness(size_t awesome);
	void setnumberOfFans(size_t numb);
	char* getName() const;
	int getAwesomeness() const;
	int getnumberOfFans() const;
	void print() const;
	bool operator ==(const RockStar &rock) const;
	bool operator <(const RockStar &rock) const;
	bool operator >(const RockStar &rock) const;
};

RockStar::RockStar()
{	
	// oh come oon.... think of better name for rock star next time
	// how about dynamic memory:
	// - 0.3
	*Name = "Bai Ivan";
	Awesomeness = 1;
	numberOfFans = 1;
}

RockStar::~RockStar()
{
	//...
}
// no copy constructor and operator = 
// - 0.3
void RockStar::setName(char* newName)
{
	*Name = newName;
}

void RockStar::setAwesomeness(size_t awesome)
{
	Awesomeness = awesome;
}

void RockStar::setnumberOfFans(size_t numb)
{
	numberOfFans = numb;
}

char* RockStar::getName() const
{
	return *Name;
}

int RockStar::getAwesomeness() const
{
	return Awesomeness;
}

int RockStar::getnumberOfFans() const
{
	return numberOfFans;
}

void RockStar::print() const
{
	cout << "Name: " << *Name << endl;
	cout << "Awesomeness: " << Awesomeness << endl;
	cout << "Number of fans: " << numberOfFans << endl;

}



int main()
{
	RockStar star;
	star.print();

}

// 2.5 