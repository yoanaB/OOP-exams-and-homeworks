#include<iostream>
using namespace std;
class Programmer
{
private:
	char* name;
	int iq;
	double salary;
	void copy(const Programmer&);
	void del();
public:
	Programmer();
	Programmer(char* name, int iq, double salary);
	Programmer(const Programmer&);
	void setName(char* name);
	void setIQ(int iq);
	void setSalary(double salary);
	char* getName();
	int getIQ();
	double getSalary();
	void print();
	~Programmer();
	int operator==(int iq);
	int operator<(int iq);
	int operator>(int iq);
};
class Team
{
private:
	Programmer* programmers;
	unsigned size;
	unsigned capacity;
	static unsigned lastIQ;
	Programmer getProgrammer(unsigned) const;
	unsigned getNumberOfProgrammers() const;
	void extend();
	void copy(const Team&);
	void del();
public:
	Team();
	Team(const Team&);
	~Team();
	void addProgrammer(const Programmer&);
	void removeProgrammer(unsigned);
	void sort();
	void print();
	Team& operator -=(Team&);
};
class Company
{
private:
	Team*teams;
	unsigned size;
	unsigned capacity;
	void copy(const Company&);
	void del();
public:
	Company();
	Company(const Company&);
	~Company();
	void print();
};