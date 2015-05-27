#include <iostream>
#include <cassert>
#include <cstring>

using namespace std;

class Programmer {
private:
    char*name;
    int iq;
    double salary;
public:

    const char*get_name() const {
        return name;
    }
    const int get_iq() const {
        return iq;
    }
    const double get_salary() const {
        return salary;
    }

    void set_name(char*Name) {
        delete[]name;
        name = new char[strlen(Name) + 1];
        assert(name);
        strcpy(name, Name);
    }
    void set_iq(int IQ) {
        iq = IQ;
    }
    void set_salary(double Salary) {
        salary = Salary;
    }

    Programmer() {
        name = NULL;
        iq = 100;
        salary = 150.0;
    }

    ~Programmer() {
        delete[]name;
    }

    Programmer(const Programmer&other) {
        strcpy(name, other.name);
        iq = other.iq;
        salary = other.salary;
    }

    Programmer &operator=(const Programmer&other){
        if(this != &other) {
            strcpy(name, other.name);
            iq = other.iq;
            salary = other.salary;
        }
        return *this;
    }


    const void print(Programmer &some) {
        cout << get_name() << ' ' << get_iq() << ' ' << get_salary() << endl;
    }

    bool operator>(const Programmer&other) {
        return iq > other.get_iq();
    }
    bool operator<(const Programmer&other) {
        return iq < other.get_iq();
    }
    bool operator==(const Programmer&other) {
        return iq == other.get_iq();
    }

};

class Team {
private:
    Programmer*table;
    int size, max_size;
public:

    const int get_size() const {
        return size;
    }
    const int get_max_size() {
        return max_size;
    }

    void set_size(int Size) {
        size = Size;
    }
    void set_max_size(int Max_size) {
        max_size = Max_size;
    }

    Team() {
        table = NULL;
        size = 0;
        max_size = 0;
    }

    ~Team() {
        delete[]table;
    }

    Team(const Team&other) {
        for(int i = 0; i < size; i++) {
            table[i] = other.table[i];
        }
        size = other.size;
        max_size = other.max_size;
    }

    Team &operator=(const Team&other){
        if(this != &other){
            for(int i = 0; i < size; i++) {
            table[i] = other.table[i];
        }
        size = other.size;
        max_size = other.max_size;
        }
        return *this;
    }


    void add(Programmer &p1) {
        if(size == max_size) {
            if(max_size == 0) max_size = 2;
            max_size *= 2;
            Programmer *temp = new Programmer[max_size];
            for(int i = 0; i < size; i++) {
                temp[i] = table[i];
            }
            delete[]table;
            table = temp;
        }
        table[++size] = p1;
    }

    void remove(char*name_to_remove) {
        int index = -1;
        for(int i = 0; i < size && index == -1; i++) {
            if(strcmp(table[i].get_name(), name_to_remove) == 0) {
                index = i;
            }
        }
        if(index == -1) {
            cout << "not found";
            return;
        }

        if(max_size > size * 2){
            max_size /= 2;
        }
            Programmer*temp = new Programmer[size - 1];
            for(int i = 0; i < index; i++) {
                temp[i] = table[i];
            }
            for(int j = index; j < size - 1; j++) {
                temp[j] = table[j + 1];
            }
            delete[]table;
            table = temp;
            size--;
    }
    // return something if not found 
    // - 0.1
    Programmer &get(char*name_to_find){
        bool flag = true;
        for(int i = 0; i < size && flag; i++) {
            if(strcmp(table[i].get_name(), name_to_find) == 0){
                return table[i];
                flag = false;
            }
        }
        if(flag) cout << "not found";
    }

    const void print_all() {
        for(int i = 0; i< size; i++) {
            table[i].print(table[i]);
        }
    }

    Team &operator-=(const Team &other){
        Team temp;
        int first_size = size;
        int second_size = other.size;
        temp.table = new Programmer[first_size + second_size];

        for(int i = 0; i < size; i++) {
            temp.table[i] = table[i];
        }
        for(int i = 0; i < first_size; i++) {
            for(int j = 0; j < second_size; j++) {
                if(strcmp(table[i].get_name(), other.table[j].get_name()) == 0){
                    char*buf;
                    strcpy(buf, table[i].get_name());
                    remove(buf);
                }
            }
        }

        return temp;
    }

    double avg_iq() {
        double avg = 0.0;
        for(int i = 0; i < size; i++) {
            avg += table[i].get_iq();
        }
        return avg / size;
    }

};

class Company {
private:
    Team*all;
    int size, max_size;
public:
    const int get_size() const {
        return size;
    }
    const int get_max_size() {
        return max_size;
    }

    void set_size(int Size) {
        size = Size;
    }
    void set_max_size(int Max_size) {
        max_size = Max_size;
    }

    Company() {
        all = NULL;
        size = 0;
        max_size = 0;
    }
    ~Company() {
        delete[]all;
    }
    Company(const Company &other) {
        for(int i = 0; i< size; i++){
            all[i] = other.all[i];
        }
        size = other.size;
        max_size = other.max_size;
    }
    Company &operator=(const Company&other) {
        if(this != &other){
            for(int i = 0; i< size; i++){
                all[i] = other.all[i];
            }
            size = other.size;
            max_size = other.max_size;
        }
        return *this;
    }


    double average(){
        double total = 0.0;
        for(int i = 0; i< size; i++) {
            total += all[i].avg_iq();
        }
        // total /size
        // - 0.1
        return total;
    }

    const void print_company() {
        for(int i = 0; i < size; i++) {
            all[i].print_all();
        }
    }

};

//5.8