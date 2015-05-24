#include<iostream>
#include<iomanip>
#include<string>
#include<cassert>
using namespace std;
struct Person{
	Person(char *lastName = "Topalov", char *dateOfBirth = "02.03.1994"){
		setLastName(lastName);
		setDateOfBirth(dateOfBirth);
	}
	Person(const Person &other){
		setLastName(other.lastName);
		setDateOfBirth(other.dateOfBirth);
	}
	Person& operator=(const Person &other){
		if (this != &other){
			delete[] lastName;
			delete[] dateOfBirth;
			setLastName(other.lastName);
			setDateOfBirth(other.dateOfBirth);
		}
		return *this;
	}
	~Person(){
		delete[] lastName;
		delete[] dateOfBirth;
	}
	bool operator==(const Person &other){
		if (strcmp(getLastName(), other.getLastName()) == 0)
		{
			if (strcmp(getDateOfBirth(), other.getDateOfBirth()) == 0)
			{
				return true;
			}
		}
		return false;
	}
	bool operator !=(const Person &other){
		if (strcmp(getLastName(), other.getLastName()) != 0)
		{
			return true;
		}
		if (strcmp(getDateOfBirth(), other.getDateOfBirth()) != 0)
		{
			return true;
		}
		if (strcmp(getLastName(), other.getLastName()) == 0)
		{
			if (strcmp(getDateOfBirth(), other.getDateOfBirth()) != 0)
			{
				return true;
			}
			return false;
		}
		if (strcmp(getDateOfBirth(), other.getDateOfBirth()) == 0)
		{

			if (strcmp(getLastName(), other.getLastName()) != 0)
			{
				return true;
			}
			return false;
		}
	}
	void setLastName(char *lastName){
		this->lastName = new char[strlen(lastName) + 1];
		assert(this->lastName != NULL);
		strcpy_s(this->lastName, strlen(lastName) + 1, lastName);
	}
	char *getLastName()const{
		return lastName;
	}
	char* getDateOfBirth()const{
		return dateOfBirth;
	}
	void setDateOfBirth(char *dateOfBirth){
		this->dateOfBirth = new char[strlen(dateOfBirth) + 1];
		assert(this->dateOfBirth != NULL);
		strcpy_s(this->dateOfBirth, strlen(dateOfBirth) + 1, dateOfBirth);
	}
private:
	char *lastName;
	char *dateOfBirth;

};
class ListPerson{
	Person *persons;
	Zodiac *zodiac;
	Zodiac zod[12];
	int current, max;
public:
	void setCurrent(int current){
		this->current = current;
	}
	int getCurrent()const{
		return current;
	}
	void setMax(int max){
		this->max = max;
	}
	int getMax()const{
		return max;
	}
	ListPerson(Person *persons = new Person[0], int current = 0, int max = 1){
		this->persons = new Person[max];
		setCurrent(current);
		setMax(max);
	};
	ListPerson(const ListPerson &other){
		persons = new Person[other.max];
		for (int i = 0; i < other.current; i++){
			persons[i] = other.persons[i];
		}
		current = other.current;
		max = other.max;
	}
	ListPerson& operator=(const ListPerson &other){
		if (this != &other){
			delete[] persons;
			persons = new Person[other.max];
			for (int i = 0; i < other.current; i++){
				persons[i] = other.persons[i];
			}
			current = other.current;
			max = other.max;
		}
		return *this;
	}
	~ListPerson(){
		delete[] persons;
	}
	Person& getPerson(char *name){
		for (int i = 0; i < current; i++){
			if (strcmp(persons[i].getLastName(), name) == 0){
				return persons[i];
			}
		}
		cout << "Nothing Found";
	}
	ListPerson& concat(const ListPerson &other){
		int concatCurrent = current + other.getCurrent();
		int concatMax = max + other.getMax();
		Person *temp = new Person[concatMax];
		for (int i = 0; i < current; i++){
			temp[i] = persons[i];
		}
		delete[]persons;
		for (int i = current; i < concatCurrent; i++){
			temp[i] = other.persons[i];
		}
		persons = new Person[concatCurrent];
		for (int i = 0; i < concatCurrent; i++){
			persons[i] = temp[i];
		}
		delete[]temp;
		current = concatCurrent;
		max = concatMax;
		return *this;
	}
	ListPerson& Cut(const ListPerson &other){
		Person *temp;
		int tempCurrent = 0;
		(current>other.current) ? (temp = new Person[current]) : (temp = new Person[other.getCurrent()]);
		for (int i = 0; i < current; i++){
			for (int j = 0; j < other.getCurrent(); j++){
				if (persons[i] == other.persons[j])
				{
					temp[tempCurrent] = persons[i];
					tempCurrent++;
				}
			}
		}
		current = tempCurrent;
		max = tempCurrent;;
		delete[]persons;
		persons = new Person[current];
		for (int i = 0; i < current; i++){
			persons[i] = temp[i];
		}
		delete[] temp;
		return *this;
	}
	ListPerson& Difference(const ListPerson &other){
		ListPerson temp = Cut(other);
		Person *temp1 = new Person[current];
		int tempCurrent=0;
		bool flag = false;
		for (int i = 0; i < current;i++){
			for (int j = 0; j < temp.getCurrent(); j++){
				if (persons[i] == temp.persons[j])
				{
					
					flag = true;
				}
			}
			if (!flag){
				temp1[i] = persons[i];
				tempCurrent++;
			}
			flag = false;
		}
		delete[] persons;
		persons = new Person[tempCurrent];
		for (int i = 0; i < tempCurrent; i++){
			persons[i] = temp1[i];
		}
		delete[]temp1;
	}
	void addPerson(Person &other){
		if (current == max){
			Person *temp = new Person[current];
			for (int i = 0; i < current; i++){
				temp[i] = persons[i];
			}
			delete[]persons;
			max *= 2;
			persons = new Person[max];
			for (int i = 0; i < current; i++){
				persons[i] = temp[i];
			}
			delete[]temp;
		}
		current += 1;
		persons[current] = other;

	}
	ListPerson deletePerson(char *lastName){
		if (max > current * 2){
			Person *temp = new Person[current];
			for (int i = 0; i < current; i++){
				if (strcmp(persons[i].getLastName(), lastName) == 0){
					for (int j = i + 1; j < current; j++){
						temp[j - 1] = persons[j];
					}
					current--;
					break;
				}
				temp[i] = persons[i];
			}
			delete[]persons;
			max /= 2;
			persons = new Person[max];
			for (int i = 0; i < current; i++){
				persons[i] = temp[i];
			}
		}
		else{
			for (int i = 0; i < current; i++){
				if (strcmp(persons[i].getLastName(), lastName) == 0){
					for (int j = i + 1; j < current; j++){
						persons[j - 1] = persons[j];
					}
					current--;
					break;
				}
			}
		}
		return *this;
	}
};
struct Zodiac{
	void setName(char *name){
		this->name = new char[strlen(name) + 1];
		assert(this->name != NULL);
		strcpy_s(this->name, strlen(name) + 1, name);
	}
	char *getName(){
		return name;
	}
	void setBegining(char begining[6]){
		strcpy(this->begining, begining);
	}
	char* getBegining(){
		return begining;
	}
	void setEnd(char end[6]){
		strcpy(this->end, end);
	}
	char* getEnd(){
		return end;
	}
	Zodiac(char *name = "Aries", char begining[6] = "21.03", char end[6] = "21.04"){
		setName(name);
		setBegining(begining);
		setEnd(end);
	}
	Zodiac(const Zodiac &other){
		setName(other.name);
		strcpy(this->begining, begining);
		strcpy(this->end, end);
	}
	Zodiac& operator=(const Zodiac &other){
		if (this != &other){
			delete[] name;
			setName(other.name);
			strcpy(this->begining, other.begining);
			strcpy(this->end, other.end);
		}
		return *this;
	}
	~Zodiac(){
		delete[] name;
	}
private:
	char *name;
	char begining[6];
	char end[6];
};
int main(){

}