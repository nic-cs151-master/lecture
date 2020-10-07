#include <iostream>

using namespace std;

void countDown(int num);
void towerOfHanoi(int n, char from_rod, char to_rod, char extra_rod);

int main()
{
    // countDown(5);
    towerOfHanoi(7, 'A', 'C', 'B');

    return 0;
}

void towerOfHanoi(int n, char from_rod, char to_rod, char extra_rod)
{
    if (n == 1)
    {
        cout << "Move Disk " << n << " from peg " << from_rod << " to peg " << to_rod << '\n';
    }
    else
    {
        towerOfHanoi(n - 1, from_rod, extra_rod, to_rod);
        cout << "Move Disk " << n << " from peg " << from_rod << " to peg " << to_rod << '\n';
        towerOfHanoi(n - 1, extra_rod, to_rod, from_rod);
    }
}

void countDown(int num)
{ 	
   if (num == 0)
   {
      cout << "Blastoff!";
   }
   else
   { 
      countDown(num-1); // recursive call
      cout << num << ". . .";
   }              
}