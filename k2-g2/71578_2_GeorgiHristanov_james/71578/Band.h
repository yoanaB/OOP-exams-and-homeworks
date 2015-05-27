#ifndef BAND_H
#define BAND_H

class Band
{
private:
	RockStar* stars;
	char* name;
	int currSize;
	int size;
public:
	
	Band();
	Band(char*, int);
	~Band();
	
	void addStar(char*, int, int);
	void removeStar(char*);
	void getStar(char*);
	
	void print() const;

};

#endif