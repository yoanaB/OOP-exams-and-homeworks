// Polimorfizum, Enkapsulaciq, Nasledqvane, Abstrakciq
#include<iostream>
#include<cstring>
#include <cassert>
#include <cmath>
using namespace std;

struct Musical_skill
{
private:
    char* name;
    int skill;
    void del ()
    {
        delete [] name;
    }
    void cpy (const Musical_skill& other)
    {
        name = new char [strlen(other.name) + 1];
        assert (name != NULL);
        strcpy (name, other.name);
        skill = other.skill;
    }
public:
    Musical_skill(const char* name = "", int skill = 0)
    {
        this->name = new char [strlen(name) + 1];
        assert (this->name != NULL);
        strcpy (this->name, name);
        this->skill = skill;
    }
    ~Musical_skill()
    {
        del();
    }
    Musical_skill (const Musical_skill& other)
    {
        cpy(other);
    }
    Musical_skill& operator = (const Musical_skill& other)
    {
        if (this != &other)
        {
            del();
            cpy(other);
        }
        return *this;
    }
    char* getName () const
    {
        return name;
    }
    int getSkill () const
    {
        return skill;
    }


};

class Muzikant
{
protected:
    char* name;
    int beauty;
    int poroci;
    Musical_skill* skills[5];
    int number;
protected:
    void delMuzikant ()
    {
        delete [] name;
        // nice :)
        for (int i = 0; i < number; i++)
        {
            delete [] (this->skills + i);
        }
    }
    void cpyMuzikant (const Muzikant& other)
    {
        name = new char [strlen(other.name) + 1];
        assert (name != NULL);
        strcpy (name, other.name);
        beauty = other.beauty;
        poroci = other.poroci;
        number = other.number;
        for (int i = 0; i < number; i++)
        {
            skills[i] = other.skills[i];
        }
    }
public:
    Muzikant (const char* name = "", int beauty = 0, int poroci = 0)
    {
        this->name = new char [strlen(name) + 1];
        assert (this->name != NULL);
        strcpy (this->name, name);
        this->beauty = beauty;
        this->poroci = poroci;
        number = 0;
    }
    virtual ~Muzikant ()
    {
        delMuzikant ();
    }
    Muzikant (const Muzikant& other)
    {
        cpyMuzikant (other);
    }
    Muzikant& operator = (const Muzikant& other)
    {
        if (this != &other)
        {
            delMuzikant();
            cpyMuzikant (other);
        }
        return *this;
    }
    virtual char* getName () const
    {
        return name;
    }
    void setName (char* name)
    {
        delete [] name;
        this->name = new char [strlen(name) + 1];
        assert (this->name != NULL);
        strcpy (this->name, name);
    }
    virtual int getBeauty () const
    {
        return beauty;
    }
    virtual int getPoroci () const
    {
        return poroci;
    }
    virtual char* getType () const = 0;
    virtual char** getSkills (int n) const = 0;
    int getSum () const
    {
        int sum = 0;
        for (int i = 0; i < number; i++)
        {
            sum += skills[i]->getSkill();
        }
        return sum;
    }


};

class Rock : public Muzikant
{
public:
    Rock (const char* name = "", int beauty = 0, int poroci = 0) : Muzikant (name, beauty, poroci)
    {
    }
    Rock (const Rock& other) : Muzikant (other)
    {
    }
    Rock& operator = (const Rock& other)
    {
        if (this != &other)
        {
            Muzikant :: operator = (other);
        }
        return *this;
    }

    virtual int getBeauty () const
    {
        // nope 
        // - 0.1
        int a = getSum();
        return ((2*getBeauty()) + a + 3*getPoroci());
    }
    virtual int getPoroci () const
    {
        return poroci;
    }
    virtual char* getType () const
    {
        return "rock";
    }

    virtual char** getSkills (int n) const
    {

    }
};

class Chalga : public Muzikant
{
private:
    bool prinadlejnost;
public:
    Chalga (const char* name = "", int beauty = 0, int poroci = 0, bool prinadlejnost = 0) : Muzikant (name, beauty, poroci)
    {
        this->prinadlejnost = prinadlejnost;
    }
    Chalga (const Chalga& other) : Muzikant (other)
    {
        prinadlejnost=other.prinadlejnost;
    }
    Chalga& operator = (const Chalga& other)
    {
        if (this != &other)
        {
            Muzikant :: operator = (other);
            prinadlejnost=other.prinadlejnost;
        }
        return *this;
    }

