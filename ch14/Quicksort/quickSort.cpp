/**
 * @file quickSort.cpp
 * @author Gabe de la Cruz
 * @brief This program demonstrates implementation of 
 *        the recursive quicksort algorithm, where the
 *        last element is always the pivot.
 * @version 0.1
 * @date 2020-09-28
 * 
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <stack>
using namespace std::chrono;
using namespace std;

const int NUM_ITEMS = 10;

struct Range
{
    int start;
    int end;
    Range(){}
    Range(int s, int e)
    {
        start = s;
        end = e;
    }
};

int partition(vector<string>& A, int lo, int hi);
void quickSort(vector<string>& A, int lo, int hi);
int binarySearchString(const vector<string>& list, string value);

int main()
{
    // int array[] = {4, 3, 42, 17, 666, 123, 69, 72, 9, 12};
    vector<string> words;
    ifstream inputFile;

    inputFile.open("words_notsorted.txt");

    if (inputFile)
    {
        while (!inputFile.eof())
        {
            string word;
            getline(inputFile, word);
            words.push_back(word);
        }
        inputFile.close();
    }

    // sort here
    cout << "Sorting initiated...\n";
    quickSort(words, 0, words.size() - 1);
    cout << "Sorting completed\n";

    char repeat = 'y';
    while (repeat != 'n')
    {
        string searchString;
        cout << "Search word: ";
        getline(cin, searchString);

        auto start = high_resolution_clock::now();
        int position = binarySearchString(words, searchString);
        auto stop = high_resolution_clock::now();

        if (position == -1)
        {
            cout << "Value not found!\n";
        }
        else
        {
            cout << "Binary Value found at position " << position << '\n';
            cout << searchString << "=" << words[position] << '\n';
        }
        duration<double, milli> fp_ms = stop - start;
        cout << "Time taken for Binary: "
                << fp_ms.count() << " ms" << endl;

        cout << "Again?";
        repeat = cin.get();
    }
    
    return 0;
}

int partition(vector<string>& A, int lo, int hi)
{
    int pivot = hi;
    int i = lo - 1;
    int j = hi;

    while (1)
    {
        do
        {
            i = i + 1;
        } while (A[i] < A[pivot]);

        do
        {
            j = j - 1;
        } while (A[j] > A[pivot]);

        if (i >= j)
            break;
        
        string temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
    string temp = A[i];
    A[i] = A[hi];
    A[hi] = temp;
    return i;
}

void quickSort(vector<string>& A, int lo, int hi)
{
    if (lo < hi)
    {
        int pivot = partition(A, lo, hi);
        quickSort(A, lo, pivot - 1);
        quickSort(A, pivot + 1, hi);
    }
}

int binarySearchString(const vector<string>& list, string value)
{
    int first = 0;
    int last = list.size() - 1;
    bool found = false;
    int position = -1; // Why -1?
    while (found == false && first <= last)
    {
        int middle = (first + last) / 2;
        if (list[middle] == value)
        {
            found = true;
            position = middle;
        }
        else if (list[middle] > value)
        {
            last = middle - 1;
        }
        else
        {
            first = middle + 1;
        }
    }
    return position;
}