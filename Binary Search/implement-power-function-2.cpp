#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main()
{
    int x, n, d;
    cin >> x >> n >> d;
    ll ans = 1;
    int x = x % d;
    if (d == 1)
    {
        ans = 0;
    }
    else if (x == 0)
    {
        ans = 0;
    }
    else
    {
        while (n > 0)
        {
            if (n & 1)
            {
                ans = (ans * x) % d;
            }
            x = (x * x) % d;
            n = n >> 1;
        }
    }
    if (ans < 0)
    {
        ans = (d - abs(ans) % d);
    }
    cout << ans;
    cout << endl;
    return 0;
}