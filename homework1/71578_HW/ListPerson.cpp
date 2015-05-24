#include <iostream>
#include <cstring>
#include "ListPerson.h"

using namespace std;

ListPerson :: ListPerson()
{
	currSize = 0;
	size = 1;
	visits[currSize].lastName = "";
	visits[currSize].dayOfBirth = 1;
	visits[currSize].month = 1;
	visits[currSize].birthYear = 1990;
}

ListPerson :: ListPerson (char * _lastName, int _dayOfBirth, int _month, int _birthYear)
{
	visits[currSize].lastName = _lastName;
	visits[currSize].dayOfBirth = _dayOfBirth;
	visits[currSize].month = _month;
	visits[currSize].birthYear = _birthYear;
}

ListPerson :: ~ListPerson()
{
	delete[] visits;
}

void ListPerson :: addVisit (const visit& other)
{
	if (currSize >= size)
	{
		visit* old = visits;
		visits = new visit[2 * size];
		for (int i = 0; i < currSize; i++)
		{
			visits[i] = old[i];
		}
		delete[] old;
		size = size * 2;
	}
	visits[currSize] = other;
	currSize++;
}

visit ListPerson :: findVisit (char * _lastName)
{
	for (int i = 0; i < currSize; i++)
	{
		if (visits[i].lastName == _lastName)
		{
			return visits[i];
			break;
		}
	}
}

void ListPerson :: removeVisit (char *_lastName)
{
	for (int i = 0; i < currSize; i++)
	{
		if (visits[i].lastName == _lastName) 
		{
			for (int j = i + 1; j < currSize - 1; j++) 
			{
				visits[j - 1] = visits[j];
			}
			currSize--;
		}
	}
}

void ListPerson :: printVisit(visit someVisit) const
{
	cout << "Last name: "		<< someVisit.lastName << endl
		<< "Date of birth: "	<< someVisit.dayOfBirth << "/" << someVisit.month << "/" << someVisit.birthYear << endl;
}
int main()
{
	return 0;
}