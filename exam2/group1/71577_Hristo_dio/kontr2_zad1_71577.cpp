//4te principa: Abstrakciq, Nasledqvane, Polymorfizam, Kapsulacia
#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
using namespace std;
class Musical_skill
{
private:
    char* name;
    int ability;
public:
    Musical_skill(char*name = "guitar", int ability=58)
    {
        this-> name = new char[strlen(name)+1];
        assert(this-name !=NULL);
		strcpy(this-> name, name);
		this -> ability = ability;
    }
    ~Musical_skill()
    {
        delete[] this-> name;
    }
    Msusical_skill(const Musical_skill& other)
    {
        this->name=new char[strlen(other.name)+1];
        assert(this->other.name != NULL);
        strcpy(this->other.name, name);
		this -> ability = other.ability;
	}
	Musical_skill &operator=(const Musical_skill &other)
	{
	    if(this != other)
        {
            delete []name;
            name=new char[strlen(other.name)+1];
            assert(name != NULL);
            strcpy(name, other.name);
            ability=other.ability;
        }
        return *this;
	}

	void setName(char* name)
	{
		delete [] this->name;
		this->name = new char[strlen(name)+1];
		assert(this->name != NULL);
		strcpy(this->name, strlen(name)+1, name);
	}
	char* getName() const
	{
		return name;
	}
	int getAbility() const
	{
	    return ability;
	}
	void setAbility(int ab)
	{
	    ability=ab;
	}
};
class Musician
{
private:
    char* name;
    int pretty;
    int bad_goods;
    Musical_skill skills[5];
    int size;
public:
    virtual char getType() const = 0;
    virtual int getPretty() const = 0;
    virtual int getAbility() const = 0;

    Musician (char* name= "Martin", int pretty=25, int bad_goods=11)

    {
        this->name=new char[strlen(name)+1];
        assert(this->name != NULL);
        strcpy(this->name, name);
        this->pretty=pretty;
        this->bad_goods=bad_goods;
    }
    ~Musician()
    {
        delete []name;
    }
    Musician (const Musician &other)
    {
        this->name=new char[strlen(other.name)+1];
        assert(this->other.name != NULL);
        strcpy(this->other.name, name);
        this->pretty=other.pretty;
        this->bad_goods=other.bad_goods;
    }
    Musician &operator= (const Musician &other)
    {
        if(this != ohter)
        {
            delete []name;
            name=new char[strlen(other.name)+1];
            assert(name != NULL);
            strcpy(name, other.name);
            pretty=other.pretty;
            bad_goods=other.bad_goods;
        }
        return *this;
    }
    char* getName() const
    {
        return name;
    }
    void setName(char* name)
    {
        delete [] this->name;
        this->name=new char[strlen(name)+1];
        assert(this->name!=NULL);
        strcpy(this->name, name);
    }

    void setPretty(int pr)
    {
        pretty=pr;
    }

    void setBad_goods(int bg)
    {
        bad_goods=bg;
    }
   /* Musical_skill getSkills () const
    {
        for(int i=0; i<5; i++)
        {
             int br;
        }
    }
    */


};

class Rock_musician : public Musician
{
public:
    Rock_musician() : Musician()
    virtual char getType() const
	{
		return 'rock';
	}
	virtual int getPritty()
	{
		if ((pretty> 0) && (size > 0) && (bad_goods> 0))
        {
			return pow(pretty, 2)+ size - bad_goods*3*3.14
		}
		return 0;
	}
	virtual int getAbility()
	{
	    return ability;
	}
	Rock_musician(char* name, int pretty, int ability) : Musician(char*name, int pretty, int ability)
	{

	}


}

};


class Cl_musician: public Musician
{
public:
    bool r_pr;
};
