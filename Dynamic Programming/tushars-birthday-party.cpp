#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> A, vector<int> B, vector<int> C)
{
    int cost = 0;
    int n = B.size();
    vector<pair<int, int>> dish;
    for (int i = 0; i < B.size(); i++)
    {
        dish.push_back({B[i], C[i]});
    }
    sort(dish.begin(), dish.end());
    int maxCap = *max_element(A.begin(), A.end());

    vector<vector<int>> dp(n, vector<int>(maxCap + 1, 0));
    for (int i = 1; i <= maxCap; i++)
    {
        dp[0][i] = i * dish[0].second;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= maxCap; j++)
        {
            if (j >= dish[i].first)
                dp[i][j] = min(dp[i - 1][j], dish[i].second + dp[i][j - dish[i].first]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    for (auto cap : A)
    {
        cost += dp[n - 1][cap];
    }
    return cost;
}

int main()
{
    int m, n;
    cin >> m;
    vector<int> A(m);
    for (int i = 0; i < m; i++)
        cin >> A[i];
    cin >> n;
    vector<int> B(n), C(n);
    for (int i = 0; i < n; i++)
        cin >> B[i];
    for (int i = 0; i < n; i++)
        cin >> C[i];

    cout << helper(A, B, C);

    cout << endl;
    return 0;
}