//Iveta Champoeva 71530 purva grupa, no zadachata mi ne e dovurshena

#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;
public:
    void copy(const Date& other)
    {
        day = other.day;
        month = other.month;
        year = other.year;
    }
    Date (int d = 1, int m = 1, int y = 2000)
    {
        day = d;
        month = m;
        year = y;
    }
    Date (const Date& other)
    {
        copy(other);
    }
    Date& operator=(const Date& other)
    {
        if(this != &other)
            copy(other);
        return *this;
    }
    void setDay(int d)
    {
        day = d;
    }
    int getDay() const
    {
        return day;
    }
    void setMonth(int m)
    {
        month = m;
    }
    int getMonth() const
    {
        return month;
    }
    void setYear(int y)
    {
        year = y;
    }
    int getYear() const
    {
        return year;
    }
    void read()
    {
        cout<<"Input day: ";
        cin>>day;
        cout<<"Input month: ";
        cin>>month;
        cout<<"Input year: ";
        cin>>year;
    }
    void print() const
    {
        cout<<day<<"-"<<month<<"-"<<year<<endl;
    }
    bool operator<(const Date& other)
    {
        if(month < other.month)
            return true;
        if(day < other.day)
            return true;
        return false;
    }
    bool operator>(const Date& other)
    {
        if(month > other.month)
            return true;
        if(day > other.day)
            return true;
        return false;
    }
    bool operator==(const Date& other)
    {
        if((day == other.day)&&(month == other.month)&&(year==other.year))
            return true;
        return false;
    }
};

struct Person
{
private:
    char* familyName;
    Date dateOfBirth;
    void copy(const Person& other)
    {
        familyName = new char[strlen(other.familyName)+1];
        assert(familyName!=NULL);
        strcpy(familyName,other.familyName);
        dateOfBirth = other.dateOfBirth;
    }
    void del()
    {
        delete [] familyName;
    }
public:
    Person(char* n = "", int d = 1, int m = 1, int y = 2000):dateOfBirth(d,m,y)
    {
        familyName = new char[strlen(n)+1];
        assert(familyName!=NULL);
        strcpy(familyName, n);
    }

