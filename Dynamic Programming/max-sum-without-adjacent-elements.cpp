#include <bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>> A)
{
    if (A.size() == 0)
        return 0;
    int n = A[0].size();
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = max(A[0][0], A[1][0]);
    int maxSoFar = dp[1];
    for (int i = 2; i <= n; i++)
    {
        int curr = max(dp[i - 1], dp[i - 2] + max(A[0][i - 1], A[1][i - 1]));
        maxSoFar = max(maxSoFar, curr);
        dp[i] = curr;
    }
    return maxSoFar;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> A(2, vector<int>(n));
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    cout << helper(A);

    cout << endl;
    return 0;
}