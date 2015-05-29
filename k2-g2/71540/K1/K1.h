#ifndef ROCSTAR_H
#define  ROCSTAR_H

class RockStar
{
public:
	RockStar();
	~RockStar();
	RockStar(const RockStar&);
	RockStar& operator= (const RockStar&);
	void setName(char*);
	char* getName() const;
	void setAw(int);
	int getAw() const;
	void setN(int);
	int getN() const;
	void print();
	bool operator>(const RockStar&) const;
	bool operator<(const RockStar&) const;
	bool operator==(const RockStar&) const;
private:
	char* name;
	int awesomeness;
	int numberofFens;
};

class Band
{
public:
	Band();
	~Band();
	Band(const Band&);
	Band& operator= (const Band&);
	void addStar(const RockStar&);
	void removeStar(char*);
	RockStar getStar(char*);
	void print();
	int getCount() const;
	Band operator+=(const Band&);//obedinqva 2 bandi i nai dobrite 5 gi vrushta v res
	RockStar pickFrontman();
	double average();
	void sort();
private:
	RockStar* r;
	int count,
		size;
};

class Concert
{
public:
	Concert();
	~Concert();
	Concert(const Concert&);
	Concert& operator= (const Concert&);
	double averageAwesomeness();
	Band headliners();
private:
	Band* b;
	int size,
		count;
};

#endif