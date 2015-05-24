
#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;

struct Date
{
	int day,
		month,
		year;
};

struct Person
{
	char* familyName;
	Date dateOfBirth;
};


class ListPerson
{
private:
	Person* database;
	int size;
	int capacity;
public:
	ListPerson()
	{
		capacity = 1;
		size = 0;
		database = new Person[capacity];
	}
	ListPerson(Person* database, int size, int capacity)
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
	~ListPerson()
	{
		delete[]database;
	}
	ListPerson(const ListPerson &other)
	{
		database = new Person[other.size];
		assert(database != NULL);
		for (int i = 0; i < size; i++)
		{
			database[i] = other.database[i];
		}
		size = other.size;
		capacity = other.capacity;

	}
	ListPerson &operator = (const ListPerson &other)
	{
		if (this != &other)
		{
			delete[]database;
			database = new Person[other.size];
			assert(database != NULL);
			for (int i = 0; i < size; i++)
			{
				database[i] = other.database[i];
			}
			size = other.size;
			capacity = other.capacity;
		}
		return *this;
	}


	void print()
	{
		for (int i = 0; i < size; i++)
		{
			cout << database[i].familyName << " " << database[i].dateOfBirth.day << "." << database[i].dateOfBirth.month
				<< "." << database[i].dateOfBirth.year <<  endl;
		}
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
	ListPerson& operator+(ListPerson& other)
	{

        Person* newdb = new Person[this->size + other.size];

        for (int i = 0; i < this->size; i++)
        {
            newdb[i] = this->database[i];
        }
        for(int i = this->size, j =0; i < this->size+other.size; i++, j++)
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

		for (int i = 0; i < this->size; i++)
		{
			for (int j = 0; j < other.size; j++)
			{
				if (strcmp(database[i].familyName, other.database[j].familyName) == 0)
                {
                    newdb[i] = database[i];
                }
			}
		}

		ListPerson* result = new ListPerson(newdb, newSize, this->capacity + other.capacity);
        delete[]newdb;
        cout << "Section found:" << endl;
		result->print();
        return *result;
	}

	void set_size(int size)
	{
		this->size = size;
	}
	void set_capacity(int capacity)
	{
		this->capacity = capacity;
	}
	void set_database(Person* database)
	{
	    delete[]database;
	    this->database = new Person[capacity];
		assert(this->database != NULL);
		for (int i = 0; i < size; i++)
		{
			this->database[i] = database[i];
		}
	}
	
};



int main()
{
Person p1 = {"Petrova", {2,3,1995}};
Person p2 = {"Ivanov", {5,3,1996}};
ListPerson l1;
l1.addPerson(p1);

ListPerson l2;
l2.addPerson(p1);
l2.addPerson(p2);

ListPerson c;
c = l1 + l2;

ListPerson d;
d = l1.sectionList(l2);



system("pause");
return 0;

}
