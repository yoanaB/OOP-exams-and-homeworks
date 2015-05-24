#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;
struct Date
{
private:
    int day;
    int month;
    int year;

public:
    int getDay()
    {
        return this->day;
    }

    int getMonth()
    {
        return this->month;
    }

    int getYear()
    {
        return this->year;
    }

    Date()
    {
        this->day = 1;
        this->month = 1;
        this->year = 1900;
    }

    Date(int day, int month, int year)
    {
        assert(month > 0 && month <= 12);
        assert(year >= 1900);
        if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        {
            if(day <= 0 || day > 31)
            {
                throw "Invalid date";
            }
        }
        else if(month == 4 || month == 6 || month == 9 || month == 11)
        {
            if(day <= 0 || day > 30)
            {
                throw "Invalid date";
            }
        }
        else
        {
            if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
            {
                if(day <= 0 && day > 29)
                {
                    throw "Invalid date";
                }
            }
            else
            {
                if(day <= 0 && day > 28)
                {
                    throw "Invalid date";
                }
            }
        }
    }
};

struct BusinessCard
{
private:
    char* family;
    Date birthday;

    void init(char* family, Date birthday)
    {
        this->family = new char[strlen(family) + 1];
        assert(this->family != NULL);
        strcpy(this->family, family);
        this->birthday = birthday;
    }

public:
    char* getFamily()
    {
        return this->family;
    }

    Date getBirthday()
    {
        return this->birthday;
    }

    BusinessCard(char* family, Date birthday)
    {
        init(family, birthday);
    }

    BusinessCard()
    {
        init("no name", Date(1, 1, 1900));
    }

    BusinessCard(const BusinessCard& other)
    {
        init(other.family, other.birthday);
    }

    BusinessCard& operator= (const BusinessCard& other)
    {
        if(this != &other)
        {
            delete[] this->family;
            init(other.family, other.birthday);
        }
        return *this;
    }

    ~BusinessCard()
    {
        delete[] this->family;
    }
};

class ListPerson
{
private:
    BusinessCard* cards;
    int capacity;
    int cardCount;

    void increaseCapacity(){
        BusinessCard* temp = new BusinessCard[this->capacity];
        assert(temp != NULL);
        copyCards(this->cards, temp, this->capacity);
        delete[] this->cards;
        this->cards = new BusinessCard[this->capacity * 2];
        assert(this->cards != NULL);
        copyCards(temp, this->cards, this->capacity);
        this->capacity *= 2;
        delete[] temp;
    }

    void reduceCapacity()
    {
        BusinessCard* temp = new BusinessCard[this->cardCount];
        assert(temp != NULL);
        copyCards(this->cards, temp, this->cardCount);
        delete[] this->cards;
        this->cards = new BusinessCard[this->capacity / 2];
        assert(this->cards != NULL);
        copyCards(temp, this->cards, this->cardCount);
        this->capacity /= 2;
        delete[] temp;
    }

    void copyCards(BusinessCard* source, BusinessCard* destination, int count){
        for(int i = 0; i < count; i++){
            destination[i] = source[i];
        }
    }

    int findCardByName(char* family)
    {
        for(int i = 0; i < this->cardCount; i++)
        {
            if(strcmp(this->cards[i].getFamily(), family) == 0)
            {
                return i;
            }
        }
        return -1;
    }

public:
    void printCapacity()
    {
        cout << this->capacity << endl;
    }

    void printCards()
    {
        for(int i = 0; i < this->cardCount; i++)
        {
            cout << this->cards[i].getFamily() << endl;
        }
    }

    void addBusinessCard(BusinessCard& card)
    {
        if(findCardByName(card.getFamily()) != -1)
        {
            throw "Family name already exists";
        }
        if(this->capacity == this->cardCount)
        {
            increaseCapacity();
        }
        this->cards[this->cardCount] = card;
        this->cardCount++;
    }

    BusinessCard* getBusinessCard(char* family)
    {
        int index = findCardByName(family);
        if(index != -1)
        {
            return this->cards + index;
        }
        return NULL;
    }

    void deleteBusinessCard(char* family)
    {
        int index = findCardByName(family);
        if(index != -1)
        {
            for(int i = index; i < this->cardCount - 1; i++)
            {
                this->cards[i] = this->cards[i + 1];
            }
            this->cardCount--;
            if(this->cardCount == this->capacity/2)
            {
                reduceCapacity();
            }
        }
    }

    ListPerson()
    {
        this->cards = new BusinessCard[2];
        assert(this->cards != NULL);
        this->capacity = 2;
        this->cardCount = 0;
    }

    ~ListPerson()
    {
        delete[] this->cards;
    }
};

int main()
{

    return 0;
}
