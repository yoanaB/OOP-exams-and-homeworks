#ifndef Concert_H
#define Concert_H
#include "Band.h"
#include "Rockstar.h"

class Concert
{
public:
	Concert();
	Concert(Band*, size_t);
	Concert(const Concert&);
	Concert& operator=(const Concert&);
	~Concert();

	size_t AverageAwesomeness(Rockstar**);
	Band headliners(Band*);

	
private:
	Band* bands;
	size_t size;

};


#endif