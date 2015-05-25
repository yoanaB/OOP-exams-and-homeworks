#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;

class Programer {
private:
    char* name;
    int iq;
    double salary;
    void init(const char* name, int iq, double salary)
    {
        this->name = new char[strlen(name) + 1];
        assert(this->name != NULL);
        strcpy(this->name, name);
        this->iq = iq;
        this->salary = salary;
    }

public:
    void setName(char* name)
    {
        delete[] this->name;
        this->name = new char[strlen(name) + 1];
        assert(this->name != NULL);
        strcpy(this->name, name);
    }

    char* getName ()
    {
        return this->name;
    }

    void setIq(int iq)
    {
        this->iq  = iq;
    }

    int getIq ()
    {
        return this->iq;
    }

    void setSalary(double salary)
    {
        this->salary= salary;
    }
    double getSalary()
    {
        return this->salary;
    }

    void print()
    {
        cout << this->name << " " << this->iq << " " << this->salary;
    };

    Programer()
    {
        init("no name", 0, 0);
    }

    Programer(char* name, int iq, double salary)
    {
        init(name, iq, salary);
    }

    Programer(const Programer& other)
    {
        init(other.name, other.iq, other.salary);
    }

    Programer operator== (const Programer& other)
    {
        if(this != &other)
        {
            delete[] this->name;
            init(other.name, other.iq, other.salary);
        }
        return *this;
    }

    ~Programer()
    {
        delete[] this->name;
    }
};


class Team
{
private:
    Programer* programers;
    int programersCount;
    int capacity;
    void increaseCapacity()
    {
        Programer* temp = new Programer[this->capacity];
        assert(temp != NULL);
        copyProgramers(this->programers, temp, this->capacity);
        delete[] this->programers;
        this->programers = new Programer[this->capacity * 2];
        assert(this->programers != NULL);
        copyProgramers(temp, this->programers, this->capacity);
        this->capacity *= 2;
        delete[] temp;
    }

    void copyProgramers(Programer* source, Programer* destination, int count){
        for(int i = 0; i < count; i++){
            destination[i] = source[i];
        }
    }

    int getProgramerByName(char* name)
    {
        for(int i = 0; i < this->programersCount; i++){
            if(this->programers[i].getName() == name){
                return i;
            }
        }
        return -1;
    }

public:
    void addProgramer(Programer& programers)
    {
        if(Programer == programersCount)
        {
            increaseCapacity();
        }
        this->programers[this->programersCount] = programers;
        this->programersCount++;
    }

    Programer* getProgramer(char* name)
    {
        int index = getProgramerByName(name);
        if(index != -1)
        {
            return this->programers + index;
        }
        return NULL;
    }

    void removeProgramer(char* name)
    {
        int index = getProgramerByName(name);
        if(index != -1)
        {
             for(int i = index; i < this->programersCount - 1; i++)
            {
                this->programers[i] = this->programers[i + 1];
            }
             this->programersCount--;
        }
    }

    void printProgramers ()
    {
        for(int i = 0; i < this->programersCount; i++)
        {
            this->programers[i].print();
            cout << endl;
        }
    }

    Team()
    {
        this->programers = new Programer[3];
        assert(this->programers != NULL);
        this->capacity = 3;
        this->programersCount = 0;
    }

    Team operator-= (const Team& other)
    {
        for(int i=0; i< programersCount; i++)
        {
            delete[] this->programers;
        }
        return *this;
    }


    ~Team()
    {
        delete[] this->programers;
    }
};
class Company
{
    Company* teams;
    int teamsCount;

    void printTeam()
     {
        for(int i = 0; i < this->teamsCount; i++)
        {
            this->teams[i].print();
            cout << endl;
        }
    }


};

int main()
{

    return 0;
}

// 2 cheater