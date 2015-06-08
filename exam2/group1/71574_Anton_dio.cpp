//Абстракция, Полиморгизъм, Наследяване, Енкапсулация

#include <iostream>
#include <cassert>
#include <cstring>
#include <cmath>
using namespace std;

class MusicalSkill {
private:
    char* instrument;
    int skill;
    void init(char* instrument, int skill) {
        this->skill = skill;
        this->instrument = new char[strlen(instrument) + 1];
        assert(this->instrument != NULL);
        strcpy(this->instrument, instrument);
    }
public:
    int getSkill() {
        return this->skill;
    }

    void setSkill(int skill) {
        this->skill = skill;
    }

    char* getInstrument() {
        return this->instrument;
    }

    void setInstrument(char* instrument) {
        delete[] this->instrument;
        this->instrument = new char[strlen(instrument) + 1];
        assert(this->instrument != NULL);
        strcpy(this->instrument, instrument);
    }

    MusicalSkill(char* instrument = "", int skill = 0) {
        init(instrument, skill);
    }

    MusicalSkill(const MusicalSkill& other) {
        init(other.instrument, other.skill);
    }

    MusicalSkill& operator=(const MusicalSkill& other) {
        if(this != &other) {
            delete[] this->instrument;
            init(other.instrument, other.skill);
        }
        return *this;
    }

    ~MusicalSkill() {
        delete[] this->instrument;
    }
};

class Musician {
protected:
    char* name;
    int beauty;
    int sins;
    MusicalSkill skills[5];
    int skillsCount;
    void init(char* name, int beauty, int sins, int skillsCount = 0, const MusicalSkill* skills = NULL) {
        this->skillsCount = skillsCount;
        this->beauty = beauty;
        this->sins = sins;
        this->name = new char[strlen(name) + 1];
        assert(this->name != NULL);
        strcpy(this->name, name);
        for(int i = 0; i < skillsCount; i++) {
            this->skills[i] = skills[i];
        }
    }
public:
    virtual double getBeauty() = 0;
    virtual char* getType() = 0;

    bool addSkill(MusicalSkill skill) {
        if(this->skillsCount < 5) {
            this->skills[this->skillsCount] = skill;
            this->skillsCount++;
            return true;
        }
        return false;
    }

    int getMaxSkill() {
        int skill = -1;
        for(int i = 0; i < this->skillsCount; i++) {
            if(this->skills[i].getSkill() > skill) {
                skill = this->skills[i].getSkill();
            }
         }
         return skill;
    }

    int getMinSkill() {
        int skill = -1;
        if(this->skillsCount > 0) {
            skill = this->skills[0].getSkill();
            for(int i = 1; i < this->skillsCount; i++) {
                if(this->skills[i].getSkill() < skill) {
                    skill = this->skills[i].getSkill();
                }
             }
        }
        return skill;
    }

    int sumAllSkills() {
        int sum = 0;
        for(int i = 0; i < this->skillsCount; i++) {
            sum += this->skills[i].getSkill();
        }
        return sum;
    }

    int getSins() {
        return this->sins;
    };

    char* getName() {
        return this->name;
    }

    void setName(char* name) {
        delete[] this->name;
        this->name = new char[strlen(name) + 1];
        assert(this->name != NULL);
        strcpy(this->name, name);
    }

    Musician(char* name = "", int beauty = 0, int sins = 0) {
        init(name, beauty, sins);
    }

    Musician(const Musician& other) {
        init(other.name, other.beauty, other.sins, other.skillsCount, other.skills);
    }

    Musician& operator=(const Musician& other) {
        if(this != &other) {
            delete[] this->name;
            init(other.name, other.beauty, other.sins, other.skillsCount, other.skills);
        }
        return *this;
    }

    ~Musician() {
        delete[] this->name;
    }
};

class RockStar: public Musician{
public:
    char* getType() {
        return "rock";
    }

    double getBeauty() {
        int sum = 0;
        for(int i = 0; i < this->skillsCount; i++) {
            sum += this->skills[i].getSkill();
        }

        return beauty * beauty + sum - sins * 3 * M_PI;
    }

    RockStar(char* name = "", int beauty = 0, int sins = 0): Musician(name, beauty, sins) {}
};

class FolkStar: public Musician {
private:
    bool race;
public:
    char* getType() {
        return "rock_tack";
    }

