#include "Human.h"

Human::Human(char* arg_name, int arg_health, int arg_loyalty) {
    name = arg_name;
    health = arg_health;
    loyalty = arg_loyalty;
    friends = new Human*[loyalty];
    for(int i = 0; i < loyalty; i++) {
        friends[i] = NULL;
    }
}

Human::~Human() {
    delete name;
    //friends are dynamic

    delete[] friends;
}

void Human::setName(char* arg_name) {
    name = arg_name;
}

void Human::setHealth(int arg_health) {
    if(arg_health < 0) {
        health = arg_health;
    }
    else {
        health = 0;
        cout << "Error! " << name << " can't have " << arg_health << " health!" << endl;
        cout << "Health set to 0.";
    }
}

void Human::setLoyalty(int arg_loyalty) {
    loyalty = arg_loyalty;
}

void Human::decreaseHealth(int amount) {
    health -= amount;
    if(health < 0)
        health = 0;
}

char* Human::getName() {
    return name;
}

int Human::getHealth() {
    return health;
}

int Human::getLoyalty() {
    return loyalty;
}

char* Human::getSpecialSkill() {
    return "none";
}

int Human::getRevengeScore() {
    int res = 0;
    for(int i = 0; i < loyalty; i++) {
        if(friends[i] != NULL) {
            res += friends[i]->getHealth();
            break;
        }
    }
    return res;
}

// hmm...

// ?? 
// - 0.2
void Human::addFriend(Human* newFriend) {
    for(int i = 0; i < loyalty; i++) {
        if(friends[i] == NULL) {
         for(int i = 0; i < loyalty; i++) {
        if(friends[i] == NULL) {
            friends[i] = newFriend;
            break;
        }
    }   friends[i] = newFriend;
        }
    }
}

void Human::removeFriend(Human* formerFriend) {
    // leak memory
    // - 0.1
    for(int i = 0; i < loyalty; i++) {
        if(friends[i] != NULL) {
            friends[i] = NULL;
            break;
        }
    }
}
