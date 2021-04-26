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
    int B;
    cin >> B;

    unordered_map<int, int> um;
    int xorValue = 0;
    int ans = 0;
    for (auto it : A)
    {
        xorValue ^= it;
        um[xorValue]++;
        if (xorValue == B)
        {
            ans++;
        }
        if (um.find(xorValue ^ B) != um.end())
        {
            ans += um[xorValue ^ B];
        }
    }

    cout << ans;
    cout << endl;

    return 0;
}