#include<bits/stdc++.h>
using namespace std;

int helper(string A, string B)
{
    int l1 = A.length();
    int l2 = B.length();
    vector<vector<int>> dp(l2 + 1, vector<int> (l1 + 1, 0));
    for (int i = 0; i < l1; i++)
    {
        dp[0][i] = 1;
    }
    for (int i = 1; i <= l2; i++)
    {
        for (int j = 1; j <= l1; j++)
        {
            if (A[j - 1] == B[i - 1])
            {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = dp[i][j - 1];
            }
        }
    }
    return dp[l2][l1];
}

int main()
{
    string A, B;
    cin >> A >> B;

    cout << helper(A, B);

    cout << endl;
    return 0;
}