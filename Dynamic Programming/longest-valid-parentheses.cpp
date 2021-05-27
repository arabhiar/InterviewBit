#include <bits/stdc++.h>
using namespace std;

int helper(string A)
{
    stack<int> s;
    s.push(-1);
    int maxLen = 0;
    for (int i = 0; i < A.length(); i++)
    {
        if (A[i] == '(')
            s.push(i);
        else
        {
            s.pop();
            if (s.empty())
            {
                s.push(i);
            }
            else
            {
                int currLen = i - s.top();
                maxLen = max(maxLen, currLen);
            }
        }
    }
    return maxLen;
}

int main()
{
    string A;
    cin >> A;

    cout << helper(A);

    cout << endl;
    return 0;
}