#ifndef CONCERT_H
#define CONCERT_H
#include "Band.h"

class Concert
{
public:
	Concert();
	Concert(const Concert&);
	Concert& operator= (const Concert&);
	~Concert();
private:
	Band* bands;
	size_t size;
};
#endif