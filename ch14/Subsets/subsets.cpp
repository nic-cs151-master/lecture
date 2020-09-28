/**
 * @file subsets.cpp
 * @author Gabe de la Cruz
 * @remark Adapted from Stanford's CS106B course
 * @brief The program will find all combination of
 *        a set using recursive enumeration.
 * @version 0.1
 * @date 2020-09-28
 * 
 */
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_set>
using namespace std;

void listSubsetsRec(const unordered_set<char>& elems, 
                    const unordered_set<char>& chosen);
void listSubsetsWrapper(const unordered_set<char>& elems);
string toString(const unordered_set<char>& set);

int main()
{
    unordered_set<char> charSet;

    charSet.insert('A');
    charSet.insert('H');
    charSet.insert('I');

    listSubsetsWrapper(charSet);

    return 0;
}

/**
 * @brief Wrapper function for the listSubsetsRec
 *        recursive function. 
 * 
 * @param elems unordered list of data
 */
void listSubsetsWrapper(const unordered_set<char>& elems)
{
    unordered_set<char> chosen;
    listSubsetsRec(elems, chosen);
}

/**
 * @brief Returns a formatted string of the unordered
 *        set
 * 
 * @param  set     unordered set to convert to string
 * @return string  formatted string of the unordered set
 */
string toString(const unordered_set<char>& set)
{
    ostringstream ostr;
    ostr << '{';
    for (auto it = set.begin(); it != set.end(); ++it)
    {
        ostr << *it;
        if (next(it, 1) != set.end())
            ostr << ',';
    }
    ostr << '}';
    return ostr.str();
}

/**
 * @brief Recursive enumeration of the elems set, useful
 *        for enumerating all possible combinations.
 * 
 * @param elems   set with decisions yet to be made
 * @param chosen  set with decisions already made
 */
void listSubsetsRec(const unordered_set<char>& elems, 
                    const unordered_set<char>& chosen)
{
    // no decision remains
    if (elems.empty())
    {
        cout << toString(chosen) << endl;
    }
    else // try all options for next decision
    {
        auto element = elems.begin();
        unordered_set<char> remaining = elems;
        remaining.erase(*element); // exclude first element

        // Option 1: Include this element
        unordered_set<char> includingElem = chosen;
        includingElem.insert(*element);
        listSubsetsRec(remaining, includingElem);

        // Option 2: Exclude this element
        unordered_set<char> excludingElem = chosen;
        listSubsetsRec(remaining, excludingElem);
    }
}