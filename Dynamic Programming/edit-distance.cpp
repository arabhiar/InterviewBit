#include <bits/stdc++.h>
using namespace std;

int helper(string A, string B)
{
    vector<vector<int>> dp(A.length() + 1, vector<int>(B.length() + 1, -1));
    dp[0][0] = 0;
    for (int i = 1; i < dp.size(); i++)
    {
        dp[i][0] = dp[i - 1][0] + 1;
    }
    for (int i = 1; i < dp[0].size(); i++)
    {
        dp[0][i] = dp[0][i - 1] + 1;
    }
    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 1; j < dp[i].size(); j++)
        {
            if (A[i - 1] != B[j - 1])
            {
                // (i - 1), (j - 1) ==> replace a char in string A
                // (i - 1), (j) ==> delete a char in string A
                // (i), (j - 1) ==> insert a char in string A
                dp[i][j] = min((min(dp[i][j - 1], dp[i - 1][j - 1])), dp[i - 1][j]) + 1;
            }
            else
            {
                // char is same
                dp[i][j] = dp[i - 1][j - 1];
            }
        }
    }
    return dp[A.length()][B.length()];
}

int main()
{
    string A, B;
    cin >> A >> B;

    cout << helper(A, B);

    cout << endl;
    return 0;
}