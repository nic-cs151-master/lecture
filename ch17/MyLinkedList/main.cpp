#include <iostream>
#include "linkedlist.h"
using namespace std;

int main()
{
    LinkedList list;

    list.add(234.23);
    list.add(24.34);
    list.add(565.23);
    list.add(452.645);
    list.add(3);
    list.add(546.2);

    cout << list.toString() << '\n';
    list.toString2();

    list.remove(234.23);
    list.remove(3);

    cout << list.toString() << '\n';

    return 0;
}