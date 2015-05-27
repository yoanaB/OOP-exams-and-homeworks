#ifndef BAND_H
#define BAND_H
#include "RockStar.h"

class Band{

public:
	Band();
	Band(int, int);
	Band(const Band&);
	Band& operator=(const Band&);
	~Band();

	int getSize() const;
	void copyStars(const Band&);
	int findStar(const char*) const;

	RockStar& getStar(const char* name) const;
	void addRockStar(RockStar&);
	void removeRockStar(const char*);
	RockStar& pickFrontMan();

	void sort();
	Band& operator+=(const Band&);
	void print() const;

	double getAverageAwesomeness() const;

private:
	RockStar* band;
	int size;
	int capacity;



};


#endif