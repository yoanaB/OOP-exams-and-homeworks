#ifndef HEADER_H
#define HEADER_H
class RockStar{
private:
	char* name;
	int awesomeness;
	int numberOfFans;
public:
	RockStar();
	RockStar(char*, int, int);
	~RockStar();
	RockStar(const RockStar&);
	RockStar& operator=(const RockStar&);
	void setName(char*);
	void setAwesomeness(int);
	void setNumberOfFans(int);
	char* getName()const;
	int getAwesomeness()const;
	int getNumberOfFans()const;
	void print()const;
	bool operator>(const RockStar&);
	bool operator<(const RockStar&);
	bool operator==(const RockStar&);
};

class Band{
private:
	RockStar* stars;
	int size;
	int capacity;
public:
	Band();
	~Band();
	Band(const Band&);
	Band& operator=(const Band&);
	void print()const;
	void addStar(const RockStar&);
	int numberOfStars()const;
	void removeStar(char*);
	RockStar& getStar(char*);
	int getAwesomenessKoef()const;
	void sort();
	RockStar& pickAFrontman()const;
};

class Concert{
private:
	Band* bands;
	int size;
	int capacity;
public:
	Concert();
	~Concert();
	Concert(const Concert&);
	Concert& operator=(const Concert&);
	double averageAwesomeness();
	int headliners();
};
#endif // !ROCKSTAR_H
