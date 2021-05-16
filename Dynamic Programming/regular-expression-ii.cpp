#include <bits/stdc++.h>
using namespace std;

int helper(string A, string B)
{
    // ’?’ : Matches any single character.
    // ‘*’ : Matches any sequence of characters (including the empty sequence).
    int l1 = A.length(), l2 = B.length();
    int count = 0;
    for (auto ch : B)
    {
        if (ch != '*')
        {
            count++;
        }
    }
    if (count > l1)
    {
        return 0;
    }
    vector<vector<bool>> dp(l1 + 1, vector<bool>(l2 + 1, false));
    dp[0][0] = 1;
    for (int i = 1; i <= l1; i++)
    {
        for (int j = 1; j <= l2; j++)
        {
            if (B[j - 1] == '*' && B[j - 2] == A[i - 1])
            {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - 1] || dp[i][j - 1];
            }
            else if (B[j - 1] == '*')
            {
                dp[i][j] = dp[i][j - 1];
            }
            else if (B[j - 1] != '.' && B[j - 1] != A[i - 1])
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = dp[i - 1][j - 1];
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