#include <iostream>
#include <cstring>
using namespace std;

struct Person{
	int date;
	int month;
	int year;
	char family[10];
public:
	Person& operator=(Person& other);
	Person();
	Person(int newData,int newMonth,int newYear, char newFamily[10]);
	bool  operator==(Person&);
	char* getName();
};

struct Zodiac{
	char simbol[10];
	int startDate;
	int startMonth;
	int endMonth;
	int endDate;
};

class ListPerson{
public:
	ListPerson();
	ListPerson(const ListPerson&);
	ListPerson& operator+(ListPerson&);
	void addList(int newDate,int newMonth,int newYear,char newFamily[10]);
	void deleteList(char name[10]);
	int searchList(char name[10]);
	void getZodiac(char*);
	~ListPerson();
    void getYear();
private:
	Person* persons;
	int size;
	Zodiac* x;
};

void ListPerson::addList(int newDate, int newMonth, int newYear, char newFamily[10]){
	int error = 0;
	for (int i = 0; i < size; i++){
		if (strcmp(persons[i].family, newFamily) == 0){
			error = 1;
			break;
		}
	}
	int length = strlen(newFamily)+1 ;
	if (size!= 0 && error !=1){
		Person* some;
		some = new Person[size];
		for (int i = 0; i < size; i++){
			some[i] = persons[i];

		}
		delete[] persons;
		persons = new Person[++size];
		for (int i = 0; i < size-1; i++){
			 persons[i]=some[i];
		}
		delete[] some;
		persons[size-1].year = newYear;
		persons[size-1].month = newMonth;
		persons[size-1].date = newDate;
	}
	else if (error!=1){
 		delete[] persons;
		persons = new Person[++size];
		persons[size-1].date = newDate;
		persons[size-1].year = newYear;
		persons[size-1].month = newMonth;
	}
}

ListPerson::ListPerson(){
	this->size = 0;
	persons = new Person[1];
	x = new Zodiac[2];
	x[0].startDate = 21;
	x[0].endDate = 21;
	x[0].startMonth = 3;
	x[0].endMonth = 4;
	strcpy(x[0].simbol , "Oven");
}

ListPerson::~ListPerson(){
	delete [] persons;
	delete[] x;
}

void ListPerson::getYear(){
	for (int i = 0; i < size; i++){
		cout << persons[i].date<<" " <<  persons[i].month << " " << persons[i].year << endl;
		cout << persons[i].family << endl;
	}
}
void ListPerson::deleteList(char name[10]){
	for (int i = 0; i < size; i++){
		if (strcmp(persons[i].family, name)==0){
			Person one;
			persons[i] = one;
			persons[i] = persons[size - 1];
			persons[size - 1] = one;
			break;
		}
	}
	Person* some;
	some = new Person[--size];
	for (int i = 0; i < size; i++){
		some[i] = persons[i];
	}
	delete persons;
	persons = new Person[size];
	for (int i = 0; i < size; i++){
		persons[i] = some[i];
	}
	delete some;
}

int ListPerson::searchList(char name[10]){
	for (int i = 0; i < size; i++){
		if (strcmp(persons[i].family, name) == 0){
			return persons[i].date;
			break;
		}
	}
}

ListPerson& ListPerson::operator+(ListPerson& other){
	Person* some;
	some = new Person[this->size];
	for (int i = 0; i < size; i++){
		some[i] = this->persons[i];
	}
	this->size += other.size;
	delete[] this->persons;
	persons = new Person[this->size];
	int g = 0;
	for (int i = 0; i <this->size; i++){
		if (i < other.size){
			persons[i] = other.persons[i];
		}else{
			persons[i] = some[g++];
		}
	}
	delete[] some;
	return *this;
}

ListPerson::ListPerson(const ListPerson& other){
	this->size = other.size;
	persons = new Person[this->size];
	for (int i = 0; i < size; i++){
		this->persons[i] = other.persons[i];
	}
}

void ListPerson::getZodiac(char* hereName){
	for (int i = 0; i < size; i++){
		if (strcmp(persons[i].family, hereName) == 0){
			for (int j = 0; j < 2; j++){
				if (((x[j].startDate <= persons[i].date) &&
					(x[j].startMonth >= persons[i].month))
					||
					(persons[i].date <= x[j].endDate) &&
					(persons[i].month <= x[j].endMonth)){
					cout << x[j].simbol << endl;
					break;
				}
			}
		}
	}
}

Person::Person(){
	this->date = 01;
	this->month = 01;
	this->year = 1950;
}

Person& Person::operator=(Person& other){
	this->date = other.date;
	this->month = other.month;
	this->year = other.year;
	int length = strlen(other.family)+1;
	return *this;
}

Person::Person(int newData, int newMonth, int newYear, char newFamily[10]){
	this->date = newData;
	this->month = newMonth;
	this->year = newYear;
	int length = strlen(newFamily) + 1;
}

char* Person::getName(){
	return this->family;
}

bool Person::operator==(Person& other){
	if (strcmp(this->family,other.family)==0 && (this->date == other.date && (this->month == other.month &&( this->year = other.year)))){
		return true;
	}else{
		return false;
	}
}

int main(){
	ListPerson newPerson;
	newPerson.addList(19,04,1984, "IVAN");
	newPerson.getZodiac("GOSHO");
	newPerson.getYear();
	return 0;
}
