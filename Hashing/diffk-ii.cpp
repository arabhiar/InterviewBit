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
    int ans = 0;
    for (int i = 0; i < A.size(); i++)
    {
        um[A[i]]++;
    }
    for (int i = 0; i < A.size(); i++)
    {
        int req = B + A[i];
        if ((req == A[i] && um[req] >= 2) || (req != A[i] && um[req] >= 1))
        {
            ans = 1;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}