#include<iostream>
#include<string>
using namespace std;
/*
    Question #1 Answer: Encapsulation, Polymorphism, Inheritance, Abstract //
    Author: Martin Dinkov
    Faculty Number: 71543
    Specialization: Information Systems
    Course: 1
    Administration Group: 1
*/
class Programmer{
private:
    char* name;
    int iq;
    double salary;
public:
    void setName(char* name){
        this->name = name;
    }
    void setIQ(int iq){
        this->iq = iq;
    }
    void setSalary(double salary){
        this->salary = salary;
    }
    char* getName(){
        return this->name;
    }
    int getIQ(){
        return this->iq;
    }
    double getSalary(){
        return this->salary;
    }
    Programmer(){
        setName("NULL");
        setIQ(0);
        setSalary(0);
    }
    Programmer(char* name, int iq, double salary){
        setName(name);
        setIQ(iq);
        setSalary(salary);
    }
    void PrintInfo(){
        cout << "Name: " << getName() << endl;
        cout << "IQ: " << getIQ() << endl;
        cout << "Salary: " << getSalary() << endl;
    }
    bool operator<(Programmer arg){
        return (arg.getIQ() > this->getIQ());
    }
    bool operator>(Programmer arg){
        return (arg.getIQ() < this->getIQ());
    }
    bool operator==(Programmer arg){
        return (arg.getIQ() == this->getIQ());
    }
    ~Programmer(){
        //delete[];
    }
};

class Team{
private:
    Programmer* programmers;
    int programmers_count;
public:
    Team(Programmer input){
        this->programmers = new Programmer();
        this->programmers[0] = input;
        this->programmers_count = 1;
    }
    void addProgrammer(Programmer& input){
        this->programmers[programmers_count] = input;
        programmers_count++;
    }
    void removeProgrammer(char* name){
        for(int i = 0; i < programmers_count; i++){
            if(programmers[i].getName() == name){
                programmers[i] = programmers[i+1];
                for(int j = i; j < programmers_count; j++){
                    if(j != programmers_count-1){
                        programmers[j] = programmers[j+1];
                    }
                }
                delete &this->programmers[programmers_count-1];
                this->programmers_count--;
            }
        }
    }
    void removeProgrammer(int pos){
        if(pos < this->programmers_count){
            programmers[pos] = programmers[pos+1];
        }
        for(int j = pos; j < programmers_count; j++){
            if(j != programmers_count-1){
                programmers[j] = programmers[j+1];
            }
        }
        //delete &this->programmers[programmers_count-1];
        this->programmers_count--;
    }
    Programmer& getProgrammer(char* name){
        for(int i = 0; i < programmers_count; i++){
            if(programmers[i].getName() == name){
                return programmers[i];
            }
        }
    }
    void PrintInfo(){
        cout << "Programmers of the Team:" << endl << endl;
        for(int i = 0; i < programmers_count; i++){
            programmers[i].PrintInfo();
            cout << endl;
        }
    }
    void Sort(){
        Programmer swap;
        for(int i = 0; i < this->programmers_count - 1; i++){
            for(int j = i+1; j < this->programmers_count; j++){
                if(programmers[j] < programmers[i]){
                    swap = programmers[i];
                    programmers[i] = programmers[j];
                    programmers[j] = swap;
                }
            }
        }
    }
    int getProgrammersCount(){
        return this->programmers_count;
    }
    Programmer* getProgrammers(){
        return this->programmers;
    }
    ~Team(){
        //delete[] Team;
    }
    /*void operator -= (Team t1){

    }*/
};

class Company{
private:
    Team* teams;
    int teams_count;
public:
    Company(Team input){
        this->teams = new Team(input);
        this->teams_count = 1;
    }
    Team* getTeams(){
        return this->teams;
    }
    int getTeamsCount(){
        return this->teams_count;
    }
    void addTeam(Team& input){
        this->teams[teams_count] = input;
        this-> teams_count++;
    }
    void PrintInfo(){
        cout << "Teams of the Company:" << endl << endl;
        for(int i = 0; i < teams_count; i++){
            teams[i].PrintInfo();
            cout << endl;
        }
    }
    double getAverageIQ(){
        double average = 0;
        int counter = 0;
        for(int i = 0; i < this->teams_count; i++){
            for(int j = 0; j < this->teams[i].getProgrammersCount(); j++){
                average += this->teams[i].getProgrammers()[j].getIQ();
                counter++;
            }
        }
        average /= counter;
        return average;
    }
    void operator -= (Team input){
        for(int i = 0; i < input.getProgrammersCount(); i++){
            for(int j = 0; j < getTeams()->getProgrammersCount(); j++){
                if(input.getProgrammers()[i] == getTeams()->getProgrammers()[j]){
                    input.removeProgrammer(i);
                }
            }
        }
    }
    ~Company(){
        //delete[] Company;
    }
};
int main()
{
    return 0;
}
