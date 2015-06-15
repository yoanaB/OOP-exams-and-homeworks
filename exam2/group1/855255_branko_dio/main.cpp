//abstrakciq,enkapsulaciq,nasledqvane,polimorfizym
#include <iostream>
#include <cstring>
#include <assert.h>
#include <math.h>

using namespace std;

struct Musical_skill {
private:
    char* name;
    int skill;
    void init(char* name){
    this->name=new char[strlen(name)+1];
    assert(this!=NULL);
    strcpy(this->name,name);
    }
public:
    void setName(char* name){
        init(name);
    }
    char* getName(){
        return this->name;
    }
    Musical_skill(Musical_skill& other){
        init(other.name);
	//skill?
    }
    Musical_skill& operator =(const Musical_skill& other){
        if(this!=&other){
	//skill?
            delete []this->name;
            init(other.name);
        }
        return *this;
    }
    ~Musical_skill(){
        delete []this->name;
        }

};
class Musician {
private:
    char* name;
    void init(char* name){
    this->name=new char[strlen(name)+1];
    assert(this!=NULL);
    strcpy(this->name,name);

protected:
    int skill;
    int vices;
    int beauty;
    Musician* Musical_skill[5];

public:
    void setName(char* name){
        init(name);
    }
    int getName(){
        return this->name;
    }
//???
    virtual int vices()= 0;
    virtual int beauty ()= 0;
    virtual char* type () =0;
};

    void setVices(int vices){
        this->vices= vices;
    }
    int getVices () {
        return this->vices;
    }
    void setBeauty(int beauty){
        this->beauty= beauty;
    }
    int getBeauty() {
        return this->beauty;
    }
    Musician(char*name) {
        init(name);
    }
    Musician (const Musician& other) {
        init(other.name);
    }
    Musician& operator=(const Musician) {
        if(this!=&other){
            delete []this->name;
            init(other.name);
        }
        return *this;
    }
    ~Musician() {
        delete []this->name;
    }

class RockMusician : public Musician {
private:

     int getBeauty() {
        return this->beauty * this->beauty + Musical_skill - vices * 3 * 3,14 ;
    }
    int getVices() {
        return this->vices;
    }
    char* getType (){
        return "rock";
    }
    char* name;
    void init(char* name){
    this->name=new char[strlen(name)+1];
    assert(this!=NULL);
    strcpy(this->name,name);
public:
    RockMusician(char*name, int beauty, int vices){
// where is this function? 
       init(name,beauty,vices);
    }
    RockMusician(const RockMusician& other){
        init(other.name);
    }
    RockMusician& operator =(const RockMusician& other){
        if(this!=&other){
            delete[]this->name;
            init(other.name);
        }
        return *this;
    }
    ~RockMusician(){
        delete [] this->name;
    }
};
class ChalgaMusician : public Musician {
private:
    bool rasova= true;
    int skill;
    int getVices() {
    return this->vices;
    }
    int getBeauty(){
//^5 ??
        return (this->beauty)^5 + vices + rasova * cos(skill) ;
    }
    char* getType(){
        return "rock_tack";
    }

};
class Group {
private:
    char* name;
    void init(char*name){
    this->name=new char[strlen(name)+1];
    assert(this!=NULL);
    strcpy(this->name,name);
    }
    Musician* musicians [10];
public:
    int count;
    void addMusician(Musician & musicians){
        musicians[count]=&Musician;
        count++;
    }

};
class RockGroup : public Group {
    int count;
    void addMusician(Musician& musicians){
        if(skill>100 && Musician==RockMusician){

        musicians[count]=&Musician;
        count++;
        }
        return -1;
    }
};

int main()
{

    return 0;
}
