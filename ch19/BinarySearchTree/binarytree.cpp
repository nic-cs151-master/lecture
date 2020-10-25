/**@file   binarytree.cpp
 * @author CS151 North Idaho College
 * @date   2020/10/12
 */
#include "binarytree.h"

BinaryTree::BinaryTree()
{
    mRoot = nullptr;
}

BinaryTree::~BinaryTree()
{}

void BinaryTree::insert(DATA_TYPE newData)
{
    // tree is empty
    if (mRoot == nullptr)
    {
        mRoot = new TreeNode(newData);
    }
    else
    {
        TreeNode *treePtr = mRoot;
        TreeNode *prevPtr = nullptr;

        while (treePtr != nullptr)
        {
            prevPtr = treePtr;
            if (newData == treePtr->data)
            {
                return;
            }

            if (newData > treePtr->data)
            {
                treePtr = treePtr->right;
            }
            else
            {
                treePtr = treePtr->left;
            }
        }

        if (newData > prevPtr->data)
        {
            prevPtr->right = new TreeNode(newData);
        }
        else
        {
            prevPtr->left = new TreeNode(newData);
        }
    }
}

bool BinaryTree::search(DATA_TYPE value)
{
    if (mRoot == nullptr)
    {
        return false;
    }
    else
    {
        TreeNode *ptr = mRoot;

        while (ptr != nullptr)
        {
            if (value == ptr->data)
            {
                return true;
            }
            else if (value < ptr->data)
            {
                ptr = ptr->left;
            }
            else
            {
                ptr = ptr->right;
            }
        }
        
        return false;
    }
}

bool BinaryTree::searchR(DATA_TYPE value)
{
    return searchR(mRoot, value);
}

bool BinaryTree::searchR(TreeNode *ptr, DATA_TYPE value)
{
    if (ptr == nullptr)
    {
        return false;
    }
    else if (ptr->data == value)
    {
        return true;
    }
    else
    {
        if (value > ptr->data)
        {
            return searchR(ptr->right, value);
        }
        else
        {
            return searchR(ptr->left, value);
        }
    }
}

void BinaryTree::insertR(DATA_TYPE newData)
{
    insertR(mRoot, newData);
}

void BinaryTree::insertR(TreeNodePtr &ptr, DATA_TYPE newData)
{
    if (ptr == nullptr)
    {
        ptr = new TreeNode(newData);
        return;
    }
    else
    {
        // duplicate data
        if (newData == ptr->data)
        {
            return;
        }

        if (newData > ptr->data)
        {
            insertR(ptr->right, newData);
        }
        else
        {
            insertR(ptr->left, newData);
        }
    }
}

string BinaryTree::toStringInOrder()
{
    ostringstream ostr("");
    toStringInOrder(mRoot, ostr);
    return ostr.str();
}

string BinaryTree::toStringPreOrder()
{
    ostringstream ostr("");
    toStringPreOrder(mRoot, ostr);
    return ostr.str();
}

string BinaryTree::toStringPostOrder()
{
    ostringstream ostr("");
    toStringPostOrder(mRoot, ostr);
    return ostr.str();
}

void BinaryTree::toStringInOrder(TreeNode *ptr, ostringstream &ostr)
{
    // base case
    if (ptr == nullptr)
    {
        return;
    }
    else
    {
        toStringInOrder(ptr->left, ostr);
        ostr << ptr->data << ' ';
        toStringInOrder(ptr->right, ostr);
    } 
}

void BinaryTree::toStringPreOrder(TreeNode *ptr, ostringstream &ostr)
{
    // base case
    if (ptr == nullptr)
    {
        return;
    }
    else
    {
        ostr << ptr->data << ' ';
        toStringPreOrder(ptr->left, ostr);
        toStringPreOrder(ptr->right, ostr);
    } 
}

void BinaryTree::toStringPostOrder(TreeNode *ptr, ostringstream &ostr)
{
    // base case
    if (ptr == nullptr)
    {
        return;
    }
    else
    {
        toStringPostOrder(ptr->left, ostr);
        toStringPostOrder(ptr->right, ostr);
        ostr << ptr->data << ' ';
    } 
}

bool BinaryTree::isLeaf(TreeNode *ptr)
{   
    return (ptr->left == nullptr && ptr->right == nullptr);
}

void BinaryTree::remove(DATA_TYPE value)
{
    removeR(mRoot, value);
}

void BinaryTree::removeR(TreeNodePtr &ptr, DATA_TYPE value)
{
    if (ptr == nullptr)
    {
        return;
    }

    // recursive case to find the value
    if (value > ptr->data)
    {
        removeR(ptr->right, value);
    }
    else if (value < ptr->data)
    {
        removeR(ptr->left, value);
    }
    else
    {
        // value found
        deleteNode(ptr);
    }
} 

void BinaryTree::deleteNode(TreeNodePtr &nodePtr)
{
    // 1st case: leaf node
    if (isLeaf(nodePtr))
    {
        delete nodePtr;
        nodePtr = nullptr;
    }
    // 2nd case: one child
    // 2a left child
    else if (nodePtr->left == nullptr)
    {
        // child to the right
        TreeNode *tempPtr = nodePtr;
        nodePtr = nodePtr->right;
        tempPtr->right = nullptr;
        delete tempPtr;
    }
    // 2b right child
    else if (nodePtr->right == nullptr)
    {
        // child to the left
        TreeNode *tempPtr = nodePtr;
        nodePtr = nodePtr->left;
        tempPtr->left = nullptr;
        delete tempPtr;
    }

    // 3rd case: two child
    else
    {
        // two children
        DATA_TYPE minValue = processInOrderSuccessor(nodePtr->right);
        nodePtr->data = minValue;
    }

}

DATA_TYPE BinaryTree::processInOrderSuccessor(TreeNodePtr &ptr)
{
    if (ptr->left != nullptr)
    {
        return processInOrderSuccessor(ptr->left);
    }
    else // reach nullptr
    {
        DATA_TYPE minValue = ptr->data;

        // 1st case: leaf node
        if (isLeaf(ptr))
        {
            delete ptr;
            ptr = nullptr;
        }
        // 2nd case: one child
        // 2a left child
        else
        {
            // child to the right
            TreeNode *tempPtr = ptr;
            ptr = ptr->right;
            tempPtr->right = nullptr;
            delete tempPtr;
        }

        return minValue;
    }
}