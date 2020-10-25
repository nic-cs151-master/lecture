#include <iostream>
using namespace std; 

class NumberArray
{
public:
    NumberArray(int size, double value);
    // ~NumberArray(){ if (arraySize > 0) delete [ ] aPtr;}
    // Commented out to avoid problems with the 
    // default copy constructor
    void print() const;
    void setValue(double value);

private:
    double *aPtr;
    int arraySize;
};