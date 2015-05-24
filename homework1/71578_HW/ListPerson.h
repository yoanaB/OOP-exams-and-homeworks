#ifndef LISTPERSON_H
#define LISTPERSON_H
struct visit
{
	char * lastName;
	int dayOfBirth;
	int month;
	int birthYear;
};

class ListPerson
{
private:
	visit* visits;
	static int currSize;
	static int size;

public:
	ListPerson();
	ListPerson(char*, int, int, int);
	~ListPerson();

	ListPerson (const ListPerson&);
	void addVisit (const visit&);
	void removeVisit (char*);
	visit findVisit (char* lastName);
	void printVisit(visit someVisit) const;

}
#endif