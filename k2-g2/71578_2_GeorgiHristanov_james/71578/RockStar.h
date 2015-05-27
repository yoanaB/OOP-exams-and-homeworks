#ifndef ROCKSTAR_H 
#define ROCKSTAR_H

class RockStar
{
private:
	char* name;
	int awesomeness;	// girls f*cked
	int numberOfFans;
public:
	RockStar();
	RockStar(char*, int, int);
	~RockStar();
	const char* getName();
	int getAwesomeness();
	int getNumberOfFans();
	
	void setName(const char*);
	void setAwesomeness(int);
	void setNumberOfFans(int);

	RockStar& operator>(RockStar);
	RockStar& operator<(RockStar);
	RockStar& operator==(RockStar);
	void print() const;

	
};

#endif
