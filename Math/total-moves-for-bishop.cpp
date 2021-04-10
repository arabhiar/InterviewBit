#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int A, B;
        cin >> A >> B;
        int ans = 0;
        ans += min((A - 1), (B - 1));
        ans += min((A - 1), (8 - B));
        ans += min((8 - A), (8 - B));
        ans += min((8 - A), (B - 1));
        cout << ans;
        cout << endl;
    }
    return 0;
}