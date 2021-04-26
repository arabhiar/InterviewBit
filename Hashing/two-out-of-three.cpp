#include <bits/stdc++.h>
using namespace std;

int main()
{
    int p, q, r;
    cin >> p;
    vector<int> A(p);
    for (int i = 0; i < p; i++)
    {
        cin >> A[i];
    }
    cin >> q;
    vector<int> B(q);
    for (int i = 0; i < q; i++)
    {
        cin >> B[i];
    }
    cin >> r;
    vector<int> C(r);
    for (int i = 0; i < r; i++)
    {
        cin >> C[i];
    }

    unordered_map<int, int> f1, f2, f3;
    for (auto it : A)
    {
        f1[it]++;
    }

    for (auto it : B)
    {
        f2[it]++;
    }

    for (auto it : C)
    {
        f3[it]++;
    }
    vector<int> ans;
    unordered_set<int> s;
    for (auto it : A)
    {
        if (f2.count(it) || f3.count(it))
            s.insert(it);
    }
    for (auto it : B)
    {
        if (f1.count(it) || f3.count(it))
            s.insert(it);
    }
    for (auto it : C)
    {
        if (f1.count(it) || f2.count(it))
            s.insert(it);
    }
    for (auto it : s)
    {
        ans.push_back(it);
    }
    sort(ans.begin(), ans.end());

    // for (auto it : freq)
    // {
    //     cout << it.first << " -> " << it.second << endl;
    // }

    return 0;
}