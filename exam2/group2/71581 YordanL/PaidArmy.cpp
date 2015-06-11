#include "PaidArmy.h"

PaidArmy::PaidArmy(int arg_budget) {
    numberOfSoldiers = 0;
    leader = NULL;
    budget = arg_budget;
    for(int i = 0; i < 100; i++) {
        soldiers[i] = NULL;
    }
    updateSalary();
}

PaidArmy::~PaidArmy() {
    //dynamic soliders

    delete[] soldiers;
    delete leader;
}

void PaidArmy::addSoldier(Human* soldier) {
    for(int i = 0; i < 100; i++) {
        if( soldiers[i] == NULL){
            soldiers[i] = soldier;
            numberOfSoldiers++;
            break;
        }
    }
    updateSalary();
}

void PaidArmy::removeSoldier(Human* soldier) {
    for(int i = 0; i < 100; i++) {
        if( soldiers[i] != NULL){
            soldiers[i] = NULL;
            numberOfSoldiers++;
            break;
        }
    }
    updateSalary();
}

void PaidArmy::changeLeader(Human* arg_leader) {
    // leak
    // - 0.2
    leader = arg_leader;
    addSoldier(leader);
}

int PaidArmy::getArmyPower() {
    return ((double)80/100) * budget + (leader == NULL ? 0 : leader->getLoyalty());
}

void PaidArmy::updateSalary() {
    if(numberOfSoldiers)
        baseSalary = 0;
    baseSalary = (((double)80/100) * budget) / numberOfSoldiers;
}

bool PaidArmy::operator<(Army& otherArmy) {
    if(this->getArmyPower() < otherArmy.getArmyPower())
        return false;
    return true;
}
