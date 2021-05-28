#include <bits/stdc++.h>
using namespace std;

// Recursive Approach with memoization
// int memo[1001][1001];

// int helper(vector<vector<int>> &A, int i, int j)
// {
//     if (i == A.size() || j == A.size())
//     {
//         return 0;
//     }
//     if (memo[i][j] != -1)
//     {
//         return memo[i][j];
//     }
//     int val1 = helper(A, i + 1, j);
//     int val2 = helper(A, i + 1, j + 1);
//     return memo[i][j] = A[i][j] + max(val1, val2);
// }

int helper(vector<vector<int>> A)
{
    vector<vector<int>> dp(A.size(), vector<int> (A.size(), 0));
    for (int i = A.size() - 1; i >= 0; i--)
    {
        for (int j = 0; j < A[0].size() && j <= i; j++)
        {
            if (i == A.size() - 1)
            {
                dp[i][j] = A[i][j];
            }
            else
            {
                dp[i][j] = A[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]);
            }
        }
    }
    return dp[0][0];
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> A(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> A[i][j];

    // cout << helper(A, 0, 0); 
    cout << helper(A);

    cout << endl;
    return 0;
}