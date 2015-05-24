//Abstrakciq
//Nasledqvane
//Enkapsulirane
//Polimorfizum

#include <iostream>
#include <cassert>
#include <cstring>

using namespace std;

class Programmer
{
private:
    char* name;
    int IQ;
    double salary;
    void copy(const Programmer& other)
    {
        name = new char[strlen(other.name)+1];
        assert(name!=NULL);
        strcpy(name,other.name);
        IQ = other.IQ;
        salary = other.salary;
    }
    void del()
    {
        delete [] name;
    }
public:
    Programmer(char* n = "",int iq = 0,double s = 0)
    {
        name = new char[strlen(n)+1];
        assert(name!=NULL);
        strcpy(name,n);
        this->IQ = iq;
        salary = s;
    }
    ~Programmer()
    {
        del();
    }
    Programmer(const Programmer& other)
    {
        copy(other);
    }
    Programmer& operator=(const Programmer& other)
    {
        if(this!=&other)
        {
            del();
            copy(other);
        }
        return *this;
    }
    void setName(char* n)
    {
        del();
        name = new char[strlen(n)+1];
        assert(name!=NULL);
        strcpy(name,n);
    }
    char* getName() const
    {
        return name;
    }
    void setIQ(int iq)
    {
        this->IQ = iq;
    }
    int getIQ() const
    {
        return IQ;
    }
    void setSalary(double s)
    {
        salary = s;
    }
    double getSalary() const
    {
        return salary;
    }
    void print() const
    {
        cout<<"Name: "<<name<<"  IQ: "<<IQ<<"  Salary: "<<salary;
        cout<<endl;
    }
    bool operator<(const Programmer& other)
    {
        return this->IQ < other.IQ;
    }
    bool operator>(const Programmer& other)
    {
        return this->IQ > other.IQ;
    }
    bool operator==(const Programmer& other)
    {
        return this->IQ == other.IQ;
    }
};

