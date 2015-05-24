// nasledqvane, abstrakciq, kapsulaciq, polimorfizym
#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;
class Programmer
{
    char* name;
    int iq;
    double salary;
public:
    Programmer(char* name = "Ivan", int iq = 50, double salary = 100.0)
    {
        this->name = new char[strlen(name)+1];
        assert(this->name!=NULL);
        strcpy(this->name, name);
        this->iq = iq;
        this->salary = salary;
    }
    Programmer(const Programmer& other)
    {
        name = new char[strlen(other.name)+1];
        assert(name!=NULL);
        strcpy(name, other.name);
        iq = other.iq;
        salary = other.salary;
    }
    ~Programmer()
    {
        delete [] name;
    }
    Programmer& operator=(const Programmer& other)
    {
        if(this!=&other)
        {
            delete [] name;
            delete [] name;
            name = new char[strlen(other.name)+1];
            assert(name!=NULL);
            strcpy(name, other.name);
            iq = other.iq;
            salary = other.salary;
        }
        return *this;
    }
    void setIq(int _iq)
    {
        if(_iq > 0)
            iq = _iq;
        else
            cout<<"Nevalidno IQ"<<endl;
    }
    int getIq() const
    {
        return iq;
    }
    void setSalary(double _salary)
    {
        if(_salary > 0)
            salary = _salary;
        else
            cout<<"Nevalidna zaplata"<<endl;
    }
    double getSalary() const
    {
        return salary;
    }
    void setName(char* _name)
    {
        delete [] name;
        name = new char[strlen(_name)+1];
        assert(name!=NULL);
        strcpy(name, _name);
    }
    char* getName() const
    {
        return name;
    }
    bool operator>(const Programmer& other)
    {
        return this->iq > other.iq;
    }
     bool operator<(const Programmer& other)
    {
        return this->iq < other.iq;
    }
     bool operator==(const Programmer& other)
    {
        return this->iq == other.iq;
    }
    void print()
    {
        cout<<"Name: "<<name<< endl
            <<"IQ: "<<iq<<endl
            <<"Salary: "<<salary<<endl;
    }
};
class Team
{
    Programmer* programmers;
    int _size;
    int capacity;
public:
    Team(int _size = 0, int capacity = 2)
    {
        this->_size = _size;
        this->capacity = capacity;
        programmers = new Programmer[capacity];
        assert(programmers!=NULL);
    }
    Team(const Team& other)
    {
        _size = other._size;
        capacity = other.capacity;
        programmers = new Programmer[capacity];
        assert(programmers!=NULL);
        for(int i = 0; i < _size; i++)
        {
            programmers[i] = other.programmers[i];
        }
    }
    ~Team()
    {
        delete [] programmers;
    }
    Team& operator=(const Team& other)
    {
        if(this!=&other)
        {
             delete [] programmers;
            _size = other._size;
            capacity = other.capacity;
            programmers = new Programmer[capacity];
            assert(programmers!=NULL);
            for(int i = 0; i < _size; i++)
            {
                programmers[i] = other.programmers[i];
            }
        }
        return *this;
    }
    void print()
    {
        cout<<"Team"<<endl
            <<"Size: "<<_size<<endl
            <<"Capacity: "<<capacity<<endl;
        for(int i = 0; i < _size; i++)
            programmers[i].print();
        cout<<"************"<<endl;
    }
    void addProgrammer(Programmer p)
    {
        if(_size == capacity)
        {
            Programmer* tmp = new Programmer[_size];
            assert(tmp!=NULL);
            for(int i = 0; i < _size; i++)
            {
                tmp[i] = programmers[i];
            }
            delete [] programmers;
            capacity *= 2;
            programmers = new Programmer[capacity];
            assert(programmers!=NULL);
            for(int i = 0; i < _size; i++)
            {
                programmers[i] = tmp[i];
            }
            delete [] tmp;
        }
        programmers[_size] = p;
        _size++;
    }
    void removeProgrammer(char* name)
    {
        if(capacity > _size*2)
        {
            Programmer* tmp = new Programmer[capacity/2];
            assert(tmp!=NULL);
            for(int i = 0; i < _size; i++)
            {
                tmp[i] = programmers[i];
            }
            delete [] programmers;
            capacity /= 2;
            programmers = new Programmer[capacity];
            for(int i = 0; i < _size; i++)
            {
                programmers[i] = tmp[i];
            }
            delete [] tmp;
        }
        for(int i = 0; i < _size; i++)
        {
            if(!strcmp(programmers[i].getName(), name))
            {
                for(int j = i+1; j < _size; j++)
                {
                    programmers[j-1] = programmers[j];
                }
                _size--;
            }
            //break;
        }
    }
    Programmer getProgrammer(char* name)
    {
        for(int i = 0; i < _size; i++)
        {
            if(!strcmp(programmers[i].getName(), name))
                return programmers[i];
        }
    }
    Programmer getProgrammerByIndex(int index)
    {
        return programmers[index];
    }
    Programmer* operator-=(const Team& other)
    {
        Programmer* tmp = new Programmer[capacity];
        assert(tmp!=NULL);
        for(int i = 0; i < _size; i++)
            tmp[i] = programmers[i];
        delete [] programmers;
        for(int i = 0; i < _size; i++)
        {
            for(int j = 0; j < other._size; j++)
            {
                if(tmp[i] == other.programmers[j])
                {
                    removeProgrammer(tmp[i].getName());
                }
                break;
            }
        }
        programmers = new Programmer[capacity];
        assert(programmers!=NULL);
        for(int i = 0; i < _size; i++)
            programmers[i] = tmp[i];
        return programmers;
    }
};
class Company
{
    Team* teams;
    int _size;
    int capacity;
public:
    Company(int _size = 0, int capacity = 2)
    {
        this->_size = _size;
        this->capacity = capacity;
        teams = new Team[capacity];
        assert(teams!=NULL);
    }
    Company(const Company& other)
    {
        _size = other._size;
        capacity = other.capacity;
        teams = new Team[capacity];
        assert(teams!=NULL);
        for(int i = 0; i < _size; i++)
        {
            teams[i] = other.teams[i];
        }
    }
    ~Company()
    {
        delete [] teams;
    }
    Company& operator=(const Company& other)
    {
        if(this!=&other)
        {
            delete [] teams;
            _size = other._size;
            capacity = other.capacity;
            teams = new Team[capacity];
            assert(teams!=NULL);
            for(int i = 0; i < _size; i++)
            {
                teams[i] = other.teams[i];
            }
        }
        return *this;
    }
    void print()
    {
        cout<<"Company"<< endl
            <<"Size: "<< _size<< endl
            <<"Capacity: "<< capacity<< endl;
        for(int i = 0; i < _size; i++)
            teams[i].print();
        cout<<"*************"<<endl;
    }
    double averageIQ()
    {
        double averageOfTeam = 0, sum = 0;
        double sumOfAverage = 0;
        for(int i = 0; i < this->_size; i++)
        {
            for(int j = 0; j < _size; j++)
            {
                sum += teams[i].getProgrammerByIndex(j).getIq();
                averageOfTeam = sum/j;
            }
            sumOfAverage += averageOfTeam;
        }
        return sumOfAverage/this->_size;
    }
};
int main()
{
    //class Programmer
    Programmer p1;
    p1.print();
    Programmer p2("Maria", 100, 700.0);
    p2.print();
    Programmer p3 = p2;
    p3.print();
    Programmer p4;
    p4 = p2;
    p4.print();
    p4.setName("Petq");
    p4.setIq(140);
    p4.setSalary(1000);
    p4.print();
    cout<<p4.getIq()<<endl;
    cout<<p4.getSalary()<<endl;
    cout<<p4.getName()<<endl;
    if(p2 > p1) cout<<"Raboti"<<endl;
    if(p1 < p2) cout<<"Raboti2"<<endl;
    if(p2 == p3) cout<<"Raboti3"<<endl;
    cout<<"*****************************"<<endl;

    //class Team
    Team t1;
    t1.print();
    Team t2(0, 10);
    t2.addProgrammer(p1);
    t2.addProgrammer(p2);
    t2.addProgrammer(p4);
    t2.print();
    Team t3 = t2;
    t3.print();
    t3.removeProgrammer(p4.getName());
    Team t4;
    t4 = t3;
    t4.print();
    //t2.removeProgrammer(p2.getName());
    //t2.print();
    t2.getProgrammer(p4.getName()).print();
    t2.getProgrammerByIndex(1).print();
    //cout<<"******************"<<endl;
    t2-=t3;
    t2.print();
    cout<<"*******************************"<<endl;

    //class Company
    Company c1;
    c1.print();
    Company c2(2,5);
    c2.print();
    Company c3 = c2;
    c3.print();
    Company c4;
    c4 = c3;
    c4.print();

}
