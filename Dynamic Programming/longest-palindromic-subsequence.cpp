#include <bits/stdc++.h>
using namespace std;

int helper(string A)
{
    int l = A.length();
    vector<vector<int>> dp(l, (vector<int>(l, -1)));
    for (int i = 0; i < l; i++)
    {
        dp[i][i] = 1;
    }
    for (int block = 2; block <= l; block++)
    {
        for (int left = 0; left <= l - block; left++)
        {
            int right = left + block - 1;
            if (A[left] == A[right])
            {
                if (left + 1 == right)
                {
                    dp[left][right] = 2;
                }
                else
                {
                    dp[left][right] = 2 + dp[left + 1][right - 1];
                }
            }
            else
            {
                dp[left][right] = max(dp[left + 1][right], dp[left][right - 1]);
            }
        }
    }
    return dp[0][l - 1];
}

int main()
{
    string A;
    cin >> A;

    int ans = helper(A);

    cout << ans << endl;
    return 0;
}