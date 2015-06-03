#ifndef CARD_H
#define CARD_H
struct Card
{
public:
	void setName(char*);
	void setDay(int);
	void setYear(int);
	void setMonth(int);
	char* getName()const;
	void print()const;
	int getDay();
	int getMonth();
	int getYear();
	void getDate();
	~Card();
	Card();
	Card(int, int, int, char*);
	Card& operator=(const Card&);
	Card(const Card&);
	bool operator==(const Card&)const;

	
private:
	char*name;
	int day;
	int month;
	int year;
};
#endif
