#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> A, vector<int> B, int C)
{
    // Here A is capacity and B is the corresponding value. 
    int n = A.size();
    vector<vector<int>> dp(n + 1, vector<int>(C + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            if (j >= A[i - 1])
            {
                dp[i][j] = max(dp[i - 1][j], B[i - 1] + dp[i - 1][j - A[i - 1]]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][C];
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n), B(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < n; i++)
        cin >> B[i];
    int C;
    cin >> C;

    cout << helper(B, A, C);

    cout << endl;
    return 0;
}