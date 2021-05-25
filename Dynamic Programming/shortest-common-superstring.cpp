#include <bits/stdc++.h>
using namespace std;

int shortestSuperstring(vector<string> &A)
{
    const int n = A.size();
    vector<vector<int>> g(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            g[i][j] = A[j].length();
            for (int k = 1; k <= min(A[i].length(), A[j].length()); ++k)
                if (A[i].substr(A[i].size() - k) == A[j].substr(0, k))
                    g[i][j] = A[j].length() - k;
        }

    // for (int i = 0; i < g.size(); i++)
    // {
    //     for (int j = 0; j < g[i].size(); j++)
    //     {
    //         cout << g[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    vector<vector<int>> dp(1 << n, vector<int>(n, INT_MAX / 2));
    vector<vector<int>> parent(1 << n, vector<int>(n, -1));

    for (int i = 0; i < n; ++i)
        dp[1 << i][i] = A[i].length();

    for (int s = 1; s < (1 << n); ++s)
    {
        for (int j = 0; j < n; ++j)
        {
            if (!(s & (1 << j)))
                continue;
            int ps = s & ~(1 << j);
            for (int i = 0; i < n; ++i)
            {
                if (dp[ps][i] + g[i][j] < dp[s][j])
                {
                    dp[s][j] = dp[ps][i] + g[i][j];
                    parent[s][j] = i;
                }
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
    // cout << endl;

    auto it = min_element(begin(dp.back()), end(dp.back()));
    int j = it - begin(dp.back());
    int s = (1 << n) - 1;
    string ans;
    while (s)
    {
        int i = parent[s][j];
        if (i < 0)
            ans = A[j] + ans;
        else
            ans = A[j].substr(A[j].length() - g[i][j]) + ans;
        s &= ~(1 << j);
        j = i;
    }
    return ans.length();
}

int main()
{
    int n;
    cin >> n;
    vector<string> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    cout << shortestSuperstring(A);

    cout << endl;
    return 0;
}