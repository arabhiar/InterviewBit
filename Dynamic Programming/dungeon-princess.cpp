#include <bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>> A)
{
    int m = A.size(), n = A[0].size();
    vector<vector<int>> dp(m, vector<int>(n));
    dp[m - 1][n - 1] = A[m - 1][n - 1] < 0 ? abs(A[m - 1][n - 1]) + 1 : 1;
    for (int i = m - 2; i >= 0; i--)
    {
        dp[i][n - 1] = max(dp[i + 1][n - 1] - A[i][n - 1], 1);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        dp[m - 1][i] = max(dp[m - 1][i + 1] - A[m - 1][i], 1);
    }
    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            dp[i][j] = max(min(dp[i + 1][j], dp[i][j + 1]) - A[i][j], 1);
        }
    }
    return dp[0][0];
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> A(m, vector<int>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    cout << helper(A);

    cout << endl;
    return 0;
}