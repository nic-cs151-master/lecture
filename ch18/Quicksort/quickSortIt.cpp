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

void quickSortIt(vector<string>& A)
{
    stack<Range> myStack;

    // push Range(0, size-1) onto stack
    myStack.push(Range(0, A.size() - 1));

    // while stack not empty
    while (!myStack.empty())
    {
        // pop a range r from stack
        Range r = myStack.top();
        myStack.pop(); // deletes only, does not return value

        // if r is not empty
        if (r.start < r.end)
        {
            // partition the range r into
            int pivot = partition(A, r.start, r.end);
            // smaller ranges
            // push the 2 smaller range to stack
            myStack.push(Range(r.start, pivot - 1));
            myStack.push(Range(pivot + 1, r.end));
        } // End if
    } // End while
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
    // quickSort(words, 0, words.size() - 1);
    quickSortIt(words);
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