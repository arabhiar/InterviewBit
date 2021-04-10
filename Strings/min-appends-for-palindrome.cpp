#include <bits/stdc++.h>
using namespace std;

int main()
{
    string A;
    cin >> A;

    int i = A.length() - 1;
    int max_len = 1;
    int l, r;
    while (i > 0)
    {
        l = i;
        r = i;
        while (l > 0 && A[l - 1] == A[l])
        {
            l--;
        }
        i = l - 1;
        while (l > 0 && r < A.length() - 1 && A[l - 1] == A[r + 1])
        {
            l--;
            r++;
        }
        if (r == A.length() - 1)
        {
            max_len = max(max_len, r - l + 1);
        }
    }
    int ans = A.length() - max_len;
    cout << ans;
    cout << endl;
    return 0;
}