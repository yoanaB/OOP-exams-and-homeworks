#ifndef HUMAN_H
#define HUMAN_H

//Encapsulation, Inheritance, Polymorphism, Abstraction


class Human{

public:
	Human(const char* = "", size_t = 0, size_t = 0);
	Human(const Human&);
	Human& operator=(const Human&);
	virtual ~Human();

	void setName(const char*);
	void setStrength(size_t);
	virtual void setLoyalty(size_t);

	virtual size_t getStrength() const;
	virtual size_t getLoyalty() const;
	const char* getName() const;

	virtual void reduceStrength(size_t);

	virtual size_t revenge() const=0;
	virtual const char* getSpecialSkill() const = 0;

	virtual Human* clone() const = 0;



protected:
	size_t size;

private:
	char* name;
	size_t strength;
	size_t loyalty;



	void copyFriends(const Human&){};
};


#endif