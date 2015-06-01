#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;
class Date
{
private:
    int month,
        day,
        year;
public:
    Date (int d = 1,int m = 1,int y = 2000)
    {
        day = d;
        month = m;
        year = y;
    }
    /*
    Date (const Date& other)
    {
        month = other.month;
        day = other.day;
        year = other.year;
    }
    Date& operator=(const Date& other)
    {
        month = other.month;
        day = other.day;
        year = other.year;
        return *this;
    }
    */
    void print()
    {
        cout<<day<<"."<<month<<"."<<year<<endl;
    }
    void setMonth(int m)
    {
        if (m>=1 && m<=12)
        {
            month = m;
        }
        else
            cout<<"Nevaliden mesec"<<endl;
    }
    void setDay(int d)
    {
        if (d>=1 && d<=31)
        {
            day = d;
        }
        else
            cout<<"Nevaliden den"<<endl;
    }
    void setYear(int y)
    {
        year = y;
    }
    int getMonth() const
    {
        return month;
    }
    int getDay() const
    {
        return day;
    }
    int getYear() const
    {
        return year;
    }
    /*
    void read()
    {
        cout<<"Input day, month and year"<<endl;
        cin>>day>>month>>year;
    }
    */
};
struct Card
{
    char lastName [30];
    Date dateOfBirth;
public:
    Card(char* lastName = "Ivanov", int d = 1, int m = 1, int y = 2000)//:dateOfBirth(d,m,y)
    {
        strcpy(this->lastName, lastName);
        dateOfBirth.setDay(d);
        dateOfBirth.setMonth(m);
        dateOfBirth.setYear(y);
    }
    Card& operator=(const Card& other)
    {
        if(this!=&other)
        {
            strcpy(lastName, other.lastName);
            dateOfBirth.setDay(other.dateOfBirth.getDay());
            dateOfBirth.setMonth(other.dateOfBirth.getMonth());
            dateOfBirth.setYear(other.dateOfBirth.getYear());
        }
        return *this;
    }
    void printCard()
   {
       cout<<lastName<<" ";
       dateOfBirth.print();
       //cout<<endl;
   }
};

struct Zodiac
{
    char name[9];
    Date beginning;
    Date ending;
public:
    Zodiac(char* name = "oven", int d1 = 21, int m1 = 3, int y1 = 0, int d2 = 20, int m2 = 4, int y2 = 0)//:begging(d1,m1,y1), ending(d2,m2,y2)
    {
        strcpy(name, "oven");
        beginning.setDay(d1);
        beginning.setMonth(m1);
        beginning.setYear(y1);
        ending.setDay(d2);
        ending.setMonth(m2);
        ending.setYear(y2);
    }
    void print()
    {
        cout<<name<<" ";
        beginning.print();
        cout<<" ";
        ending.print();
        cout<<endl;
    }
};

