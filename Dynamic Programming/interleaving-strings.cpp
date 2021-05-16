#include<bits/stdc++.h>
using namespace std;

int helper(string A, string B, string C)
{
    int l1 = A.length(), l2 = B.length();
    vector<vector<bool>> dp(l1 + 1, vector<bool> (l2 + 1, false));
    dp[0][0] = 1;
    for (int i = 1; i <= l1; i++)
    {
        dp[i][0] = (A[i - 1] == C[i - 1]) && dp[i - 1][0];
    }
    for (int i = 1; i <= l2; i++)
    {
        dp[0][i] = (B[i - 1] == C[i - 1]) && dp[0][i - 1];
    }
    for (int i = 1; i <= l1; i++)
    {
        for (int j = 1; j <= l2; j++)
        {
            if (A[i - 1] == C[i + j - 1] && B[j - 1] != C[i + j - 1])
            {
                dp[i][j] = dp[i - 1][j];
            }
            else if (B[j - 1] == C[i + j - 1] && A[i - 1] != C[i + j - 1])
            {
                dp[i][j] = dp[i][j - 1];
            }
            else if (A[i - 1] == C[i + j - 1] && B[j - 1] == C[i + j - 1])
            {
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }
        }
    }
    return dp[l1][l2];
}

int main()
{
    string A, B, C;
    cin >> A >> B >> C;

    cout << helper(A, B, C);

    cout << endl;
    return 0;
}