#ifndef BAND_H
#define BAND_H
#include "RockStar.h"

class Band
{
private:
	Rock* stars;
	size_t size;
	size_t cap;
	
	void expand();
	
public:
	Band();
	Band(const Band&);
	Band& operator= (const Band&);
	~Band();

	Rock& getStar(const Rock*);
	void addStar(const Rock&);
	void removeStar(const Rock&);

	void print() const;

	Rock& sort();
};
#endif