/**
 * @file readnumbers.cpp
 * @author Gabe de la Cruz
 * @brief Read data from a file into a linked list.
 * @version 0.1
 * @date 2020-09-29
 * 
 */
#include <iostream>
#include <fstream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(){} // default constructor
    Node(int d, Node *p=nullptr)
    {
        data = d;
        next = p;
    }
};

int main()
{
    fstream in;
    
    in.open("numbers.dat", ios::in);

    if (!in)
    {
        cout << "error";
        exit(1);
    }

    Node *head = nullptr;
    int number;
    while (in >> number)
    {
        head = new Node(number, head);
    }

    // cout << "1st node's value: " << head->data << '\n';
    // cout << "2nd node's value: " << head->next->data << '\n';
    // cout << "3rd node's value: " << head->next->next->data << '\n';
    // cout << "4th node's value: " << head->next->next->next->data << '\n';

    // Node *nodePtr = head;
    // cout << "1st node's value: " << nodePtr->data << '\n';
    // nodePtr = nodePtr->next;
    // cout << "2nd node's value: " << nodePtr->data << '\n';
    // nodePtr = nodePtr->next;
    // cout << "3rd node's value: " << nodePtr->data << '\n';
    // nodePtr = nodePtr->next;
    // cout << "4th node's value: " << nodePtr->data << '\n';

    Node *nodePtr = head;
    while (nodePtr != nullptr)
    {
        cout << nodePtr->data << ' ';
        nodePtr = nodePtr->next;
    }
    cout << '\n';

    return 0;
}