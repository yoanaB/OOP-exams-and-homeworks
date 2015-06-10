#include <iostream>
#include <cstring>
using namespace std;

#include "Paid_army.h"

Paid_army::Paid_army():Army()
{
    budjet = 0;
    zaplataVoinik = 0;
}

Paid_army::Paid_army(Paid_army& other)
{
    Army::operator=(other);
    budjet = other.budjet;
    zaplataVoinik = other.zaplataVoinik;
}

Paid_army& Paid_army::operator=(Paid_army& other)
{
    if(this == &other)
        return *this;
    Army::operator=(other);
    budjet = other.budjet;
    zaplataVoinik = other.zaplataVoinik;
    return *this;
}

bool Paid_army::operator>(Army& other)
{
    // return getOcenka() > other.getOcenka() ? :)

    if(getOcenka() > other.getOcenka())
        return 1;
    return 0;
}

void Paid_army::addVoinik(Human* newVoinik)
{
    if(capacity == 100)
        cout << "Ima prekaleno mnogo voinici\nVoinikat ne moje da bade dobaven";
    else
        voinici[capacity++] = newVoinik;
}

void Paid_army::removeVoinik(Human* oldVoinik)
{
    for(int i = 0; i < capacity; i++)
        if(strcmp(voinici[i]->getName(),oldVoinik->getName()) == 0)
        {
            voinici[i] = voinici[capacity - 1];
            capacity--;
            break;
        }
    //leaking memory
        // - 0 .2
}

void Paid_army::addLider(Human* newLider)
{
    if(strcmp(newLider -> getType(),"none") == 0 || strcmp(newLider -> getType(),"Targaryen") == 0)
    {
        lider = newLider;
    }
    else
        cout << "Noviq lider ne e ot saotvetniq tip\n";
}

int Paid_army::getOcenka() const
{
    int ocenka = lider -> getLoyalnost()*(budjet*0.8) + lider -> getSila();
    for(int i = 0; i < capacity; i++)
        ocenka += voinici[i] -> getSila();
    return ocenka;
}
