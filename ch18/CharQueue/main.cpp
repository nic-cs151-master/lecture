#include <iostream>
#include "queue.h"
using namespace std;

int main()
{
    Queue myQueue;

    myQueue.enqueue('C');
    myQueue.enqueue('A');
    myQueue.enqueue('R');
    myQueue.enqueue('E');
    myQueue.enqueue('F');
    
    cout << "Front: " << myQueue.front() << '\n';
    cout << "Back: " << myQueue.back() << '\n';

    myQueue.dequeue();
    myQueue.dequeue();
    cout << "Front: " << myQueue.front() << '\n';
    cout << "Back: " << myQueue.back() << '\n';

    myQueue.enqueue('U');
    myQueue.enqueue('L');
    cout << "Front: " << myQueue.front() << '\n';
    cout << "Back: " << myQueue.back() << '\n';


    return 0;
}