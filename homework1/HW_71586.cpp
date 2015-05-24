//2зад
#include <iostream>
using namespace std;

struct Date
{
	int day;
	int month;
	int year;
	Date()
	{
		day = 1;
		month = 1;
		year = 1990;
	}
	Date (int day, int month, int year)
	{
		this -> day = day;
		this -> month = month;
		this -> year = year;
	}
	
	bool operator > (Date& other)
	{
		
		if( year > other.year)
		return true;
		else
			if ( month > other.month)
				return true;
			else
			{
				if ( day > other.day)
					return true;
				else
					return false;
			}
			

	}

	bool operator < (Date& other)
	{
		
		if( year < other.year)
		return true;
		else
			if ( month < other.month)
				return true;
			else
			{
				if ( day < other.day)
					return true;
				else
					return false;
			}
			

	}

	Date& operator = (const Date& other)
	{
		this -> day = other.day;
		this -> month = other.month;
		this -> year = other.year;
		return* this;
	}
	
	const void printDate () 
	{
		cout << day << endl << month << endl << year << endl;
	}
};

struct BusinessCard
{
	char lastName[30];
	Date birthday;

	BusinessCard()
	{
		Date A(11,11,2011);
		strcpy( this -> lastName, "gqgqgq");
		this -> birthday = A;
	}
	void printCard ()
	{
		cout << lastName << endl ;
		birthday.printDate();
	}
	
};

class ListPerson 
{
public:

	ListPerson()
	{
		this -> size = 0;
		this -> capacity = 1;
		this -> cardArray = new BusinessCard[capacity];
	}
	ListPerson (const ListPerson& other)
	{
		this -> size = other.size;
		this -> capacity = other.capacity;
		cardArray = new BusinessCard[capacity];
		for(int i = 0; i < size; i++)
		{
			cardArray[i] = other.cardArray[i];
		}
	}
	~ListPerson()
	{
		delete [] cardArray;
	}
	ListPerson& operator = (const ListPerson& other)
	{

		delete [] cardArray;
		this -> size = other.size;
		this -> capacity = other.capacity;
		cardArray = new BusinessCard[capacity];
		for(int i = 0; i < size; i++)
		{
			cardArray[i] = other.cardArray[i];
		}
	}
	
	void addBusinessCard(const BusinessCard& other)
	{
		if(size == capacity)
		{
		    BusinessCard* temp = cardArray;
		    cardArray = new BusinessCard[capacity*2];
		    for(int i = 0; i< size; i++)
		    {
		    cardArray[i] = temp[i];
		    }
			delete [] temp;
			capacity = capacity*2;
		}
		cardArray[size++] = other;

	}

	void removeBusinesCard (const BusinessCard& otherLastName)
	{
		for(int i=0 ; i < size; i++)
		{
			if( cardArray[i].lastName = otherLastName)
				for (int j= i+1 ; j < size; j++)
				{
					cardArray[j] = cardArray[j+1];
				}
				size --;
				
		}
	}
	BusinessCard findBusinessCard(char lastName)
	{
		for(int i = 0; i<size; i++)
		{
			if(cardArray[i].lastName = lastName)
				return cardArray[i];
		}
	}

private:

	BusinessCard* cardArray;
	int size;
	int capacity;
};

int main()
{
	
	Date B(25, 11, 2000);
	B.printDate();
	BusinessCard Misho;
	Misho.printCard();
	return 0;
}