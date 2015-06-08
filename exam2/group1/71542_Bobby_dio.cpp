//Abstrtaction , Encapsulation , Polymorphisum , Inheritance
// :)

#include<iostream>
#include<cassert>
#include<cstring>
using namespace std ;

class Musical_skill
{
private:
    char*name ;
    int skill ;
public:
    Musical_skill(char*name="",int skill=0)
    {
        this->name=new char[strlen(name)+1] ;
        assert(this->name!=NULL)
        strcpy(this->name,name) ;
        this->skill=skill ;
    }
    ~Musical_skill()
    {
        delete[] this->name ;
    }
    Musical_skill(const Musical_skill&other)
    {
        this->name=new char[strlen(other.name)+1] ;
        assert(this->name!=NULL)
        strcpy(this->name,other.name) ;
        this->skill=other.skill ;
    }
   Musical_skill &operator=(const Musical_skill&other)
   {
       if(this!=&other)
       {
           delete[] this->name;
           this->name=new char[strlen(other.name)+1] ;
            assert(this->name!=NULL)
            strcpy(this->name,other.name) ;
            this->skill=other.skill ;
       }
       return *this ;
   }

};

class Musician
{
private:
    char*name ;
    int beuaty ;
    int vice ;
    Musical_skill*musical_skills[5] ;
   int numberOfMusicalSkills ;
public:
    Musician (char*name="",int beauty=0,int vice=0)
    {
        this->name=new char[strlen(name)+1] ;
        assert(this->name!=NULL)
        strcpy(this->name,name) ;
        this->beauty=beauty;
        this->vice=vice ;
        this->numberOfMusicalSkills=0;
    }
    ~Musician()
    {
        delete[] this->name ;
        for(int i=0; i<numberOfMusicalSkills ; i++)
        {
            delete[] this->musical_skills[i] ;
        }
    }
    Musician(const Musician&other)
    {
        this->name=new char[strlen(other.name)+1] ;
        assert(this->name!=NULL)
        strcpy(this->name,other.name) ;
        this->beauty=other.beauty;
        this->vice=other.vice ;
        this->numberOfMusicalSkills=other.numberOfMusicalSkills ;
        for(int i=0 ; i<5 ; i++)
        {
            this->musical_skills[i]= other.musical_skills[i] ;
        }
    }
    Musician &operator=(const Musician&other)
    {
        if(this!=&other)
        {
            delete[] this->name ;
            for(int i=0; i<numberOfMusicalSkills ; i++)
            {
                delete[] this->musical_skills[i] ;
            }
            this->name=new char[strlen(other.name)+1] ;
            assert(this->name!=NULL)
            strcpy(this->name,other.name) ;
            this->beauty=other.beauty;
            this->vice=other.vice ;
            for(int i=0 ; i<5 ; i++)
            {
                this->musical_skills[i]= other.musical_skills[i] ;
            }
        }
        return *this ;
    }

    virtual void setName() = 0 ;
    const char*getName()
    {
        return name ;
    }
    virtual int getBeauty() = 0 ;
    virtual int getVice() = 0 ;
    virtual int getType() = 0 ;
    virtual Musical_skill getStrongest() = 0;

};

class RockMusician : virtual public Musician
{
public:
    RockMusician(char*name="",int beauty=0,int vice=0 ) : Musician(name,beauty,vice)
    {
        // noo need of this code one more time:
        // - 0.2
        this->name=new char[strlen(name)+1] ;
        assert(this->name!=NULL)
        strcpy(this->name,name) ;
        this->beauty=beauty;
        this->vice=vice ;
    }
    ~RockMusician()
    {
        delete[] this->name ;
    }
    RockMusician(const RockMusician&other) : Musician(other)
    {
        // same....
        // - 0.1
        this->name=new char[strlen(other.name)+1] ;
        assert(this->name!=NULL)
        strcpy(this->name,other.name) ;
        this->beauty=other.beauty;
        this->vice=other.vice ;
    }
    RockMusician &operator=(const RockMusician&other)
    {
        if(this!=&other)
        {
            delete[] this->name ;
            Musician::operator=(other)
            // .....
            ///..........
            this->name=new char[strlen(other.name)+1] ;
            assert(this->name!=NULL)
            strcpy(this->name,other.name) ;
            this->beauty=other.beauty;
            this->vice=other.vice ;

        }
        return *this ;
    }



