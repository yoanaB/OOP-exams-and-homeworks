#ifndef band_h
#define band_h
#include "RockStar.h"

class Band
{
public:
	Band();
	Band(char*, int, int);
	Band(const Band&);
	Band& operator=(const Band&);
	~Band();

	Band& addStar(const RockStar&);
	Band& removeStat(const char*);
	RockStar getStar(const char*);

	void setBandName(const char*);
	void print()const;

	Band& operator+=(const Band&);

	RockStar& pickAFrontman(const Band&);

	double avarageAwesomeness(const Band&);

private:
	RockStar* rockstars;
	char* name;
	int size;
	int capacity;

};

#endif