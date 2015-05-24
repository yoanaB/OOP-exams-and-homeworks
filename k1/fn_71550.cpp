// Наследяване, Абстракция, Капсулация, Полиморфизъм

#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;

class Programmer
{
private:
    char* name;
    int iq;
    double salary;
public:
    Programmer()
    {
        name = "";
        iq = 0;
        salary = 0;
    }
    Programmer(char* name, int iq, double salary)
    {
        this->name = new char[strlen(name) + 1];
        assert(this->name != NULL);
        strcpy(this->name, name);

        this-> iq = iq;
        this->salary = salary;
    }
    Programmer(const Programmer& other)
    {
        name = new char[strlen(other.name) + 1];
        assert(name != NULL);
        strcpy(name, other.name);

        iq = other.iq;
        salary = other.salary;
    }
    ~Programmer()
    {
        delete[]name;
    }
    Programmer& operator=(const Programmer& other)
    {
        delete[]name;
        name = new char[strlen(other.name) + 1];
        assert(name != NULL);
        strcpy(name, other.name);

        iq = other.iq;
        salary = other.salary;
    }
    void set_name(char* name)
    {
        delete[]name;
        this->name = new char[strlen(name) + 1];
        assert(this->name != NULL);
        strcpy(this->name, name);
    }
    char* get_name()const
    {
        return name;
    }
    void set_iq(int iq)
    {
        this-> iq = iq;
    }
    int get_iq()const
    {
        return iq;
    }
    void set_salary(double salary)
    {
        this->salary = salary;
    }
    double get_salary()const
    {
        return salary;
    }
    void print()
    {
        cout <<"Name: " << name << " " << "Iq: "<< iq << " " << "Salary: " << salary << endl;
    }
    bool operator<(const Programmer& other)
    {
        return this->iq < other.iq;
    }
    bool operator>(const Programmer& other)
    {
        return this->iq > other.iq;
    }
    bool operator==(const Programmer& other)
    {
        return this->iq == other.iq;
    }

};

class Team
{
private:
	Programmer* database;
	int size;
	int capacity;
public:
	Team()
	{
		capacity = 1;
		size = 0;
		database = new Programmer[capacity];
	}
	Team(Programmer* database, int size, int capacity)
	{
		this->database = new Programmer[size];
		assert(this->database != NULL);
		for (int i = 0; i < size; i++)
		{
			this->database[i] = database[i];
		}
		this->size = size;
		this->capacity = capacity;
	}
	~Team()
	{
		delete[]database;
	}
	Team(const Team& other)
	{
		database = new Programmer[other.size];
		assert(database != NULL);
		for (int i = 0; i < size; i++)
		{
			database[i] = other.database[i];
		}
		size = other.size;
		capacity = other.capacity;

	}
	Team &operator=(const Team& other)
	{
		if (this != &other)
		{
			delete[]database;
			database = new Programmer[other.size];
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

	void addProgrammer(const Programmer& other)
	{
		{

			if (size == capacity)
			{
			    capacity *= 2;
				Programmer* temp = new Programmer[size];
				assert(temp != NULL);
				for (int i = 0; i < size; i++)
				{
					temp[i] = database[i];
				}

				delete[] database;

				database = new Programmer[capacity];
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


	void removeProgrammer(char* name)
	{

	    if (capacity > size * 2)
		{
		    capacity /= 2;
			Programmer* temp = new Programmer[size];
			for (int i = 0; i < size; i++)
			{
				temp[i] = database[i];
			}

			delete[] database;
			database = new Programmer[capacity];

			for (int i = 0; i < size; i++)
			{
				database[i] = temp[i];
			}
			delete[] temp;
		}

		for (int i = 0; i<size; i++)
		{
			if (strcmp(database[i].get_name(), name) == 0)
			{
                for (int j = i + 1; j < size; ++j)
                {
                    database[j - 1] = database[j];
                }
            }
        }

        size--;
	}

	Programmer& getProgrammer(char* name)
	{
	    for (int i = 0; i<size; i++)
		{
			if (strcmp(database[i].get_name(), name) == 0) return database[i];
		}
	}

	void print()
	{
		for (int i = 0; i < size; i++)
		{
		    database[i].print();
		}
	}
	void sortProgrammer()
    {
        bool is_not_sorted = true;
        while(is_not_sorted)
        {
            is_not_sorted = false;
            for(int i = 0; i < size - 1; i++)
            {
                if(database[i].get_iq() > database[i+1].get_iq())
                {
                    Programmer temp = database[i];
                    database[i] = database[i+1];
                    database[i+1] = temp;
                    is_not_sorted = true;
                }
            }
        }
    }
    Team& operator-=(const Team& other)
    {
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < other.size; j++)
            {
               if((strcmp(this->database[i].get_name(), other.database[i].get_name()) == 0) && this->database[i].get_iq() == other.database[i].get_iq())
               {
                   removeProgrammer(database[i].get_name());
               }
            }

        }
        return *this;
    }



    Programmer* get_database()const
    {
        return database;
    }
    void set_database(Programmer* database)
    {
        delete[]database;
        for (int i = 0; i < size; i ++)
        {
            this->database[i] = database[i];
        }
    }
    int get_size()
    {
        return size;
    }

};
/*
class Company
{
    private:
    Team* database;
    int size;
    int capacity;
public:
	Company()
	{
		capacity = 1;
		size = 0;
		database = new Team[capacity];
	}
	Company(Team* database, int size, int capacity)
	{
		this->database = new Team[size];
		assert(this->database != NULL);
		for (int i = 0; i < size; i++)
		{
		    for(int j = 0; j < database[i].get_size(); j++)
            {
                this->database[i].set_database(database[i].get_database());
            }
		}
		this->size = size;
		this->capacity = capacity;
	}
	~Company()
	{
		for(int i = 0; i < size; i++)
        {
            delete[]database[i].get_database();
        }
	}
	Company(const Company& other)
	{
		database = new Team[other.size];
		assert(database != NULL);
		for (int i = 0; i < size; i++)
		{
		    for(int j = 0; j < database[i].get_size(); j++)
            {
                database[i].set_database(other.database[i].get_database());
            }
		}
		size = other.size;
		capacity = other.capacity;

	}
	Company &operator=(const Company& other)
	{
		if (this != &other)
		{
			for(int i = 0; i < size; i++)
            {
                delete[]database[i].get_database();
            }
			database = new Team[other.size];
			assert(database != NULL);
			for (int i = 0; i < size; i++)
		{
		    for(int j = 0; j < database[i].get_size(); j++)
            {
                database[i].set_database(other.database[i].get_database());
            }
		}
			size = other.size;
			capacity = other.capacity;
		}
		return *this;
	}

    void print()
    {
        for (int i =0; i< size; i++)
        {
            database[i].print();
        }
    }

    double AverageIq()
    {
    double sum = 0;
        for(int i = 0; i< size; i++)
        {
            for(int j = 0; j < database[i].get_size; j++)
            {
                sum + = database[i].database[j].get_iq();
            }
        }

    }
};
*/
int main()
{
    Programmer p1;
    Programmer p2("Ivan", 7, 5);
    p2.print();
    p1.set_iq(19);
    if(p1 > p2) cout << "Yes" << endl;
    Team t;
    t.addProgrammer(p2);
    t.addProgrammer(p1);
    t.sortProgrammer();
    t.print();
    Team t2;
    t2.addProgrammer(p2);
    t -= t2;
    t.print();
    Team arr[2];
    arr[0] = t;
    arr[1] = t2;

    //Company c;
    //c.print();

    return 0;
}