    virtual int getBeauty () const
    {
        int a = getSum();
        int maxskill = skills[0]->getSkill();
        for (int i = 0; i < number; i++)
        {
            if (maxskill < skills[i]->getSkill())
                maxskill = skills[i]->getSkill();
        }
        // nope 
        // - 0.1
        return ((5*getBeauty()) + getPoroci() + cos(maxskill) );
    }
    virtual int getPoroci () const
    {
        return poroci;
    }
    virtual char* getType () const
    {
        return "rock_tack";
    }
    // wow no....
    // - 0.1
    virtual char** getSkills (int n) const = 0;
};

class Group
{
protected:
    char* namegroup;
    Muzikant** muzikanti;
    int max_size;
    int real_size;
    void delGroup ()
    {
        delete [] namegroup;
        for (int i = 0; i < real_size; i++)
        {
            delete [] (this->muzikanti + i);
        }
        delete [] muzikanti;
    }
    void cpyGroup (const Group& other)
    {
        namegroup = new char [strlen(other.namegroup) + 1];
        assert (namegroup != NULL);
        strcpy (namegroup, other.namegroup);
        max_size = other.max_size;
        real_size = other.real_size;
        muzikanti = new Muzikant*[max_size];
        for (int i =0; i < real_size; i++)
        {
            muzikanti[i]=other.muzikanti[i];
        }
    }
public:
    Group (const char* namegroup = "")
    {
        this->namegroup = new char [strlen(namegroup) + 1];
        assert (this->namegroup != NULL);
        strcpy (this->namegroup, namegroup);
        this->real_size = 0;
        this->max_size = 20;
        this->muzikanti = new Muzikant* [max_size];
    }
    virtual ~Group ()
    {
        delGroup();
    }
    Group (const Group& other)
    {
       cpyGroup(other);
    }
    Group& operator = (const Group& other)
    {
        if (this != &other)
        {
            delGroup();
            cpyGroup(other);
        }
        return *this;
    }
    virtual bool add (Muzikant& other) = 0;
    virtual int avBeauty () = 0;
    virtual int ocenka () = 0;
    virtual bool removeM (char* name)
    {
        for (int i = 0; i < real_size; i++)
        {
            if (max_size > real_size*2)
            {
                max_size/=2;
                Muzikant** tmp = new Muzikant* [max_size];
                for (int i = 0; i < real_size; i++)
                {
                    tmp[i] = muzikanti[i];
                }
                for (int i = 0; i < real_size; i++)
                {
                    delete [] (this->muzikanti + i);
                }
                delete [] muzikanti;
                muzikanti = new Muzikant* [max_size];
                for (int i = 0; i < real_size; i++)
                {
                    muzikanti[i] = tmp[i];
                }
                for (int i = 0; i < real_size; i++)
                {
                    delete [] (tmp + i);
                }
                delete [] tmp;
            }
            if (!(strcmp(muzikanti[i]->getName(), name)))
            {
                for (int j = i; j < real_size; j++)
                {
                    muzikanti[j] = muzikanti [j+1];
                }
                real_size--;
                return true;
            }
        }
        return false;
    }


};

class ChalgaGroup : virtual public Group
{
public:
    ChalgaGroup (const char* namegroup = "") : Group (namegroup)
    {
    }
    ChalgaGroup (const ChalgaGroup& other) : Group (other)
    {
    }
    ChalgaGroup& operator = (const ChalgaGroup& other)
    {
        if (this != &other)
        {
            Group:: operator = (other);
        }
        return *this;
    }


