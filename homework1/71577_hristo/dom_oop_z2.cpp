#include<iostream>
#include<cassert>
#include<cstring>
using namespace std;
struct ID
{
private:
    char* family;
    int day;
    int month;
    int year;
public:
void setFamily(char* family)
    {
        delete [] this->family;
        this->family=new char[strlen(family)+1];
        assert(this->family!=NULL);
        strcpy(this->family, family);
    }
    const char*family() const 
    {
        return family();
    }
    int getDay() const
    {
        return day;
    }
    void setDay(int d) const
    {
        day=d;
    }
    int getMonth() const
    {
        return month;
    }
    void setMonth(int m) const
    {
        month=m
    }
    int getYear() const
    {
        return yaer;
    }
    void setYear(int y) const
    {
        year=y;
    }
};
struct Zodiac
{
private:
    char name[15];
    int day_s;
    int month_s;
    int day_f;
    int month_f;
public:
    int getDay_s() const
    {
        return day_s;
    }
    void setDay_s(int d_s) const
    {
        day_s=d_s;
    }
     int getMonth() const
    {
        return month_s;
    }
    void setMonth(int m_s) const
    {
        month_s=m_s;
    }
};
class ListPerson
{
public:
    ID cards[50];
    int size;
    void addCard(ID newCard)
    {
        if(size<50)
        {
            cards[size+1]=newCard;
        }
        else cout<<"Capacity is full!"<<endl;
    }
    void removeCard(char*fam)
    {
        ID newList[50];
        for(int i=0; i<size; i++)
        {
            if(cards[i].getFamily!=fam)
            {
                newList[i]=cards[i];
            }
        }
    }
    ID accessCard(char*fam)
    {
        for(int i=0; i<size; i++)
        {
            if(cards[i].getFamily==fam)
            {
                cout<<"Family:"<<cards[i].getFamily<<endl;
                cout<<"Date of birth:"<<cards[i].getDay<<"."<<cards[i].getMonth<<"."<<cards[i].getYear<<endl;
            }
        }
    }
    Zodiac findZodia(char*fam)  //namirane na zodia po familiq - nedovarsheno
    {
        for(int i=0; i<size; i++)
        {
            if(cards[i].getFamily==fam)
            {

            }
        }
    }
    ID &operator+ (const ID &other)
    {
        ID* a = new ID;     //obedinenie na kortoteki - nedovarsheno

    }

};
