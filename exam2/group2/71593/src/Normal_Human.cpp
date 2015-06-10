#include <iostream>
#include <cstring>
using namespace std;

#include "Normal_Human.h"

int Normal_Human::getOcenkaOtmashtenie() const
{
    int ocenka = 0;
    for(int i = 0; i < size; i++)
        ocenka += priqteli[i] -> getSila();
    return ocenka;
}

char* Normal_Human::getType() const
{
    return "none";
}

void Normal_Human::addFriend(Human* newFriend)
{
    char* tmp = newFriend -> getType();
    if(strcmp(tmp,"none") == 0)
    {
        if(size == capacity)
            cout << "Maksimumat priqteli e dostignat\n";
        else
        {
            priqteli[size++] = newFriend;
        }
    }
}
