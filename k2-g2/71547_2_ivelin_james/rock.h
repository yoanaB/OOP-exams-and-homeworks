#ifndef rock_h
#include <iostream>
#define rock_h
class RockStar
{
private:
	char* name;
	int awesomeness;
	int numberOfFans;
public:
	RockStar(char* = "", int = 0, int = 0);
	RockStar(RockStar&);
	RockStar& operator=(RockStar&);
	bool operator>(RockStar&);
	bool operator<(RockStar&);
	bool operator==(RockStar&);

	~RockStar();
	void setName(char* hereName);
	void setAwesomness(int aw);
	void setFans(int fans);
	char* getName();
	int getAwesomness();
	int getFans();
	void printRS();
};

#endif rock_h