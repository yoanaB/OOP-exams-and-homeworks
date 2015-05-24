#ifndef LIST_H
#define LIST_H

struct Date
{
public:
	Date();
	void setDate(int, int, int);
	int getMonth() const;
	int getDay() const;
	int getYear() const;
	void print() const;
	bool isLeap() const;
	bool isValid() const;
	Date& operator=(const Date&);
private:
	int day,
		month,
		year;
};
class Person
{
public:
	Person();
	~Person();
	Person(const Person&);
	Person& operator=(const Person&);
	void setDate(const Date&);
	Date getDate() const;
	void setName(char*);
	char* getName() const;
	void print();
private:
	char* lastName;
	Date birthDate;
};

class ListPerson
{
public:
	ListPerson();
	~ListPerson();
	ListPerson(const ListPerson&);
	ListPerson& operator=(const ListPerson&);
	int getCount() const;
	void addPerson(const Person&);
	void deletePerson(char*);
	Person* getPerson(char*);
	ListPerson& unionList(const ListPerson&);
	ListPerson& sectionList(const ListPerson&);
	ListPerson& differenceList(const ListPerson&);
	void print();
private:
	Person* list;
	int size;
	int count;
};

struct Zodiak
{
	char* name;
	Date start;
	Date end;
	void setName(char*);
	char* getName() const;
	void setStart(const Date&);
	Date getStart() const;
	void setEnd(const Date&);
	Date getEnd() const;
};

#endif