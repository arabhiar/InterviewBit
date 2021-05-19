#include <bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>> &A)
{
    auto dp = A;
    for (int i = 1; i < A.size(); i++)
    {
        for (int j = 0; j < A[i].size(); j++)
        {
            if (A[i][j] == 1)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + 1);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < dp.size(); i++)
    {
        sort(dp[i].begin(), dp[i].end(), greater<int>());
        int j = 0;
        while (dp[i][j] != 0 && j < dp[i].size())
        {
            ans = max(ans, (j + 1) * dp[i][j]);
            j++;
        }
    }
    return ans;
}

int main()
{
    int m, n;
    cin >> m;
    cin >> n;
    vector<vector<int>> A(m, vector<int>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    cout << helper(A);

    cout << endl;
    return 0;
}