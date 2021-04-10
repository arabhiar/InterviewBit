#include <bits/stdc++.h>
using namespace std;

int main()
{
    string A;
    cin >> A;

    int l, r;
    int n = A.length();
    int i = 0;
    int max_len = INT_MIN;
    string ans = "";
    while (i < n)
    {
        r = i;
        l = i;
        while (r < n - 1 && A[r] == A[r + 1])
        {
            r++;
        }
        i = r + 1;
        while (l > 0 && l < n - 1 && A[l - 1] == A[r + 1])
        {
            r++;
            l--;
        }
        int curr_len = (r - l + 1);
        if (curr_len > max_len)
        {
            max_len = curr_len;
            ans = A.substr(l, max_len);
        }
    }

    cout << ans;
    cout << endl;

    return 0;
}