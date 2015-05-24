/*
Abstraction, Polymorphism, Inheritance, Encapsulation
*/

#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;

class Programmer
{
private:
    char* name;
    int iq;
    double salary;
    void init(char* name, int iq, double salary)
    {
        this->name = new char[strlen(name) + 1];
        assert(this->name != NULL);
        strcpy(this->name, name);
        this->iq = iq;
        this->salary = salary;
    }

public:
    char* getName()
    {
        return this->name;
    }

    void setName(char* name)
    {
        delete[] this->name;
        this->name = new char[strlen(name) + 1];
        assert(this->name != NULL);
        strcpy(this->name, name);
    }

    int getIq()
    {
        return this->iq;
    }

    void setIq(int iq)
    {
        this->iq = iq;
    }

    double getSalary()
    {
        return this->salary;
    }

    void setSalary(double salary)
    {
        this->salary = salary;
    }


    void print()
    {
        cout << this->name << " " << this->iq << " " << this->salary;
    }

    Programmer()
    {
        init("no name", 0, 0);
    }

    Programmer(char* name, int iq, double salary)
    {
        init(name, iq, salary);
    }

    Programmer(const Programmer& other)
    {
        init(other.name, other.iq, other.salary);
    }

    Programmer operator=(const Programmer& other)
    {
        if(this != & other)
        {
            delete[] this->name;
            init(other.name, other.iq, other.salary);
        }
        return *this;
    }

    ~Programmer()
    {
        delete[] this->name;
    }

    bool operator==(const Programmer& other)
    {
        return this->iq == other.iq;
    }

    bool operator<(const Programmer& other)
    {
        return this->iq < other.iq;
    }

    bool operator>(const Programmer& other)
    {
        return this->iq > other.iq;
    }
};

class Team
{
private:
    Programmer* programmers;
    int capacity;
    int programmersCount;

    int getProgrammerIndexByName(char* name)
    {
        for(int i = 0; i < this->programmersCount; i++)
        {
            if(strcmp(this->programmers[i].getName(), name) == 0)
            {
                return i;
            }
        }
        return -1;
    }

    void increaseCapacity()
    {
        Programmer* temp = new Programmer[this->programmersCount];
        assert(temp != NULL);
        copyProgrammers(this->programmers, temp, this->programmersCount);
        delete[] this->programmers;
        this->programmers = new Programmer[this->capacity * 2];
        assert(this->programmers != NULL);
        copyProgrammers(temp, this->programmers, this->programmersCount);
        this->capacity *= 2;
    }

    void decreaseCapacity()
    {
        Programmer* temp = new Programmer[this->programmersCount];
        assert(temp != NULL);
        copyProgrammers(this->programmers, temp, this->programmersCount);
        delete[] this->programmers;
        this->programmers = new Programmer[this->capacity / 2];
        assert(this->programmers != NULL);
        copyProgrammers(temp, this->programmers, this->programmersCount);
        this->capacity /= 2;
    }

    void copyProgrammers(Programmer* source, Programmer* destination, int count)
    {
        for(int i = 0; i < count; i++)
        {
            destination[i] = source[i];
        }
    }

    void init(Programmer* programmers, int capacity, int programmersCount)
    {
        this->programmers = new Programmer[capacity];
        assert(this->programmers != NULL);
        copyProgrammers(programmers, this->programmers, programmersCount);
        this->capacity = capacity;
        this->programmersCount = programmersCount;
    }

public:
    void addProgrammer(Programmer& programmer)
    {
        if(this->capacity == this->programmersCount)
        {
            increaseCapacity();
        }
        this->programmers[this->programmersCount] = programmer;
        this->programmersCount++;
    }

    void removeProgrammer(char* name)
    {
        int index = getProgrammerIndexByName(name);
        if(index != -1)
        {
            for(int i = index; i < this->programmersCount - 1; i++)
            {
                this->programmers[i] = this->programmers[i + 1];
            }
            this->programmersCount--;
            if(this->programmersCount == this->capacity / 2)
            {
                decreaseCapacity();
            }
        }
    }

    Programmer* getProgrammer(char* name)
    {
        int index = getProgrammerIndexByName(name);
        if(index != -1)
        {
            return this->programmers + index;
        }
        return NULL;
    }

