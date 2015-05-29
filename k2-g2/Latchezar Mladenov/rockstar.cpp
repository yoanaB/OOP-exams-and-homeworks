#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
using namespace std;

// 4-те принципа:
// Абстракция
// Капсулиране
// Наследяване
// Полиморфизъм

char s[60];// buffer for name
int size = 2;
class RockStar{
public:
    RockStar();
    ~RockStar();
    RockStar (const RockStar&);
    RockStar& operator=(const RockStar&);
    void print() const;
    char* get_name() const;
    int get_awesomeness() const;
    int get_fens() const;
    bool operator>(const RockStar&) const;
    bool operator<(const RockStar&) const;
    bool operator==(const RockStar&) const;
private:
    char* name;
    int awesomeness;
    int numberOfFens;
};

class Band{
public:
    Band();
    ~Band();
    Band (const Band&);
    Band& operator=(const Band&);
    void addStar() const;
    void printStar() const;
    void removeStar() const;
    bool operator+=(const Band&) const;
    bool isBetter() const;
private:
    char* name;
    RockStar* band;
};

class Concert{
public:
    Concert();
    ~Concert();
    Concert (const Concert&);
    Concert& operator=(const Concert&);
    void avgAwesomeness() const;
    void headLiners() const;
private:
    Band* concert;
};


RockStar::RockStar()
{
    cout << "Name: "; cin.ignore(); cin.getline(s, 60);
    name = new char[strlen(s) + 1];
    assert(name != NULL);
    strcpy(name, s);
    cout << "Awesomeness: "; cin >> awesomeness;
    cout << "numberOfFens: "; cin >> numberOfFens;
}


RockStar::~RockStar()
{
    delete [] name;
}

void RockStar::print() const
{
    cout << setw (24) << name
         << setw (12) << awesomeness
         << setw (12) << numberOfFens;
}

char* RockStar::get_name() const
{
    return name;
}

int RockStar::get_awesomeness() const
{
    return awesomeness;
}

int RockStar::get_fens() const
{
    return numberOfFens;
}

RockStar& RockStar::operator=(const RockStar& p)
{
    if(this != &p)
    {
        delete [] name;
        name = new char[strlen(p.name) + 1];
        assert(name != NULL);
        strcpy(name, p.name);
        awesomeness = p.awesomeness;
        numberOfFens = p.numberOfFens;
    }
}

bool RockStar::operator>(const RockStar& x) const
{
    return awesomeness > x.awesomeness;
}

bool RockStar::operator<(const RockStar& x) const
{
    return awesomeness < x.awesomeness;
}

bool RockStar::operator==(const RockStar& x) const
{
    return awesomeness == x.awesomeness;
}


Band::Band()
{
    name = new char[strlen(s) + 1];
    assert(name != NULL);
    strcpy(name, s);
}

Band::~Band()
{
    delete [] name;
}

Band& Band::operator=(const Band& p)
{
    if(this != &p)
    {
        delete [] name;
        name = new char[strlen(p.name) + 1];
        assert(name != NULL);
        strcpy(name, p.name);
    }
}

void Band::addStar() const
{
    // add star
    RockStar* table = new RockStar[size];
    RockStar** ptable = new RockStar*[size];
}

void Band::removeStar() const
{
    //remove star
    RockStar* table = new RockStar[size];
    RockStar** ptable = new RockStar*[size];
    delete table;
    delete [] ptable;

}

void Band::printStar() const
{

    RockStar* table = new RockStar[size];
    RockStar** ptable = new RockStar*[size];

    // print band
    for(int i = 0; i < size; i ++)
    {
        table[i].print();
        cout << endl;
        ptable[i] = &table[i];
    }
}

bool Band::operator+=(const Band&) const
{

}

void Concert::avgAwesomeness() const
{

}

void Concert::headLiners() const
{

}

int main()
{
    RockStar* table = new RockStar[size];
    RockStar** ptable = new RockStar*[size];

    for(int i = 0; i < size; i ++)
    {
        table[i].print();
        cout << endl;
        ptable[i] = &table[i];
    }
    delete table;
    delete [] ptable;

    return 0;
}
