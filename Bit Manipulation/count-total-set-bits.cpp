#include <bits/stdc++.h>
using namespace std;

#define M 1000000007

int main()
{
    int A;
    cin >> A;

    long long int temp, div, rem, ans = 0;

    for (int i = 1; i <= 32; i++)
    {
        temp = powl(2, i);
        div = (A + 1) / temp;
        ans += div * (temp / 2);
        ans %= M;
        rem = (A + 1) % temp;
        ans += (rem > temp / 2) ? (rem - (temp / 2)) : 0;
        ans %= M;
    }

    cout << ans;
    cout << endl;

    return 0;
}