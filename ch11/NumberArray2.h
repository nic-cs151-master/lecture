#include <iostream>
using namespace std; 

class NumberArray
{
public:
    NumberArray(const NumberArray &obj);
    NumberArray(int size, double value);

    ~NumberArray() 
    { 
        if (arraySize > 0) delete [] aPtr; 
    }

    void print() const;
    void setValue(double value);

private:
    double *aPtr;
    int arraySize;
};