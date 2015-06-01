#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;

class Data
{
private:
    int day;
    int month;
    int year;
public:
    void setDay (int day)
    {
        if (this->day > 0 || this->day <= 31)
            this->day = day;
    }

    int getDay () const
    {
        return day;
    }

    void setMonth (int month)
    {
        if (this->month > 0 || this->month <= 12)
            this->month = month;
    }

    int getMonth () const
    {
        return month;
    }

    void setYear (int year)
    {
        if (this->year >= 0)
            this->year = year;
    }

    int getYear () const
    {
        return year;
    }

    Data (int day = 1, int month = 1, int year = 2000)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }

    void print () const
    {
        cout << "Day: " << day << endl;
        cout << "Month: " << month << endl;
        cout << "Year: " << year << endl;
        cout << endl;
    }
};

class Card
{
private:
    char* name;
    Data date;
public:
    Card (char* name = "name", int day = 5, int month = 1, int year = 2000)
    {
        this->name = new char [strlen(name) + 1];
        assert (this->name != NULL);
        strcpy (this->name, name);

        date = Data (day, month, year);
    }

    ~Card ()
    {
        delete [] name;
    }

    Card (const Card& other)
    {
        name = new char [strlen (other.name) + 1];
        assert (name != NULL);
        strcpy (name, other.name);

        date = other.date;
    }

    Card &operator = (const Card& other)
    {
        if (this != &other)
        {
            delete [] name;

            name = new char [strlen (other.name) + 1];
            assert (name != NULL);
            strcpy (name, other.name);

            date = other.date;
        }
        return *this;
    }

    void setName (char* name)
    {
        delete [] this->name;
        this->name = new char [strlen(name) + 1];
        assert (this->name != NULL);
        strcpy (this->name, name);
    }

    char* getName () const
    {
        return name;
    }

    void setDate (Data date)
    {
        this->date = date;
    }

    Data getDate () const
    {
        return date;
    }

    void printCard() const
        {
            cout << "\n-------------Card--------------\n";
            cout << "Name: " << name << endl;
            date.print();
            cout << "-------------------------------\n";
            cout << endl;
        }
};

class Zodiac
{
private:
    Data zodia;
public:
    Zodiac (Data zodia)
    {
        if (zodia.getDay() >= 21 && zodia.getMonth() == 3 || zodia.getDay() <=21 && zodia.getMonth() == 4)
            cout << "oven";
        else if (zodia.getDay() >= 22 && zodia.getMonth() == 4 || zodia.getDay() <=20 && zodia.getMonth() == 5)
            cout << "telec";
        else if (zodia.getDay() >= 21 && zodia.getMonth() == 5 || zodia.getDay() <=21 && zodia.getMonth() == 6)
            cout << "bliznaci";
        else if (zodia.getDay() >= 21 && zodia.getMonth() == 6 || zodia.getDay() <=21 && zodia.getMonth() == 7)
            cout << "rak";
        else if (zodia.getDay() >= 22 && zodia.getMonth() == 7 || zodia.getDay() <=23 && zodia.getMonth() == 8)
            cout << "luv";
        else if (zodia.getDay() >= 23 && zodia.getMonth() == 8 || zodia.getDay() <=22 && zodia.getMonth() == 9)
            cout << "deva";
        else if (zodia.getDay() >= 23 && zodia.getMonth() == 9 || zodia.getDay() <=22 && zodia.getMonth() == 10)
            cout << "vezni";
        else if (zodia.getDay() >= 23 && zodia.getMonth() == 10 || zodia.getDay() <=21 && zodia.getMonth() == 11)
            cout << "skorpion";
        else if (zodia.getDay() >= 22 && zodia.getMonth() == 11 || zodia.getDay() <=21 && zodia.getMonth() == 12)
            cout << "strelec";
        else if (zodia.getDay() >= 22 && zodia.getMonth() == 12 || zodia.getDay() <=20 && zodia.getMonth() == 1)
            cout << "kozirog";
        else if (zodia.getDay() >= 21 && zodia.getMonth() == 1 || zodia.getDay() <=19 && zodia.getMonth() == 2)
            cout << "vodolei";
        else if (zodia.getDay() >= 20 && zodia.getMonth() == 2 || zodia.getDay() <=20 && zodia.getMonth() == 3)
            cout << "ribi";
    }
};

class ListPerson
{
private:
    Card* persons;
    int max_size;
    int real_size;
    void delListPerson ()
    {
        delete [] persons;
    }
    void cpyListPerson (const ListPerson& other)
    {
        real_size = other.real_size;
        max_size = other.max_size;
        persons = new Card [max_size];
        assert (persons != NULL);
        for (int i = 0; i < real_size; i++)
        {
            persons[i] = other.persons[i];
        }
    }
public:
    ListPerson ()
    {
        this->max_size = 5;

        persons = new Card [5];
        assert (persons != NULL);

        this->real_size = 0;
    }

