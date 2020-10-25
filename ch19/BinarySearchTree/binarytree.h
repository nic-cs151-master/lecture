/**
 * @file   binarytree.h
 * @author CS151 North Idaho College
 * @date   2020/10/12
 */
#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

typedef int DATA_TYPE;

struct TreeNode
{
    DATA_TYPE data;
    TreeNode *left;
    TreeNode *right;
    TreeNode() {}
    TreeNode(DATA_TYPE data1, TreeNode *left1 = nullptr, TreeNode *right1 = nullptr)
    {
        data = data1;
        left = left1;
        right = right1;
    }
};

typedef TreeNode* TreeNodePtr;

class BinaryTree
{
public:
    BinaryTree();
    ~BinaryTree();

    void insert(DATA_TYPE newData);
    void insertR(DATA_TYPE newData);

    bool search(DATA_TYPE value);
    bool searchR(DATA_TYPE value);

    string toStringInOrder();
    string toStringPreOrder();
    string toStringPostOrder();

    void remove(DATA_TYPE value);

private:
    TreeNodePtr mRoot;

    // helper functions
    void insertR(TreeNodePtr &ptr, DATA_TYPE newData);
    // void insertR(TreeNode **ptr, string newData);
    void toStringInOrder(TreeNode *ptr, ostringstream &ostr);
    void toStringPreOrder(TreeNode *ptr, ostringstream &ostr);
    void toStringPostOrder(TreeNode *ptr, ostringstream &ostr);

    bool searchR(TreeNode *ptr, DATA_TYPE value);

    bool isLeaf(TreeNode *ptr);
    void removeR(TreeNodePtr &ptr, DATA_TYPE value);
    void deleteNode(TreeNodePtr &nodePtr);
    DATA_TYPE processInOrderSuccessor(TreeNodePtr &ptr);
    DATA_TYPE processInOrderPredecessor(TreeNodePtr &ptr);
};

#endif