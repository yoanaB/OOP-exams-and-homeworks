#include <iostream>
#include <cstring>
using namespace std;
#include "Stark.h"

Stark::Stark():Human()
{}


void Stark::addFriend(Human* newFriend)
{
    char* tmp = newFriend -> getType();
    bool flag = 1;
    if(strcmp(tmp,"Targaryen") == 0)
    {
        for(int i = 0; i < size; i++)
        if(strcmp(priqteli[i]->getType(),"Targaryen") == 0)
            flag = 0;
    }
    if(size == capacity)
        cout << "Maksimumat priqteli e dostignat\n";
    else if(flag)
    {
        priqteli[size++] = newFriend;
    }
}

int Stark::getLoyalnost() const
{
    return loyalnost + size;
}

const char* Stark::getSpecialSkill() const
{
    return "ice";
}

int Stark::getOcenkaOtmashtenie() const
{
    int ocenka = 0;
    for(int i = 0; i < size; i++)
    {
        if(strcmp(priqteli[i]->getType(),"Targaryen") == 0)
            ocenka += priqteli[i] -> getSila() * 2;
        else if(strcmp(priqteli[i] -> getType(),"Stark") == 0)
            ocenka += priqteli[i] -> getSila() * 3;
        else
            ocenka += priqteli[i] -> getSila();
    }

}

char* Stark::getType() const
{
    return "Stark";
}

void Stark::setLoyalnost(int loyalnost)
{
    Human::setLoyalnost(loyalnost - size);
}
// the big 4 
// - 0.2