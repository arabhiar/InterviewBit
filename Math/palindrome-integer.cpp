#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A;
    cin >> A;
    int ans = 0;
    string str1 = to_string(A);
    string str2 = str1;
    reverse(str2.begin(), str2.end());
    if (str1 == str2)
    {
        ans = 1;
    }
    cout << ans;
    cout << endl;
    return 0;
}