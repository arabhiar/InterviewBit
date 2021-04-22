#include <bits/stdc++.h>
using namespace std;

int main()
{
    string A;
    cin >> A;

    unordered_set<char> s;
    int start = 0, end = 0, maxLen = INT_MIN;
    while (end < A.length())
    {
        if (s.find(A[end]) == s.end())
        {
            // not found
            s.insert(A[end]);
            end++;
        }
        else
        {
            // found
            while (A[start] != A[end])
            {
                s.erase(A[start]);
                start++;
            }
            s.erase(A[start]);
            s.insert(A[end]);
            end++;
            start++;
        }
        maxLen = max(maxLen, (int)s.size());
    }

    cout << maxLen << endl;

    return 0;
}