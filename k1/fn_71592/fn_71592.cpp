#include<iostream>
#include<cassert>
#include<string>
#include<cstring>
#include<iomanip>

using namespace std;

// 4-te osnovni neshta sa: default-en konstruktor, destruktor, copy-konstruktor, operator ravno ( Golqmata 4-ka)

class Programmer
{
private:
    char* name;
    int iq;
    double salary;
public:
    Programmer(char* name = "Ivan", int iq = 100 , double salary = 1000.50)
    {
        this -> name = new char[strlen(name) + 1];
        assert(name != NULL);
        strcpy(this -> name, name);
        this -> iq = iq;
        this -> salary = salary;
    }
    Programmer(const Programmer& other)
    {
        this -> name = new char[strlen(other.name) + 1];
        assert(name != NULL);
        strcpy(this -> name, other.name);
        this -> iq = other.iq;
        this -> salary = other.salary;
    }
    ~Programmer()
    {
        delete[] name;
    }
    Programmer& operator =(const Programmer& other)
    {
        if(this != &other)
        {
            delete[] name;
            this -> name = new char[strlen(other.name) + 1];
            assert(name != NULL);
            strcpy(this -> name, other.name);
            this -> iq = other.iq;
            this -> salary = other.salary;
        }
        return *this;
    }
    void Print()
    {
        cout << "Name: " << name << setw(5) << "IQ: " << iq << setw(5) << "Salary: " << salary << endl;
    }
    void setName(char* name)
    {
         this -> name = new char[strlen(name) + 1];
         assert(name != NULL);
         strcpy(this -> name, name);
    }
    char* getName() const
    {
        return name;
    }
    void setIq(int iq)
    {
        this -> iq = iq;
    }
    int getIq() const
    {
        return iq;
    }
    void setSalary(double salary)
    {
        this -> salary = salary;
    }
    int getSalary() const
    {
        return salary;
    }
    bool operator >(const Programmer& other)
    {
        return this -> iq > other.iq;
    }
      bool operator <(const Programmer& other)
    {
        return this -> iq < other.iq;
    }
     Programmer& operator  == (int iq)
    {
        this -> iq == iq;
        return* this;
    }
};

class Team
{
private:
    Programmer* programmers;
    int size;
public:
    Programmer(int size, Programmer* programmers)
    {
        this -> size = size;
        assert(this -> programmers != NULL);
        this -> programmers = new programmers[size];
        for(int i = 0; i < size; i++)
        {
           this -> programmers[i] = programmers[i];
        }
    }
     int getSize()const
    {
        return size;
    }
    void setSize(int size)
    {
        this -> size = size;
    }
     void addProgrammer(Programmer &other)
    {
        Programmer *temp = new Programmer[getSize() + 1];
        for(int i = 0; i < getSize(); i++)
        {
            temp[i] = programmers[i];
        }
        temp[getSize()] = other;
        delete[] programmers;
        programmers = new Programmer[getSize()];
        for(int i = 0; i < getSize(); i++)
        {
        programmers[i] = temp[i];
        }
        delete[] temp;
    }
    void removeProgrammer(char* name)
    {
        for(int i = 0; i < getSize(); i++)
        {
            if(programmers[i].getName() == name)
            {
                programmers[i].setIq(0);
                programmers[i].setSalary(0);
                programmers[i].setName("");
                break;
            }
        }
    }
    Programmer getProgrammer(char* name)
    {
        for(int i = 0; i < getSize(); i++)
        {
            if(programmers[i].getName() == name)
            {
                Programmers[i].Print();
                return programmers[i];
                break;
            }
        }
    }
    void printAllProgrammers()
    {
        for(int i = 0; i < getSize(); i++)
        {
            programmers[i].Print();
            cout << endl;
        }
    }

};

class Company
{
private:
    Team* teams;
    int size;
public:
    Company(int size, Team* teams)
    {
        this -> size = size;
        assert(teams != NULL);
        strcpy(this -> teams, teams);
        this -> teams = new teams[size];
        for(int i = 0; i < size; i++)
        {
           this -> teams[i] = teams[i];
        }
    }
    Company(const Company& other)
    {
        this -> teams = new char[strlen(other.teams) + 1];
        assert(this -> teams != NULL);
        strcpy(this -> teams, other.teams);
        this -> size = size;
    }
    Company& operator =(const Company& other)
    {
        if(this != &other)
        {
            delete[] teams;
            this -> teams = new char[strlen(other.teams) + 1];
            assert(this -> teams != NULL);
            strcpy(this -> teams, other.teams);
            this -> size = size;
        }
        return *this;
    }
    ~Company()
    {
        delete[] teams;
    }
    int getSize()const
    {
        return size;
    }
    void setSize(int size)
    {
        this -> size = size;
    }
     void printAllTeams()
    {
        for(int i = 0; i < getSize(); i++)
        {
            Teams[i].Print();
            cout << endl;
        }
    }
    double averageIq(int iq)
    {
        for(int i = 0; i < getSize(); i++)
        {
            teams[i] = teams[i];
            teams[i] / size = n;

        }
        return n;
    }
};


int main()
{


 return 0;
}
