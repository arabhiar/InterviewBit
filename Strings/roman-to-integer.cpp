#include <bits/stdc++.h>
using namespace std;

int main()
{
    string A;
    cin >> A;

    int num[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    string symbol[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};

    int i = (sizeof(num) / sizeof(int)) - 1;
    int ans = 0;
    while (A.length() > 0)
    {
        int sl = symbol[i].length();
        string temp = A.substr(0, sl);
        int count = 0;
        while (temp == symbol[i])
        {
            count++;
            A = A.substr(sl);
            temp = A.substr(0, sl);
        }
        ans += (count * num[i]);
        i--;
    }

    cout << ans;
    cout << endl;

    return 0;
}