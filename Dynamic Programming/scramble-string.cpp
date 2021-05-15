#include <bits/stdc++.h>
using namespace std;

bool helper(string A, string B, unordered_map<string, bool> &memo)
{
    int l1 = A.length(), l2 = B.length();
    if (l1 != l2)
        return false;
    if (A == B)
        return true;
    if (memo.find(A + B) != memo.end())
    {
        return memo[A + B];
    }
    for (int i = 1; i < l1; i++)
    {
        if (helper(A.substr(0, i), B.substr(0, i), memo) && helper(A.substr(i), B.substr(i), memo))
        {
            // no swapping
            memo[A + B] = true;
            return true;
        }
        if (helper(A.substr(0, i), B.substr(l2 - i), memo) && helper(A.substr(i), B.substr(0, l2 - i), memo))
        {
            // swapping
            memo[A + B] = true;
            return true;
        }
    }
    memo[A + B] = false;
    return false;
}

int main()
{
    string A, B;
    cin >> A >> B;

    unordered_map<string, bool> memo;
    cout << helper(A, B, memo);

    cout << endl;
    return 0;
}