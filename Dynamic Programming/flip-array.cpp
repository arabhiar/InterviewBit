#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> A)
{
    // Let 'S' be the sum of all element. Then this problem is similar to Knapsack
    // problem where capacity is 'S/2' and we have to use min no. of elements.
    int sum = 0;
    for (auto it : A)
        sum += it;
    if (sum == 0)
        return 0;
    int cap = sum / 2;
    int m = A.size(), n = cap;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        dp[0][i] = 10001;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= A[i - 1])
            {
                if (dp[i][j] > dp[i - 1][j - A[i - 1]] + 1)
                {
                    dp[i][j] = dp[i - 1][j - A[i - 1]] + 1;
                }
            }
        }
    }

    int idx = 0;
    for (int i = 0; i <= n; i++)
    {
        if (dp[m][i] != 10001)
        {
            idx = i;
        }
    }

    return dp[m][idx];
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    cout << helper(A);

    cout << endl;
    return 0;
}