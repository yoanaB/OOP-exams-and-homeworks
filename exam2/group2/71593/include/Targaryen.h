#ifndef TARGARYEN_H
#define TARGARYEN_H

#include <Human.h>


class Targaryen : virtual public Human
{
    public:
        Targaryen();
        void setAge (int);
        int getAge()const;
        virtual void addFriend (Human*);
        virtual int getLoyalnost () const;
        virtual const char* getSpecialSkill () const ;
        virtual int getOcenkaOtmashtenie () const;
        virtual char* getType () const;
    protected:
        void setLoyalnost (int);
    private:
        int godini;
};

#endif // TARGARYEN_H
