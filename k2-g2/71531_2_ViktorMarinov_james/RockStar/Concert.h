#ifndef Concert_h
#define Concert_h
#include "Band.h"
class Concert
{
	Band* bands;
	int size;
	void setConcert(Band* bands, int size);
public:
	Concert(Band* bands, int size);
	~Concert();
	Concert(const Concert&);
	Concert& operator=(const Concert&);

	int averageAwesomness() const;
	Band& headliner() const;
};

#endif