// Abstaction
// Inheritance
// Encapsulation
// Polymorphism
#include <iostream>
#include <cassert>
#include <cstring>

using namespace std;

class Programmer
{
private:
    char* name;
    int iq;
    double salary;
    void del ()
    {
        delete [] name;
    }
    void cpy (const Programmer& other)
    {
        this->name = new char [strlen (other.name) + 1];
        assert (this->name != NULL);
        strcpy (this->name, other.name);

        this->iq = other.iq;
        this->salary = other.salary;
    }
public:
    Programmer ()
    {
        name = new char[4];
        strcpy (name, "ime");
        iq = 0;
        salary = 0;
    }

    Programmer (char* name, int iq, double salary)
    {
        this->name = new char [strlen(name) + 1];
        assert (this->name != NULL);
        strcpy (this->name, name);

        this->iq = iq;
        this->salary = salary;
    }

    ~Programmer ()
    {
        del ();
    }

    Programmer &operator= (const Programmer& other)
    {
        if (this != &other)
        {
            del ();
            cpy (other);
        }
        return *this;
    }

    Programmer (const Programmer& other)
    {
        del ();
        cpy (other);
    }

    void setName (char* name)
    {
        delete [] name;
        this->name = new char [strlen(name) + 1];
        assert (this->name != NULL);
        strcpy (this->name, name);
    }

    const char* getName () const
    {
        return name;
    }

    void setIq (int iq)
    {
        if (this->iq > 0)
            this->iq = iq;
    }

    int getIq () const
    {
        return iq;
    }

    void setSalary (double salary)
    {
        if (this->salary > 0)
            this->salary = salary;
    }

    double getSalary () const
    {
        return salary;
    }


    bool operator > (const Programmer& other)
    {
        return this->iq > other.iq;
    }

    bool operator < (const Programmer& other)
    {
        return this->iq < other.iq;
    }

    bool operator == (const Programmer& other)
    {
        return this->iq == other.iq;
    }

    void print ()
    {
        cout << "Name: " << name << endl;
        cout <<"Iq: " << iq << endl;
        cout << "Salary: " << salary << endl;
    }


};

class Team
{
private:
    Programmer* programisti;
    int real_size;
    int max_size;
    void delTeam ()
    {
        delete [] programisti;
    }
    void cpyTeam (const Team& other)
    {
        max_size = other.max_size;
        real_size = other.real_size;

        this->programisti = new Programmer [max_size];
        assert (this->programisti != NULL);

        for (int i = 0; i < real_size; i++)
        {
            this->programisti[i] = other.programisti[i];
        }
    }
public:
    Team (int max_size)
    {
        this->max_size = max_size;

        this->programisti = new Programmer [max_size];
        assert (this->programisti != NULL);

        this->real_size = 0;
    }

    ~Team ()
    {
        delTeam();
    }

    Team (const Team& other)
    {
        delTeam();
        cpyTeam (other);
    }

    Team &operator = (const Team& other)
    {
        if (this != &other)
        {
            delTeam();
            cpyTeam(other);
        }
        return *this;
    }

    void printTeam ()
    {
        if (real_size > 0)
        {
            for (int i = 0; i < real_size; i++)
            {
                programisti[i].print();
            }
        }
        else cout << "nqma vuvedeni programisti"<< endl;
    }

    void getProgrammer (char* name)
    {
        for (int i = 0; i < real_size; i++)
        {
            if (!(strcmp (programisti[i].getName (), name)))
            {
                programisti[i].print ();
            }
        }
    }

    void addProgrammer (const Programmer& other)
    {
        if (max_size <= real_size)
        {
            max_size *= 2;
            Programmer* tmp = new Programmer [max_size];
            assert (tmp != NULL);
            for (int i = 0; i < real_size; i++)
            {
                tmp[i] = programisti[i];
            }
            delete [] programisti;
            programisti = tmp;
        }
        programisti[++real_size] = other;
    }

    void removeProgrammer (char* name)
    {
        if (max_size > real_size*2)
            max_size /= 2;
            Programmer* tmp = new Programmer [max_size];
            assert (tmp != NULL);

            for (int i = 0; i < real_size; i++)
            {
                tmp[i] = programisti[i];
            }
            delete [] programisti;
            programisti = tmp;


        int removeIndex = 0;
        bool flag = false;
        for (int i = 0; i < real_size; i++)
        {
            if (!(strcmp(programisti[i].getName(), name)))
            {
                removeIndex = i;
                flag = true;
            }
        }

        if (flag)
        {
            for (int i = removeIndex; i < real_size; i++)
            {
                programisti[i] = programisti[i + 1];
            }
            real_size--;
        }
    }

    void sortTeam ()
    {
        bool isNotSorted = true;
        while (isNotSorted)
        {
            isNotSorted = false;
            for (int i = 0; i < real_size; i++)
            {
                if (programisti[i].getIq() < programisti [i + 1].getIq())
                {
                    Programmer tmp = programisti [i];
                    programisti [i] = programisti [i + 1];
                    programisti [i + 1] = tmp;
                    isNotSorted = true;
                }
            }
        }
    }

    Team (Programmer* smt, int Size)
    {
        this->programisti = new Programmer [Size];
        for (int i = 0; i < Size; i++)
        {
            programisti[i] = smt[i];
        }
        delete [] smt;
    }


    Team &operator -= (const Team& other)
    {
        Programmer* tmp = new Programmer [max_size];
        assert (tmp != NULL);
        for (int i = 0; i < real_size; i++)
        {
            if ( !(strcmp (this->programisti[i].getName(), other[i].getName())))
            {
                tmp[i] = programisti[i + 1];
                real_size --;
            }
        }

        delete [] this->programisti;
        programisti = tmp;

    }


    double avIq ()
    {
        double result = 0;
        for (int i = 0; i < real_size; i++)
        {
            result += programisti[i].getIq();
        }
        return result/real_size;
    }


};

class Company
{
private:
    Team* teams;
    int real_size_company;
    int max_size_company;
public:
    void printCompany ()
    {
        for (int i = 0; i < real_size_company; i++)
        {
            teams[i].printTeam();
        }
    }

    double avarageIq ()
    {
        double result1 = 0;
        for (int i = 0; i < real_size_company; i++)
        {
            result1 += teams[i].avIq();
        }
        return result1/real_size_company;
    }

    ~Company ()
    {
         for (int i = 0; i < real_size_company; i++)
         {
             delete [] (this->teams + i);
         }
        delete [] teams;
    }


    Company (int real_size_company)
    {
        this->max_size_company = max_size_company;

        for (int i = 0; i < real_size_company; i++)
         {
            this->teams = new Team (max_size_company);
            assert (this->teams != NULL);
         }
        this->real_size_company = 0;
    }



};

int main ()
{
     Programmer a;
     // a.print ();

    // Programmer b(a);
    // b.print ();

    Programmer d("kali", 5, 10);
    // d.print ();

    // bool c = d > a;
    // cout << c << endl;
    // bool e = d < a;
    // cout << e << endl;
    // bool f = a == (d);
    // cout << f;

    // Programmer c;
    // c = d;
    // c.print ();

    Team t(5);
    t.printTeam();
    t.addProgrammer(d);
    t.printTeam();
    // t.removeProgrammer("ime");
    // t.printTeam ();


    return 0;

}
