#include "band.h"
#include <iostream>
using namespace std;
Band::Band(int hereSize)
{
	this->size = hereSize;
	this->capasity = 0;
	all = new RockStar[this->size];
}

void Band::addStar(char* hereName, int hereAw, int fans)
{
	if (this->capasity == this->size)
	{
		RockStar* here;
		here = new RockStar[this->size];
		for (int i = 0; i < capasity; i++)
		{
			here[i] = all[i];
		}
		this->size *= 2;
		delete[] all;
		all = new RockStar[this->size];
		for (int i = 0; i < capasity; i++)
		{
			all[i] = here[i];
		}
		delete[] here;
	}
	all[capasity].setAw(hereAw);
	all[capasity].setName(hereName);
	all[capasity].setFans(fans);
	++capasity;

}

void Band::removeStar(char* hereName)
{
	for (int i = 0; i < capasity; i++)
	{
		if (strcmp(all[i].getName(), hereName) == 0)
		{
			RockStar here; 
			here = all[i];
			all[i] = all[capasity];
			all[capasity] = here;
			--capasity;
			break; 
		}
	}
}
void getStar(char* hereName);


void Band::printBand()
{
	for (int i = 0; i < capasity; i++)
	{
		cout << "Name: " << all[i].getName() << endl << "Awsomeness: " << all[i].getAw() << endl <<"Fans : "<< all[i].getFans() << endl;
	}
}

Band :: ~Band()
{
	delete[] all; 
}



Band& Band :: operator=(Band& other)
{
	all = new RockStar[other.size];
	this->capasity = other.capasity;
	for (int i = 0; i < other.capasity; i++)
	{
		all[i] = other.all[i];
	}
	return *this;
}



Band::Band(Band& other)
{
	all = new RockStar[other.size];
	this->capasity = other.capasity;
	for (int i = 0; i < other.capasity; i++)
	{
		all[i] = other.all[i];
	}
}


Band& Band :: operator+=(Band&other)
{
	RockStar* here;
	here = new RockStar[this->size];
	for (int i = 0; i <this-> capasity; i++)
	{
		here[i] = all[i];
	}
	delete[] all;
	this->size += other.size;
	all = new RockStar[this->size ];
	for (int i = 0; i < this->capasity; i++)
	{
		all[i] = here[i];
	}
	delete[] here;
	for (int i = this->capasity; i < this->capasity+other.capasity; i++)
	{
		all[i] = other.all[i- this->capasity];
	}
	this->capasity += other.capasity;
	return *this;
}
