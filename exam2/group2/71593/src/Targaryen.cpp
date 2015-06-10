#include <iostream>
#include <cstring>
using namespace std;
#include "Targaryen.h"

Targaryen::Targaryen():Human(),godini(0)
{}



void Targaryen::addFriend(Human* newFriend)
{
    char* tmp = newFriend -> getType();
    if(strcmp(tmp,"Targaryen") == 0)
    {
        if(size == capacity)
            cout << "Maksimumat priqteli e dostignat\n";
        else
        {
            priqteli[size++] = newFriend;
        }
    }
}

void Targaryen::setLoyalnost (int loyalnost)
{
    Human::setLoyalnost(loyalnost);
}

int Targaryen::getLoyalnost() const
{
    return loyalnost * godini;
}

const char* Targaryen::getSpecialSkill() const
{
    return "fire";
}

int Targaryen::getOcenkaOtmashtenie() const
{
    int ocenka = 0;
    for(int i = 0; i < size; i++)
        ocenka += 2*priqteli[i] -> getSila();
    return ocenka;
}

char* Targaryen::getType() const
{
    return "Targaryen";
}

void Targaryen::setAge(int godini)
{
    this -> godini = godini;
}

int Targaryen::getAge() const
{
    return godini;
}
//...