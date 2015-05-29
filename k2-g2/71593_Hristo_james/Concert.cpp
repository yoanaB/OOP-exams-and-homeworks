#include "Concert.h"

Concert::Concert():
    arr(NULL),size(0),maxSize(0) {}

Concert::Concert(Band& other)
{
    size = 1;
    maxSize = 1;
    arr = new Band [maxSize];
    arr[0] = other;
}

Concert::Concert(Concert& other)
{
    size = other.size;
    maxSize = other.maxSize;
    arr = new Band [maxSize];
    for(int i = 0; i < size; i++)
        arr[i] = other.arr[i];
}
Concert::~Concert()
{
    delete [] arr;
}

Concert& Concert::operator= (Concert& other)
{
    // if..
    size = other.size;
    maxSize = other.maxSize;
    if(other.arr != NULL)
    {
        if(arr != NULL)
            delete [] arr;
        arr = new Band [maxSize];
        for (int i = 0; i < size; i++)
            arr[i] = other.arr[i];
    }
}


double Concert::averageAwesomeness () const
{
    int average = 0,average2;
    for(int i = 0; i < size; i++)
    {
        average2 = 0;
        for (int j = 0; j < arr[i].getSize();j++)
            average2 += arr[i].arr[j].getAwesomeness();
        average2 /= arr[i].getSize();
        average += average2;
    }
    return average / size;

}
// not exactly
// - 0.1
Band& Concert::headliners () const
{
    Band tmp = arr[0];
    int average1 = 0;
    for (int j = 0; j < arr[0].getSize();j++)
            average1 += arr[0].arr[j].getAwesomeness();
    for(int i = 1; i < size; i++)
    {
        int average2 = 0;
        for (int j = 0; j < arr[i].getSize();j++)
            average2 += arr[i].arr[j].getAwesomeness();
        if(average1 < average2)
        {
            tmp = arr[i];
            average1 = average2;
        }
    }
    return tmp;
}

//5.6