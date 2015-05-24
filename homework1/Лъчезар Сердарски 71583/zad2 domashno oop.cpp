#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
using namespace std;
struct Date
{
    int day,month;
    Date()
    {
        day = 1;
        month = 1;
    }
    bool operator>=(const Date& other)
    {
        if(month == other.month)
        {
            if(day >= other.day)
                return true;
        }
        else if(month > other.month)
            return true;
        return false;
    }
    bool operator<=(const Date& other)
    {
        if(month == other.month)
        {
            if(day <= other.day)
                return true;
        }
        else if(month < other.month)
            return true;
        return false;
    }
    Date(int d, int m):day(d), month(m){}
    void print()
    {
        cout << day << "." << month;
    }
};
struct BusinessCard
{
    char* family;
    Date birthday;
    BusinessCard()
    {
        family = "Ivanov";
    }
    BusinessCard(char* name, int d, int m)
    {
        family = name;
        birthday = Date(d,m);
    }
    void print()
    {
        cout << family << " ";
        birthday.print();
    }
};
class ListPerson
{
public:
    ListPerson();
    ListPerson(const ListPerson&);
    ~ListPerson();
    ListPerson& operator=(const ListPerson&);
    void addBusinessCard(const BusinessCard&);
    void removeBusinessCard(const char*);
    BusinessCard getBusinessCard(char*);
    void print()const;
    bool contain(BusinessCard*, char*, unsigned);
    ListPerson& operator+(const ListPerson&);//obedinqvane
    ListPerson& operator/(const ListPerson&);//sechenie
    ListPerson& operator-(const ListPerson&);//razlika
    struct Zodiac
    {
        char* zodia;
        Date beginning;
        Date ending;
        Zodiac(char* z, int beginningDay, int beginningMonth, int endingDay, int endingMonth):
        beginning(beginningDay, beginningMonth), ending(endingDay, endingMonth)
        {
            zodia = z;
        }
    }zodiac[12] = {{"Oven",21,3,20,4},{"Telec",21,4,20,5},{"Bliznaci",21,5,20,6},
                    {"Rak",21,6,20,7},{"Lav",21,7,20,8},{"Deva",21,8,20,9},
                    {"Vezni",21,9,20,10},{"Skorpion",21,10,20,11},{"Strelec",21,11,20,12},
                    {"Kozirog",21,12,20,1},{"Vodolei",21,1,20,2},{"Ribi",21,2,20,3}};
    void zodiq(char*);
private:
    BusinessCard* businessCards;
    unsigned size;
    unsigned capacity;
    void extend();
    void copy(const ListPerson&);
    void del();
};
ListPerson::ListPerson():size(0),capacity(1)
{
    businessCards = new BusinessCard[capacity];
}
ListPerson::ListPerson(const ListPerson& other)
{
    copy(other);
}
ListPerson::~ListPerson()
{
    del();
}
ListPerson& ListPerson::operator=(const ListPerson& other)
{
    if(this != &other)
    {
        del();
        copy(other);
    }
    return *this;
}
void ListPerson::addBusinessCard(const BusinessCard& businessCard)
{
    if(size == capacity)
    {
        extend();
    }
    if(contain(businessCards, businessCard.family, size) == false)
    {
        businessCards[size++] = businessCard;
    }
}
void ListPerson::removeBusinessCard(const char* name)
{
    for(int i = 0; i < size; i++)
    {
        if(strcmp(businessCards[i].family,name))
        {
            for(int j = i+1; j < size; j++)
            {
                businessCards[j-1] = businessCards[j];
            }
            --size;
            return;
        }
    }
}
BusinessCard ListPerson::getBusinessCard(char* name)
{
    for(int i = 0; i < size; i++)
    {
        if(strcmp(businessCards[i].family, name))
            return businessCards[i];
    }
}
bool ListPerson::contain(BusinessCard* b, char* name,unsigned s)
{
    for(int i = 0; i < s; i++)
    {
        if(strcmp(b[i].family, name))
            return true;
    }
}
ListPerson& ListPerson::operator+(const ListPerson& other)//obedinenie
{
    capacity = size + other.size;
    for(int i = size; i < capacity; i++)
    {
        businessCards[i] = other.businessCards[i - size];
    }
    size += other.size;
    return *this;
}
ListPerson& ListPerson::operator/(const ListPerson& other)//sechenie
{
    for(int i = 0; i < size; i++)
    {
        if(contain(other.businessCards, businessCards[i].family, size) == false)
            removeBusinessCard(businessCards[i].family);
    }
    return *this;
}
ListPerson& ListPerson::operator-(const ListPerson& other)//razlika
{
    for(int i = 0; i < size; i++)
    {
        if(contain(other.businessCards, businessCards[i].family, size))
            removeBusinessCard(businessCards[i].family);
    }
    capacity = size + other.size;
    for(int i = 0; i < other.size; i++)
    {
        if(contain(businessCards, other.businessCards[i].family, size) == false)
            addBusinessCard(other.businessCards[i]);
    }
    return *this;
}
void ListPerson::zodiq(char* name)
{
    for(int i = 0; i < 12; i++)
    {
        if(getBusinessCard(name).birthday >= zodiac[i].beginning &&
           getBusinessCard(name).birthday <= zodiac[i].ending)
        {
            cout << zodiac[i].zodia << endl;
        }
    }
}
void ListPerson::print()const
{
    for(int i = 0; i < size; i++)
    {
        businessCards[i].print();
        cout << endl;
    }
    return;
}
void ListPerson::extend()
{
    BusinessCard* oldBusinessCards = businessCards;
    businessCards = new BusinessCard[2*capacity];
    for(int i = 0; i < size; i++)
    {
        businessCards[i] = oldBusinessCards[i];
    }
    delete[] oldBusinessCards;
    capacity *= 2;
}
void ListPerson::copy(const ListPerson& other)
{
    size = other.size;
    businessCards = new BusinessCard[capacity];
    for(int i = 0; i < size; i++)
    {
        businessCards[i] = other.businessCards[i];
    }
}
void ListPerson::del()
{
    delete[] businessCards;
}
int main()
{

    return 0;
}
