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

    int ans = 0;

    if (n % 2 == 1)
    {
        // odd length
        ans = A[0];
        if (n > 2)
        {
            for (int i = 2; i < n; i+= 2)
            {
                ans = ans ^ A[i];
            }
        }
    }

    cout << ans;
    cout << endl;

    return 0;
}