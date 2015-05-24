// TASK 1 :
//1. Inheritance
//2. Abstraction
//3. Encapsulation
//4. Polymorphism

// TASK 2:

#include <iostream>
#include <string.h>

using namespace std;

class Programmer
{
public:
    Programmer();
    Programmer(const char*, int, double);
    Programmer(const Programmer&);
    ~Programmer();
    Programmer& operator = (const Programmer&);

    const char* getName() const;
    int getIQ() const;
    double getSalary() const;

    void setName(const char*);
    void setIQ(int);
    void setSalary(double);
    void print() const;

private:
    char* name;
    int IQ;
    double salary;

    void copy(const Programmer&);
    void del();
};

Programmer::Programmer():
    IQ(0), salary(0)
{
    name = new char[1];
    name[0] = '\0';
}
Programmer::Programmer(const char* programmerName,
                 int programmerIQ,
                 double programmerSalary):
  IQ(programmerIQ), salary(programmerSalary)
{
	name = new char[strlen(programmerName) + 1];
	strcpy(name, programmerName);
}
Programmer::Programmer(const Programmer& other)
{
    copy(other);
}
Programmer::~Programmer()
{
    del();
}
Programmer& Programmer::operator=(const Programmer& other)
{
    if (this != &other)
    {
        del();
        copy(other);
    }
    return *this;
}
const char* Programmer::getName() const
{
    return name;
}
int Programmer::getIQ() const
{
    return IQ;
}
double Programmer::getSalary() const
{
    return salary;
}
void Programmer::setName(const char* _name)
{
    delete[] name;

	name = new char[strlen(programmerName) + 1];
	strcpy(name, programmerName);
}
void Programmer::setIQ(int _IQ)
{
	IQ = programmerIQ;
}
void Programmer::setSalary(double _salary)
{
	salary = programmerSalary;
}
void Programmer::print() const
{
    cout << "Name: " << name << endl
         << "IQ: " << IQ << endl
         << "Salary: " << salary << endl;
}
void Programmer::copy(const Programmer& other)
{
    IQ = other.IQ;
    salary = other.salary;

    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
}
void Programmer::del()
{
    delete[] name;
}