    virtual int getTyoe()
    {
        return "rock" ;
    }

    virtual getVice()
    {
        return vice ;
    }

    virtual int getBeauty()
    {
        // 3.14 ... really?
        // - 0.1
        return (beauty()*2-vice * 3 * 3.14) ;
    }

};


class ChalgaMusician() : virtual public Musician
{
public:
    ChalgaMusician(char*name="",int beauty=0,int vice=0 ) : Musician(name,beauty,vice)
    {
        /// .... 
        //  - 0.2
        this->name=new char[strlen(name)+1] ;
        assert(this->name!=NULL)
        strcpy(this->name,name) ;
        this->beauty=beauty;
        this->vice=vice ;
    }
    ~ChalgaMusician()
    {
        delete[] this->name ;
    }
    ChalgaMusician(const ChalgaMusician&other) : Musician(other)
    {
        //...
        // - 0.1 
        this->name=new char[strlen(other.name)+1] ;
        assert(this->name!=NULL)
        strcpy(this->name,other.name) ;
        this->beauty=other.beauty;
        this->vice=other.vice ;
    }
    ChalgaMusician &operator=(const ChalgaMusician&other)
    {
        if(this!=&other)
        {
            //...
            delete[] this->name ;
            Musician::operator=(other)
            this->name=new char[strlen(other.name)+1] ;
            assert(this->name!=NULL)
            strcpy(this->name,other.name) ;
            this->beauty=other.beauty;
            this->vice=other.vice ;

        }
        return *this ;
    }


     virtual int getTyoe()
    {
        return "rock_tack" ;
    }
    virtual getVice()
    {
        return vice ;
    }

     virtual int getBeauty()
    {
        return (beauty()*5+vice) ;
    }

};







class Group
{
private:
    char*name ;
    Musician*musicians[10] ;
    int numberOfMusicians ;
public:
    Group(char*name="")
    {
        this->name=new char[strlen(name)+1] ;
        assrt(this->name!=NULL) ;
        strcpy(this->name,name) ;
        this->numberOfMusicians = 0 ;
    }
    ~Group()
    {
        delete[] this->name ;
        for(int i=0 ; i<numberOfMusicians ; i++)
        {
            delete[] this->musicians[i] ;
        }
    }
    Group(const Group&other)
    {
        this->name=new char[strlen(other.name)+1] ;
        assrt(this->name!=NULL) ;
        strcpy(this->name,other.name) ;
        this->numberOfMusicians = other.numberOfMusicians ;
        for(int i=0; i<10 ; i++)
        {
            this->musicians[i]=other.musicians[i] ;
        }
    }
    Group &operator=(const Group&other)
    {
        if(this!=&other)
        {
            delete[] this->name ;
            for(int i=0 ; i<numberOfMusicians ; i++)
            {
                delete[] this->musicians[i] ;
            }
            this->name=new char[strlen(other.name)+1] ;
            assrt(this->name!=NULL) ;
            strcpy(this->name,other.name) ;
            this->numberOfMusicians = other.numberOfMusicians ;
            for(int i=0; i<10 ; i++)
            {
                this->musicians[i]=other.musicians[i] ;
            }

        }
        return *this ;
    }

    virtual bool addMusician(char*musicians)
    {
        if(numberOfMusicians<10)
        {
            this->musicians[numberOfMusicians] = musicians ;
            numberOfMusicians++ ;
            return true ;
        }
        else return  false ;
    }

    virtual void removeMusician(char*musicians)
    {
        for(int i=0 ; i<numberOfMusicians ; ++i)
        {
            // strcmp??  
            // - 0.2
            if(musicians[i].getName() == name)
            {
                delete[] musicians[i] ;
                for(int j=i+1 ; i<numberOfMusicians ; ++j)
                {
                    musicins[j-1] = musicians[j] ;
                }
                --numberOfMusicians ;
                return  ;
            }
        }
    }


};


