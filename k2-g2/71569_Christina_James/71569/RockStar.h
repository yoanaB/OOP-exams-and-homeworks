#ifndef ROCKSTAR_H
#define ROCKSTAR_H


/*

Four principles of OOP:
1. Abstraction
2. Encapsulation
3. Inheritance
4. Polymorphism

*/


class RockStar{

public:
	RockStar();
	RockStar(const char*, int, int);
	RockStar(const RockStar&);
	RockStar& operator=(const RockStar&);
	~RockStar();

	void setName(const char*);
	void setAwesomeness(int);
	void setNumberOfFans(int);

	int getAwesomeness() const;
	int getNumberOfFans() const;
	const char* getName() const;

	void print() const;

	bool operator==(const RockStar&) const;
	bool operator<(const RockStar&) const;
	bool operator>(const RockStar&) const;


private:
	char* name;
	int awesomeness;
	int numberOfFans;


};


#endif