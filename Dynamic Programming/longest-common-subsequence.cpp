#include <bits/stdc++.h>
using namespace std;

int helper(string A, string B)
{
    vector<vector<int>> dp(A.length() + 1, vector<int>(B.length() + 1, 0));
    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 1; j < dp[i].size(); j++)
        {
            if (A[i - 1] == B[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
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