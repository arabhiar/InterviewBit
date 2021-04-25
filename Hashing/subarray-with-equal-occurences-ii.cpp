#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    int B, C;
    cin >> B >> C;

    vector<int> countB(A.size(), 0);
    vector<int> countC(A.size(), 0);
    vector<int> diff(A.size());
    unordered_map<int, int> um;
    A[0] == B ? countB[0] = 1 : 0;
    A[0] == C ? countC[0] = 1 : 0;
    diff[0] = countB[0] - countC[0];
    um[diff[0]]++;
    for (int i = 1; i < A.size(); i++)
    {
        A[i] == B ? countB[i] = countB[i - 1] + 1 : countB[i] = countB[i - 1];
        A[i] == C ? countC[i] = countC[i - 1] + 1 : countC[i] = countC[i - 1];
        diff[i] = countB[i] - countC[i];
        um[diff[i]]++;
    }
    int ans = um.find(0) != um.end() ? um[0] : 0;
    for (auto it : um)
    {
        ans += (it.second * (it.second - 1)) / 2;
    }

    cout << ans;
    cout << endl;

    return 0;
}