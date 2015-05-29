#ifndef band_h
#define band_h
#include "rock.h"

class Band
{
private:
	RockStar* all;


public:
	void addStar();
	char getStar();
	void removeStar();
	void print();


};

#endif band_h