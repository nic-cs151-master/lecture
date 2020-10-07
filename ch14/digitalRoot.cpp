#include <iostream>
using namespace std;

int digitalRoot(int n);
int sumOfDigits(int n);

int main()
{
    cout << digitalRoot(9258);
    return 0;
}

int digitalRoot(int n)
{
    if (n < 10)
    {
        return n;
    }
    else
    {
        return digitalRoot(sumOfDigits(n));
    }
}

int sumOfDigits(int n)
{
    if (n < 10)
    {
        return n;
    }
    else
    {
        return sumOfDigits(n / 10) + (n % 10);
    }
}