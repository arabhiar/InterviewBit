#include <bits/stdc++.h>
using namespace std;

#define M 1000000007
#define ll long long

ll factorsModulo(int n)
{
    ll res = 1;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            res *= i;
            res %= M;
            int t = n / i;
            if (t != i)
            {
                res *= t;
                res %= M;
            }
        }
    }
    return res;
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
    int m;
    cin >> m;
    vector<int> B(m);
    for (int i = 0; i < m; i++)
    {
        cin >> B[i];
    }
    stack<int> s;
    s.push(0);
    vector<int> freq(n);
    for (ll i = 1; i < n; i++)
    {
        while (!s.empty() && A[s.top()] <= A[i])
        {
            int idx = s.top();
            s.pop();
            ll left = idx + 1;
            ll right = i - idx;
            if (!s.empty())
            {
                left = idx - s.top();
            }
            freq[idx] = left * right;
        }
        s.push(i);
    }

    while (!s.empty())
    {
        ll idx = s.top();
        s.pop();
        ll left = idx + 1;
        ll right = n - idx;
        if (!s.empty())
        {
            left = idx - s.top();
        }
        freq[idx] = left * right;
    }
    unordered_map<int, int> um;
    for (int i = 0; i < n; i++)
    {
        if (um.find(A[i]) == um.end())
        {
            // not found
            um[A[i]] = freq[i];
        }
        else
        {
            // found
            um[A[i]] += A[i];
        }
    }
    vector<int> G;
    for (auto it : um)
    {
        G.insert(G.end(), it.second, factorsModulo(it.first));
    }
    sort(G.begin(), G.end());
    reverse(G.begin(), G.end());
    vector<int> ans;
    for (int i = 0; i < m; i++)
    {
        ans.push_back(G[B[i] - 1]);
    }

    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}