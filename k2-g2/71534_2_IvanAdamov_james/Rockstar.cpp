#include <iostream>

using namespace std;

class Rockstar 
{
private:
	char *name;
	int awesomeness;
	int fans;
public:
	Rockstar(int length);
	~Rockstar();
	Rockstar(const Rockstar &r);
	Rockstar operator=(const Rockstar &r);
	Rockstar(char *n, int a, int f);

	void setName(char n);
	char getName();
	void setAwesomeness(int a);
	int getAwesomeness();
	void setFans(int f);
	int getFans();

	void print();

	bool operator<(const Rockstar &r);
	bool operator>(const Rockstar &r);
	bool operator==(const Rockstar &r);
};
//ouch...
// no cin in the constructors
// - 0.2
Rockstar::Rockstar(int length)
{	
	name = new char[length];
	cout << "name = ";
	cin >> name;
	cout << "awesomeness = ";
	cin >> awesomeness;
	cout << "fans = ";
	cin >> fans;
}

Rockstar::~Rockstar()
{
	delete name;
}

Rockstar::Rockstar(const Rockstar &r)
{
	name = r.name;
	awesomeness = r.awesomeness;
	fans = r.fans;
}

Rockstar::Rockstar(char *n, int a, int f)
{
	name = n;
	awesomeness = a;
	fans = f;
}

Rockstar Rockstar::operator=(const Rockstar &r)
{
	return Rockstar(r.name, r.awesomeness, r.fans);
}

void Rockstar::setName(char n) 
{
	*name = n;
}

char Rockstar::getName()
{
	return *name;
}

void Rockstar::setAwesomeness(int a) 
{
	awesomeness = a;
}

int Rockstar::getAwesomeness()
{
	return awesomeness;
}

void Rockstar::setFans(int f) 
{
	fans = f;
}

int Rockstar::getFans()
{
	return fans;
}

void Rockstar::print()
{
	cout << "name = " << name << endl;
	cout << "awesomeness = " << awesomeness << endl;
	cout << "fans = " << fans << endl; 
}

bool Rockstar::operator>(const Rockstar &r)
{
	return awesomeness > r.awesomeness;
}

bool Rockstar::operator<(const Rockstar &r)
{
	return awesomeness < r.awesomeness;
}

bool Rockstar::operator==(const Rockstar &r)
{
	return awesomeness == r.awesomeness;
}