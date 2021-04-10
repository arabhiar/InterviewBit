#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        int l = n - 1;
        int ans = -1;
        vector<int> B(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (B[A[i]] < 0)
            {
                ans = A[i];
                break;
            }
            else
            {
                B[A[i]] = -A[A[i]];
            }
        }
        cout << ans;
        cout << endl;
    }
    return 0;
}