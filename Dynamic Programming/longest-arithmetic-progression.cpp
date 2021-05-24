#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> A)
{
    int n = A.size();
    if (n <= 2)
        return n;
    vector<unordered_map<int, int>> dp(n);
    int lap = 2;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int diff = A[j] - A[i];
            if (dp[i].find(diff) != dp[i].end())
            {
                // there exist a AP with same common difference which have same index as current index.
                dp[j][diff] = dp[i][diff] + 1;
            }
            else
            {
                dp[j][diff] = 2;
            }
            lap = max(lap, dp[j][diff]);
        }
    }
    return lap;
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    cout << helper(A);

    cout << endl;
    return 0;
}