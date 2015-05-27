#ifndef Band_H
#define Band_H
#include "Rockstar.h"

class Band
{
public:
	Band();
	Band(Rockstar*, size_t, size_t);
	Band(const Band&);
	Band& operator=(const Band&);
	~Band();

	Rockstar getStar(char* nameSearch) const;
	Band& addStar(Rockstar& newOne);
	Band& removeStar(Rockstar& deletedOne);
	void printBand();
	Rockstar operator+=(Rockstar*);
	Rockstar pickAFrontman(const Band&);

private:
	Rockstar* stars;
	size_t size;
	size_t capacity;
};

#endif 