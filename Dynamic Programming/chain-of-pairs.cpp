#include <bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>> A)
{
    int n = A.size();
    if (n == 0) return 0;
    vector<int> dp(n, 1);
    int maxChainSoFar = 1;
    for (int i = 1; i < n; i++)
    {
        int maxChainEndingHere = 1;
        for (int j = 0; j < i; j++)
        {
            if (A[i][0] > A[j][1])
            {
                int curr = dp[j] + 1;
                maxChainEndingHere = max(maxChainEndingHere, curr);
            }
        }
        dp[i] = maxChainEndingHere;
        maxChainSoFar = max(maxChainSoFar, maxChainEndingHere);
    }
    return maxChainSoFar;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> A(n, vector<int>(2));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2; j++)
            cin >> A[i][j];

    cout << helper(A);

    cout << endl;
    return 0;
}