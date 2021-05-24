#include <bits/stdc++.h>
using namespace std;

bool helper(vector<int> A)
{
    vector<bool> dp(A.size(), false);
    dp[0] = true;
    for (int i = 0; i < A.size() - 1; i++)
    {
        if (dp[i] == false)
        {
            break;
        }
        for (int j = i + 1; j <= i + A[i]; j++)
        {
            dp[j] = true;
        }
    }
    return dp[A.size() - 1];
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    cout << helper(A);

    cout << endl;
    return 0;
}