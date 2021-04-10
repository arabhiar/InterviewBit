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

    sort(A.begin(), A.end());

    int ans = INT_MAX;

    for (int i = 0; i < n - 1; i++)
    {
        ans = min(ans, A[i] ^ A[i + 1]);
    }

    cout << ans;
    cout << endl;

    return 0;
}