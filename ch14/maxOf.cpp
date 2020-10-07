#include <iostream>
#include <vector>
using namespace std;

int maxOf(const vector<int> &numbers);
int maxOf2(const vector<int> &numbers);
vector<int> subList(const vector<int> &v, int m, int n);

int main()
{
    vector<int> elems{137, 271, 828, 182, 200, 983, 1023, 33, 12, 103};
    cout << maxOf(elems) << endl;
    cout << maxOf2(elems) << endl;
    return 0;
}

int maxOf2(const vector<int> &numbers)
{
    if (numbers.size() == 1)
    {
        return numbers[0];
    }
    else
    {
        // cout << "size: " << numbers.size() << '\n';
        int half = numbers.size() / 2;
        // cout << half << ' ' << numbers.size() - 1 << '\n';
        vector<int> upper = subList(numbers, 0, half-1);
        vector<int> lower = subList(numbers, half, numbers.size()-1);
        return max(maxOf2(upper), maxOf2(lower));
    }
}

int maxOf(const vector<int> &numbers)
{
    if (numbers.size() == 1)
    {
        return numbers[0];
    }
    else
    {
        int first = numbers[0];
        vector<int> rest = subList(numbers, 1, numbers.size()-1);
        return max(first, maxOf(rest));
    }
    
}

vector<int> subList(const vector<int> &v, int m, int n)
{
    auto first = v.cbegin() + m;
    auto last = v.cbegin() + n + 1;

    vector<int> subVec(first, last);
    return subVec;
}