class RockGroup : virtual public Group
{
public:
    RockGroup(char name="") : Group(name)
    {

    }

     RockGroup(const RockGroup&other) : Group(other)
    {
        // come on..
        // - 0.1
        this->name=new char[strlen(other.name)+1] ;
        assrt(this->name!=NULL) ;
        strcpy(this->name,other.name) ;

    }
    RockGroup &operator=(const Group&other)
    {
        if(this!=&other)
        {
            delete[] this->name ;
            //....
            Group::operator=(other) ;
            this->name=new char[strlen(other.name)+1] ;
            assrt(this->name!=NULL) ;
            strcpy(this->name,other.name) ;
        }
        return *this ;
    }

    //Musician* ...
    // - 0.2
    bool addRockMusician(Musician m)
    {
        if(m.getType== "rock")
        {
            musicians[numberOfMusicians] = m ;
            numberOfMusicians++ ;
            return true ;
        }
        else return false ;
    }
    // copy paste
    // but why??
    // - 0.1
    virtual void removeMusician(char*musicians)
    {
        for(int i=0 ; i<numberOfMusicians ; ++i)
        {
            if(musicians[i].getName() == name)
            {
                delete[] musicians[i] ;
                for(int j=i+1 ; i<numberOfMusicians ; ++j)
                {
                    musicins[j-1] = musicians[j] ;
                }
                --numberOfMusicians ;
                return  ;
            }
        }
    }

};


class ChalgaGroup : virtual public Group
{
public:
    ChalgaGroup(char name="") : Group(name)
    {

    }


     ChalgaGroup(const ChalgaGroup&other) : Group(other)
    {
        // o come ooon
        this->name=new char[strlen(other.name)+1] ;
        assrt(this->name!=NULL) ;
        strcpy(this->name,other.name) ;

    }
    ChalgaGroup &operator=(const Group&other)
    {
        // ... 
        if(this!=&other)
        {
            delete[] this->name ;
            Group::operator=(other) ;
            this->name=new char[strlen(other.name)+1] ;
            assrt(this->name!=NULL) ;
            strcpy(this->name,other.name) ;
        }
        return *this ;
    }
    //......
    // .... 
     bool addChalgaMusician(Musician m)
    {
        if(m.getType== "rock_tack")
        {
            musicians[numberOfMusicians] = m ;
            numberOfMusicians++ ;
            return true ;
        }
        else return false ;
    }


    virtual void removeMusician(char*musicians)
    {
        for(int i=0 ; i<numberOfMusicians ; ++i)
        {
            if(musicians[i].getName() == name)
            {
                delete[] musicians[i] ;
                for(int j=i+1 ; i<numberOfMusicians ; ++j)
                {
                    musicins[j-1] = musicians[j] ;
                }
                --numberOfMusicians ;
                return  ;
            }
        }
    }


};


class RockChalgaGroup : public RockGroup , public ChalgaGroup
{
    RockChalgaGroup(char*name="") : Group(name) , RockGroup(name) , ChalgaGroup(name)
    {

    }

    //wtfff?? :D 
    // oh god...
    // - 0.2 
    virtual bool addRockOrChalgaMusician()
    {

        if(addRockMusician(Musician m) == true)
            {
                return true ;
            }

    if(addChalgaMusician(Musician m) == true)
            {
                return true ;
            }
            else return false ;

    }




    // goood copy paste agaaain...
    virtual void removeMusician(char*musicians)
    {
        for(int i=0 ; i<numberOfMusicians ; ++i)
        {
            if(musicians[i].getName() == name)
            {
                delete[] musicians[i] ;
                for(int j=i+1 ; i<numberOfMusicians ; ++j)
                {
                    musicins[j-1] = musicians[j] ;
                }
                --numberOfMusicians ;
                return  ;
            }
        }
    }


};


int main()
{


    return 0;

}
// some stuffs missing 
// - 1.1
// 3.4