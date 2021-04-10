#include<bits/stdc++.h>
using namespace std;

int main()
{
    unsigned int A;
    cin >> A;
    int ans = 0;
    while (A)
    {
        A &= (A - 1);
        ans++;
    }
    cout << ans;
    cout << endl;
    return 0;
}