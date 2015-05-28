#include "Concert.h"
#include <iostream>
using namespace std;

//броя групи на концерта
unsigned int Concert::cnt = 0;

Concert::Concert()
{
	bands = NULL;
}

Concert::Concert(Concert& r)
{
	this->cnt = r.cnt;
	for(size_t i = 0; i < this->cnt; i++)
	{
		this->bands[i] = r.bands[i];
	}
}

Concert::~Concert()
{
	delete[] bands;
}

int Concert::averageAwesomeness()
{
	int result = 0;
	for(size_t i = 0; i < cnt; i++)
	{
		result += bands[i].averageAwesomeness();
	}
	result = result / cnt;
	return result;
}

// no operator = 
// no headliners

// - 0.4