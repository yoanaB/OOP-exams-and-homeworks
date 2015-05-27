#ifndef band_h
#define band_h
#include "rock.h"
class Band
{
private:
	RockStar* all; 
	int capasity;
	int size; 
public:
	Band(int hereSize = 0 );
	Band& operator=(Band&);
	Band& operator+=(Band&);
	Band(Band&);
	~Band();
	void addStar(char* hereName,int hereAw,int fans);
	void removeStar(char* hereName);
	void getStar(char* hereName);
	void printBand();

};
#endif band_h