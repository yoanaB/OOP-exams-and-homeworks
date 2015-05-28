#ifndef BAND_H
#define BAND_H
#include "RockStar.h"

class Band
{
	static unsigned int cnt;
	RockStar* stars;

public:
	Band();
	Band(Band& r);
	~Band();

public:
	void addStar(RockStar& star);
	void removeStar(const char* name);

	RockStar& getStar(const char* name);

	void print();
	int averageAwesomeness();

public:
	Band& operator+=(Band& r);
	bool operator==(Band& r);
	Band& operator=(Band& r);
};

#endif