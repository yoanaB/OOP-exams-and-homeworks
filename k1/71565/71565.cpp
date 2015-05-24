// 1.Abstraction
// 2.Encapsulation
// 3.Inheritance
//4.Polymorphism
#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;
class Programmer
{
private:
    char*name;
    int iq;
    double salary;
public:
    Programmer(char*name="",int iq=0,double salary=0)
    {
        this->name=new char[strlen(name)+1];
        assert(this->name!=NULL);
        strcpy(this->name,name);
        this->iq=iq;
        this->salary=salary;
    }
    ~Programmer()
    {
        delete []name;
    }
    Programmer(const Programmer &other)
    {
        this->name=new char[strlen(other.name)+1];
        assert(this->name!=NULL);
        strcpy(this->name,other.name);
        this->iq=other.iq;
        this->salary=other.salary;
    }
    Programmer &operator=(const Programmer &other)
    {
        if(this!=&other)
        {
            delete []name;
            this->name=new char[strlen(other.name)+1];
            assert(this->name!=NULL);
            strcpy(this->name,other.name);
            this->iq=other.iq;
            this->salary=other.salary;
        }
        return *this;
    }
    void setIQ(int iq)
    {
        this->iq=iq;
    }
    void setSalary(double salary)
    {
        this->salary=salary;
    }
    void setName(char*name)
    {
        this->name=new char[strlen(name)+1];
        assert(this->name!=NULL);
        strcpy(this->name,name);
    }
    int getIQ() const
    {
        return iq;
    }
    double getSalary() const
    {
        return salary;
    }
    char* getName() const
    {
        return name;
    }
    void print()
    {
        cout<<getName();
        cout<<getIQ()<<endl;
        cout<<getSalary()<<endl;
    }
    bool operator<(const Programmer &other)
    {
        return this->iq < other.iq;
    }
    bool operator>(const Programmer &other)
    {
        return this->iq > other.iq;
    }
    bool operator==(const Programmer &other)
    {
        return this->iq == other.iq;
    }
};
class Team
{
private:
    Programmer* programists;
    int size;
    int maxSize;
public:
    Team(int size=0,int maxSize=1)
    {
        this->size=size;
        this->maxSize=maxSize;
        programists=new Programmer[size];
        assert(programists!=NULL);
    }
    ~Team()
    {
        delete []programists;
    }
    Team(const Team &other)
    {
        this->size=other.size;
        this->maxSize=other.maxSize;
        this->programists=new Programmer[other.size];
        assert(programists!=NULL);
        for(int i=0; i<size; i++)
        {
            programists[i]=other.programists[i];
        }

    }
    Team &operator=(Team &other)
    {
        delete []programists;
        this->size=other.size;
        this->maxSize=other.maxSize;
        this->programists=new Programmer[other.size];
        assert(programists!=NULL);
        for(int i=0; i<size; i++)
        {
            programists[i]=other.programists[i];
        }
    }
    void printALL()
    {
        for(int i=0; i<size; i++)
        {
            programists[i].print();
        }
    }
    void removeProgrammer(char*name)
    {
        for(int i=0; i<size; i++)
        {
            if(programists[i].getName()==name)
            {
                swap(programists[i],programists[size-1]);
                for(int j=i+1; j<size; j++)
                {
                    programists[j-1]=programists[j];

                }
                size--;
            }
        }
    }
    Programmer getProgrammer(char*name) const
    {
        for(int i=0; i<size; i++)
        {
            if(programists[i].getName()==name)
                return programists[i];
        }
    }
    void addProgrammer(Programmer a)
    {
        int counter=0;
        if(size=maxSize)
        {
            Programmer* oldProgramists=programists;
            delete[]programists;
            programists=new Programmer[size*2];
            for(int i=0; i<size; i++)
            {
                counter++;
                programists[i]=oldProgramists[i];
            }
        }
        programists[counter+1]=a;
    }
    Team &operator-=(Team &other)
    {
        for(int i=0; i<size; i++)
        {
            if(this->programists[i]==other.programists[i])
                removeProgrammer(this->programists[i].getName());
        }
    }
    void sortTeam()
    {
        for(int i=0; i<size; i++)
        {
            int max=i;
            for(int j=i+1; j,size; j++)
            {
                if(programists[j].getIQ() < programists[i].getIQ())
                    max=j;
            }
            if(i!=max)
                swap(programists[i],programists[max]);
        }
    }
    double averageTeamIQ()
    {
        int sum=0,counter=0;
        for(int i=0; i<size; i++)
        {
            counter++;
            sum+=programists[i].getIQ();
        }
        return sum/counter;
    }
};
class Company
{
private:
    Team* teams;
    int size;
    int maxSize;
public:
    Company(int size=0,int maxSize=1)
    {
        this->size=size;
        this->maxSize=maxSize;
        teams=new Team[size];
        assert(teams!=NULL);
    }
    ~Company()
    {
        delete []teams;
    }
    Company(const Company &other)
    {
        this->size=other.size;
        this->maxSize=other.maxSize;
        teams=new Team[other.size];
        assert(teams!=NULL);
        for(int i=0; i<size; i++)
        {
            this->teams[i]=other.teams[i];
        }
    }
    Company &operator=(const Company &other)
    {
        delete []teams;
        this->size=other.size;
        this->maxSize=other.maxSize;
        teams=new Team[other.size];
        assert(teams!=NULL);
        for(int i=0; i<size; i++)
        {
            this->teams[i]=other.teams[i];
        }
    }
    double averageIQ()
    {
        int sum=0,counter=0;
        for(int i=0; i<size; i++)
        {
            counter++;
            sum+=teams[i].averageTeamIQ();
        }
        return sum/counter;
    }
    void printCompany()
    {
        for(int i=0; i<size; i++)
        {
            teams[i].printALL();
        }
    }

};
int main()
{
    return 0;
}
