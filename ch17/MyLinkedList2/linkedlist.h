#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <sstream>
using namespace std;

struct ListNode
{
    double value;
    ListNode* next;
    ListNode() {}
    ListNode(double val, ListNode* p=nullptr)
    {
        value = val;
        next = p;
    }
};

class LinkedList
{
public:
    LinkedList();                 // default constructor
    ~LinkedList();                // destructor
    void add(double number);
    void remove(double number);
    string toString();
    void toString2();            // recursive
    unsigned int size() const;
    unsigned int length() const;   // recursive

private:
    // member variables
    ListNode* mHead;              // list head pointer
    // ListNode* mTail;
    unsigned int mSize;           // size of the list

    // helper functions
    unsigned int getLength(ListNode* ptr) const;
    void printList(ListNode* ptr);
};


#endif