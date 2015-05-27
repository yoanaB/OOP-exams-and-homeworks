#ifndef Rockstar_H
#define Rockstar_H

class Rockstar
{
public:
	Rockstar();
	Rockstar(char*, int, size_t);
	Rockstar(const Rockstar&);
	Rockstar& operator=(const Rockstar&);
	~Rockstar();

	void setName(char*);
	void setAwesomeness(int);
	void setNumberOfFans(size_t);

	char* getName() const;
	int getAwesomeness() const;
	size_t getNumberOfFans() const;

	void print();

	bool operator==(const Rockstar&); //po awesomeness
	bool operator>(const Rockstar&);
	bool operator<(const Rockstar&);


private:
	char* name;
	int awesomeness;
	size_t numberOfFans;


};



#endif