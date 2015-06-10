#include <iostream>
#include <cstring>
using namespace std;
#include "Human.h"

Human::Human():
    name(NULL),sila(0),loyalnost(0),priqteli(NULL),size(0),capacity(0)
{}

Human::Human(const char* name, int sila, int loyalnost, Human** priqteli, int size):
    name(NULL)
{
    setName(name);
    setSila(sila);
    setLoyalnost(loyalnost);
    capacity = this -> loyalnost;
    this -> size = 0;
    if(loyalnost != 0)
    {
        this -> priqteli = new Human* [loyalnost];
        for(int i = 0; i < size; i++)
        {
            addFriend(priqteli[i]);
        }
    }
    else
        this -> priqteli = NULL;
}


Human::~Human()
{
    delete [] name;
    // you should iterate priqteli to remove them. They are dynamic
    // - 0.1
    delete [] priqteli;
}

Human::Human(const Human& other)
{
    setName(other.name);
    setSila(other.sila);
    setLoyalnost(other.loyalnost);
    size = 0;
    capacity = loyalnost;
    if(loyalnost != 0)
    {
        priqteli = new Human* [loyalnost];
        for(int i = 0; i < other.size; i++)
        {
            addFriend(other.priqteli[i]);
        }
    }
    else
        priqteli = NULL;
}

Human& Human::operator= (Human& other)
{
    if(this == &other)
        return *this;
    setName(other.name);
    setSila(other.sila);
    setLoyalnost(other.loyalnost);
    capacity = loyalnost;
    if(size != 0)
        delete [] priqteli;
    size = 0;
    if(loyalnost != 0)
    {
        priqteli = new Human* [loyalnost];
        for(int i = 0; i < other.size; i++)
        {
            addFriend(other.priqteli[i]);
        }
    }
    else
        priqteli = NULL;
    return *this;
}

void Human::setName(const char* name)
{
    if(this -> name != NULL)
        delete [] this -> name;
    if(name == NULL)
        this -> name = NULL;
    else
    {
        size_t length = strlen (name) + 1;
        this -> name = new char [length];
        strncpy(this -> name, name, length);
    }
}

const char* Human::getName() const
{
    return name;
}

void Human::setSila(int sila)
{
    if(sila < 0)
        this -> sila = 0;
    else
        this -> sila = sila;
}

int Human::getSila() const
{
    return sila;
}

void Human::namalqvaneSila(int sila)
{
    this -> sila -= sila;
    if (this -> sila < 0)
        this -> sila = 0;
}

void Human::setLoyalnost(int loyalnost)
{
    if (loyalnost >= 0)
        this -> loyalnost = loyalnost;
    else
        this -> loyalnost = 0;
}

int Human::getLoyalnost() const
{
    return loyalnost;
}

void Human::addFriend(Human* newFriend)
{
    if(size == capacity)
        cout << "Maksimumat priqteli e dostignat\n";
    else
    {
        priqteli[size++] = newFriend;
    }
}

void Human::removeFriend(const Human& oldFriend)
{
    // almost
    // - 0.1
    for(int i = 0; i < size; i++)
        if(strcmp(priqteli[i] -> name,oldFriend.name) == 0)
        {
            Human ** tmp = new Human* [capacity];
            for(int j = 0, l = 0; l < size; l++)
                if(i != l)
                {
                    tmp[j] = priqteli[l];
                    j++;
                }
            delete [] priqteli;
            priqteli = tmp;
            size--;
            break;
        }
}

// the big 4
// - 0.1?