/**
 * @file pr12-14.cpp
 * @author Gabe de la Cruz
 * @remark Adapted from Gaddis book
 * @brief This program prints its environment variables.
 * @version 0.1
 * @date 2020-09-16
 * 
 */
#include <iostream>
using namespace std; 

int main(int argc, char** argv)
{
    extern char **environ;

    int k = 0;
    while (environ[k] != 0)
    {
        cout << environ[k] << "\n";
        k++;
    }
    return 0;
}

