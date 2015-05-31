#include <iostream>
#include <cassert>
#include <cstring>

using namespace std;

struct Date
{
	int day,
		month,
		year;

	Date()
	{
		day = 0;
		month = 0;
		year = 0;
	}
	Date(int day, int month, int year)
	{
		this->day = day;
		this->month = month;
		this->year = year;
	}
	Date(const Date& other)
	{
		day = other.day;
		month = other.month;
		year = other.year;
	}
	Date& operator=(const Date& other)
	{
		if (this != &other)
		{
			day = other.day;
			month = other.month;
			year = other.year;
		}
		return *this;
	}
	bool operator >(const Date& other)
	{
	    if (this->month > other.month) return true;
	    else if (this->month == other.month)
        {
            if(this->day > other.day) return true;
            else return false;
        }
	    else return false;
	}
	bool operator <(const Date& other)
	{
	    if (this->month < other.month) return true;
	    else if (this->month == other.month)
        {
            if(this->day < other.day) return true;
            else return false;
        }
	    else return false;
	}
	bool operator==(const Date& other)
    {
        if((day == other.day)&&(month == other.month)) return true;
        else return false;
    }

	void print()
	{
		cout << day << "." << month << "." << year << endl;
	}
};

struct Zodiac
{
    char* name;
    Date starting;
    Date ending;
};

const Zodiac Zod[12] = {{"Aries", {21, 3, 0}, {19, 4, 0}}, {"Taurus", {20, 4, 0}, {20, 5, 0}}, {"Gemini", {21, 5, 0}, {20, 6, 0}},{"Cancer", {21, 6, 0}, {22, 7, 0}},
{"Leo", {23, 7, 0}, {22, 8, 0}},{"Virgo", {23, 8, 0}, {22, 9, 0}}, {"Libra", {23, 9, 0}, {22, 10, 0}}, {"Scorpio", {23, 10, 0}, {21, 11, 0}},
{"Sagittarius", {24, 11, 0}, {21, 12, 0}}, {"Capricorn", {22, 12, 0}, {19, 1, 0}}, {"Aquarius", {20, 1, 0}, {18, 2, 0}}, {"Pisces", {19, 2, 0}, {20, 3, 0}}};

class Person
{
    public:
	char* familyName;
	Date date;
	Person(char* familyName = "Default", Date date = {1,1,1})
	{
		this->familyName = new char[strlen(familyName) + 1];
		assert(this->familyName != NULL);
		strcpy(this->familyName, familyName);
		this->date = date;
	}
	Person(const Person& other)
	{
		familyName = new char[strlen(other.familyName) + 1];
		assert(familyName != NULL);
		strcpy(familyName, other.familyName);
		date = other.date;
	}
	~Person()
	{
		delete[]familyName;
	}
	Person& operator=(const Person& other)
	{
		if (this != &other)
		{
			delete[]familyName;
			familyName = new char[strlen(other.familyName) + 1];
			assert(familyName != NULL);
			strcpy(familyName, other.familyName);
			date = other.date;
		}
		return *this;
	}
	void print()
	{
		cout << familyName << ", ";
		date.print();
	}
};

class ListPerson
{
	Person* database;
	int capacity;
	int size;
public:
	ListPerson()
	{
		size = 0;
		capacity = 1;
		database = new Person[capacity];
	}
	ListPerson(Person* database, int capacity, int size)
	{
		this->database = new Person[size];
		assert(this->database != NULL);
		for (int i = 0; i < size; i++)
		{
			this->database[i] = database[i];
		}
		this->size = size;
		this->capacity = capacity;
	}
	ListPerson(const ListPerson& other)
	{
		database = new Person[other.size];
		assert(database != NULL);
		for (int i = 0; i < other.size; i++)
		{
			database[i] = other.database[i];
		}
		size = other.size;
		capacity = other.capacity;
	}
	~ListPerson()
	{
		delete[]database;
	}
	ListPerson& operator=(const ListPerson& other)
	{
		if (this != &other)
		{
			delete[]database;
			database = new Person[other.size];
			assert(database != NULL);
			for (int i = 0; i < other.size; i++)
			{
				database[i] = other.database[i];
			}
			size = other.size;
			capacity = other.capacity;
		}
		return *this;

	}
	void addPerson(const Person& other)
	{
		{

			if (size == capacity)
			{
				capacity *= 2;
				Person* temp = new Person[size];
				assert(temp != NULL);
				for (int i = 0; i < size; i++)
				{
					temp[i] = database[i];
				}

				delete[] database;

				database = new Person[capacity];
				assert(database != NULL);

				for (int i = 0; i < size; i++)
				{
					database[i] = temp[i];
				}

				delete[] temp;
			}
			database[size] = other;
			size++;
		}
	}

