#ifndef CONCERT_H
#define CONCERT_H
#include "Band.h"


class Concert{

public:
	Concert();
	Concert(int, int);
	Concert(const Concert&);
	Concert& operator=(const Concert&);
	~Concert();

	void clearBands();
	void copyStuff(const Concert&);
	double getAveAwesomeness();
	Band getHeadliners();

private:
	Band** concert;
	int numberBands;
	int capacity;
	

};


#endif