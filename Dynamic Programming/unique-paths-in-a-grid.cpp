#include <bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>> A)
{
    int n = A.size(), m = A[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    if (n == 0 || m == 0)
        return 0;
    dp[0][0] = A[0][0] == 1 ? 0 : 1;
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {
            if (A[i][j] == 1)
            {
                dp[i][j] = 0;
            }
            else if (i >= 1 && j >= 1)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
            else if (i == 0 && j != 0)
            {
                dp[i][j] = dp[i][j - 1];
            }
            else if (j == 0 && i != 0)
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n - 1][m - 1];
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