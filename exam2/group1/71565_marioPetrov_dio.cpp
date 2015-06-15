#include <iostream>
#include <cstring>
#include <cassert>
#include <cmath>
/*
 1.Abstraction.
 2. Encapsulation.
 3. Inheritance.
 4.Polymorphism.
 */
class Musical_skill
{

protected:
    char*name;
    int skill;
public:
    Musical_skill(char*name="",int skill=0)
    {
        this->name=new char[strlen(name)+1];
        assert(this->name!=NULL);
        strcpy(this->name,name);
        this->skill=skill;
    }
    ~Musical_skill()
    {
        delete[]name;
    }
    Musical_skill(const Musical_skill &other)
    {
        this->name=new char[strlen(other.name)+1];
        assert(this->name!=NULL);
        strcpy(this->name,other.name);
        this->skill=other.skill;
    }
    Musical_skill &operator=(const Musical_skill &other)
    {
        if(this!=&other)
        {
            delete[]name;
            this->name=new char[strlen(other.name)+1];
            assert(this->name!=NULL);
            strcpy(this->name,other.name);
            this->skill=other.skill;

        }
        // return ? 
        // - 0.1
    }


};
class Musician
{
protected:
    char*name;
    int beauty;
    int badFeatures;
    Musical_skill mskill[5];
public:
    Musician(char*name="",int beauty=2,int badFeatures=5)
    {}
    ~Musician()
    {
        delete []name;
    }
    Musician(const Musician &other)
    {
        this->name=new char[strlen(other.name)+1];
        assert(this->name!=NULL);
        strcpy(this->name,other.name);
        this->beauty=other.beauty;
        this->badFeatures=other.badFeatures;
        for(int i=0; i<5; i++)
        {
            this->mskill[i]=other.mskill[i];
        }
    }
    Musician &operator=(const Musician &other)
    {
        if(this!=&other)
        {
            delete[]name;
            this->name=new char[strlen(other.name)+1];
            assert(this->name!=NULL);
            strcpy(this->name,other.name);
            this->beauty=other.beauty;
            this->badFeatures=other.badFeatures;

            for(int i=0; i<5; i++)
            {
                this->mskill[i]=other.mskill[i];
            }


        }
    }
    virtual int getBadFeatures()=0 ;
    virtual int getBeauty()=0 ;
    virtual const char*getName()=0;
    virtual void setName()=0;
    virtual const char*getType()=0;
    virtual Musical_skill getStrongest()=0;
};
class Rocker: public Musician
{
public:
    virtual const char*getType()
    {
        return "rock";
    }
    virtual int getBadFeatures()
    {
        return badFeatures;
    }
    virtual int getBeauty()
    {
        // there is Pi in cmath
        // - 0.1
        const double pi=3.14;
        int allSkills=0;
        for(int i=0; i<5; i++)
        {
            allSkills+=mskill[i].skill;
        }
        // * 2?
        return beauty*2-badFeatures+allSkills+ badFeatures*3*pi;
    }


};
class Chalga:public Musician
{
private:
    bool race;
public:
    Chalga(bool race=true,char*name="",int beauty=1,int badFeatures=2): Musician(name,beauty,badFeatures)
    {

    }
    // - 0.2
    Chalga(const Chalga &other) // : Musician(other);
    {
        // Musician:: Musician(other);
        this->race=other.race;
    }
    Chalga &operator=(Chalga const&other)
    {

        if(this!=&other)
        {
            Musician:: operator=(other);
            this->race=other.race;
        }
        //...

    }
    virtual const char*getType()
    {
        return "rock_tack";
    }
    virtual int getBeauty()
    {
        int maxSkill=0;
        for(int i=0; i<5; i++)
        {
            if(mskill[i].skill>maxSkill)
            {
                maxSkill=mskill[i].skill;
            }
        }
        // * 5 ??
        // - 0.1
        return beauty*5+badFeatures+race*cos(maxSkill);

    }
};
class Group
{
private:
    char*groupName;
    Musician *musiciants[10];
public:
    Group();
    ~Group()
    {
        delete []groupName;
    }
    Group(const Group&other)
    {
        this->groupName=new char[strlen(other.groupName)+1];
        assert(this->groupName!=NULL);
        strcpy(this->groupName,other.groupName);
        for(int i=0; i<10; i++)
        {
            this->musiciants[i]=other.musiciants[i];
        }

    }
    Group &operator=(const Group &other)
    {
        if(this!=&other)
        {

            delete []groupName;
            this->groupName=new char[strlen(other.groupName)+1];
            assert(this->groupName!=NULL);
            strcpy(this->groupName,other.groupName);
            for(int i=0; i<10; i++)
            {
                this->musiciants[i]=other.musiciants[i];
            }


        }

        //....
    }
   virtual void addMusician()=0;
   virtual void removeMusician()=0;
};
class RockGroup:public Group
{
public:
    virtual void addMusician(Musician a)
    {
        // wut??
        // - 0.2
        musiciants[9]=a;
    }
    virtual void removeMusician(char*name)
    {
        for(int i=0;i<10;i++){
            // strcmp?
            // - 0.1
            if(musiciants[i].getName()==name)
            {
                for(int j=i+1;j<10;j++)
                {
                    musiciants[j-1]=musiciants[j];
                }
            }
        }
    }
};
using namespace std;
int main()
{

    return 0;
}
// - 1.9
// 3.3 