#include "Concert.h"
Concert::Concert(int hereSize = 0)
{
	this->size = hereSize;
	this->capacity = 0;
	here = new Band[this->size];
}
Concert& Concert ::  operator=(Concert&)
{

}
Concert(Concert&);

Concert ::~Concert()
{
	delete[] here;
}
