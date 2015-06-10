#ifndef TARGARYEN_STARK_H
#define TARGARYEN_STARK_H

#include "Stark.h"
#include "Targaryen.h"

class Targaryen_Stark:public Stark, public Targaryen
{
    public:
        Targaryen_Stark();
        virtual int getLoyalnost () const;
        virtual const char* getSpecialSkill () const ;
        virtual int getOcenkaOtmashtenie () const;
        virtual char* getType () const;
        void setLoyalnost (int);
        void setName (const char*);
        virtual void addFriend (Human*);
    protected:
    private:
};

#endif // TARGARYEN_STARK_H
