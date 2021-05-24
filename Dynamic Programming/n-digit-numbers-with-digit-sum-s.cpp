#include <bits/stdc++.h>
using namespace std;

long long int M = 1e9 + 7;

int helper(int A, int B)
{
    if (A < 1 || B > 9 * A)
        return 0;
    vector<vector<long long int>> dp(A, vector<long long int>(B, 0));
    for (int i = 0; i < B; i++)
    {
        if (i < 9)
        {
            dp[0][i] = 1;
        }
        else
        {
            break;
        }
    }
    for (int i = 0; i < A; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i < A; i++)
    {
        for (int j = 1; j < B; j++)
        {
            int k = 0;
            if (j >= 9)
                k = j - 9;
            for (; k <= j; k++)
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % M;
            }
        }
    }
    // for (int i = 0; i < dp.size(); i++)
    // {
    //     for (int j = 0; j < dp[i].size(); j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return dp[A - 1][B - 1];
}

int main()
{
    int A, B;
    cin >> A >> B;

    cout << helper(A, B);

    cout << endl;
    return 0;
}