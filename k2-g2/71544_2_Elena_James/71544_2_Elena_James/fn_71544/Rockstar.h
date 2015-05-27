#ifndef ROCK_H
#define ROCK_H

class Rockstar {
public:
	void setName(char*);
	void setAwesomeness(int);
	void setNumber(int);
	char* getName()const;
	int getAwesomeness()const;
	int getNumber()const;

	Rockstar();
	Rockstar(char*, int, int);
	Rockstar(const Rockstar&);
	Rockstar& operator=(const Rockstar&);
	~Rockstar();

	void print();

	bool operator>(const Rockstar&);
	bool operator<(const Rockstar&);
	bool operator==(const Rockstar &);
private:
	char*name;
	int awesomeness;
	int numberOfFans;
};

#endif