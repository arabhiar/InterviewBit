#include<bits/stdc++.h>
using namespace std;

int main()
{
    int A;
    cin >> A;

    int num[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    string symbol[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    int i = (sizeof(num) / sizeof(int)) - 1;
    string ans = "";
    while (A > 0)
    {
        int div = A / num[i];
        A %= num[i];
        while (div--)
        {
            ans += symbol[i];
        }
        i--;
    }

    cout << ans;
    cout << endl;

    return 0;
}