    bool add(Muzikant& other)
    {/*
        bool flag = false;
        for (int i = 0; i < real_size; i++)
        {
            if (muzikanti[i]->getSkill() < 10)
            {
                flag = true;
                break;
            }
        }*/
            // - 0.1
        if ((!(strcmp("rock_tack", other.getType())))) //|| flag )
        {
            if (max_size == real_size)
            {
                max_size*=2;
                Muzikant** tmp = new Muzikant* [max_size];
                for (int i = 0; i < real_size; i++)
                {
                    tmp[i] = muzikanti[i];
                }
                for (int i = 0; i < real_size; i++)
                {
                    delete [] (this->muzikanti + i);
                }
                delete [] muzikanti;
                muzikanti = new Muzikant* [max_size];
                for (int i = 0; i < real_size; i++)
                {
                    muzikanti[i] = tmp[i];
                }
                for (int i = 0; i < real_size; i++)
                {
                    delete [] (tmp + i);
                }
                delete [] tmp;
            }
            muzikanti[real_size] = &other;
            real_size++;
            return true;
        }
        else
            return false;
    }

    int avBeauty ()
    {
        int result = 0;
        for (int i = 0; i < real_size; i++)
        {
            result += muzikanti[i]->getBeauty();
        }
        // average??
        return result;
    }

    int ocenka ()
    {
        int result = 0;
        for (int i = 0; i < real_size; i++)
        {
            result += muzikanti[i]->getSum();
        }
        int result1 = 0;
        for (int i = 0; i < real_size; i++)
        {
            result1 += muzikanti[i]->getBeauty();
        }
        return result + result1;
    }

};

class RockGroup : virtual public Group
{
public:
    RockGroup (const char* namegroup = "") : Group (namegroup)
    {
    }
    RockGroup (const RockGroup& other) : Group (other)
    {
    }
    RockGroup& operator = (const RockGroup& other)
    {
        if (this != &other)
        {
            Group:: operator = (other);
        }
        return *this;
    }

    bool add(Muzikant& other)
    {
        /*bool flag = false;
        for (int i = 0; i < real_size; i++)
        {
            if (muzikanti[i]->getSkill() > 100)
            {
                flag = true;
                break;
            }
        }*/
        if (!(strcmp("rock", other.getType())))
        {
            if (max_size == real_size)
            {
                max_size*=2;
                Muzikant** tmp = new Muzikant* [max_size];
                for (int i = 0; i < real_size; i++)
                {
                    tmp[i] = muzikanti[i];
                }
                for (int i = 0; i < real_size; i++)
                {
                    delete [] (this->muzikanti + i);
                }
                delete [] muzikanti;
                muzikanti = new Muzikant* [max_size];
                for (int i = 0; i < real_size; i++)
                {
                    muzikanti[i] = tmp[i];
                }
                for (int i = 0; i < real_size; i++)
                {
                    delete [] (tmp + i);
                }
                delete [] tmp;
            }
            muzikanti[real_size] = &other;
            real_size++;
            return true;
        }
        else
            return false;
    }
    int avBeauty ()
    {
        int result = 0;
        for (int i = 0; i < real_size; i++)
        {
            result += muzikanti[i]->getBeauty();
        }
        return result;
    }
    int ocenka ()
    {
        int result = 0;
        for (int i = 0; i < real_size; i++)
        {
            result += muzikanti[i]->getSum();
        }
        int result1 = 0;
        for (int i = 0; i < real_size; i++)
        {
            result1 += muzikanti[i]->getPoroci();
        }
        return result - result1;
    }
};

class AllGroup : public ChalgaGroup, public RockGroup
{
public:
    AllGroup (const char* namegroup = "", const char* namegroup1 = "", const char* namegroup2 = "") : Group (namegroup), ChalgaGroup (namegroup1), RockGroup (namegroup2)
    {
    }
    AllGroup (const AllGroup& other) : Group (other), ChalgaGroup (other), RockGroup (other)
    {
    }
    AllGroup& operator= (const AllGroup& other)
    {
        if (this!= &other)
        {
            ChalgaGroup :: operator = (other);
            RockGroup :: operator = (other);
        }
        return *this;
    }
    bool add (Muzikant& other)
    {
        return ChalgaGroup::add(other) || RockGroup::add(other);
    }
    virtual int avBeauty ()
    {
        // not averate 
        // - 0.1
        return ChalgaGroup::avBeauty() + RockGroup::avBeauty();
    }
    virtual int ocenka ()
    {
        return ChalgaGroup::ocenka() + RockGroup::ocenka();
    }
};

int main ()
{
    return 0;
}
// 5.5 