    ListPerson (const ListPerson& other)
    {
        cpyListPerson (other);
    }

    ~ListPerson ()
    {
        delListPerson ();
    }

    ListPerson &operator=(const ListPerson& other)
    {
        if (this != &other)
        {
            delListPerson ();
            cpyListPerson (other);
        }
    }

    void setMaxSize(int max_size)
	{
		this -> max_size = max_size;
	}

	int getMaxSize()const
	{
		return  max_size;
	}

	void setRealSize(int real_size)
	{
		this -> real_size = real_size;
	}

	int getRealSize () const
	{
		return real_size;
	}

    void printListPerson ()
    {
        for (int i = 0; i < this->getRealSize(); i++)
        {
           persons[i].printCard();
        }
    }

    void addCard (const Card& other)
    {
        if (real_size == max_size)
        {
            max_size *= 2;
            Card* tmp = new Card [max_size];
            assert (tmp != NULL);
            for (int i = 0; i < real_size; i++)
            {
                tmp[i] = persons[i];
            }
            delete [] persons;
            for (int i = 0; i < real_size; i++)
            {
                persons[i] = tmp[i];
            }
            delete [] tmp;
        }
        persons [real_size] = other;
        real_size++;
    }

    bool removeCard (char* name)
    {
        if (max_size > real_size*2)
        {
            max_size /= 2;
            Card* tmp = new Card [max_size];
            assert (tmp != NULL);
            for (int i = 0; i < real_size; i++)
            {
                tmp[i] = persons[i];
            }
            delete [] persons;
            for (int i = 0; i < real_size; i++)
            {
                persons[i] = tmp[i];
            }
            delete [] tmp;
        }
        for (int i = 0; i < real_size ; i++)
        {
            if (!(strcmp(name, persons[i].getName())))
            {
                for (int j = i; j < real_size - 1; j++)
                    persons[i] = persons[i + 1];
                real_size--;
                return true;
            }
        }
        return false;
    }

    void getCard (char* name)
    {
        bool flag = false;
        for (int i = 0; i < real_size; i++)
        {
            if (!(strcmp(name, persons[i].getName())))
            {
                persons[i].printCard();
                flag = true;
            }
        }

        if (!flag)
        {
            cout << "There is no card with this last name";
        }
    }

    void whichZodia (char* name)
    {
        bool flag = false;
        for (int i = 0; i < real_size; i++)
        {
            if (!(strcmp(name, persons[i].getName())))
            {
                Zodiac (persons[i].getDate());
                flag = true;
            }
        }

        if (!flag)
        {
            cout << "There is no card with this last name";
        }
    }

    Card* obedinenie (const ListPerson& other)
    {
        int newSize = this->getMaxSize() + other.max_size;
        int newRealSize = this->getRealSize() + other.real_size;
        Card* tmp = new Card [newSize];

        for (int i = 0; i < this->getRealSize(); i++)
        {
            tmp[i] = this->persons[i];
        }

        for (int k = this->getRealSize(); k < newRealSize; k++)
        {
            for (int j = 0; j < other.real_size;  j++)
            {
                tmp[k] = other.persons[j];
            }
        }
        return tmp;
    }


    ListPerson& razlika (const ListPerson& other)
    {
        for (int i = 0; i < this->getRealSize(); i++)
        {
            for (int j = 0; j < other.real_size; j++)
            {
                if(!(strcmp (persons[i].getName(), other.persons[j].getName())))
                {
                    removeCard(persons[i].getName());
                }
            }
        }
        return *this;
    }

    Card* sechenie (const ListPerson& other)
    {
        Card* result = new Card [this->getRealSize() + other.real_size];
        assert (result != NULL);
        for (int i = 0, j = 0, k=0; i < this->getRealSize(); i++, j++, k++)
        {
            for (int j = 0; j < other.real_size; j++)
            {
                if(!(strcmp (persons[i].getName(), other.persons[j].getName())))
                    {
                        result[k] = persons[i];
                    }
            }
        }
        return result;
    }
};

int main ()
{
     Card b1("kalina", 29, 04, 1995);
     Card c1 ("poli", 28, 6, 1768);
     Card d1 ("viki", 24 ,8, 4534);

     Card e1 ("tera", 7, 8, 446);
     Card e2("nia", 6, 12,54654);
     Card e3 ("viki", 1, 2, 4534);

     ListPerson a;
     a.addCard(b1);
     a.addCard(c1);
     a.addCard(d1);

     //a.printListPerson();
     //a.removeCard("viki");
     //a.printListPerson();
     //a.getCard("ds");
     //a.whichZodia ("kalina");

     ListPerson b;
     b.addCard(e1);
     b.addCard(e2);
     b.addCard(e3);
     //b.printListPerson();
     //b.whichZodia("tera");
     //b.removeCard("nia");
     //b.printListPerson();

     //a.razlika(b);
     //a.printListPerson();

     return 0;
}


