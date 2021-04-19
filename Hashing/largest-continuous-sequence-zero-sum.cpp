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

    unordered_map<ll, ll> um;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += A[i];
        um[sum] = i;
    }
    int maxLen = INT_MIN;
    sum = 0;
    vector<int> ans;
    if (um.find(0) != um.end())
    {
        maxLen = um[0] + 1;
        auto first = A.begin();
        auto last = A.begin() + um[sum] + 1;
        vector<int> temp(first, last);
        ans = temp;
    }
    for (int i = 0; i < n; i++)
    {
        sum += A[i];
        if (um.find(sum) != um.end())
        {
            // found
            if (um[sum] - i > maxLen)
            {
                maxLen = um[sum] - i;
                auto first = A.begin() + i + 1;
                auto last = A.begin() + um[sum] + 1;
                vector<int> temp(first, last);
                ans = temp;
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