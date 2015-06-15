//encapsulation
//abstraction
//polymorphism
//inheritence

#include <iostream>
#include <cassert>
#include <cstring>
#include <cmath>

using namespace std;

struct MusicSkill
{
private:
    char* name;
    int skill;
    void copyMusicSkill(const MusicSkill& other)
    {
        name = new char[strlen(other.name)+1];
        assert(name!=NULL);
        strcpy(name,other.name);
        skill = other.skill;
    }
    void delMusicSkill()
    {
        delete [] name;
    }
public:
    MusicSkill(char* n="",int s=1)
    {
        name = new char[strlen(n)+1];
        assert(name!=NULL);
        strcpy(name,n);
        skill = s;
    }
    MusicSkill(const MusicSkill& other)
    {
        copyMusicSkill(other);
    }
    MusicSkill& operator=(const MusicSkill& other)
    {
        if(this!=&other)
        {
            delMusicSkill();
            copyMusicSkill(other);
        }
        return *this;
    }
    ~MusicSkill()
    {
        delMusicSkill();
    }
    char* getName() const
    {
        return name;
    }
    int getSkill() const
    {
        return skill;
    }
    void setName(char* n)
    {
        delete [] name;
        name = new char[strlen(n)+1];
        assert(name!=NULL);
        strcpy(name,n);
    }
    void setSkill(int s)
    {
        skill = s;
    }
};

class Musician
{
private:
    char* name;
    void copyMusician(const Musician& other)
    {
        name = new char[strlen(other.name)+1];
        assert(name!=NULL);
        strcpy(name,other.name);
        beauty = other.beauty;
        badHabits = other.badHabits;
        numSkills = other.numSkills;

        for(int i=0;i<numSkills;i++)
        {
            skills[i] = other.skills[i];
        }
    }
    void delMusician()
    {
        // what about delete skills?
        // - 0.2 
        delete [] name;
    }
protected:
    int beauty;
    int badHabits;
    MusicSkill skills[5];
    int numSkills;
public:
    Musician(char* n="",int b=1,int bh=1)
    {
        name = new char[strlen(n)+1];
        assert(name!=NULL);
        strcpy(name,n);
        beauty = b;
        badHabits = bh;
        numSkills = 0;
    }
    Musician(const Musician& other)
    {
        copyMusician(other);
    }
    Musician& operator=(const Musician& other)
    {
        if(this!=&other)
        {
            delMusician();
            copyMusician(other);
        }
        return *this;
    }
    virtual ~Musician()
    {
        delMusician();
    }
    void setName(char* n)
    {
        delete [] name;
        name = new char[strlen(n)+1];
        assert(name!=NULL);
        strcpy(name,n);
    }
    char* getName() const
    {
        return name;
    }
    void addSkill(MusicSkill& s)
    {
        if(numSkills < 5)
        {
            skills[numSkills] = s;
            numSkills++;
            for(int i=numSkills-1;i>0;i--)
            {
                if(skills[i].getSkill() < skills[i-1].getSkill())
                {
                    MusicSkill tmp = skills[i];
                    skills[i] = skills[i-1];
                    skills[i-1] = tmp;
                }
                else
                {
                    break;
                }
            }
        }
    }
    MusicSkill* getTheStrongest(int n) const
    {
        // really?? :D
        // - 0.2
        MusicSkill tmp[n];
        for(int i=1;i<n;i++)
        {
            tmp[i] = skills[i];
        }
        return tmp;
    }
    int sumSkill() const
    {
        int sum = 0;
        for(int i=0;i<numSkills;i++)
        {
            sum += skills[i].getSkill();
        }
        return sum;
    }
    virtual int getBeauty() const = 0;
    virtual int getBadHabits() const = 0;
    virtual char* getType() = 0;
};

class Rocker : public Musician
{
public:
    Rocker(char* n="",int b=1,int bh=1):Musician(n,b,bh)
    {

    }
    Rocker(const Rocker& other) : Musician(other)
    {

    }
    Rocker& operator=(const Rocker& other)
    {
        if(this!=&other)
        {
            Musician::operator=(other);
        }
        return *this;
    }
    ~Rocker()
    {

    }
    int getBeauty() const
    {
        // 3.14 yeaaah
        // - 0.1
        return pow(beauty,2) + sumSkill() - badHabits*3*3.14;
    }
    int getBadHabits() const
    {
        return badHabits;
    }
    char* getType()
    {
        return "rock";
    }
};

class Tacky : public Musician
{
private:
    bool race;
public:
    Tacky(char* n="",int b=1,int bh=1,bool r=0) : Musician(n,b,bh)
    {
        race = r;
    }
    Tacky(const Tacky& other) : Musician(other)
    {
        race = other.race;
    }
    Tacky& operator=(const Tacky& other)
    {
        //race ?
        if(this!=&other)
        {
            Musician::operator=(other);
        }
        return *this;
    }
    ~Tacky()
    {

    }
    int getBeauty() const
    {
        return pow(beauty,5) + badHabits + race*cos(skills[0].getSkill());
    }
    int getBadHabits() const
    {
        return badHabits;
    }
    char* getType()
    {
        return "rock_tack";
    }
};

