#include "Band.h"

Band::Band():
    name(NULL),arr(NULL),size(0),maxSize(0) {}

Band::Band (const char* name, RockStar& other):
    size(1), maxSize(1),name(NULL)
{
    if(name != NULL)
    {
        size_t length = strlen(name) + 1;
        this -> name = new char [length];
        strncpy(this -> name, name, length);
    }
    arr = new RockStar [maxSize];
    arr[0] = other;
}
Band& Band::operator= (Band& other)
{
    // if this ?? 
    // - 0.1
    size = other.size;
    maxSize = other.maxSize;
    if(other.name != NULL)
    {
        size_t length = strlen(other.name) + 1;
        name = new char [length];
        strncpy(name, other.name, length);
    }
    else
        name = NULL;
    if(other.arr != NULL)
    {
        arr = new RockStar[maxSize];
        for(int i = 0; i < size; i++)
            arr[i] = other.arr[i];
    }
    else
        arr = NULL;
}

Band::Band (Band& other):
    size(size),maxSize(maxSize),name(NULL),arr(NULL)
{
    if(other.name != NULL)
    {
        size_t length = strlen(other.name) + 1;
        name = new char [length];
        strncpy(name, other.name, length);
    }
    size = other.size;
    maxSize = other.maxSize;
    arr = new RockStar[maxSize];
    for(int i = 0; i < size; i++)
        arr[i] = other.arr[i];
}

Band::~Band ()
{
    delete [] arr;
    delete [] name;
}

void Band::addStar (RockStar& other)
{
    if(size == maxSize)
    {
        maxSize*=2;
        RockStar* tmp;
        tmp = new RockStar [maxSize];
        for(int i = 0; i < size; i++)
            tmp[i] = arr[i];
        delete [] arr;
        arr = tmp;
    }
    arr[size++] = other;
}

// decreasing size?
// - 0.2 
void Band::removeStar (const char* name)
{
    for(int i = 0; i < size; i++)
        if(strcmp(arr[i].getName(),name) == 0)
            arr[i] = arr[--size];
}
// return something if no star..
const RockStar& Band::getStar(const char* name) const
{
    for(int i = 0; i < size; i++)
        if(strcmp(arr[i].getName(),name) == 0)
            return arr[i];
    cout << "Nqma takava Rock Zvezda." << endl;
}
/*Band& Band::operator+= (Band& other)
{
    Band tmp = *this;
    delete [] arr;
    arr = new RockStar [5];
    for (int i = 0; i < size; i++)
        arr[i] = tmp;
    if(size < 5)
        for(int i = size, j = 0; i < 5; i++,j++)
            arr[i] = other.arr[j];

}*/


size_t Band:: getSize () const
{
    return size;
}

void Band::print () const
{
    cout << "Name: " << name << endl;
    for(int i = 0; i < size; i++)
    {
        cout << "Rock Star No " << i+1 << endl;
        arr[i].print();
    }
}
RockStar& Band::pickAFrontman () const
{
    RockStar tmp = arr[0];
    for (int i = 0; i < size; i++)
        if(tmp.getAwesomeness() < arr[i].getAwesomeness())
            tmp = arr[i];
    return tmp;
}
