#ifndef CONCERT_H
#define CONCERT_H
#include "Band.h"

class Concert
{
	static unsigned int cnt;
	Band* bands;

public:
	Concert();
	Concert(Concert& r);
	~Concert();

public:
	int averageAwesomeness();

};

#endif