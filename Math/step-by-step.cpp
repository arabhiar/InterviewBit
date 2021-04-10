#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int A;
        cin >> A;
        int ans = 0;
        int n = ceil((-1.0 + sqrt(1 + (8.0 * A))) / 2.0);
        int sum = (n * (n + 1)) / 2;
        if (sum == A)
        {
            ans = n;
        }
        else
        {
            int d = sum - A;
            if ((d & 1) == 0)
            {
                // d is even
                ans = n;
            }
            else
            {
                ans = n + ((n & 1) ? 2 : 1);
            }
        }
        cout << ans;
        cout << endl;
    }
    return 0;
}