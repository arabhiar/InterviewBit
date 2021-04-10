#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A;
    cin >> A;

    int ans = 0;
    int i = 0;
    while (1)
    {
        if ((1 << i) & A)
        {
            break;
        }
        i++;
        ans++;
    }

    cout << ans;
    cout << endl;

    return 0;
}