    double getBeauty() {
        int skill = 0;
        if(this->skillsCount > 0) {
            skill = this->skills[0].getSkill();
            for(int i = 1; i < this->skillsCount; i++) {
                if(this->skills[i].getSkill() > skill) {
                    skill = this->skills[i].getSkill();
                }
            }
        }

        return pow(beauty, 5) + sins + race * cos(skill);
    }

    FolkStar(char* name = "", int beauty = 0, int sins = 0, bool race = false): Musician(name, beauty, sins) {
        this->race = race;
    }
};

class Group {
protected:
    char* name;
    Musician* members[10];
    int membersCount;
    void init(char* name, int membersCount = 0, Musician* const* members = NULL) {
        this->name = new char[strlen(name) + 1];
        assert(this->name != NULL);
        strcpy(this->name, name);
        this->membersCount = membersCount;
        for(int i = 0; i < membersCount; i++) {
            this->members[i] = members[i];
        }
    }

public:
    virtual double getValue() = 0;

    bool addMusician(Musician& musician) {
        if(this->membersCount < 10) {
            this->members[this->membersCount] = &musician;
            this->membersCount++;
            return true;
        }
        return false;
    }

    bool removeMusician(char* name) {
        int index = -1;
        for(int i = 0;i < this->membersCount; i++) {
            if(strcmp(name, this->members[i]->getName()) == 0) {
                index = i;
                break;
            }
        }

        if(index == -1) {
            return false;
        }
        // some delete here??
        // - 0.2
        for(int i = index; i < this->membersCount - 1; i++) {
            this->members[i] = this->members[i + 1];
        }
        this->membersCount--;
        return true;
    }

    char* getName() {
        return this->name;
    }

    void setName(char* name) {
        delete[] this->name;
        this->name = new char[strlen(name) + 1];
        assert(this->name != NULL);
        strcpy(this->name, name);
    }

    double getAverageBeauty() {
        double sum = 0;
        for(int i = 0; i < this->membersCount; i++) {
            sum += this->members[i]->getBeauty();
        }

        return sum / this->membersCount;
    }

    Group(char* name = "") {
        init(name);
    }

    Group(const Group& other) {
        init(other.name, other.membersCount, other.members);
    }

    Group& operator=(const Group& other) {
        if(this != &other) {
            delete[] this->name;
            init(other.name, other.membersCount, other.members);
        }
        return *this;
    }

    ~Group() {
        delete[] this->name;
    }
};

class RockGroup: virtual public Group {
public:
    bool addMusician(Musician& musician) {
        if(strcmp("rock", musician.getType()) == 0 ||
           musician.getMaxSkill() > 100) {
            return Group::addMusician(musician);
        }
        return false;
    }

    double getValue() {
        double sum = 0;
        for(int i = 0; i < membersCount; i++) {
            sum += members[i]->sumAllSkills() - members[i]->getSins();
        }
        return sum;
    }

    RockGroup(char* name = ""): Group(name){}
};

class FolkGroup: virtual public Group {
public:
    bool addMusician(Musician& musician) {
        // 10 not 100   
        if(strcmp("rock_tack", musician.getType()) == 0 ||
           (musician.getMinSkill() < 100 && musician.getMinSkill() != -1)) {
            return Group::addMusician(musician);
        }
        return false;
    }

    double getValue() {
        double sum = 0;
        for(int i = 0; i < membersCount; i++) {
            sum += members[i]->sumAllSkills() + members[i]->getBeauty();
        }
        return sum;
    }

    FolkGroup(char* name = ""): Group(name){}
};

class FolkRockGroup: public RockGroup, public FolkGroup {
public:
    bool addMusician(Musician& musician) {
        bool added = RockGroup::addMusician(musician);
        if(!added) {
            added = FolkGroup::addMusician(musician);
        }
        return added;
    }

    double getValue() {
        // sum of all music skills?
        // - 0.2
        int changesCount = 0;
        for(int i = 0; i < membersCount - 1; i++) {
            if(strcmp(members[i]->getType(), members[i + 1]->getType()) != 0) {
                changesCount++;
            }
        }
        return changesCount;
    }

    FolkRockGroup(char* name = ""): Group(name), RockGroup(name), FolkGroup(name){}
};

// 5.60