#include <iostream>
#include <cstring>
using namespace std;
class Programmer
{
public:
    Programmer();
    Programmer(char*, int, double);
    ~Programmer();
    Programmer(const Programmer&);
    Programmer& operator=(const Programmer&);
    void setName(char*);
    void setIq(int);
    void setSalary(double);
    char* getName()const;
    int getIq()const;
    double getSalary()const;
    void print()const;
    bool operator>(const Programmer&);
    bool operator<(const Programmer&);
    bool operator==(const Programmer&);
private:
    char* name;
    int iq;
    double salary;
    void copy(const Programmer&);
    void del();
};
Programmer::Programmer():
    iq(0), salary(0.0)
{
    name = "";
}
Programmer::Programmer(char* name, int iq, double salary)
{
    this -> iq = iq;
    this -> salary = salary;
    this -> name = new char[strlen(name) + 1];
    strcpy(this -> name, name);
}
Programmer::~Programmer()
{
    del();
}
Programmer::Programmer(const Programmer& other)
{
    copy(other);
}
Programmer& Programmer::operator=(const Programmer& other)
{
    if(this != &other)
    {
        del();
        copy(other);
    }
    return *this;
}
void Programmer::setName(char* name)
{
    del();
    strcpy(this -> name, name);
}
void Programmer::setIq(int iq)
{
    this -> iq = iq;
}
void Programmer::setSalary(double salary)
{
    this -> salary = salary;
}
char* Programmer::getName()const
{
    return name;
}
int Programmer::getIq()const
{
    return iq;
}
double Programmer::getSalary()const
{
    return salary;
}
void Programmer::print()const
{
    cout << name << " " << iq << " " << salary;
}
// else what?
// - 0.2
bool Programmer::operator>(const Programmer& other)
{
    if(iq > other.iq)
        return true;
}
// ... 
bool Programmer::operator<(const Programmer& other)
{
    if(iq < other.iq)
        return true;
}
//...
bool Programmer::operator==(const Programmer& other)
{
    if(iq == other.iq)
        return true;
}
void Programmer::copy(const Programmer& other)
{
    iq = other.iq;
    salary = other.salary;
    name = new char[strlen(other.name) + 1];
    strcpy(name,other.name);
}
void Programmer::del()
{
    delete[] name;
}
class Team
{
public:
    Team();
    ~Team();
    Team(const Team&);
    Team& operator=(const Team &);
    void addProgrammer(const Programmer&);
    void removeProgrammer(const char*);
    Programmer getProgrammer(const char*);
    void print()const;
    Team& operator-=(const Team&);
    bool contain(const Programmer*, const char*, int);
    int getSize()const;
private:
    Programmer* programmers;
    int size;
    int capacity;
    void extend();
    void copy(const Team&);
    void del();
};
Team::Team():
    size(0), capacity(1)
{
    programmers = new Programmer[capacity];
}
Team::~Team()
{
    del();
}
Team::Team(const Team& other)
{
    copy(other);
}
Team& Team::operator=(const Team& other)
{
    if(this != &other)
    {
        del();
        copy(other);
    }
    return *this;
}
void Team::addProgrammer(const Programmer& newPro)
{
    if(size == capacity)
    {
        extend();
    }
    programmers[size++] = newPro;
}
void Team::removeProgrammer(const char* name)
{
    for(int i = 0; i < size; i++)
    {
        // strcmp? 
        // - 0.1
        if(programmers[i].getName() == name)
        {
            for(int j = i+1; j < size; j++)
            {
                programmers[j-1] = programmers[j];
            }
            --size;
            return;
        }
    }
}
Programmer Team::getProgrammer(const char* name)
{
    for(int i = 0; i < size; i++)
    {
        //..
        if(programmers[i].getName() ==  name)
        {
            return programmers[i];
        }
    }
}
void Team::print()const
{
    for(int i = 0; i < size; i++)
    {
        programmers[i].print();
        cout << endl;
    }
}
Team& Team::operator-=(const Team& other)
{
    for(int i = 0; i < size; i++)
    {
        if(contain(other.programmers, programmers[i].getName(), other.size))
            removeProgrammer(programmers[i].getName());
    }
}
bool Team::contain(const Programmer* other, const char* name, int n)
{
    for(int i = 0; i < n; i++)
    {
        //...
        if(other[i].getName() == name)
            return true;
    }
    return false;
}
int Team::getSize()const
{
    return size;
}
// same as 71580
void Team::extend()
{
    Programmer* oldProgrammers = programmers;
    programmers = new Programmer[2*capacity];
    for(int i = 0; i < size; i++)
    {
        programmers[i] = oldProgrammers[i];
    }
    delete[] oldProgrammers;
    capacity *= 2;
}
void Team::copy(const Team& other)
{
    size = other.size;
    capacity = other.capacity;
    del();
    programmers = new Programmer[capacity];
    for(int i = 0; i < size; i++)
    {
        programmers[i] = other.programmers[i];
    }
}
void Team::del()
{
    delete[] programmers;
}
class Company
{
public:
    Company();
    ~Company();
    Company(const Company&);
    Company& operator=(const Company&);
    int averageIq();
    void print()const;
private:
    Team* teams;
    int size;
    int capacity;
    void copy(const Company&);
    void del();
};
Company::Company():
    size(0),capacity(1)
{
    teams = new Team[capacity];
}
Company::~Company()
{
    del();
}
Company::Company(const Company& other)
{
    copy(other);
}
Company& Company::operator=(const Company& other)
{
    if(this != &other)
    {
        del();
        copy(other);
    }
    return *this;
}
int Company::averageIq()
{
    int sum = 0, counter = 0;
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < teams[i].getSize(); j++)
        {
            sum += teams[i].programmers[j].getIq();
            counter ++;
        }
    }
    return sum/counter;
}
void Company::print()
{
    for(int i = 0; i < size; i++)
    {
        teams[i].print();
        cout << endl;
    }
}
// 5.7