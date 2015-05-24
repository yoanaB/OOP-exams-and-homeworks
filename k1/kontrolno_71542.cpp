// Abstraction ,  Encapsulation , Inheritance , Polymorphism

#include<iostream>
#include<cstring>
#include<cassert>
using namespace std ;

class Programmer
{
private:
    char *name ;
    int IQ ;
    double salary ;

    void init(char *name, int IQ , double salary)
    {
        this->name = new char[strlen(name)+1] ;
        assert(this->name != NULL) ;
        strcpy(this->name,name) ;
        this->IQ=IQ;
        this->salary=salary ;
    }

public:
        Programmer()
        {
            init("no name" , 0 , 0 ) ;
        }

        Programmer(const Programmer &other)
        {
            init(other.name, other.IQ , other.salary) ;
        }

        Programmer operator= (const Programmer & other)
        {
            if(this != NULL)
            {
                delete[] this->name ;
                init(other.name, other.IQ , other.salary) ;
            }
            return *this ;
        }

       ~Programmer()
       {
           delete[] this->name ;
       }


        void printProgrammer()
        {
            cout << "name: " << name << endl ;
            cout << "IQ :" << IQ << endl ;
            cout << "salary :" << salary << endl ;
        }

        void readProgrammer()
        {
            char name[20] ;
            int IQ ;
            double salary ;
            cout << "name: " ;
            cin.ignore() ;
            cin.getline(name,20) ;
            cout << "IQ : "  ;
            cin>> IQ ;
            cout << "salary :" ;
            cin>> salary ;
            delete[] this->name ;
            init(name,IQ,salary) ;
        }

        void setName(char* name)
        {
            this->name = new char[strlen(name) + 1] ;
            assert(this->name != NULL) ;
            strcpy(this->name,name) ;
        }

        char* getName() const
        {
            return name ;
        }

        void setIQ(int IQ)
        {
            this->IQ = IQ ;
        }

        int getIQ() const
        {
            return IQ ;
        }

        void setSalary(double salary)
        {
            this->salary = salary ;
        }

        double getSalary() const
        {
            return salary ;
        }


        bool operator > (const Programmer &other)
        {
            return this->IQ > other.IQ ;
        }

        bool operator < (const Programmer &other)
        {
            return this->IQ < other.IQ ;
        }


        bool operator == (const Programmer &other)
        {
            return this->IQ == other.IQ ;
        }

};


class Team

{

private:

    unsigned max_ ;
    unsigned current ;
    Programmer *hakers;


public:

    Team(unsigned max_=1, unsigned current=0 , Programmer *hakers=new Programmer[0])
    {
        this->max_=max_ ;
        this->current=current ;
        this->hakers=hakers ;
    }

    ~Team()
    {
        delete[] hakers ;
    }



    Programmer getProgrammer(char* name)
    {
        for (int i=0 ; i< current ; i++)
        {
            if( ! strcmp(hakers[i].getName(), name) )
            {
              return hakers[i] ;
            }
        }
    }


    void addProgrammer(Programmer &other)
    {
        if(current=max_)
        {
            Team *temp= new Team[current] ;
            assert[(temp != Null) ;
            for(int i=0 ; i<current ; i++)
            {
                temp[i]=hakers[i] ;
            }
            delete[] hakers ;
            max_*=2 ;
            hakers=new Team[max_] ;
            for(int i=0 ; i< current ; i++)
            {
                hakers[i] = temp[i] ;
            }
            delete[] temp ;
        }
        current = current + 1 ;
        hakers[current] = other ;
    }



    void removeProgrammers(char* name)
    {
        if(max_ > (current * 2) )
        {
            Team *temp = new Team[current] ;
            for(int i=0 ; i< current ; i++)
            {
                temp[i]=hakers[i] ;
            }
            delete[] hakers ;
            max_=max_ / 2 ;
            Team = new Team[max_] ;
            for(int i= 0; i<current ; i++)
            {
                hakers[i] = temp[i] ;
            }
        }
         for(int i=0 ; i< current ; i++)
    {
         if( ! strcmp(hakers[i].getName(), name) )
            {
                for(int j=i+1 ; j< current ; j++)
                {
                    hakers[j--]=hakers[j] ;
                }
                current = current-1 ;
                break ;
            }
    }

    }


     Programmer getProgrammer(char* name)
    {
        for (int i=0 ; i< current ; i++)
        {
            if( ! strcmp(hakers[i].getName(), name) )
            {
                hakers[i].print() ;
            }
        }
    }

};



int main()
{

    Programmer Harry ;
    Harry.printProgrammer() ;
    Harry.readProgrammer() ;


    return 0 ;
}
