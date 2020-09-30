/**
 * @file simplelist.cpp
 * @author Gabe de la Cruz
 * @brief Introduction to linked list. A very
 *        basic implementation.
 * @version 0.1
 * @date 2020-09-29
 * 
 */
#include <iostream>
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
    Node *head = nullptr; // empty list

    head = new Node(5, head);
    // head->data = 5;
    // head->next = nullptr;

    head = new Node(13, head);
    // Node *newNode = new Node;
    // newNode->data = 13;
    // newNode->next = head;
    // head = newNode;

    head = new Node(24, head);
    head = new Node(92, head);

    // cout << "1st node's value: " << head->data << '\n';
    // cout << "2nd node's value: " << head->next->data << '\n';
    // cout << "3rd node's value: " << head->next->next->data << '\n';
    // cout << "4th node's value: " << head->next->next->next->data << '\n';

    Node *nodePtr = head;
    while (nodePtr != nullptr)
    {
        cout << nodePtr->data << ' ';
        nodePtr = nodePtr->next;
    }
    cout << '\n';

    return 0;
}