class Group
{
private:
    char* name;
    void copyGroup(const Group& other)
    {
        name = new char[strlen(other.name)+1];
        assert(name!=NULL);
        strcpy(name,other.name);
        numMusicians = other.numMusicians;
        
        for(int i=0;i<numMusicians;i++)
        {
            musicians[i] = other.musicians[i];
        }
    }
    void delGroup()
    {
        delete [] name;
    }
protected:
    Musician* musicians[10];
    int numMusicians;
public:
    Group(char* n="")
    {
        name = new char[strlen(n)+1];
        assert(name!=NULL);
        strcpy(name,n);
        numMusicians = 0;
    }
    Group(const Group& other)
    {
        copyGroup(other);
    }
    Group& operator=(const Group& other)
    {
        if(this!=&other)
        {
            delGroup();
            copyGroup(other);
        }
        return *this;
    }
    virtual ~Group()
    {
        delGroup();
    }
    virtual bool addMusicain(Musician* m) = 0;
    virtual bool removeMusician(char* n) = 0;
};

class RockGroup : virtual public Group
{public:
    RockGroup(char* n="") : Group(n)
    {

    }
    RockGroup(const RockGroup& other) : Group(other)
    {

    }
    RockGroup& operator=(const RockGroup& other)
    {
        if(this!=&other)
        {
            Group::operator=(other);
        }
        return *this;
    }
    ~RockGroup()
    {

    }
    bool addMusician(Musician* m)
    {
        if(!strcmp(m->getType(),"rock")||(m->getTheStrongest(1)->getSkill() >= 100))
        {
            musicians[numMusicians] = m;
            numMusicians++;
            return true;
        }
        return false;
    }
    bool removeMusician(char* n)
    {
        // delete??
        // - 0.2
        if(numMusicians > 0)
        {
            for(int i=0;i<numMusicians;i++)
            {
                if(!strcmp(musicians[i]->getName(),n))
                {
                    for(int j=i;j<numMusicians-1;j++)
                    {
                        musicians[j] = musicians[j+1];
                    }
                    numMusicians--;
                    return true;
                }
            }
        }
        return false;
    }
    double getAverageBeauty()
    {
        int sum = 0;
        for(int i=0;i<numMusicians;i++)
        {
            sum += musicians[i]->getBeauty();
        }
        return sum/numMusicians;
    }
    double getTotal()
    {
        int sumH = 0;
        int sumS = 0;
        for(int i=0;i<numMusicians;i++)
        {
            sumS += musicians[i]->sumSkill();
            sumH += musicians[i]->getBadHabits();
        }
        return sumS - sumH;
    }

};

class TackyGroup : virtual public Group
{
public:
    TackyGroup(char* n="") : Group(n)
    {

    }
    TackyGroup(const TackyGroup& other) : Group(other)
    {

    }
    TackyGroup& operator=(const TackyGroup& other)
    {
        if(this!=&other)
        {
            Group::operator=(other);
        }
        return *this;
    }
    ~TackyGroup()
    {

    }
    bool addMusician(Musician* m)
    {
        if(!strcmp(m->getType(),"rock_tack")||(m->getTheStrongest(1)->getSkill() < 10))
        {
            musicians[numMusicians] = m;
            numMusicians++;
            return true;
        }
        return false;
    }
    bool removeMusician(char* n)
    {
        //...
        if(numMusicians > 0)
        {
            for(int i=0;i<numMusicians;i++)
            {
                if(!strcmp(musicians[i]->getName(),n))
                {
                    for(int j=i;j<numMusicians-1;j++)
                    {
                        musicians[j] = musicians[j+1];
                    }
                    numMusicians--;
                    return true;
                }
            }
        }
        return false;
    }
    double getAverageBeauty()
    {
        int sum = 0;
        for(int i=0;i<numMusicians;i++)
        {
            sum += musicians[i]->getBeauty();
        }
        return sum/numMusicians;
    }
    double getTotal()
    {
        int sumB = 0;
        int sumS = 0;
        for(int i=0;i<numMusicians;i++)
        {
            sumS += musicians[i]->sumSkill();
            sumB += musicians[i]->getBeauty();
        }
        return sumS + sumB;
    }

};

class TackyRockGroup : public RockGroup, public TackyGroup
{
public:
    TackyRockGroup(char* n=""):Group(n),TackyGroup(n),RockGroup(n)
    {

    }
    TackyRockGroup(const TackyRockGroup& other) : Group(other),RockGroup(other), TackyGroup(other)
    {

    }
    TackyRockGroup& operator=(const TackyRockGroup& other)
    {
        if(this!=&other)
        {
            RockGroup::operator=(other);
            TackyGroup::operator=(other);
        }
        return *this;
    }
    ~TackyRockGroup()
    {

    }
    bool addMusician(Musician* m)
    {
        return RockGroup::addMusician(m) || TackyGroup::addMusician(m);
    }
    bool removeMusician(char* n)
    {
        // what about tackyGroup??
        return RockGroup::removeMusician(n);
    }
    double getAverageBeauty()
    {
        int sum = 0;
        for(int i=0;i<numMusicians;i++)
        {
            sum += musicians[i]->getBeauty();
        }
        return sum/numMusicians;
    }
};
// - 0 .3
int main()
{
    return 0;
}

//5.00