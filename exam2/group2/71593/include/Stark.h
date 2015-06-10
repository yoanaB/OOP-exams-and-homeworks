#ifndef STARK_H
#define STARK_H

#include <Human.h>


class Stark : virtual public Human
{
    public:
        Stark();
        void setAge (int);
        int getAge()const;
        virtual void addFriend (Human*);
        virtual int getLoyalnost () const;
        virtual const char* getSpecialSkill () const ;
        virtual int getOcenkaOtmashtenie () const;
        virtual char* getType () const;
        void setLoyalnost (int);
};

#endif // STARK_H
