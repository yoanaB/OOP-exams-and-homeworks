#include<iostream>
#include<cassert>
using namespace std;
/*
Zad 1 
enkapsulaciq
nasledqvane
abstrakciq
polimorfizum
*/
class RockStar{
	char *name;
	unsigned awesomeness;
	unsigned numberOfFens;
public:
	void setName(char *name){
		this->name = new char[strlen(name) + 1];
		assert(this->name != NULL);
		strcpy_s(this->name, strlen(name) + 1, name);
	}
	char *getName()const{
		return name;
	}
	void setAwesomeness(unsigned awesomeness ){
		if (awesomeness >= 0)
			this->awesomeness = awesomeness;
		else
			this->awesomeness = 0;
	}
	unsigned getAwesomeness()const{
		return awesomeness;
	}
	void setNumberOfFens(unsigned numberOfFens){
		if (numberOfFens >= 0)
			this->numberOfFens = numberOfFens;
		else
			this->numberOfFens = 0;
	}
	unsigned getNumberOfFans()const{
		return numberOfFens;
	}
	RockStar(){
		name = new char[0];
		awesomeness = 0;
		numberOfFens = 0;
	}
	RockStar(char *name,unsigned awesomeness,unsigned numberOfFens){
		setName(name);
		setAwesomeness(awesomeness);
		setNumberOfFens(numberOfFens);
	}
	RockStar(const RockStar &other){
		setName(other.getName());
		setAwesomeness(other.getAwesomeness());
		setNumberOfFens(other.getNumberOfFans());
	}
	RockStar& operator =(const RockStar &other){
		if (this != &other){
			delete[]name;
			setName(other.getName());
			setAwesomeness(other.getAwesomeness());
			setNumberOfFens(other.getNumberOfFans());
		}
		return *this;
	}
	bool operator >(const RockStar &other){
		return getAwesomeness() > other.getAwesomeness();
	}
	bool operator <(const RockStar &other){
		return getAwesomeness() < other.getAwesomeness();
	}
	bool operator ==(const RockStar &other){
		return getAwesomeness() == other.getAwesomeness();
	}
	void printRockStar(){
		cout << "Name: " << getName() << endl
			<< "Awesomeness: " << getAwesomeness() << endl
			<< "Number of Fens: " << getNumberOfFans() << endl;
	}

	~RockStar(){
		delete[]name;
	}
};

struct Band{
	RockStar *rockstars;
	int current;
	int max;
public:
	void setCurrent(int current){
		this->current = current;
	}
	int getCurrent()const{
		return current;
	}
	void setMax(unsigned max){
		this->max = max;
	}
	int getMax()const{
		return max;
	}
	Band(int current=0,int max=1){
		this->current = current;
		this->max = max;
		rockstars = new RockStar[max];
		// HI :)
		cout << "HELO";
	}
	Band(const Band &other){
		current=other.getCurrent();
		max=other.getMax();
		rockstars = new RockStar[max];
		assert(rockstars = NULL);
		for (int i = 0; i < current; i++){
			rockstars[i] = other.rockstars[i];
		}
	}
	Band& operator = (const Band &other){
		if (this != &other){
			delete[]rockstars;
			setCurrent(other.getCurrent());
			setMax(other.getMax());
			rockstars = new RockStar[max];
			assert(rockstars != NULL);
			for (int i = 0; i < current; i++){
				rockstars[i] = other.rockstars[i];
			}
		}
		return *this;
	}
	~Band(){
		delete[] rockstars;
	}
	void addStar(const RockStar &other){
		// HI again :D
		cout << "HELO";
		if (current == max){
			RockStar *temp;			
			temp = new RockStar[current];
			assert(temp != NULL);
			for (int i = 0; i < current; i++){
				temp[i] = rockstars[i];
			}
			delete[] rockstars;
			max*=2;
			rockstars = new RockStar[max];
			assert(rockstars != NULL);
			for (int i = 0; i <current; i++){
				rockstars[i] = temp[i];
			}
			delete[] temp;
		}
		current ++;
		rockstars[current] = other;
		cout << "OLA";
	}
	void removeStar(char *name){
		if (getMax()>(getCurrent() * 2)){
			RockStar *temp;
			temp = new RockStar[getMax()];
			assert(temp != NULL);
			for (int i = 0; i < getCurrent(); i++){
				temp[i] = rockstars[i];
			}
			delete[] rockstars;
			setMax(getMax()/2);
			rockstars = new RockStar[getMax()];
			assert(rockstars != NULL);
			for (int i = 0; i < getCurrent(); i++){
				rockstars[i] = temp[i];
			}
			delete[] temp;
		}
		bool flague = true;
		for (int i = 0; i < current; i++){
			if (strcmp(rockstars[i].getName(), name) == 0){
				for (int j = i + 1; j < current; j++){
					rockstars[j - 1] = rockstars[j];
				}
				flague = false;
				setCurrent(getCurrent() - 1);
				break;
			}
		}
		if (!flague){
			cout << "Neuspeshno triene";
		}
	}

	// & would be great :)
	RockStar getStar(char *name){
		for (int i = 0; i < getCurrent(); i++){
			if (strcmp(rockstars[i].getName(), name) == 0){
				return rockstars[i];
			}
		}
		RockStar error("Error", 0, 0);
		return error;
	}

	// wut?
	RockStar pickAFrontMan(const RockStar &other){
	}
	void printBand(){
		for (int i = 0; i < current; i++){
			rockstars[i].printRockStar();
		}
	}
	double averageBandAwesomeness(){
		double temp;
		for (int i = 0; i < current; i++){
			temp += rockstars[i].getAwesomeness();
		}
		temp /= current;
		return temp;
	}
};
class Concert{
	Band *bands;
	int current, max;
public:
	double AverageAwesomeness(){
		double temporary;
		for (int i = 0; i < current; i++){
			temporary+=bands[i].averageBandAwesomeness();
		}
		temporary /= current;
		return temporary;
	}
	Band HeadLiners(){
		double temp = bands[0].averageBandAwesomeness();
		int k = 0;
		for (int i = 0; i < current; i++){
			if (bands[i].averageBandAwesomeness() > temp){
				temp = bands[i].averageBandAwesomeness();
				k = i;
			}
		}
		return bands[k];
	}
	Concert(int current=0,int max=1){
		this->current = current;
		this->max = max;
	}
	Concert(const Concert &other){
		this->current = other.current;
		this->max = other.max;
		bands = new Band[max];
		assert(bands != NULL);
		for (int i = 0; i < current; i++){
			bands[i] = other.bands[i];
		}
	}
	Concert operator = (const Concert &other){
		if (this != &other){
			delete[]bands;
			this->current = other.current;
			this->max = other.max;
			bands = new Band[max];
			assert(bands != NULL);
			for (int i = 0; i < current; i++){
				bands[i] = other.bands[i];
			}
		}
	}
	~Concert(){
		delete[]bands;
	}
};
int main(){
	RockStar BonJovi("Jon Bon Jovi", 500000, 123000), MichaelJackson("Michael Jackson", 30000, 20000), CharlieSheen("Charlie Sheen", 60000, 10000); // coool :D
	RockStar *band = new RockStar[3];
	band[0] = BonJovi;
	band[1] = BonJovi;
	band[2] = MichaelJackson;
	BonJovi.printRockStar();
	Band CoolBand;
	CoolBand.addStar(MichaelJackson);//add gurmi ?? da ne ti dreme...

}

//6.0