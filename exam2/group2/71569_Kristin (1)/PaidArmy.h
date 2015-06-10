#ifndef PAIDARMY_H
#define PAIDARMY_H
#include "Army.h"


class PaidArmy :virtual public Army{

public:
	PaidArmy();
	PaidArmy(const Human&, size_t, size_t, size_t);
	PaidArmy(const PaidArmy&);
	PaidArmy& operator=(const PaidArmy&);
	~PaidArmy();

	void setBudget(size_t);
	size_t getBudget() const;
	void setSalary(size_t);
	size_t getSalary() const;

	void addSoldier()

	size_t getRevenge() const;

	bool operator>(const PaidArmy&);

private:

	size_t budget;
	size_t salary;

};

#endif