#include <bits/stdc++.h>
using namespace std;

int helper(int A)
{
    vector<int> dp(A, 0);
    dp[0] = 1;
    dp[1] = 2;
    for (int i = 2; i < A; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[A - 1];
}

int main()
{
    int A;
    cin >> A;

    cout << helper(A);

    cout << endl;
    return 0;
}