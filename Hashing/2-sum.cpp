#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    int B;
    cin >> B;

    vector<int> ans;
    if (A.size() > 1)
    {
        unordered_map<ll, ll> um;
        for (int i = 0; i < A.size(); i++)
        {
            if (um.find(A[i]) == um.end())
            {
                // not found
                um[A[i]] = i + 1;
            }
        }
        for (int i = A.size() - 1; i >= 0; i--)
        {
            int req = B - A[i];
            if (um.find(req) != um.end() && um[req] < i + 1)
            {
                ans.resize(2);
                ans[0] = um[req];
                ans[1] = i + 1;
            }
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}