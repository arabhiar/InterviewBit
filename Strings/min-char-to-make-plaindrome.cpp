#include <bits/stdc++.h>
using namespace std;

int main()
{
    string A;
    cin >> A;

    int n = A.length();
    int match_len = 1;

    int i = 0;
    int r, l;
    while (i < n)
    {
        r = i;
        l = i;
        while (r < n - 1 && A[r] == A[r + 1])
        {
            r++;
        }
        i = r + 1;
        while (l > 0 && r < n - 1 && A[l - 1] == A[r + 1])
        {
            r++;
            l--;
        }
        if (l == 0)
        {
            match_len = max(match_len, r - l + 1);
        }
    }

    int ans = n - match_len;
    cout << ans;
    cout << endl;
    return 0;
}