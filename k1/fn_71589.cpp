// 1. Inheritance
// 2. Abstraction
// 3. Encapsulation
// 4. Polymorphism

#include <iostream>
#include <cstring>
#include <cassert>
#include <algorithm>
using namespace std;

class Programmer {
private:
	char* name;
	int iq;
	double salary;

public:
	Programmer(char* name = "", int iq = 0, double salary = 0.0) {
		this->name = new char[strlen(name) + 1];
		assert(this->name != NULL);
		strcpy_s(this->name, strlen(name) + 1, name);
		this->iq = iq;
		this->salary = salary;
	}

	~Programmer() {
		delete[]name;
	}

	Programmer(const Programmer &other) {
		name = new char[strlen(other.name) + 1];
		assert(name != NULL);
		strcpy_s(name, strlen(other.name) + 1, other.name);
		iq = other.iq;
		salary = other.salary;
	}

	Programmer &operator =(const Programmer &other) {
		if (this != &other) {
			delete[]name;

			name = new char[strlen(other.name) + 1];
			assert(name != NULL);
			strcpy_s(name, strlen(other.name) + 1, other.name);
			iq = other.iq;
			salary = other.salary;
		}
		return*this;
	}

	void setName(char* name) {
		delete[]name;
		this->name = new char[strlen(name) + 1];
		assert(this->name != NULL);
		strcpy_s(this->name, strlen(name) + 1, name);
	}

	char* getName() const {
		return name;
	}

	void setIq(int iq) {
		this->iq = iq;
	}

	int getIq() const {
		return iq;
	}

	void setSalary(double salary) {
		this->salary = salary;
	}

	double getSalary() const {
		return salary;
	}

	void print() const {
		cout << "Name: " << name << endl
			<< "Iq: " << iq << endl
			<< "Salary: " << salary << endl;
	}

	bool operator <(const Programmer &other) {
		return this->iq < other.iq;
	}

	bool operator >(const Programmer &other) {
		return this->iq > other.iq;
	}

	bool operator ==(const Programmer &other) {
		return this->iq == other.iq;
	}
};

class Team {
private:
	Programmer* programmers;
	int size, capacity;

public:
	Team(int size = 0, int capacity = 1) {
		this->size = size;
		this->capacity = capacity;
		programmers = new Programmer[this->capacity];
		assert(programmers != NULL);
	}

	~Team() {
		delete[]programmers;
	}

	Team(const Team &other) {
		size = other.size;
		capacity = other.capacity;
		programmers = new Programmer[other.capacity];
		assert(programmers != NULL);

		for (int i = 0; i < size; i++) {
			programmers[i] = other.programmers[i];
		}
	}

	Team &operator =(const Team &other) {
		if (this != &other) {
			delete[]programmers;

			size = other.size;
			capacity = other.capacity;
			programmers = new Programmer[other.capacity];
			assert(programmers != NULL);

			for (int i = 0; i < size; i++) {
				programmers[i] = other.programmers[i];
			}
		}
		return*this;
	}

	void addProgrammer(char* name, int iq, double salary) {
		if (size == capacity) {
			Programmer* tmp = programmers;
			programmers = new Programmer[2 * capacity];

			for (int i = 0; i < size; i++) {
				programmers[i] = tmp[i];
			}
			delete[]tmp;
			capacity *= 2;
		}
		Programmer p(name, iq, salary);
		programmers[size++] = p;
	}

	void removeProgrammer(char* name) {
		for (int i = 0; i < size; i++) {
			if (!strcmp(programmers[i].getName(), name)) {
				programmers[i] = programmers[i + 1];
				//int pos = i;
				for (int j = i + 1; j < size; j++) {
					programmers[j] = programmers[j + 1];
				}
				size--;
			}
		}
	}

	void getProgrammer(char* name) {
		for (int i = 0; i < size; i++) {
			if (!strcmp(programmers[i].getName(), name)) {
				programmers[i].print();
			}
		}
	}

	void print() const {
		cout << "Team:" << endl
			<< endl;
		for (int i = 0; i < size; i++) {
			programmers[i].print();
			cout << endl;
		}
	}

	Team &operator -=(const Team &other) {
		Programmer* tmp;
		for (int i = 0; i < size; i++) {
			if (!strcmp(programmers[i].getName(), other.programmers[i].getName())) {
				tmp[i] = programmers[i];
			}
		}
		delete[]tmp;
		return*this;
	}

	void sort() {
		for (int i = 0; i < size; i++) {
			int max = i;
			for (int j = i + 1; j < size; j++) {
				if (programmers[max].getIq() < programmers[j].getIq()) {
					max = j;
				}
			}

			if (max != i) {
				swap(programmers[max], programmers[i]);
			}

		}
	}
};

class Company {
private:
	Team* teams;
	int size, capacity;
	Programmer* programmers;

public:
	Company(int size = 0, int capacity = 1) {
		this->size = size;
		this->capacity = capacity;
		teams = new Team[this->capacity];
		assert(teams != NULL);
	}

	~Company() {
		delete[]teams;
	}

	Company(const Company &other) {
		size = other.size;
		capacity = other.capacity;
		teams = new Team[other.capacity];
		assert(teams != NULL);

		for (int i = 0; i < size; i++) {
			teams[i] = other.teams[i];
		}
	}

	Company &operator =(const Company &other) {
		if (this != &other) {
			delete[]teams;

			size = other.size;
			capacity = other.capacity;
			teams = new Team[other.capacity];
			assert(teams != NULL);

			for (int i = 0; i < size; i++) {
				teams[i] = other.teams[i];
			}
		}
		return*this;
	}

	int averageIq() {
		int counter = 0;
		double sum = 0;
		for (int i = 0; i < size; i++) {
			sum += programmers[i].getIq();
			counter++;
		}
		return sum / counter;
	}

	void print() {
		cout << "Company:" << endl
			<< endl;
		for (int i = 0; i < size; i++) {
			teams[i].print();
			cout << endl;
		}
	}
};