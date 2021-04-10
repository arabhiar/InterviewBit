#include <bits/stdc++.h>
using namespace std;

string divide_by_2(string s)
{
    int rem = 0;
    int l = s.length();
    string res = "";
    for (int i = 0; i < l; i++)
    {
        int curr_dig = s[i] - '0';
        int temp = rem * 10 + curr_dig;
        int div = temp / 2;
        rem = temp % 2;
        res += div + '0';
    }
    int j = 0;
    while (res[j] == '0')
    {
        j++;
    }
    return res.substr(j);
}

int main()
{
    string A;
    cin >> A;

    int flag = 0;

    while (A != "1")
    {
        flag = 1;
        int last_digit = A[A.length() - 1] - '0';
        if (last_digit % 2 == 1)
        {
            break;
        }
        A = divide_by_2(A);
    }
    int ans = 0;
    if (A == "1" && flag == 1)
    {
        ans = 1;
    }

    cout << ans;
    cout << endl;

    return 0;
}