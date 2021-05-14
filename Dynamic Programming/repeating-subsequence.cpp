#include <bits/stdc++.h>
using namespace std;

int helper(string A)
{
    int l = A.length();
    vector<vector<int>> dp(l + 1, vector<int>(l + 1, 0));
    for (int i = 1; i <= l; i++)
    {
        for (int j = 1; j <= l; j++)
        {
            if (A[i - 1] == A[j - 1] && i != j)
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    return dp[l][l];
}

int main()
{
    string A;
    cin >> A;

    int ans = helper(A) > 1 ? 1 : 0;
    
    cout << ans;
    cout << endl;
    return 0;
}