    Person(const Person& other)
    {
        copy(other);
    }
    Person& operator=(const Person& other)
    {
        if(this != &other)
        {
            del();
            copy(other);
        }
        return *this;
    }
    ~Person()
    {
        del();
    }
    void setFamilyName(char* n)
    {
        del();
        familyName = new char[strlen(n)+1];
        assert(familyName!=NULL);
        strcpy(familyName, n);
    }
    char* getFamilyName() const
    {
        return familyName;
    }
    void setDateOfBirth(Date d)
    {
        dateOfBirth = d;
    }
    Date getDateOfBirth() const
    {
        return dateOfBirth;
    }
    void read()
    {
        cin.ignore();
        char buffer[30];
        cout<<"Input name: ";
        cin.getline(buffer,30);
        setFamilyName(buffer);
        cout<<"Input birthday: "<<endl;
        dateOfBirth.read();
    }
    void print() const
    {
        cout<<"Family name: "<<familyName<<"  Birthday: ";
        dateOfBirth.print();
    }
    bool operator==(const Person& other)
    {
        if((!strcmp(familyName,other.familyName))&&(dateOfBirth == other.dateOfBirth))
            return true;
        return false;
    }
    bool operator!=(const Person& other)
    {
        return strcmp(familyName,other.familyName);
    }
};
class ListPerson
{
private:
    Person* people;
    int size;
    int capacity;
    void copy(const ListPerson& other)
    {
        people = new Person [other.capacity];
        assert(people != NULL);
        size = other.size;
        capacity = other.capacity;
        for(int i = 0;i<size;i++)
        {
            people[i] = other.people[i];
        }
    }
    void del()
    {
        delete [] people;
    }
    bool isUnique()
    {
        for(int i=0;i<size-1;i++)
        {
            for(int j=i+1;j<size;j++)
            {
                if(people[i] == people[j])
                {
                    if(j == size-1)
                    {
                        size--;
                    }
                    else
                    {
                        for(int m=j;m<size-1;m++)
                        {
                            people[m] = people[m+1];
                        }
                    }
                }
            }
        }
    }
public:
    int equalElem(const ListPerson& other)
    {
        int sum = 0;
        for(int i=0;i<this->size;i++)
        {
            for(int j=0;j<other.size;j++)
            {
                if(people[i] == other.people[j])
                {
                    sum++;
                }
            }
        }
        return sum;
    }
    ListPerson()
    {
        size = 0;
        capacity = 1;
        people = new Person [capacity];
    }
    ~ListPerson()
    {
        del();
    }
    ListPerson(const ListPerson& other)
    {
        copy(other);
    }
    ListPerson& operator=(const ListPerson& other)
    {
        if(this != &other)
        {
            del();
            copy(other);
        }
        return *this;
    }
    void addPerson(const Person& p)
    {
        if(size == capacity)
        {
            Person* tmp = new Person[capacity];
            assert(tmp!=NULL);
            for(int i=0;i<size;i++)
            {
                tmp[i] = people[i];
            }
            delete [] people;
            capacity *= 2;
            people = new Person[capacity];
            assert(people!=NULL);
            for(int i=0;i<size;i++)
            {
                people[i] = tmp[i];
            }
            delete [] tmp;
        }
        people[size] = p;
        size++;
        isUnique();
    }
    void addPerson(char* n, int d, int m, int y)
    {
        if(size == capacity)
        {
            Person* tmp = new Person[capacity];
            assert(tmp!=NULL);
            for(int i=0;i<size;i++)
            {
                tmp[i] = people[i];
            }
            delete [] people;
            capacity *= 2;
            people = new Person[capacity];
            assert(people!=NULL);
            for(int i=0;i<size;i++)
            {
                people[i] = tmp[i];
            }
            delete [] tmp;
        }
        Person p(n,d,m,y);
        people[size] = p;
        size++;
        isUnique();
    }
    bool removePerson(char* name)
    {
        if(capacity > size*2)
        {
            Person* tmp = new Person [size];
            assert(tmp!=NULL);
            for(int i=0;i<size;i++)
            {
                tmp[i] = people[i];
            }
            delete [] people;
            capacity /= 2;
            people = new Person [capacity];
            assert(people!=NULL);
            for(int i=0;i<size;i++)
            {
                people[i] = tmp[i];
            }
            delete [] tmp;
        }
        bool flag = false;
        for(int i=0;i<size-1;i++)
        {
            if(!strcmp(people[i].getFamilyName(),name))
                flag = true;
            if(flag)
                people[i] = people[i+1];
        }
        if((people[size-1].getFamilyName()== name) || flag)
        {
            size--;
            return true;
        }
        return false;
    }
    Person& findPerson(char* name) const
    {
        for(int i=0;i<size;i++)
        {
            if(!strcmp(people[i].getFamilyName(),name))
            {
                return people[i];
            }
        }
    }
    void print() const
    {
        for(int i=0;i<size;i++)
        {
            cout<<"------------------------------------------------"<<endl;
            people[i].print();
        }
    }
    //obedinenie
    ListPerson operator+(const ListPerson& other)
    {
        Person* result = new Person[size + other.size];
        for(int i=0;i<size;i++)
        {
            result[i] = people[i];
        }
        for(int j=0, i=size; i<(size + other.size);i++, j++)
        {
            result[i] = other.people[j];
        }
        ListPerson l;
        for(int i=0;i<(size+other.size);i++)
        {
            l.addPerson(result[i]);
        }
        delete [] result;
        l.isUnique();
        return l;
    }
    //sechenie
    ListPerson operator-(const ListPerson& other)
    {
        int n = equalElem(other);
        Person* tmp = new Person[n];
        assert(tmp!=NULL);
        int k=0;
        for(int i=0;i<size;i++)
        {
            for(int j=0;j<other.size;j++)
            {
                if(people[i] == other.people[j])
                {
                    tmp[k] = people[i];
                    k++;
                }
            }
        }
        ListPerson r;
        {
            for(int i=0;i<n;i++)
            {
                r.addPerson(tmp[i]);
            }
        }
        delete [] tmp;
        return r;
    }
    //razlika
    ListPerson operator/(const ListPerson& other)
    {
        ListPerson l = (*this) - other;
        int n = equalElem(other);
        Person* tmp = new Person[size-n];
        assert(tmp!=NULL);
        int k=0;
        for(int i=0;i<size;i++)
        {
            for(int j=0;j<l.size;j++)
            {
                if(people[i] != l.people[j])
                {
                    tmp[k] = people[i];
                    k++;
                }
            }
        }
        ListPerson r;
        {
            for(int i=0;i<k;i++)
            {
                r.addPerson(tmp[i]);
            }
        }
        delete [] tmp;
        return r;
    }
};

struct Zodiac
{
private:
    char name[20];
    Date start;
    Date end;
};

int main()
{
    ListPerson listOfP1;
    listOfP1.addPerson("Ivanov",4,5,2010);
    listOfP1.addPerson("Petrov",6,7,1999);
    listOfP1.addPerson("Atanasov",16,5,1995);
    ListPerson listOfP2;
    listOfP2.addPerson("Vladimirov",15,12,1995);
    listOfP2.addPerson("Atanasov",16,5,1995);
    listOfP2.addPerson("Svilenov",20,7,1980);
    ListPerson listOfP3 = listOfP1 + listOfP2;
    ListPerson listOfP4 = listOfP1 - listOfP2;
    cout<<"\nObedinenie: \n";
    listOfP3.print();
    cout<<"\nSechenie: \n";
    listOfP4.print();
    ListPerson listOfP5 = listOfP1 / listOfP2;
    cout<<"\nRazlika: \n";
    listOfP5.print();
    return 0;
}
