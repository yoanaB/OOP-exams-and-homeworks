/*3) Да се дефинира клас  Concert, който съхранява масив от Банди(Band), като има следната функционалност:
averageAwesomeness - намира средния коефициент на якост на концерта( средната якост на всички банди)
headliners - намира главната група в концерта( тази с най голяма якост)
Да се реализира канонично представяне на класа.*/

#ifndef CONCERT_H
#define CONCERT_H
#include "Band.h"
class Concert
{
public:
	Concert();
	~Concert();
	Concert(const Concert&);
	Concert(Band*, int, int);
	Concert& operator=(const Concert&);

	double averageAwesomeness();
	Band& headliners();
private:
	Band* bands;
	int size;
	int capacity;
};

#endif