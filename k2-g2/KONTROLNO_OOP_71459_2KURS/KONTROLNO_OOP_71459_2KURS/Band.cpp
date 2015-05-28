#include "Band.h"
#include <iostream>
using namespace std;

unsigned int Band::cnt = 0;

Band::Band()
{
	stars = NULL;
}

Band::Band(Band& r)
{
	this->cnt = r.cnt;
	for(size_t i = 0; i < this->cnt; i++)
	{
		this->stars[i] = r.stars[i];
	}
}

Band::~Band()
{
	delete[] stars;
}
// nope ... 
// - 0.3
void Band::addStar(RockStar& r)
{
	RockStar* buffer = new RockStar[cnt];
	if(!buffer)
	{
		cerr << "Error allocating memory!";
	}
	for(size_t i = 0; i < cnt; i++)
	{
		buffer[i] = stars[i];
	}
	delete[] stars;
	
	cnt++;
	
	stars = new RockStar[cnt];
	if(!stars)
	{
		cerr << "Error allocating memory!";
	}

	for(size_t i = 0; i < cnt - 1; i++)
	{
		stars[i] = buffer[i];
	}
	stars[cnt - 1] = r;
	
}
// nope ... 
// - 0.3
void Band::removeStar(const char* name)
{
	int delIndex = 0;
	for(size_t i = 0; i < cnt; i++)
	{
		if(strcmp(stars[i].getName(), name) == 0)
		{
			delIndex = i;
		}
	}
	for(int i = delIndex; i < cnt - 1; i++)
	{
		RockStar tmp = stars[i];
		stars[i] = stars[i + 1];
		stars[i + 1] = tmp;
	}

	cnt--;
	RockStar* buffer = new RockStar[cnt];
	if(!buffer)
	{
		cerr << "Error allocating memory!";
	}
	delete[] stars;
	
	stars = new RockStar[cnt];
	for(size_t i = 0; i < cnt; i++)
	{
		stars[i] = buffer[i];
	}
}

RockStar& Band::getStar(const char* name)
{
	for(size_t i = 0; i < cnt; i++)
	{
		if(strcmp(stars[i].getName(), name) == 0)
			return stars[i];
	}
}

void Band::print()
{
	cout << "Band info:" << endl;
	for(size_t i = 0; i < cnt; i++)
	{
		stars[i].print();
		cout << endl;
	}
}

int Band::averageAwesomeness()
{
	int result = 0;
	for(size_t i = 0; i < cnt; i++)
	{
		result += stars[i].getAwesomeness();
	}
	result = result / cnt;
	return result;
}

bool Band::operator==(Band& r)
{
	bool result = false;
	if(this->cnt == r.cnt)
		result = true;

	for(size_t i = 0; i < this->cnt; i++)
	{
		if(!(stars[i] == r.stars[i]))
		{
			result = false;
		}
	}
	return result;
}

Band& Band::operator=(Band& r)
{
	if(!(r == *this))
	{
		delete[] this->stars;
		this->cnt = r.cnt;
		this->stars = new RockStar[this->cnt];

		for(size_t i = 0; i < this->cnt; i++)
		{
			this->stars[i] = r.stars[i];
		}
		return *this;
	}
}