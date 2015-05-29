#ifndef CONCERT_H
#define CONCERT_H


class Concert
{
    public:
        Concert();
        Concert(Band&);
        Concert(Concert&);
        ~Concert();
        Concert& operator= (Concert&);

        double averageAwesomeness () const;
        Band& headliners () const;
    private:
        Band* arr;
        unsigned size, maxSize;
};

#endif // CONCERT_H
