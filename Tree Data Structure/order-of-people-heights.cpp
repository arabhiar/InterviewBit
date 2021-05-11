#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    vector<int> B(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> B[i];
    }

    vector<pair<int, int>> v;
    n = A.size();

    for (int i = 0; i < n; i++)
        v.push_back({A[i], B[i]});

    sort(v.begin(), v.end(), greater<pair<int, int>>());

    vector<int> res;

    for (int i = 0; i < n; i++)
    {
        int ind = v[i].second;
        if (ind < res.size())
            res.insert(res.begin() + ind, v[i].first);
        else
            res.push_back(v[i].first);
    }

    for (auto it : res)
    {
        cout << it << " ";
    }

    cout << endl;
    return 0;
}