#ifndef PAIDARMY_H
#define PAIDARMY_H

#include "Army.h"

class PaidArmy: public Army {
    private:
        int budget;
        int baseSalary;

    public:
        PaidArmy(int arg_budget);
        ~PaidArmy();

        void addSoldier(Human* soldier);
        void removeSoldier(Human* soldier);
        void changeLeader(Human* newLeader);
        int getArmyPower();

        void updateSalary();

        bool operator<(Army& otherArmy);

};

#endif // PAIDARMY_H
