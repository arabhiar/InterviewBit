#include <bits/stdc++.h>
using namespace std;

int helper(string A, string B)
{
    // '.' Matches any single character.
    // '*' Matches zero or more of the preceding element.
    int l1 = A.length(), l2 = B.length();
    vector<vector<bool>> dp(l1 + 1, vector<bool>(l2 + 1, false));
    dp[0][0] = 1;
    for (int i = 0; i <= l1; i++)
    {
        for (int j = 1; j <= l2; j++)
        {
            if (B[j - 1] != '*')
            {
                dp[i][j] = (i > 0) && (A[i - 1] == B[j - 1] || B[j - 1] == '.') && dp[i - 1][j - 1];
            }
            
            else
            {
                dp[i][j] = dp[i][j - 2] || (i > 0 && (B[j - 2] == A[i - 1] || B[j - 2] == '.') && dp[i - 1][j]);
            }
        }
    }
    return dp[l1][l2];
}

int main()
{
    string A, B;
    cin >> A >> B;

    cout << helper(A, B);

    cout << endl;
    return 0;
}