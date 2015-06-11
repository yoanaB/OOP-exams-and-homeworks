#ifndef ARMY_H
#define ARMY_H

#include "Human.h"

class Army {
    protected:
        Human* soldiers[100];
        int numberOfSoldiers;
        Human* leader;
    public:
        virtual void addSoldier(Human* soldier) = 0;
        virtual void removeSoldier(Human* soldier) = 0;
        virtual void changeLeader(Human* newLeader) = 0;
        virtual int getArmyPower() = 0;

};

#endif // ARMY_H
