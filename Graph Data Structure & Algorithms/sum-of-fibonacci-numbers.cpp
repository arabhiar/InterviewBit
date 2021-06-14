#include <bits/stdc++.h>
using namespace std;

int helper(int A)
{
    if (A == 1)
    {
        return 1;
    }
    if (A == 2)
    {
        return 1;
    }
    vector<int>fib;
    fib.push_back(1);
    fib.push_back(2);
    int prev = 1, curr = 2;
    while (curr <= A)
    {
        int temp = curr;
        curr += prev;
        prev = temp;
        fib.push_back(curr);
    }
    fib.pop_back();
    int count = 0;
    int idx = fib.size() - 1;
    while (A)
    {
        if (A - fib[idx] >= 0)
        {
            A -= fib[idx];
            count++;
        }
        else
        {
            idx--;
        }
    }
    return count;
}

int main()
{
    int A;
    cin >> A;

    cout << helper(A);

    cout << endl;
    return 0;
}