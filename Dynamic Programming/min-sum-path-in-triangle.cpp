#include <bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>> A)
{
    int n = A.size();
    vector<vector<int>> dp(n, vector<int> (n, 0));
    dp[0][0] = A[0][0];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j > 0 && j < i)
            {
                dp[i][j] = A[i][j] + min(dp[i - 1][j - 1], dp[i - 1][j]);
            }
            else if (j == 0)
            {
                dp[i][j] = A[i][j] + dp[i - 1][j];
            }
            else if (j == i)
            {
                dp[i][j] = A[i][j] + dp[i - 1][j - 1];
            }
        }
    }
    return *min_element(dp[n - 1].begin(), dp[n  - 1].end());
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> A(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];
    
    cout << helper(A);

    cout << endl;
    return 0;
}