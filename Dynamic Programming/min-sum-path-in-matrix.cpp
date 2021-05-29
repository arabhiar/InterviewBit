#include <bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>> A)
{
    int m = A.size(), n = A[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    if (m == 0 || n == 0)
        return 0;
    dp[0][0] = A[0][0];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i >= 1 && j >= 1)
            {
                dp[i][j] = A[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
            else if (i == 0 && j != 0)
            {
                dp[i][j] = A[i][j] + dp[i][j - 1];
            }
            else if (j == 0 && i != 0)
            {
                dp[i][j] = A[i][j] + dp[i - 1][j];
            }
        }
    }
    return dp[m - 1][n - 1];
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