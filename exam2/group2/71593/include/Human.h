#ifndef HUMAN_H
#define HUMAN_H


class Human
{
    public:
        Human();
        Human (const char*, int, int, Human **, int);
        virtual ~Human();
        Human (const Human&);
        Human& operator= (Human&);

        void setName (const char*);
        const char* getName () const;

        void setSila (int);
        int getSila () const;
        void namalqvaneSila (int);


        void setLoyalnost (int);
        void removeFriend (const Human&);
        virtual void addFriend (Human*);
        virtual int getLoyalnost () const;
        virtual const char* getSpecialSkill () const = 0;
        virtual int getOcenkaOtmashtenie () const = 0;
        virtual char* getType () const = 0;
    private:
        char* name;
        int sila;
    protected:
        Human** priqteli;
        int size, capacity;
        int loyalnost;
};

#endif // HUMAN_H
