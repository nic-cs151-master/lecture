/**
 * @file   main.cpp
 * @author CS151 North Idaho College
 * @date   2020/10/12
 */
#include <iostream>
#include "binarytree.h"

using namespace std;

int main()
{
    BinaryTree myTree;

    // myTree.insertR("John");
    // myTree.insertR("Kevin");
    // myTree.insertR("Jim");
    // myTree.insertR("Paul");
    // myTree.insertR("Maria");
    // cout << "In order: " << myTree.toStringInOrder() << '\n';

    myTree.insert(50);
    myTree.insert(30);
    myTree.insert(70);
    myTree.insert(20);
    myTree.insert(40);
    myTree.insert(60);
    myTree.insert(80);
    myTree.insert(55);
    myTree.insert(65);
    myTree.insert(90);
    myTree.insert(59);
    myTree.insert(85);
    myTree.insert(95);
    myTree.insert(75);
    myTree.insert(72);
    
    cout << "In order: " << myTree.toStringInOrder() << '\n';
    cout << "Post order: " << myTree.toStringPostOrder() << '\n';
    cout << "Pre order: " << myTree.toStringPreOrder() << '\n';

    cout << "search for 85: " << myTree.search(85) << '\n';
    cout << "searchR for 85: " << myTree.searchR(85) << '\n';
    cout << "search for 25: " << myTree.search(25) << '\n';
    cout << "searchR for 25: " << myTree.searchR(25) << '\n';

    myTree.remove(20);
    myTree.remove(55);
    myTree.remove(50);
    myTree.remove(70);
    cout << "In order: " << myTree.toStringInOrder() << '\n';
    cout << "Post order: " << myTree.toStringPostOrder() << '\n';
    cout << "Pre order: " << myTree.toStringPreOrder() << '\n';

    return 0;
}