//abstraction, encapsulation, polymorphism, inheritance
#ifndef HUMAN_H
#define HUMAN_H

class Human {
protected:
	char* name;
	int strenght;
	int loyalty;
	Human* friends;

public:
	Human(const char* = "", int = 0, int = 0, Human*[]);
	Human(const char*, int, int, Human*);
	Human(const Human&);
	Human& operator = (const Human&);
	virtual ~Human();


	void setName(const char*);

	virtual char* getName()const = 0;
	virtual int getStrenght()const = 0;
	virtual int getLoyalty()const = 0;
	// wuuut
	int dicreaseStrenght(int strenght, int n){
		if (strenght >= 0){
			for (int i = 0; i > n; i--);
		}
	}

	int sumStrenght(int strenght, int soldiers){
		return soldiers*strenght;
	}

	virtual int addFriends()const;
	virtual int removeFriends()const;
	virtual char* getSpeacialSkill()const;



};

class Normal_human : public Human{

public:
	Normal_human(const char* = "", int = 0, int = 0);
	Normal_human(const char*, int, int);
	Normal_human(const Normal_human&);
	Normal_human& operator=(const Normal_human&);

	int getNoteRevenge()const;
	char* getSpecialSkill()const;
	int addFriend()const;
	int removeFriends()const;


};


class Army : public Human{
protected:
	Human* soldiers[100];
	int numberSold;
	Human* leader;

public:
	Army(Human*[], int = 0, Human*[]);
	Army(Human*, int, Human*);
	Army(const Army&);
	Army& operator=(const Army&);
	~Army();

	virtual int addSoldier()const = 0;
	virtual int removeSoldier()const = 0;
	virtual int changeLeader()const = 0;
	virtual int getNoteArmy()const = 0;


};

class Paid_Army : public Army{
private:
	int budget;
	double getSalary(int budget){
		return (budget - 0.2*budget) / numberSold;
	}

//	int sumSalary(int size, Human* soldiers [100]){
//		for (int i = 0; i <= size; i++){
//			sum += Human*[i]->soldiers;
//		}
//	}

	int sumSalary(double getSalary){
		return numberSold*getSalary;
	}

public:
	int getNoteArmy()const;


};

class Conscript_army : public Army{

};

class Targaryen : virtual public Human{
private:
	int age;
public:
	char* getName()const;
	int getLoyalty()const;
	int getStrenght()const;
	char* getSpecialSkill()const;

};

class Stark : virtual public Human{
private:
	int age;
public:
	char* getName()const;
	int getLoyalty()const;
	int getStrenght()const;
	char* getSpecialSkill()const;

};


