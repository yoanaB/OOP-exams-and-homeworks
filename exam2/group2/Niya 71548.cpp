#include <iostream>
#include<cassert>
#include<csting>

using namespace std;

class Player
{
private:
	char* name;
	int atlet;
	int discipline;
	int skill;
public:
	Player(char* = "", int = 0, int = 0, int = 0);
	virtual ~Player() = 0;
	Player(const Player&);
	Player& operator= (const Player&);
	void setName(char*);
	char* getName() const;
	virtual char* getType() const = 0;
	virtual double getSalary() const = 0;
	virtual int getFailure() const = 0;
	virtual int getPotential() const = 0;
	int getAtlet() const;
	int getDiscipline() const;
	int getSkill() const;
};
Player::Player(char* name, int atlet, int discipline, int skill):
name(NULL)
{
	this->setName(name);
	this->atlet = atlet;
	this->discipline = discipline;
	this->skill = skill;

}
Player::~Player()
{
	delete[] this->name;
}
Player::Player(const Player& other) : name(NULL)
{
	this->setName(other.name);
	this->atlet = other.atlet;
	this->discipline = other.discipline;
	this->skill = other.skill;
}
Player& Player:: operator= (const Player& other)
{
	if (this != &other)
	{
		this->setName(other.name);
		this->atlet = other.atlet;
		this->discipline = other.discipline;
		this->skill = other.skill;
	}
	return *this;
}
void Player::setName(char* name)
{
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	assert(this->name != NULL);
	strcpy(this->name, name);
}
char* Player::getName() const
{
	return this->name;
}
int Player::getAtlet() const
{
	return this->atlet;
}
int Player::getDiscipline() const
{
	return this->discipline;
}
int Player::getSkill() const
{
	return this->skill
}

class FutboolPlayer: public Player
{
private:
	double salary;
public:
	FutboolPlayer(char* = "", int = 0, int = 0, int = 0, double = 0);
	char* getType() const;
	double getSalary() const;
	int getFailure() const;
	int getPotential() const;


};
FutboolPlayer::FutboolPlayer(char* name, int atlet, int discipline, int skill, double salary) :Player(name,atlet,discipline,skill)
{
	this->salary = salary;
}
char* FutboolPlayer::getType() const
{
	// different requirements you had...
	char* type = "Futbolist";
	return type;

}
double FutboolPlayer:: getSalary() const
{
	return this->salary;
}
int FutboolPlayer::getFailure() const
{
	return ((this->getDiscipline)-(this->getSkill));
}
int FutboolPlayer::getPotential() const
{
	return((this->getAtlet) + (this->getDiscipline) + (this->getSkill));
}

class VolleyballPlayer : public Player
{
private:
	double salary;
public:
	VolleyballPlayer(char* name, int atlet, int discipline, int skill, double salary) ;
	char* getType() const;
	double getSalary() const;
	int getFailure() const;
	int getPotential() const;


};
VolleyballPlayer::VolleyballPlayer(char* name, int atlet, int discipline, int skill, double salary) :Player(name, atlet, discipline, skill)
{
	this->salary = salary;
}
char* VolleyballPlayer::getType() const
{
	char* type1 = "Volleyball";
	return type1;
}
double VolleyballPlayer::getSalary() const
{
	return(salary * 30);
}
int VolleyballPlayer::getFailure() const
{
	return((this->getDiscipline) - (this->getAtlet) - (this->getSkill));
}
int VolleyballPlayer::getPotential() const
{
	return((this->getDiscipline) + (this->getAtlet) + (this->getSkill));
}

class Team
{
private:
	char* Teamname;
protected:
	Player** players;
	int size;
	int max_size;
public:
	Team(char* = "");
	virtual  ~Team() = 0;
	Team(const Team&);
	Team& operator=(const Team&);
	void setTeamname(char*);
	char* getTeamname() const;
	virtual bool add() = 0;
	virtual bool remove() = 0;
	virtual double money() = 0;

};

void Team::setTeamname(char* Teamname)
{
	delete[] this->Teamname;
	this->Teamname = new char[strlen(Teamname) + 1];
	assert(this->Teamname != NULL);
	strcpy(this->Teamname, Teamname);
}
char* Team::getTeamname() const
{
	return this->Teamname;
}
Team::Team(char* name) : Teamname(NULL)
{
	this->setTeamname(Teamname);
	this->size = 0;
	this->max_size = 1;
	this->players = new Player*[max_size];
}
Team::~Team()
{
	delete[] Teamname;
}
Team::Team(const Team& other) :Teamname(NULL)
{
	this->setTeamname(other.Teamname);
	this->size = other.size;
	this->max_size = other.max_size;
	this->players = new Player*[max_size];
	for (int i = 0; i < size; i++)
	{
		this->players[i] = other.players[i];
	}
}

Team& Team:: operator=(const Team& other)
{
	if (this != &other)
	{
		this->setTeamname(other.Teamname);
		this->size = other.size;
		this->max_size = other.max_size;
		// some delete: 
		// - 0.3
		this->players = new Player*[max_size];
		for (int i = 0; i < size; i++)
		{
			this->players[i] = other.players[i];
		}
	}
	return *this;
}

class FutboolTeam: public Team
{
public:
	bool add(FutboolPlayer k)
	{
		// not exactly
		// - 0.2
		if (max_size = size)
		{
			Player** tmp = new Player*[max_size];
			for (int i = 0; i < size; i++)
			{
				tmp[i] = players[i];
			}
			for (int i = 0; i < size; i++)
			{
				delete players[i];
			}
			delete[] this->players;

			max_size *= 2;
			players = new Player*[max_size];
			for (int i = 0; i < size; i++)
			{
				players[i] = tmp[i];
			}
			for (int i = 0; i < size; i++)
			{
				delete tmp[i];
			}
			delete[] tmp;
		}
		if (!strcmp(k.getType(), "futbolist"))
		{
			players[size] = &k;
			return true;
		}
		else
		{
			return false;
		}
	}

	//not finished
	// - 0.3
	bool remove(FutboolPlayer k)
	{
		for (int i = 0; i < size; i++)
		{
			//what??
			if (k.getName())
			{
				int size = 0;
				int max_size = 1;
				players = new Player *[max_size];
				for (int j = 0; j < size; j++)
				{
					if

	// not finished
	// -0.2		
	double money()
	{
		double expences = 0;
		for (int i = 0; i < size; i++)
		{
			expences +=




		}
	}
};

class VolleyboolTeam : public Team
{
public:
	bool add(VolleyballPlayer p)
	{
		//....
		if (max_size = size)
		{
			Player** tmp = new Player*[max_size];
			for (int i = 0; i < size; i++)
			{
				tmp[i] = players[i];
			}
			for (int i = 0; i < size; i++)
			{
				delete players[i];
			}
			delete[] this->players;

			max_size *= 2;
			players = new Player*[max_size];
			for (int i = 0; i < size; i++)
			{
				players[i] = tmp[i];
			}
			for (int i = 0; i < size; i++)
			{
				delete tmp[i];
			}
			delete[] tmp;
		}
		if (!strcmp(p.getType(), "volleyball"))
		{
			players[size] = &p;
			return true;
		}
		else
		{
			return false;
		}
	}

	// last class not finished:
	// - 0.5

// 4.7