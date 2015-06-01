#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;

class Date {
private:
	int day, month, year;

public:
	Date(int day = 1, int month = 1, int year = 1) {
		this->day = day;
		this->month = month;
		this->year = year;
	}

	void setDay(int day) {
		this->day = day;
	}

	int getDay() const {
		return day;
	}

	void setMonth(int month) {
		this->month = month;
	}

	int getMonth() const {
		return month;
	}

	void setYear(int year) {
		this->year = year;
	}

	int getYear() const {
		return year;
	}

	void print() const {
		cout << day << "." << month << "." << year << endl;
	}
};

class Card {
private:
	char* name;
	Date date;

public:
	Card(char* name = "", int day = 1, int month = 1, int year = 1) {
		this->name = new char[strlen(name) + 1];
		assert(this->name != NULL);
		strcpy_s(this->name, strlen(name) + 1, name);

		date = Date(day, month, year);
	}

	~Card() {
		delete[]name;
	}

	Card(const Card &other) {
		name = new char[strlen(other.name) + 1];
		assert(name != NULL);
		strcpy_s(name, strlen(other.name) + 1, other.name);

		date = other.date;
	}

	Card &operator = (const Card &other) {
		if (this != &other) {
			delete[]name;

			name = new char[strlen(other.name) + 1];
			assert(name != NULL);
			strcpy_s(name, strlen(other.name) + 1, other.name);

			date = other.date;
		}
		return*this;
	}

	void setName(char* name) {
		delete[]this->name;
		this->name = new char[strlen(name) + 1];
		assert(this->name != NULL);
		strcpy_s(this->name, strlen(name) + 1, name);
	}

	char* getName() const {
		return name;
	}

	void setDate(Date date) {
		this->date = date;
	}

	Date getDate() const {
		return date;
	}

	void print() const {
		cout << "Name: " << name << endl
			<< "Date of birth: ";
		date.print();
	}
};

class ListPerson {
private:
	Card* cards;
	int size;
	int capacity;

public:
	ListPerson(int size = 0, int capacity = 1) {
		this->size = size;
		this->capacity = capacity;
		cards = new Card[this->capacity];
		assert(cards != NULL);
	}

	~ListPerson() {
		delete[]cards;
	}

	ListPerson(const ListPerson &other) {
		size = other.size;
		capacity = other.capacity;
		cards = new Card[other.capacity];
		assert(cards != NULL);

		for (int i = 0; i < size; i++) {
			cards[i] = other.cards[i];
		}
	}

	ListPerson &operator = (const ListPerson &other) {
		if (this != &other) {
			delete[]cards;

			size = other.size;
			capacity = other.capacity;
			cards = new Card[other.capacity];
			assert(cards != NULL);

			for (int i = 0; i < size; i++) {
				cards[i] = other.cards[i];
			}
		}
		return*this;
	}

	void addCard(char* name, int day, int month, int year) {
		if (size == capacity) {
			Card* tmp = cards;
			cards = new Card[2 * capacity];

			for (int i = 0; i < size; i++) {
				cards[i] = tmp[i];
			}
			
			delete[]tmp;
			capacity *= 2;
		}

		Card c(name, day, month, year);
		cards[size++] = c;
	}

	void removeCard(int pos) {
		for (int i = 0; i < size; i++) {
			if (i == pos) {
				cards[i] = cards[i + 1];
				for (i = pos; i < size; i++) {
					cards[i] = cards[i + 1];
				}
				size--;
			}
		}
	}

	void getCard(char* name) {
		for (int i = 0; i < size; i++) {
			if (name == cards[i].getName()) {
				cards[i].print();
			}
		}
	}

	void print() const {
		cout << "Persons: " << endl
			<< endl;
		for (int i = 0; i < size; i++) {
			cards[i].print();
			cout << endl;
		}
	}
}; 