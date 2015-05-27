#ifndef RockStar_h
#define RockStar_h

#endif // !RockStar_h

class RockStar
{
public:
	RockStar();
	RockStar(char*, int awesomeness, int numberOfFans);
	RockStar(const RockStar&);
	~RockStar();
	RockStar& operator=(const RockStar&);

	void print();

	void setName(const char*);
	void setAwesomeness(int);
	void setNumberOfFans(int);

	char* getName()const;
	int getAwesomeness()const;
	int getNumberOfFans()const;

	
	bool operator==(const RockStar&) const;
	bool operator>(const RockStar&) const;
	bool operator<(const RockStar&) const;


private:

	char* name;
	int awesomeness;
	int numberOfFans;

	
};

