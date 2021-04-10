#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int A, B, C;
        cin >> A >> B >> C;
        int ans = ((A % B) + (C % B) - 1) % B;
        cout << ans;
        cout << endl;
    }
    return 0;
}