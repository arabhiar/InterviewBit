#include <bits/stdc++.h>
using namespace std;

#define ll long long int

void path(vector<ll> &cuts, vector<int> &result, ll i, ll j, vector<vector<ll>> dp)
{
    if (i + 1 == j)
        return;
    for (ll k = i + 1; k < j; k++)
    {
        if (dp[i][k] + dp[k][j] + cuts[j] - cuts[i] == dp[i][j])
        {
            result.push_back(cuts[k]);
            path(cuts, result, i, k, dp);
            path(cuts, result, k, j, dp);
            return;
        }
    }
}

// https://stackoverflow.com/a/21111714/13658008
vector<int> helper(int A, vector<int> B)
{
    vector<ll> temp;
    temp.push_back(0);
    for (auto it : B)
        temp.push_back(it);
    temp.push_back(A);
    vector<vector<ll>> dp(temp.size(), vector<ll>(temp.size(), 0));
    ll minCost = INT64_MAX, currCost;
    for (ll block_size = 3; block_size <= dp.size(); block_size++)
    {
        for (ll left = 0; left <= dp.size() - block_size; left++)
        {
            ll right = left + block_size - 1;
            minCost = INT64_MAX;
            for (ll k = left + 1; k < right; k++)
            {
                currCost = dp[left][k] + dp[k][right];
                if (currCost < minCost)
                {
                    minCost = currCost;
                }
            }
            dp[left][right] = minCost + temp[right] - temp[left];
        }
    }
    // cout << dp[0][dp.size() - 1] << endl;
    vector<int> result;
    path(temp, result, 0, temp.size() - 1, dp);
    return result;
}

int main()
{
    int A;
    int n;
    cin >> A;
    cin >> n;
    vector<int> B(n);
    for (int i = 0; i < n; i++)
        cin >> B[i];

    auto ans = helper(A, B);
    for (auto it : ans)
        cout << it << " ";
    cout << endl;

    cout << endl;
    return 0;
}