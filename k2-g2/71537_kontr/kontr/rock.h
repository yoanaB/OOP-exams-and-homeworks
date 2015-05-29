#ifndef ROCK_H
#define ROCH_H

//Inheritance,Polymorphism,Encapsulation,Abstraction 

class RockStar
{ 
public:
	RockStar()
	{
		name = "Bon Jovi";
		awesomness = 0;
		numberOfFens = 1;
	}
	RockStar(char*, int, int);
	RockStar(const RockStar&);
	~RockStar();
	RockStar& operator= (const RockStar&);
	void setName(char*);
	void setAwesomness(int);
	void setNumberOfFens(int);
	char* getName() const;
	int getAwesomness() const;
	int getNumberOfFens() const;
	void print() const;
	bool  operator> (const RockStar&);
	bool  operator== (const RockStar&);
	bool  operator< (const RockStar&);
private:
	char* name;
	int awesomness;
	int numberOfFens;

	void cpy (const RockStar& a)
	{
		this->name = new char[strlen(a.name) + 1];
		assert(this->name);
		strcpy_s(this->name, strlen(a.name) + 1, a.name);

		this-> awesomness = a.awesomness;
		this->numberOfFens = a.numberOfFens;
	}
	void del()
	{
		delete[] name;
	}
};

class Band
{
public:
	Band();
	Band(char*,int);
	Band(const Band&);
	~Band();
	Band& operator= (const Band&);
	void print() const;
	void addStar(const RockStar&);
	void removeStar(char*);
	void getStar(char*) ;
	void operator+= (const Band&);
	double getAv(const Band&);
	int getAwesomness(const Band&);
	void pickFrontMan(const Band&);
private:
	RockStar* stars;
	char* name;
	int size;
	int capacity;
	void cpy(const Band& a)
	{
		this->name = new char[strlen(a.name) + 1];
		assert(this->name);
		strcpy_s(this->name, strlen(a.name) + 1, a.name);

		this->stars = new RockStar[capacity];
		assert(stars);
		
		
		this->size = a.size;
		this->capacity= a.capacity;
	}
	void del()
	{
		delete[] name;
		delete[] stars;
	}
	void extend()
	{
		capacity *= 2;
		RockStar* oldStars = stars;
		for (int i = 0; i < size; i++)
		{
			stars[i] = oldStars[i];
		}
		delete[] oldStars;
	}
	void sort(const Band&)
	{
		for (int i = 0; i < size - 1; i++)
		{
			int greater = i;
			for (int j = 0; j < size; j++)
			{
				if (stars[greater].getAwesomness() < stars[j].getAwesomness())
					greater = j;
			}
			if (!(greater == i))
				std::swap(stars[greater], stars[i]);
		}
	}
};

class Concert
{
public:
	Concert();
	~Concert();
	Concert(const Concert&);
	Concert& operator= (const Concert&);
	double averageAwesomness(const Concert&);
	void headliners(const Concert&);
private:
	Band* bands;
	int sizeBands;
	int capacityBands;

};

#endif