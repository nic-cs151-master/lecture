/**
 * @file towerOfHanoi.cpp
 * @author Gabe de la Cruz
 * @brief  Program solves the Tower of Hanoi problem.
 * @version 0.1
 * @date 2020-09-28
 * 
 */
#include <iostream>
using namespace std;

void towerOfHanoi(int n, char from_rod, char to_rod, char extra_rod);

int main()
{
    towerOfHanoi(7, 'A', 'C', 'B');

    return 0;
}

/**
 * @brief This function prints out the steps to solve the
 *        Tower of Hanoi problem. This is implemented as
 *        a recursive function that moves disks from the initial
 *        peg *from_rod* to the destination peg *to_rod*
 *        where there is one extra peg *extra_rod*.
 * 
 * @param n          number of disks in the initial peg
 * @param from_rod   initial peg
 * @param to_rod     destination/target peg
 * @param extra_rod  extra peg
 */
void towerOfHanoi(int n, char from_rod, char to_rod, char extra_rod)
{
    if (n == 1)
    {
        cout << "Move Disk " << n 
             << " from peg " << from_rod 
             << " to peg " << to_rod << '\n';
    }
    else
    {
        towerOfHanoi(n - 1, from_rod, extra_rod, to_rod);
        cout << "Move Disk " << n 
             << " from peg " << from_rod 
             << " to peg " << to_rod << '\n';
        towerOfHanoi(n - 1, extra_rod, to_rod, from_rod);
    }
}