	void removePerson(char* familyName)
	{

		if (capacity > size * 2)
		{
			capacity /= 2;
			Person* temp = new Person[size];
			for (int i = 0; i < size; i++)
			{
				temp[i] = database[i];
			}

			delete[] database;
			database = new Person[capacity];

			for (int i = 0; i < size; i++)
			{
				database[i] = temp[i];
			}
			delete[] temp;
		}

		for (int i = 0; i<size; i++)
		{
			if (strcmp(database[i].familyName, familyName) == 0)
			{
				for (int j = i + 1; j < size; ++j)
				{
					database[j - 1] = database[j];
				}
			}
		}

		size--;
	}

	Person& getPerson(char* familyName)
	{
		for (int i = 0; i < size; i++)
		{
			if (strcmp(database[i].familyName, familyName) == 0) return this->database[i];
		}
	}
	ListPerson operator+(ListPerson& other)
	{

		Person* newdb = new Person[this->size + other.size];

		for (int i = 0; i < this->size; i++)
		{
			newdb[i] = this->database[i];
		}
		for (int i = this->size, j = 0; i < this->size + other.size; i++, j++)
		{
			newdb[i] = other.database[j];
		}

		ListPerson* result = new ListPerson(newdb, this->size + other.size, this->capacity + other.capacity);
		delete[]newdb;
		cout << "Lists merged: " << endl;
		result->print();

		return *result;
	}

	ListPerson& sectionList(ListPerson& other)
	{
		int newSize = 0;
		for (int i = 0; i < this->size; i++)
		{
			for (int j = 0; j < other.size; j++)
			{
				if (strcmp(database[i].familyName, other.database[j].familyName) == 0) newSize++;
			}
		}

		Person* newdb = new Person[newSize];
		int temp_size = 0;

		for (int i = 0; i < this->size; i++)
		{
			for (int j = 0; j < other.size; j++)
			{
				if (strcmp(database[i].familyName, other.database[j].familyName) == 0)
				{
					newdb[temp_size] = database[i];
					temp_size++;
				}
			}
		}

        ListPerson* result = new ListPerson;
        for(int i = 0 ; i < newSize; i++)
        {
            result->addPerson(newdb[i]);
        }
        delete[]newdb;
        cout << "Section Found: " << endl;
        result->print();
        return *result;
	}

	ListPerson& differenceList(ListPerson& other)
	{
		int newSize = 0;
		for (int i = 0; i < this->size; i++)
		{
			for (int j = 0; j < other.size; j++)
			{
				if (strcmp(database[i].familyName, other.database[j].familyName) != 0) newSize++;
			}
		}

		Person* newdb = new Person[newSize];

		ListPerson section;
		section = sectionList(other);

		ListPerson all;
		all = ListPerson::operator+(other);

        int temp_size = 0;

		for (int i = 0; i < all.size; i++)
		{
			for (int j = 0; j < section.size; j++)
			{
				if (strcmp(all.database[i].familyName, section.database[j].familyName) != 0)
                {
                    newdb[temp_size] = all.database[i];
                    temp_size++;
                }
			}
		}

		ListPerson* result = new ListPerson(newdb, newSize, this->capacity);
        delete[]newdb;
        cout << "Difference found:" << endl;
		result->print();
        return *result;
	}

	void print()
	{
		for (int i = 0; i < size; i++)
		{
			database[i].print();
		}
	}

	Zodiac getZodiac(char* familyName)
	{
	    Person temp = getPerson(familyName);
        for(int i = 0; i < 12; i++)
        {
            if((temp.date > Zod[i].starting && temp.date < Zod[i].ending) || temp.date == Zod[i].starting || temp.date == Zod[i].ending )
               {
                 return Zod[i];
               }
        }
	}

};
int main()
{
	Person p1("Petrova", { 2, 3, 1995 });
	Person p2("Ivanov", { 5, 3, 1996 });

	ListPerson l1;
	l1.addPerson(p1);
	cout << "l1: " << endl;
	l1.print();


	ListPerson l2;
	l2.addPerson(p1);
	l2.addPerson(p2);
	cout << "l2: " << endl;
	l2.print();

	ListPerson united = l1 + l2;

	ListPerson section = l1.sectionList(l2);

	ListPerson difference = l1.differenceList(l2);

    cout << l1.getZodiac("Petrova").name;
	return 0;
}
