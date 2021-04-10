#include<bits/stdc++.h>
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
    int ans = A[0];
    for (int i = 1; i < n; i++)
    {
        ans ^= A[i];
    }

    cout << ans;
    cout << endl;

    return 0;
}