    void sortProgrammers()
    {
        for(int i = 0; i < this->programmersCount - 1; i++)
        {
            int minProgrammerIndex = i;
            for(int k = i + 1; k < this->programmersCount; k++)
            {
                if(this->programmers[minProgrammerIndex] > this->programmers[k])
                {
                    minProgrammerIndex = k;
                }
            }
            if(minProgrammerIndex != i)
            {
                Programmer temp = this->programmers[i];
                this->programmers[i] = this->programmers[minProgrammerIndex];
                this->programmers[minProgrammerIndex] = temp;
            }
        }
    }

    double getAverageIq()
    {
        if(this->programmersCount == 0)
        {
            return 0;
        }
        double totalIq = 0;
        for(int i = 0; i < this->programmersCount; i++)
        {
            totalIq += this->programmers[i].getIq();
        }
        return totalIq / this->programmersCount;
    }

    void print()
    {
        for(int i = 0; i < this->programmersCount; i++)
        {
            this->programmers[i].print();
            cout << endl;
        }
    }

    Team()
    {
        init(NULL, 2, 0);
    }

    Team(const Team& other)
    {
        init(other.programmers, other.capacity, other.programmersCount);
    }

    Team operator=(const Team& other)
    {
        if(this != &other)
        {
            delete[] this->programmers;
            init(other.programmers, other.capacity, other.programmersCount);
        }
        return *this;
    }

    ~Team()
    {
        delete[] this->programmers;
    }

    void operator-=(const Team& other)
    {
        for(int i = 0; i < other.programmersCount; i++)
        {
            this->removeProgrammer(other.programmers[i].getName());
        }
    }
};

class Company
{
private:
    Team* teams;
    int capacity;
    int teamsCount;

    void increaseCapacity()
    {
        Team* temp = new Team[this->teamsCount];
        assert(temp != NULL);
        copyTeams(this->teams, temp, this->teamsCount);
        delete[] this->teams;
        this->teams = new Team[this->capacity * 2];
        assert(this->teams != NULL);
        copyTeams(temp, this->teams, this->teamsCount);
        this->capacity *= 2;
    }

    void copyTeams(Team* source, Team* destination, int count)
    {
        for(int i = 0; i < count; i++)
        {
            destination[i] = source[i];
        }
    }

    void init(Team* teams, int capacity, int teamsCount)
    {
        this->teams = new Team[capacity];
        assert(this->teams != NULL);
        copyTeams(teams, this->teams, teamsCount);
        this->capacity = capacity;
        this->teamsCount = teamsCount;
    }

public:
    void addTeam(Team& team)
    {
        if(this->capacity == this->teamsCount)
        {
            increaseCapacity();
        }
        this->teams[this->teamsCount] = team;
        this->teamsCount++;
    }

    void print()
    {
        for(int i = 0; i < this->teamsCount; i++)
        {
            cout << "Team #" << i + 1 << endl;
            this->teams[i].print();
        }
    }

    double getAverageIq()
    {
        if(this->teamsCount == 0)
        {
            return 0;
        }
        double totalIq = 0;
        for(int i = 0; i < this->teamsCount; i++)
        {
            totalIq += this->teams[i].getAverageIq();
        }
        return totalIq / this->teamsCount;
    }

    Company()
    {
        init(NULL, 2, 0);
    }

    Company(const Company& other)
    {
        init(other.teams, other.capacity, other.teamsCount);
    }

    Company operator=(const Company& other)
    {
        if(this != &other)
        {
            delete[] this->teams;
            init(other.teams, other.capacity, other.teamsCount);
        }
        return *this;
    }

    ~Company()
    {
        delete[] this->teams;
    }
};

int main()
{
    Programmer p1("pesho", 5, 1);
    Programmer p2("gosho", 2, 1);
    Programmer p3("ivan", 1, 1);
    Programmer p4("anton", 1, 1);
    Programmer p5("branko", 1, 1);
    Programmer p6("marto", 1, 1);

    Team t1;
    t1.addProgrammer(p1);
    t1.addProgrammer(p2);
    t1.addProgrammer(p3);

    Team t2;
    t2.addProgrammer(p3);
    t2.addProgrammer(p4);

    t1-=t2;

    Team t3;
    t3.addProgrammer(p5);
    t3.addProgrammer(p6);

    Company c;
    c.addTeam(t1);
    c.addTeam(t2);
    c.addTeam(t3);

    c.print();

    cout << c.getAverageIq();

    return 0;
}
