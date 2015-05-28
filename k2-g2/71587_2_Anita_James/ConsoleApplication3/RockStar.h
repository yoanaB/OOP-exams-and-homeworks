#ifndef ROCK_H
#define ROCK_H

class Rock
{
public:
	Rock();
	Rock (const char*, int, int);
	Rock (const Rock&);
	Rock& operator= (const Rock&);
	~Rock();

	const char* getName() const;
	int getAwesomeness() const;
	int getNumber() const;

	void setName(const char*);
	void setAwesomeness(int);
	void setNumber(int);
	
	void print() const;

	bool operator > (const Rock&);
	bool operator < (const Rock&);
	bool operator == (const Rock&);
private:
	char* name;
	int awesomeness;
	int numberOfFens;

	void copy(const Rock&);
	void del();
};
#endif