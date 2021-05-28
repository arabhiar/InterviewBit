#include <bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>> A)
{
    int n = A.size(), m = A[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    int maxLength = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = A[i][j];
                maxLength = max(maxLength, dp[i][j]);
            }
            else
            {
                if (A[i][j] == 1)
                {
                    dp[i][j] = 1 + min(min(dp[i - 1][j], dp[i - 1][j - 1]), dp[i][j - 1]);
                    maxLength = max(maxLength, dp[i][j]);
                }
            }
        }
    }
    return maxLength * maxLength;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> A(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> A[i][j];

    cout << helper(A);

    cout << endl;
    return 0;
}