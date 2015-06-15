//абстракция,капсулация,полиморфизъм,наследяване
#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>

using namespace std;

struct Musical_skill
{
private:
    char* name;
    int skill;
    int Sum;
public:
    Musical_skill(char* name = "", int skill = 0)
    {
        setName(name);
        setSkill(skill);
    }
    Musical_skill(const Musical_skill &other)
    {
        setName(other.name);
        setSkill(other.skill);
    }
    ~Musical_skill()
    {
        delete[] name;
    }
    Musical_skill &operator=(const Musical_skill &other)
    {
        if(this != &other)
        {
            delete[]name;
            setName(other.name);
            setSkill(other.skill);
        }
        return *this;
    }
    void setName(char* name)
    {
        this -> name = new char[strlen(name) + 1];
        assert(this -> name != NULL);
        strcpy(this -> name, name);
    }
    char* getName() const
    {
        return name;
    }
    void setSkill(int skill)
    {
        this -> skill = skill;
    }
    int getSkill() const
    {
        return skill;
    }
    virtual int Sum() //?
    {
        for(int i = 0; i < skill; i++)
            Sum = skill[0] + skill[i];
    }
};
//inheritance?
class Мusician : virtual public Musical_skill
{
private:
    char* name;
    int beauty;
    int porok;
    Musical_skill m_skill[5];
    int size;
public:
    Musician(char* name = "", int skill = 0, int beauty = 0, int porok = 0, size = 0) : Muzikal_skill(name, skill, Sum) //sum?
    { //musical skill and musician has the same name?
        setName(name);
        this -> beauty = beauty;
        this -> porok = porok;
    }
    Musician (const Musician &other)
    {
        setName(other.name);
        this -> beauty = other.beauty;
        this -> porok = other.porok;
	//musical skills?

    }
    Musician &operator=(const Musician &other)
    {
        if(this != &other)
        {
            delete[]name;
            setName(other.getName());
            this -> beauty = other.beauty;
            this -> porok = other.porok;
        }
        return *this;
    }
    ~Musician()
    {
        delete[] name;
    }
    void setName(char* name)
    {
        this -> name = new char[strlen(name) + 1];
        assert(this -> name != NULL);
        strcpy(this -> name, name);
    }
    char* getName() const
    {
        return name;
    }
    virtual int getBeauty() const
    {
        return beauty;
    }
    virtual int getPorok() const
    {
        return porok;
    }
    virtual int Sum1()
    {
        for(int i = 0; i < size; i++)
        { //?
            Sum1 = porok[0] + porok[i];
        }
    }
    virtual int SumBeauty()
    {
        for(int i = 0; i < size; i++)
        {
            SumBeauty = porok[0] + porok[i];
        }
    }
    virtual char getType();
};
class Rok_musician : virtual public Musician //virtual?
{
public:
    Rok_musician(char* name = "", int skill = 0, int beauty = 0, int porok = 0, m_skill = "") : Musician(name, beauty, porok,m_skill)
    {

    }

    virtual int getBeauty() const
    {// return? pi?
        beauty*2 + Sum(skill) - porok*3,14;
    }
    virtual int getPorok() const
    {
        return porok;
    }
    virtual void getType()
    {
        return 'Rok_m';
    }

};
class Chalga_musician : virtual public Musician
{
private:
    bool race;
public:
    Chalga_musician(char* name = "", int skill = 0, int beauty = 0, int porok = 0, m_skill = "", bool race = 0) : Musician(name, beauty, porok, m_skill)
    {

    }
    virtual char getType()
    {
        return 'Chalga_m';
    }
    virtual int getBeauty() const
    {
        return getBeauty()*5 + getPorok() + race + cos(skill);
    }
    virtual int getPorok() const
    {
        return porok;
    }
};
//inheritance?
class Group : virtual public Musician
{
private:
    char* name;
    Musician m[10];
    int size;
public:
    Group(char* name = "", int beauty = 0, int porok = 0, m_skill = "", char* name = "", m = "", int size = 0) : Musician(name, beauty, porok, m_skill)
    {
        setName(name);
        this -> size = size;
        this -> m[10] = 0;+
    }
    ~Group()
    {
        delete[]name;
    }
    void setName(char* name)
    {
        this -> name = new char[strlen(name) + 1];
        assert(this -> name != NULL);
        strcpy(this -> name, name);
    }
    char* getName() const
    {
        return name;
    }
    bool add(Musician &other)
	 {
	     if(size == 0)
         {
             Musician[size] = other;
             size++;
             return true;
         }
         else
             {
                if(Musician[size - 1].getType() == other.getType && size <= 19)
                    {
                        Musician[size] == other.getType();
                        size++;
                        return true;
                    }
                    else
                        return false;
            }
	 }
    bool remove(char* name)
	 {
	     Team temp[20];
	     for(size_t i = 0; i < size; i++)
         {
             temp[i] = musicians[i];
         }
         delete[] musicians;
	     for(size_t i = 0; i < size; i++)
         {
             if(strcmp(musicians[i],name)==0)
             {
                 for(size_t j = i + 1, j < length; j++)
                 {
                     temp[j-1] = temp[j];
                 }
                 break;
             }
         }
         size--;
         musicians = new Team[size];
         for(size_t i = 0; i < size; i++)
         {
             musicians[i] = temp[i];
         }
	 }
};
class Rok_group : virtual public Group
{
private:
    int size;
public:
    bool add(Muscian &other)
    {
        if(getType() = 'Rock_m' || getSkill() > 100)
	//add?
            return true;
        else
            return false;
    }
    virtual int getBeauty()
    {
        for(int i = 0; i < size; i++)
        {
            (beauty[0] + beauty[i])/size;
        }
    }
    virtual int Ocenka()
    {
        return Sum() - Sum1();
    }
};
class Chalga_group : virtual public Group
{
public:
    bool add(Muscian &other)
    {
        if(getType() = 'Chalga_m' || getSkill() < 10)
            return true;
        else
            return false;
    }
    virtual int getBeauty()
    {
        for(int i = 0; i < size; i++)
        { // return?
            (beauty[0] + beauty[i])/size;
        }
    }
    virtual int Ocenka()
    {
        return Sum() + SumBeauty();
    }
};
class Rok_Chalga_Group :  public Rok_group, public Chalga_group, public Musician // musician??
{
private:
    int size;
public:
     bool add(Muscian &other)
    {
        if(getType() = 'Chalga_m' || getType() = 'Rok_m')
           // add?
		 return true;
        else
            return false;
    }
    virtual int getBeauty()
    {
        for(int i = 0; i < size; i++)
        {
            (beauty[0] + beauty[i])/size;
        }
    }
    virtual int Ocenka()
    {
        return Sum() + SumBeauty();
    }
    virtual int Ocenka()
    {

    }

};
int main()
{

}
