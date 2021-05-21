#include <bits/stdc++.h>
using namespace std;

int helper(int A)
{
    vector<int> dp(A + 1, 0);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= A; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            int left = j - 1;
            int right = i - 1 - left;
            dp[i] += dp[left] * dp[right];
        }
    }
    return dp[A];
}

int main()
{
    int A;
    cin >> A;

    cout << helper(A);

    cout << endl;
    return 0;
}