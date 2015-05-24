//TASK 3:

#include <iostream>
#include <string.h>

using namespace std;

class Team
{
public:
    Team();
    Team(const Team&);
    ~Team();

    Team& operator=(const Team&);

    Programmer getProgrammer(int) const;
    int getNumberOfProgrammers() const;

    void addProgrammer(const Programmer&);
    void removeProgrammer(int);
    void sort();

    void print() const;

private:
    Programmer* Programmers;
    int size;
    int capacity;

    static int lastIQ;

    void extend();

    void copy(const Team&);
    void del();
};