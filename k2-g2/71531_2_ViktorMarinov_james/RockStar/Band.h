#ifndef Band_h
#define Band_h
#include "RockStar.h"

class Band
{
	friend class Concert;
	char* name;
	RockStar* members;
	int size,
		capacity;
	void setBand(char*, RockStar*, int, int);
public:
	Band(char* = "", int = 1);
	~Band();
	Band(const Band&);
	Band& operator=(const Band&);

	void addStar(const RockStar&);
	void removeStar(char*);
	RockStar& getStar(char*);

	void print() const;

	Band& operator+=(const Band&);
	RockStar& pickAFrontman() const;
};

#endif