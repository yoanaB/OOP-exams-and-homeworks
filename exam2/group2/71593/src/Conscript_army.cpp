#include <iostream>
#include <cstring>
using namespace std;

#include "Conscript_army.h"

bool Conscript_army::operator>(Army& other)
{
    //..
    if(getOcenka() > other.getOcenka())
        return 1;
    return 0;
}

void Conscript_army::addVoinik(Human* newVoinik)
{
    if(capacity == 100)
        cout << "Ima prekaleno mnogo voinici\nVoinikat ne moje da bade dobaven";
    else
        voinici[capacity++] = newVoinik;
}

void Conscript_army::removeVoinik(Human* oldVoinik)
{
    for(int i = 0; i < capacity; i++)
        if(strcmp(voinici[i]->getName(),oldVoinik->getName()) == 0)
        {
            voinici[i] = voinici[capacity - 1];
            capacity--;
            break;
        }
}

void Conscript_army::addLider(Human* newLider)
{
    // leaking memory here
    // - 0.2
    lider = newLider;
}

int Conscript_army::getOcenka() const
{
    int ocenka = 0;
    for(int i = 0; i < capacity; i++)
        ocenka+= voinici[i] -> getLoyalnost()*lider -> getLoyalnost() + voinici[i] -> getSila();
    return ocenka;
}
