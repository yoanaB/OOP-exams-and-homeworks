#ifndef HUMAN_H
#define HUMAN_H

#include <iostream>
using namespace std;

class Human {
    private:
        char* name;
        int health;
        int loyalty;
        Human** friends;

    public:
        Human(char* arg_name, int arg_health, int arg_loyalty);
        ~Human();

        void setName(char* arg_name);
        void setHealth(int arg_health);
        void setLoyalty(int arg_loyalty);

        char* getName();
        int getHealth();
        int getLoyalty();

        int getRevengeScore();

        char* getSpecialSkill();

        void decreaseHealth(int amount);

        void addFriend(Human* newFriend);
        void removeFriend(Human* formerFriend);

};

#endif // HUMAN_H
