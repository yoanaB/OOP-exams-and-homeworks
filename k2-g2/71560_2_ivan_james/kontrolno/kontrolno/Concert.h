#ifndef concert_h
#define concert_h
#include"Band.h"

class Concert
{
public:
	Concert();
	~Concert();
	Concert(int, int);
	Concert(const Concert&);
	Concert& operator=(const Concert&);

	double averageAwesomeness(const Concert&);
	Band headliners(const Concert&);

private:
	Band* concert;
	int size;
	int capacity;
};


#endif 