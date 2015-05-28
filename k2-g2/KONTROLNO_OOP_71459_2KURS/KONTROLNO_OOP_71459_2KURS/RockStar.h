#ifndef ROCKSTAR_H
#define ROCKSTAR_H

class RockStar
{
	char* name;
	int awesomeness;
	unsigned int numberOfFens;

public:
	RockStar();
	RockStar(RockStar& r);
	~RockStar();

public:
	char* getName();
	int getAwesomeness();
	unsigned int getNumberOfFens();

	void setRockStar(const char* name, const int awesomeness, const unsigned int numberOfFens);
	
	void print();

public:
	RockStar& operator=(RockStar& r);
	bool operator>(RockStar& r);
	bool operator<(RockStar& r);
	bool operator==(RockStar& r);
};

#endif