class Team
{
private:
    char* name;
    Programmer* team;
    int size;
    int capacity;
    void copy(const Team& other)
    {
        name = new char[strlen(other.name)+1];
        assert(name!=NULL);
        strcpy(name,other.name);
        size = other.size;
        capacity = other.capacity;
        team = new Programmer[capacity];
        assert(team!=NULL);
        for(int i=0;i<size;i++)
        {
            team[i] = other.team[i];
        }
    }
    void del()
    {
        delete [] name;
        delete [] team;
    }
public:
    Team(char* n = "")
    {
        name = new char[strlen(n)+1];
        assert(name!=NULL);
        strcpy(name,n);
        size = 0;
        capacity = 1;
        team = new Programmer[capacity];
        assert(team!=NULL);
    }
    ~Team()
    {
        del();
    }
    Team(const Team& other)
    {
        copy(other);
    }
    Team& operator=(const Team& other)
    {
        if(this != &other)
        {
            del();
            copy(other);
        }
        return *this;
    }
    void addProgrammer(char* n,int iq, double s)
    {
        if(size == capacity)
        {
            // could do with only one new :)
            Programmer* tmp = new Programmer[capacity];
            assert(tmp!=NULL);
            for(int i=0;i<size;i++)
            {
                tmp[i] = team[i];
            }
            delete [] team;
            capacity *= 2;
            team = new Programmer[capacity];
            assert(team!=NULL);
            for(int i=0;i<size;i++)
            {
                team[i] = tmp[i];
            }
            delete [] tmp;
        }
        Programmer p(n,iq,s);
        team[size] = p;
        size++;
        sort();
    }
    // function with the main functionality could be usefull here
    void addProgrammer(Programmer& p)
    {
        if(size == capacity)
        {
            Programmer* tmp = new Programmer[capacity];
            assert(tmp!=NULL);
            for(int i=0;i<size;i++)
            {
                tmp[i] = team[i];
            }
            delete [] team;
            capacity *= 2;
            team = new Programmer[capacity];
            assert(team!=NULL);
            for(int i=0;i<size;i++)
            {
                team[i] = tmp[i];
            }
            delete [] tmp;
        }
        team[size] = p;
        size++;
        sort();
    }
    bool removeProgrammer(char* name)
    {
        if(capacity > size*2)
        {
            Programmer* tmp = new Programmer[size];
            assert(tmp!=NULL);
            for(int i=0;i<size;i++)
            {
                tmp[i] = team[i];
            }
            delete [] team;
            capacity /= 2;
            team = new Programmer[capacity];
            assert(team!=NULL);
            for(int i=0;i<size;i++)
            {
                team[i] = tmp[i];
            }
            delete [] tmp;
        }
        bool flag = false;
        for(int i=0;i<size-1;i++)
        {
            if(!strcmp(team[i].getName(),name))
            {
                flag = true;
            }
            if(flag)
            {
                team[i] = team[i+1];
            }
        }
        if(!strcmp(team[size-1].getName(),name) || flag)
        {
            size--;
            return true;
        }
        return false;
    }
    Programmer& getProgrammer(char* name)
    {
        for(int i=0;i<size;i++)
        {
            if(!strcmp(team[i].getName(),name))
            {
                return team[i];
            }
        }
    }
    void print() const
    {
        cout<<"***************************************\n";
        cout<<"Team: "<<name<<endl;
        for(int i=0;i<size;i++)
        {
            team[i].print();
        }
    }
    Team& operator-=(const Team& other)
    {
        for(int i=0;i<size;i++)
        {
            for(int j=0;j<other.size;j++)
            {
                Programmer p = other.team[j];
                if(!strcmp(team[i].getName(),p.getName()))
                {
                    removeProgrammer(team[i].getName());
                }
            }
        }
        return *this;
    }
    void sort()
    {
        for(int i=0;i<size-1;i++)
        {
            int k = i;
            Programmer maxProgrammer = team[i];
            for(int j=i+1;j<size;j++)
            {
                if(maxProgrammer < team[j])
                {
                    maxProgrammer = team[j];
                    k = j;
                }
            }
            Programmer a = team[i];
            team[i] = team[k];
            team[k] = a;
        }
    }
    double averageIQ()
    {
        double sum=0;
        for(int i=0;i<size;i++)
        {
            sum += team[i].getIQ();
        }
        return sum/size;
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
};

class Company
{
private:
    Team* company;
    int size;
    int capacity;
    void copy(const Company& other)
    {
        size = other.size;
        capacity = other.capacity;
        company = new Team[other.capacity];
        for(int i=0;i<size;i++)
        {
            company[i] = other.company[i];
        }
    }
    void del()
    {
        delete [] company;
    }
public:
    Company()
    {
        size = 0;
        capacity = 1;
        company = new Team[capacity];
    }
    ~Company()
    {
        del();
    }
    Company(const Company& other)
    {
        copy(other);
    }
    Company& operator=(const Company& other)
    {
        if(this != &other)
        {
            del();
            copy(other);
        }
        return *this;
    }
    void addTeam(Team& t)
    {
        if(size == capacity)
        {
            Team* tmp = new Team[capacity];
            assert(tmp!=NULL);
            for(int i=0;i<size;i++)
            {
                tmp[i] = company[i];
            }
            delete [] company;
            capacity *= 2;
            company = new Team[capacity];
            assert(company!=NULL);
            for(int i=0;i<size;i++)
            {
                company[i] = tmp[i];
            }
            delete [] tmp;
        }
        company[size] = t;
        size++;
    }
    double averageIQ()
    {
        double sum = 0;
        for(int i=0;i<size;i++)
        {
            sum += company[i].averageIQ();
        }
        return sum/size;
    }
    void print() const
    {
        for(int i=0;i<size;i++)
        {
            company[i].print();
        }
    }
};

int main()
{
    Team first("One");
    first.addProgrammer("Ivan",60,300);
    first.addProgrammer("Kiril",100,1000);
    first.addProgrammer("Mihail",90,700);
    first.addProgrammer("Darina",120,2000);
    first.addProgrammer("Svilen",160,3000);
    first.removeProgrammer("Mihail");
    Team second("Two");
    second.addProgrammer("Hristina",80,800);
    second.addProgrammer("Georgi",40,500);
    second.addProgrammer("Ivan",60,300);
    first -= second;
    Team third("Three");
    third.addProgrammer("Liliq",90,1500);
    third.addProgrammer("Dobri",70,1300);
    third.addProgrammer("Frank",130,2400);
    Company Microsoft;
    Microsoft.addTeam(first);
    Microsoft.addTeam(second);
    Microsoft.addTeam(third);
    Microsoft.print();
    cout<<"Average IQ: "<<Microsoft.averageIQ();
    return 0;
}

//6.00