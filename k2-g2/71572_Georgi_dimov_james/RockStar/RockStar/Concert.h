#ifndef Concert_h
#define Concert_h
#include "band.h"
class Concert
{
private:
	Band* here;
	int capacity;
	int size; 
public:
	Concert(int hereSize=0);
	Concert& operator=(Concert&);
	Concert(Concert&);
	~Concert();
	void averageAwesomeness();
	void headliners();


};
#endif Concert_h