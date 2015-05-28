#include <iostream>
#include <new>
#include <cstdlib>
#include "Rockstar.cpp"

using namespace std;

class Band
{
private:
	int length;
	Rockstar *stars;
public:
	Band(int len);
	Band(Rockstar *);
	~Band();
	Band(const Band &);
	Band operator=(const Band &);

	void addStar(Rockstar r);
	void removeStar(char *n);
	Rockstar getStar(char *n);
	void print();

	Band operator+=(const Band &);
	Rockstar pickFrontman();
};

Band::Band(int len)
{
	length = len;
	stars = new Rockstar(length);
	for(int i = 0; i < length; i++)
	{
		*(stars + i) = Rockstar(20);
	}
}
// []??
Band::~Band()
{
	delete stars;
}
// no
// - 0.2
Band::Band(const Band &b)
{
	stars = b.stars;
}
//oh .. 
// - 0.2
Band Band::operator=(const Band &b)
{
	return Band(b.stars);
}

// wut??
Band::Band(Rockstar *s)
{
	stars = s;
}

// no.. 
// - 0.2
void Band::addStar(Rockstar r)
{
	*(stars + length + 1) = r;
	length++;
}

// ... 
// - 0.2
void Band::removeStar(char *n)
{
	for(int i = 0; i < length; i++)
	{
		if((*(stars + i)).getName() == *n)
		{
			*(stars + i) = NULL;
			break;
		}

	}
}

Rockstar Band::getStar(char *n)
{
	for(int i = 0; i < length; i++)
	{
		if((*(stars + i)).getName() == *n)
		{
			return *(stars + i);
		}
	}

}

void Band::print()
{
	for(int i = 0; i < length; i++)
	{
		(*(stars + i)).print();
	}
}

// wtf...
Band Band::operator+=(const Band &b)
{
	int *un;
	un = new int[length + b.length];
	
	int totalLength = length + b.length;

	for(int i = 0; i < length; i++)
	{
		*(un + i) = (*(stars + i)).getAwesomeness();
	}

	for(int j = length; j < totalLength; j++)
	{
		*(un + j) = (*(b.stars + j - length)).getAwesomeness();	
	}

	for(int i = 0; i < totalLength - 1; i++) 
	{
		int bestIndex = i;
		for(int j = i + 1; j < totalLength; j++)
		{
			int best = *(un + i);
			if(*(un + j) > *(un + bestIndex))
			{
				bestIndex = j;
			}
		}

		if(bestIndex != i)
		{
			int swap = *(un + i);
			*(un + i) = *(un + bestIndex);
			*(un + bestIndex) = swap;
		}
	}

	Rockstar *result = new Rockstar[5];
	int index = 0;

	for(int i = 0; i < length; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			if((*(stars + i)).getAwesomeness() == *(un + i)) {
				*(result + index) = *(stars + i);
				index++;
				break;
			}
		} 
	}

	for(int i = 0; i < b.length; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			if((*(b.stars + i)).getAwesomeness() == *(un + i)) {
				*(result + index) = *(stars + i);
				index++;
				break;
			}
		} 
	}
	return Band(result);
}

Rockstar Band::pickFrontman()
{
	Rockstar best = *(stars + 0);
	for(int i = 1; i < length; i++)
	{
		if((*(stars + i)).getAwesomeness() > best.getAwesomeness()) 
		{
			best = *(stars + i);
		}
	}
	return best;
}
// - 0.2
int main()
{	
	// Принципите са енкапсулация на данните, полиморфизъм, унаследяване и абстракция
	// унаследяване is my favorite
	return 0;
}