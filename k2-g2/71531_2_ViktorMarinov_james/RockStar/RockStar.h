#ifndef RockStar_h
#define RockStar_h
class RockStar
{
	friend class Band;
	friend class Concert;
	char* name;
	int awesomeness,
		numberOfFens;
	void setRockStar(char*, int, int);
public:
	RockStar(char* = "", int = 0, int = 0);
	~RockStar();
	RockStar(const RockStar&);
	RockStar& operator=(const RockStar&);

	void setName(char*);
	void setAwesomeness(int);
	void setNumberOfFans(int);

	char* getName() const{
		return name;
	}
	int getAwesomeness() const{
		return awesomeness;
	}
	int getNumberOfFans() const{
		return numberOfFens;
	}

	void print() const;

	bool operator>(const RockStar&);
	bool operator<(const RockStar&);
	bool operator==(const RockStar&);
};

#endif