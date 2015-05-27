/*
1.Abstaction
2.Inheritance
3.Encapsulation
4.Polymorphysum
*/

#ifndef rockstar_h
#define rockstar_h

class RockStar
{

public:
	RockStar();
	RockStar(char*, int, int);
	~RockStar();
	RockStar(const RockStar&);

	RockStar& operator=(const RockStar&);
	
	bool operator<(const RockStar&) const;
	bool operator>(const RockStar&) const;
	bool operator==(const RockStar&) const;

	void setName(const char*);

	char* getName() const;
	int getAwesomeness() const;
	int getNumberOfFens() const;

	void print() const;


private:
	char* name;
	int awesomeness;
	int numberOfFens;
};


#endif