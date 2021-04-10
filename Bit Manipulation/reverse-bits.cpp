#include<bits/stdc++.h>
using namespace std;

int main()
{
    unsigned int A;
    cin >> A;
    unsigned int ans = 0;
    for (int i = 0; i < 32; i++)
    {
        if ((1 << i) & A)
        {
            ans += (1 << (31 - i));
        }
    }
    cout << ans;
    cout << endl;
    return 0;
}