class ListPerson
{
   Zodiac zodiacSigns[12] = {Zodiac("Oven", 21, 3, 0, 20, 4, 0),
                             Zodiac("Telec", 21, 4, 0, 21, 5, 0),
                             Zodiac("Bliznaci", 22, 5, 0, 21, 6 , 0),
                             Zodiac("Rak", 22, 6, 0, 22, 7, 0),
                             Zodiac("Lyv", 23, 7, 0, 23, 8, 0),
                             Zodiac("Deva", 24, 8, 0, 23, 9 ,0),
                             Zodiac("Vezni", 24, 9, 0, 23, 10, 0),
                             Zodiac("Skorpion", 24, 10, 0, 22, 11, 0),
                             Zodiac("Strelec", 23, 11, 0, 21, 12, 0),
                             Zodiac("Kozirog", 22, 12, 0, 20, 1, 0),
                             Zodiac("Vodolei", 21, 1, 0, 19, 2, 0),
                             Zodiac("Ribi", 20, 2, 0, 20, 3, 0)
                            };
   Card* cards;
   int size;
   int capacity;
public:
   ListPerson (int size = 0, int capacity = 2)
   {
       this->size = size;
       this->capacity = capacity;
       cards = new Card [capacity];
       assert(cards!=NULL);
   }
   ListPerson (const ListPerson& other)
   {
       size = other.size;
       capacity = other.capacity;
       cards = new Card [other.capacity];
       for(int i=0; i<size; i++)
       {
           cards[i] = other.cards[i];
       }
   }
   ~ListPerson()
   {
       delete [] cards;
   }
   ListPerson& operator=(const ListPerson& other)
   {
       if(this!=&other)
       {
           delete [] cards;
           size = other.size;
           capacity = other.capacity;
           cards = new Card [other.capacity];
           for(int i=0; i<size; i++)
           {
              cards[i] = other.cards[i];
           }
       }
       return *this;
   }
   void setSize(int _size)
   {
       if(_size > 0)
        size = _size;
       else
        cout<<"Nevaliden razmer"<<endl;
   }
   int getSize() const
   {
       return size;
   }
   void setCapacity(int _capacity)
   {
       if(_capacity > 0)
        capacity = _capacity;
       else
        cout<<"Nevaliden kapacitet"<<endl;
   }
   int getCapacity() const
   {
       return capacity;
   }
   void deleteCard(char* _lastName)
   {
       if(capacity > size*2)
       {
           capacity/=2;
           Card* temp = new Card[capacity];
           for(int i = 0; i<size; i++)
                temp[i] = cards[i];
           delete [] cards;
           cards = new Card[capacity];
           for(int i = 0; i<size; i++)
                cards[i] = temp[i];
           delete [] temp;
       }
       for(int i=0; i<size; i++)
       {
           if(!strcmp(cards[i].lastName, _lastName))
            {
                for(int j=i+1; j<size; j++)
                    cards[j-1] = cards[j];
                size--;
                break;
            }
       }
   }
   void addCard(Card c)
   {
       if(size == capacity)
       {
           Card* tmp = new Card[size];
           assert(tmp!=NULL);
           for(int i=0; i<size; i++)
           {
               tmp[i] = cards[i];
           }
           delete [] cards;
           capacity *=2; // capacity++;
           cards = new Card[capacity];
           for(int i=0; i<size; i++)
           {
               cards[i] = tmp[i];
           }
           delete [] tmp;
       }
       cards[size] = c;
       size++;
   }
   Card getCard(char* _lastName)
   {
       for(int i=0; i<size; i++)
       {
           if(!strcmp(cards[i].lastName,_lastName))
            return cards[i];
       }
   }
   ListPerson operator+(const ListPerson& other)
   {
       ListPerson temp;
       temp.setSize(size + other.size);
       temp.setCapacity(capacity + other.capacity);
       temp.cards = new Card[temp.getCapacity()];
       assert(temp.cards!=NULL);
       for(int i = 0; i < size; i++)
       {
           temp.cards[i] = cards[i];
       }
       for(int i=size;i<size+other.size;i++)
       {
           int j = 0;
           temp.cards[i] = other.cards[j];
       }
       return temp;
   }
   ListPerson operator*(const ListPerson& other)
   {
       int _size = 0, _capacity = 0;
       if(size < other.size)
       {
           _size = size;
           _capacity = capacity;
       }
       else
       {
           _size = other.size;
           _capacity = other.capacity;
       }
       ListPerson temp;
       temp.setSize(_size);
       temp.setCapacity(_capacity);
       temp.cards = new Card[temp.capacity];
       assert(temp.cards!=NULL);
       for(int i=0; i<size; i++)
       {
           for(int j=0; j<other.size; j++)
           {
               if(cards[i] == other.cards[j])
               {
                   int k=0;
                   temp.cards[k] = cards[i];
                   k++;
                   break;
               }
           }
       }
       return temp;
   }
   ListPerson operator-(const ListPerson& other)
   {
       ListPerson temp;
       temp.setSize(size + other.size);
       temp.setCapacity(capacity + other.capacity);
       temp.cards = new Card[temp.capacity];
       assert(temp.cards!=NULL);
       for(int i=0; i<size; i++)
       {
           temp.cards[i] = cards[i];
       }
       delete [] cards;
       for(int i=0; i<size; i++)
       {
           for(int j=0; j<other.size; j++)
           {
               if(temp.cards[i] == other.cards[j])
                deleteCard(other.cards[i].lastName);
           }
       }
       for(int i=size; i<size + other.size; i++)
       {
           int j=0;
           temp.cards[i] = other.cards[j];
           j++;
       }
       return temp;
   }
   Zodiac getZodiacalSign(char* name)
   {
       for(int i=0; i<size; i++)
       {
           if(!strcmp(cards[i].lastName, name))
           {
               for(int j = 0; j<12; j++)
               {
                   if((cards[i].dateOfBirth.getMonth() == zodiacSigns[j].beginning.getMonth() || cards[i].dateOfBirth.getMonth() == zodiacSigns[j].ending.getMonth())
                       && zodiacSigns[j].beginning.getDay() <= cards[i].dateOfBirth.getDay() && cards[i].dateOfBirth.getDay() <= zodiacSigns[j].ending.getDay())
                       return zodiacSigns[j];
               }
           }
       }
   }
   void printListPerson()
   {
       cout<<size<<" "<<capacity<<endl;
       for(int i=0; i<size; i++)
       {
           getCard(cards[i].lastName).printCard();
           cout<<endl;
       }
   }
};
int main()
{
    Date data1;
    Date data2(24,2,1996);
    Date data3(3,5,1968);
    data1.print();
    data2.print();
    cout<<data1.getDay()<<" ";
    cout<<data2.getMonth()<<" ";
    cout<<data3.getYear()<<endl;
    data1.setDay(23);
    data1.setMonth(5);
    data1.setYear(1997);
    data1.print();
}
