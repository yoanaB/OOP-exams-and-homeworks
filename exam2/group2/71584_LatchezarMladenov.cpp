// Encapsulation, Abstraction, Polymorphism, Inheritance

#include <iostream>
#include <cstring>
#include <cassert>

// wut??
class NormalHuman{
protected:
    char* name;
    int skill;
    void init(char* name, int skill)
    {
        this->name = name;
        this->skill = skill;
        this->name = new char[strlen(name) + 1];
        assert(this->name != NULL);
        strcpy(this->name, name);
    }
public:
    int getSkill () {
        return this->skill;
    }

    void setSkill(int skill) {
        this->skill = skill;
    }

    char* getName () {
        return this->name;
    }

    void setName () {
        delete [] this->name;
        this->name = new char[strlen(name) + 1];
        assert(this->name != NULL);
        strcpy(this->name, name);
    }

    NormalHuman (char* name = "", int skill = 0){
        init(name, skill);
    }

    NormalHuman (const NormalHuman& other){
        init(other.name, other.skill);
    }

    ~NormalHuman(){
        delete [] this->name;
    }

};

class Human : public NormalHuman {
protected:
    char* name;
    int strength;
    int  loyalty;
    NormalHuman skills[5];
    int skillsCount;
    void init(char* name, int strength, int loyalty, int skillsCount = 0, const NormalHuman* skills = NULL){
        this->skillsCount = skillsCount;
        this->strength = strength;
        this->loyalty = loyalty;
        this->name = new char[strlen(name) + 1];
        assert(this->name != NULL);
        strcpy(this->name, name);
        for(int i = 0; i < skillsCount; i++)
        {
            this->skills[i] = skills[i];
        }
    }

public:
    virtual double getStrength() = 0;
    virtual char* getType() = 0;

    char* getName(){
        return this->name;
    }

    void setName(char* name){
        delete [] this->name;
        this->name = new char[strlen(name)+1];
        assert(this->name != NULL);
        strcpy(this->name , name);
    }


    Human(char* name = "", int strength = 0, int loyalty= 0) {
        init(name, strength, loyalty);
    }

    Human(const Human& other) {
        init(other.name, other.strength, other.loyalty, other.skillsCount, other.skills);
    }


    ~Human() {
        delete[] this->name;
    }
};
 // - 0.2
class Army {
protected:
    Human* warriors[100];
    // no?
    // - 0.1
    char* leader;
    int warriorsNum;
    void init(char* leader, int warriorsNum = 0, Human* const* warriors = NULL) {
        this->leader = new char[strlen(leader) + 1];
        assert(this->leader != NULL);
        strcpy(this->leader, leader);
        this->warriorsNum = warriorsNum;
        for(int i = 0; i < warriorsNum; i++) {
            this->warriors[i] = warriors[i];
        }
    }
public:
    virtual bool addWarrior() = 0;
    virtual bool removeWarrior() = 0;
    virtual bool changeLeader() = 0;
    virtual void getTask() = 0;
};


class PaidArmy : virtual public Army {
protected:
    int budget;
    double salary;
    void init(int budget, int salary)
    {
        // no 
        // - 0.2
        this->budget = budget;
        this->salary = salary;
    }
public:

    int getBudget() {
        return this->budget;
    }

    void setBudget(int budget) {
        this->budget = budget;
    }

    double getSalary(){
        return this->salary;
    }

    void setSalary(double salary) {
        this->salary = salary;
    }

    PaidArmy(int budget = 0, double salary = 0){
        init(budget, salary);
    }

    PaidArmy(const PaidArmy& other){
        init(other.budget, other.salary);
    }

    ~PaidArmy() {}

};

// a lot of missing stuffs 
// - 0 .5
class ConscriptArmy : virtual public Army {


};

class Targaryen : public Human {
public:
    int age;
    char* getType() {
        return "fire";
    }

    Targaryen(char* name = "", int strength = 0, int loyalty = 0, int age = 0) : Human(name, strength, loyalty) {
        this->age = age;
    }
};

class Stark : public Human {
public:
    char* getType() {
        return "ice";
    }

    Stark(char* name = "", int strength = 0, int loyalty = 0, int age = 0) : Human(name, strength, loyalty) { }
};


class Targaryen_Stark : public Targaryen, Stark {
public:
    Targaryen_Stark(char* name = "", int strength = 0, int loyalty = 0, int age = 0) : Human(name, strength, loyalty) { }
};


// - 2.2